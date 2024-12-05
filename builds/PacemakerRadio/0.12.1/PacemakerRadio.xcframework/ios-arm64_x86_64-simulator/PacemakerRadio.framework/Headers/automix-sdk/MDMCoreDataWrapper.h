
#if !defined MDMCOREDATAWRAPPER_H
#define MDMCOREDATAWRAPPER_H


@class AutomixSDKPlayLog;
@class AutomixSDKTransitionLog;
@class MDMPersistenceController;
@class NSFetchRequest;


@interface _MDMCoreDataWrapper: NSObject

-(nonnull instancetype)initWithStoreURL:(nonnull NSURL*)storeURL model:(nonnull NSManagedObjectModel*)model;
-(void)saveContextAndWait:(BOOL)wait completion:(nullable void (^)(NSError* _Nullable error))completion;

// Play logs
-(nullable AutomixSDKPlayLog*)insertNewPlayLog;
-(nonnull NSString*)playLogMDMCoreDataAdditionsEntityName;
-(void)deletePlayLog:(nonnull AutomixSDKPlayLog*)playlog;

// Transition logs
-(nullable AutomixSDKTransitionLog*)insertNewTransitionLog;
-(nonnull NSString*)transitionLogMDMCoreDataAdditionsEntityName;
-(void)deleteTransitionLog:(nonnull AutomixSDKTransitionLog*)transitionlog;

// Requests
-(nullable NSArray*)executeFetchRequest:(nonnull NSFetchRequest*)request error:(nullable void (^)(NSError* _Nullable error))errorBlock;


@property (nonatomic, strong, nullable) MDMPersistenceController* persistanceController;

@end


#endif
