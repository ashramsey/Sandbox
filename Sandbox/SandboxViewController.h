//
//  SandboxViewController.h
//  Sandbox
//
//  Created by Ashley Ramsey on 4/06/11.
//  Copyright 2011 ashramsey. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SandboxUtilities.h"

@interface SandboxViewController : UIViewController {
    IBOutlet UITextView *textView;
}

@property (nonatomic, retain) IBOutlet UITextView *textView;

- (void) sandbox;

@end
