//
//  wifiSettingController.m
//  SiWiFiDemo
//
//  Created by siflower on 2019/6/18.
//  Copyright © 2019 siflower. All rights reserved.
//

#import "wifiSettingController.h"
#import <SiRouterApi/SiWiFiManager.h>

extern SiRouter *MyCurrentRouter;
extern SiWiFiManager *manager;
@interface wifiSettingController () <UITableViewDelegate,UITableViewDataSource >
@property(strong,nonatomic)UITableView *tableview;
@property(strong,nonatomic)UITextField *nameText;
@property(strong,nonatomic)UITextField *pswText;
@property (nonatomic,strong) SiWiFiInfo *para5;
@property (nonatomic,strong) UILabel *label;
@end

@implementation wifiSettingController

@synthesize label;

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    self.navigationItem.title = @"WiFi 设置";
    self.navigationItem.backBarButtonItem = [[UIBarButtonItem alloc]initWithTitle:@"" style:UIBarButtonItemStylePlain target:self action:nil];
}

-(void)viewDidLoad{
    [super viewDidLoad];
    
    label = [UILabel new];
    
    _tableview = [[UITableView alloc]initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
    _tableview.delegate = self;
    _tableview.dataSource = self;
    [self.view addSubview:_tableview];
    
    UIImageView *imaView = [[UIImageView alloc]initWithFrame:CGRectMake(0, 10, self.view.frame.size.width, 40)];
    self.tableview.tableFooterView = imaView;
    imaView.userInteractionEnabled = YES;
    UIButton *btn = [[UIButton alloc]initWithFrame:CGRectMake(80, 10, self.view.frame.size.width - 160, 40)];
    btn.layer.cornerRadius = 8;
    btn.userInteractionEnabled = YES;
    btn.backgroundColor = [UIColor colorWithRed:64/255.0 green:180/255.0 blue:255/255.0 alpha:1.0];
    [btn setTitle:@"保存" forState:UIControlStateNormal];
    [imaView addSubview:btn];
    [btn addTarget:self action:@selector(setWifiInfo) forControlEvents:UIControlEventTouchUpInside];
    
    
    [self getWifiInfo];
    NSString *currentName = [SiWiFiManager getConnectWifiName];
    NSLog(@"getConnectWifiName currentname ===== %@",currentName);
}


-(void)getWifiInfo{
    NSLog(@"getRouterWifi mycurrentname ====== %@",MyCurrentRouter.name);
    [manager getRouterWifi:^(id ret, int code, NSString *msg) {
        NSLog(@"getRouterWifi ret == %@,code == %d,msg == %@",ret,code,msg);
        if(code == 0){
            if (!code && ((NSMutableArray*)ret).count) {
                for (SiWiFiInfo *wifiInfo in ret) {
                    if ([wifiInfo.band isEqualToString:@"5G"] && ![wifiInfo.ifname containsString:@"guest"] && [wifiInfo.ifname containsString:@"wlan"]) {
                        self.para5 = wifiInfo;
                        
                    }
                }
                [self performSelectorOnMainThread:@selector(update_wifi_data) withObject:nil waitUntilDone:NO];
            }
        }else{
            NSLog(@"getRouterWifi error");
        }
    }];
}

-(void)update_wifi_data{
    [self.tableview reloadData];
}

-(void)setWifiInfo{
    NSLog(@"setWifiInfo======");
    SiWiFiSetParams *wifi5 = [[SiWiFiSetParams alloc]init];
    NSString *str5 = [[[_para5.encryption stringByReplacingOccurrencesOfString:@"+ccmp" withString:@""] stringByReplacingOccurrencesOfString:@"%2Bccmp" withString:@""] stringByReplacingOccurrencesOfString:@" ccmp" withString:@""];
    wifi5.password = self.pswText.text;
    wifi5.ssidold = self.para5.ssid;//
    wifi5.ssidnew = self.nameText.text;
    wifi5.encryption = [NSString stringWithFormat:@"%@%%2Bccmp",str5];
    wifi5.enable = self.para5.enable;
    wifi5.channel = self.para5.channel;
    wifi5.signalmode = self.para5.signal;
    NSMutableArray *setArray = [NSMutableArray array];
    [setArray addObject:wifi5];
    [manager setRouterWifi:setArray onresult:^(id ret, int code, NSString *msg) {
        NSLog(@"setRouterWifi ret == %@ ,code == %d,msg == %@",ret,code,msg);
        if(code == 0){
            NSLog(@"set success");
            [self labelAnimate:@"设置成功"];
        }else{
            [self labelAnimate:@"设置失败"];
        }
    }];
}

-(CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section{
    return 60;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return 2;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 50;
}


-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:nil];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    if(indexPath.row == 0){
        cell.textLabel.text = @"名称";
        self.nameText = [[UITextField alloc]initWithFrame:CGRectMake(90, 0, 123, 50)];
        self.nameText.placeholder = @"wifi 名称";
        self.nameText.text = self.para5.ssid;
        [cell addSubview:self.nameText];
    }else{
        cell.textLabel.text = @"密码";
        self.pswText = [[UITextField alloc]initWithFrame:CGRectMake(90, 0, 123, 50)];
        self.pswText.placeholder = @"wifi 密码";
        self.pswText.text = self.para5.password;
        [cell addSubview:self.pswText];
    }
    
    return cell;
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
