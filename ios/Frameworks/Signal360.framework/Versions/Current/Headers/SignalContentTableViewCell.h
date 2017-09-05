//
//  SignalContentTableViewCell.h
//  Signal360
//
//  Created by Ryan Mannion on 10/6/11.
//  Copyright 2011 Signal360 All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SignalShared.h"

@interface SignalContentTableViewCell : UITableViewCell {
	SignalActivation * _content;
	CGFloat _height;
	
	UIImageView * _backgroundImage;
	UIView * _nameBackgroundView;
	UILabel * _nameLabel;
	UIView * _bottomShadeView;
}

@property (nonatomic, retain) SignalActivation * content;
@property (nonatomic, assign) CGFloat height;

@end
