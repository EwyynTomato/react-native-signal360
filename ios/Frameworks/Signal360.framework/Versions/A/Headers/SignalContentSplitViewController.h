//
//  SLSplitViewController.h
//  Signal360
//
//  Created by Ryan Mannion on 10/6/11.
//  Copyright 2011 Signal360 All rights reserved.
//

#import <UIKit/UIKit.h>

#import "SignalUI.h"
#import "SignalContentTableViewController.h"
#import "SignalContentViewController.h"



@interface SignalContentSplitViewController : UISplitViewController<UIActionSheetDelegate>

- (id) initWithSignalUI: (SignalUI*) signalUI;

@property (nonatomic, retain, readonly) UINavigationController * contentTableNavigationController;
@property (nonatomic, retain, readonly) UINavigationController * contentNavigationController;

@end
