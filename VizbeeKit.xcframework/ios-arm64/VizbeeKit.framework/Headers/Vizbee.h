//
//  Vizbee.h
//  VizbeeKit
//
//  Copyright (c) Vizbee Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>
#import <VizbeeHomeOSKit/VizbeeHomeOSKit.h>

#import "VZBRequest.h"

#import "VZBAppAdapterDelegate.h"
#import "VZBAuthenticationDelegate.h"
#import "VZBCurrentVideoDelegate.h"
#import "VZBLayoutsConfig.h"
#import "VZBCastIconProxy.h"
#import "VZBOptions.h"
#import "VZBNotificationUserInfo.h"
#import "VZBUICastContainerViewController.h"
#import "VZBCastBarViewController.h"
#import "VZBCastButton.h"

@class VZBSessionManager;
@class VZBAnalyticsManager;

/**
 * @brief The main user interface int Vizbee services
 */
@interface Vizbee : NSObject

#pragma mark - Init

/**
 * @brief initialize Vizbee SDK using the provided application ID
 * @param appID must be the unique string ID provided by Vizbee.
 * @param appAdapterDelegate required for the VizbeeSDK to interface with host application
 */
+(void) startWithAppID:(NSString * _Nonnull)appID
 andAppAdapterDelegate:(id<VZBAppAdapterDelegate> _Nonnull)appAdapterDelegate;

/**
 * @brief initialize Vizbee SDK using the provided application ID
 *
 * @param appID must be the unique string ID provided by Vizbee.
 * @param appAdapterDelegate required for the VizbeeSDK to interface with host application
 * @param isProduction determines if the app connects to a production or staging configuration service.
 * @warning <isProduction> must be YES for apps submitted to the App Store.
 */
+(void) startWithAppID:(NSString * _Nonnull)appID
 andAppAdapterDelegate:(id<VZBAppAdapterDelegate> _Nonnull)appAdapterDelegate
          isProduction:(BOOL)isProduction;

/**
 * @brief initialize Vizbee SDK using the provided application ID
 *
 * @param appID must be the unique string ID provided by Vizbee.
 * @param appAdapterDelegate required for the VizbeeSDK to interface with host application
 * @param options must be a VZBOptions object with configurable SDK options
 */
+(void) startWithAppID:(NSString * _Nonnull)appID
    appAdapterDelegate:(id<VZBAppAdapterDelegate> _Nonnull)appAdapterDelegate
      andVizbeeOptions:(VZBOptions * _Nonnull)options;

/**
 *  @brief adds a given custom attributes to the Vizbee Events.
 *
 * @param customEventAttributes must be a dictionary with valid inputs.
*/
+(void) addCustomEventAttributes:(NSDictionary * _Nonnull)customEventAttributes;

#pragma mark - UI

/**
 * Set UI Config
 * @param style must be a dictionary with style options
 */
+(void) setUIConfig:(NSDictionary * _Nonnull)style;

/**
 * Set UI Config
 * @param style must be a dictionary with style options
 * @param layouts must be VZBLayoutsConfig object with various workflow and card options
 */
+(void) setUIConfig:(NSDictionary* _Nonnull)style
            layouts:(VZBLayoutsConfig* _Nonnull) layouts;

#pragma mark - SmartHelp

/**
 * 'smartHelp:' API is used to show helpful prompts like
 * ‘SmartInstall’ or ‘SmartFirstTimeHelp’ in-app messages to the user.
 *  @param presentingViewController used to present smarthelp card
 */
+(BOOL) smartHelp:(UIViewController *_Nonnull)presentingViewController;

//----------------------------------
#pragma mark - CastIcon Proxy
//----------------------------------

/**
 * @brief creates and returns a cast icon proxy object
 */
+(VZBCastIconProxy* _Nonnull) getCastIconProxy;

//----------------------------------
#pragma mark - CastButton to Navigation Controller
//----------------------------------

// old API
/**
 * @brief adds the cast icon to the navigation item
 * @param navItem the navigation bar item to insert the cast icon
 * @param viewController the related viewcontroller should the cast icon be pressed
 */
+(void) addCastIconToNavigationItem:(UINavigationItem* _Nonnull)navItem
                 withViewController:(UIViewController* _Nonnull)viewController ;

+(VZBCastButton* _Nonnull) addCastButtonToNavigationItem:(UINavigationItem*  _Nonnull)navItem
                                   withDelegate:(id<VZBCurrentVideoDelegate> _Nullable) delegate
                              forViewController:(UIViewController* _Nullable) viewController;

//----------------------------------
#pragma mark - CastButton
//----------------------------------

+(VZBCastButton* _Nonnull) createCastButton;

+(VZBCastButton* _Nonnull) createCastButtonWithDelegate:(id<VZBCurrentVideoDelegate> _Nullable) delegate;

+(VZBCastButton* _Nonnull) createCastButtonWithDelegate:(id<VZBCurrentVideoDelegate> _Nullable) delegate
               forViewController:(UIViewController* _Nullable) viewController;

//----------------------------------
#pragma mark - CastBarContainer
//----------------------------------
/*
 * @brief constructs a VZBUICastContainerViewController that embeds the given UIViewController along with
 * a VZBCastBarViewController automatically.
 *
 */
+(VZBUICastContainerViewController*_Nonnull) createUICastContainerForViewController:(UIViewController *_Nonnull)viewController;

//----------------------------------
#pragma mark - CastBar
//----------------------------------

+(VZBCastBarViewController* _Nonnull) createCastBarController;

//----------------------------------
#pragma mark - SmartPlay
//----------------------------------

/**
 * @brief intelligently determines whether to play on phone or offer TV options to user and play on TV
 * @param appVideoObject video metadata object (app specific)
 * @param startTime start time for the video (typically 0)
 * @param viewController presenting view controller should the user choose to play on phone
 */
+(BOOL) smartPlay:(id _Nonnull) appVideoObject
       atPosition:(NSTimeInterval)startTime
presentingViewController:(UIViewController * _Nonnull)viewController;

+(void) smartPlay:(VZBRequest* _Nonnull) request
presentingViewController:(UIViewController * _Nonnull)viewController;

//----------------------------------
#pragma mark - SmartNotification
//----------------------------------

+(void) application:(UIApplication* _Nonnull)application
didRegisterForRemoteNotificationsWithDeviceToken:(NSData* _Nonnull)deviceToken;

+(void) handleNotificationResponse:(UNNotificationResponse*_Nullable) response
                          onFinish:(void (^_Nullable)(NSError*_Nullable)) finishHandler;

+(void) handleNotificationResponseWithUserInfo:(VZBNotificationUserInfo* _Nullable) userInfo
                                      onFinish:(void (^_Nullable)(NSError* _Nullable)) finishHandler;

#pragma mark - DeepLink

/**
 * @brief to be called from within [AppDelegate application:openURL:sourceApplication:annotation:]
 *
 * This API is necessary pre iOS 9.
 * @param url The url of the deep link
 * @param sourceApplication sourceApplication
 * @return YES if the url is intended for and handled by Vizbee
 */
+(BOOL) handleDeepLink:(NSURL * _Nonnull)url
 fromSourceApplication:(NSString * _Nullable)sourceApplication;

/**
 * @brief to be called from within [AppDelegate application:continueUserActivity:restorationHandler:]
 *
 * @param userActivity passed in from the calling api
 * @return YES if the url is intended for and handled by Vizbee
 */
+(BOOL) handleUniversalLink:(NSUserActivity * _Nonnull)userActivity;

#pragma mark - Authentication

/**
 * @brief Set only if app supports authentication
 * @param authnDelegate Delegate for authentication
 */
+(void) setAuthenticationDelgate:(id<VZBAuthenticationDelegate> _Nonnull)authnDelegate;

/**
 * @brief Callback invoked on completion of user auth flow in host app
 * @param authStatus YES/NO based on authentication success/failure
 */
+(void) onUserAuthCompleted:(BOOL) authStatus;

#pragma mark - Session

/**
 * @brief Provides access to Vizbee session state information, state changes and current active session.
 * The current session in turn provides device and current video status along with volume and video playback controls.
 * @return Vizbee's session manager
 */
+(VZBSessionManager* _Nonnull) getSessionManager;

+(VZBAnalyticsManager* _Nonnull) getAnalyticsManager;

#pragma mark - HomeOS

/**
 * @brief Get instance of VZBHomeDiscovery which provides currently discovered devices and listener for
 * device list changes.
 * @return new instance of VZBHomeDiscovery or null if {Vizbee.startWithAppID(appId, , appAdapterDelegate)} has not been called previously
 */
+(id<VZBHomeDiscovery>_Nullable) getHomeDiscovery;

/**
 * @brief Get new instance of VZBHomeFlows to start a Vizbee UI flow.
 * @return new instance of VZBHomeFlows or null if {Vizbee#startWithAppID(appId, , appAdapterDelegate)} has not been called previously
 */
+(VZBHomeFlows *_Nullable) getHomeFlows;

//----------------------------------
#pragma mark - Internal Use Only
//----------------------------------

+(VZBLayoutsConfig* _Nullable) getLayoutsConfig;

/*
 * @brief create a cast button as a standard UIButton.
 * @warning this is not advised for production use, but may be useful for debugging screens.
 */
+(UIButton * _Nonnull) createVizbeeButtonForViewController:(UIViewController * _Nonnull)viewController;

/*
 * @brief adds the admin button to the navigation item.
 * @warning This is used for diagnostic purposes only, not for public use.
 * @deprecated
 */
+(void) addAdminButton:(nonnull UINavigationItem *)navigationItem atViewController:(nullable UIViewController*)presentingViewController __attribute__ ((deprecated));

/**
 * @brief disable the displaying of the first time help screen when a user clicks on the cast icon for the first time.
 * IMPORTANT: Intended for INTERNAL USE ONLY
 */
+(void) disableFirstTimeUserHelpScreen __attribute__ ((deprecated));

// this will return the vizbee sdk scemantic version eg: 5.2.0
+(NSString*_Nonnull) getVersionString;

// this will return the vizbee sdk build number eg: 416
+(NSString*_Nonnull) getVersion;

@end
