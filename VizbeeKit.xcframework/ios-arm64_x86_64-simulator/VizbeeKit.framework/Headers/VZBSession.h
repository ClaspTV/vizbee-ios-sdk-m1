#import <Foundation/Foundation.h>
#import "VZBScreen.h"
#import "VZBVideoClient.h"
#import "VZBVolumeClient.h"

@class VZBDeviceInstance;

@interface VZBSession : NSObject

@property (nonatomic, readonly, strong, nonnull) VZBScreen* vizbeeScreen;
@property (nonatomic, readonly, strong, nonnull) VZBVolumeClient* volumeClient;
@property (nonatomic, readonly, strong, nonnull) VZBVideoClient* videoClient;

- (nonnull instancetype)initWithDevice:(nonnull VZBDeviceInstance *)device;

/**
 * @brief Sends a custom message to receiver device.
 * @param name event name.
 * @param data payload sent to receiver device. Expected as JSON.
*/
- (void)sendEventWithName:(nonnull NSString *)name
                  andData:(nonnull NSDictionary *)data;

@end
