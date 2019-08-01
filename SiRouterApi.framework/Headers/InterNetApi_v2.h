//
//  InterNetApi_v2.h
//  SiWiFiAPI
//
//  Created by qianbin on 15/8/24.
//  Copyright (c) 2015年 qianbin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalApi_v2.h"

#import "XCloudObject.h"
#import "XCloudEvent.h"

#define ApplicationID @"bffe04f2cb0f9155fb69acc6f37a0924"
#define MSG_TYPE_BIND 1
#define MSG_TYPE_MANAGE 2
#define MSG_TYPE_HEARTBEAT 3
#define MSG_TYPE_STATUS 4
#define MSG_TYPE_ONLINE 5
#define MSG_TYPE_USER_LOGIN 6
#define MSG_TYPE_USB_HOTPLUG 7
#define MSG_TYPE_WECHAT_SHARE 8
#define MSG_TYPE_USER_CHAT 9

#define API_HEART_BEAT @"heartbeat"
#define API_LISTEN_STATE @"listenstate"

//定义获取bmob数据方法类型
typedef NS_ENUM(NSInteger, BmobGetType)
{
    BMOB_GET_ROUTER_WIFI,
    BMOB_GET_ROUTER_DEVICE,
    BMOB_GET_ROUTERS,
    BMOB_GET_ROUTER_STATE,
    BMOB_BIND_ROUTER,
    BMOB_UNBIND_ROUTER,
    BMOB_CHECK_OTA,
    BMOB_SET_CURRENT_ROUTER,
    BMOB_SET_USER,
    BMOB_HEART_BEAT_MESSAGE,
    BMOB_LISTEN_ROUTER_STATE_MESSAGE,
    BMOB_LISTEN_DEVICE_STATE_MESSAGE,
    BMOB_GET_WIFI_FILTER,
    BMOB_GET_WAN_TYPE,
    BMOB_CHECK_INSTALLATION_ID,
    BMOB_GET_QOS,
    BMOB_GET_DEV_MANUFACTURER,
    BMOB_RESET_LISTENER,
    BMOB_CHECK_APP_VERSION,
    BMOB_UPDATE_WIFI_RENT_INFO,
    BMOB_GET_WIFI_RENT_INFO,
    BMOB_GET_GUEST_WIFI,
    BMOB_USER_FEEDBACK,
    BMOB_REMOTE_UNBIND_ROUTER,
    BMOB_QUERY_RENTAL_MODE,
    BMOB_SET_RENTAL_MODE
};


@interface CommonRouterMessage : Jastor
@property (copy, nonatomic) NSString *routerid;
@property (copy, nonatomic,readwrite) NSString *subid;
-(instancetype) initWithRouterid:(NSString*)rid andSubid:(NSString*)sid;
@end

@interface BindMessage : CommonRouterMessage
@end

@interface ManageMessage : CommonRouterMessage
/*0:邀请，1：移除完成，2：添加完成 3：拒绝 4：退出分享*/
@property (assign, nonatomic) int action;
@property (copy, nonatomic) NSString *userid;
@property (copy, nonatomic) NSString *phonenumber;
@property (copy, nonatomic) NSString *managername;
@property (copy, nonatomic) NSString *username;
@property (copy, nonatomic) NSString *tag;


@end

@interface HeartBeatMessage : CommonRouterMessage
/*0：发送心跳*/
@property (assign, nonatomic, readwrite) int action;
@end

@interface StatusMessage : CommonRouterMessage
@property (copy, nonatomic) NSString *time;
@property (copy, nonatomic) NSString *routername;
/*0:路由器在线 1：路由器升级中 2：路由器重启中 3：路由器重置中 4：路由器离线*/
@property (assign, nonatomic,readwrite) int action;
@end

@interface OnlineMessage : CommonRouterMessage
@property (copy, nonatomic) NSString *time;
@property (copy, nonatomic) NSString *routername;
@property (copy, nonatomic) NSString *mac;
@property (copy, nonatomic) NSString *name;
/*0:上线提醒 1：陌生设备上线提醒*/
@property (assign, nonatomic) int strange;
@property (copy, nonatomic) NSString *ssid5G;
@end

@interface UserLoginMessage : CommonRouterMessage
@property (copy, nonatomic) NSString *installationId;
@end

@interface USBHotPlugMessage : CommonRouterMessage
@property (assign, nonatomic) int action;
@end

@interface WXShareMessage : CommonRouterMessage
@property (assign, nonatomic) int action;
@property (copy, nonatomic) NSString *managerid;
@end

@interface UserChatMessage : Jastor
@property (copy, nonatomic) NSString *sourceid;
@property (copy, nonatomic) NSString *destid;
@property (copy, nonatomic) NSString *timeStamp;
@property (copy, nonatomic) NSString *text;
@property (assign, nonatomic) int messagetype;
@property (assign, nonatomic) int receiveBitMap;
@end

@class SFManageHeartBeatReply;
@class SFManagerListenDeviceState;
@class SFManagerListenRouterState;
@class SiWiFiFilter;
@class SiWanType;
@class SFManagerUploadLogParams;
@class SFUserFeedbackParams;


#pragma mark - operation

typedef void (^InterNetOnSuccess)(id ret);
typedef void (^InterNetOnError)(int code, NSString *msg);

@interface InterNetOperation1 : NSOperation
@property BmobGetType mType;
@property id mParam;
@property (strong, nonatomic) NSString *mUserid;
@property (strong, nonatomic) XCloudObject *mRouter;
@property (copy, nonatomic) InterNetOnSuccess mOnSuccess;
@property (copy, nonatomic) InterNetOnError mOnError;
- (instancetype)init:(NSString *)userid router:(XCloudObject *)router type:(BmobGetType)type param:(id)param success:(InterNetOnSuccess)success error:(InterNetOnError)error;
@end



typedef void (^InterNetOnResult)(id ret,int code,NSString *msg);
@interface InterNetOperation2 : NSOperation
@property int mMsgId;
@property (copy, nonatomic) NSString *mUserId;
@property (copy, nonatomic) NSString *mData;
@property int mType;
@property (copy ,nonatomic) NSString  *mRouterSub;
@property (copy ,nonatomic) NSString *mUserSub;
@property Class mRetClass;
@property (strong, nonatomic) InterNetOnResult mOnResult;

- (instancetype)init:(int)msgid userid:(NSString *)userid type:(int)type routersub:(NSString *)routersub usersub:(NSString *)usersub class:(Class)retclass data:(NSString *)data result:(InterNetOnResult)result;
@end

@interface InterNetMessage : NSObject
@property int msgId;
@property (copy, nonatomic) NSString *api;
@property (strong ,nonatomic) InterNetOnResult onResult;
@end

@interface InterNetOperation3 : NSOperation
@property (strong, nonatomic) XCloudObject *mUserSub;
@property (copy, nonatomic) InterNetOnResult mOnResult;

@end

/*
 *New websocket Oprate
 */
@interface InterNetOperation4 : NSOperation
@property int mMsgId;
@property (copy, nonatomic) NSString *mUserId;
@property (copy, nonatomic) NSString *mData;
@property int mType;
@property (copy ,nonatomic) NSString  *mRouterSub;
@property (copy ,nonatomic) NSString *mUserSub;
@property (copy ,nonatomic) NSString *mRouterId;
@property Class mRetClass;
@property (strong, nonatomic) InterNetOnResult mOnResult;
@property (copy ,nonatomic) SRWebSocket *mSocket;

- (instancetype)init:(int)msgid userid:(NSString *)userid type:(int)type routerid:(NSString *)routerid routersub:(NSString *)routersub usersub:(NSString *)usersub class:(Class)retclass data:(NSString *)data socket:(SRWebSocket *)socket result:(InterNetOnResult)result;
@end

/*
*New API body Oprate
*/
@interface InterNetOperation5 : NSOperation
@property int mMsgId;
@property (copy, nonatomic) NSString *mUserId;
@property (copy, nonatomic) NSDictionary *mData;
@property int mType;
@property (copy ,nonatomic) NSString  *mRouterSub;
@property (copy ,nonatomic) NSString *mUserSub;
@property (copy ,nonatomic) NSString *mRouterId;
@property Class mRetClass;
@property (strong, nonatomic) InterNetOnResult mOnResult;
@property (copy ,nonatomic) SRWebSocket *mSocket;

- (instancetype)init:(int)msgid userid:(NSString *)userid type:(int)type routerid:(NSString *)routerid routersub:(NSString *)routersub usersub:(NSString *)usersub class:(Class)retclass data:(NSDictionary *)data socket:(SRWebSocket *)socket result:(InterNetOnResult)result;
@end

/*
 *New socket send mesage Oprate
 */
@interface InterNetSocketOperation : NSOperation
@property int mMsgId;
@property (copy, nonatomic) NSString *mUserId;
@property (copy, nonatomic) NSString *mData;
@property int mType;
//@property (copy ,nonatomic) NSString  *mRouterSub;
@property (copy ,nonatomic) NSString *mUserSub;
@property (copy ,nonatomic) NSString *mDestId;
//@property Class mRetClass;
@property (strong, nonatomic) InterNetOnResult mOnResult;
@property (copy ,nonatomic) SRWebSocket *mSocket;

- (instancetype)init:(NSString *)msgid userid:(NSString *)userid type:(int)type usersub:(NSString *)usersub destid:(NSString *)destid data:(NSString *)data socket:(SRWebSocket *)socket result:(InterNetOnResult)result;
@end

/*
 id: CommonRouterMessage
 type：MSG_TYPE_XXX
 */
typedef void (^InternetMessageOnResult)(id ret,int type);


@class LocalApi_v2;
@class CommonParams;
@class GetWiFiRentInfoParams;
@class UpdateWiFiRentalWifiInfo;
@class UpdateWiFiRentInfoParams;
@class QueryWifiRentInfoParams;
@interface InterNetApi_v2 : NSObject<XCloudSocketDelegate>
{
    NSTimer *mNSTimer;
    BOOL mCheckMessageFlag;
    NSString *mInstallationId;
    BOOL mFirstCheck;
    NSOperationQueue *mInterNetqueue;
}
@property (strong ,nonatomic) NSMutableArray *messageArray;
@property (strong, nonatomic) LocalApi_v2 *mLocalApi;
@property (strong, nonatomic) NSString *mUserid;
@property (strong, nonatomic) XCloudObject *mCurrentRouter;
@property (strong, nonatomic) NSString *mUserSub;
@property (strong, nonatomic) XCloudObject *mRouterSub;
//@property (strong, nonatomic) BmobEvent *mEvent;
@property (strong, nonatomic) XCloudEvent *mEvent;
@property (copy, nonatomic) InternetMessageOnResult onmessageresult;
@property (nonatomic,weak)NSTimer *wbConnectTimer;
@property (strong, nonatomic) SRWebSocket *mSocket;

- (void)stopWebSocketListener;
//- (void)checkRouterMessageDelayed;
- (void)setRouter:(XCloudObject *)r success:(InterNetOnSuccess)success andreeor:(InterNetOnError)error;
- (void)setUser:(NSString *)userid subid:(NSString *)subid success:(InterNetOnSuccess)success andreeor:(InterNetOnError)error;
- (void)getBindRouters:(InterNetOnSuccess)success andreeor:(InterNetOnError)error;
- (void)getManageRouters:(InterNetOnSuccess)success andreeor:(InterNetOnError)error;

- (instancetype)init:(LocalApi_v2 *)localapi;
- (void)getRouterWifi:(InterNetOnSuccess)success andreeor:(InterNetOnError)error;
- (void)getRouterDevice:(int)param success:(InterNetOnSuccess)success andreeor:(InterNetOnError)error;
- (void)getRouterDeviceNumber:(InterNetOnSuccess)success andreeor:(InterNetOnError)error;
- (void)getSingleRouterDevice:(NSString *)mac success:(InterNetOnSuccess)success andreeor:(InterNetOnError)error;
- (void)getRouterState:(InterNetOnSuccess)success andreeor:(InterNetOnError)error;
- (void)bindRouter:(InterNetOnSuccess)success andreeor:(InterNetOnError)error;
- (void)unbindRouter:(InterNetOnSuccess)success andreeor:(InterNetOnError)error;
- (void)checkOta:(NSString *)otaVersion success:(InterNetOnSuccess)success andreeor:(InterNetOnError)error;
- (void)getWifiFilter:(InterNetOnSuccess)success anderror:(InterNetOnError)error;
- (void)getWanType:(InterNetOnSuccess)success anderror:(InterNetOnError)error;
- (void)getQos:(InterNetOnSuccess)success anderror:(InterNetOnError)error;
- (void)heartBeat:(SFManageHeartBeatReply*)param msgId:(NSNumber*)msgId result:(InterNetOnResult)result;
- (void)listenRouterState:(SFManagerListenRouterState*)param msgId:(NSNumber*)msgId result:(InterNetOnResult)result;
- (void)listenDeviceState:(SFManagerListenDeviceState*)param msgId:(NSNumber*)msgId result:(InterNetOnResult)result;
- (void)checkInstallationId:(NSString*)installationId result:(InterNetOnResult)result;
- (void)getManufacturerByMAC:(NSArray *)MacArray onresult:(InterNetOnResult)result;
- (void)checkAppVersion:(InterNetOnSuccess)success andreeor:(InterNetOnError)error;
- (void)sendUserChatMessage:(NSString *)chatUserId text:(NSString *)text messageId:(NSString *)messageId message:(InterNetMessage *)message;
- (void)sendmessage:(CommonParams *)param routersub:(XCloudObject *)routersub message:(InterNetMessage *)message;
- (void)updateWiFiRentInfo:(UpdateWiFiRentInfoParams*)param result:(InterNetOnResult)result;
- (void)getWiFiRentInfo:(GetWiFiRentInfoParams*)param result:(InterNetOnResult)result;
- (void)userFeedback:(SFUserFeedbackParams*)param onresult:(InterNetOnResult)result;
- (void)remoteUnbindRouter:(NSString *)routerid onresult:(InterNetOnResult)result;
-(void)queryRentalMode:(QueryWifiRentInfoParams *)routerid result:(InterNetOnResult)result;
-(void)setRentalWifiMode:(UpdateWiFiRentalWifiInfo *)param result:(InterNetOnResult)result;
@end
