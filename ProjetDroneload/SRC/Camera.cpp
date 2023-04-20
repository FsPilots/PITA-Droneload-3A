/**
  @file videocapture_basic.cpp
  @brief A very basic sample for using VideoCapture and VideoWriter
  @author PkLab.net
  @date Aug 24, 2016
*/
#include "Camera.h"
#include "Radio.h"

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
        if (m_type == FRONT) ImageProcessing_WindowsDetection() ;
        if (m_type == BOTTOM) ImageProcessing_PointLaserDetection() ;
        //if (m_type == BOTTOM) XYStabilizeProcessing_harris();

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

void C_Camera::ImageProcessing_WindowsDetection()
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

void C_Camera::ImageProcessing_PointLaserDetection()
{
    Mat blured;
    // Apply Gaussian blur to the image
        // ksize == 25 intensifie le flou et permet de reduire le bruit de l'image thresholded
        GaussianBlur(m_frame, blured, Size(25, 25), 0);

        // Convert the image to the HSV color space
        Mat hsv;
        cvtColor(blured, hsv, COLOR_BGR2HSV);

        // Définition des bornes de couleur pour le rouge -> Laser rouge
        Scalar lower_red(0, 150, 150);
        Scalar upper_red(10, 255, 255);
        Scalar lower_red2(170, 150, 150);
        Scalar upper_red2(180, 255, 255);

        // Masquage de l'image pour ne garder que les pixels rouges
        Mat mask, mask2;
        inRange(hsv, lower_red, upper_red, mask);
        inRange(hsv, lower_red2, upper_red2, mask2);
        bitwise_or(mask, mask2, mask);

        // Application d'une morphologie pour éliminer les petits artefacts
        Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
        morphologyEx(mask, mask, MORPH_OPEN, kernel);

        // Recherche des contours dans l'image
        std::vector<std::vector<Point>> contours;
        findContours(mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        // Initialisation d'une liste pour stocker les centres des cercles rouges
        std::vector<Point> centers;

        // Parcours des contours et recherche des cercles rouges
        for (const auto& contour : contours) {
            // Calcul du centre du contour
            Moments M = moments(contour);
            if (M.m00 != 0) {
                int cx = int(M.m10 / M.m00);
                int cy = int(M.m01 / M.m00);
                // Vérification de la couleur rouge
                if (mask.at<uchar>(cy, cx) == 255) {
                    // Stockage des coordonnées du centre
                    centers.push_back(Point(cx, cy));
                }
            }
        }
        /*
        std::cout << "Recap des cercles trouves: ";
        for (const auto& center : centers) {
            std::cout << "(" << center.x << ", " << center.y << ") ";
        }
        std::cout << std::endl;
        */

        // Vérification que deux cercles rouges ont été détectés
        if (centers.size() == 2)
        {
            // Traitement des coordonnées des cercles (Deduction de la distance)
            float distance = sqrt(pow(centers[1].x - centers[0].x, 2) + pow(centers[1].y - centers[0].y, 2));
            // Traitement de la distance (Deduction de la hauteur)
            float altitude = 0;


            // Dessin des cercles sur l'image d'origine et affichage des coordonnées
            for (size_t i = 0; i < centers.size(); i++)
            {
                circle(m_frame, centers[i], 5, Scalar(0, 255, 0), -1); // Dessin d'un cercle vert pour chaque centre
                putText(m_frame, to_string(i+1), centers[i], FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2); // Affichage du numéro de chaque cercle
                // Affichage des coordonnées du cercle
                string coord = "(" + to_string(centers[i].x) + ", " + to_string(centers[i].y) + ")";
                putText(m_frame, coord, Point(centers[i].x + 20, centers[i].y - 20), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
                // Calcul et affichage de la distance entre les deux cercles
                if (i > 0)
                {
                    string dist = "Distance: " + to_string(distance) + " pixels";
                    putText(m_frame, dist, Point(200, 425), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);


                    string alti = "Altitude: " + to_string(altitude) + " metres";
                    putText(m_frame, alti, Point(200, 450), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
                    imshow("Webcam avec cercles", m_frame);
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



void C_Camera::XYStabilizeProcessing_harris()
{

    Mat frame1, frame2; // Frames pour stocker les images

    m_cap >> frame1; // Capture une première image
    cvtColor(frame1, frame1, COLOR_BGR2GRAY); // Convertit l'image en niveaux de gris

    // Définit les paramètres pour le calcul du flux optique
    const int MAX_CORNERS = 500;
    double quality_level = 0.01;
    double min_distance = 10;
    int block_size = 3;
    bool use_harris_detector = false;
    double k = 0.04;

    std::vector<Point2f> corners1, corners2;
    goodFeaturesToTrack(frame1, corners1, MAX_CORNERS, quality_level, min_distance, Mat(), block_size, use_harris_detector, k);

    // Boucle principale pour le calcul du flux optique
    while (true)
    {
        m_cap >> frame2; // Capture une deuxième image
        cvtColor(frame2, frame2, COLOR_BGR2GRAY); // Convertit l'image en niveaux de gris

        std::vector<uchar> status;
        std::vector<float> err;
        Size win_size = Size(21, 21);
        TermCriteria termcrit = TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 70, 0.01);

        // Calcule le flux optique à partir des deux images et des coins détectés dans la première image
        calcOpticalFlowPyrLK(frame1, frame2, corners1, corners2, status, err, win_size, 3, termcrit);

        // Dessine les déplacements des coins sur l'image de la deuxième frame
        for (size_t i = 0; i < corners1.size(); i++)
        {
            if (status[i])
            {
                line(frame2, corners1[i], corners2[i], Scalar(0, 0, 255));
                circle(frame2, corners2[i], 2, Scalar(0, 255, 0), -1);
            }
        }

        imshow("Flux optique", frame2); // Affiche l'image avec les déplacements des coins

        char c = waitKey(1); // Attends une touche pour quitter
        if (c == 27)
            break;

        // Met à jour la première image et les coins pour la prochaine itération
        frame1 = frame2.clone();
        goodFeaturesToTrack(frame1, corners1, MAX_CORNERS, quality_level, min_distance, Mat(), block_size, use_harris_detector, k);

        corners1 = corners2;
    }


}
