
//
//  SignalCodeHeard.h
//  signal360
//
//  Created by Alex Bell on 11/25/13.
//  Copyright (c) 2013 Signal360 All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SignalCodeHeard : NSObject <NSCopying>{
    long _beaconCode;
    long _timeCodeHeard;
    NSArray * _codesHeard;
    NSDate * _timeCodeWasHeard;
}

/**
 * Code that was heard by the beacon
 */
@property (nonatomic, assign) long beaconCode;
/**
 * The time that the code was heard
 */
@property (nonatomic, assign) long timeCodeHeard;
/**
 * Array of codes heard
 */
@property (nonatomic, retain) NSArray * codesHeard;


-(id) initWithBeaconCode:(long) beaconCode;
-(id) initWithBeaconCode:(long) beaconCode andTime:(long) time;

@end