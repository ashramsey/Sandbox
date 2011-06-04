//
//  SandboxAppDelegate.h
//  Sandbox
//
//  Created by Ashley Ramsey on 4/06/11.
//  Copyright 2011 ashramsey. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SandboxViewController;

@interface SandboxAppDelegate : NSObject <UIApplicationDelegate> {

}

@property (nonatomic, retain) IBOutlet UIWindow *window;

@property (nonatomic, retain) IBOutlet SandboxViewController *viewController;

@end
