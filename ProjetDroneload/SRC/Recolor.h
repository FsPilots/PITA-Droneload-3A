#ifndef RECOLOR_H
#define RECOLOR_H

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
class Recolor
{
private :

    cv::VideoCapture webcam;
    double width;
    double height;
    int x;
    cv::Mat face;
    double centre_rect_x=0;
    double centre_rect_y=0;
    double centre_image_x;
    double centre_image_y;
    bool detection =false;



public :
    Recolor(int source=0) ;
    void run();
    cv::Mat get_frame();
    cv::Mat colordetect(cv::Mat _image, int low1, int low2, int low3, int high1, int high2, int high3);
    void pilotage();


};

#endif // MATRICE33_H
