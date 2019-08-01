//
//  ErrorCode.h
//  SiWiFiAPI
//
//  Created by edward on 18/12/20.
//  Copyright © 2018年 Siflower. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Jastor.h"

#ifdef DEBUG
# define DebugLog(fmt, ...) NSLog((@"\n[文件名:%s]\n""[函数名:%s]\n""[行号:%d] \n" fmt), __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
# define DebugLog(...);
#endif

extern NSString *API_VERSION;
#define ROUTER_API_VERSION @"V17"
#define MAC_PREV @"0:16:88"
#define MAC_PREV_NEW @"A8:5A:F3"
#define WIFI_PARAMETER_ENABLE 1
#define WIFI_PARAMETER_SSID 2
#define WIFI_PARAMETER_ENCRYPTION 4
#define WIFI_PARAMETER_SIGNAL_MODE 8
#define WIFI_PARAMETER_PASSWORD 16
#define WIFI_PARAMETER_CHANNEL 32
#define WIFI_PARAMETER_DISABLEALL 64


#define CMD_GET_BIND_INFO @"/api/visitor/get_bindinfo"
#define CMD_GET_VERSION @"/api/visitor/get_version"
#define CMD_GET_DEVICE_LIST @"/api/sfsystem/device_list"
#define CMD_SET_DEVICE @"/api/sfsystem/setdevice"
#define CMD_GET_STOK_LOCAL @"/api/sfsystem/get_stok_local"
#define CMD_GET_STOK_REMOTE @"/api/sfsystem/get_stok_remote"
#define CMD_GET_SIWIFI_INFO @"/api/sfsystem/init_info"
#define CMD_GET_SIWIFI_STATUS @"/api/sfsystem/main_status"
#define CMD_SET_ADMIN_PASSWORD @"/api/sfsystem/setpasswd"
#define CMD_GET_WIFI_DETAIL @"/api/sfsystem/wifi_detail"
#define CMD_SET_WIFI_DETAIL @"/api/sfsystem/setwifi"
#define CMD_CHECK_WAN_TYPE @"/api/sfsystem/check_wan_type"
#define CMD_GET_WAN_TYPE @"/api/sfsystem/get_wan_type"
#define CMD_SET_WAN_TYPE @"/api/sfsystem/set_wan_type"
#define CMD_GET_QOS_INFO @"/api/sfsystem/qos_info"
#define CMD_SET_QOS @"/api/sfsystem/qos_set"
#define CMD_NET_DETECT @"/api/sfsystem/netdetect"
#define CMD_COMMAND @"/api/sfsystem/command"
#define CMD_BIND @"/api/sfsystem/bind"
#define CMD_UNBIND @"/api/sfsystem/unbind"
#define CMD_MANAGER @"/api/sfsystem/manager"
#define CMD_OTA_CHECK @"/api/sfsystem/ota_check2"
#define CMD_OTA_UPGRADE @"/api/sfsystem/ota_upgrade"
#define CMD_GET_WIFI_FILTER @"/api/sfsystem/get_wifi_filter"
#define CMD_SET_WIFI_FILTER @"/api/sfsystem/set_wifi_filter"
#define CMD_UPLOAD_LOG @"/api/sfsystem/upload_log"
#define CMD_SET_USER_INFO @"/api/sfsystem/set_user_info"
#define CMD_NEW_ORAY_PARAMS @"/api/sfsystem/new_oray_params"
#define CMD_DESTROY_ORAY_PARAMS @"/api/sfsystem/destroy_oray_params"
#define CMD_CHECK_NET @"/api/sfsystem/check_net"
#define CMD_DETECT_WAN_TYPE @"/api/sfsystem/detect_wan_type"
#define CMD_GET_DEFAULT @"/api/sfsystem/getdefault"
#define CMD_SET_DEFAULT @"/api/sfsystem/setdefault"

#define CMD_SET_SPEED @"/api/sfsystem/setspeed"
#define CMD_GET_URL_LIST @"/api/sfsystem/urllist_get"
#define CMD_SET_URL_LIST @"/api/sfsystem/urllist_set"
#define CMD_ENABLE_DEVICE_URL_LIST @"/api/sfsystem/urllist_enable"
#define CMD_GET_DEVICE_RESTRICT @"/api/sfsystem/getdevicerestrict"
#define CMD_SET_DEVICE_RESTRICT @"/api/sfsystem/setdevicerestrict"
#define CMD_GET_DEVICE_DATA_USAGE @"/api/sfsystem/getdevicedatausage"
#define CMD_SET_DEVICE_DATA_USAGE @"/api/sfsystem/setdevicedatausage"

#define CMD_GET_WIFIADVANCED @"/api/sfsystem/getwifi_advanced"
#define CMD_SET_WIFIADVANCED @"/api/sfsystem/setwifi_advanced"

#define CMD_GET_WDS_INFO @"/api/sfsystem/get_wds_info"
#define CMD_WDS_SCAN_WIFI @"/api/sfsystem/wifi_scan"
#define CMD_WDS_CONNECT_WIFI @"/api/sfsystem/wifi_connect"
#define CMD_GET_WDS_WAN_IP @"/api/sfsystem/wds_getwanip"
#define CMD_WDS_ENABLE @"/api/sfsystem/wds_enable"
#define CMD_WDS_DISABLE @"/api/sfsystem/wds_disable"
#define CMD_GET_WDS_IFACE @"/api/sfsystem/get_wifi_iface"

#define CMD_GET_WIFI_GUEST @"/api/sfsystem/get_customer_wifi_iface"
#define CMD_SET_WIFI_GUEST @"/api/sfsystem/set_customer_wifi_iface"

#define CMD_GET_WIFI_WARN @"/api/sfsystem/get_warn"
#define CMD_SET_WIFI_WARN @"/api/sfsystem/set_warn"
#define CMD_SET_DEVICE_WARN @"/api/sfsystem/set_dev_warn"

#define CMD_GET_AP_GROUPS @"/api/sfsystem/get_ap_groups"
#define CMD_SET_AP_GROUP @"/api/sfsystem/set_ap_group"
#define CMD_REMOVE_AP_GROUP @"/api/sfsystem/remove_ap_group"
#define CMD_GET_AP_LIST @"/api/sfsystem/get_ap_list"
#define CMD_SET_AP @"/api/sfsystem/set_ap"
#define CMD_DELETE_AP @"/api/sfsystem/delete_ap"

#define CMD_GET_CLIENT_MAC @"/api/visitor/get_client_mac"

#define CMD_GET_LEASE_NET @"/api/sfsystem/get_lease_net"
#define CMD_SET_LEASE_NET @"/api/sfsystem/set_lease_net"
#define CMD_SET_LEASE_MAC @"/api/sfsystem/set_lease_mac"
#define CMD_SET_CLIENT_MAC_ACCESS @"/api/visitor/set_client_mac_access"

#define CMD_AC_AP_OTA_CHECK @"/api/sfsystem/ac_ap_ota_check"
#define CMD_AC_OTA_UPGRADE @"/api/sfsystem/ac_ota_upgrade"

#define CMD_GET_FREQ_INTERGRATION @"/api/sfsystem/get_freq_intergration"
#define CMD_SET_FREQ_INTERGRATION @"/api/sfsystem/set_freq_intergration"
#define CMD_GET_WDS_RELIP @"/api/sfsystem/wds_getrelip"
#define CMD_WDS_ENABLE_NEW @"/api/sfsystem/wds_enable"
#define CMD_WDS_STA_DISCONNECTED @"/api/sfsystem/wds_sta_is_disconnected"

#define CMD_GET_SPEAKER_ALARM @"/api/sfsystem/get_alarm"
#define CMD_DELETE_SPEAKER_ALARM @"/api/sfsystem/del_alarm"
#define CMD_GET_SPEAKER_VOLUNE @"/api/sfsystem/get_volume"
#define CMD_SET_SPEAKER_VOLUNE @"/api/sfsystem/set_volume"
#define CMD_GET_SPEAKER_SLEEP @"/api/sfsystem/get_sleep"
#define CMD_SET_SPEAKER_SLEEP @"/api/sfsystem/set_sleep"
#define CMD_GET_SPEAKER_MUSIC_INFO @"/api/sfsystem/get_music_info"
#define CMD_SET_SPEAKER_MEDIA_CONTROL @"/api/sfsystem/media_control"
#define CMD_GET_SPEAKER_MEDIA_STATES @"/api/sfsystem/get_media_states"
#define CMD_SET_SPEAKER_PLAY_MUSIC @"/api/sfsystem/media_play"
#define CMD_GET_SPEAKER_MUSIC_COLLECTION @"/api/sfsystem/get_collection"
#define CMD_ADD_SPEAKER_MUSIC_COLLECTION @"/api/sfsystem/add_to_collection"
#define CMD_CANCEL_SPEAKER_MUSIC_COLLECTION @"/api/sfsystem/cancel_collection"
#define CMD_GET_SPEAKER_SECURITY_MODE @"/api/sfsystem/get_security_mode"
#define CMD_SET_SPEAKER_SECURITY_MODE @"/api/sfsystem/set_security_mode"
#define CMD_GET_SPEAKER_GREEN_DEVICE @"/api/sfsystem/get_green"
#define CMD_SET_SPEAKER_GREEN_DEVICE @"/api/sfsystem/set_green"

#define CMD_URL_PREFIX @"https://"
#define CMD_COMMON @"/cgi-bin/luci"

typedef NS_ENUM(NSInteger, Status)
{
    RUNING,
    UPGRADING,
    REBOOTING,
    RESTING
};

@interface CommonRet : Jastor
@property (assign, nonatomic,readwrite)int code;
@property (copy, nonatomic,readwrite) NSString *msg;
@end

@interface CommonParams : NSObject
@property (copy, nonatomic, readwrite) NSString *version;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
-(void)setVersion:(NSString *)version;
+ (NSString *)stringByDecodingURLFormate : (NSString *)url;
+ (NSString *)stringByEncodingURLFormate : (NSString *)text;
+ (NSString *)stringByEncodingWifiURLFormate : (NSString *)text;
@end

@interface GetBindInfoParams : CommonParams
- (NSMutableDictionary *)getDictionary;
@end

@interface GetBindInfoRet : CommonRet
@property (assign, nonatomic)int bind;
@property (assign,nonatomic)int passwdset;
@property (copy, nonatomic) NSString *binderid;
@property (copy, nonatomic) NSString *routerid;
@property (copy, nonatomic) NSString *mac;
@end

@interface GetVersionParams : CommonParams
- (NSMutableDictionary *)getDictionary;
@end

@interface GetVersionRet : CommonRet
@property (copy, nonatomic) NSString *version;
@end

@interface GetDeviceListParams : CommonParams
@property (assign, nonatomic) int type;
@property (strong, nonatomic) NSString *mac;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface GetDeviceListRet : CommonRet
@property (strong, nonatomic) NSMutableArray *list;
@end

@class Jastor;
@interface Authority : Jastor
@property (assign,nonatomic)int internet;
@property (assign,nonatomic)int lan;
@property (assign,nonatomic)int notify;
@property (assign,nonatomic)int speedlvl;
@property (assign,nonatomic)int disk;
@property (assign,nonatomic)int limitup;
@property (assign,nonatomic)int limitdown;
@property (assign,nonatomic)int speedlimit;
@property (assign,nonatomic)int listfunc;
- (NSMutableDictionary *)getDictionary;
@end

@interface Speed : Jastor
@property (assign,nonatomic)int maxdownloadspeed;
@property (assign,nonatomic)long long uploadtotal;
@property (assign, nonatomic)int upspeed;
@property (assign, nonatomic)int downspeed;
@property (assign, nonatomic)int online;
@property (assign,nonatomic)int maxuploadspeed;
@property (assign,nonatomic)long long downloadtotal;
- (NSMutableDictionary *)getDictionary;
@end

@interface DeviceTime : Jastor
//@property (copy, nonatomic) NSString *timeid;
@property (assign,nonatomic)int enable;
@property (copy, nonatomic) NSString *starttime;
@property (copy, nonatomic) NSString *endtime;
@property (copy, nonatomic) NSString *week;
@property (assign,nonatomic)int config;
@end

@interface Device : Jastor
@property (copy, nonatomic) NSString *nickname;
@property (copy, nonatomic) NSString *hostname;
@property (copy, nonatomic) NSString *mac;
@property (assign,nonatomic)int online;
@property (assign,nonatomic)int warn;
@property (copy, nonatomic) NSString *ip;
@property (assign,nonatomic)int port;
@property (assign,nonatomic)int is_ap;
@property (copy, nonatomic) NSString *dev;
@property (copy, nonatomic) NSString *icon;
@property (strong, nonatomic) Authority *authority;
@property (strong, nonatomic) Speed *speed;
@property (strong, nonatomic) NSMutableArray *timelist;
@end

@interface GetDeviceNumberParams : GetDeviceListParams
@end

@interface GetDeviceNumberRet : CommonRet
@property (assign,nonatomic)int online;
@end

@interface GetDeviceParams : GetDeviceListParams
@end

@interface GetDeviceRet : CommonRet
//@property (strong ,nonatomic) Device *list;
@property (strong, nonatomic) NSMutableArray *list;
@end

@interface SetDeviceParams : CommonParams
@property (copy, nonatomic) NSString *mac;
@property (copy, nonatomic) NSString *nickname;
@property (assign,nonatomic)int internet;
@property (assign,nonatomic)int lan;
@property (assign,nonatomic)int notify;
@property (assign,nonatomic)int speedlvl;
@property (assign,nonatomic)int limitup;
@property (assign,nonatomic)int limitdown;
@property (assign,nonatomic)int disk;
@property (assign,nonatomic)int warn;
@property (strong, nonatomic) NSMutableArray *timelist;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface SetDeviceRet : CommonRet
@end

@interface GetWifiReminderParams : CommonParams
@end

@interface GetWifiReminderRet : CommonRet
@property (assign,nonatomic) int enable;
@property (assign,nonatomic) int mode;
@end

@interface SetWifiReminderParams : CommonParams
@property (assign,nonatomic)int enable;
@property (assign,nonatomic)int mode;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface SetWifiReminderRet : CommonRet
@end

@interface GetStokLocalParams : CommonParams
@property (copy, nonatomic) NSString *password;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface GetStokLocalRet : CommonRet
@property (strong, nonatomic) NSString *stok;

@end

@interface GetStokRemoteParams : CommonParams
@property (copy, nonatomic) NSString *userid;
@property (copy, nonatomic) NSString *sessiontoken;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface GetStokRemoteRet : GetStokLocalRet
@end

@interface GetSiWiFiInfoParams : CommonParams
@end

@interface GetSiWiFiInfoRet : CommonRet
@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *romversion;
@property (assign,nonatomic)int romversionnumber;
@property (copy, nonatomic) NSString *hardware;
@property (copy, nonatomic) NSString *mac;
@property (copy, nonatomic) NSString *sn;
@property (copy, nonatomic) NSString *account;
@property (assign, nonatomic)int disk;
@property (copy, nonatomic) NSString *routerid;
@end

@interface GetSiWiFiStatusParams : CommonParams
@property (assign,nonatomic)int querycpu;
@property (assign,nonatomic)int querymem;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface GetSiWiFiStatusRet : CommonRet
@property (assign, nonatomic) Status status;
@property (assign,nonatomic)int upspeed;
@property (assign,nonatomic)int downspeed;
@property (assign,nonatomic)int devicecount;
@property (assign,nonatomic)int downloadingcount;
@property (assign,nonatomic)int cpuload;
@property (assign,nonatomic)int memoryload;
@end

@interface SetPasswordParams : CommonParams
@property (copy ,nonatomic) NSString *oldpwd;
@property (copy ,nonatomic) NSString *newpwd;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface SetPasswordRet : CommonRet
@end

@interface GetWiFiDetailParams : CommonParams
@end

@interface WiFiInfo : Jastor
@property (copy ,nonatomic) NSString *ifname;
@property (copy ,nonatomic) NSString *ssid;
@property (assign,nonatomic )int enable;
@property (copy ,nonatomic) NSString *encryption;
@property int signal;
@property (copy ,nonatomic) NSString *password;
@property int channel;
@property (copy ,nonatomic) NSString *mac;
@property (copy ,nonatomic) NSString *band;
@end

@interface GetWiFiDetailRet : CommonRet<NSCoding>
@property (strong, nonatomic) NSMutableArray *info;
@end

@interface WifiParams: NSObject
@property (assign,nonatomic)int enable;
@property (copy, nonatomic) NSString *ssidold;
@property (copy, nonatomic) NSString *ssidnew;
@property (copy, nonatomic) NSString *encryption;
@property (assign,nonatomic)int signalmode;
@property (copy, nonatomic) NSString *password;
@property (assign,nonatomic)int channel;
@property (assign,nonatomic)int flag;
@property (assign,nonatomic)int disableall;

@end

@interface WifiGuestParams: NSObject
@property (copy ,nonatomic) NSString *band;
@property (assign,nonatomic )int remainingtime;
@property (copy ,nonatomic) NSString *ssid;
@property (assign,nonatomic )BOOL enable;
@property (assign,nonatomic )int limittimetype;
@property (assign,nonatomic )BOOL open;
@property (assign,nonatomic )int limitupload;
@property (assign,nonatomic )int limitdownload;
@property (copy ,nonatomic) NSString *periodicaltime;
@property (copy ,nonatomic) NSString *key;
@property (assign,nonatomic )BOOL localaccess;
@property (assign,nonatomic )BOOL limittime;
- (id)getWifiGuestParams;
@end

@interface SetWiFiDetailParams : CommonParams
@property (strong, nonatomic) NSMutableArray *info;
- (NSMutableDictionary *)getDictionary;
- (NSMutableDictionary *)getInternetDictionary;
- (NSString *)toString;
- (NSString *)toInternetString;
@end

@interface SetWiFiDetailRet : CommonRet
@end

@interface CheckWanTypeParams : CommonParams
@end

@interface CheckWanTypeRet : CommonRet
@property (assign, nonatomic) int type;
@end

@interface GetWanTypeParams : CommonParams
@end

@interface GetWanTypeRet : CommonRet
@property (assign, nonatomic) int type;
@property (copy, nonatomic) NSString *pppname;
@property (copy, nonatomic) NSString *ppppwd;
@property (copy, nonatomic) NSString *ip;
@property (copy, nonatomic) NSString *gateway;
@property (copy, nonatomic) NSString *mask;
@property (assign, nonatomic) int autodns;
@property (copy, nonatomic) NSString *dns1;
@property (copy, nonatomic) NSString *dns2;
@end

@interface SetWanTypeParams : CommonParams
@property (assign, nonatomic) int type;
@property (copy, nonatomic) NSString *pppname;
@property (copy, nonatomic) NSString *ppppwd;
@property (copy, nonatomic) NSString *mask;
@property (assign, nonatomic) int autodns;
@property (copy, nonatomic) NSString *dns1;
@property (copy, nonatomic) NSString *dns2;
@property (copy, nonatomic) NSString *address;
@property (copy, nonatomic) NSString *gateway;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface SetWanTypeRet : CommonRet
@end

@interface QosSpeed : Jastor
@property (assign, nonatomic) int upspeed;
@property (assign, nonatomic) int downspeed;
@property (assign, nonatomic) int min;
@property (assign, nonatomic) int max;
@property (assign, nonatomic) int speedlvl;
@end

//@interface QosDevice : Jastor
//{
//    NSString *nickname;
//    NSString *hostname;
//    NSString *mac;
//    NSString *ip;
//    QosSpeed *speed;
//}
//@property (copy, nonatomic) NSString *nickname;
//@property (copy, nonatomic) NSString *hostname;
//@property (copy, nonatomic) NSString *mac;
//@property (copy, nonatomic) NSString *ip;
//@property (strong, nonatomic) QosSpeed *speed;
//@end

@interface GetQosParams : CommonParams
@end

@interface GetQosRet : CommonRet
@property (assign, nonatomic) int enable;
@property (assign, nonatomic) int mode;
@end

@interface SetQosParams : CommonParams
@property (assign, nonatomic) int enable;
@property (assign, nonatomic) int mode;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface SetQosRet : CommonRet
@end

@interface NetDetectParams : CommonParams
@end

@interface WiFi : Jastor
@property (assign, nonatomic) int strong;
@property (assign, nonatomic) int same;
@property (copy, nonatomic) NSString *band;
@end

@interface Ping : Jastor
@property (assign, nonatomic) int status;
@property (assign, nonatomic) int lost;
@end

@interface WanSpeed : Jastor
@property (assign, nonatomic) int upspeed;
@property (assign, nonatomic) int downspeed;
@end

@interface BandWidth : Jastor
@property (assign, nonatomic) int upbandwidth;
@property (assign, nonatomic) int downbandwidth;
@end

@interface NetDetectRet : CommonRet
@property (assign, nonatomic) int wanlink;
@property (strong, nonatomic) NSMutableArray *wifi;
@property (assign, nonatomic) int dns;
@property (assign, nonatomic) int memoryue;
@property (strong, nonatomic) WanSpeed *wanspeed;
@property (assign,nonatomic) int delay;
@property (strong, nonatomic) BandWidth *bandwidth;
@property (assign, nonatomic) int cpuuse;
@property (strong, nonatomic) Ping *ping;
@end

@interface CommandParams : CommonParams
@property (assign,nonatomic)int cmd;
@property (copy, nonatomic) NSString *data;
- (NSMutableDictionary *)getDictionary;
@end

@interface CommandRet : CommonRet
@end

@interface BindParams : CommonParams
@property (copy, nonatomic) NSString *userobjectid;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface BindRet : CommonRet
@property (copy, nonatomic) NSString *routerobjectid;
@end

@interface UnbindParams : BindParams

@end


@interface UnbindRet : CommonRet
@end

@interface ManagerParams : CommonParams
//0 邀请管理员 1 删除管理员 2 接受邀请 3 拒绝邀请 4 退出分享 5 取消分享
@property (assign,nonatomic)int action;
@property (copy, nonatomic) NSString *userid;
@property (copy, nonatomic) NSString *phonenumber;
@property (copy, nonatomic) NSString *username;
@property (copy, nonatomic) NSString *tag;
@property (copy, nonatomic) NSString *routerid;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface ManagerRet : CommonRet
@end

@interface GetWifiFilterParams : CommonParams
@end

@interface GetWifiFilterRet : CommonRet
@property (assign,nonatomic)int enable;
@property (assign,nonatomic)int mode;
@end

@interface SetWifiFilterParams : CommonParams
@property (assign,nonatomic)int enable;
@property (assign,nonatomic)int mode;
- (NSMutableDictionary *)getDictionary;
@end

@interface SetWifiFilterRet : CommonRet
@end

@interface GetOtaCheckParams : CommonParams
@end

@interface OtaCheckRet : CommonRet
@property (copy, nonatomic) NSString *romversion;
@property (copy, nonatomic) NSString *romtime;
@property (copy, nonatomic) NSString *otaversion;
@property (copy, nonatomic) NSString *otatime;
@property (assign, nonatomic) int size;
@property (assign, nonatomic) int type;
@property (copy, nonatomic) NSString *log;
@end

@interface OtaUpgradeParams : CommonParams
@property (assign, nonatomic) int check;
@property (assign, nonatomic) NSString *routerId;
@property (assign, nonatomic) NSString *userid;
@property (assign, nonatomic) NSString *usersubid;
@property (assign, nonatomic) int msgid;
- (NSMutableDictionary *)getDictionary;
@end

@interface OtaUpgradeRet : CommonRet
@property (assign, nonatomic) int status;
@property (assign, nonatomic) int downloaded;
@end

@interface SFLocalUploadLogParams : CommonParams
@property (copy, nonatomic, readwrite) NSString *feedback;
- (NSMutableDictionary *)getDictionary;
- (NSString*)toString;
@end

@interface SFLocalUploadLogRet : CommonRet
@property (copy,nonatomic,readwrite) NSString *objectid;
@end

@interface SetUserInfoParams : CommonParams
@property (copy, nonatomic) NSString *ip;
@property (copy, nonatomic) NSString *port;
- (NSMutableDictionary *)getDictionary;
@end

@interface SetUserInfoRet : CommonRet
@end

@interface NewOrayParams : CommonParams
@end

@interface NewOrayRet : CommonRet
@property (copy, nonatomic) NSString *url;
@property (copy, nonatomic) NSString *session;
@end

@interface DestroyOrayParams : CommonParams
@property (copy, nonatomic) NSString *session;
- (NSMutableDictionary *)getDictionary;
@end

@interface DestroyOrayRet : CommonRet
@end

@interface CheckNetParams : CommonParams
@end

@interface CheckNetRet : CommonRet
@property (assign, nonatomic) int status;
@end

@interface DetectWanTypeParams : CommonParams
@end

@interface DetectWanTypeRet : CommonRet
@property (copy, nonatomic) NSString *wantype;
@end

@interface GetDefaultParams : CommonParams
@end

@interface GetDefaultRet : CommonRet
@property (assign, nonatomic) int internet;
@end

@interface SetDefaultParams : CommonParams
@property (assign, nonatomic) int internet;
- (NSMutableDictionary *)getDictionary;
@end

@interface SetDefaultRet : CommonRet
@end

@interface SetSpeedParams : CommonParams
@property (copy, nonatomic) NSString *mac;
@property (assign, nonatomic) int enable;
@property (assign, nonatomic) int limitup;
@property (assign, nonatomic) int limitdown;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface SetSpeedRet : CommonRet
@end

@interface EnableUrlListParams : CommonParams
@property (assign, nonatomic) int listfunc;
@property (copy, nonatomic) NSString *mac;
@property (strong, nonatomic) NSMutableArray *urllist_en;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface EnableUrlListRet : CommonRet
@end

@interface GetUrlListParams : CommonParams
@property (assign, nonatomic) int listtype;
@property (copy, nonatomic) NSString *mac;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface GetUrlListRet : CommonRet
@property (strong, nonatomic) NSMutableArray *urllist;
@end

@interface SetUrlListParams : CommonParams
@property (strong, nonatomic) NSString *mac;
@property (assign, nonatomic) int listtype;
@property (strong, nonatomic) NSMutableArray *urllist;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface SetUrlListRet : CommonRet
@end

@interface GetDeviceRestictParams : CommonParams
@property (strong, nonatomic) NSString *mac;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface GetDeviceRestictRet : CommonRet
@property (assign, nonatomic) int social;
@property (assign, nonatomic) int video;
@property (assign, nonatomic) int game;
@property (assign, nonatomic) int restrictenable;
@end

@interface SetDeviceRestictParams : CommonParams
@property (strong, nonatomic) NSString *mac;
@property (assign, nonatomic) int social;
@property (assign, nonatomic) int video;
@property (assign, nonatomic) int game;
@property (assign, nonatomic) int restrictenable;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface SetDeviceRestictRet : CommonRet
@end

@interface GetDeviceDataUsageParams : CommonParams
@property (strong, nonatomic) NSString *mac;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface DataUsage : Jastor
@property (assign,nonatomic)int count;
@property (assign, nonatomic)int type;
@property (strong, nonatomic) NSString *week;
- (NSMutableDictionary *)getDictionary;
@end

@interface GetDeviceDataUsageRet : CommonRet
@property (strong, nonatomic) NSMutableArray *setlist;
@property (assign, nonatomic) int credit;
@property (assign, nonatomic) int usageenable;
@end

@interface SetDeviceDataUsageParams : CommonParams
@property (strong, nonatomic) NSString *mac;
@property (strong, nonatomic) NSMutableArray *setlist;
@property (assign, nonatomic) int change;
@property (assign, nonatomic) int usageenable;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface SetDeviceDataUsageRet : CommonRet
@end

@interface UpdateWiFiRentInfoParams : CommonParams
@property (strong, nonatomic) NSString *routerid;
@property (assign, nonatomic) BOOL enable;
@property (assign, nonatomic) long uploadSpeed;
@property (assign, nonatomic) long downloadSpeed;
@property (assign, nonatomic) float unitPrice;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface UpdateWiFiRentalWifiInfo : CommonParams
@property (strong, nonatomic) NSString *routerid;
@property (assign, nonatomic) BOOL enable;
@property (assign, nonatomic) long uploadSpeed;
@property (assign, nonatomic) long downloadSpeed;
@property (assign, nonatomic) float unitPrice;
@property (assign, nonatomic) int  mode;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface UpdateWiFiRentInfoRet : CommonRet
@end

@interface GetWiFiRentInfoParams : NSObject
@property (strong, nonatomic) NSString *mac;
@end

@interface QueryWifiRentInfoParams : NSObject
@property(strong,nonatomic)NSString *routerid;
- (NSMutableDictionary *)getDictionary;
@end
@interface GetWiFiRentInfoRet : CommonRet
@property (strong, nonatomic) NSString *mac;
@property (assign, nonatomic) BOOL enable;
@property (assign, nonatomic) long uploadSpeed;
@property (assign, nonatomic) long downloadSpeed;
@property (assign, nonatomic) float unitPrice;
@property (strong, nonatomic) NSString *ssid;
@end

@interface WiFiGuestInfo : Jastor
@property (copy ,nonatomic) NSString *band;
@property (assign,nonatomic )int remainingtime;
@property (copy ,nonatomic) NSString *ssid;
@property (assign,nonatomic )BOOL enable;
@property (assign,nonatomic )int limittimetype;
@property (assign,nonatomic )BOOL open;
@property (assign,nonatomic )int limitupload;
@property (assign,nonatomic )int limitdownload;
@property (copy ,nonatomic) NSString *periodicaltime;
@property (copy ,nonatomic) NSString *key;
@property (assign,nonatomic )BOOL localaccess;
@property (assign,nonatomic )BOOL limittime;
@end

@interface GetWiFiGuestParams : CommonParams
@end

@interface GetWiFiGuestRet : CommonRet
@property (strong, nonatomic) NSMutableArray *info;
@end

@interface SetWiFiGuestParams : CommonParams
@property (strong, nonatomic) NSMutableArray *guest;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface SetWiFiGuestRet : CommonRet
@end

@interface WiFiAdvancedInfo : Jastor
@property (copy ,nonatomic) NSString *ifname;
@property (assign,nonatomic )int enable;
@property (copy ,nonatomic) NSString *ssid;
@property (copy ,nonatomic) NSString *encryption;
@property (copy ,nonatomic) NSString *password;
@property (assign,nonatomic )int channel;
@property (copy,nonatomic )NSString *htmode;
@property (copy ,nonatomic) NSString *country;
@property (assign,nonatomic )int signalmode;
@property (assign,nonatomic )long distance;
@property (assign,nonatomic )int fragment;
@property (assign,nonatomic )int rts;
@end

@interface WiFiAdvancedPramas : NSObject
//@property (assign,nonatomic )int enable;
//@property (copy ,nonatomic) NSString *ssid;
//@property (copy ,nonatomic) NSString *encryption;
//@property (assign,nonatomic )int channel;
@property (assign,nonatomic )int bandwidth;
//@property (copy ,nonatomic) NSString *country;
@property (assign,nonatomic )int signalmode;
//@property (assign,nonatomic )long distance;
//@property (assign,nonatomic )int fragment;
//@property (assign,nonatomic )int rts;
- (id)getWiFiAdvancedPramas;
@end

@interface GetWiFiAdvanceParams : CommonParams
@end

@interface GetWiFiAdvanceRet : CommonRet
@property (strong, nonatomic) NSMutableArray *info;
@end

@interface SetWiFiAdvanceParams : CommonParams
@property (strong, nonatomic) NSMutableArray *info;
- (NSMutableDictionary *)getDictionary;
- (NSString *)toString;
@end

@interface SetWiFiAdvanceRet : CommonRet
@end

@interface WDSInfo : Jastor
@property (copy ,nonatomic) NSString *band;
@property (copy ,nonatomic) NSString *ssid;
@property (copy ,nonatomic) NSString *bssid;
@property (copy ,nonatomic) NSString *key;
@property (copy ,nonatomic) NSString *ip;
@property (assign,nonatomic) int enable;
@property (assign,nonatomic) int channel;
@property (copy ,nonatomic) NSString *lanip;
@end

@interface GetWDSInfoParams : CommonParams
@end

@interface GetWDSInfoRet : CommonRet
@property (strong, nonatomic) NSMutableArray *info;
@end

@interface WDSScanInfoEncryption : Jastor
@property (copy ,nonatomic) NSString *description;
@property (assign,nonatomic )BOOL enabled;
//@property (assign,nonatomic )BOOL wep;
//@property (assign,nonatomic )int wpa;
//@property (strong, nonatomic) NSMutableArray *auth_suites;
//@property (strong, nonatomic) NSMutableArray *pair_ciphers;
//@property (strong, nonatomic) NSMutableArray *group_ciphers;
//@property (strong, nonatomic) id auth_algs;
@end

@interface WDSScanInfo : Jastor
@property (copy ,nonatomic) NSString *mode;
@property (assign,nonatomic) int quality_max;
@property (assign,nonatomic) int channel;
@property (assign,nonatomic) int signal;
@property (copy ,nonatomic) NSString *ssid;
@property (copy ,nonatomic) NSString *bssid;
@property (assign,nonatomic) int quality;
@property (strong, nonatomic) WDSScanInfoEncryption *encryption;
@end

@interface WDSWiFiScanParams : CommonParams
@property (copy ,nonatomic) NSString *band;
- (NSMutableDictionary *)getDictionary;
@end

@interface WDSWiFiScanRet : CommonRet
@property (copy ,nonatomic) NSString *device;
@property (assign,nonatomic )int noise;
@property (strong, nonatomic) NSMutableArray *list;
@end

@interface WDSConnectWiFiParams : CommonParams
@property (copy ,nonatomic) NSString *encryption;
@property (copy ,nonatomic) NSString *key;
@property (copy ,nonatomic) NSString *ssid;
@property (copy ,nonatomic) NSString *bssid;
@property (assign ,nonatomic) int channel;
- (NSMutableDictionary *)getDictionary;
@end

@interface WDSConnectWiFiRet : CommonRet
@property (copy ,nonatomic) NSString *band;
@end

@interface WDSGetWanIPParams : CommonParams
@property (copy ,nonatomic) NSString *band;
- (NSMutableDictionary *)getDictionary;
@end

@interface WDSGetWanIPRet : CommonRet
@property (copy ,nonatomic) NSString *ip;
@end

@interface WDSEnableWiFiIface : Jastor
@property (copy ,nonatomic) NSString *band;
@property (copy ,nonatomic) NSString *ssid;
@property (copy ,nonatomic) NSString *key;
@end

@interface WDSEnableParams : CommonParams
@property (copy ,nonatomic) NSString *ip;
@property (strong, nonatomic) NSMutableArray *ifaces;
- (NSMutableDictionary *)getDictionary;
@end

@interface WDSEnableRet : CommonRet
@property (assign ,nonatomic) int redirect;
@end

@interface WDSEnableNewParams : CommonParams
@property (copy ,nonatomic) NSString *band;
@property (strong, nonatomic) NSMutableArray *ifaces;
- (NSMutableDictionary *)getDictionary;
@end

@interface WDSEnableNewRet : CommonRet
@end

@interface WDSDisableParams : CommonParams
@property (assign ,nonatomic) int redirect;
- (NSMutableDictionary *)getDictionary;
@end

@interface WDSDisableRet : CommonRet
@property (copy ,nonatomic) NSString *ip;
@end

@interface WDSWiFiIface : Jastor
@property (copy ,nonatomic) NSString *band;
@property (assign ,nonatomic) int channel;
@property (copy ,nonatomic) NSString *htmode;
@property (copy ,nonatomic) NSString *hwmode;
@property (assign ,nonatomic) BOOL enable;
@property (copy ,nonatomic) NSString *ssid;
@property (copy ,nonatomic) NSString *key;
@property (assign ,nonatomic) BOOL open;
@property (assign ,nonatomic) int signal;
@property (assign ,nonatomic) BOOL broadcast;
@property (assign ,nonatomic) BOOL apartheid;
@end

@interface GetWDSIfaceParams : CommonParams
@end

@interface GetWDSIfaceRet : CommonRet
@property (strong, nonatomic) NSMutableArray *ifaces;
@end

//For wifi warn params
@interface GetWiFiWarnParams : CommonParams
@end

@interface GetWiFiWarnRet : CommonRet
@property (assign ,nonatomic) int enable;
@end

@interface SetWiFiWarnParams : CommonParams
@property (assign ,nonatomic) int enable;
- (NSMutableDictionary *)getDictionary;
@end

@interface SetWiFiWarnRet : CommonRet
@end

@interface SetDeviceWiFiWarnParams : CommonParams
@property (copy ,nonatomic) NSString *mac;
@end

@interface SetDeviceWiFiWarnRet : CommonRet
@end

//For AP Controller
@interface APGroupsIfaceBandLimit : Jastor
@property (assign ,nonatomic) int download;
@property (assign ,nonatomic) int enable;
@property (assign ,nonatomic) int upload;
@end

@interface APGroupsIface : Jastor
@property (assign ,nonatomic) int band;
@property (strong ,nonatomic) APGroupsIfaceBandLimit *band_width_limit;
@property (assign ,nonatomic) int enable;
@property (copy ,nonatomic) NSString *encryption;
@property (assign ,nonatomic) int hide;
@property (assign ,nonatomic) int isolation;
@property (assign ,nonatomic) int channel;
@property (copy ,nonatomic) NSString *password;
@property (copy ,nonatomic) NSString *ssid;
@end

@interface APGroupsInfo : Jastor
@property (assign ,nonatomic) int alive;
@property (assign ,nonatomic) int total;
@property (assign ,nonatomic) int unworkable;
@end

@interface APGroupsList : Jastor
@property (strong, nonatomic) NSMutableArray *ifaces;
@property (assign ,nonatomic) int index;
@property (strong, nonatomic) APGroupsInfo *info;
@property (copy ,nonatomic) NSString *name;
@end

@interface GetAPGroupsParams : CommonParams
@end

@interface GetAPGroupsRet : CommonRet
@property (strong, nonatomic) NSMutableArray *ap_group_list;
@end

@interface APList : Jastor
@property (copy ,nonatomic) NSString *mac;
@property (copy ,nonatomic) NSString *hardware_version;
@property (copy ,nonatomic) NSString *group;
@property (strong, nonatomic) NSMutableArray *ifaces;
@property (assign ,nonatomic) int led;
@property (copy ,nonatomic) NSString *name;
@property (copy ,nonatomic) NSString *model;
@property (assign ,nonatomic) int status;
@property (assign ,nonatomic) int client_idle_time;
@property (assign ,nonatomic) int ap_alive_time;
@property (assign ,nonatomic) int client_alive_time;
@property (copy ,nonatomic) NSString *firmware_version;
@end

@interface GetAPListParams : CommonParams
@property (assign ,nonatomic) int index;
- (NSMutableDictionary *)getDictionary;
@end

@interface GetAPListRet : CommonRet
@property (strong, nonatomic) NSMutableArray *ap_list;
@end

@interface SetAPGroupParams : CommonParams
@property (assign ,nonatomic) int index;
@property (copy ,nonatomic) NSString *name;
@property (strong, nonatomic) NSMutableArray *ifaces;
@property (strong, nonatomic) APGroupsInfo *info;
- (NSMutableDictionary *)getDictionary;
@end

@interface SetAPGroupRet : CommonRet
@end

@interface RemoveAPGroupParams : CommonParams
@property (assign ,nonatomic) int index;
- (NSMutableDictionary *)getDictionary;
@end

@interface RemoveAPGroupRet : CommonRet
@end

@interface SetAPParams : CommonParams
@property (copy ,nonatomic) NSString *name;
@property (strong ,nonatomic) NSMutableArray *macs;
@property (assign ,nonatomic) int led;
@property (assign ,nonatomic) int ap_group_index;
@property (strong, nonatomic) NSMutableArray *ifaces;
@property (assign ,nonatomic) int client_alive_time;
@property (assign ,nonatomic) int client_idle_time;
@property (assign ,nonatomic) int ap_alive_time;
- (NSMutableDictionary *)getDictionary;
@end

@interface SetAPRet : CommonRet
@end

@interface DeleteAPParams : CommonParams
//@property (copy ,nonatomic) NSString *name;
@property (strong ,nonatomic) NSMutableArray *macs;
//@property (assign ,nonatomic) int led;
//@property (strong, nonatomic) NSMutableArray *ifaces;
- (NSMutableDictionary *)getDictionary;
@end

@interface DeleteAPRet : CommonRet
@end

//For WiFi Rental
@interface GetClientMacRet : CommonRet
@property (strong, nonatomic) NSString *devicemac;
@property (strong, nonatomic) NSString *wlan;
@end

@interface GetLeaseNetParams : CommonParams
- (NSMutableDictionary *)getDictionary;
@end

@interface GetLeaseNetRet : CommonRet
@property (assign ,nonatomic) BOOL enable;
@property (copy ,nonatomic) NSString *ssid;
@property (assign ,nonatomic) long limitdownload;
@end

@interface SetLeaseNetParams : CommonParams
@property (assign ,nonatomic) BOOL enable;
@property (copy ,nonatomic) NSString *ssid;
@property (assign ,nonatomic) long limitdownload;
- (NSMutableDictionary *)getDictionary;
@end

@interface SetLeaseNetRet : CommonRet
@end

@interface SetLeaseMacParams : CommonParams
@property (assign ,nonatomic) int timecount;
@property (copy ,nonatomic) NSString *mac;
- (NSMutableDictionary *)getDictionary;
@end

@interface SetLeaseMacRet : CommonRet
@end

@interface SetClientMacAccessParams : CommonParams
@property (assign ,nonatomic) int timecount;
@property (copy ,nonatomic) NSString *mac;
@end

@interface SetClientMacAccessRet : CommonRet
@end

@interface OTACheckDetail : Jastor
@property (copy, nonatomic) NSString *romversion;
@property (copy, nonatomic) NSString *romtime;
@property (copy, nonatomic) NSString *otaversion;
@property (copy, nonatomic) NSString *otatime;
@property (assign, nonatomic) int size;
@property (assign, nonatomic) int type;
@property (copy, nonatomic) NSString *checksum;
@property (copy, nonatomic) NSString *url;
@property (assign, nonatomic) int force;
@property (assign, nonatomic) int stop;
@property (copy, nonatomic) NSString *log;
@end

@interface GetACOtaCheckParams : CommonParams
@end

@interface ACOtaCheckRet : CommonRet
@property (strong, nonatomic) OTACheckDetail *ac;
@property (strong, nonatomic) NSMutableArray *ap;
@end

@interface ACOtaUpgradeParams : CommonParams
@property (assign, nonatomic) int check;
@property (assign, nonatomic) int mode;
@property (assign, nonatomic) int msgid;
@property (assign, nonatomic) NSString *userid;
@property (assign, nonatomic) NSString *usersubid;
- (NSMutableDictionary *)getDictionary;
@end

@interface ACOtaUpgradeRet : CommonRet
@property (assign, nonatomic) int mode;
@property (assign, nonatomic) int status;
@property (assign, nonatomic) int downloaded;
@end

@interface GetFreqIntergrationParams : CommonParams
@end

@interface GetFreqIntergrationRet : CommonRet
@property (assign, nonatomic) int enable;
@end

@interface SetFreqIntergrationParams : CommonParams
@property (assign, nonatomic) int enable;
- (NSMutableDictionary *)getDictionary;
@end

@interface SetFreqIntergrationRet : CommonRet
@end

@interface GetWDSStaParams : CommonParams
- (NSMutableDictionary *)getDictionary;
@end

@interface GetWDSStaRet : CommonRet
@end

@interface AlarmInfo : Jastor
@property (copy, nonatomic) NSString *sec;
@property (copy, nonatomic) NSString *min;
@property (copy, nonatomic) NSString *hour;
@property (copy, nonatomic) NSString *day;
@property (copy, nonatomic) NSString *mon;
@property (copy, nonatomic) NSString *year;
@property (copy, nonatomic) NSString *vid;
@property (copy, nonatomic) NSString *notify;
@end

@interface GetAlarmParams : CommonParams
@property (assign, nonatomic)int type;
- (NSMutableDictionary *)getDictionary;
@end

@interface GetAlarmRet : CommonRet
@property (assign, nonatomic)int type;
@property (strong, nonatomic) NSMutableArray *result;
@end

@interface DeleteAlarmParams : CommonParams
@property (assign, nonatomic)int type;
@property (strong, nonatomic) NSMutableArray *contents;
- (NSMutableDictionary *)getDictionary;
@end

@interface DeleteAlarmRet : CommonRet
@end

@interface GetVolumeParams : CommonParams
@end

@interface GetVolumeRet : CommonRet
@property (assign, nonatomic)int volume;
@end

@interface SetVolumeParams : CommonParams
@property (assign, nonatomic) int volume;
- (NSMutableDictionary *)getDictionary;
@end

@interface SetVolumeRet : CommonRet
@end

@interface GetSleepParams : CommonParams
@end

@interface GetSleepRet : CommonRet
@property (assign, nonatomic)int sleeping;
@end

@interface SetSleepParams : CommonParams
@property (assign, nonatomic)int sleeping;
- (NSMutableDictionary *)getDictionary;
@end

@interface SetSleepRet : CommonRet
@end

@interface MusicInfoExtra : Jastor
@property (copy, nonatomic) NSString *resType;
@property (copy, nonatomic) NSString *origintitle;
@property (assign, nonatomic) int source;
@end

@interface MusicInfo : Jastor
@property (copy, nonatomic) NSString *subTitle;
@property (strong, nonatomic) MusicInfoExtra *extra;
//@property (copy, nonatomic) NSString *imageUrl;
@property (copy, nonatomic) NSString *linkUrl;
@property (copy, nonatomic) NSString *label;
@property (copy, nonatomic) NSString *title;
@end

@interface GetMusicInfoParams : CommonParams
@end

@interface GetMusicInfoRet : CommonRet
@property (strong, nonatomic) NSMutableArray *contents;
@end

@interface SetMediaControlParams : CommonParams
@property (assign, nonatomic) int command;
- (NSMutableDictionary *)getDictionary;
@end

@interface SetMediaControlRet : CommonRet
@end

@interface GetMediaStatusParams : CommonParams
@end

@interface GetMediaStatusRet : CommonRet
@property (copy, nonatomic) NSString *url;
@property (assign, nonatomic) int duration;
@property (assign, nonatomic) int position;
@property (assign, nonatomic) int play_mode;
@property (assign, nonatomic) int playing_state;
@property (assign, nonatomic) int collected;
@property (assign, nonatomic) MusicInfo *info;
@end

@interface MediaPlayMusicParams : CommonParams
@property (strong, nonatomic) MusicInfo *music;
- (NSMutableDictionary *)getDictionary;
@end

@interface MediaPlayMusicRet : CommonRet
@end

@interface AddMusicCollectionParams : CommonParams
@property (strong, nonatomic) MusicInfo *music;
- (NSMutableDictionary *)getDictionary;
@end

@interface AddMusicCollectionRet : CommonRet
@end

@interface CancelMusicCollectionParams : CommonParams
@property (copy, nonatomic) NSString *url;
- (NSMutableDictionary *)getDictionary;
@end

@interface CancelMusicCollectionRet : CommonRet
@end

@interface GetMusicCollectionParams : CommonParams
@end

@interface GetMusicCollectionRet : CommonRet
@property (strong, nonatomic) NSMutableArray *collections;
@property (assign, nonatomic) int len;
@end

@interface GetSecurityModeParams : CommonParams
@end

@interface GetSecurityModeRet : CommonRet
@property (assign, nonatomic) int security_mode;
@end

@interface SetSecurityModeParams : CommonParams
@property (assign, nonatomic) int enable;
- (NSMutableDictionary *)getDictionary;
@end

@interface SetSecurityModeRet : CommonRet
@end

@interface GetGreenParams : CommonParams
@end

@interface GetGreenRet : CommonRet
@property (copy, nonatomic) NSString *start_time;
@property (copy, nonatomic) NSString *end_time;
@property (assign, nonatomic) int limit;
@property (assign, nonatomic) int enable;
@end

@interface SetGreenParams : CommonParams
@property (copy, nonatomic) NSString *start_time;
@property (copy, nonatomic) NSString *end_time;
@property (assign, nonatomic) int limit;
@property (assign, nonatomic) int enable;
- (NSMutableDictionary *)getDictionary;
@end

@interface SetGreenRet : CommonRet
@end

#pragma mark - 本地操作队列

typedef void(^CompletionLoad)(id result);
typedef void (^onSuccess)(CommonRet *ret);
typedef void (^onError)(int code, NSString *msg);
typedef void (^onGetToken)(NSString *token);

@interface LocalOperation1 : NSOperation
@property Class retclass;
@property (copy, nonatomic) onSuccess onsuccess;
@property (copy, nonatomic) onError onerror;
@property (strong, nonatomic) NSString *url;
@property (strong, nonatomic) NSString *type;
@property (strong, nonatomic) NSDictionary *dictionary;
- (instancetype)initWithCommonParams:(NSString *)url1 dictioary:(NSDictionary *)dict retclass:(Class )bclass httpMethod:(NSString*)type1 success:(onSuccess)success error:(onError)error;

@end

@interface LocalOperation2 : NSOperation
@property Class retclass;
@property (copy, nonatomic) onSuccess onsuccess;
@property (copy, nonatomic) onError onerror;
@property (copy, nonatomic) onGetToken ongettoken;
@property (strong, nonatomic) NSString *cmd;//不同Http请求的url字段
@property (strong, nonatomic) NSDictionary *dictionary;
@property (strong, nonatomic) NSString *ip;
@property (strong, nonatomic) NSString *objectId;
@property (strong, nonatomic) NSString *password;
@property (strong, nonatomic) NSString *token;
@property (strong, nonatomic) NSString *type;
- (instancetype)initWithCommonParams:(NSString *)cmd1 ip:(NSString *)ip1 objid:(NSString *)objid passwd:(NSString *)passwd token:(NSString *)stok dictioary:(NSDictionary *)dict retclass:(Class)bclass httpMethod:(NSString*)type1 success:(onSuccess)success error:(onError)error gettoken:(onGetToken)gettoken;
@end

@interface LocalOperation3 : NSOperation
@property Class retclass;
@property (copy, nonatomic) onSuccess onsuccess;
@property (copy, nonatomic) onError onerror;
@property (strong, nonatomic) NSString *url;
@property (strong, nonatomic) NSString *type;
@property (strong, nonatomic) id bodyDic;
- (instancetype)initWithCommonParams:(NSString *)urlString body:(id)body retclass:(Class )bclass httpMethod:(NSString*)type1 success:(onSuccess)success error:(onError)error;

@end


typedef void (^GetIPOnResult)(id ret, int code, NSString *msg);

@interface LocalGetIPOperation : NSOperation
@property (strong, nonatomic) id mParam;
@property (strong, nonatomic) GetIPOnResult mOnResult;
- (instancetype)initWithCommonParams:(id)parama result:(GetIPOnResult)result;
@end

typedef NS_ENUM(NSInteger, TokenGetMode)
{
    PASSWORD,
    UER_OBJECT
};

@class GCDAsyncUdpSocket;
@interface LocalApi_v2 : NSObject
{
    NSOperationQueue *queue;
}
@property (strong, nonatomic) NSString *routerIp;
@property (strong, nonatomic) NSString *tokenSession;
@property (strong, nonatomic) NSString *adminPassword;
@property (strong, nonatomic) NSString *userObjectId;
@property TokenGetMode mTokenGetMode;
@property (strong, nonatomic)GCDAsyncUdpSocket * udpSocket;
+ (void)requestWithURL:(NSString *)url params:(NSDictionary *)params httpMethod:(NSString *)httpMethod block:(CompletionLoad)block;

- (instancetype)quickInit:(NSString *)userid;
+ (NSString *)getRouterIp;
- (NSString *)getMacAddress;
- (NSString *)getCurrentConnectWifiName;
- (BOOL)isSiWiFi;

- (void)getRouterIp:(GetIPOnResult)success;

- (void)getBindInfo:(onSuccess)success error:(onError)error;
- (void)getVersion:(onSuccess)success error:(onError)error;
- (void)getStokLocal:(GetStokLocalParams *)param success:(onSuccess)success error:(onError)error;
- (void)getStokRemote:(GetStokRemoteParams *)param success:(onSuccess)success error:(onError)error;
- (void)setPassword:(SetPasswordParams *)param success:(onSuccess)success error:(onError)error;
- (void)setCommandReboot:(onSuccess)success error:(onError)error;
- (void)setCommandShutDown:(onSuccess)success error:(onError)error;
- (void)setCommandReset:(onSuccess)success error:(onError)error;
- (void)getSiwifiInfo:(GetSiWiFiInfoParams *)param success:(onSuccess)success error:(onError)error;
- (void)getSiwifiStatus:(GetSiWiFiStatusParams *)param success:(onSuccess)success error:(onError)error;
- (void)getWifiDetail:(GetWiFiDetailParams *)param success:(onSuccess)success error:(onError)error;
- (void)setWifiDetail:(SetWiFiDetailParams *)param success:(onSuccess)success error:(onError)error;
- (void)bindRouter:(BindParams *)param success:(onSuccess)success error:(onError)error;
- (void)unbindRouter:(UnbindParams *)param success:(onSuccess)success error:(onError)error;

- (void)setWifiFilter:(SetWifiFilterParams *)param success:(onSuccess)success error:(onError)error;
- (void)getWifiFilter:(GetWifiFilterParams *)param success:(onSuccess)success error:(onError)error;
- (void)getDeviceList:(GetDeviceListParams *)param success:(onSuccess)success error:(onError)error;
- (void)setDevice:(SetDeviceParams *)param success:(onSuccess)success error:(onError)error;
- (void)getOnlineDeviceNumber:(GetDeviceNumberParams *)param success:(onSuccess)success error:(onError)error;
- (void)getSingleDevice:(GetDeviceParams *)param success:(onSuccess)success error:(onError)error;

- (void)manageRouter:(ManagerParams *)param success:(onSuccess)success error:(onError)error;

- (void)checkWanType:(CheckWanTypeParams *)param success:(onSuccess)success error:(onError)error;
- (void)getWanType:(GetWanTypeParams *)param success:(onSuccess)success error:(onError)error;
- (void)setWanType:(SetWanTypeParams *)param success:(onSuccess)success error:(onError)error;

- (void)getQosInfo:(GetQosParams *)param success:(onSuccess)success error:(onError)error;
- (void)setQosInfo:(SetQosParams *)param success:(onSuccess)success error:(onError)error;

- (void)netDetect:(NetDetectParams *)param success:(onSuccess)success error:(onError)error;

- (void)otaUpdate:(OtaUpgradeParams *)param success:(onSuccess)success error:(onError)error;
- (void)uploadLog:(SFLocalUploadLogParams*)param success:(onSuccess)success error:(onError)error;

- (void)setUserInfo:(SetUserInfoParams*)param success:(onSuccess)success error:(onError)error;

- (void)destroyOrayParams:(DestroyOrayParams*)param success:(onSuccess)success error:(onError)error;

- (void)chectNet:(CheckNetParams*)param success:(onSuccess)success error:(onError)error;
- (void)detectWanType:(DetectWanTypeParams*)param success:(onSuccess)success error:(onError)error;

- (void)getDefault:(GetDefaultParams*)param success:(onSuccess)success error:(onError)error;
- (void)setDefault:(SetDefaultParams*)param success:(onSuccess)success error:(onError)error;

- (void)getOtaCheck:(GetOtaCheckParams*)param success:(onSuccess)success error:(onError)error;

- (void)setUserObject:(NSString *)s;
- (void)setAdminPassword:(NSString *)s;

- (void)setSpeed:(SetSpeedParams*)param success:(onSuccess)success error:(onError)error;

- (void)getUrlList:(GetUrlListParams*)param success:(onSuccess)success error:(onError)error;
- (void)setUrlList:(SetUrlListParams*)param success:(onSuccess)success error:(onError)error;
- (void)enableUrlList:(EnableUrlListParams*)param success:(onSuccess)success error:(onError)error;

- (void)getDeviceRestrict:(GetDeviceRestictParams*)param success:(onSuccess)success error:(onError)error;
- (void)setDeviceRestrict:(SetDeviceRestictParams*)param success:(onSuccess)success error:(onError)error;
- (void)getDeviceDataUsage:(GetDeviceDataUsageParams*)param success:(onSuccess)success error:(onError)error;
- (void)setDeviceDataUsage:(SetDeviceDataUsageParams*)param success:(onSuccess)success error:(onError)error;

- (void)getGuestWifi:(GetWiFiGuestParams *)param success:(onSuccess)success error:(onError)error;
- (void)setGuestWifi:(SetWiFiGuestParams *)param success:(onSuccess)success error:(onError)error;

- (void)getAdvancedWifi:(GetWiFiAdvanceParams *)param success:(onSuccess)success error:(onError)error;
- (void)setAdvancedWifi:(SetWiFiAdvanceParams *)param success:(onSuccess)success error:(onError)error;

- (void)getWDSInfo:(GetWDSInfoParams *)param success:(onSuccess)success error:(onError)error;
- (void)getWDSWiFiScan:(WDSWiFiScanParams *)param success:(onSuccess)success error:(onError)error;

- (void)setWDSConnectWiFi:(WDSConnectWiFiParams *)param success:(onSuccess)success error:(onError)error;
- (void)getWDSWanIP:(WDSGetWanIPParams *)param success:(onSuccess)success error:(onError)error;
- (void)getWDSRelIP:(WDSGetWanIPParams *)param success:(onSuccess)success error:(onError)error;

- (void)enableRouterWDS:(WDSEnableParams *)param success:(onSuccess)success error:(onError)error;
- (void)enableRouterWDSNew:(WDSEnableNewParams *)param success:(onSuccess)success error:(onError)error;
- (void)disableRouterWDS:(WDSDisableParams *)param success:(onSuccess)success error:(onError)error;
- (void)getWDSWiFiIfaces:(GetWDSIfaceParams *)param success:(onSuccess)success error:(onError)error;
- (void)getWDSSta:(GetWDSStaParams *)param success:(onSuccess)success error:(onError)error;

//wifi warn api
- (void)getWifiWarn:(GetWiFiWarnParams *)param success:(onSuccess)success error:(onError)error;
- (void)setWifiWarn:(SetWiFiWarnParams *)param success:(onSuccess)success error:(onError)error;
- (void)disableDeviceWifiWarn:(SetDeviceWiFiWarnParams *)param success:(onSuccess)success error:(onError)error;

//AC Controller api
- (void)getAPGroups:(GetAPGroupsParams *)param success:(onSuccess)success error:(onError)error;
- (void)setAPGroup:(SetAPGroupParams *)param success:(onSuccess)success error:(onError)error;
- (void)getAPList:(GetAPListParams *)param success:(onSuccess)success error:(onError)error;
- (void)setAP:(SetAPParams *)param success:(onSuccess)success error:(onError)error;
- (void)removeAPGroup:(RemoveAPGroupParams *)param success:(onSuccess)success error:(onError)error;
- (void)deleteAP:(DeleteAPParams *)param success:(onSuccess)success error:(onError)error;

- (void)getACOtaCheck:(GetACOtaCheckParams*)param success:(onSuccess)success error:(onError)error;
- (void)acOtaUpdate:(ACOtaUpgradeParams *)param success:(onSuccess)success error:(onError)error;

- (void)getClientMAC:(onSuccess)success error:(onError)error;

//WiFi rent api
- (void)getLeaseNet:(GetLeaseNetParams *)param success:(onSuccess)success error:(onError)error;
- (void)setLeaseNet:(SetLeaseNetParams *)param success:(onSuccess)success error:(onError)error;
- (void)setLeaseMac:(SetLeaseMacParams *)param success:(onSuccess)success error:(onError)error;
- (void)setClientAccessNet:(SetClientMacAccessParams *)param success:(onSuccess)success error:(onError)error;
//WiFi Freqintergration
- (void)getFreqIntergration:(GetFreqIntergrationParams *)param success:(onSuccess)success error:(onError)error;
- (void)setFreqIntergration:(SetFreqIntergrationParams *)param success:(onSuccess)success error:(onError)error;

//Speaker api
- (void)getSpeakerAlarm:(GetAlarmParams *)param success:(onSuccess)success error:(onError)error;
- (void)deleteSpeakerAlarm:(DeleteAlarmParams *)param success:(onSuccess)success error:(onError)error;

- (void)getSpeakerVolume:(GetVolumeParams *)param success:(onSuccess)success error:(onError)error;
- (void)setSpeakerVolume:(SetVolumeParams *)param success:(onSuccess)success error:(onError)error;

- (void)getSpeakerSleep:(GetSleepParams *)param success:(onSuccess)success error:(onError)error;
- (void)setSpeakerSleep:(SetSleepParams *)param success:(onSuccess)success error:(onError)error;

- (void)getSpeakerMusicInfo:(GetMusicInfoParams *)param success:(onSuccess)success error:(onError)error;
- (void)setSpeakerMediaControl:(SetMediaControlParams *)param success:(onSuccess)success error:(onError)error;

- (void)getSpeakerMediaStatus:(GetMediaStatusParams *)param success:(onSuccess)success error:(onError)error;
- (void)setSpeakerPlayMusic:(MediaPlayMusicParams *)param success:(onSuccess)success error:(onError)error;

- (void)getSpeakerMusicCollection:(GetMusicCollectionParams *)param success:(onSuccess)success error:(onError)error;
- (void)addSpeakerMusicCollection:(AddMusicCollectionParams *)param success:(onSuccess)success error:(onError)error;
- (void)cancelSpeakerMusicCollection:(CancelMusicCollectionParams *)param success:(onSuccess)success error:(onError)error;

- (void)getSpeakerSecurityMode:(GetSecurityModeParams *)param success:(onSuccess)success error:(onError)error;
- (void)setSpeakerSecurityMode:(SetSecurityModeParams *)param success:(onSuccess)success error:(onError)error;

- (void)getSpeakerGreen:(GetGreenParams *)param success:(onSuccess)success error:(onError)error;
- (void)setSpeakerGreen:(SetGreenParams *)param success:(onSuccess)success error:(onError)error;

@end











