//
// VZBNotificationUserInfo.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VZBNotificationUserInfo : NSObject

+(instancetype) from:(NSDictionary*)userInfo;

@property (nonatomic, copy) NSString* sender;
@property (nonatomic, copy) NSString* session;

@property (nonatomic, copy) NSString* campaign;
@property (nonatomic, copy) NSString* title;
@property (nonatomic, copy) NSString* body;

@property (nonatomic, copy) NSString* guid;

@property (nonatomic, copy) NSString* tapToTV;
@property (nonatomic, copy) NSString* screenDeviceType;
@property (nonatomic, copy) NSString* screenFriendlyName;
@property (nonatomic, copy) NSArray* screenDeviceTypeList;

@end

