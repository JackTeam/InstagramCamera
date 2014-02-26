//
//  XHInstagramCameraManager.h
//  InstagramCamera
//
//  Created by 曾 宪华 on 14-2-26.
//  Copyright (c) 2014年 HUAJIE QQ群: (142557668) QQ:543413507  Gmail:xhzengAIB@gmail.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

typedef NS_ENUM(NSInteger, XHFlashMode) {
    XHFlashModeOff  = AVCaptureFlashModeOff,
    XHFlashModeOn   = AVCaptureFlashModeOn,
    XHFlashModeAuto = AVCaptureFlashModeAuto,
    XHFlashModeLight
};

typedef NS_ENUM(NSInteger, XHTorchMode) {
    XHTorchModeOff  = AVCaptureTorchModeOff,
    XHTorchModeOn   = AVCaptureTorchModeOn,
    XHTorchModeAuto = AVCaptureTorchModeAuto,
};

typedef NS_ENUM(NSInteger, XHExposureMode) {
    XHExposureModeLocked  = AVCaptureExposureModeLocked,
    XHExposureModeAutoExpose   = AVCaptureExposureModeAutoExpose,
    XHExposureModeContinuousAutoExposure = AVCaptureExposureModeContinuousAutoExposure,
};

typedef NS_ENUM(NSInteger, XHWhiteBalanceMode) {
    XHWhiteBalanceModeLocked  = AVCaptureWhiteBalanceModeLocked,
    XHWhiteBalanceModeAutoWhiteBalance   = AVCaptureWhiteBalanceModeAutoWhiteBalance,
    XHWhiteBalanceModeContinuousAutoWhiteBalance = AVCaptureWhiteBalanceModeContinuousAutoWhiteBalance,
};

typedef NS_ENUM(NSInteger, XHCameraDevice) {
    XHCameraDeviceBack = AVCaptureDevicePositionBack,
    XHCameraDeviceFront = AVCaptureDevicePositionFront
};

typedef NS_ENUM(NSInteger, XHCameraFocusMode) {
    XHCameraFocusModeLocked = AVCaptureFocusModeLocked,
    XHCameraFocusModeAutoFocus = AVCaptureFocusModeAutoFocus,
    XHCameraFocusModeContinuousAutoFocus = AVCaptureFocusModeContinuousAutoFocus
};

@protocol XHInstagramCameraManagerDelegate <NSObject>

@optional
// Photo
- (void)capturePhotoDidFinish:(UIImage *)photo withMetadata:(NSDictionary *)metadata;
- (void)capturePhotoFailedWithError:(NSError *)error;

// Video
- (void)videoRecordDidFinish:(NSURL *)videoRecorderUrl didRecordVideoFrame:(CMTime)frameTime;
- (void)videoRecordFailedWithError:(NSError *)error;

// Error
- (void)someOtherError:(NSError *)error;
- (void)acquiringDeviceLockFailedWithError:(NSError *)error;

// Session
- (void)captureSessionDidStartRunning;
- (void)cameraSessionDidStop;

@end

@interface XHInstagramCameraManager : NSObject

@property (nonatomic, weak) id <XHInstagramCameraManagerDelegate> delegate;
@property (nonatomic, readonly, strong) AVCaptureSession *captureSession;
@property (nonatomic, readonly, strong) AVCaptureDeviceInput *videoInput;
@property (nonatomic, assign) XHFlashMode flashMode;
@property (nonatomic, assign) XHTorchMode torchMode;
@property (nonatomic, assign) XHCameraFocusMode focusMode;
@property (nonatomic, assign) XHExposureMode exposureMode;
@property (nonatomic, assign) XHWhiteBalanceMode whiteBalanceMode;
@property (nonatomic, assign, readonly) NSUInteger cameraCount;

// Camera Infomation
- (CGFloat)cameraMaxScale;
- (BOOL)cameraToggle;
- (BOOL)hasMultipleCameras;
- (BOOL)hasFlash;
- (BOOL)hasTorch;
- (BOOL)hasFocus;
- (BOOL)hasExposure;
- (BOOL)hasWhiteBalance;
- (BOOL)isRecording;

- (BOOL)setupSessionWithPreset:(NSString *)sessionPreset error:(NSError **)error;

- (void)startRunning;
- (void)stopRunning;

// Photo
- (void)capturePhotoForDeviceOrientation:(UIDeviceOrientation)deviceOrientation;

// Video
- (void)recordVideo;
- (void)pauseVideo;
- (void)cancelVideo;

// Focus
- (void)focusAtPoint:(CGPoint)point;
- (void)exposureAtPoint:(CGPoint)point;
- (CGPoint)convertToPointOfInterestFrom:(CGRect)frame coordinates:(CGPoint)viewCoordinates layer:(AVCaptureVideoPreviewLayer *)layer;

// VideoScaleAndCropFactor
- (void)setCameraMaxScale:(CGFloat)maxScale;

@end
