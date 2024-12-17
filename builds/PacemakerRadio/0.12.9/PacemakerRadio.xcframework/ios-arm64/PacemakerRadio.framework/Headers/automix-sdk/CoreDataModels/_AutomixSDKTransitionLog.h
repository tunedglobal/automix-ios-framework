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

@interface AutomixSDKTransitionLogID : NSManagedObjectID {}
@end

@interface _AutomixSDKTransitionLog : NSManagedObject
+ (instancetype)insertInManagedObjectContext:(NSManagedObjectContext *)moc_;
+ (NSString*)entityName;
+ (nullable NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
@property (nonatomic, readonly, strong) AutomixSDKTransitionLogID *objectID;

@property (nonatomic, strong, nullable) NSString* guid;

@property (nonatomic, strong) NSString* transitionType;

@property (nonatomic, strong) NSNumber* duration;

@property (atomic) int64_t durationValue;
- (int64_t)durationValue;
- (void)setDurationValue:(int64_t)value_;

@property (nonatomic, strong) NSNumber* trackIdOut;

@property (atomic) int64_t trackIdOutValue;
- (int64_t)trackIdOutValue;
- (void)setTrackIdOutValue:(int64_t)value_;

@property (nonatomic, strong) NSNumber* trackIdIn;

@property (atomic) int64_t trackIdInValue;
- (int64_t)trackIdInValue;
- (void)setTrackIdInValue:(int64_t)value_;

@property (nonatomic, strong) NSNumber* userId;

@property (atomic) int64_t userIdValue;
- (int64_t)userIdValue;
- (void)setUserIdValue:(int64_t)value_;

@property (nonatomic, strong) NSDate* when;

@end

@interface _AutomixSDKTransitionLog (CoreDataGeneratedPrimitiveAccessors)

- (nullable NSString*)primitiveGuid;
- (void)setPrimitiveGuid:(nullable NSString*)value;

- (NSString*)primitiveTransitionType;
- (void)setPrimitiveTransitionType:(NSString*)value;

- (NSNumber*)primitiveDuration;
- (void)setPrimitiveDuration:(NSNumber*)value;

- (int64_t)primitiveDurationValue;
- (void)setPrimitiveDurationValue:(int64_t)value_;

- (NSNumber*)primitiveTrackIdOut;
- (void)setPrimitiveTrackIdOut:(NSNumber*)value;

- (int64_t)primitiveTrackIdOutValue;
- (void)setPrimitiveTrackIdOutValue:(int64_t)value_;

- (NSNumber*)primitiveTrackIdIn;
- (void)setPrimitiveTrackIdIn:(NSNumber*)value;

- (int64_t)primitiveTrackIdInValue;
- (void)setPrimitiveTrackIdInValue:(int64_t)value_;

- (NSNumber*)primitiveUserId;
- (void)setPrimitiveUserId:(NSNumber*)value;

- (int64_t)primitiveUserIdValue;
- (void)setPrimitiveUserIdValue:(int64_t)value_;

- (NSDate*)primitiveWhen;
- (void)setPrimitiveWhen:(NSDate*)value;

@end

@interface AutomixSDKTransitionLogAttributes: NSObject
+ (NSString *)guid;
+ (NSString *)transitionType;
+ (NSString *)duration;
+ (NSString *)trackIdOut;
+ (NSString *)trackIdIn;
+ (NSString *)userId;
+ (NSString *)when;
@end

NS_ASSUME_NONNULL_END
