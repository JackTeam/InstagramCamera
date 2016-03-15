//
//  XHInstagramCamera.h
//  InstagramCamera
//
//  Created by 曾 宪华 on 14-2-26.
//  Copyright (c) 2014年 嗨，我是曾宪华(@xhzengAIB)，曾加入YY Inc.担任高级移动开发工程师，拍立秀App联合创始人，热衷于简洁、而富有理性的事物 QQ:543413507 主页:http://zengxianhua.com All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@protocol XHInstagramCameraDelegate <NSObject>

@optional
// Focus
- (void)cameraView:(UIView *)camera focusAtPoint:(CGPoint)point;
- (void)cameraView:(UIView *)camera exposeAtPoint:(CGPoint)point;

// Photo
- (void)cameraViewCapturePhoto;

// Video

// Camera
- (void)closeCamera;
- (void)switchCamera;

// Focus Mode

// Flash Mode
- (void)triggerFlashForMode:(AVCaptureFlashMode)flashMode;

// Grid View
- (void)cameraView:(UIView *)camera showGridView:(BOOL)show;

// Scale
- (CGFloat)cameraMaxScale;
- (void)cameraCaptureScale:(CGFloat)scaleNum;


@end

@interface XHInstagramCamera : UIView

@end
