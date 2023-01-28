/**
  @file videocapture_basic.cpp
  @brief A very basic sample for using VideoCapture and VideoWriter
  @author PkLab.net
  @date Aug 24, 2016
*/
#include "Camera.h"

#include <iostream>
#include <stdio.h>


C_Camera::C_Camera()
{
}

C_Camera::~C_Camera()
{
};
int C_Camera::Run()
{

    //--- INITIALIZE VIDEOCAPTURE
    VideoCapture cap;
    // open the default camera using default API
    // cap.open(0);
    // OR advance usage: select any API backend
    int deviceID = 1;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API
    // open selected camera using selected API
    cap.open(deviceID, apiID);
    // check if we succeeded



    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return 1;
    }

    //--- GRAB AND WRITE LOOP
    cout << "Start grabbing" << endl
        << "Press any key to terminate" << endl;
    for (;;)
    {
        // wait for a new frame from camera and store it into 'frame'
        cap.read(m_frame);
        // check if we succeeded
        if (m_frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // show live and wait for a key with timeout long enough to show images
        imshow("Live", m_frame);
        if (waitKey(5) >= 0)
            break;
    }
    return(0) ;
}


