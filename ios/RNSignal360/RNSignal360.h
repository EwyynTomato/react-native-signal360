
#if __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#import "RCTEventEmitter.h"
#import "RCTLog.h"
#else
#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>
#import <React/RCTLog.h>
#endif

#import <Signal360/SignalShared.h>

@interface RNSignal360 : RCTEventEmitter <RCTBridgeModule, SignalDelegate>

@property (strong) NSString *deviceGuid;

@end
