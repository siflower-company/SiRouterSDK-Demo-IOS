//
//  XCloudConfig.h
//  SiWiFi
//
//  Created by Edward on 16/11/16.
//  Copyright © 2016年 Siflower. All rights reserved.
//


#import "Jastor.h"

#define XCLOUD_CMD_VERSION @"/v1"
//#define XCLOUD_CMD_BASE_URL @"https://cloud.siflower.cn/v4"
//#define XCLOUD_CMD_BASE_URL @"https://k8s.siflower.cn/v3"
#define XCLOUD_CMD_BASE_URL @"https://cloud.siflower.cn/v3"
//#define XCLOUD_CMD_BASE_URL @"https://139.196.176.186:8090"
//#define XCLOUD_CMD_BASE_URL @"https://120.76.161.56:8090"
//#define XCLOUD_CMD_BASE_URL @"https://192.168.1.12:8090"

#define XCLOUD_CMD_URL @"https://cloud.siflower.cn"

#define WXPatient_App_ID @"wxceaa828d0820bbe5"
#define WXPatient_App_Secret @"4d628300fe9ec68699366a609c132bb8"

#define XCLOUD_USE_COREDATA true

@interface XCloudResponse : Jastor
@property (assign, nonatomic,readwrite)NSInteger code;
@property (copy, nonatomic,readwrite) NSString *msg;
@end

@class XCloudObject;
@class XCloudUser;

typedef void (^XCloudObjectResultBlock)(XCloudObject *object, XCloudResponse *error);
typedef void (^XCloudObjectArrayResultBlock)(NSArray *array, XCloudResponse *error);
typedef void (^XCloudBooleanResultBlock) (BOOL isSuccessful, XCloudResponse *error);
typedef void (^XCloudIntegerResultBlock)(int number, NSError *error) ;
typedef void (^XCloudUserResultBlock)(XCloudUser *user, XCloudResponse *error);
typedef void (^XCloudIdResultBlock)(id object, XCloudResponse *error);
typedef void (^XCloudMessageResultBlock)(NSString *requestStatus,NSError *error);
typedef void (^XCloudQuerySMSCodeStateResultBlock)(NSDictionary *dic,NSError *error);

@interface XCloudConfig : NSObject
+(NSString*)DataToJasonString:(id)obj;
+(NSString*)stringToJsonString:(NSString*)string;
+(NSDictionary*)dictWithJsonString:(NSString *)jsonString;
+ (int)getStringLength:(NSString*)strtemp;
@end


