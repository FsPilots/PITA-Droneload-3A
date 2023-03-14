/**
  @file videocapture_basic.cpp
  @brief A very basic sample for using VideoCapture and VideoWriter
  @author PkLab.net
  @date Aug 24, 2016
*/
#include "Camera.h"
#include "Radio.h"
#include <iostream>
#include <opencv2/opencv.hpp>

extern C_Radio MyRadio ;

using namespace cv;
using namespace std;

C_Camera::C_Camera()
{
    m_deviceID = 0;             // 0 = open default camera
    m_apiID = cv::CAP_ANY;      // 0 = autodetect default API
    m_IsRunning = false ;
    m_ShowImage = true ;
    m_ReccodImage = false ;
}

C_Camera::~C_Camera()
{
};

int C_Camera::Setup( int i_channel , int i_type, char * i_name )
{
    m_deviceID = i_channel ;
    m_type = i_type ;
    strcpy(m_name, i_name ) ;

    // open selected camera using selected API
    m_cap.open ( m_deviceID, m_apiID );

    // check if we succeeded
    if ( !m_cap.isOpened() )
    {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }

    m_frame_width = m_cap.get ( cv::CAP_PROP_FRAME_WIDTH );
    m_frame_height = m_cap.get ( cv::CAP_PROP_FRAME_HEIGHT );

    return 0 ;
}

int C_Camera::Run()
{
    namedWindow(m_name,WINDOW_NORMAL) ;
    m_IsRunning =true ;

    // Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file.
    char VideoFileName[256] ;
    sprintf(VideoFileName,"%s.avi",m_name);
    VideoWriter video ( VideoFileName , cv::VideoWriter::fourcc ( 'M', 'J', 'P', 'G' ), 25, Size ( m_frame_width, m_frame_height ) );

    for ( ;; )
    {
        // wait for a new frame from camera and store it into 'frame'
        m_cap.read ( m_frame );

        // check if we succeeded
        if ( m_frame.empty() )
        {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }

        // Traitement image
        if (m_type == FRONT) ImageProcessing() ;

        // Write the frame into the file 'outcpp.avi'
        if (m_ReccodImage) video.write ( m_frame );

        // incruts help
        putText(m_frame, "Exit : ESC   -   Record : r   -   Stop recording : s", Point(10,m_frame_height-12), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(255,255,255),1);
        if (m_ReccodImage) circle(m_frame,Point(m_frame_width-20,m_frame_height-15),12,Scalar(0,0,255),FILLED);

        // show live and wait for a key with timeout long enough to show images
        if (m_ShowImage)
        {
            imshow ( m_name, m_frame );
        }
        else
        {
        }

        // manage cmd
        int key =  waitKey ( 5 ) ;
        if (key == 27 ) m_ShowImage = false; // esc : exit image viewer
        if (key == 114) m_ReccodImage  = true ; // r start recording
        if (key == 115) m_ReccodImage = false ; // s stop recording

    }

    // When everything done, release the video capture and write object
    m_cap.release();
    video.release();

    // Closes all the frames
    destroyWindow( m_name );
    m_IsRunning =false ;

    return ( 0 ) ;
}

void C_Camera::ToggleRecording ()
{
    if ( m_ReccodImage )
    {
        m_ReccodImage = false ;
    }
    else
    {
        m_ReccodImage = true ;
    }
} ;

bool C_Camera::IsRecording()
{
    return m_ReccodImage ;
} ;

void C_Camera::ToggleShowing ()
{
    if ( m_ShowImage )
    {
        m_ShowImage = false ;
    }
    else
    {
        m_ShowImage = true ;
    }
} ;

bool C_Camera::IsShowing()
{
    return m_ShowImage ;
} ;

void C_Camera::ImageProcessing()
{
    // Convert the image to grayscale
    Mat gray ;
    cvtColor(m_frame, gray, COLOR_BGR2GRAY) ;

    // Apply Gaussian blur to the image
    Mat blurred ;
    int ksize = 25 ; // intensifie le flou et permet de reduire le bruit de l'image thresholded
    GaussianBlur(gray,blurred,Size(ksize, ksize), 0) ;

    // Create an adaptive binary thresholded image
    Mat adaptthresh ;
    int  blocksize = 15 ; // permet de reduire la sensibilité du threshold pour garder uniquement les contours les plus importants
    adaptiveThreshold(blurred,adaptthresh, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blocksize, 2) ;

    // Find contours in the thresholded image
    std::vector < std::vector <cv::Point> > contours ;
    findContours(adaptthresh, contours, RETR_LIST, CHAIN_APPROX_SIMPLE) ;

    // Iterate over the contours and draw a rectangle around any contour that is a rectangle
    for (size_t  i = 0; i < contours.size(); i ++)
    {
        Rect boundbox = boundingRect( contours[ i ] ) ;
        int x = boundbox.x ;
        int y = boundbox.y ;
        int w = boundbox.width ;
        int h = boundbox.height ;

        double aspectRatio = ( (float) w ) / ( (float) h );
        int center_x = x + w/2 ;
        int center_y = y + h/2 ;

        // Check if the aspect ratio of the contour is close to 1, indicating it is a scare
        if ( ( 0.95 <= aspectRatio ) && ( aspectRatio <= 1.05 ))
        {
            if ( h > 50 )
            {
                rectangle(m_frame, Point(x, y), Point(x + w, y + h), Scalar(0,0,0), 2) ;
                circle(m_frame, Point(center_x, center_y), 5, Scalar(0, 0, 255), -1) ;
                char tmp_str[ 50 ] ;
                sprintf(tmp_str,"x: %d y: %d",center_x, center_y) ;
                putText(m_frame, tmp_str, Point(center_x+10, center_y-10), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(300, 0, 255), 2, LINE_AA) ;
             }
        }
    }

    char tmp_str[50];
    int Level_T = MyRadio.GetLevelT();
    sprintf(tmp_str,"Throttle   %d",Level_T);
    putText(m_frame,tmp_str,Point(+20,+30),FONT_HERSHEY_SIMPLEX, 0.5, Scalar(100, 255, 100), 2, LINE_AA);

    int Level_A = MyRadio.GetLevelA();
    sprintf(tmp_str,"Roll       %d",Level_A);
    putText(m_frame,tmp_str,Point(+20,+50),FONT_HERSHEY_SIMPLEX, 0.5, Scalar(100, 255, 100), 2, LINE_AA);

    int Level_E = MyRadio.GetLevelE();
    sprintf(tmp_str,"Pitch      %d",Level_E);
    putText(m_frame,tmp_str,Point(+20,+70),FONT_HERSHEY_SIMPLEX, 0.5, Scalar(100, 255, 100), 2, LINE_AA);

    int Level_R = MyRadio.GetLevelR();
    sprintf(tmp_str,"Yaw       %d",Level_R);
    putText(m_frame,tmp_str,Point(+20,+90),FONT_HERSHEY_SIMPLEX, 0.5, Scalar(100, 255, 100), 2, LINE_AA);

}

void C_Camera::Laser_distanceProcessing()
{

}
