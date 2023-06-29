//
//  VZBMiniCastViewDelegate.h
//  VizbeeKit
//
//  Copyright © 2018 Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class VZBCastBarViewController;

@protocol VZBUIMiniCastViewDelegate <NSObject>

@required
- (void)miniCastViewController:(VZBCastBarViewController *)miniCastViewController
                           shouldAppear:(BOOL)shouldAppear;

@end
