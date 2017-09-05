
#import "RNSignal360.h"

@implementation RNSignal360 {
    NSString *deviceGuid;
}

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}
RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(setGuid:(NSString *)guid) {
    deviceGuid = guid;
}

RCT_EXPORT_METHOD(setAskPermissionString:(NSString *)text) {
    //This only works on Android
}

RCT_EXPORT_METHOD(start) {
    [[Signal sharedInstance] requestLocationAlwaysPermission];
    [[Signal sharedInstance] requestNotificationPermission];

    [[Signal sharedInstance] initializeWithApplicationGUID:deviceGuid andDelegate:self];
    [[Signal sharedInstance] start];
}

RCT_EXPORT_METHOD(stop) {
    [[Signal sharedInstance] stop];
}

- (BOOL)signal:(Signal *)signal didHearCode:(SignalCodeHeard *)code {
    [self sendEventWithName:[self getEventName]
                       body:@{@"signalType": @"AUDIO",
                              @"beaconCode": code}];
    return YES;
}

- (NSString *)getEventName {
    return @"RNSignal360Event";
}

- (NSArray<NSString *> *)supportedEvents {
    return @[[self getEventName]];
}

@end
  
