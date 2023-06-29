//
//  VZBAuthorizationDelegate.m
//  VizbeeKit
//
//  Created by Jesse Nikolaidis on 8/16/16.
//  Copyright © 2016 Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol VZBAuthorizationDelegate <NSObject>
@required

-(BOOL) isUserAuthorizedToPlay:(id _Nonnull)appVideoObject;

@end
