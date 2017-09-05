//
//  SignalAudioCodeHeard.h
//  signal360
//
//  Created by Alex Bell on 11/25/13.
//  Copyright (c) 2013 Signal360 All rights reserved.
//

#import "SignalCodeHeard.h"

@interface SignalAudioCodeHeard : SignalCodeHeard <NSCopying>{
    long _timeInterval;
    int _customPayload;
}

/**
 * Time Interval that was decoded, returns nil if none
 */
@property (nonatomic, assign) long timeInterval;

/**
 * Custom Payload that was decoded, returns nil if none
 */
@property (nonatomic, assign) int customPayload;

@end
