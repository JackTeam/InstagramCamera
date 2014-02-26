//
//  XHInstagramCamera.h
//  InstagramCamera
//
//  Created by 曾 宪华 on 14-2-26.
//  Copyright (c) 2014年 HUAJIE QQ群: (142557668) QQ:543413507  Gmail:xhzengAIB@gmail.com. All rights reserved.
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
