//
//  SignalIndicatorView.h
//  signal360
//
//  Created by Jonathan Glanz on 6/28/12.
//  Copyright (c) 2012 Signal360 All rights reserved.
//

#import <UIKit/UIKit.h>

/**
* Signal360IndicatorView is a customizable view that blinks whenever a Sonic Notify trigger is detected. In addition it functions a a button which opens a listview of past received content when using SignalUIas an out of the box app.
 
 Using Interface Builder, add a view right at the top of your root view controller with the class SignalIndicatorView.
 
*/
@interface SignalIndicatorView : UIButton

/**
* signalDetected can be polled for whether or not the signal has been heard in the past 3 seconds
*/
@property (readonly) BOOL signalDetected;

-(void)setBadgeEnabled:(bool)enabled;

-(void)setBadgeColor:(UIColor*)color;

-(void)setBadgePosition:(CGPoint)pos;

@end
