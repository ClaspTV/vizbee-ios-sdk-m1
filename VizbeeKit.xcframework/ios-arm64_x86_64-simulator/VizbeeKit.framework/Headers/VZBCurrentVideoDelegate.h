//
//  VZBCurrentVideoDelegate.h
//  VizbeeKit
//

#import <Foundation/Foundation.h>
#import "VZBRequest.h"

@protocol VZBCurrentVideoDelegate <NSObject>
@optional

-(id) getCurrentVideo DEPRECATED_MSG_ATTRIBUTE("Deprecated - please use 'getRequest'");

-(NSTimeInterval) getCurrentPlaybackPosition DEPRECATED_MSG_ATTRIBUTE("Deprecated - please use 'getRequest'");

-(VZBRequest*) getRequest;

@end
