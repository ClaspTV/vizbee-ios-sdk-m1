//
//  VZBError.h
//  VizbeeKit
//
//  Copyright (c) Vizbee Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Error domain for Vizbee. Used in NSError */
extern NSString * const VZBErrorDomain;

/** Error codes used in NSError */
typedef NS_ENUM(NSInteger, VZBErrorCode) {
    
    /** Generic Vizbee Error code */
    VZBErrorCodeGeneric = 2300,
    
    VZBErrorCodeNone,
    
    /** Standard error code for an abstract method in Vizbee that is not implemented in a derived class */
    VZBErrorCodeAbstractMethodNotImplemented,

    /** NSError Code for when Client Services responds to REST request with an error JSON */
    VZBErrorCodeClientServicesReportedErrorJSON,
    
    /** NSError code for when DIAL is asked to launch an app already running */
    VZBErrorCodeDialCannotRelaunchRunningApp,
    
    /** NSError code for when DIAL cannot load the app store */
    VZBErrorCodeDialCannotLoadAppStore,
    
    /** NSError code for when DIAL detects 404 for app not installed */
    VZBErrorCodeDialAppNotInstalled,
    
    /** NSError code for when DIAL cannot determine the state of the screen app */
    VZBErrorCodeDialCannotExplainApp,
    
    /** NSError code for when GoogleCast is lost its connection */
    VZBErrorCodeGCastLostConnection,
    
    /** */
    VZBErrorCodeExceededTimeout,
    
    /** */
    VZBErrorCodeBadArgs,
    
    /** NSError code for when VZBCondition failed */
    VZBErrorCodeOperationConditionFailed,
    
    /** NSError code for when VZBOperation failed */
    VZBErrorCodeOperationExecutionFailed,
    
    /** Command failed*/
    VZBErrorCodeCommandFailed,
    
    VZBErrorCodeCommandCancelled,
    
    VZBErrorCodeCommandFailedPairingInProgress,
    
    VZBErrorCodeWebSockets,
    
    /** getAppStatus: app not running */
    VZBErrorCodeAppNotRunning,
    
    VZBErrorCodeScreenExitWithOlleh
};
