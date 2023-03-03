#ifndef C_Camera_H
#define C_Camera_H

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <pthread.h>

class C_Camera
{
private:
    cv::VideoCapture cap;
    cv::Mat frame;
    int deviceID ;
    int apiID ;
    int frame_width ;
    int frame_height ;
    bool ShowImage ;
    bool ReccodImage ;     // pour savoir si on enregistre ou non la vidéo
    void ImageProcessing() ;

public:
    C_Camera();
    ~C_Camera();
    pthread_t m_CameraThread;
    pthread_mutex_t m_CameraMutex ;
    bool IsRunning ;
    int Run() ;
    void ToggleRecording () ;
    bool IsRecording() ;
    void ToggleShowing () ;
    bool IsShowing() ;
} ;
#endif /* C_PortSerie_H */
