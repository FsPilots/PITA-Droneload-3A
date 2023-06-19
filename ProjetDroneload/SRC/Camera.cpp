/**
  @file videocapture_basic.cpp
  @brief A very basic sample for using VideoCapture and VideoWriter
  @author PkLab.net
  @date Aug 24, 2016
*/
#include  <windows.h>
#include "Camera.h"
#include "Radio.h"

#include "Pilote.h"



#include <iostream>
#include <cstdlib>
#include <ctime>


extern C_Radio MyRadio ;
extern C_Pilote MyPilot ;

using namespace cv;
using namespace std;

C_Camera::C_Camera()
{
    m_deviceID = 0;             // 0 = open default camera
    m_apiID = cv::CAP_ANY;      // 0 = autodetect default API
    m_IsRunning = false ;
    m_ShowImage = true ;
    m_ReccodImage = false ;
    m_Altitude = -1 ;
    m_TimeAltitude = 0 ;
    m_CameraActivity = 0;
    m_2LazerFounded=false;
}

C_Camera::~C_Camera()
{
    if ( m_type == BOTTOM )
    {
        fprintf(stderr,"Save the Bottom Camera TI parameters in Camera.txt\n") ;
        FILE * ConfigFile = fopen("Camera.txt","w");
        fprintf(ConfigFile,"%d\n",m_GreyLevelThreshold);
        fprintf(ConfigFile,"%d\n",m_OpenKernelSize);
        fprintf(ConfigFile,"%d\n",m_TopHatKernelSize);
        fprintf(ConfigFile,"%d\n",m_MaxRayon);
        fprintf(ConfigFile,"%d\n",m_MinArea);
        fprintf(ConfigFile,"%d\n",m_MoyenneMin);
        fprintf(ConfigFile,"%d\n",m_SigmaMax);
        fprintf(ConfigFile,"%d\n",m_SymetryCondition);
        fprintf(ConfigFile,"%d\n",m_HorizCondition);
        fprintf(ConfigFile,"%d\n",m_ProxyCondition);
        fclose( ConfigFile );
    }
};

int C_Camera::Setup ( int i_channel, int i_type, char * i_name )
{
    m_deviceID = i_channel ;
    m_type = i_type ;
    strcpy ( m_name, i_name ) ;
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

    if ( m_type == BOTTOM )
    {
        FILE * ConfigFile = NULL ;
        ConfigFile = fopen("Camera.txt","r");

        if (ConfigFile == NULL)
        {
            m_GreyLevelThreshold = 200 ;
            m_OpenKernelSize = 2 ;
            m_TopHatKernelSize = 20 ;
            m_MaxRayon = 20 ;
            m_MinArea = 3 ;
            m_MoyenneMin = 2 ;
            m_SigmaMax =  15 ;
            m_SymetryCondition = 100 ;
            m_HorizCondition = 30 ;
            m_ProxyCondition = 20 ;
        }
        else
        {
            fscanf(ConfigFile,"%d",&m_GreyLevelThreshold);
            fscanf(ConfigFile,"%d",&m_OpenKernelSize);
            fscanf(ConfigFile,"%d",&m_TopHatKernelSize);
            fscanf(ConfigFile,"%d",&m_MaxRayon);
            fscanf(ConfigFile,"%d",&m_MinArea);
            fscanf(ConfigFile,"%d",&m_MoyenneMin);
            fscanf(ConfigFile,"%d",&m_SigmaMax);
            fscanf(ConfigFile,"%d",&m_SymetryCondition);
            fscanf(ConfigFile,"%d",&m_HorizCondition);
            fscanf(ConfigFile,"%d",&m_ProxyCondition);
            fclose( ConfigFile );

            m_AltitudeFilter.Setup( 100 ) ; // en ms
        }
    }

    return 0 ;
}

int C_Camera::Run()
{
    //namedWindow ( m_name, WINDOW_NORMAL ) ;
    m_IsRunning = true ;
    // Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file.
    char VideoFileName[256] ;
    sprintf ( VideoFileName, "%s.avi", m_name );
    VideoWriter video ( VideoFileName, cv::VideoWriter::fourcc ( 'M', 'J', 'P', 'G' ), 25, Size ( m_frame_width, m_frame_height ) );

    //Initialisation des variables pour le script windows detection
    accroche = 0;
    accroche_error = 10 ; //Valeur assigné à une variable ACCROCHE_ERROR qu'on doit pouvoir changer via l'interface graphique
    indice_non_accrochage = accroche_error;

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
        // Traitement image Front
        if ( m_type == FRONT )
        {
            if ( MyPilot.GetActivity() == READINGQR )
            {
                //Correction_Distortions_Camera_Frontale();
                ImageProcessing_QRCodeDetection();
            }
            else
            {
                ImageProcessing_WindowsDetection() ;
            }
        }
        //if (m_type == FRONT) ImageProcessing_QRCodeDetection() ; //--> A assigné à un bouton
        //Traitement image Bottom
        if ( m_type == BOTTOM )
        {
            ImageProcessing_PointLaserDetection();
        }
        //if (m_type == BOTTOM) XYStabilizeProcessing_harris();
        // Write the frame into the file 'outcpp.avi'
        if ( m_ReccodImage ) video.write ( m_frame );
        // incruts help
        //putText ( m_frame, "Exit : ESC   -   Record : r   -   Stop recording : s", Point ( 10, m_frame_height - 12 ), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar ( 255, 255, 255 ), 1 );
        if ( m_ReccodImage ) circle ( m_frame, Point ( m_frame_width - 20, m_frame_height - 15 ), 12, Scalar ( 0, 0, 255 ), FILLED );
        // show live and wait for a key with timeout long enough to show images
        if ( m_ShowImage )
        {
            // imshow ( m_name, m_frame );
            ShowImage();
        }
        else
        {
        }
        // manage cmd
        int key =  waitKey ( 5 ) ;
//        if ( key == 27 ) m_ShowImage = false; // esc : exit image viewer
//        if ( key == 114 ) m_ReccodImage  = true ; // r start recording
//        if ( key == 115 ) m_ReccodImage = false ; // s stop recording
    }
    // When everything done, release the video capture and write object
    m_cap.release();
    video.release();
    // Closes all the frames
    destroyWindow ( m_name );
    m_IsRunning = false ;
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

//void C_Camera::ImageProcessing_WindowsDetection()
//{
//    // Convert the image to grayscale
//    Mat gray ;
//    cvtColor ( m_frame, gray, COLOR_BGR2GRAY ) ;
//    // Apply Gaussian blur to the image
//    Mat blurred ;
//    int ksize = 25 ; // intensifie le flou et permet de reduire le bruit de l'image thresholded
//    GaussianBlur ( gray, blurred, Size ( ksize, ksize ), 0 ) ;
//    // Create an adaptive binary thresholded image
//    Mat adaptthresh ;
//    int  blocksize = 15 ; // permet de reduire la sensibilité du threshold pour garder uniquement les contours les plus importants
//    adaptiveThreshold ( blurred, adaptthresh, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blocksize, 2 ) ;
//    // Find contours in the thresholded image
//    std::vector < std::vector <cv::Point> > contours ;
//    findContours ( adaptthresh, contours, RETR_LIST, CHAIN_APPROX_SIMPLE ) ;
//    // Iterate over the contours and draw a rectangle around any contour that is a rectangle
//    for ( size_t  i = 0; i < contours.size(); i ++ )
//    {
//        Rect boundbox = boundingRect ( contours[ i ] ) ;
//        int x = boundbox.x ;
//        int y = boundbox.y ;
//        int w = boundbox.width ;
//        int h = boundbox.height ;
//        double aspectRatio = ( ( float ) w ) / ( ( float ) h );
//        double center_x = x + w / 2 ;
//        double center_y = y + h / 2 ;
//
//        // Check if the aspect ratio of the contour is close to 1, indicating it is a scare
//        if ( ( 0.95 <= aspectRatio ) && ( aspectRatio <= 1.05 ) )
//        {
//            if ( h > 50 )
//            {
//                rectangle ( m_frame, Point ( x, y ), Point ( x + w, y + h ), Scalar ( 0, 0, 0 ), 2 ) ;
//                circle ( m_frame, Point ( center_x, center_y ), 5, Scalar ( 0, 0, 255 ), -1 ) ;
//                char tmp_str[ 50 ] ;
//                sprintf ( tmp_str, "x: %f y: %f", center_x, center_y ) ;
//                putText ( m_frame, tmp_str, Point ( center_x + 10, center_y - 10 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 300, 0, 255 ), 2, LINE_AA ) ;
//                m_Center_x = center_x ;
//                m_Center_y = center_y ;
//            }
//        }
//    }
//    char tmp_str[50];
//    int Level_T = MyRadio.GetLevelT();
//    sprintf ( tmp_str, "Throttle   %d", Level_T );
//    putText ( m_frame, tmp_str, Point ( +20, +30 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 100, 255, 100 ), 2, LINE_AA );
//    int Level_A = MyRadio.GetLevelA();
//    sprintf ( tmp_str, "Roll       %d", Level_A );
//    putText ( m_frame, tmp_str, Point ( +20, +50 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 100, 255, 100 ), 2, LINE_AA );
//    int Level_E = MyRadio.GetLevelE();
//    sprintf ( tmp_str, "Pitch      %d", Level_E );
//    putText ( m_frame, tmp_str, Point ( +20, +70 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 100, 255, 100 ), 2, LINE_AA );
//    int Level_R = MyRadio.GetLevelR();
//    sprintf ( tmp_str, "Yaw       %d", Level_R );
//    putText ( m_frame, tmp_str, Point ( +20, +90 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 100, 255, 100 ), 2, LINE_AA );
//}

void C_Camera::ImageProcessing_WindowsDetection()
{
    // Définition des constantes qu'on doit pouvoir changer via l'interface graphique
    resolution_x = m_frame.size().width;
    resolution_y = m_frame.size().height;
    size_error =  30;
    size_accroche_error = 30;

/*
    // Define the lower and upper bounds of the WINDOW COLOR in the HSV color space --> actual window color: Black
    cv::Scalar lower_black(0, 0, 0);
    cv::Scalar upper_black(180, 255, 30);

    // Convert the image to the HSV color space
    cv::Mat hsv;
    cv::cvtColor(m_frame, hsv, cv::COLOR_BGR2HSV);

    // Create a mask that only selects pixels that fall within the lower and upper bounds of the black color
    cv::Mat maskWin;
    cv::inRange(hsv, lower_black, upper_black, maskWin);
    cv::imshow("Verif1",maskWin);

    // Apply adaptive thresholding
    cv::Mat thresh;
    cv::adaptiveThreshold(maskWin, thresh, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY_INV, 5, 2);

    // Apply slight blurring to smooth the contours
    cv::GaussianBlur(thresh, thresh, cv::Size(25, 25), 5);

    // Use the Canny edge detection algorithm to detect edges in the image
    cv::Mat edges;
    cv::Canny(thresh, edges, 100, 200);

    cv::imshow("Verif2",thresh);
    cv::imshow("Verif3",edges);
    */

    // Convert the image to grayscale
    Mat gray ;
    cvtColor ( m_frame, gray, COLOR_BGR2GRAY ) ;
    // Apply Gaussian blur to the image
    Mat blurred ;
    int ksize = 25 ; // intensifie le flou et permet de reduire le bruit de l'image thresholded
    GaussianBlur ( gray, blurred, Size ( ksize, ksize ), 0 ) ;
    // Create an adaptive binary thresholded image
    Mat adaptthresh ;
    int  blocksize = 15 ; // permet de reduire la sensibilité du threshold pour garder uniquement les contours les plus importants
    adaptiveThreshold ( blurred, adaptthresh, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blocksize, 2 ) ;

    // Find contours
    std::vector < std::vector <cv::Point> > contours ;
    findContours ( adaptthresh, contours, RETR_LIST, CHAIN_APPROX_SIMPLE ) ;


    // k est un indicateur de fenêtre trouvé
    int k = 0;
    if (accroche == 1)
    {
        char tmp_str1 [50];
        sprintf(tmp_str1,"ACCROCHE %d", indice_non_accrochage);
        cv::putText(m_frame,tmp_str1, cv::Point(resolution_x/2 - 100, resolution_y - 10), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 255, 255), 2);
        // Iterate over the contours and draw a rectangle around any contour that is a rectangle
        for ( size_t  i = 0; i < contours.size(); i ++ )
        {
            Rect boundbox = boundingRect ( contours[ i ] ) ;
            int x = boundbox.x ;
            int y = boundbox.y ;
            int w = boundbox.width ;
            int h = boundbox.height ;
            double aspectRatio = ( ( float ) w ) / ( ( float ) h );
            double center_x = x + w / 2 ;
            double center_y = y + h / 2 ;
            double check_x1 = m_Center_x - size_accroche_error;
            double check_x2 = m_Center_x + size_accroche_error;
            double check_y1 = m_Center_y - size_accroche_error;
            double check_y2 = m_Center_y + size_accroche_error;

            //Check if the window is centered
            if ((abs(check_x1) < abs(center_x)) &&  (abs(center_x)< abs(check_x2)) && (abs(check_y1) < abs(center_y)) &&(abs(center_y) < abs(check_y2)))
            {
                // Check if the aspect ratio of the contour is close to 1, indicating it is a scare
                if ( ( 0.85 <= aspectRatio ) && ( aspectRatio <= 1.15 ) )
                {
                    if ( h > 50 )
                    {
                        rectangle ( m_frame, Point ( x, y ), Point ( x + w, y + h ), Scalar ( 0, 0, 0 ), 2 ) ;
                        circle ( m_frame, Point ( center_x, center_y ), 5, Scalar ( 0, 0, 255 ), -1 ) ;
                        char tmp_str[ 50 ] ;
                        sprintf ( tmp_str, "x: %f y: %f", center_x, center_y ) ;
                        putText ( m_frame, tmp_str, Point ( center_x + 10, center_y - 10 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 300, 0, 255 ), 2, LINE_AA ) ;
                        k = 1;
                        indice_non_accrochage = 0;
                        m_Center_x = center_x ;
                        m_Center_y = center_y ;
                        break;
                    }
                }
            }
            else
            {
                k = 0;
            }
        }
        //Vérification de l'accroche pour une itération
        if (k == 0)
        {
            indice_non_accrochage = indice_non_accrochage + 1;
            //Si l'accroche n'est pas vérifié pour un nombre d'itération supérieur à la limite, l'accroche est perdue.
            if (indice_non_accrochage == accroche_error)
            {
                accroche = 0;
              cout <<"END ACCROCHAGE" <<endl ;
            }
        }
    }
    else
    {
        char tmp_str1 [50];
        sprintf(tmp_str1,"AUCUNE ACCROCHE %d", indice_non_accrochage);
        cv::putText(m_frame, tmp_str1, cv::Point(resolution_x/2 - 200, resolution_y - 10), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 255, 255), 2);
        // Iterate over the contours and draw a rectangle around any contour that is a rectangle
        for ( size_t  i = 0; i < contours.size(); i ++ )
        {
            Rect boundbox = boundingRect ( contours[ i ] ) ;
            int x = boundbox.x ;
            int y = boundbox.y ;
            int w = boundbox.width ;
            int h = boundbox.height ;
            double aspectRatio = ( ( float ) w ) / ( ( float ) h );
            double center_x = x + w / 2 ;
            double center_y = y + h / 2 ;
            double check_x1 = (resolution_x/2) - size_accroche_error;
            double check_x2 = (resolution_x/2) + size_accroche_error;
            double check_y1 = (resolution_y/2) - size_accroche_error;
            double check_y2 = (resolution_y/2) + size_accroche_error;
            //Check if the window is centered
            if ((abs(check_x1) < abs(center_x)) &&  (abs(center_x)< abs(check_x2)) && (abs(check_y1) < abs(center_y)) &&(abs(center_y) < abs(check_y2)))
            {
                // Check if the aspect ratio of the contour is close to 1, indicating it is a scare
                if ( ( 0.85 <= aspectRatio ) && ( aspectRatio <= 1.15 ) )
                {
                    if ( h > 50 )
                    {
                        rectangle ( m_frame, Point ( x, y ), Point ( x + w, y + h ), Scalar ( 0, 0, 0 ), 2 ) ;
                        circle ( m_frame, Point ( center_x, center_y ), 5, Scalar ( 0, 0, 255 ), -1 ) ;
                        char tmp_str[ 50 ] ;
                        sprintf ( tmp_str, "x: %f y: %f", center_x, center_y ) ;
                        putText ( m_frame, tmp_str, Point ( center_x + 10, center_y - 10 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 300, 0, 255 ), 2, LINE_AA ) ;
                        k = 1;
                        m_Center_x = center_x ;
                        m_Center_y = center_y ;
                        break;
                    }
                }
            }
            else
            {
                k = 0;
            }
        }
        //Vérification de l'accroche pour une itération
        if (k == 1)
        {
            indice_non_accrochage = indice_non_accrochage - 1;
            //Si l'accroche n'est pas vérifié pour un nombre d'itération supérieur à la limite, l'accroche est perdue.
            if (indice_non_accrochage == 0)
            {
                accroche = 1;
              cout <<"ACCROCHAGE" <<endl ;
            }


        }
        else
        {
            if(indice_non_accrochage < accroche_error)
            {
                indice_non_accrochage = indice_non_accrochage + 1;
            }
        }
    }

    char tmp_str[50];
    int Level_T = MyRadio.GetLevelT();
    sprintf ( tmp_str, "Throttle   %d", Level_T );
    putText ( m_frame, tmp_str, Point ( +20, +30 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 100, 255, 100 ), 2, LINE_AA );
    int Level_A = MyRadio.GetLevelA();
    sprintf ( tmp_str, "Roll       %d", Level_A );
    putText ( m_frame, tmp_str, Point ( +20, +50 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 100, 255, 100 ), 2, LINE_AA );
    int Level_E = MyRadio.GetLevelE();
    sprintf ( tmp_str, "Pitch      %d", Level_E );
    putText ( m_frame, tmp_str, Point ( +20, +70 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 100, 255, 100 ), 2, LINE_AA );
    int Level_R = MyRadio.GetLevelR();
    sprintf ( tmp_str, "Yaw       %d", Level_R );
    putText ( m_frame, tmp_str, Point ( +20, +90 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 100, 255, 100 ), 2, LINE_AA );
}

double DistanceInterPoint (Point point1, Point point2)
{
    double dx = (double) (point1.x-point2.x);
    double dy = (double) (point1.y-point2.y);
    double distance = sqrt(dx*dx+dy*dy);
    return distance;
}


void C_Camera::ImageProcessing_PointLaserDetection()
{
    Mat src, dst;
    src = m_frame ;
    cvtColor ( src, dst, COLOR_BGR2GRAY ); // Convertit l'image en niveaux de gris
    double thresh = m_GreyLevelThreshold ;
    double maxval = 255 ;
    int type = THRESH_BINARY ;
    Mat mask;
    threshold( dst, mask, thresh, maxval, type );
//// ON commence par ne garder que ce qui est proche du blanc et du rouge
//    Scalar lower_red ( 201-20, 97-20, 227-20 );
//    Scalar upper_red ( 255, 97+20, 227+20 );
//// Scalar lower_red2 ( 220 +15 , 190 +15, 200+15 );
//    Scalar lower_red2 ( 230-50, 230-50, 230-50 );
//    Scalar upper_red2 ( 255, 255, 255 );
//// Masquage de l'image pour ne garder que les pixels rouges
//    Mat mask, mask2;
//    inRange ( m_frame, lower_red, upper_red, mask );
//    cv::imshow ( "mask ", mask );
//    inRange ( m_frame, lower_red2, upper_red2, mask2 );
//    cv::imshow ( "mask2", mask2 );
//    bitwise_or ( mask, mask2, mask );
//    cv::imshow ( "mask total", mask );
    // Application d'une morphologie pour éliminer les petits artefacts
    int kernelSize = std::max( m_OpenKernelSize, 1 ) ;
    Mat kernel = getStructuringElement ( MORPH_ELLIPSE, Size (  kernelSize, kernelSize ) );         // si lazer supprimé , diminuer
    morphologyEx ( mask, mask, MORPH_OPEN, kernel );
//    cv::imshow ( "mask open", mask );
    // Application d'une morphologie pour éliminer les gros artefacts
    // Créer un élément structurant en forme de disque
    cv::Mat element = cv::getStructuringElement ( cv::MORPH_ELLIPSE, cv::Size ( m_TopHatKernelSize, m_TopHatKernelSize ) );
    // Appliquer l'opération de tophat
    cv::Mat thresholdImage;
    cv::morphologyEx ( mask, thresholdImage, cv::MORPH_TOPHAT, element );      // si lazer supprimé, augmenter 15
//    cv::imshow ( "mask open tophat", thresholdImage );
    // Application d'une morphologie pour éliminer les petits artefacts
    morphologyEx ( thresholdImage, thresholdImage, MORPH_OPEN, kernel );
//    cv::imshow ( "mask open tophat open ", thresholdImage );




    /// Recherches des contours
    vector<vector<Point>> contourstreshold;
    findContours ( thresholdImage, contourstreshold, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE );
    // Parcourir les contours et calculer l'aire de chaque zone blanche
    int Rayon = std::max( m_MaxRayon, 1) ;
    int Sref = CV_PI * Rayon * Rayon;
    std::vector<Point> centers;
    for ( size_t i = 0; i < contourstreshold.size(); i++ )                      // boucle sur touts les contours
    {
        double area = contourArea ( contourstreshold[i] );
//        int R = std::rand() % 255;
//        int G = std::rand() % 255;
//        int B = std::rand() % 255;
        // Vérifier si l'aire dépasse celle d'un disque de surface Sref
        if ( ( area < Sref ) && ( contourstreshold[i].size() > m_MinArea ) )
        {
            // Calcul du centre du contour
            Point Center;
            Moments M = moments ( contourstreshold[i] );
            if ( M.m00 != 0 )
            {
                Center.x = int ( M.m10 / M.m00 );
                Center.y = int ( M.m01 / M.m00 );
            }
            double Moyenne = 0.;
            double Moyenne2 = 0.;
            double NbPoints = 0 ;
            for ( size_t j = 0; j < contourstreshold[i].size(); j++ )           //boucle sur les points du contours i
            {
                NbPoints = NbPoints + 1. ;
                Point M = contourstreshold[i][j];
                int R2 = ( M.x - Center.x ) * ( M.x - Center.x ) + ( M.y - Center.y ) * ( M.y - Center.y );
                double rayon = sqrt ( ( double ) R2 ) ;
                Moyenne = Moyenne + rayon ;
                Moyenne2 = Moyenne2 + rayon * rayon ;
            }
            Moyenne = Moyenne / NbPoints ;
            Moyenne2 = Moyenne2 / NbPoints ;
            double Variance = Moyenne2 - Moyenne * Moyenne ;
            double Sigma = sqrt ( Variance ) ;
//            fprintf(stderr,"Contour:%d Moyenne:%f Sigma:%f\n",i,Moyenne,Sigma) ;
//            char  c = fgetc(stdin);
            if ( ( Moyenne > m_MoyenneMin ) && ( Sigma < (double)m_SigmaMax/10. ) )         // baisser moyenne si on supprime les cercles trop petits , augmenter sigma si les cercles ne sont pas bien réguliers
            {
//                drawContours ( m_frame, contourstreshold, i, Scalar ( R, G, B ), LINE_4 );
//                putText ( m_frame, to_string ( Moyenne ), Center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 0, 255, 0 ), 2 );
//                putText ( m_frame, to_string ( Sigma ), Point(Center.x,Center.y+20), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 0, 255, 0 ), 2 );
//                putText ( m_frame, to_string ( Center.x ), Point(Center.x,Center.y+40), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 0, 255, 0 ), 2 );
//                putText ( m_frame, to_string ( m_frame.cols-Center.x ), Point(Center.x,Center.y+60), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 0, 255, 0 ), 2 );
//                putText ( m_frame, to_string ( Center.y ), Point(Center.x,Center.y+80), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 0, 255, 0 ), 2 );
               centers.push_back ( Center );
            }
        }
    }
    std::vector<Point> centersValidetmp;
    for ( size_t i = 0; i < centers.size(); i++ )     //on se met sur le centre i
    {
        for ( size_t j = i; j < centers.size(); j++ )
        {
            if ( i != j )
            {
                if ( ( fabs ( m_frame.cols - centers[i].x - centers[j].x ) < m_SymetryCondition ) // condition de symétrie
                  && ( fabs ( centers[i].y - centers[j].y ) < m_HorizCondition ) // a peu près horizontal
                  && ( fabs ( centers[i].x - centers[j].x ) > m_ProxyCondition ) // pas trop proche en x
                   )
                {

                    centersValidetmp.push_back ( centers[i] );
                    centersValidetmp.push_back ( centers[j] );
                    //putText ( m_frame, "OK", centers[i], FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 255, 0, 0 ), 2 );
                    //putText ( m_frame, "OK", centers[j], FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 255, 0, 0 ), 2 );
                }
            }
        }
    }


    std::vector<Point> centersValide;

     for ( size_t i = 0; i < centersValidetmp.size(); i++ )
        {
            if (m_2LazerFounded)
            {
                if ((DistanceInterPoint(centersValidetmp[i],m_Center1)<20)||(DistanceInterPoint(centersValidetmp[i],m_Center2)<20))
                {
                     centersValide.push_back ( centersValidetmp[i] );
                }

            }
            else
            {
                centersValide.push_back ( centersValidetmp[i] );
            }
        }
    /*
          // Supprimer les zones blanches du tiers supérieur de l'image
        Rect roi(0, 0, thresholdImage.cols, thresholdImage.rows / 3);
        thresholdImage(roi) = Scalar(0);



            // Définir les points du triangle
        Point center(thresholdImage.cols / 2, thresholdImage.rows / 2);
        Point bottomLeft(0, thresholdImage.rows);
        Point bottomRight(thresholdImage.cols, thresholdImage.rows);
        vector<Point> trianglePoints = { center, bottomLeft, bottomRight };

        // Supprimer les zones blanches dans le triangle défini par les points
        Mat masktriangle = Mat::zeros(thresholdImage.size(), CV_8UC1);
        fillConvexPoly(masktriangle, trianglePoints, Scalar(255));
        thresholdImage.setTo(Scalar(0), masktriangle);
    */
//    // Afficher l'image résultante
//    cv::imshow("Image resultat", thresholdImage);
//
//    // Afficher l'image originale et l'image filtrées
//    cv::imshow ( "Image originale", mask );
    cv::imshow ( "Image filtrée", thresholdImage );
//    // Recherche des contours dans l'image
//    std::vector<std::vector<Point>> contours;
//    findContours ( thresholdImage, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE );
//    // Initialisation d'une liste pour stocker les centres des cercles rouges
//    std::vector<Point> centers;
//    // Parcours des contours et recherche des cercles rouges
//    for ( const auto& contour : contours )
//    {
//        // Calcul du centre du contour
//        Moments M = moments ( contour );
//        if ( M.m00 != 0 )
//        {
//            int cx = int ( M.m10 / M.m00 );
//            int cy = int ( M.m01 / M.m00 );
//            // Stockage des coordonnées du centre
//            centers.push_back ( Point ( cx, cy ) );
//        }
//    }
    // Vérification que deux cercles rouges ont été détectés
    float altitude = 0;
    if ( centersValide.size() == 2 )
    {
        m_2LazerFounded=true;

        m_Center1=centersValide[0];
        m_Center2=centersValide[1];

        // Traitement des coordonnées des cercles (Deduction de la distance)
        float distance = sqrt ( pow ( centersValide[1].x - centersValide[0].x, 2 ) + pow ( centersValide[1].y - centersValide[0].y, 2 ) );
        // Traitement de la distance (Deduction de la hauteur)
        altitude = 5000. * pow(distance,-0.87) ;
        // Dessin des cercles sur l'image d'origine et affichage des coordonnées
        for ( size_t i = 0; i < centersValide.size(); i++ )
        {
            cv::circle ( m_frame, centersValide[i], 5, Scalar ( 0, 255, 0 ), -1 ); // Dessin d'un cercle vert pour chaque centre
            putText ( m_frame, to_string ( i + 1 ), centersValide[i], FONT_HERSHEY_SIMPLEX, 1, Scalar ( 0, 255, 0 ), 2 ); // Affichage du numéro de chaque cercle
            // Affichage des coordonnées du cercle
            string coord = "(" + to_string ( centersValide[i].x ) + ", " + to_string ( centersValide[i].y ) + ")";
            putText ( m_frame, coord, Point ( centersValide[i].x + 20, centersValide[i].y - 20 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 0, 255, 0 ), 2 );
            // Calcul et affichage de la distance entre les deux cercles
            if ( i > 0 )
            {
                string dist = "Distance: " + to_string ( distance ) + " pixels";
                putText ( m_frame, dist, Point ( 200, 425 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 0, 255, 0 ), 2 );
                string alti = "Altitude: " + to_string ( altitude ) + " cm";
                putText ( m_frame, alti, Point ( 200, 450 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 0, 255, 0 ), 2 );
                //imshow ( "Webcam avec cercles", m_frame );
            }
        }
        if ( ( altitude > 0. ) && ( altitude < 200 ) ) // si on a pu récupérer une altitude de la caméra (sinon renvoie -1)
        {
            m_Altitude = altitude ;
        }
    }
    else
    {
        m_2LazerFounded=false;
    }

    m_TimeAltitude = timeGetTime() ;
    m_FilteredAltitude = m_AltitudeFilter.FilteredValue( m_TimeAltitude , m_Altitude ) ;

}



void C_Camera::ImageProcessing_QRCodeDetection()
{
    QRCodeDetector qrDetector = QRCodeDetector();
    // Vérification de la validité de l'image
    if ( m_frame2.empty() )
    {
        cout << "Erreur lors de la lecture de l'image" << endl;
    }
    Correction_Distortions_Camera_Frontale();
    // Détection des QR codes dans l'image
    vector<Point> points;
    string qrData = qrDetector.detectAndDecode ( m_frame2, points );
    // Affichage des QR codes détectés
    if ( qrData.length() > 0 )
    {
        // Dessin des points de détection
        for ( int i = 0; i < 4; i++ )
        {
            line ( m_frame2, points[i], points[ ( i + 1 ) % 4], Scalar ( 0, 255, 0 ), 2 );
        }
        // Affichage des données du QR code détecté
        putText ( m_frame2, qrData, Point ( 20, 40 ), FONT_HERSHEY_SIMPLEX, 1, Scalar ( 0, 0, 255 ), 2 );
        //Affichage de l'image avec les QR codes détectés
        // imwrite("C:\PITA-Droneload-3A\ProjetDroneload", m_frame);
        //imshow("test",m_frame2);
    }
    m_frame = m_frame2;
}

void C_Camera::XYStabilizeProcessing_harris()
{
    Mat frame1, frame2; // Frames pour stocker les images
    m_cap >> frame1; // Capture une première image
    cvtColor ( frame1, frame1, COLOR_BGR2GRAY ); // Convertit l'image en niveaux de gris
    // Définit les paramètres pour le calcul du flux optique
    const int MAX_CORNERS = 500;
    double quality_level = 0.01;
    double min_distance = 10;
    int block_size = 3;
    bool use_harris_detector = false;
    double k = 0.04;
    std::vector<Point2f> corners1, corners2;
    goodFeaturesToTrack ( frame1, corners1, MAX_CORNERS, quality_level, min_distance, Mat(), block_size, use_harris_detector, k );
    // Boucle principale pour le calcul du flux optique
    while ( true )
    {
        m_cap >> frame2; // Capture une deuxième image
        cvtColor ( frame2, frame2, COLOR_BGR2GRAY ); // Convertit l'image en niveaux de gris
        std::vector<uchar> status;
        std::vector<float> err;
        Size win_size = Size ( 21, 21 );
        TermCriteria termcrit = TermCriteria ( TermCriteria::COUNT + TermCriteria::EPS, 70, 0.01 );
        // Calcule le flux optique à partir des deux images et des coins détectés dans la première image
        calcOpticalFlowPyrLK ( frame1, frame2, corners1, corners2, status, err, win_size, 3, termcrit );
        // Dessine les déplacements des coins sur l'image de la deuxième frame
        for ( size_t i = 0; i < corners1.size(); i++ )
        {
            if ( status[i] )
            {
                line ( frame2, corners1[i], corners2[i], Scalar ( 0, 0, 255 ) );
                circle ( frame2, corners2[i], 2, Scalar ( 0, 255, 0 ), -1 );
            }
        }
        //imshow ( "Flux optique", frame2 ); // Affiche l'image avec les déplacements des coins
        char c = waitKey ( 1 ); // Attends une touche pour quitter
        if ( c == 27 )
            break;
        // Met à jour la première image et les coins pour la prochaine itération
        frame1 = frame2.clone();
        goodFeaturesToTrack ( frame1, corners1, MAX_CORNERS, quality_level, min_distance, Mat(), block_size, use_harris_detector, k );
        corners1 = corners2;
    }
}

bool C_Camera::ShowImage()
{
    if ( m_frame.empty() ) return false ;
    // on adapte la taille de ma frame à celle de l'affichage
    Mat tmpFrame ; // Une matrice temporaire pour faire le boulot
    cv::resize ( m_frame, tmpFrame, cv::Size ( m_imagepanel->GetClientSize().x, m_imagepanel->GetClientSize().y ), 1.0, 1.0, INTER_LINEAR );
    // on passe la frame retaillée au panel d'affichage
    m_imagepanel->SetBitmapFromMat ( tmpFrame );
    return true ;
}


void C_Camera::Correction_Distortions_Camera_Frontale ()
{
    cv::Mat image = m_frame;
    // Paramètres de distorsion de la caméra Caddx Turbo
    double k1 = - 0.04;  // Coefficient de distorsion radiale
    double k2 = - 0.01;  // Coefficient de distorsion radiale
    // Taille de l'image
    int width = image.cols;
    int height = image.rows;
    // Calcul du centre de l'image
    cv::Point2f center ( width / 2.0f, height / 2.0f );
    // Image corrigée
    cv::Mat undistorted = cv::Mat::zeros ( image.size(), image.type() );
    // Correction de la distorsion de l'image
    for ( int y = 0; y < height; y++ )
    {
        for ( int x = 0; x < width; x++ )
        {
            // Calcul des coordonnées corrigées
            double u = ( x - center.x ) / center.x;
            double v = ( y - center.y ) / center.y;
            double r = std::sqrt ( u * u + v * v );
            double uDistorted = u * ( 1 + k1 * r * r + k2 * r * r * r * r );
            double vDistorted = v * ( 1 + k1 * r * r + k2 * r * r * r * r );
            int xDistorted = static_cast<int> ( center.x + uDistorted * center.x );
            int yDistorted = static_cast<int> ( center.y + vDistorted * center.y );
            // Copier le pixel correspondant dans l'image corrigée
            if ( xDistorted >= 0 && xDistorted < width && yDistorted >= 0 && yDistorted < height )
            {
                undistorted.at<cv::Vec3b> ( y, x ) = image.at<cv::Vec3b> ( yDistorted, xDistorted );
            }
        }
    }
    // Afficher l'image originale et l'image corrigée
    //cv::imshow("Image originale", image);
    //cv::imshow("Image corrigée", undistorted);
    //cv::waitKey(0);
    m_frame2 = undistorted;
}
