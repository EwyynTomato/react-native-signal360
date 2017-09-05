//
//  SignalActivation.h
//  signal360
//
//  Created by Matt Isaacs on 2/6/13.
//  Copyright (c) 2013 Signal360 All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class SignalActivation;
/**
 * The Signal Activation is the object which contains a piece of content that was delivered and other information about the delivery. An activation is used by the CMS to count and sort analytics. It is also useful on the device to view information on pieces of content which may have been delivered multiple times. Each activation has one and only one piece of content tied to it.
 */
@interface SignalActivation : NSObject
/**
 *  Unique identifier which represents that specific piece of content on the device
 */
@property (nonatomic, assign) SignalId identifier;
/**
 *  The unique identifier of the content which is associated with this activation
 */
@property (nonatomic, assign) SignalId contentId;
/**
 *  The unique identifier of the program which is associated with this activation
 */
@property (nonatomic, assign) SignalId programId;
/**
 *  The unique identifier of the program which is associated with this activation
 */
@property (nonatomic, assign) SignalId programParentId;
/**
 * Activation start date
 */
@property (nonatomic, retain) NSDate* startDate;
/**
 * Activation end date
 */
@property (nonatomic, retain) NSDate* endDate;
/**
 * The beacon code which was used to trigger the activation
 */
@property (nonatomic, assign) long long int code;
/**
 * Sequence number
 */
@property (nonatomic, assign) long long int sequenceNumber;

/**
 * Content type
 */
@property (nonatomic, retain) NSString* contentType;
/**
 * Content metadata
 */
@property (nonatomic, retain) NSDictionary* fieldsDictionary;

@property (nonatomic, retain) NSString* fields;

-(NSDictionary*)fieldsDictionary;

-(NSDictionary*)displayDictionary;

-(bool)isActive;

-(bool)isListView;

-(bool)isCardView;

-(bool)isDelayed;

-(NSURL*) thumbnailUrl;

-(NSString*)thumbnail;

@end
