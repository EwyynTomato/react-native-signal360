//
//  SignalUI.h
//  signal360
//
//  Created by Jonathan Glanz on 6/28/12.
//  Copyright (c) 2012 Signal360 All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SignalShared.h"
#import "SignalCache.h"

//Notifications are used on delegate callbacks to enabled linked functionality
FOUNDATION_EXPORT NSString *const SignalContentTypeURL;
FOUNDATION_EXPORT NSString *const SignalContentTypeCard;
FOUNDATION_EXPORT NSString *const SignalContentTypeCustom;

FOUNDATION_EXPORT NSString *const SignalLocalNotificationSource;
FOUNDATION_EXPORT NSString *const SignalLocalNotificationActivationId;

@class SignalUI;
@class SignalContentViewController;

BOOL SignalUIStandardContentType(NSString * contentTypeAlias);

/**
 * Protocol that allows view controllers to control if content is allowed to activate while active
 */
@protocol SignalUIViewControllerDelegate <NSObject>

@optional

/**
 * Prevent content from activating when certain views are showing
 *
 * @param signalUI - the configured running instance of signal ui
 * @param content - the content that will activate
 *
 * @return BOOL whether or not the content is allowed to activate
 **/
- (BOOL) signalUI: (SignalUI*)signalUI canActivateContent:(SignalActivation*)content;

/**
 * Prevent content from showing when certain views are showing
 *
 * @param signalUI - the configured running instance of signal ui
 * @param content - the content that will activate
 *
 * @return BOOL whether or not the content is allowed to be shown
 **/
- (BOOL) signalUI: (SignalUI*)signalUI canShowContent:(SignalActivation*)content;

/**
 * SDK will only show splash cards on presented views that respond YES to this protocol method
 *
 * @param signalUI - the configured running instance of signal ui
 * @param content - the content that will activate
 *
 * @return BOOL whether or not the content is allowed to activate
 **/
- (BOOL) signalUI: (SignalUI*)signalUI canDisplayCard:(SignalActivation*)content;

@end

/**
* Protocol that is implemented by any application that is using the UI sdk
*/
@protocol SignalUIDelegate <NSObject>

@optional

/**-----------------------------------------------------------------------------
 * @name Content Display Callbacks
 * -----------------------------------------------------------------------------
 */

/**
 * Prevent content from activating when certain views are showing
 *
 * @param signalUI - the configured running instance of signal ui
 * @param content - the content that will activate
 *
 * @return BOOL whether or not the content is allowed to activate
 **/
- (BOOL) signalUI: (SignalUI*)signalUI canActivateContent:(SignalActivation*)content;

/**
 * Prevent content from activating when certain views are showing
 *
 * @param signalUI - the configured running instance of signal ui
 * @param content - the content that will activate
 *
 * @return BOOL whether or not the content is allowed to show
 **/
- (BOOL) signalUI: (SignalUI*)signalUI canShowContent:(SignalActivation*)content;

/**
* Callback used to provide custom table cells for rendering custom content types
*
* @param signalUI - the configured running instance of signal ui
* @param tableView - the tableView that is rendering the cells
* @param content - that the cell will represent
*
* @return TableViewCell to be used in the rendering of content cells
 **/
- (UITableViewCell *) signalUI: (SignalUI*)signalUI tableView: (UITableView *) tableView cellForContent: (SignalActivation *) content;

/**
* Callback used to provide custom table cell height
*
* @param signalUI - the configured running instance of signal ui
* @param tableView - the tableView that is rendering the cells
* @param content - that the cell will represent
*
* @return CGFloat height of cell
 **/
- (CGFloat) signalUI: (SignalUI*)signalUI tableView: (UITableView *) tableView cellHeightForContent: (SignalActivation *) content;

/**
* Callback for a view that will be used to display custom content types
*
* @param signalUI - the configured running instance of signal ui
* @param content - content that needs to be displayed to the user
* @param signalContentViewController - the parent view controller that will hold the content view
*
* @return UIView - to display the content
**/
- (UIView *) signalUI: (SignalUI*)signalUI viewForContent: (SignalActivation *) content withViewController: (SignalContentViewController *) signalContentViewController;

/**
* Decorate the navigation controller, this is called before presenting the navigation controller through
* showContentNavigator
*
* @param signalUI - the configured running instance of signal ui
* @param navigationController - the controller to decorate
*
* @return the navigation controller that was decorated, this should usually be a reference to the navigation controller that was passed
*
*/

- (UINavigationController *) signalUI: (SignalUI*)signalUI decorateContentNavigationController: (UINavigationController *) navigationController;


/**
* Decorate the table view controller used for presenting a content list
*
*
* @param signalUI - instance that is configured and running
* @param tableViewController - the controller to decorate
*
* @return the navigation controller that was decorated, this should usually be a reference to the navigation controller that was passed
*
*/

- (UITableViewController *) signalUI: (SignalUI*)signalUI decorateContentTableViewController: (UITableViewController *) tableViewController;

/**
* Decorate the content view controller
*
*
* @param signalUI - instance that is configured and running
* @param contentViewController - the controller to decorate
*
* @return the decorator controller
*
*/

- (UIViewController *) signalUI: (SignalUI*)signalUI decorateContentViewController: (UIViewController *) contentViewController;

/**
 * Whether or not one can delete a list card
 *
 *
 * @param signalUI - instance that is configured and running
 * @param activation - activation that user wants to delete
 *
 */

- (bool) signalUI: (SignalUI*)signalUI canDeleteListCard:(SignalActivation*)activation;

/**
 * Proximity card was closed
 *
 *
 * @param signalUI - instance that is configured and running
 * @param activation - content that was closed
 * @param expanded - whether or not the card was expanded when it was closed
 *
 */

- (void) signalUI: (SignalUI*)signalUI didCloseSplashCard:(SignalActivation*)activation wasExpanded:(BOOL)expanded;

/**
 * Proximity card will expand with url
 *
 *
 * @param signalUI - instance that is configured and running
* @param activation - content that will expand
 * @param url - the url requested to be shown in the expanded view
 *
 * @return the url that will be shown in the expanded view
 *
 */

- (NSString *) signalUI: (SignalUI*)signalUI willExpandSplashCard:(SignalActivation*)activation withURL:(NSString*)url;

/**
 * Decorate/Customize Notification Text
 *
 *
 * @param signalUI - instance that is configured and running
 * @param notification - the notification that is to be sent
 *
 * @return the notification that will be sent
 *
 */
- (UILocalNotification *) signalUI: (SignalUI*)signalUI decorateNotification: (UILocalNotification *) notification;

/**
 * Decorate/Customize Card
 *
 *
 * @param signalUI - instance that is configured and running
 * @param fieldValues - the fieldValues that are to be displayed
 *
 * @return the fieldValues that will be sent
 *
 */
- (NSDictionary *) signalUI: (SignalUI*)signalUI decorateCard: (NSDictionary *) fieldValues;


/**
* Decorate the split view controller (iPad Only), this is called before presenting the split view controller through
* showContentNavigator
*
* @param signalUI - instance that is configured and running
* @param splitViewController - the controller to decorate
*
* @return the split view controller that was decorated, this should usually be a reference to the navigation controller that was passed
*
*/

- (UISplitViewController *) signalUI: (SignalUI*)signalUI decorateContentSplitViewController: (UISplitViewController *) splitViewController;


@end

/** The `SignalUI` class manages the interaction with the Signal360 UI system.
 *
 */
@interface SignalUI: NSObject <SignalActivationDelegate>
/**-----------------------------------------------------------------------------
 * @name Core System Calls and Setup
 * -----------------------------------------------------------------------------
 */
/** 
 Retrieve the shared UI class instance
 **/
+ (SignalUI*) sharedInstance;


/**
 Initialize the UI interface system
 
 @param delegate - Delegate for user interface call backs and decorations
 **/
- (id) initializeWithDelegate: (id <SignalUIDelegate>) delegate;

/**-----------------------------------------------------------------------------
 * @name Content Calls
 * -----------------------------------------------------------------------------
 */

/**
  Show the content navigator as a modal view controller on the parent that was passed
  during the system initialization.
*/
- (void) showContentNavigator;

/**
  Close the content navigator modal view controller; simply calls dismiss on the parent
 
  @param animated whether or not the dismissal should be animated
*/
- (void) closeContentNavigator: (BOOL) animated;

/**
 Verifies if the local notification is produced by the Signal SDK
 
 @param notification notification to validate
 
 **/

-(bool)isSignalNotification:(UILocalNotification*)notification;

/**
 Verifies if the remote notification is produced by the Signal SDK
 
 @param notification notification to validate
 
 **/

-(bool)isSignalRemoteNotification:(NSDictionary*)userInfo;

/**
  Used to retrieve the navigation controller being used for content widget management
*/
@property (nonatomic, retain, readonly) UINavigationController * contentNavigationController;

/**
 Expand the currently visible splash card
 
 **/
-(void) expandVisibleSplashCard;

/**
 Returns the currently visible splash card
 
 **/
-(SignalActivation *) visibleSplashCard;

/**
 Handles opening app due to local notification
 
 **/
-(bool)didReceiveLocalNotification:(UILocalNotification*)notification;

/**
 Handles opening app due to remote notification
 
 **/
-(bool)didReceiveRemoteNotification:(NSDictionary *)userInfo;


/**
 * User info to activation
 */
- (SignalActivation*) userInfoToSignalActivation:(NSDictionary*)userInfo;

/**
 * Relayout visible card
 */
- (void) relayoutVisibleCard;

@end
