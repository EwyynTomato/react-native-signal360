//
//  SignalContentViewController.h
//  Signal360
//
//  Created by Ryan Mannion on 10/6/11.
//  Copyright 2011 Signal360 All rights reserved.
//

#import <UIKit/UIKit.h>

@class SignalActivation;
@class SignalContentViewController;

typedef enum {
    SignalContentViewControllerStateUnknown,
    SignalContentViewControllerStateLoading,
    SignalContentViewControllerStateLoaded,
    SignalContentViewControllerStateFailed
} SignalContentViewControllerState;

@protocol SignalContentViewControllerDelegate <NSObject>
    -(void)closeContent;
@end

@interface SignalContentViewController : UIViewController <UINavigationControllerDelegate>

/**
* Set content with the option to animate the transition
*
* @param content to display
* @param animated whether or not to animate the transition
*/
- (void)setContent:(SignalActivation *)content animated: (BOOL) animated url:(NSString*)url;

/**
* Content state, whether or not content has been loaded
*/
@property (nonatomic, assign) SignalContentViewControllerState state;

/**
* Used to set and retrieve the current content being displayed
*/
@property (nonatomic, retain) SignalActivation * content;

/**
* Parses a query string into a dictionary.  This is used for JavaScript callbacks
*
* @param queryString to parse
*
* @return dictionary of key value pairs from the query string
*/
- (NSDictionary *) parseKeyValuesFromQueryString: (NSString *) queryString;


/**
* The internal webview that is being used to display the content
*/
@property (nonatomic, retain) UIWebView * webView;

@property (nonatomic, strong) id<SignalContentViewControllerDelegate> delegate;

@end


