Skip to content
Product
Solutions
Open Source
Pricing
Search
Sign in
Sign up
FsPilots
/
PITA-Droneload-3A
Public
Code
Issues
Pull requests
Actions
Projects
Security
Insights
PITA-Droneload-3A/ProjetDroneload/SRC/Camera.h
@FsPilots
FsPilots Update windows detection projet CBlock
Latest commit e5e7e08 3 days ago
 History
 2 contributors
@GabiGabiGabiGabi@FsPilots
132 lines (94 sloc)  3.3 KB
 

#ifndef C_Camera_H
#define C_Camera_H

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <pthread.h>

#include <opencv2/opencv.hpp>


#include "wxImagePanel.h"





#define FRONT 1
#define BOTTOM 2

class C_Camera
{
    private:
        int m_type ; // type de la caméra (FRONT ou BOTTOM)
        cv::VideoCapture m_cap;
        cv::Mat m_frame;
        cv::Mat m_frame2;
        int m_deviceID ;
        int m_apiID ;
        char m_name[256] ;
        int m_frame_width ;
        int m_frame_height ;
        bool m_ShowImage ;
        bool m_ReccodImage ;     // pour savoir si on enregistre ou non la vidéo
        bool m_IsRunning ;
        void ImageProcessing_WindowsDetection() ;
        void ImageProcessing_PointLaserDetection() ;

public :
        int m_GreyLevelThreshold ;
        int m_OpenKernelSize ;
        int m_TopHatKernelSize ;
        int m_MaxRayon ;
        int m_MinArea ;
        int m_MoyenneMin ;
        int m_SigmaMax ;
        int m_SymetryCondition ;
        int m_HorizCondition ;
        int m_ProxyCondition ;

private :
        bool m_2LazerFounded;
        cv::Point m_Center1;
        cv::Point m_Center2;
        int m_MaxDistance;

        void XYStabilizeProcessing_harris() ;
        //void XYStabilizeProcessing_TVL() ;

        wxImagePanel *m_imagepanel;

        bool ShowImage();
        double m_Altitude ;
        int m_TimeAltitude ;


        //données concernant les fenetres
        double m_Center_x ;
        double m_Center_y ;
        double  m_error_x;
        double m_error_y;
        int m_CameraActivity ;
        int accroche;
        int indice_non_accrochage;//Valeur assigné à une variable ACCROCHE_ERROR qu'on doit pouvoir changer via l'interface graphique


            // Définition des constantes script reconnaissance des fenetres
    int resolution_x ;
    int resolution_y ;
    int size_error ;
    int size_accroche_error;
    int accroche_error ;

    public:
        C_Camera();
        ~C_Camera();
        pthread_t m_CameraThread;
        pthread_mutex_t m_CameraMutex ;

        int Setup ( int i_channel, int i_type, char * i_name ) ;

        int Run() ;
        void ToggleRecording () ;
        bool IsRecording() ;
        void ToggleShowing () ;
        bool IsShowing() ;

        void ImageProcessing_QRCodeDetection() ;

        void SetRenderPanel ( wxImagePanel* i_imagepanel ) {m_imagepanel = i_imagepanel;};
        void SetCameraActivity ( int i_CameraActivity ) {m_CameraActivity = i_CameraActivity;};

        double GetAltitude() { return m_Altitude ; } ;
        double GetTimeAltitude() { return m_TimeAltitude ; } ;
        double GetCameraActivity() { return m_CameraActivity ; } ;


        double GetCenter_x() { return  m_Center_x ; } ;
        double GetCenter_y() { return  m_Center_y ; } ;
        void SetCenter_x ( double i_Center_x ) {m_Center_x = i_Center_x;};
        void SetCenter_y ( double i_Center_y ) {m_Center_y = i_Center_y;};



        void Correction_Distortions_Camera_Frontale ();



        int Geterrorx(){return m_error_x;};
        int Geterrory(){return m_error_y;};


double GetImageCenter_x(){return (double) m_frame.cols/2.;};
double GetImageCenter_y(){return (double) m_frame.rows/2.;};



} ;
#endif /* C_PortSerie_H */
Footer
© 2023 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
PITA-Droneload-3A/ProjetDroneload/SRC/Camera.h at main · FsPilots/PITA-Droneload-3A · GitHub