
#if !defined RADIO_SDK_H
#define RADIO_SDK_H

#import <AVFoundation/AVFoundation.h>

#ifdef __cplusplus
#import <string>
extern "C" {
#endif
    void __b_duff_debug(const char* _Nullable message);
    void __b_duff_info(const char* _Nullable message);
    void __b_duff_warn(const char* _Nullable message);
    void __b_duff_error(const char* _Nullable message);
    void __b_duff_fatal(const char* _Nullable message);

    void __b_duff_assert_false(void);

    void __b_duff_debug_break(void);

    void __b_duff_exception_message(const char* _Nullable message);

    NSString* _Nonnull _HMACAlgorithmSign(int algorithmInt, NSString* _Nonnull input, NSString* _Nonnull key);
#ifdef __cplusplus
}
#endif

@protocol AutomixSDKStreamingDelegate;
@protocol SocialBackendDelegate;
@protocol TunedRestDelegate;
@protocol AutomixSDKStatusObserverDelegate;
@protocol RadioUIDelegate;
@protocol TunedMusicCacheDelegate;

@class AutomixSDKList;
@class AutomixSDKTrackModel;
@class RadioSDKConfig;

@interface RadioSDKObjC : NSObject

+(void)initializeWithConfig:(nonnull RadioSDKConfig*)config
              tunedDelegate:(nonnull id<TunedRestDelegate>)tunedDelegate
             statusDelegate:(nonnull id<AutomixSDKStatusObserverDelegate>)statusDelegate
            radioUIDelegate:(nonnull id<RadioUIDelegate>)radioUIDelegate
         musicCacheDelegate:(nullable id<TunedMusicCacheDelegate>)musicCacheDelegate
                 completion:(void (^_Nullable)(NSError* _Nullable error))completion;

+(BOOL)initialised;
+(nullable RadioSDKObjC*)instance;

-(void)startRadioSessionWithIdentifiers:(nonnull NSArray<NSString*>*)identifiers
                               metadata:(nullable NSArray<AutomixSDKTrackModel*>*)trackMetadataArray
                         playTrackIndex:(int)index seconds:(float)seconds autoplay:(BOOL)autoplay
                            contextType:(nullable NSString*)contextType contextId:(nullable NSString*)contextId
                             completion:(void (^_Nullable)(NSError* _Nullable error, UIViewController* _Nullable viewController))completion;
-(void)endRadioSessionWithCompletion:(void (^_Nonnull)(void))completion;

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
                          completion:(void (^_Nullable)(NSError* _Nullable error, UIViewController* _Nullable viewController))completion;

-(void)stopEngine;
-(void)setRecordingAudioDataWithFrames:(UInt32)frames numberOfChannels:(int)numberOfChannels audioPCMBuffer:(nonnull AVAudioPCMBuffer*)audioPCMBuffer;
-(int)getAudioDataWithFrames:(UInt32)frames numberOfChannels:(int)numberOfChannels fadeState:(int)fadeState audioPCMBuffer:(nonnull AVAudioPCMBuffer*)audioPCMBuffer isRecording:(nonnull BOOL*)isRecording;
-(BOOL)isAudioDeviceActiveOrRecording:(nonnull BOOL*)recording;
-(void)playWithCompletion:(void (^_Nullable)(NSError* _Nullable error))completion;
-(nonnull id<AutomixSDKStreamingDelegate>)getAutomixStreamingDelegate;
-(void)setMusicCacheDelegate:(nullable id<TunedMusicCacheDelegate>)musicCacheDelegate;
-(void)addStatusObserverDelegate:(nonnull id<AutomixSDKStatusObserverDelegate>)statusObserverDelegate;
-(void)removeStatusObserverDelegate:(nonnull id<AutomixSDKStatusObserverDelegate>)statusObserverDelegate;

+(BOOL)internetAvailable;

@end

#endif
