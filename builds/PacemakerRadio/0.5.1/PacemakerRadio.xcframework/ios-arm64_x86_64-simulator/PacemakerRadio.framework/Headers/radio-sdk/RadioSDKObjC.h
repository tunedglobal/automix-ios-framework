
#if !defined RADIO_SDK_H
#define RADIO_SDK_H

#import <AVFoundation/AVFoundation.h>

@protocol AutomixSDKStreamingDelegate;
@protocol SocialBackendDelegate;
@protocol TunedRestDelegate;
@protocol AutomixSDKStatusObserverDelegate;
@protocol RadioUIDelegate;
@protocol TunedMusicCacheDelegate;

@class AutomixSDKList;


@interface RadioSDKObjC : NSObject

+(void)initializeWithTunedDelegate:(nonnull id<TunedRestDelegate>)tunedDelegate
                    statusDelegate:(nonnull id<AutomixSDKStatusObserverDelegate>)statusDelegate
                   radioUIDelegate:(nonnull id<RadioUIDelegate>)radioUIDelegate
                    interfaceWidth:(float)interfaceWidth
                   interfaceHeight:(float)interfaceHeight
                       countryCode:(nonnull NSString*)countryCode
                           storeId:(nonnull NSString*)storeId
                     applicationId:(nonnull NSString*)applicationId
                musicCacheDelegate:(nullable id<TunedMusicCacheDelegate>)musicCacheDelegate
                        completion:(void (^_Nullable)(NSError* _Nullable error))completion;

+(void)initializeWithStreamingDelegate:(nonnull id<AutomixSDKStreamingDelegate>)streamingDelegate
                        statusDelegate:(nonnull id<AutomixSDKStatusObserverDelegate>)statusDelegate
                       radioUIDelegate:(nonnull id<RadioUIDelegate>)radioUIDelegate
                        interfaceWidth:(float)interfaceWidth
                       interfaceHeight:(float)interfaceHeight
                           countryCode:(nonnull NSString*)countryCode
                               storeId:(nonnull NSString*)storeId
                         applicationId:(nonnull NSString*)applicationId
                            completion:(void (^_Nullable)(NSError* _Nullable error))completion;

+(nullable RadioSDKObjC*)instance;

-(nonnull UIViewController*)radioUIViewController;

-(void)getLiveShowsWithLimit:(int)limit
                       start:(nullable NSString*)start
                  completion:(void (^_Nullable)(NSError* _Nullable error, AutomixSDKList* _Nullable liveMixtapes))completion;

-(void)reportUserWithIdentifier:(nonnull NSString*)identifier
                     completion:(void (^_Nullable)(NSError* _Nullable error))completion;

-(void)reportMixtapeWithIdentifier:(nonnull NSString*)identifier
                        completion:(void (^_Nullable)(NSError* _Nullable error))completion;

-(void)notifyFollowersWithUserIdentifier:(nonnull NSString*)identifier
                                   title:(nonnull NSString*)title
                                    body:(nonnull NSString*)body
                              objectType:(nonnull NSString*)objectType
                                objectId:(nonnull NSString*)objectId
                              completion:(void (^_Nullable)(NSError* _Nullable error))completion;

-(void)joinLiveMixtapeWithIdentifier:(nonnull NSString*)identifier
                          completion:(void (^_Nullable)(NSError* _Nullable error))completion;

@end

#endif
