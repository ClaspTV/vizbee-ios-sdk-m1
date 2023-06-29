#import <Foundation/Foundation.h>

@class VZBDeviceInstance;

@interface VZBScreenInfo : NSObject

@property (nonatomic, strong, readonly) NSString *deviceId;
@property (nonatomic, strong, readonly) NSString *friendlyName;
@property (nonatomic, strong, readonly) NSString *model;

- (instancetype)initWithDevice:(VZBDeviceInstance *)device;

@end

