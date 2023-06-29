#import <Foundation/Foundation.h>
#import "VZBVideoStatus.h"

@class VZBCurrentVideoModel;

@protocol VZBVideoStatusUpdateDelegate <NSObject>

- (void)onVideoStatusUpdate:(VZBVideoStatus *)videoStatus;

@end

@interface VZBVideoClient : NSObject

- (instancetype)initWithVideoModel:(VZBCurrentVideoModel *)videoModel;

- (void)play;

- (void)pause;

- (void)seek:(long)position;

- (void)stop;

- (void)setActiveTracks:(NSArray<VZBVideoTrackInfo*>*) tracks;

- (VZBVideoStatus *)getVideoStatus;

- (void)addVideoStatusDelegate:(id<VZBVideoStatusUpdateDelegate>)delegate;

- (void)removeVideoStatusDelegate:(id<VZBVideoStatusUpdateDelegate>)delegate;

- (void)tearDown;

@end
