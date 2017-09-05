//
//  SignalBluetoothCodeHeard.h
//  signal360
//
//  Created by Alex Bell on 11/25/13.
//  Copyright (c) 2013 Signal360 All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SignalCodeHeard.h"
#import <CoreLocation/CoreLocation.h>

@interface SignalBluetoothCodeHeard : SignalCodeHeard <NSCopying>{
    int _rssiValue;
    CLProximity _proximity;
    CLLocationAccuracy _accuracy;
    BOOL _fromiBeacon;
    BOOL _securityBeacon;
}

/**
 * RSSI Value that was decoded, returns nil if none
 */
@property (nonatomic, assign) int rssiValue;

/**
 * Proximity for beacon decoded
 */
@property (nonatomic, assign) CLProximity proximity;

/**
 * Accuracy of beacons
 */
@property (nonatomic, assign) CLLocationAccuracy accuracy;

/**
 * Boolean true if code heard using security beacon
 */
@property (nonatomic, assign) BOOL securityBeacon;

@end
