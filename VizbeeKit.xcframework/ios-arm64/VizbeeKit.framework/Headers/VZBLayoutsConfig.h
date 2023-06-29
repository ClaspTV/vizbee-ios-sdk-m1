//
//  VZBLayoutsConfig.h
//  VizbeeKit
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, VZBLayoutType) {
    VZBLayoutTypeFutura
};


typedef NS_ENUM(NSUInteger, VZBWorkflowType) {
    VZBworkflowTypeChromecast
};

typedef NS_ENUM(NSUInteger, VZBCardType) {
    VZBCardTypeStyleable
};

typedef NS_ENUM(NSUInteger, VZBChromecastSyncType) {
    VZBSyncTypeDefault,
    VZBSyncTypeGooglecast,
    VZBSyncTypeHybrid,
    VZBSyncTypeGooglecastCustomChannel
};

typedef NS_ENUM(NSUInteger, VZBFireTVChannelType) {
    VZBFireTVChannelTypeDeviceIP,
    VZBFireTVChannelTypeDeviceID
};

@interface VZBLayoutsConfig : NSObject

-(instancetype) init;
-(instancetype) initWithType:(VZBLayoutType)type;
-(instancetype) initFromDictionary:(NSDictionary*) config;

+(instancetype) defaultLayoutForVizbeeFutura;

-(NSString*) getPlayerCardConfiguration:(NSString*) key
                           forVideoType:(BOOL)isLive;

// workflow config
@property (nonatomic, assign) VZBWorkflowType workflowType;
@property (nonatomic, assign) BOOL shouldShowFirstTimeUserHelpCard;
@property (nonatomic, assign) BOOL shouldShowDeviceSelectionCardOnDeepLink;
@property (nonatomic, assign) BOOL shouldShowDeviceSelectionCardOnSmartNotification;
@property (nonatomic, assign) BOOL shouldShowSwitchVideoCard;
@property (nonatomic, assign) BOOL shouldPlayOnPhoneOnDisconnect;

@property (nonatomic, assign) int smartPlayCardFrequency;
@property (nonatomic, assign) BOOL shouldPersistSmartPlayAcrossSessions;
@property (nonatomic, assign) BOOL shouldRepeatSmartPlayUntilUserSelectsDevice;

@property (nonatomic, strong) NSDictionary* playerCardConfiguration;

// v4.1.0 API related config
// This property must be deprecated once all customers switch to v4.1+ SDKs
@property (nonatomic, assign) BOOL shouldSmartPlayInvokePlayOnLocalDevice;

@property (nonatomic, assign) BOOL shouldSyncReconnect;

@property (nonatomic, assign) VZBChromecastSyncType chromecastSyncType __attribute__((deprecated));
@property (nonatomic, assign) VZBFireTVChannelType fireTVChannelType __attribute__((deprecated));

// cards config
@property (nonatomic, assign) VZBCardType firstTimeHelpCardType;
@property (nonatomic, assign) VZBCardType appInstallCardType;
@property (nonatomic, assign) VZBCardType pairingCardType;
@property (nonatomic, assign) VZBCardType switchVideoCardType;
@property (nonatomic, assign) VZBCardType deviceSelectionCardType;
@property (nonatomic, assign) VZBCardType playerCardType;

@end
