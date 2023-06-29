//
//  VZBRequest.h
//  VizbeeKit
//

#import <Foundation/Foundation.h>
#import "VZBVideoMetadata.h"
#import "VZBScreen.h"
#import "VZBStatus.h"

@interface VZBRequest : NSObject

@property (nonatomic, copy, readonly) void (^ _Nullable didPlayOnTVCallback)(VZBScreen* _Nonnull screen);
@property (nonatomic, copy, readonly) void (^ _Nullable doPlayOnPhoneCallback)(VZBStatus* _Nonnull status);

-(instancetype _Nonnull ) initWithAppVideo:(id _Nonnull) appVideoObject
                            GUID:(NSString* _Nonnull) guid
                   startPosition:(NSUInteger) position;

// callbacks

 -(void) didPlayOnTV:(void (^_Nonnull)(VZBScreen* _Nonnull screen)) callback;

 -(void) doPlayOnPhone:(void (^_Nonnull)(VZBStatus* _Nonnull status)) callback;

// ---------
// Long term API?
// ---------

// -(void) didPlayOnTV:(void (^_Nonnull)(VZBScreen* _Nonnull screen, VZBSmartPlayOnTVReason* _Nonnull reason)) callback;
// -(void) doPlayOnPhone:(void (^_Nonnull)(VZBSmartPlayOnPhoneReason* _Nonnull reason)) callback;
// -(void) onFailure:(void (^_Nonnull)(VZBSmartPlayFailureReason* _Nonnull reason)) callback;

// getters

-(NSString* _Nonnull) getGUID;

-(NSUInteger) getStartPosition;

-(VZBVideoMetadata* _Nonnull) getMetadata;

-(id _Nonnull) getAppVideoObject;

@end
