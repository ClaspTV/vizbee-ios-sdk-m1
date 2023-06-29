#import <Foundation/Foundation.h>

@class VZBDeviceClient;

@protocol VZBVolumeStatusDelegate <NSObject>

- (void)onVolumeChanged;

@end

@interface VZBVolumeClient : NSObject

@property (nonatomic, readonly) BOOL supportsVolumeControl;

- (instancetype)initWithDeviceClient:(VZBDeviceClient *)deviceClient;

- (float)getVolume;

- (BOOL)isMute;

- (void)setVolume:(float)volume;

- (void)setMute:(BOOL)mute;

- (void)addVolumeStatusDelegate:(id<VZBVolumeStatusDelegate>)delegate;

- (void)removeVolumeStatusDelegate:(id<VZBVolumeStatusDelegate>)delegate;

- (void)tearDown;

@end
