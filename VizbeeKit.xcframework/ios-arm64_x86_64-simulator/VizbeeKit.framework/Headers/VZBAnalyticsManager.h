//
//  VZBAnalyticsManager.h
//  VizbeeKit
//
//  Copyright (c) Vizbee Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// This class provides various events and attributes
// related to UI Cards & UI Actions.
// Apps must register to get notified about various
// events that the SDK triggers at various UI flows.
//
// Use the `disable` API to disable sending all events,
// by default it's enabled.

typedef NS_ENUM(NSUInteger, VZBAnalyticsEventType) {
        
    // smart prompt
    VZBAnalyticsEventTypeCastIntroductionCardShown,
    VZBAnalyticsEventTypeSmartInstallCardShown,
    
    // device selection
    VZBAnalyticsEventTypeCastIconDeviceSelectionCardShown,
    VZBAnalyticsEventTypeSmartPlayDeviceSelectionCardShown,
    VZBAnalyticsEventTypeSmartNotificationDeviceSelectionCardShown,
    VZBAnalyticsEventTypeScreenDeviceSelected,
    
    // play selection
    VZBAnalyticsEventTypePlayOnPhoneSelected,
    VZBAnalyticsEventTypePlayOnTVSelected
};

@protocol VZBAnalyticsDelegate<NSObject>

-(void) onAnalyticsEvent:(VZBAnalyticsEventType) event
                withAttrs:(NSDictionary*) attrs;

@end

@interface VZBAnalyticsManager : NSObject

-(void) addAnalyticsDelegate:(id<VZBAnalyticsDelegate>) delegate;

-(void) removeAnalyticsDelegate:(id<VZBAnalyticsDelegate>) delegate;

-(void) enable;
-(void) disable;

@end
