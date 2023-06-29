//
//  VZBAuthenticationAdapter.h
//  VizbeeKit
//
//  Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VZBUserInfo.h"

/**
 * These are the set of adapter methods that enable
 * VZB to intelligently check and
 * hand-off any user authentication and authorization
 * steps to the video app.
 *
 * This adapter should be implemented by the host app
 * and passed to VZB during initialization
 * as follows.
 *
 * <pre>
 *    TODO
 * </pre>
 *
 * By default, if the AuthenticationAdapter is not set,
 * VZB assumes that authentication is not enabled for the app.
 */

typedef void (^VZBAuthCompletionBlockType)(BOOL authStatus);

@protocol VZBAuthenticationDelegate <NSObject>
@required

/**
 * Returns nil if not authenticated.
 * Returns filled in UserInfo if authenticated.
 */
-(VZBUserInfo*) getUserAuthenticationStatus;

/**
 * Method to invoke video app's custom
 * authentication process
 */
-(void) startUserAuthentication:(UIViewController *)presentingViewController;

@end
