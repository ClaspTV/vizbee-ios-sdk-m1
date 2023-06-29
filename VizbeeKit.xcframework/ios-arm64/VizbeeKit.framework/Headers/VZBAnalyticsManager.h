//
//  VZBAnalyticsManager.h
//  VizbeeKit
//
//  Copyright (c) Vizbee Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, VZBAnalyticsEventType) {
    VZBAnalyticsEventTypeCastIntroductionCardShown,
    VZBAnalyticsEventTypeSmartInstallCardShown
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
