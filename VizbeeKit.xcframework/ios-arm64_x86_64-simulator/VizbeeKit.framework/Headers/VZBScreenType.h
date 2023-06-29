//
//  VZBScreenType.h
//  VizbeeKit
//
//  Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, VZBScreenProtocolType) {
    VZBScreenProtocolTypeAny,
    VZBScreenProtocolTypeHTTP,
    VZBScreenProtocolTypeHLS,
    VZBScreenProtocolTypeSmoothStreaming,
    VZBScreenProtocolTypeDASH,
    VZBScreenProtocolTypeOther
};

typedef NS_ENUM(NSUInteger, VZBScreenDRMType) {
    VZBScreenDRMTypeAny,
    VZBScreenDRMTypeNone,
    VZBScreenDRMTypePlayReady,
    VZBScreenDRMTypeAdobeAccess,
    VZBScreenDRMTypeAES128,
    VZBScreenDRMTypeWideVineModular,
    VZBScreenDRMTypeWideVineClassic,
    VZBScreenDRMTypeVerimatrix,
    VZBScreenDRMTypeOther
};

@interface VZBScreenType : NSObject

/** equals cloud type */
@property (nonatomic, copy) NSString* typeName; 

@property (nonatomic, assign) VZBScreenProtocolType suggestedProtocolType;

@property (nonatomic, assign) VZBScreenDRMType suggestedDRMType;

@property (nonatomic, strong) id other;

@property (nonatomic, assign) NSDictionary* streamInfo;

+(NSString*) drmTypeToString:(VZBScreenDRMType) drm;
+(NSString*) protocolTypeToString:(VZBScreenProtocolType)screenProtocolType;

@end
