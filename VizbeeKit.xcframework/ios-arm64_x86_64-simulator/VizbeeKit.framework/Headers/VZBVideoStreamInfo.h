//
//  VZBVideoStreamInfo.h
//  VizbeeKit
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VZBScreenType.h"
#import "VZBVideoTrackInfo.h"

/**
 * Encapsulates all the streaming info a video.
 */
@interface VZBVideoStreamInfo : NSObject

@property (nonatomic, copy) NSString* guid;

@property (nonatomic, strong) NSURL* videoURL;
@property (nonatomic, assign) VZBScreenProtocolType protocolType;

//----------------------------------
#pragma mark - Tracks
//----------------------------------

/** array of VZBVideoTrackInfo */
@property (nonatomic, strong) NSArray<VZBVideoTrackInfo*>* tracks;

@property (nonatomic, assign) VZBScreenDRMType drmType;
@property (nonatomic, strong) NSURL* drmLicenseURL;
@property (nonatomic, copy) NSString* drmCustomData;

@property (nonatomic, copy) NSDictionary* customStreamInfo;

-(void) copy:(VZBVideoStreamInfo*)src;

@end
