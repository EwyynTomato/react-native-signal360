#import "RNSignal360.h"
#import <Signal360/SignalBluetoothCodeHeard.h>

@implementation RNSignal360

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(setGuid:(NSString *)guid) {
    self.deviceGuid = guid;
}

RCT_EXPORT_METHOD(start) {
    [[Signal sharedInstance] requestLocationAlwaysPermission];
    [[Signal sharedInstance] requestNotificationPermission];

    [[Signal sharedInstance] initializeWithApplicationGUID:self.deviceGuid andDelegate:self];
    [[Signal sharedInstance] setDelegate:self]; //<- this is needed so that Dev Menu > Reload will replace the delegate with new instance, initializeWithApplicationGUID:andDelegate: doesn't seem to do such thing.
    [[Signal sharedInstance] start];
}

RCT_EXPORT_METHOD(stop) {
    [[Signal sharedInstance] stop];
}

- (BOOL)signal:(Signal *)signal didHearCode:(SignalCodeHeard *)code {
    /**
     We need to check if self.bridge still exists, for the following reasons Upon Dev Menu > Reload:
     - _bridge will no longer exist, and self.bridge would be nil
     - SignalDelegate would keep on calling this delegate method
     - RCTEventEmitter's sendEventWithName need _bridge not to be nil to work/NOT CRASH
     - this RCT Module won't be dealloc late after, so implementing [[Signal sharedInstance] stop]; in dealloc won't prevent the issue
     
     Oh, also: you can't move this delegate to AppDelegate, because you need to emit event using RCTEventEmitter, which is only available as instance method.
     */
    if (self.bridge) {
        NSString *signalType = [code isKindOfClass:[SignalBluetoothCodeHeard class]] ? @"BLUETOOTH" : @"AUDIO";
        [self sendEventWithName:[self getEventName]
                           body:@{@"signalType": signalType,
                                  @"beaconCode": [NSString stringWithFormat:@"%ld", code.beaconCode]}];
    }
    
    return YES;
}

- (NSString *)getEventName {
    return @"RNSignal360Event";
}

- (NSArray<NSString *> *)supportedEvents {
    return @[[self getEventName]];
}

@end

