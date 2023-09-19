//
// VZBSmartPlayOptions.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, VZBSmartPlayCardVisibility) {
    VZBSmartPlayCardVisibilityShowHideBasedOnConfiguration,
    VZBSmartPlayCardVisibilityForceShow,
    VZBSmartPlayCardVisibilityForceHide,
};

@interface VZBSmartPlayOptions : NSObject

@property (nonatomic, assign) BOOL isFromSmartNotification;

@property (nonatomic, assign) VZBSmartPlayCardVisibility smartPlayCardVisibility;

@end
