//
//  VZBAppAdapterDelegate.h
//  VizbeeKit
//
//  Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VZBVideoMetadata.h"
#import "VZBVideoStreamInfo.h"
#import "VZBScreenType.h"

/**
 * Should be implemented by the host application
 * to interface with the Vizbee SDK
 */
@protocol VZBAppAdapterDelegate <NSObject>
@required

/**
 * @brief fetch app's video object for a given video GUID.
 * @param guid Globally Unique ID for the video.
 * @param successCallback asynchronous success callback.
 * @param failureCallback asynchronous failure callback.
 */
-(void) getVideoInfoByGUID:(nonnull NSString *)guid
                 onSuccess:(void(^_Nonnull)(id _Nonnull appVideoObject))successCallback
                 onFailure:(void(^_Nonnull)(NSError* _Nonnull error))failureCallback;

/**
 * Map host app's video object to Vizbee video metadata for a given video GUID.
 * @param appVideoObject any datatype that naturally encapsulates the host app's video metadata
 * @param successCallback asynchronous success callback.
 * @param failureCallback asynchronous failure callback.
 */
-(void) getVZBMetadataFromVideo:(id _Nonnull)appVideoObject
                      onSuccess:(void(^_Nonnull)(VZBVideoMetadata* _Nonnull videoMetadata))successCallback
                      onFailure:(void(^_Nonnull)(NSError* _Nonnull error))failureCallback;

/**
 * Map host app's video object to Vizbee stream info for a given video GUID.
 * @param appVideoObject any datatype that naturally encapsulates the host app's video metadata
 * @param successCallback asynchronous success callback.
 * @param failureCallback asynchronous failure callback.
 */
-(void) getVZBStreamInfoFromVideo:(id _Nonnull)appVideoObject
                        forScreen:(nonnull VZBScreenType*)screenType
                        onSuccess:(void(^_Nonnull)(VZBVideoStreamInfo* _Nonnull videoStreamInfo))successCallback
                        onFailure:(void(^_Nonnull)(NSError* _Nonnull error))failureCallback;

/**
 * Launch the host app's ViewController to play video on the phone.
 *
 * @see smartPlay
 */
-(void) playVideoOnPhone:(id _Nonnull) appVideoObject
              atPosition:(NSTimeInterval)playHeadTime
          shouldAutoPlay:(BOOL) shouldAutoPlay
presentingViewController:(UIViewController * _Nonnull)viewController;

/**
 * @brief Go to a presenting view controller in the app to play a new deeplinked video.
 *
 * This method is called when a deep link or universal link is received by the Vizbee SDK.
 * Vizbee request the app to go to a presenting controller for the deeplinked video so the
 * video can be played on the phone or TV.
 *
 * @param guid a Globally Unique ID for video
 * @param successCallback asynchronous success callback.
 * @param failureCallback asynchronous failure callback.
 */
-(void) goToViewControllerForGUID:(NSString* _Nonnull)guid
                        onSuccess:(void(^_Nonnull)(UIViewController* _Nonnull presentingViewController))successCallback
                        onFailure:(void(^_Nonnull)(NSError* _Nonnull error))failureCallback;

@end
