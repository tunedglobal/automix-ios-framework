
#if !defined AUTOMIX_SDK_H
#define AUTOMIX_SDK_H

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
@protocol AutomixSDKStatusObserverDelegate;
@protocol TunedRestDelegate;
@protocol RadioUIDelegate;
@protocol SocialBackendDelegate;
@protocol AutomixNetworkObserver;
@protocol TunedMusicCacheDelegate;
@class AutomixSDKTrackModel;
@class AutomixSDKStatus;

typedef void (^CompletionWithError)(NSError* _Nullable error);
typedef void (^CompletionWithErrorAndPlaybackState)(NSError* _Nullable error, AutomixSDKStatus* _Nonnull status);

/// AutomixSDKObjC represents the AutomixIQ SDK and exposes all its functionality for use in Objective-C classes. It follows a Singleton pattern.
@interface AutomixSDKObjC : NSObject

@property (nonatomic, assign) BOOL on;

#ifdef HAVE_AUTOMIXIQ

+(BOOL)initialised;
+(nonnull NSError*)automixSDKErrorWithCode:(int)code;
+(nonnull NSString*)errorDescriptionWithCode:(int)code;

+(void)initialiseWithTunedDelegate:(nonnull id<TunedRestDelegate>)tunedDelegate
                    statusDelegate:(nullable id<AutomixSDKStatusObserverDelegate>)statusDelegate
                       countryCode:(nonnull NSString*)countryCode
                           storeId:(nonnull NSString*)storeId
                     applicationId:(nonnull NSString*)applicationId
                musicCacheDelegate:(nullable id<TunedMusicCacheDelegate>)musicCacheDelegate
                        completion:(nullable CompletionWithError)completion;

+(void)initialiseWithStreamingDelegate:(nonnull id<AutomixSDKStreamingDelegate>)streamingDelegate
                        statusDelegate:(nullable id<AutomixSDKStatusObserverDelegate>)statusDelegate
                           countryCode:(nonnull NSString*)countryCode
                               storeId:(nonnull NSString*)storeId
                         applicationId:(nonnull NSString*)applicationId
                            completion:(nullable CompletionWithError)completion;

+(BOOL)internetAvailable;
+(nullable instancetype)instance;

-(void)clearCacheWithCompletion:(nullable CompletionWithError)completion;

-(void)setMusicCacheDelegate:(nullable id<TunedMusicCacheDelegate>)musicCacheDelegate;
-(void)addStatusObserverDelegate:(nonnull id<AutomixSDKStatusObserverDelegate>)statusObserverDelegate;
-(void)removeStatusObserverDelegate:(nonnull id<AutomixSDKStatusObserverDelegate>)statusObserverDelegate;

-(void)prepareRefocusUIWithWidth:(float)width height:(float)height
                      uiDelegate:(nullable id<RadioUIDelegate>)uiDelegate
           socialBackendDelegate:(nullable id<SocialBackendDelegate>)socialBackendDelegate
                     countryCode:(nonnull NSString*)countryCode
                    tunedStoreId:(nonnull NSString*)tunedStoreId
                       configURL:(nonnull NSURL*)configURL;
-(nullable UIViewController*)radioUIViewController;
-(void)joinLiveMixtapeWithIdentifier:(nonnull NSString*)identifier
                          completion:(nullable CompletionWithError)completion;

-(void)automixOnWithCompletion:(nullable CompletionWithError)completion;
-(void)automixOnWithIdentifiers:(nonnull NSArray<NSString*>*)identifiers
                       metadata:(nullable NSArray<AutomixSDKTrackModel*>*)trackMetadataArray
                 playTrackIndex:(int)index seconds:(float)seconds autoplay:(BOOL)autoplay
                    contextType:(nullable NSString*)contextType contextId:(nullable NSString*)contextId
                     completion:(nullable CompletionWithError)completion;
-(void)automixOffWithCompletion:(nullable CompletionWithErrorAndPlaybackState)completion;
-(void)resetPlaylistToEmptyWithCompletion:(nullable CompletionWithError)completion;

-(void)loadTracksWithIdentifiers:(nonnull NSArray<NSString*>*)identifiers
                        metadata:(nullable NSArray<AutomixSDKTrackModel*>*)trackMetadataArray
                  playTrackIndex:(int)index seconds:(float)seconds autoplay:(BOOL)autoplay
                     contextType:(nullable NSString*)contextType contextId:(nullable NSString*)contextId
                      completion:(nullable CompletionWithError)completion;
-(void)addTracksWithIdentifiers:(nonnull NSArray<NSString*>*)identifiers
                       metadata:(nullable NSArray<AutomixSDKTrackModel*>*)trackMetadataArray
                          index:(int)index completion:(nullable CompletionWithError)completion;
-(void)addTrackWithIdentifier:(nonnull NSString*)identifier
                     metadata:(nullable AutomixSDKTrackModel*)metadata
                        index:(int)index completion:(nullable CompletionWithError)completion;
-(void)removeTrackAtIndex:(int)index completion:(nullable CompletionWithError)completion;
-(void)moveTrackAtIndex:(int)index toIndex:(int)index completion:(nullable CompletionWithError)completion;
-(void)playWithCompletion:(nullable CompletionWithError)completion;
-(void)pauseWithCompletion:(nullable CompletionWithError)completion;
-(void)nextWithCompletion:(nullable CompletionWithError)completion;
-(void)previousWithCompletion:(nullable CompletionWithError)completion;
-(void)backWithCompletion:(nullable CompletionWithError)completion;
-(void)toggleReplayWithCompletion:(nullable CompletionWithError)completion;
-(void)setReplayOn:(BOOL)on completion:(nullable CompletionWithError)completion;
-(void)seekToSeconds:(float)seconds completion:(nullable CompletionWithError)completion;
-(void)skipToTrackAtIndex:(int)index completion:(nullable CompletionWithError)completion;
-(void)setFilterExplicit:(BOOL)filterExplicit completion:(nullable CompletionWithError)completion;
-(void)reorderTracksWithNewOrder:(nonnull NSArray<NSString*>*)newOrder completion:(nullable CompletionWithError)completion;
-(void)playTrackToEndThenPauseWithCompletion:(nullable CompletionWithError)completion;
-(void)setAutomixPlaySpeed:(float)playSpeed completion:(nullable CompletionWithError)completion;
-(void)setAutomixVolumeNormalised:(float)volumeNormalised completion:(nullable CompletionWithError)completion;
-(void)toggleMuteWithCompletion:(nullable CompletionWithError)completion;
-(void)setMuteOn:(BOOL)on completion:(nullable CompletionWithError)completion;
-(void)setPreferredTransitionDurationSeconds:(float)preferredTransitionDurationSeconds completion:(nullable CompletionWithError)completion;
-(void)loopPlayingTrackWithCompletion:(nullable CompletionWithError)completion;
-(void)stopLoopingPlayingTrackWithCompletion:(nullable CompletionWithError)completion;
-(void)setVinylStartStopEnabled:(BOOL)enabled completion:(nullable CompletionWithError)completion;

-(void)stopEngine;
-(int)getAudioDataWithFrames:(UInt32)frames numberOfChannels:(int)numberOfChannels fadeState:(int)fadeState audioPCMBuffer:(nonnull AVAudioPCMBuffer*)audioPCMBuffer;
-(BOOL)isAudioDeviceActive;

-(void)setWaveformPointsPerTrack:(int)waveformPointsPerTrack;
-(nullable NSArray<NSArray<NSNumber*>*>*)waveformDataForTrackWithIdentifier:(nonnull NSString*)identifier applyTransitions:(BOOL)applyTransitions;

-(void)terminate;

-(nonnull id<AutomixSDKStreamingDelegate>)getAutomixStreamingDelegate;

#endif
@end

#endif