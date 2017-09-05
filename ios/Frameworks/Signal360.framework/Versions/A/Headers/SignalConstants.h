//
//  SignalConstants.h
//  signal360
//
//  Created by Ryan Mannion on 11/10/11.
//  Copyright (c) 2011 Signal360 All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


#define SN_API_TIMEOUT					                      30
#define SN_API_DEVICETYPEALIAS			                      ((UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) ? SignalDeviceTypePad : SignalDeviceTypePhone)


#define SN_DB_NAME						                      @"Signal3602"
//#define BACKGROUND_TIMER_SECONDS                              ((60*10) - 30)



//Location Constants
#define LOCATION_ENABLED                                      true
#define LOCATION_DEFAULT_RADIUS                               500
#define LOCATION_DEFAULT_LIMIT_RETURNED                       1000
#define SN_LOCATION_DEFAULT_SEARCHING_DB_DISTANCE             .1
#define SN_LOCATION_CONTINUOUS_NUMBER_REGIONS                 2000
#define SN_LOCATION_DISTANCE_TRAVELED_BEFORE_UPDATE_MONITORED_REGIONS   1000
#define SN_LOCATION_DISTANCE_TRAVELED_BEFORE_SERVER_CONFIG_FOR_REGIONS   5000
#define SN_LOCATION_MAX_REGIONS_REQUEST_FROM_SERVER             50

//Office Debugging
#define SONICNOTIFY_OFFICE_LATITUDE                           40.751248
#define SONICNOTIFY_OFFICE_LONGITUDE                          -74.004389

//Database constants
#define SONIC_SCHEMA_VERSION                                      8

//Pending content time out (how long the ui system should wait to check for pending content to display)
#define SONIC_PENDING_CONTENT_TIMEOUT                              0.1

//Bluetooth
#define SN_IBEACON_UUID                                              @"1F4FB808-E87A-4E0F-8D01-BD9FC717D112"   //This is the UUID searched for by the OS. It should be unique among the beacons we manufacture.
#define SNS_IBEACON_UUID                                              @"805237AE-EAE5-4376-8160-65AAB33084C5"   //This is the UUID searched for by the OS. It should be unique among the beacons we manufacture.


#define SN_IBEACON_ID                                                @"com.sonic.ibeacon"
#define SNS_IBEACON_ID                                                @"com.sonic.ibeaconS"


#define SN_BEACON_TIME_BETWEEN_HITS                                 1.0 // This is the time in seconds between calls with the same beacon code are sent to the SDK.
#define SN_BTLE_SCAN_PERIOD											4
//#define SN_BTLE_EXP_PERIOD											(60.0 * 15.0)
#define SN_BTLE_EXP_PERIOD											10.0
#define SN_BTLE_RSSI_TRIGGER_RATIO									0.05
#define SN_BTLE_RSSI_LIMIT											-100

#define SIGNAL_HEARD_CODE_TIMEOUT                                   3

#define BLUETOOTH_CODE_HEARD_RSSI_EQUAlITY_THRESHOLD                10