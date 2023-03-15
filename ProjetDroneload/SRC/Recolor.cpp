#include "Recolor.h"
#include <iostream>

using namespace std;

Recolor::Recolor(int source)
{
    webcam = cv::VideoCapture(source);
    if (!webcam.isOpened())
    {
        throw std::runtime_error("Unable to open video source");
    }
    width = webcam.get(cv::CAP_PROP_FRAME_WIDTH);
    height = webcam.get(cv::CAP_PROP_FRAME_HEIGHT);
    x = 0;
}

void Recolor::run()
{
    if (!webcam.isOpened())
    {
        std::cout << "Error opening camera" << std::endl;
        return;
    }
    while (true)
    {
        bool ret = false;
        cv::Mat frame;
        frame = this->get_frame();
        cv::imshow("Live", frame);
        if (cv::waitKey(1) & 0xFF == 'q')
        {
            break;
        }
    }
    webcam.release();
    cv::destroyAllWindows();
}

cv::Mat Recolor::get_frame()
{
    if (webcam.isOpened())
    {
        cv::Mat imageframe;
        webcam >> imageframe;// get frame per frame from the webcam
        face = colordetect(imageframe, 22, 93, 0, 45, 255, 255);;
        return face;
    }

    else
    {
        return cv::Mat();
    }
}
cv::Mat Recolor::colordetect(cv::Mat _image, int low1, int low2, int low3, int high1, int high2, int high3)
{
    cv::Mat imageFrame = _image.clone();
    cv::Mat hsvFrame;
    cv::cvtColor(imageFrame, hsvFrame, cv::COLOR_BGR2HSV);
    cv::Scalar lower(low1, low2, low3);
    cv::Scalar upper(high1, high2, high3);
    cv::Mat mask;
    cv::inRange(hsvFrame, lower, upper, mask);
    cv::Mat kernal = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
    cv::dilate(mask, mask, kernal);
    cv::Mat res;
    cv::bitwise_and(imageFrame, imageFrame, res, mask);
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(mask, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    for (size_t i = 0; i < contours.size(); i++)
    {
        double area = cv::contourArea(contours[i]);
        if (area > 300)
        {
            cv::Rect rect = cv::boundingRect(contours[i]);
            cv::rectangle(imageFrame, rect, cv::Scalar(0, 0, 255), 2);
        }
    }
    return imageFrame;
}
