//
//  VZBOptions.h
//  VizbeeKit
//
//  Copyright © 2018 Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VZBLayoutsConfig.h"
#import "VZBAuthenticationDelegate.h"
#import "VZBAuthorizationDelegate.h"

@interface VZBOptions : NSObject

/**
 * Point to Vizbee production/staging config, must be set to 'true' when submitting apps to App Store
 */
@property (nonatomic, assign) BOOL isProduction;

/**
 * Dictionary with Vizbee style options
 */
@property (nonatomic, strong) NSDictionary * _Nullable uiConfig;

/**
 * Configuration with various workflow and card options
 */
@property (nonatomic, strong) VZBLayoutsConfig * _Nullable layoutsConfig;

/**
 * creates a new UIWindow and shows all Vizbee cards at a specified window level.
 */
@property (nonatomic, assign) UIWindowLevel useVizbeeUIWindowAtLevel;

/**
 * Optional delegate set for apps which support authentication
 */
@property (nonatomic, strong) id<VZBAuthenticationDelegate> _Nullable authenticationDelegate;

/**
 * Optional delegate set for apps which support authentication and authorization
 */
@property (nonatomic, strong) id<VZBAuthorizationDelegate> _Nullable authorizationDelegate;

/**
 * Custom set of attributes Vizbee collects for customer metrics
 */
@property (nonatomic, strong) NSDictionary * _Nullable customMetricsAttributes;

@end
