//
//  SignalContentTableViewController.h
//  Signal360
//
//  Created by Jonathan Glanz on 10/6/11.
//  Copyright 2012 Signal360 All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SignalUIDelegate;

@interface SignalContentTableViewController : UITableViewController <SignalUIViewControllerDelegate>

/**
 * Manages the data available to the table, SonicContent instances
 */
@property (nonatomic, readonly) NSMutableArray * contents;
@property (nonatomic, retain) id<SignalUIDelegate> delegate;

@end


