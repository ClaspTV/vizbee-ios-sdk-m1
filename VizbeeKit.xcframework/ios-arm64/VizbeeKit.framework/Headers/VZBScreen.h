#import <Foundation/Foundation.h>
#import "VZBScreenType.h"
#import "VZBScreenInfo.h"

@class VZBDeviceInstance;

@interface VZBScreen : NSObject

@property (nonatomic, strong, readonly) VZBScreenType *screenType;
@property (nonatomic, strong, readonly) VZBScreenInfo *screenInfo;

- (instancetype)initWithDevice:(VZBDeviceInstance *)device;

@end