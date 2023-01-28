#ifndef C_Camera_H
#define C_Camera_H

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

class C_Camera
{
public:
    C_Camera();
    ~C_Camera();
    int Run() ;

private:
    Mat m_frame ;
};

#endif /* C_PortSerie_H */
