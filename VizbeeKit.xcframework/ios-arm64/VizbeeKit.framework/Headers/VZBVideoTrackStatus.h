//
//  VZBVideoTrackStatus.h
//  VizbeeKit
//

#import <Foundation/Foundation.h>
#import "VZBVideoTrackInfo.h"

/*
 "cc": {
     "currentTextTrack": {
         "screenTrackId": 1,
         "languageCode": "en-US"
     },
     "availableTextTracks": [
         {
             "screenTrackId": 1,
             "languageCode": "en-US"
         },
         {
             "screenTrackId": 2,
             "languageCode": "fr"
         }
     ]
 }
*/

@interface VZBVideoTrackStatus : NSObject

@property (nonatomic, strong) NSMutableArray<VZBVideoTrackInfo*>* availableTracks;

@property (nonatomic, strong) VZBVideoTrackInfo* currentTrack;

@end
