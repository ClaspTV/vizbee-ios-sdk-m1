//
//  VZBStatus.h
//  VizbeeKit
//

#import <Foundation/Foundation.h>

@interface VZBStatus : NSObject

typedef NS_ENUM(NSInteger, VZBStatusCode) {
    
    VZBStatusCodeSDKNotInitialized,
    VZBStatusCodeConfigForcesToPlayOnPhone,
    VZBStatusCodeVideoExcludedFromSmartPlay, 
    VZBStatusCodeFailedToResolveMetadata,
    VZBStatusCodeUserSelectedPlayOnPhone,
    VZBStatusCodeFailedToResolveStreamInfo,
    VZBStatusCodeGeneric,
};

@property (nonatomic, assign) VZBStatusCode code;

-(instancetype) initWithStatusCode:(VZBStatusCode)statusCode;

@end
