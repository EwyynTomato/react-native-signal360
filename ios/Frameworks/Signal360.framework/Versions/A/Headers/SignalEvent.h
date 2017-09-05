//
//  SignalEvent.h
//  signal360
//
//  Created by Matt Isaacs on 2/6/13.
//  Copyright (c) 2013 Signal360 All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SignalShared.h"

/**
 * Signal Event
 */
@interface SignalEvent : NSObject

/**
 * SignalId is an object that identifies the content delivered
 */
@property (nonatomic, readonly) SignalId identifier;
/**
 * json is the payload of the event metadata
 */
@property (nonatomic, retain) NSString * json;

@end
