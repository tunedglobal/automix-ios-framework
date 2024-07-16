#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "automix-sdk/AutomixSDK.h"
#import "automix-sdk/CoreDataModels/_AutomixSDKPlayLog.h"
#import "automix-sdk/CoreDataModels/AutomixSDKPlayLog.h"
#import "automix-sdk/CoreDataModels/_AutomixSDKTransitionLog.h"
#import "automix-sdk/CoreDataModels/AutomixSDKTransitionLog.h"
#import "automix-sdk/MDMCoreDataWrapper.h"

FOUNDATION_EXPORT double AutomixIQVersionNumber;
FOUNDATION_EXPORT const unsigned char AutomixIQVersionString[];
