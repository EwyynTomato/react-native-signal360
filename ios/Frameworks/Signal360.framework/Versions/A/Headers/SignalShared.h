//
//  SignalShared.h
//  Signal360
//
//  Created by Ryan Mannion on 11/8/11.
//  Copyright (c) 2011 Signal360 All rights reserved.
//

#import "SignalConstants.h"
#import "SignalCache.h"

#ifdef MANAGER
#import "SignalHistoricalData.h"
#endif

//Core Macros
#define SIGNAL_DEPRECATED __attribute__((deprecated))

//Notifications are used on delegate callbacks to enabled linked functionality
FOUNDATION_EXPORT NSString *const SignalNotificationDidHearCode;
FOUNDATION_EXPORT NSString *const SignalNotificationDidReceiveActivations;
FOUNDATION_EXPORT NSString *const SignalNotificationDidDeactivateActivation;
FOUNDATION_EXPORT NSString *const SignalNotificationPreferencesUpdated;
FOUNDATION_EXPORT NSString *const SignalNotificationReset;
FOUNDATION_EXPORT NSString *const SignalNotificationRegionUpdated;
FOUNDATION_EXPORT NSString *const SignalNotificationLocationMessage;
FOUNDATION_EXPORT NSString *const SignalNotificationCustomPayload;
FOUNDATION_EXPORT NSString *const SignalUserInfoChannelCode;
FOUNDATION_EXPORT NSString *const SignalUserInfoCustomPayload;
FOUNDATION_EXPORT NSString *const SignalUserInfoContentId;

//Define Id Field Type
typedef long long int SignalId;

/**
 * Track user actions on content card
 */
typedef NS_ENUM(NSInteger, SignalUserActionType) {
    SwipeRight = 0,
    SwipeLeft = 1,
    ClickRightButton = 2,
    ClickLeftButton = 3,
    ClickOpenButton = 4,
    ClickCloseButton = 5,
    ClickAwayToClose = 6,
    NoticeAccept = 7,
    NoticeDecline = 8
};

#define signalUserActionTypeString(enum) [@[@"SWIPE_RIGHT", @"SWIPE_LEFT", @"CLICK_RIGHT_BUTTON", @"CLICK_LEFT_BUTTON", @"CLICK_OPEN_BUTTON", @"CLICK_CLOSE_BUTTON", @"CLICK_AWAY_TO_CLOSE", @"NOTICE_ACCEPT", @"NOTICE_DECLINE" ] objectAtIndex:enum];

//Declare these classes as they are used in delegates
@class Signal;
@class SignalActivation;
@class SignalLocation;
@class SignalCodeHeard;
@class SignalBluetoothCodeHeard;
@class SignalAudioCodeHeard;
@class SignalEvent;

/**
 * The SDK must be in one of the following statuses.
 * Note that each status implies that certain functionality maybe disabled.
 */
typedef NS_ENUM(NSInteger, SignalSdkStatus) {
    SignalSdkStatusNotInitialized, /** We have not been able to determine the status of the SDK, either the program is starting or there hasn't been any network connectivity.  Delegate will not receive any code or activation calls.*/
    SignalSdkStatusDisabled,        /** This SDK is disabled, the delegate will not receive any code or activation calls.*/
    SignalSdkStatusTrial,           /** This SDK is in a trial (developer) mode, a message will appear to the user.  Delegate will receive code and activation calls.*/
    SignalSdkStatusEnabled          /** This SDK is fully enabled, the delegate will receive all applicable calls.*/
};

/**
 * Result of manually refetching the content delivery configuration
 */
typedef NS_ENUM(NSInteger, SignalFetchResult) {
    SignalFetchResultNewData, /** A new configuration was received.*/
    SignalFetchResultNoData, /** No configuration changes were received.*/
    SignalFetchResultFailed /** Configuration refetch failed.*/
};

/**
 * Result of signal operation
 */
typedef NS_ENUM(NSInteger, SignalOperationResult) {
    SignalOperationSuccess, /** Operation succeeded.*/
    SignalOperationFailed /** Operation failed.*/
};

/**
 * Signal delegate used for responding to signal events, it includes several core functions
 *
 * - Responding to the fact that a signal is in range
 * - Responding to a specific signal with the appropriate time index relative to the program
 * - Respond to receiving activations (content)
 * - Respond to content being deleted
 * - Respond to offline content caching
 *
 */
@protocol SignalDelegate <NSObject>
@optional

/**
 * This is called when a signal is heard and provides a code heard object
 *
 * NOTE: this does not mean content is available
 *
 * @param signal - the configured running instance of signal
 * @param codeHeard instance of the SignalCodeHeard
 *
 * @return whether or not you are interested in receiving content for this signal, it is the implementers responsibility for throttling
 *
 */
- (BOOL) signal: (Signal *)signal didHearCode: (SignalCodeHeard *) code;


/**
 * Did receive activations is called after URL#signal:didHearCode:withTimeInterval returns YES.
 *
 * The server is then queried (or offline content prepared) and activations delivered
 *
 * @param signal - the configured running instance of signal
 * @param activations instances of SignalActivation that contain, delivery time, content, etc
 */
- (void) signal: (Signal *)signal didReceiveActivations: (NSArray *) activations;

/**
 * When offline content is receive and cached internally (signal only caches the raw data)
 * it is then passed to the delegate to have the implementing system cache whatever data is required.
 *
 * @param signal - the configured running instance of signal
 * @param activations is an array of SignalActivation that needs to have application level caching completed
 */
- (void) signal: (Signal *)signal cacheOfflineContent: (NSArray *) contents;

/**
 * When the SDK status changes, this method is executed with the new status
 *
 * @param signal - the configured running instance of signal
 * @param status new status of the SDK
 */
- (void) signal: (Signal *)signal didStatusChange: (SignalSdkStatus) status;

/**
 * When the application has location enabled, and the user has broken a geo-fence this will be called with that location.
 * It is not guaranteed that this is called when a user has entered a geo fence.
 *
 * @param signal - the configured running instance of signal
 * @param location of the geo fence entered
 */
- (void) signal: (Signal *)signal didGeoFenceEntered: (SignalLocation *) location;

/**
 * When the application has location enabled and the user has exited a geo-fence this will be called with that location.
 * It is not guaranteed that this is called for each geo fence enter event.  For example the user turned off device while inside
 * a geo fence.
 *
 * @param signal - the configured running instance of signal
 * @param location of the geo fence exited
 */
- (void) signal: (Signal *)signal didGeoFenceExited: (SignalLocation *) location;

/**
*
* @param signal - the configured running instance of signal
* @param locations of the geo fences to monitor
*/
- (void) signal: (Signal *)signal didGeoFencesUpdated: (NSArray *) locations;

/**
 * When the application enter a beacon region *
 * @param signal - the configured running instance of signal
 * @param region - the region enter
 */
- (void) signalDidBluetoothRegionEnter: (Signal *)signal;

/**
 * When the application exits a beacon region
 *
 * @param signal - the configured running instance of signal
 * @param region - the region exited
 */
- (void) signalDidBluetoothRegionExit: (Signal *)signal;

/**
 * When the application finishes registering
 *
 * @param signal - the configured running instance of signal
 * @param success whether or not sdk succeeded to register
 */
- (void) signal: (Signal *)signal didCompleteRegistration:(BOOL)success;

/**
 * When the application finishes configuring
 *
 * @param signal - the configured running instance of signal
 * @param changed whether or not configuration changed
 */
- (void) signal: (Signal *)signal didUpdateConfiguration:(BOOL)changed;

/**
 * Get tags for code
 *
 * @param signal - the configured running instance of signal
 * @param code code for which to provide tags
 */
- (NSDictionary*) signal: (Signal *)signal getTagsForCode:(SignalCodeHeard*)code customerTags:(NSDictionary*)customerTags;

/**
 * Get beacon tags for config
 *
 * @param signal - the configured running instance of signal
 */
- (NSArray*) signalGetBeaconTagsForConfig: (Signal *)signal;

@end

@protocol SignalActivationDelegate <NSObject>

/**
 * Whether or not we are allowed to activate the content
 *
 * @param signal - the configured running instance of signal
 * @param content the content we are trying to activate
 */
- (BOOL) signal: (Signal *)signal canActivateContent:(SignalActivation*)content;

@end

/**-----------------------------------------------------------------------------
 * @name Delegate
 * -----------------------------------------------------------------------------
 */



/** The `Signal` class manages the interaction with the Core Signal360 system.
 *
 *  Notifications used in delegate calls are below
 *  -SignalNotificationDidHearCode;
 *  -SignalNotificationDidReceiveActivations;
 *  -SignalNotificationPreferencesUpdated;
 *  -SignalNotificationReset;
 *  -SignalNotificationRegionUpdated;
 *  -SignalNotificationLocationMessage;
 *  -SignalNotificationCustomPayload;
 *  -SignalUserInfoChannelCode;
 *  -SignalUserInfoCustomPayload;
 *  -SignalUserInfoContentId;
 */
@interface Signal : NSObject <SignalCacheDownloaderDelegate>


/**-----------------------------------------------------------------------------
 * @name Core System Calls and Setup
 * -----------------------------------------------------------------------------
 */

/**
 * The delegate that was initialized
 */
@property (nonatomic, retain) id <SignalDelegate> delegate;

/**
 * The activation delegate
 */
@property (nonatomic, retain) id <SignalActivationDelegate> activationDelegate;

/**
 * Get the sdk singleton to execute operations on
 *
 * @return Signal singleton reference
 */
+ (Signal *) sharedInstance;


/**
 * Initialize the sdk with the application guid and a delegate that will receive all callbacks.
 *
 * @param applicationGuid unique identifier provided by Signal360 CMS
 * @param delegate for Signal360 callbacks
 * @param quiet request for sdk to prevent os popups
 */
- (void) initializeWithApplicationGUID: (NSString *) applicationGuid andDelegate: (id <SignalDelegate>) delegate quietOption:(BOOL) makeQuiet;

/**
 * Initialize the sdk with the application guid and a delegate that will receive all callbacks.
 *
 * @param applicationGuid unique identifier provided by Signal360 CMS
 * @param delegate for Signal callbacks
 */
- (void) initializeWithApplicationGUID: (NSString *) applicationGuid andDelegate: (id <SignalDelegate>) delegate;


/**
 * Start, this is for both Bluetooth and Audio. If you are interested in one or the other this can be configured via the CMS.
 *
 * @return whether or not listening began
 */
- (void) start;


/**
 * Stop, this is for both Bluetooth and Audio. If you are interested in one or the other this can be configured via the CMS.
 */
- (void) stop;

/**
 * Called to determine if start has been called
 * @return BOOL whether or not start has been called
 */
- (BOOL) isOn;

- (void) changeApplicationGUID: (NSString *) guid;

/**
 * Called to determine if Bluetooth is enabled on the device
 * @return BOOL whether or not Bluetooth is Enabled
 */
- (BOOL) isBluetoothEnabled;

/**
 * User opts out
 */
- (void) userOptOut;

/**
 * User opts out for one hour
 */
- (void) userOptOutOneHour;

/**
 * User opts in
 */
- (void) userOptIn;

/**
 * @return BOOL whether or not user has opted out
 */
- (BOOL) isUserOptedOut;

/**
 * Enable advertising identifier
 */
- (void) enableAdvertisingIdentifier;

/**
 * Disable advertising identifier
 */
- (void) disableAdvertisingIdentifier;

/**
 * @return BOOL whether or not advertising identifier is enabled
 */
- (BOOL) isAdvertisingIdentifierEnabled;

/**
 * This allows SDK integrator to pass in customer identifier
 * @param customerIdentifier
 */
- (void) setCustomerIdentifier: (NSString *) customerIdentifier;

/**
 * Reset all content, activations, cached content, etc
 */
- (void) reset;

/**
 * Manually update cached configuration
 */
- (void) checkConfig:(void (^)(SignalFetchResult))completionHandler;

/**
 * Retrieve the current status of the SDK.
 */
- (SignalSdkStatus) status;

/**
 * Request always authorization
 */
- (void) requestLocationAlwaysPermission;

/**
 * Request notifications authorization
 */
- (void) requestNotificationPermission;

/**
 * Register for remote notifications
 */
- (void) registerForRemoteNotifications;

/**
 * Did register for remote notifications callback
 */
- (void) didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

/**-----------------------------------------------------------------------------
 * @name Content Calls
 * -----------------------------------------------------------------------------
 */

/**
 * Mark an activation as engaged
 *
 * @param content that was engaged
 */
- (void) engagedContent: (SignalActivation *) content;

/**
 * Mark remote content as activated
 *
 * @param content that was engaged
 */
- (void) activatedContent: (SignalActivation *) content;

/**
 * Simulate code heard
 *
 * @param code
 */
- (void) getActivationsWithCodeHeard:(SignalCodeHeard *) code;

/**
 * Retrieve an activation identified by its id
 * @param activationId of activation to retrieve
 */
- (SignalActivation *) activationForId: (SignalId) activationId;

/**
 * Mark content with user action
 *
 * @param content that was acted on by user (right_swipe, left_swipe, click, etc)
 */
- (void) userActionOnContent: (SignalActivation *) activation withAction: (SignalUserActionType) action;

/**
 * Record custom analytics event
 *
 * @param tag identifier of analytics event
 * @param content content associated with the event
 */
- (void) customAction:(NSString*)tag onContent:(SignalActivation*)content;

- (void) deactivateActivation:(SignalActivation *)activation;

- (void) cacheActivation: (SignalActivation*)activation withCompletionHandler:(void (^)())completionHandler;

- (void) updateUserData:(NSDictionary*)userData withCompletionHandler:(void (^)(SignalOperationResult))completionHandler;

/**
 * All active activations
 */

- (NSArray*) allActiveContent;

/**
 * Access the unique identifier for this device (NOT UDID).
 */
@property (nonatomic, retain, readonly) NSString * uuid;

/**
 * Access the advertising identifier.
 */
@property (nonatomic, strong) NSString *advertisingIdentifier;

#ifdef MANAGER
-(void) setHistoricalData:(SignalHistoricalData*)historicalData;
#endif

@end
