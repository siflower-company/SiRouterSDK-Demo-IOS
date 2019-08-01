//
//  XCloudObject.h
//  SiWiFi
//
//  Created by Edward on 16/11/18.
//  Copyright © 2016年 Siflower. All rights reserved.
//

#import "XCloudConfig.h"

@interface XCloudObject : NSObject
{
    NSMutableDictionary *mDict;
    NSOperationQueue *mXCloudObjectOperation;
}

@property(nonatomic,copy)NSString *objectId;

@property(nonatomic,strong)NSDate *updatedAt;

@property(nonatomic,strong)NSDate *createdAt;

@property(nonatomic,copy)NSString * className;


/**
 *	创建一个带有className的XCloudObject对象
 *
 *	@param	className	表示对象名称(类似数据库表名)
 *
 *	@return	XCloudObject
 */
+(instancetype )objectWithClassName:(NSString*)className;


/**
 *	通过对象名称（类似数据库表名）初始化XCloudObject对象
 *
 *	@param	className	表示对象名称(类似数据库表名)
 *
 *	@return	XCloudObject
 */
-(id)initWithClassName:(NSString*)className;



/**
 *  从字典创建XCloudObject
 *
 *  @param dictionary 字典
 *
 *  @return XCloudObject 对象
 */
-(instancetype)initWithDictionary:(NSDictionary *)dictionary;

/**
 *	向XCloudObject对象添加数据
 *
 *	@param	obj	数据
 *	@param	aKey	键
 */
-(void)setObject:(id)obj forKey:(NSString*)aKey;

/**
 *	得到BombObject对象某个列的值
 *
 *	@param	aKey	列名
 *
 *	@return	该列的值
 */
-(id)objectForKey:(id)aKey;


#pragma mark  array add and remove
/**
 *  向给定的列添加数组
 *
 *  @param objects 想要添加的数组
 *  @param key     给定的列名
 */
-(void)addObjectsFromArray:(NSArray *)objects forKey:(NSString *)key;

/**
 *  向给定的列添加数组，只会在原本数组字段中没有这些对象的情形下才会添加入数组
 *
 *  @param objects 想要添加的数组
 *  @param key     给定的列名
 */
-(void)addUniqueObjectsFromArray:(NSArray *)objects forKey:(NSString *)key;

/**
 *  从一个数组字段的值内移除指定的数组中的所有对象
 *
 *  @param objects 想要移除的数组
 *  @param key     给定的列名
 */
-(void)removeObjectsInArray:(NSArray *)objects forKey:(NSString *)key;



#pragma mark networking

/**
 *	后台保存XCloudObject对象，没有返回结果
 */
-(void)saveInBackground;

/**
 *	后台保存XCloudObject对象，返回保存的结果
 *
 *	@param	block	返回保存的结果是成功还是失败
 */
-(void)saveInBackgroundWithResultBlock:(XCloudBooleanResultBlock)block;

/**
 *	后台更新XCloudObject对象，没有返回结果
 */
-(void)updateInBackground;

/**
 *	后台更新XCloudObject对象
 *
 *	@param	block	返回更新的结果是成功还是失败
 */
-(void)updateInBackgroundWithResultBlock:(NSString *)className param:(id)param onresult:(XCloudIdResultBlock)result;

/**
 *  删除某条数据，可多次调用
 *
 *  @param className 表名
 *  @param objectId  某条数据的objectId
 */
-(void)deleteXCloudObjectWithClassName:(NSString *)className objectId:(NSString*)objectId;

-(void)insertInBackgroundWithResultBlock:(NSString *)className param:(id)param onresult:(XCloudIdResultBlock)result;

/**
 *	后台删除XCloudObject对象，没有返回结果
 */
-(void)deleteInBackground;

- (BOOL)isEqual:(XCloudObject*)object;


@end

@interface XCloudObjectOperation : NSOperation
@property id mParam;
@property (strong, nonatomic) NSString *mTableName;
@property (copy, nonatomic) XCloudIdResultBlock mOnResult;
- (instancetype)init:(NSString *)table param:(id)param onresult:(XCloudIdResultBlock)onresult;
@end

