/**
  @file videocapture_basic.cpp
  @brief A very basic sample for using VideoCapture and VideoWriter
  @author PkLab.net
  @date Aug 24, 2016
*/
#include "Camera.h"


using namespace cv;
using namespace std;

C_Camera::C_Camera()
{
    deviceID = 0;             // 0 = open default camera
    apiID = cv::CAP_ANY;      // 0 = autodetect default API
    IsRunning = false ;
    ShowImage = true ;
    ReccodImage = false ;
}

C_Camera::~C_Camera()
{
};

int C_Camera::Run()
{
    // open selected camera using selected API
    cap.open ( deviceID, apiID );

    // check if we succeeded
    if ( !cap.isOpened() )
    {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }

    IsRunning =true ;

    frame_width = cap.get ( cv::CAP_PROP_FRAME_WIDTH );
    frame_height = cap.get ( cv::CAP_PROP_FRAME_HEIGHT );

    // Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file.
    VideoWriter video ( "outcpp.avi", cv::VideoWriter::fourcc ( 'M', 'J', 'P', 'G' ), 25, Size ( frame_width, frame_height ) );


    for ( ;; )
    {
        // wait for a new frame from camera and store it into 'frame'
        cap.read ( frame );

        // check if we succeeded
        if ( frame.empty() )
        {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }

        // Traitement image
        ImageProcessing() ;

        // Write the frame into the file 'outcpp.avi'
        if (ReccodImage) video.write ( frame );

        // incruts help
        putText(frame, "Exit : ESC   -   Record : r   -   Stop recording : s", Point(10,frame_height-12), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(255,255,255),1);
        if (ReccodImage) circle(frame,Point(frame_width-20,frame_height-15),12,Scalar(0,0,255),FILLED);

        // show live and wait for a key with timeout long enough to show images
        if (ShowImage)
        {
            imshow ( "Live", frame );
        }
        else
        {
            destroyAllWindows();
        }

        // manage cmd
        int key =  waitKey ( 5 ) ;
        if (key == 27 ) ShowImage = false; // esc : exit image viewer
        if (key == 114) ReccodImage  = true ; // r start recording
        if (key == 115) ReccodImage = false ; // s stop recording

    }

    // When everything done, release the video capture and write object
    cap.release();
    video.release();

    // Closes all the frames


    IsRunning =false ;

    return ( 0 ) ;
}

void C_Camera::ToggleRecording ()
{
    if ( ReccodImage )
    {
        ReccodImage = false ;
    }
    else
    {
        ReccodImage = true ;
    }
} ;

bool C_Camera::IsRecording()
{
    return ReccodImage ;
} ;

void C_Camera::ToggleShowing ()
{
    if ( ShowImage )
    {
        ShowImage = false ;
    }
    else
    {
        ShowImage = true ;
    }
} ;

bool C_Camera::IsShowing()
{
    return ShowImage ;
} ;

void C_Camera::ImageProcessing()
{
    // Convert the image to grayscale
    Mat gray ;
    cvtColor(frame, gray, COLOR_BGR2GRAY) ;

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
                rectangle(frame, Point(x, y), Point(x + w, y + h), Scalar(0,0,0), 2) ;
                circle(frame, Point(center_x, center_y), 5, Scalar(0, 0, 255), -1) ;
                char tmp_str[ 50 ] ;
                sprintf(tmp_str,"x: %d y: %d",center_x, center_y) ;
                putText(frame, tmp_str, Point(center_x+10, center_y-10), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(300, 0, 255), 2, LINE_AA) ;
             }
        }
    }
}
