//
//  VZBUICastContainerViewController.h
//  VizbeeKit
//
//  Copyright © 2018 Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VZBCastBarViewController.h"

@interface VZBUICastContainerViewController : UIViewController 

@property (strong, nonatomic) UIViewController *contentViewController;

@property (strong, nonatomic, readonly) VZBCastBarViewController *castBarViewController;

@property (assign, nonatomic) BOOL miniCastControlsEnabled;

@end
