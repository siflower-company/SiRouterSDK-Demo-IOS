//
//  XCloudEvent.h
//  SiWiFi
//
//  Created by Edward on 16/11/29.
//  Copyright © 2016年 Siflower. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XCloudConfig.h"
//#import "SRWebSocket.h"


#define XCLOUD_WEBSOCKET_URL @"https://cloud.siflower.cn:9090/v1/websocket"
#define XCLOUD_WEBSOCKET_NEW_URL @"https://cloud.siflower.cn/v3/websocketNew"
//#define XCLOUD_WEBSOCKET_NEW_URL @"https://k8s.siflower.cn/v3/websocketNew"
//#define XCLOUD_WEBSOCKET_URL @"https://139.196.176.186:8090/websocket"
//#define XCLOUD_WEBSOCKET_URL @"https://120.76.161.56:8090/websocket"
//#define XCLOUD_WEBSOCKET_URL @"https://192.168.1.12:8090/websocket"

@class SRWebSocket;
@protocol XCloudSocketDelegate <NSObject>

-(void)webSocketDidOpen:(SRWebSocket *)webSocket;
-(void)webSocket:(SRWebSocket *)webSocket didFailWithError:(NSError *)error;
-(void)webSocket:(SRWebSocket *)webSocket didReceiveMessage:(id)message;
-(void)webSocket:(SRWebSocket *)webSocket didCloseWithCode:(NSInteger)code reason:(NSString *)reason wasClean:(BOOL)wasClean;
-(void)webSocket:(SRWebSocket *)webSocket didReceivePong:(NSData *)pongPayload;

@end

@interface XCloudEvent : NSObject

@property (nonatomic, weak) id<XCloudSocketDelegate> delegate;

- (void)connect;
- (void)disconnect;
-(void)sendData:(NSData *)data;
-(void)sendPing:(NSData *)data;

//- (BOOL)isConnected;
//- (void)readDataWithTimeout:(NSTimeInterval)timeout tag:(long)tag;
//- (void)writeData:(NSData *)data timeout:(NSTimeInterval)timeout tag:(long)tag;


@end

/*
@protocol XCloudSocketDelegate <NSObject>

-(void)didDisconnectWithError:(NSError *)error;
-(void)didConnectToHost:(NSString *)host port:(UInt16)prot;
-(void)didReceiveData:(NSData *)data tag:(long)tag;

@end



@interface XCloudEvent : NSObject

@property (nonatomic, weak) id<XCloudSocketDelegate> delegate;

- (void)connectWithHost;
- (void)disconnect;

- (BOOL)isConnected;
- (void)readDataWithTimeout:(NSTimeInterval)timeout tag:(long)tag;
- (void)writeData:(NSData *)data timeout:(NSTimeInterval)timeout tag:(long)tag;


@end
*/




