#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VZBSession.h"

typedef NS_ENUM(NSUInteger, VZBSessionState) {
    VZBSessionStateNoDeviceAvailable,
    VZBSessionStateNotConnected,
    VZBSessionStateConnecting,
    VZBSessionStateConnected
};

@protocol VZBSessionStateDelegate<NSObject>

- (void)onSessionStateChanged:(VZBSessionState)newState;

@end

@interface VZBSessionManager : NSObject

- (VZBSessionState)getSessionState;

- (void)addSessionStateDelegate:(id<VZBSessionStateDelegate>)delegate;

- (void)removeSessionStateDelegate:(id<VZBSessionStateDelegate>)delegate;

- (BOOL)isConnecting;

- (BOOL)isConnected;

- (void)disconnectSession;

- (VZBSession *)getCurrentSession;

- (void)onCastIconTapped:(UIViewController *)presentingViewController;

- (void)trackDeviceSelectionShownEvent;

@end
