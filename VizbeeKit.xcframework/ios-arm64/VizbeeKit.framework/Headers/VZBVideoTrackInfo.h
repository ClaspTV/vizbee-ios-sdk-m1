//
//  VZBVideoTrackInfo.h
//  VizbeeKit
//
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, VZBVideoTrackType) {
    VZBVideoTrackTypeUnknown,
    VZBVideoTrackTypeText,
    VZBVideoTrackTypeAudio,
    VZBVideoTrackTypeVideo
};

typedef NS_ENUM(NSUInteger, VZBVideoTextTrackSubtype) {
    
    VZBVideoTextTrackSubtypeUnknown,
    VZBVideoTextTrackSubtypeSubtitles,
    VZBVideoTextTrackSubtypeCaptions,
    VZBVideoTextTrackSubtypeDescriptions,
    VZBVideoTextTrackSubtypeChapters,
    VZBVideoTextTrackSubtypeMetadata
};

@interface VZBVideoTrackInfo : NSObject

-(instancetype) init;

-(instancetype) initWithIdentifier: (NSInteger) identifier
                 contentIdentifier: (NSString*) contentIdOrUrl
                       contentType: (NSString*) contentType
                         trackType: (VZBVideoTrackType) trackType
                       textSubtype: (VZBVideoTextTrackSubtype) trackTextSubtype
                              name: (NSString*) name
                      languageCode: (NSString*) languageCode;

-(instancetype) initWithIdentifier: (NSInteger) identifier
                 contentIdentifier: (NSString*) contentIdOrUrl
                       contentType: (NSString*) contentType
                         trackType: (VZBVideoTrackType) trackType
                       textSubtype: (VZBVideoTextTrackSubtype) trackTextSubtype
                              name: (NSString*) name
                      languageCode: (NSString*) languageCode
                        customData: (NSString*) customData __attribute__((deprecated));

-(void) copy:(VZBVideoTrackInfo*) src;

@property (nonatomic, assign) NSInteger identifier;

@property (nonatomic, copy) NSString* contentIdentifier;

@property (nonatomic, copy) NSString* contentType;

@property (nonatomic, assign) VZBVideoTrackType type;

@property (nonatomic, assign) VZBVideoTextTrackSubtype textSubtype;

@property (nonatomic, copy) NSString* name;

@property (nonatomic, copy) NSString* languageCode;

@property (nonatomic, copy) NSDictionary* customData;

@end
