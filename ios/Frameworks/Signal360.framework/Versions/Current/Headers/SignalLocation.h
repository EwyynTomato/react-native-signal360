//
//  SignalLocation.h
//  signal360
//
//  Created by Matt Isaacs on 3/19/13.
//  Copyright (c) 2013 Signal360 All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SignalShared.h"

/**
 * Signal Locations are the objects which govern the geo-fence operation of the sdk. The geographic locations where the sdk starts and stops listening for Signal triggers. The behaviour and actual geographic points are added in the CMS
 */
@interface SignalLocation : NSObject

/**
 * the identifier unique on the device for the Signal Location
 */
@property (nonatomic, assign) SignalId identifier;
/**
 * The name of the location entered in the CMS
 */
@property (nonatomic, retain) NSString * name;
/**
 * The date at which the location is no longer valid and has expired
 */
@property (nonatomic, retain) NSDate * endTime;
/**
 *  The date at which the location starts being valid
 */
@property (nonatomic, retain) NSDate * startTime;
/**
 * the latitude of the location
 */
@property (nonatomic, assign) double latitude;
/**
 * the longitude of the location
 */
@property (nonatomic, assign) double longitude;
/**
 *  the range of the location which represents the radius from the center point
 */
@property (nonatomic, assign) double radius;
/**
 * the state of the location
 */
@property (nonatomic, retain) NSString * state;
/**
 * the program id to which the location belongs
 */
@property (nonatomic, assign) SignalId programId;

@end
