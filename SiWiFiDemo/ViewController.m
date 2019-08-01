//
//  ViewController.m
//  SiWiFiDemo
//
//  Created by edward on 2018/12/27.
//  Copyright © 2018年 siflower. All rights reserved.
//

#import "ViewController.h"
#import "AppDelegate.h"
#import "wifiSettingController.h"
#import <AFNetworking.h>
#import <SiRouterApi/SiWiFiManager.h>

extern SiWiFiManager *manager;
extern SiRouter *MyCurrentRouter;

@interface ViewController ()
@property (nonatomic,strong) UITextField *nametext;
@property (nonatomic,strong) UITextField *pswname;
@property (nonatomic,strong) BindInfo *Binfo;
@property (nonatomic,strong) UILabel *label;
@property (nonatomic,strong) UILabel *tipLab;
@property (nonatomic,strong) UILabel *wifiNameLab;
@property (nonatomic,strong) UILabel *promptLab;
@property (nonatomic,strong) NSArray *routerArray;


@end

@implementation ViewController
@synthesize label;
- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    [self performSelector:@selector(delayClick) withObject:nil afterDelay:3];
    self.navigationItem.backBarButtonItem = [[UIBarButtonItem alloc]initWithTitle:@"" style:UIBarButtonItemStylePlain target:self action:nil];  
}

- (void)viewDidLoad {
    [super viewDidLoad];
    label = [[UILabel alloc]init];
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.navigationController.navigationBar.backgroundColor = [UIColor colorWithRed:64/255.0 green:180/255.0 blue:255/255.0 alpha:1.0];
    self.navigationItem.title = @"主菜单";
    self.navigationController.navigationBar.titleTextAttributes=
  @{NSForegroundColorAttributeName:[UIColor whiteColor],
    NSFontAttributeName:[UIFont systemFontOfSize:20]};
    
    self.promptLab = [[UILabel alloc]initWithFrame:CGRectMake(20, 80, self.view.frame.size.width-60, 30)];
    [self.view addSubview:self.promptLab];
   
    UIButton *btn = [[UIButton alloc]initWithFrame:CGRectMake(80, 280, self.view.frame.size.width-160, 30)];
    [btn setTitle:@"绑定路由" forState:UIControlStateNormal];
    btn.layer.cornerRadius = 8;
    btn.backgroundColor = [UIColor colorWithRed:64/255.0 green:180/255.0 blue:255/255.0 alpha:1.0];
    [self.view addSubview:btn];
    [btn addTarget:self action:@selector(checkSiWiFi) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton *wifiBtn = [[UIButton alloc]initWithFrame:CGRectMake(80, 360, self.view.frame.size.width-160, 30)];
    [wifiBtn setTitle:@"wifi 设置" forState:UIControlStateNormal];
    wifiBtn.layer.cornerRadius = 8;
    wifiBtn.backgroundColor = [UIColor colorWithRed:64/255.0 green:180/255.0 blue:255/255.0 alpha:1.0];
    [self.view addSubview:wifiBtn];
    [wifiBtn addTarget:self action:@selector(wifiClick) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton *unbindBtn = [[UIButton alloc]initWithFrame:CGRectMake(80, 440, self.view.frame.size.width-160, 30)];
    [unbindBtn setTitle:@"解绑路由" forState:UIControlStateNormal];
    unbindBtn.layer.cornerRadius = 8;
    unbindBtn.backgroundColor = [UIColor colorWithRed:64/255.0 green:180/255.0 blue:255/255.0 alpha:1.0];
    [self.view addSubview:unbindBtn];
    [unbindBtn addTarget:self action:@selector(unbindClick) forControlEvents:UIControlEventTouchUpInside];
    
    self.tipLab = [[UILabel alloc]initWithFrame:CGRectMake(80, 160, self.view.frame.size.width-160, 80)];
    self.tipLab.numberOfLines = 0;
    
    self.tipLab.textAlignment = NSTextAlignmentCenter;
    //[self.view addSubview:self.tipLab];
    
    self.wifiNameLab = [[UILabel alloc]initWithFrame:CGRectMake(90, 120, self.view.frame.size.width-180, 40)];
    self.wifiNameLab.textAlignment = NSTextAlignmentCenter;
    
}

-(void)delayClick{
    if(!MyCurrentRouter.name){
        self.promptLab.text = @"当前账户未绑定路由";
    }else{
        NSLog(@"MyCurrentRouter ==== %@",MyCurrentRouter.name);
        self.promptLab.text = [NSString stringWithFormat:@"当前绑定路由为： %@",MyCurrentRouter.name];
        [self.view addSubview:self.tipLab];
    }
}

-(void)reachbility{
    
}

-(void)wifiClick{
    NSLog(@"wifiClick =========");
    [manager getSiRouters:ALL_ROUTER onresult:^(id ret, int code, NSString *msg) {
        NSArray *routerArray = ret;
        if(routerArray.count == 0){
            [self labelAnimate:@"路由器尚未绑定,请先绑定路由器再进行wifi 设置"];
            return ;
        }else{
            [self.navigationController pushViewController:[wifiSettingController new] animated:YES];
        }
    }];
    
}

-(void)unbindClick{
    [manager unbindSiRouter:^(id ret, int code, NSString *msg) {
        NSLog(@"unbindSiRouter ret ==== %@,code == %d",ret,code);
        manager.mLocalnetWorking = 0;
        if(code == 0){
            [self labelAnimate:@"解绑成功"];
            [manager getSiRouters:ALL_ROUTER onresult:^(id ret, int code, NSString *msg) {
                self.routerArray = ret;
                NSLog(@"routerArray ret ===== %@",self.routerArray);
                NSArray *RouterArray = [self.routerArray mutableCopy];
                if(RouterArray.count){
                    SiRouter *newRouter = RouterArray[0];
                    NSLog(@"newRouter.name ===== %@,newRouter.mac ===== %@ ",newRouter.name,newRouter.mac);
                    self.promptLab.text = [NSString stringWithFormat:@"当前绑定路由为： %@",newRouter.name];
                    [manager setCurrentRouter:newRouter onresult:^(id ret, int code, NSString *msg) {
                        MyCurrentRouter = newRouter;
                        AppDelegate *app = (AppDelegate*)[UIApplication sharedApplication].delegate;
                        [app CheckWiFiStatus];
                        NSLog(@"setCurrentRouter ret ==== %@,code ==== %d",ret,code);
                    }];
                    
                }else{
                    MyCurrentRouter = nil;
                    manager.mLocalnetWorking = 0;
                    self.promptLab.text = @"当前账户未绑定路由";
                }
            }];
        }else if(code == 1016){
            [self labelAnimate:@"路由器尚未绑定"];
        }else{
            [self labelAnimate:@"解绑失败"];
        }
    }];
}


-(void)checkSiWiFi
{
    if ([SiWiFiManager isSiWiFi]) {
        NSLog(@"SiWiFiManager isSiWiFi");
        [manager getClientMac:^(id ret, int code, NSString *msg) {
            NSLog(@"getClientMac  ret == %@,code == %d",ret,code);
            if(code == 0){
                GetClientMacRet *client = (GetClientMacRet *)ret;
                if(![client.wlan containsString:@"lease"]){
                    [manager getBindInfo:^(id ret, int code, NSString *msg) {
                        self.Binfo = ret;
                       [self getBindInformation];
                        NSLog(@"getBindInfo ret == %@,code == %d",ret,code);
                    }];
                }
            }
        }];
    }else{
        [self labelAnimate:@"当前路由器不是矽路由,是否切换为矽路由进行设置"];
        return ;
    }
}
-(void)getBindInformation{
    
    if(self.Binfo.bind == 0){
        NSLog(@"getBindInformation bind === 0");
        manager.mAddRouterFlag = true;
        self.tipLab.text = @"发现1台矽路由，是否绑定它";
        self.wifiNameLab.text = [SiWiFiManager getConnectWifiName];
        NSLog(@"wifiNameLab.text ====== %@",self.wifiNameLab.text);
        self.wifiNameLab.textColor = [UIColor redColor];
        [self.view addSubview:self.wifiNameLab];
        [self.view addSubview:self.tipLab];
        
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:self.wifiNameLab.text message:nil preferredStyle:UIAlertControllerStyleAlert];
        
        //可以给alertview中添加一个输入框
        [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.placeholder = @"请输入管理员密码";
            textField.font = [UIFont systemFontOfSize:17];
        }];
        
        UIAlertAction *action1 = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            NSLog(@"点击了按钮1，进入按钮1的事件");
            //textFields是一个数组，获取所输入的字符串
            NSLog(@"%@",alert.textFields.lastObject.text);
            [manager checkAdminPassword:alert.textFields.lastObject.text flag:false onresult:^(id ret, int code, NSString *msg) {
                NSLog(@"checkAdminPassword  ret === %@,code === %d msg === %@",ret,code,msg);
                if(code == 0){
                    if(!manager.mLocalnetWorking){
                        manager.mLocalnetWorking = true;
                    }
                    if([SiWiFiManager checkNetworkCanUse:kAppleUrlTocheckWifi]){
                        NSLog(@"manager.interapi ====== %@",manager.mInternetapi);
                        [self bindRouter];
                    }else{
                        [self labelAnimate:@"当前网络不可用，请检查网络"];
                        return ;
                    }
                }else{
                    [self labelAnimate:@"管理员密码输入错误，请重新输入"];
                    return ;
                }
            }];
        }];
        UIAlertAction *action2 = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
            NSLog(@"点击了取消");
        }];
        
        [alert addAction:action2];
        [alert addAction:action1];
        
        [self presentViewController:alert animated:YES completion:nil];
    }else{
        NSLog(@"getBindInformation bind === 1");
        self.wifiNameLab.text = [SiWiFiManager getConnectWifiName];
        NSLog(@"wifiNameLab.text ====== %@",self.wifiNameLab.text);
        self.wifiNameLab.textColor = [UIColor redColor];
        [self.view addSubview:self.wifiNameLab];
        [self.view addSubview:self.tipLab];
        
        [self labelAnimate:@"当前路由器已被绑定"];
        return ;
    }
    
}

-(void)bindRouter{
    NSLog(@"bindRouter ========");
    [manager bindSiRouter:^(id ret, int code, NSString *msg) {
        NSLog(@"bindSiRouter  ret === %@,code == %d",ret,code);
        if(code == 0){
            [self labelAnimate:@"绑定成功"];
            [manager getRealSiRouters:ALL_ROUTER onresult:^(id ret, int code, NSString *msg) {
                NSArray *routerArray = ret;
                NSArray *RouterArray = [routerArray mutableCopy];
                NSLog(@"bind getRealSiRouters RouterArray ==== %@",RouterArray);
                SiRouter *newRouter = RouterArray[0];
                NSLog(@"newRouter.name ===== %@,newRouter.mac ===== %@",newRouter.name,newRouter.mac);
               
                for (SiRouter *router in routerArray) {
                    if (self.Binfo.routerid != nil) {
                        if ([router.routerid isEqualToString:self.Binfo.routerid]) {
                            NSLog(@"找到相同的");
                            newRouter = router;
                        }
                    }
                }
                self.promptLab.text = [NSString stringWithFormat:@"当前绑定路由为： %@",newRouter.name];
                [manager setCurrentRouter:newRouter onresult:^(id ret, int code, NSString *msg) {
                    MyCurrentRouter = newRouter;
                    NSLog(@"MyCurrentRouter subid ====== %@",MyCurrentRouter.sub);
                    NSLog(@"setCurrentRouter ret ==== %@,code ==== %d",ret,code);
                }];
            }];
            
            [self.navigationController pushViewController:[wifiSettingController new] animated:YES];
        }else{
            [self labelAnimate:@"绑定失败"];
        }
    }];
}


-(void)labelAnimate:(NSString *)title
{
    dispatch_async(dispatch_get_main_queue(), ^{
        label.text = title;
        [label sizeToFit];
        label.frame = CGRectMake(label.frame.origin.x, label.frame.origin.y, label.frame.size.width+20, label.frame.size.height + 20);
        [self.view addSubview:label];
        label.center = self.view.center;
        [UIView animateWithDuration:1.0 animations:^{
            label.alpha = 1;
        } completion:^(BOOL finished) {
            [UIView animateWithDuration:0.5 delay:1 options:UIViewAnimationOptionCurveLinear animations:^{
                label.alpha = 0.0;
            } completion:^(BOOL finished) {
                //[label removeFromSuperview];
            }];
        }];
    });
}
@end
