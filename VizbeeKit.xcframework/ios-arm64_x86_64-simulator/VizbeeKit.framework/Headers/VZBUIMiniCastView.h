//
//  VZBCastBarViewController.h
//  VizbeeKit
//
//  Copyright © 2018 Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VZBUIMiniCastViewDelegate.h"

@protocol VZBUIMiniCastView <NSObject>
@required

@property (nonatomic, weak) id<VZBUIMiniCastViewDelegate> delegate;

@property (nonatomic, weak) UIViewController* associatedViewController;

@property (nonatomic, readonly, assign) BOOL active;

@property (nonatomic, readonly, assign) CGFloat minHeight;

@end
