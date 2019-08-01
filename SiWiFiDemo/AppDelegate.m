//
//  AppDelegate.m
//  SiWiFiDemo
//
//  Created by edward on 2018/12/27.
//  Copyright © 2018年 siflower. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import "Reachability.h"
#import <SiRouterApi/SiWiFiManager.h>

SiWiFiManager *manager;
SiRouter *MyCurrentRouter;
@interface AppDelegate ()
@property (nonatomic,assign) UIBackgroundTaskIdentifier backgroundTask;
@property (strong, nonatomic) Reachability *hostReach;
@end

@implementation AppDelegate
@synthesize hostReach;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    manager = [SiWiFiManager new];
    MyCurrentRouter = [[SiRouter alloc]init];
    
    
    [UIApplication sharedApplication].statusBarStyle=UIStatusBarStyleLightContent;
    [self setStatusBarBackgroundColor:[UIColor colorWithRed:64/255.0 green:180/255.0 blue:255/255.0 alpha:1]];
    ViewController *fc = [[ViewController alloc]init];
    
    UINavigationController *navCtrlr = [[UINavigationController alloc]initWithRootViewController:fc];
    [navCtrlr.navigationBar setBackgroundImage:[UIImage new] forBarMetrics:UIBarMetricsDefault];
    [self.window setRootViewController:navCtrlr];
    //用户需要自己注册新的appkey 和secrectkey
    NSArray *productKeys = [NSArray arrayWithObject:@"25dd9e496f31064299a438621540bd95"];
    
    [manager initializeManager:@"25dd9e496f31064299a438621540bd95" andRouterKeys:productKeys];
    
    [manager initLocalApi:^(id ret) {
        NSLog(@"initlocalapi");
        manager.mLocalapi.adminPassword = @"admin";
        //[self registeUser];
        [self userLogin];
    } error:^(int code, NSString *msg) {
        NSLog(@"initlocalapi----%d,%@",code,msg);
    }];
    
    
    [self performSelector:@selector(registPUSH:) withObject:(id)launchOptions afterDelay:10];
    return YES;
}

//注册
-(void) registeUser{
    [manager createUserKey:@"25dd9e496f31064299a438621540bd95" andSecretKey:@"480dfbc039017984ea10f7a42065d7dc" loginKeyExtra:@"edwardsdk" onresult:^(id ret, int code, NSString *msg) {
        NSLog(@"createUserKey: ret:%@, code = %d, msg = %@",ret,code,msg);
        //NSString *loginkey = @"2c3babed07cc0edafa30c8201457f2b6";
    }];
}
//登录
-(void) userLogin{
    [manager userLogin:@"2c3babed07cc0edafa30c8201457f2b6" andAppKey:@"25dd9e496f31064299a438621540bd95" onresult:^(id ret, int code, NSString *msg){
        if(code == 0){
            NSString *objectId = [ret objectForKey:@"objectId"];
            NSString *subId = [[ret objectForKey:@"sub"]objectForKey:@"objectId"];
            NSLog(@"self.objct ==== %@  subId ==== %@",objectId,subId);
            [manager initInterNetApi:objectId subid:subId success:^(id ret) {
                NSLog(@"success ret ==== %@",ret);
                [manager getRealSiRouters:ALL_ROUTER onresult:^(id ret, int code, NSString *msg) {
                    NSLog(@"app getSiRouters ret === %@,code === %d",ret,code);
                    if(code == 0){
                        NSArray *routerArray = ret;
                        if(routerArray.count != 0){
                            MyCurrentRouter = routerArray[0];
                            NSLog(@"currentRouter.name ====== %@",MyCurrentRouter.name);
                            NSLog(@"MyCurrentRouter subid ====== %@",MyCurrentRouter.sub);
                            [manager setCurrentRouter:MyCurrentRouter onresult:^(id ret, int code, NSString *msg) {
                                NSLog(@"checkwifi setCurrentRouter code === %d,msg ==== %@",code,msg);
                                [self CheckWiFiStatus];
                                
                            }];
                        }
                    }
                }];
                
            } error:^(int code, NSString *msg) {
                NSLog(@"error code ==== %d,msg === %@",code,msg);
            }];
        }else{
            NSLog(@"userLogin error code === %d,msg === %@",code,msg);
        }
        
    }];
}

//网络监听
-(void)registPUSH:(NSDictionary *)launchOptions{
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(myreachabilityChanged:) name:kReachabilityChangedNotification object:nil];
        hostReach = [Reachability reachabilityWithHostName:@"www.baidu.com"];
        [hostReach startNotifier];
    });
    
}


-(void)myreachabilityChanged:(NSNotification *)note{
    
    NSLog(@"连接改变");
    Reachability *curReach = [note object];
    NSParameterAssert([curReach isKindOfClass:[Reachability class]]);
    NetworkStatus status = [curReach currentReachabilityStatus];
    
    if(status == 0){
        NSLog(@"status == 0");
        manager.mInternetWorking = false;
        manager.mLocalnetWorking = false;
        manager.mAddRouterFlag = false;
    }else if(status == 1){
        manager.mInternetWorking = true;
        manager.mLocalnetWorking = false;
        NSLog(@"status == 1");
        if([SiWiFiManager isSiWiFi]){
            NSLog(@"app SiWiFiManager isSiWiFi ");
            [manager getBindInfo:^(id ret, int code, NSString *msg) {
                NSLog(@"appdelete getbindinfo ret ===== %@,code ==== %d",ret,code);
                NSLog(@"MyCurrentRouter.name ==== %@",MyCurrentRouter.name);
                BindInfo *info = ret;
                NSLog(@"info.bind ==== %d,info.mac ==== %@,MyCurrentRouter.mac == %@",info.bind,info.mac,MyCurrentRouter.mac);
                if (info.bind == 1 && [[info.mac uppercaseString] isEqualToString:MyCurrentRouter.mac])
                {
                    NSLog(@"9999999999");
                    manager.mLocalnetWorking = true;
                    
                }
                else if (info.bind == 0 && MyCurrentRouter == NULL)
                {
                    NSLog(@"ggggggggggg");
                    manager.mLocalnetWorking = true;
                }
                else
                {
                    NSLog(@"vvvvvvvvvvvvvv");
                    manager.mLocalnetWorking = false;
                }
            }];
            
            /*[manager getRealSiRouters:ALL_ROUTER onresult:^(id ret, int code, NSString *msg) {
                NSLog(@"Changed getSiRouters ret === %@,code === %d",ret,code);
                if(code == 0){
                    NSArray *routerArray = ret;
                    if(routerArray.count != 0){
                        MyCurrentRouter = routerArray[0];
                        NSLog(@"currentRouter.name ====== %@",MyCurrentRouter.name);
                        NSLog(@"MyCurrentRouter subid ====== %@",MyCurrentRouter.sub);
                        [manager setCurrentRouter:MyCurrentRouter onresult:^(id ret, int code, NSString *msg) {
                            NSLog(@"app setCurrentRouter code === %d,msg ==== %@",code,msg);
                            
                        }];
                    }
                }
            }];*/
        
        }else{
            NSLog(@"SiWiFiManager =======");
            manager.mInternetWorking = true;
            manager.mLocalnetWorking = false;
        }
    }else if(status == 2){
        NSLog(@"status === 2");
        manager.mInternetWorking = true;
        manager.mLocalnetWorking = false;
    }
}



- (void)setStatusBarBackgroundColor:(UIColor *)color {
    
    UIView *statusBar = [[[UIApplication sharedApplication] valueForKey:@"statusBarWindow"] valueForKey:@"statusBar"];
    if ([statusBar respondsToSelector:@selector(setBackgroundColor:)]) {
        statusBar.backgroundColor = color;
        //statusBar.alpha = 0.9;
    }
}


- (void)CheckWiFiStatus
{
    manager.mLocalnetWorking = false;
    if([SiWiFiManager connectedToNetwork]){
        manager.mInternetWorking = true;
        if([SiWiFiManager isSiWiFi]){
            
            [manager getBindInfo:^(id ret, int code, NSString *msg) {
                NSLog(@"CheckWiFiStatus getbindinfo ret ===== %@,code ==== %d",ret,code);
                
                BindInfo *info = ret;
                NSLog(@"MyCurrentRouter.name ==== %@,info.mac ==== %@,current.mac === %@",MyCurrentRouter.name,info.mac,MyCurrentRouter.mac);
                if (info.bind == 1 && [[info.mac uppercaseString] isEqualToString:MyCurrentRouter.mac])
                {
                    NSLog(@"kkkkk");
                    manager.mLocalnetWorking = true;
                }
                else if (info.bind == 0 && MyCurrentRouter == NULL)
                {
                    NSLog(@"jskajska");
                    manager.mLocalnetWorking = true;
                }
                else
                {
                    NSLog(@"bxnzbxnzbxnz");
                    manager.mLocalnetWorking = false;
                }
            }];

        }else{
            NSLog(@"555555");
            manager.mLocalnetWorking = false;
        }
    }else{
        NSLog(@"asasasasasa");
        manager.mInternetWorking = false;
    }
    
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    [self CheckWiFiStatus];
    if (self.backgroundTask != UIBackgroundTaskInvalid) {
        [self finishBackgroundTask];
    }
    NSLog(@"切换回前台");
   
}
-(void)finishBackgroundTask{
    NSLog(@"^^^^^^^ finishBackgroundTask ^^^^^^^^");
    [[UIApplication sharedApplication]endBackgroundTask:self.backgroundTask];
    self.backgroundTask = UIBackgroundTaskInvalid;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
