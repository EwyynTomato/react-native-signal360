
#import "RNSignal360.h"
#import <Signal360/SignalCodeHeard.h>

@implementation RNSignal360

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}
RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(setGuid:(NSString *)guid) {
    self.deviceGuid = guid;
}

RCT_EXPORT_METHOD(setAskPermissionString:(NSString *)text) {
    //This only works on Android
}

RCT_EXPORT_METHOD(start) {
    [[Signal sharedInstance] requestLocationAlwaysPermission];
    [[Signal sharedInstance] requestNotificationPermission];

    [[Signal sharedInstance] initializeWithApplicationGUID:self.deviceGuid andDelegate:self];
    [[Signal sharedInstance] start];
}

RCT_EXPORT_METHOD(stop) {
    [[Signal sharedInstance] stop];
}

- (BOOL)signal:(Signal *)signal didHearCode:(SignalCodeHeard *)code {
    [self sendEventWithName:[self getEventName]
                       body:@{@"signalType": @"AUDIO",
                              @"beaconCode": [NSString stringWithFormat:@"%ld", code.beaconCode]}];
    return YES;
}

- (NSString *)getEventName {
    return @"RNSignal360Event";
}

- (NSArray<NSString *> *)supportedEvents {
    return @[[self getEventName]];
}

@end
  
