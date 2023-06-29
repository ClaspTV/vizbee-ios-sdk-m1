//
//  VZBCastIconProxy.h
//  VizbeeKit
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, VZBCastingState) {
    VZBCastingStateUnavailable  = 0x00010000,  // Not connected and no TV devices are available
    VZBCastingStateScanning     = 0x00020000,  // Scanning for TV devices
    VZBCastingStateDisconnected = 0x00040000,  // Not connected but TV devices are available
    VZBCastingStateConnecting   = 0x00080000,  // Connecting to a TV device
    VZBCastingStateConnected    = 0x00100000,  // Connected to a TV device
    VZBCastingStateDeactivated  = 0x00200000   // Vizbee SDK is deactivated
};

@protocol VZBCastIconStateListener <NSObject>

-(void) onStateChange:(VZBCastingState)state;

@end

@interface VZBCastIconProxy : NSObject

-(instancetype) init;
-(void) uninit;

-(VZBCastingState) getCastState;
-(NSArray *) getAllowedScreenDevices;
-(NSString *) getConnectedDeviceFriendlyName;
-(void) addStateChangeListener:(id<VZBCastIconStateListener>) listener;
-(void) removeStateChangeListener:(id<VZBCastIconStateListener>) listener;

-(void) click:(UIViewController*) presentingController;

//--------------------------------
#pragma mark - Cast authorization
//--------------------------------

-(BOOL) isAuthorizedToCast;

@end
