#ifndef C_Camera_H
#define C_Camera_H

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <pthread.h>

#define FRONT 1
#define BOTTOM 2

class C_Camera
{
private:
    int m_type ; // type de la caméra (FRONT ou BOTTOM)
    cv::VideoCapture m_cap;
    cv::Mat m_frame;
    int m_deviceID ;
    int m_apiID ;
    char m_name[256] ;
    int m_frame_width ;
    int m_frame_height ;
    bool m_ShowImage ;
    bool m_ReccodImage ;     // pour savoir si on enregistre ou non la vidéo
    bool m_IsRunning ;
    void ImageProcessing() ;


public:
    C_Camera();
    ~C_Camera();
    pthread_t m_CameraThread;
    pthread_mutex_t m_CameraMutex ;

    int Setup( int i_channel , int i_type , char * i_name ) ;

    int Run() ;
    void ToggleRecording () ;
    bool IsRecording() ;
    void ToggleShowing () ;
    bool IsShowing() ;
} ;
#endif /* C_PortSerie_H */
