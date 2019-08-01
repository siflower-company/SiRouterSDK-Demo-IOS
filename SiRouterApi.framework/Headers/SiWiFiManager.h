//
//  ErrorCode.h
//  SiWiFiAPI
//
//  Created by edward on 18/12/20.
//  Copyright © 2018年 Siflower. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InterNetApi_v2.h"

#define kAppleUrlTocheckWifi @"http://captive.apple.com"

//define router api version
#define DEFAULT_ROUTER_API_VERSION 17
#define ROUTER_API_VERSION_11 11
#define ROUTER_API_VERSION_12 12
#define ROUTER_API_VERSION_13 13
#define ROUTER_API_VERSION_14 14

typedef NS_ENUM(NSInteger, RouterType)
{
    BIND_ROUTER,
    MANAGER_ROUTER,
    ALL_ROUTER
};

typedef NS_ENUM(NSInteger, ManageAction)
{
    ACTION_INVITE,
    ACTION_DELETE,
    ACTION_ACCEPT,
    ACTION_REFUSE,
    ACTION_ABANDON,
    ACTION_CANCEL
};

typedef NS_ENUM(NSInteger, AlarmType)
{
    TYPE_ALARM,
    TYPE_REMIND
};

typedef NS_ENUM(NSInteger, MediaControlType)
{
    TYPE_MEDIA_STOP,
    TYPE_MEDIA_PAUSE,
    TYPE_MEDIA_CONTINUE,
    TYPE_MEDIA_REPLAY,
    TYPE_MEDIA_FORWARD,
    TYPE_MEDIA_BACK,
    TYPE_MEDIA_RANDOM,
    TYPE_MEDIA_PLAY_ONCE,
    TYPE_MEDIA_PLAY_SEQUENTIAL,
    TYPE_MEDIA_PLAY_LISTLOOP,
    TYPE_MEDIA_PLAY_SINGLE,
    TYPE_MEDIA_PLAY_RANDOM
};

typedef NS_ENUM(NSInteger, SFCloudEventType)
{
    EVENT_TYPE_ROUTER_DATA,
    EVENT_TYPE_ROUTER_UNBIND,
    EVENT_TYPE_ROUTER_MANAGER_OPERATE,
    EVENT_TYPE_HEART_BEAT,
    EVENT_TYPE_ROUTER_STATE,
    EVENT_TYPE_ROUTER_DEVICE_ONLINE,
    EVENT_TYPE_USER_ONLINE,
    EVENT_TYPE_ROUTER_USB_HOTPLUG,
    EVENT_TYPE_WECHAT_USER_STATE,
    EVENT_TYPE_USER_MESSAGE
};

@interface WiFiRent : Jastor
@property (assign, nonatomic)BOOL enable;
@property (assign, nonatomic) long downloadSpeed;
@property (assign, nonatomic) long uploadSpeed;
@property (assign, nonatomic) float unitPrice;
@end


/**
 * The router feature class.
 * show router support feature.
 **/
@interface RouterFeature : Jastor
/**
 * @brief Is AC controller.
 **/
@property (assign, nonatomic) int ac;
/**
 * @brief support ddns fuction.
 **/
@property (assign, nonatomic) int ddns;
/**
 * @brief support dhcp fuction.
 **/
@property (assign, nonatomic) int dhcp;
/**
 * @brief support dmz fuction.
 **/
@property (assign, nonatomic) int dmz;
/**
 * @brief support externalPA fuction.
 **/
@property (assign, nonatomic) int externalPA;
/**
 * @brief support guestWifi fuction.
 **/
@property (assign, nonatomic) int guestWifi;
/**
 * @brief support home control fuction.
 **/
@property (assign, nonatomic) int homeControl;
/**
 * @brief support led.
 **/
@property (assign, nonatomic) int led;
/**
 * @brief support online warn fuction.
 **/
@property (assign, nonatomic) int onlineWarn;
/**
 * @brief support staticRouter fuction.
 **/
@property (assign, nonatomic) int staticRouter;
/**
 * @brief support upnp fuction.
 **/
@property (assign, nonatomic) int upnp;
/**
 * @brief support usb fuction.
 **/
@property (assign, nonatomic) int usb;
/**
 * @brief support virtualServer fuction.
 **/
@property (assign, nonatomic) int virtualServer;
/**
 * @brief support wds fuction.
 **/
@property (assign, nonatomic) int wds;
/**
 * @brief support wifi fuction.
 **/
@property (assign, nonatomic) int wifi;
/**
 * @brief support wifi frequence intergration fuction.
 **/
@property (assign, nonatomic) int freqInter;
/**
 * @brief support lease net fuction.
 **/
@property (assign, nonatomic) int leaseWiFi;
/**
 * @brief support lease Web fuction.
 **/
@property (assign, nonatomic) int leaseWeb;
@end

@interface SiRouter : NSObject
@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *apiversion;
@property (copy, nonatomic) NSString *romversion;
@property (assign, nonatomic)int romversionnumber;
@property (copy, nonatomic) NSString *hardware;
@property (copy, nonatomic) NSString *sn;
@property (copy, nonatomic) NSString *mac;
@property (copy, nonatomic) NSString *account;
@property (assign, nonatomic)int disk;
@property (copy, nonatomic) NSString *routerid;
@property (assign, nonatomic) RouterType type;
@property (strong, nonatomic) WiFiRent *wifiRent;
@property (strong, nonatomic) RouterFeature *feature;
@property (assign, nonatomic)int romtype;
@property (assign, nonatomic)int online;
@property (assign, nonatomic)int storage;
@property (strong, nonatomic) XCloudObject *sub;
@property (assign, nonatomic)int rentalMode;
@property (copy, nonatomic) NSString *adminPassword;
+ (SiRouter*) getSiRouterFromBmobobject:(XCloudObject*)obj andType:(RouterType)type;
@end

@interface BindInfo : NSObject
@property (assign, nonatomic) int passwdset;
@property (assign, nonatomic) int bind;
@property (copy, nonatomic) NSString *binderid;
@property (copy, nonatomic) NSString *routerid;
@property (copy, nonatomic) NSString *mac;
@end

@interface SiRouterVersion : NSObject
@property (copy, nonatomic) NSString *version;
@end


@interface SiRouterDevice : Device
+ (SiRouterDevice*) getSiRouterDeviceFromBmobObject:(XCloudObject*)obj;
@end

@interface SiRouterDeviceSetParams : NSObject
@property (copy, nonatomic) NSString *mac;
@property (assign, nonatomic) int internet;
@property (assign, nonatomic) int wan;
@property (assign, nonatomic) int lan;
@property (assign, nonatomic) int notify;
@property (assign, nonatomic) int speedlvl;
@property (assign, nonatomic) int limitup;
@property (assign, nonatomic) int limitdown;
@property (assign, nonatomic) int disk;
@property (assign, nonatomic) int warn;
@property (copy, nonatomic) NSString *nickname;
@property (strong, nonatomic) NSMutableArray *timelist;
- (instancetype)init;
- (id)getSetDeviceParams;
@end

@interface SiRouterState : NSObject
@property (assign, nonatomic) Status status;
@property (assign, nonatomic) int upspeed;
@property (assign, nonatomic) int downspeed;
@property (assign, nonatomic) int devicecount;
@property (assign, nonatomic) int downloadingcount;
@property (assign, nonatomic) int cpuload;
@property (assign, nonatomic) int memoryload;
+(SiRouterState*) getSiRouterStateFromGetSiWiFiStatusRet:(GetSiWiFiStatusRet*)ret;
+(SiRouterState*) getSiRouterStateFromBmobObject:(XCloudObject*)obj;
@end

@interface SiWiFiFilter : Jastor
@property (assign,nonatomic) int enable;
@property (assign, nonatomic)int mode;
@end

@interface SiOrayInfo : Jastor
@property (copy, nonatomic) NSString *url;
@property (copy, nonatomic) NSString *session;
@end

@interface SiCheckNet : Jastor
@property (assign, nonatomic)int status;
@end

@interface SiDetectWanType : Jastor
@property (copy, nonatomic) NSString *wantype;
@end

@class WifiInfo;

@interface SiWiFiInfo : WiFiInfo
+ (SiWiFiInfo*) getSWiFiInfoFromBmobObject:(XCloudObject*)obj;
@end


@interface SiWiFiSetParams : NSObject
@property (assign, nonatomic)int enable;
@property (copy, nonatomic) NSString *ssidold;
@property (copy, nonatomic) NSString *ssidnew;
@property (copy, nonatomic) NSString *encryption;
@property (assign, nonatomic) int signalmode;
@property (copy, nonatomic) NSString *password;
@property (assign, nonatomic) int channel;
@property (assign,nonatomic) int flag;
- (id)getWiFiParams;
@end

@interface SiWanType : Jastor
@property (assign, nonatomic) int type;
@property (copy, nonatomic) NSString *pppname;
@property (copy, nonatomic) NSString *ppppwd;
@property (copy, nonatomic) NSString *gateway;
@property (copy, nonatomic) NSString *mask;
@property (assign, nonatomic) int autodns;
@property (copy, nonatomic) NSString *dns1;
@property (copy, nonatomic) NSString *ip;
@property (copy, nonatomic) NSString *dns2;
+(SiWanType*) getSiWanTypeFromGetWanTypeRet:(GetWanTypeRet*)ret;
@end

@interface SiSetWanType : NSObject
@property (assign, nonatomic) int type;
@property (copy, nonatomic) NSString *pppname;
@property (copy, nonatomic) NSString *ppppwd;

@property (copy, nonatomic) NSString *mask;
@property (assign, nonatomic) int autodns;
@property (copy, nonatomic) NSString *dns1;
@property (copy, nonatomic) NSString *dns2;
@property (copy, nonatomic) NSString *address;
@property (copy, nonatomic) NSString *gateway;
- (SetWanTypeParams*) getWanTypeParams;
@end


@interface SiQosInfo : Jastor
{
    int enable;
    int mode;
}
@property (assign, nonatomic) int enable;
@property (assign, nonatomic) int mode;
@end

@interface SiNetDetect : NSObject
@property (assign, nonatomic) int wanlink;
@property (strong, nonatomic) NSMutableArray *wifi;
@property (assign, nonatomic) int dns;
@property (assign, nonatomic) int memoryue;
@property (strong, nonatomic) WanSpeed *wanspeed;
@property (assign,nonatomic) int delay;
@property (assign, nonatomic) int cpuuse;
@property (strong, nonatomic) Ping *ping;
@property (strong, nonatomic) BandWidth *bandwidth;
+(SiNetDetect*) getSiNetDetectFromNetDetectRet:(NetDetectRet*)ret;
@end

@interface SiOtaCheck : NSObject
@property (copy, nonatomic) NSString *url;
@property (copy, nonatomic) NSString *checksum;
@property (copy, nonatomic) NSString *otaversion;
@property (copy, nonatomic) NSString *otatime;
@property (assign, nonatomic) int size;
@property (assign, nonatomic) int type;
@property (assign, nonatomic) int romtype;
@property (copy, nonatomic) NSString *log;
@property (copy, nonatomic) NSString *log_zw;
@property (copy, nonatomic) NSString *log_yw;
+(SiOtaCheck*) getSiOtaCheckFromBmobObject:(XCloudObject*)obj;
@end

@interface SiCheckAppVersion : NSObject
@property (copy, nonatomic) NSString *url;
@property (copy, nonatomic) NSString *platform;
@property (copy, nonatomic) NSString *updatelog;
@property (copy, nonatomic) NSString *version;
@property (assign, nonatomic) int versioni;
@property (assign, nonatomic) BOOL isforce;
+(SiCheckAppVersion*) getSiCheckAppVersionFromBmobObject:(XCloudObject*)obj;
@end

@interface SiGetDefault : Jastor
@property (assign, nonatomic) int internet;
@end

@interface SiGetOTACheck : Jastor
@property (copy, nonatomic) NSString *romversion;
@property (assign, nonatomic) int type;
@property (copy, nonatomic) NSString *romtime;
@property (copy, nonatomic) NSString *otatime;
@property (copy, nonatomic) NSString *log;
@property (copy, nonatomic) NSString *otaversion;
@property (assign, nonatomic) int size;
+(SiGetOTACheck*) getSiNetDetectFromOtaCheckRet:(OtaCheckRet*)ret;
@end

@interface SiUpgrade : NSObject
@property (assign, nonatomic) int status;
@property (assign, nonatomic) int downloaded;
+(SiUpgrade*) getSiUpGradeFromOtaUpgradeRet:(OtaUpgradeRet*)ret;
@end

@class SFLocalUploadLogParams;

@interface SFManagerUploadLogParams : NSObject
@property (copy, nonatomic, readwrite) NSString *feedback;
@property (copy, nonatomic, readwrite) NSString *phonenumber;
- (SFLocalUploadLogParams*) getSFLocalUploadParamsFromSFManagerUploadParams;
@end

@interface SFUserFeedbackParams : NSObject
@property (copy, nonatomic, readwrite) NSString *feedback;
@property (copy, nonatomic, readwrite) NSString *userid;
@property (copy, nonatomic, readwrite) NSString *routerid;
- (SFUserFeedbackParams*) getSFUserFeedbackParams;
- (NSMutableDictionary *)getDictionary;
@end

@class SFLocalUploadLogRet;

@interface SFManagerUploadLogResult : NSString
@property (copy, nonatomic, readwrite) NSString *objectid; //bmob obj of SiWiFi log
+(SFManagerUploadLogResult*) getSFManagerUploadLogResultFromSFLocalUploadLogRet:(SFLocalUploadLogRet*)ret;
@end


/*设置参数和坚挺的返回值公用的对象*/
@interface SFManageHeartBeatReply : CommonRet
/*O:send heart beat 1: replay heart beat Other: invalid;*/
@property (assign, nonatomic, readwrite) int action;
/* 如果是当前路由器不要设置该值*/
@property (copy, nonatomic, readwrite) NSString *subid;
@end

@interface SFManagerListenRouterState : NSObject
/*0: 开始监听 1：停止监听*/
@property (assign, nonatomic) int action;
@property (assign, nonatomic,) int interest;
-(NSMutableDictionary *)getDictionary;
@end

@interface SFManagerListenDeviceState : SFManagerListenRouterState
@property (copy, nonatomic) NSString *devicelist;
-(NSMutableDictionary *)getDictionary;
@end

@interface SFManagerSimpleMessage : NSObject

@property (copy, nonatomic) NSString *icon;
@property (copy, nonatomic) NSString *text;
@property (assign, nonatomic) long timeStamp;

@end

@interface SiSetDeviceSpped : NSObject
@property (copy, nonatomic) NSString *mac;
@property (assign, nonatomic) int enable;
@property (assign, nonatomic) int limitup;
@property (assign, nonatomic) int limitdown;
- (SetSpeedParams*) setDeviceSpeedParams;
@end

@interface SiUserTaskPictures : Jastor
@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *url;
@end

@interface SiUserTaskCommits : Jastor
@property (copy, nonatomic) NSString *comment;
@property (assign, nonatomic)int number;
@property (strong, nonatomic) NSMutableArray *pictures;
@end

@interface SiUserTask : Jastor
@property (copy, nonatomic) NSString *taskname;
@property (copy, nonatomic) NSString *description;
@property (copy, nonatomic) NSString *deadline;
@property (copy, nonatomic) NSString *executorMac;
@property (copy, nonatomic) NSString *publisherId;
@property (copy, nonatomic) NSString *executorId;
@property (assign, nonatomic)int bonus;
@property (assign, nonatomic)int status;
@property (strong, nonatomic) NSMutableArray *commits;
@end

@interface SiSetWiFiRentInfo : NSObject
@property (strong, nonatomic) NSString *routerid;
@property (assign, nonatomic) BOOL enable;
@property (assign, nonatomic) long uploadSpeed;
@property (assign, nonatomic) long downloadSpeed;
@property (assign, nonatomic) float unitPrice;
- (UpdateWiFiRentInfoParams*) getWiFiRentInfoParams;
@end

@interface SiWiFiRent : Jastor
@property (assign, nonatomic)BOOL enable;
@property (copy, nonatomic) NSString *mac;
@property (assign, nonatomic) long downloadSpeed;
@property (assign, nonatomic) long uploadSpeed;
@property (assign, nonatomic) float unitPrice;
@property (copy, nonatomic) NSString *ssid;
@end

@interface SiSetRentalWifiInfo : NSObject
@property (strong, nonatomic) NSString *routerid;
@property (assign, nonatomic) BOOL enable;
@property (assign, nonatomic) long uploadSpeed;
@property (assign, nonatomic) long downloadSpeed;
@property (assign, nonatomic) float unitPrice;
@property (assign, nonatomic) int mode;
- (UpdateWiFiRentalWifiInfo*) getWiFiRentalWifiInfo;
@end

@interface SiDeviceRestict : Jastor
@property (assign, nonatomic) int social;
@property (assign, nonatomic) int video;
@property (assign, nonatomic) int game;
@property (assign, nonatomic) int restrictenable;
+(SiDeviceRestict*) getSiDeviceRestictFromGetDeviceDataUsageRet:(GetDeviceRestictRet*)ret;
@end

/**
 * SiDataUsage
 **/
@interface SiDataUsage : Jastor
@property (strong, nonatomic) NSMutableArray *setlist;
@property (assign, nonatomic) int credit;
@property (assign, nonatomic) int usageenable;
+(SiDataUsage*) getSiDataUsageFromGetDeviceDataUsageRet:(GetDeviceDataUsageRet*)ret;
@end

@class WiFiGuestInfo;

@interface SiWiFiGuestInfo : WiFiGuestInfo
+ (SiWiFiGuestInfo*) getSiWiFiGuestInfoFromBmobObject:(XCloudObject*)obj;
@end

@class WiFiAdvancedInfo;

@interface SiWiFiAdvancedInfo : WiFiAdvancedInfo
+ (SiWiFiAdvancedInfo*) getSiSiWiFiAdvancedInfoFromBmobObject:(XCloudObject*)obj;
@end

@class WDSScanInfo;

@interface SiWDSScanInfo : WDSWiFiScanRet
+ (SiWDSScanInfo*) getSiWDSScanInfoFromBmobObject:(XCloudObject*)obj;
@end

/**
 * SiWDSConnectWiFi
 **/
@interface SiWDSConnectWiFi : NSObject
@property (copy ,nonatomic) NSString *encryption;
@property (copy ,nonatomic) NSString *key;
@property (copy ,nonatomic) NSString *ssid;
@property (assign ,nonatomic) int channel;
- (WDSConnectWiFiParams*) getWDSConnectWiFiParams;
@end

@interface SiFreqIntergration : GetFreqIntergrationRet
+ (SiFreqIntergration*) getSiFreqIntergrationFromBmobObject:(XCloudObject*)obj;
@end
@interface SiGetAPGroupsInfo : APGroupsList
+ (SiGetAPGroupsInfo*) getSiAPGroupsInfoFromBmobObject:(XCloudObject*)obj;
@end
@interface SiAPGroupParam : APGroupsInfo
+ (SiAPGroupParam*) getSiAPGroupParamFromBmobObject:(XCloudObject*)obj;
@end

@interface SiAPGroupIface : APGroupsIface
+ (SiAPGroupIface*) getSiAPGroupIfaceFromBmobObject:(XCloudObject*)obj;
@end
@interface SiAPGroupbandWithLimit : APGroupsIfaceBandLimit
+ (SiAPGroupbandWithLimit*) getSiAPGroupbandWithLimitFromBmobObject:(XCloudObject*)obj;
@end
@interface SiAPList: APList
+ (SiAPList*) getSiAPListFromBmobObject:(XCloudObject*)obj;
@end
@interface SiAPInfo : SetAPParams
+ (SiAPInfo*) getSiAPFromBmobObject:(XCloudObject*)obj;
@end
@interface removeAPGroup : CommonParams

@end
/*@interface SiACOTACheck : Jastor
@property (strong, nonatomic) NSMutableArray *ap;
@property (strong, nonatomic) OTACheckDetail *ac;
+(SiACOTACheck*) getSiACOTACheckFromACOtaCheckRet:(ACOtaCheckRet*)ret;
@end*/

/**
 * SiSpeakerAlarmInfo
 **/
@interface SiSpeakerAlarmInfo : AlarmInfo
+ (SiSpeakerAlarmInfo*) getSiSpeakerAlarmInfoFromCloud:(XCloudObject*)obj;
@end

/**
 * SiSpeakerMusicInfoExtra
 **/
@interface SiSpeakerMusicInfoExtra : MusicInfoExtra
@end

/**
 * SiSpeakerMusicInfo
 **/
@interface SiSpeakerMusicInfo : MusicInfo
+ (SiSpeakerMusicInfo*) getSiSpeakerMusicInfoFromCloud:(XCloudObject*)obj;
@end

@interface NSTimer (SFBlockSupport)
+ (NSTimer*) sf_scheduledTimerWithTimeInterval:(NSTimeInterval)interval block:(void(^)())block repeats:(BOOL) repeats;
@end

typedef void (^ManageOnResult)(id ret, int code, NSString *msg);

@interface ManageOperation : NSOperation

@property (assign, nonatomic) int mType;
@property (strong, nonatomic) id mParam1;
@property (strong, nonatomic) ManageOnResult mOnResult;
@property (strong, nonatomic) ManageOnResult mInterResult;
@property (strong, nonatomic) NSMutableArray *mTempArray;
@property (strong, nonatomic) NSMutableArray *mSiTempArray;
@property (assign, nonatomic) bool mInternetWorking;
@property (assign, nonatomic) bool mLocalnetWorking;
@property (assign, nonatomic) bool mAddRouterFlag;
@property (strong, nonatomic) LocalApi_v2* mlocalapi;
@property (assign, nonatomic) InterNetApi_v2 *minternetapi;
@property (assign, nonatomic) NSTimeInterval mTimeInterval;
- (instancetype)init:(int)type param1:(id)param1 result:(ManageOnResult)result interresult:(ManageOnResult)interresult interwork:(bool)interworking addrouterflag:(bool)addrouterflag localwork:(bool)localworking localapi:(LocalApi_v2 *)localapi interapi:(InterNetApi_v2 *)interapi timeInterval:(NSTimeInterval)timeInterval;
@end

//@class SFMCoreData;

@interface SiWiFiManager : NSObject
{
    int mMsgId;
    SiRouter *mCurrentRouter;
    NSTimer *timerForListenDeviceState;
    NSOperationQueue *queue;
    BOOL mResetBmobFlag;
    int mCurrentRouterAPI;
}
@property (strong, nonatomic) ManageOnResult mInitResult;
@property (assign, nonatomic) bool mAddRouterFlag;
@property (strong, nonatomic) NSNumber *status;
@property (copy, nonatomic) NSString *mCurrentWiFiName;
@property (assign, nonatomic) bool mInternetWorking;
@property (assign, nonatomic) bool mLocalnetWorking;
@property (strong, nonatomic) LocalApi_v2 *mLocalapi;
@property (strong, nonatomic) InterNetApi_v2 *mInternetapi;
@property (strong, nonatomic) NSString *mUserid;
@property (strong, nonatomic) NSMutableArray *mRoutersArray;
@property (strong, nonatomic) NSArray *mSiRoutersArray;
@property (strong, nonatomic) NSMutableArray *mRouterKeyArray;
@property (strong, nonatomic) NSString *mAppKey;
//@property (strong, nonatomic) ManageOperation *mOperation;
//@property (strong, nonatomic) SFMCoreData *coreData;

/**
 *func: initialize SiWiFiManager.
 *@param appKey: appkey.
 *@param routerKeys: router key array.
 **/
- (void)initializeManager:(NSString *)appKey andRouterKeys:(NSArray *)routerKeys;

/**
 *func: create new user.
 *@param appKey: app key.
 *@param secretKey: app secret key.
 *@param loginKeyExtra: static key for forget user password.
 **/
- (void)createUserKey:(NSString *)appKey andSecretKey:(NSString *)secretKey loginKeyExtra:(NSString *)loginKeyExtra onresult:(ManageOnResult)result;

/**
 *func: user login.
 *@param loginKey: user login key.
 *@param appKey: appkey.
 **/
- (void)userLogin:(NSString *)loginKey andAppKey:(NSString *)appKey onresult:(ManageOnResult)result;

/**
 *func: get app router keys.
 *@param appKey: appkey.
 **/
- (void)getRouterKeys:(NSString *)appKey onresult:(ManageOnResult)result;

/**
 *func: initialize SiWiFiManager InterNetApi for remote.
 *@param userid: use userid from user login.
 *@param subid: use user subid from user login.
 **/
- (void)initInterNetApi:(NSString *)userid subid:(NSString *)subid success:(InterNetOnSuccess)success error:(InterNetOnError)error;

/**
 *func: initialize SiWiFiManager LocalApi for local.
 **/
- (void)initLocalApi:(InterNetOnSuccess)success error:(InterNetOnError)error;

/**
 *func: use bind Router.
 **/
- (void)bindSiRouter:(ManageOnResult)result;

/**
 *func: use unbind Router.
 **/
- (void)unbindSiRouter:(ManageOnResult)result;


/**
 *func: get user bind router array.
 *@param type: RouterType, now support BIND_ROUTER and ALL_ROUTER.
 **/
- (void)getSiRouters:(RouterType)type onresult:(ManageOnResult)result;

/**
 *func: get user bind router array, this func can get routers from internet.
 *@param type: RouterType, now support BIND_ROUTER and ALL_ROUTER.
 **/
- (void)getRealSiRouters:(RouterType)type onresult:(ManageOnResult)result;

/**
 *func: set user current operate router.
 *@param router: the router for current operate.
 **/
- (void)setCurrentRouter:(SiRouter *)router onresult:(ManageOnResult)result;

/**
 *func: set router admin password.
 *@param passwordold: old password.
 *@param passwordnew: new password.
 *@param flag: false: for set password before bind.
 **/
- (void)setAdminPassword:(NSString *)passwordold passwordnew:(NSString *)passwordnew flag:(bool)flag onresult:(ManageOnResult)result;

/**
 *func: check router admin password.
 *@param password: admin password.
 *@param flag: false: for set password before bind.
 **/
- (void)checkAdminPassword:(NSString *)password flag:(bool)flag onresult:(ManageOnResult)result;

/**
 *func: get router bind info.
 **/
- (void)getBindInfo:(ManageOnResult)result;

/**
 *func: get router api version.
 **/
- (void)getVersion:(ManageOnResult)result;

/**
 *func: set used api version
 *@param version: router api version.
 **/
- (void)setVersion:(NSString *)version;

/**
 *func: get router wifi info.
 **/
- (void)getRouterWifi:(ManageOnResult)result;

/**
 *func: set router wifi info.
 *@param array: array of 2.4G & 5G SiWiFiSetParams.
 **/
- (void)setRouterWifi:(NSArray *)array onresult:(ManageOnResult)result;

- (void)getRouterState:(int)cpu memory:(int)mem onresult:(ManageOnResult)result;

/**
 *func: reboot router.
 **/
- (void)reboot:(ManageOnResult)result;

/**
 *func: reset router.
 **/
- (void)reset:(ManageOnResult)result;

/**
 *func: get router connected device list.
 *@param type description:
 * 0: all device list.
 * 1: all online device list.
 * 2: all offline device list.
 **/
- (void)getdevicelist:(int)type onresult:(ManageOnResult)result;

/**
 *func: get router connected device number.
 **/
- (void)getdeviceNumber:(ManageOnResult)result;

/**
 *func: get router device detail.
 *@param macAdress: the mac address of device.
 **/
- (void)getsingleDevice:(NSString *)macAdress onresult:(ManageOnResult)result;

/**
 *func: set router device detail.
 *@param device: SiRouterDeviceSetParams.
 **/
- (void)setDevice:(SiRouterDeviceSetParams *)device onresult:(ManageOnResult)result;

/*abandoned method 废弃*/
- (void)manageSiRouter:(ManageAction)action routerid:(NSString *)routerid userid:(NSString *)userid phonenumber:(NSString *)phonenumber username:(NSString *)name tag:(NSString *)tag onresult:(ManageOnResult)result;
/*abandoned method 废弃*/
- (void)addManager:(NSString *)routerobjectid onresult:(ManageOnResult)result;
/*abandoned method 废弃*/
- (void)removeManager:(NSString *)routerobjectid onresult:(ManageOnResult)result;

/*onresult: 该回调方法的第一个参数赋值为CommonRouterMessage的继承对象*/
/**
 *func: listen message from internet, all remote message is in callback.
 * messge type is SFCloudEventType.
 **/
- (void)listenMessageResult:(InternetMessageOnResult)onresult;


- (void)checkWanType:(ManageOnResult)result;

/**
 *func: get router wan type, dhcp static ip or pppoe.
 *@param flag: false: for get wan type before bind.
 **/
- (void)getWanType:(bool)flag onresult:(ManageOnResult)result;

/**
 *func: set router wan type, dhcp static ip or pppoe.
 *@param wantype: SiSetWanType
 *@param flag: false: for set wan type before bind.
 **/
- (void)setWanType:(SiSetWanType *)wantype flag:(bool)flag onresult:(ManageOnResult)result;

/*func：获取路由器的Manager列表
 params：result: ManageOnResult中返回BmobUser数组; routerId:如果是当前路由器可赋值为nil*/
- (void)getRouterManagers:(ManageOnResult)result andRouterId:(NSString*)routerId;

//设置Qos，enable代表当前qos功能是否开启，1表示开启，0表示关闭，mode代表当前qos模式，0是自动，1是优先级，2是手动限速
//如获取成功，则使用SiQosInfo取值
/**
 *func: get router qos info.
 **/
- (void)getQosInfo:(ManageOnResult)result;

/**
 *func: set router qos info.
 *@param enable: 1,enable; 0,disable.
 *@param mode: 0,auto; 1,priority; 2,speed limit.
 **/
- (void)setQos:(int)enable mode:(int)mode onresult:(ManageOnResult)result;

//如获取成功，则使用SiNetDetect取值
/**
 *func: detect router internet.
 **/
- (void)netDetect:(ManageOnResult)result;

//如获取成功，则使用SiOtaCheck取值
- (void)otaCheck:(NSString *)otaVersion onresult:(ManageOnResult)result;

/**
 *func: check router ota infomation.
 **/
- (void)getOTACheck:(ManageOnResult)result;

//如果设置check为1，可以获得升级的进度SiUpGrade
/**
 *func: start router ota upgrade.
 *@param routerid: routerid for ota router.
 **/
- (void)otaUpgrade:(NSString *)routerid onresult:(ManageOnResult)result;

//如获取成功，则使用SiWiFiFilter取值
- (void)getWifiFilter:(ManageOnResult)result;

//enable表示wifi陌生设备的连接提醒开关，1开启，0关闭，mode表示当前推送模式，0是自动，1是晚间不会推送
- (void)setWifiFilter:(int)enable mode:(int)mode onresult:(ManageOnResult)result;

- (void)removeBinder:(NSString *)routerid onresult:(ManageOnResult)result;

- (void)uploadLog:(SFManagerUploadLogParams*)param onresult:(ManageOnResult)result;

/**
 *func: user feedback.
 *@param param: SFUserFeedbackParams.
 **/
- (void)userFeedback:(SFUserFeedbackParams*)param onresult:(ManageOnResult)result;

- (void)setUserInfo:(NSString *)ip port:(NSString *)port onresult:(ManageOnResult)result;

- (void)createOraySession:(ManageOnResult)result;

- (void)destroyOraySession:(NSString *)session onresult:(ManageOnResult)result;

/**
 *func: get device Manufacturer by device mac.
 *@param MacArray: device mac array.
 **/
- (void)getManufacturerByMAC:(NSArray *)MacArray onresult:(ManageOnResult)result;

- (void)checkAPPVersion:(int)local onresult:(ManageOnResult)result;

//检测router wan 状态
/**
 *func: check router internet infomation.
 **/
- (void)checkNet:(ManageOnResult)result;

//侦测wan type
- (void)detectWanType:(ManageOnResult)result;

- (void)getDefault:(ManageOnResult)result;

- (void)setDefault:(int)internet onresult:(ManageOnResult)result;

/**
 *func: set device speed limit.
 *@param speed: SiSetDeviceSpped.
 **/
- (void)setSpeed:(SiSetDeviceSpped *)speed onresult:(ManageOnResult)result;

/**
 *param listtype description:
 * 0: not use
 * 1: enable write list
 * 2: enable black list
 **/
- (void)getUrlList:(int)listtype mac:(NSString *)mac onresult:(ManageOnResult)result;

/**
 * param add description:
 * YES: add url list
 * NO: remove url list
 *
 * param blackList description:
 * YES: oprate black url list
 * NO: oprate write url list
 *
 * param blackList description:
 * NSArray of write/black url List
 **/
//- (void)setUrlList:(bool)add isBlackList:(bool)blackList urlList:(NSArray *)listArray onresult:(ManageOnResult)result;
- (void)setUrlList:(int)listtype mac:(NSString *)mac urlList:(NSArray *)listArray onresult:(ManageOnResult)result;

/**
 * param action description:
 * 0: not use
 * 1: enable write list
 * 2: enable black list
 **/
- (void)enableUrlList:(int)action deviceMAC:(NSString *)mac urlList:(NSArray *)listArray onresult:(ManageOnResult)result;

/**
 *func: get device restrict.
 *@param mac: device mac.
 **/
- (void)getDeviceRestrict:(NSString *)mac onresult:(ManageOnResult)result;

/**
 *func: set device restrict.
 *@param mac: device mac.
 *@param social: 0,disable forbid social; 1,enable forbid social.
 *@param video: 0,disable forbid video; 1,enable forbid video.
 *@param game: 0,disable forbid game; 1,enable forbid game.
 **/
- (void)setDeviceRestrict:(NSString *)mac social:(int)social video:(int)video game:(int)game enable:(int)enable onresult:(ManageOnResult)result;

/**
 *func: get device data usage.
 *@param mac: device mac.
 **/
- (void)getDeviceDataUsage:(NSString *)mac onresult:(ManageOnResult)result;

/**
 *func: set device restrict.
 *@param mac: device mac.
 *@param list: DataUsage array.
 *@param change: data usage count change value.
 *@param enable: 0,disable; 1,enable.
 **/
- (void)setDeviceDataUsage:(NSString *)mac setList:(NSArray *)list change:(int)change enable:(int)enable onresult:(ManageOnResult)result;

- (void)sendUserChatMessage:(NSString *)chatUserId text:(NSString *)text onresult:(ManageOnResult)result;

/*  发送/回复一个心跳给路由器
 */
- (void)heartBeat:(SFManageHeartBeatReply*)param onresult:(ManageOnResult)result;

//listenRouterState listenDeviceState 废弃作为内部接口
/*监听路由器表，通过[SFManagerListenRouterState action]的值是否为O判断开始/停止监听。
 如果需要持续的监听，需要每间隔120秒内（60秒一次）发送一次请求，否则路由器会在120内停止更新， 如果发送停止监听的请求，则立即停止更新*/
//- (void)listenRouterState:(SFManagerListenRouterState*)param onResult:(ManageOnResult)result;

/*监听设备状态，原理类似listenRouterState*/
//- (void)listenDeviceState:(SFManagerListenDeviceState*)param onResult:(ManageOnResult)result;

/*func: 登陆检测，如果已经有用户登陆则通知其下线。即同一个账户只有一个设备登陆。
  params:
    installationId: 当前设备的installationId
    result: code为0则操作成功
 */
- (void) checkInstallationId:(NSString *)installationId onResult:(ManageOnResult)result;

/**
 *func: update WiFi Rental Infomation.
 *@param rentInfo: SiSetWiFiRentInfo.
 **/
- (void) updateWiFiRentInfo:(SiSetWiFiRentInfo *)rentInfo onResult:(ManageOnResult)result;

/**
 *func: get WiFi Rental Infomation.
 *@param wifiMac: router wifi mac address.
 **/
- (void) getWiFiRentInfo:(NSString *)wifiMac onResult:(ManageOnResult)result;

/**
 *func: query WiFi Rental mode.
 *@param routerid: router objectid.
 **/
- (void)queryRentalMode:(NSString *)routerid onResult:(ManageOnResult)result;

/**
 *func: set WiFi Rental mode.
 *@param rentInfo: SiSetRentalWifiInfo
 **/
- (void)setRentalMode:(SiSetRentalWifiInfo *)rentInfo onResult:(ManageOnResult)result;

/**
 *func: get router guest WiFi infomation.
 **/
- (void)getGuestWifi:(ManageOnResult)result;

/**
 *func: set router guest WiFi infomation.
 *@param array: array of WifiGuestParams.
 **/
- (void)setGuestWifi:(NSArray *)array onresult:(ManageOnResult)result;

/**
 *func: get router WiFi advance infomation.
 **/
- (void)getAdvancedWifi:(ManageOnResult)result;

/**
 *func: set router WiFi advance infomation.
 *@param array: array of WiFiAdvancedPramas.
 **/
- (void)setAdvancedWifi:(NSArray *)array onresult:(ManageOnResult)result;

/**
 *func: get router WDS infomation.
 **/
- (void)getWDSInfo:(ManageOnResult)result;

/**
 *func: get router WDS wifi scan infomation.
 *@param band: the router wifi scan band, 2.4G or 5G.
 **/
- (void)getWDSWiFiScan:(NSString *)band onresult:(ManageOnResult)result;

/**
 *func: set router WDS connect wifi.
 *@param wifi: WDSConnectWiFiParams.
 **/
- (void)setWDSConnectWiFi:(WDSConnectWiFiParams *)wifi onresult:(ManageOnResult)result;

- (void)getWDSWanIP:(NSString *)band onresult:(ManageOnResult)result;

/**
 *func: set router wan ip after enable WDS.
 *@param band:  the router wifi connect band, 2.4G or 5G.
 **/
- (void)getWDSRelIP:(NSString *)band onresult:(ManageOnResult)result;

- (void)enableRouterWDS:(NSString *)ip ifaces:(NSArray *)ifaces onresult:(ManageOnResult)result;

/**
 *func: enable router WDS fuction.
 *@param band: the router wifi connect band, 2.4G or 5G.
 *@param ifaces: WDSWiFiIface array.
 **/
- (void)enableRouterWDSNew:(NSString *)band ifaces:(NSArray *)ifaces onresult:(ManageOnResult)result;

/**
 *func: disable router WDS fuction.
 *@param redirect: 0, not redirect; 1, redirect.
 **/
- (void)disableRouterWDS:(int)redirect onresult:(ManageOnResult)result;

- (void)getWDSWiFiIfaces:(ManageOnResult)result;

//WiFi Warn api
- (void)getWiFiWarn:(ManageOnResult)result;

- (void)setWiFiWarn:(int)enable onresult:(ManageOnResult)result;

- (void)disableDeviceWarn:(NSString *)mac onresult:(ManageOnResult)result;

//AC Controller api
/**
 *func: get AC Controller AP Groups.
 **/
- (void)getAPGroups:(ManageOnResult)result;

/**
 *func: set AC Controller AP Group.
 *@param group: SetAPGroupParams.
 *@param total: array of APGroupsList index value.
 **/
- (void)setAPGroup:(SetAPGroupParams *)group andTotal:(NSMutableArray *)total onresult:(ManageOnResult)result;

/**
 *func: get AC Controller AP list.
 *@param index: APGroupsList index value.
 **/
- (void)getAPList:(int)index onresult:(ManageOnResult)result;

/**
 *func: set AC Controller AP infomation.
 *@param ap: SetAPParams.
 *@param index: APGroupsList index value.
 **/
- (void)setAP:(SetAPParams *)ap index:(int)index onresult:(ManageOnResult)result;

/**
 *func: remove AC Controller AP Group.
 *@param index: APGroupsList index value.
 *@param total: array of APGroupsList index value.
 **/
- (void)removeAPGroup:(int)index andTotal:(NSMutableArray *)total  onresult:(ManageOnResult)result;

/**
 *func: delete AC Controller AP.
 *@param macs: array of ap mac address.
 *@param index: APGroupsList index value.
 **/
- (void)deleteAP:(NSArray *)macs index:(int)index onresult:(ManageOnResult)result;

/**
 *func: check AC Controller ota infomation.
 **/
- (void)getACOtaCheck:(ManageOnResult)result;

/**
 *func: AC Controller ota upgrade.
 *@param routerid: ota upgrade router objectid.
 **/
- (void)acAPUpgrade:(NSString *)routerid onresult:(ManageOnResult)result;

//Get iPhone MAC api
/**
 *func: get current iPhone mac address.
 *only use in local internet.
 **/
- (void)getClientMac:(ManageOnResult)result;

//WiFi Rent api
/**
 *func: get router lease net infomation.
 **/
- (void)getLeaseNet:(ManageOnResult)result;

/**
 *func: set router lease net infomation.
 *@param ssid: lease net wifi ssid.
 *@param enable: 0, disable; 1, enable.
 *@param limitdownload: lease net speed limit value.
 **/
- (void)setLeaseNet:(NSString *)ssid enable:(BOOL)enable limitSpeed:(long)limitdownload onresult:(ManageOnResult)result;

/**
 *func: set router lease net device access.
 *@param mac: device mac address.
 *@param duration: device internet access duration.
 **/
- (void)setLeaseDevice:(NSString *)mac timeCount:(int)duration onresult:(ManageOnResult)result;

/**
 *func: set router lease net device access.
 *@param mac: device mac address.
 *@param duration: device internet access duration.
 **/
- (void)setClientAccessNet:(NSString *)mac timeCount:(int)duration onresult:(ManageOnResult)result;

- (void)remoteUnbindSiRouter:(ManageOnResult)result;

/**
 *func: get router wifi frequence intergration.
 **/
- (void)getFreqIntergration:(ManageOnResult)result;

/**
 *func: set router wifi frequence intergration.
 *@param enable: 0, disable; 1, enable.
 **/
- (void)setFreqIntergration:(int)enable onresult:(ManageOnResult)result;

/**
 *func: get router WDS status.
 **/
- (void)getWDSStatus:(ManageOnResult)result;

//Speaker APIs
/**
 *func: get speaker alarm infomation.
 *@param type: AlarmType.
 **/
- (void)getSpeakerAlarm:(AlarmType)type onresult:(ManageOnResult)result;

/**
 *func: delete speaker alarm.
 *@param type: AlarmType.
 *@param alarm: delete alarm array.
 **/
- (void)deleteSpeakerAlarm:(AlarmType)type alarm:(NSMutableArray *)alarm onresult:(ManageOnResult)result;

/**
 *func: get speaker volume infomation.
 **/
- (void)getSpeakerVolume:(ManageOnResult)result;

/**
 *func: set speaker volume infomation.
 *@param volume: volume value(0~100).
 **/
- (void)setSpeakerVolume:(int)volume onresult:(ManageOnResult)result;

/**
 *func: get speaker sleep infomation.
 **/
- (void)getSpeakerSleep:(ManageOnResult)result;

/**
 *func: set speaker sleep infomation.
 *@param enable: 0, disable; 1, enable.
 **/
- (void)setSpeakerSleep:(int)enable onresult:(ManageOnResult)result;

/**
 *func: get speaker music infomation.
 **/
- (void)getSpeakerMusicInfo:(ManageOnResult)result;

/**
 *func: set speaker sleep infomation.
 *@param command: MediaControlType.
 **/
- (void)setSpeakerMediaControl:(MediaControlType)command onresult:(ManageOnResult)result;

/**
 *func: get speaker media status.
 **/
- (void)getSpeakerMediaStatus:(ManageOnResult)result;

/**
 *func: set speaker media status.
 *@param music: SiSpeakerMusicInfo.
 **/
- (void)setSpeakerPlayMusic:(SiSpeakerMusicInfo *)music onresult:(ManageOnResult)result;

/**
 *func: get speaker music collection infomation.
 **/
- (void)getSpeakerMusicCollection:(ManageOnResult)result;

/**
 *func: add speaker music collection.
 *@param music: SiSpeakerMusicInfo
 **/
- (void)addSpeakerMusicCollection:(SiSpeakerMusicInfo *)music onresult:(ManageOnResult)result;

/**
 *func: cancel speaker music collection.
 *@param musicUrl: SiSpeakerMusicInfo url value.
 **/
- (void)cancelSpeakerMusicCollection:(NSString *)musicUrl onresult:(ManageOnResult)result;

/**
 *func: get speaker security mode.
 **/
- (void)getSpeakerSecurityMode:(ManageOnResult)result;

/**
 *func: set speaker security mode.
 *@param enable: 0, disable; 1, enable.
 **/
- (void)setSpeakerSecurityMode:(int)enable onresult:(ManageOnResult)result;

/**
 *func: get speaker green access infomation.
 **/
- (void)getSpeakerGreen:(ManageOnResult)result;

/**
 *func: get speaker green access infomation.
 *@param start: green mode start time.
 *@param end: green mode end time.
 *@param limit: green mode speed limit value.
 **/
- (void)setSpeakerGreen:(NSString *)start endTime:(NSString *)end limit:(int)limit onresult:(ManageOnResult)result;

/*监听重连*/
/**
 *func: restart remote Event listener.
 **/
- (void) restartRemoteEvent;

+ (NSString *)getCurrentConnectWifiName;
+ (NSString *)getConnectWifiName;
+ (NSString *)getConnectRouterIp;

/**
 *func: check current connect router is SiRouter or not.
 **/
+ (BOOL)isSiWiFi;
+ (BOOL)connectedToNetwork;//判断是否联网
- (BOOL)isSiWiFiLocal;

/**
 *func: check current net can get internet access or not.
 **/
+(BOOL)checkNetworkCanUse:(NSString*)urlstring;
- (int)getCurrentRouterAPI;
@end
