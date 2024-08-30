// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to AutomixSDKPlayLog.h instead.

#if __has_feature(modules)
    @import Foundation;
    @import CoreData;
#else
    #import <Foundation/Foundation.h>
    #import <CoreData/CoreData.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface AutomixSDKPlayLogID : NSManagedObjectID {}
@end

@interface _AutomixSDKPlayLog : NSManagedObject
+ (instancetype)insertInManagedObjectContext:(NSManagedObjectContext *)moc_;
+ (NSString*)entityName;
+ (nullable NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
@property (nonatomic, readonly, strong) AutomixSDKPlayLogID *objectID;

@property (nonatomic, strong) NSString* fileSource;

@property (nonatomic, strong, nullable) NSString* guid;

@property (nonatomic, strong) NSNumber* logPlayType;

@property (atomic) int16_t logPlayTypeValue;
- (int16_t)logPlayTypeValue;
- (void)setLogPlayTypeValue:(int16_t)value_;

@property (nonatomic, strong) NSNumber* seconds;

@property (atomic) int64_t secondsValue;
- (int64_t)secondsValue;
- (void)setSecondsValue:(int64_t)value_;

@property (nonatomic, strong) NSNumber* sourceId;

@property (atomic) int64_t sourceIdValue;
- (int64_t)sourceIdValue;
- (void)setSourceIdValue:(int64_t)value_;

@property (nonatomic, strong) NSString* sourceType;

@property (nonatomic, strong) NSNumber* trackId;

@property (atomic) int64_t trackIdValue;
- (int64_t)trackIdValue;
- (void)setTrackIdValue:(int64_t)value_;

@property (nonatomic, strong) NSNumber* userId;

@property (atomic) int64_t userIdValue;
- (int64_t)userIdValue;
- (void)setUserIdValue:(int64_t)value_;

@property (nonatomic, strong) NSDate* when;

@end

@interface _AutomixSDKPlayLog (CoreDataGeneratedPrimitiveAccessors)

- (NSString*)primitiveFileSource;
- (void)setPrimitiveFileSource:(NSString*)value;

- (nullable NSString*)primitiveGuid;
- (void)setPrimitiveGuid:(nullable NSString*)value;

- (NSNumber*)primitiveLogPlayType;
- (void)setPrimitiveLogPlayType:(NSNumber*)value;

- (int16_t)primitiveLogPlayTypeValue;
- (void)setPrimitiveLogPlayTypeValue:(int16_t)value_;

- (NSNumber*)primitiveSeconds;
- (void)setPrimitiveSeconds:(NSNumber*)value;

- (int64_t)primitiveSecondsValue;
- (void)setPrimitiveSecondsValue:(int64_t)value_;

- (NSNumber*)primitiveSourceId;
- (void)setPrimitiveSourceId:(NSNumber*)value;

- (int64_t)primitiveSourceIdValue;
- (void)setPrimitiveSourceIdValue:(int64_t)value_;

- (NSString*)primitiveSourceType;
- (void)setPrimitiveSourceType:(NSString*)value;

- (NSNumber*)primitiveTrackId;
- (void)setPrimitiveTrackId:(NSNumber*)value;

- (int64_t)primitiveTrackIdValue;
- (void)setPrimitiveTrackIdValue:(int64_t)value_;

- (NSNumber*)primitiveUserId;
- (void)setPrimitiveUserId:(NSNumber*)value;

- (int64_t)primitiveUserIdValue;
- (void)setPrimitiveUserIdValue:(int64_t)value_;

- (NSDate*)primitiveWhen;
- (void)setPrimitiveWhen:(NSDate*)value;

@end

@interface AutomixSDKPlayLogAttributes: NSObject
+ (NSString *)fileSource;
+ (NSString *)guid;
+ (NSString *)logPlayType;
+ (NSString *)seconds;
+ (NSString *)sourceId;
+ (NSString *)sourceType;
+ (NSString *)trackId;
+ (NSString *)userId;
+ (NSString *)when;
@end

NS_ASSUME_NONNULL_END
