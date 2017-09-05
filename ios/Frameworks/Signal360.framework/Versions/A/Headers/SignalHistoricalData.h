//
//  SignalHistoricalData.h
//  Manager
//
//  Created by Alex Bell on 10/24/13.
//  Copyright (c) 2013 Sonic Notify. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SignalHistoricalData : NSObject {
    NSMutableArray *            _arrayOfPastAudioFFTData;
	NSMutableArray *            _arrayOfPastBluetoothRSSIData;
    //NSNumber * _audioIndex;
    //NSNumber * _bluetoothIndex;
}

@property (nonatomic, retain)   NSMutableArray *               arrayOfPastAudioFFTData;
@property (nonatomic, retain)   NSMutableArray *               arrayOfPastBluetoothRSSIData;
//@property (nonatomic, assign)   NSNumber * audioIndex;
//@property (nonatomic, assign)   NSNumber * bluetoothIndex;

- (void) addAudioValue:(int) value;
- (void) addBluetoothValue:(NSNumber *) value;
- (NSMutableArray *) getHistoricalAudioData;
- (NSMutableArray *) getHistoricalBluetoothData ;
- (NSNumber *) signalLevelAudio ;


@end
