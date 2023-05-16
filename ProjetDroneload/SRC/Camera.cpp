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
    m_CameraActivity=0;
}

C_Camera::~C_Camera()
{
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

            if (MyPilot.GetActivity() == READINGQR)
            {
                ImageProcessing_QRCodeDetection();
            }
            else
            {
                ImageProcessing_WindowsDetection() ;
            }





        }
        //if (m_type == FRONT) ImageProcessing_QRCodeDetection() ; //--> A assign� � un bouton

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

void C_Camera::ImageProcessing_WindowsDetection()
{
    // Convert the image to grayscale
    Mat gray ;
    cvtColor ( m_frame, gray, COLOR_BGR2GRAY ) ;
    // Apply Gaussian blur to the image
    Mat blurred ;
    int ksize = 25 ; // intensifie le flou et permet de reduire le bruit de l'image thresholded
    GaussianBlur ( gray, blurred, Size ( ksize, ksize ), 0 ) ;
    // Create an adaptive binary thresholded image
    Mat adaptthresh ;
    int  blocksize = 15 ; // permet de reduire la sensibilit� du threshold pour garder uniquement les contours les plus importants
    adaptiveThreshold ( blurred, adaptthresh, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blocksize, 2 ) ;
    // Find contours in the thresholded image
    std::vector < std::vector <cv::Point> > contours ;
    findContours ( adaptthresh, contours, RETR_LIST, CHAIN_APPROX_SIMPLE ) ;
    // Iterate over the contours and draw a rectangle around any contour that is a rectangle
    for ( size_t  i = 0; i < contours.size(); i ++ )
    {
        Rect boundbox = boundingRect ( contours[ i ] ) ;
        int x = boundbox.x ;
        int y = boundbox.y ;
        int w = boundbox.width ;
        int h = boundbox.height ;
        double aspectRatio = ( ( float ) w ) / ( ( float ) h );


        int center_x = x + w / 2 ;
        int center_y = y + h / 2 ;

        SetCenter_x(center_x);
        SetCenter_y(center_y);




        // Check if the aspect ratio of the contour is close to 1, indicating it is a scare
        if ( ( 0.95 <= aspectRatio ) && ( aspectRatio <= 1.05 ) )
        {
            if ( h > 50 )
            {
                rectangle ( m_frame, Point ( x, y ), Point ( x + w, y + h ), Scalar ( 0, 0, 0 ), 2 ) ;
                circle ( m_frame, Point ( center_x, center_y ), 5, Scalar ( 0, 0, 255 ), -1 ) ;
                char tmp_str[ 50 ] ;
                sprintf ( tmp_str, "x: %d y: %d", center_x, center_y ) ;
                putText ( m_frame, tmp_str, Point ( center_x + 10, center_y - 10 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 300, 0, 255 ), 2, LINE_AA ) ;
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

void C_Camera::ImageProcessing_PointLaserDetection()
{




  Mat blured;
    // Apply Gaussian blur to the image
    // ksize == 25 intensifie le flou et permet de reduire le bruit de l'image thresholded
    GaussianBlur ( m_frame, blured, Size ( 5, 5 ), 0 );
    // D�finition des bornes de couleur pour le rouge -> Laser rouge
    Scalar lower_red ( 190, 0, 0 );
    Scalar upper_red ( 255, 50, 50 );
    Scalar lower_red2 ( 220-20, 190-20, 200-20 );
    Scalar upper_red2 ( 255, 255, 255 );
    // Masquage de l'image pour ne garder que les pixels rouges
    Mat mask, mask2;
    inRange ( blured, lower_red, upper_red, mask );
    inRange ( blured, lower_red2, upper_red2, mask2 );
    bitwise_or ( mask, mask2, mask );

    imshow( "Webcam floue", blured);
    imshow ( "Webcam mask", mask2 );

    // Application d'une morphologie pour �liminer les petits artefacts
    Mat kernel = getStructuringElement ( MORPH_RECT, Size ( 5, 5 ) );
    morphologyEx ( mask, mask, MORPH_OPEN, kernel );





    // Recherche des contours dans l'image
    std::vector<std::vector<Point>> contours;
    findContours ( mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE );
    // Initialisation d'une liste pour stocker les centres des cercles rouges
    std::vector<Point> centers;
    // Parcours des contours et recherche des cercles rouges
    for ( const auto& contour : contours )
    {
        // Calcul du centre du contour
        Moments M = moments ( contour );
        if ( M.m00 != 0 )
        {
            int cx = int ( M.m10 / M.m00 );
            int cy = int ( M.m01 / M.m00 );
            // V�rification de la couleur rouge
            if ( mask.at<uchar> ( cy, cx ) == 255 )
            {
                // Stockage des coordonn�es du centre
                centers.push_back ( Point ( cx, cy ) );
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
    // V�rification que deux cercles rouges ont �t� d�tect�s
    float altitude = 0;

    if ( centers.size() == 2 )
    {
        // Traitement des coordonn�es des cercles (Deduction de la distance)
        float distance = sqrt ( pow ( centers[1].x - centers[0].x, 2 ) + pow ( centers[1].y - centers[0].y, 2 ) );
        // Traitement de la distance (Deduction de la hauteur)
        float d = distance;
        altitude = 4502/d ;


        // Dessin des cercles sur l'image d'origine et affichage des coordonn�es
        for ( size_t i = 0; i < centers.size(); i++ )
        {
            circle ( m_frame, centers[i], 5, Scalar ( 0, 255, 0 ), -1 ); // Dessin d'un cercle vert pour chaque centre
            putText ( m_frame, to_string ( i + 1 ), centers[i], FONT_HERSHEY_SIMPLEX, 1, Scalar ( 0, 255, 0 ), 2 ); // Affichage du num�ro de chaque cercle
            // Affichage des coordonn�es du cercle
            string coord = "(" + to_string ( centers[i].x ) + ", " + to_string ( centers[i].y ) + ")";
            putText ( m_frame, coord, Point ( centers[i].x + 20, centers[i].y - 20 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 0, 255, 0 ), 2 );
            // Calcul et affichage de la distance entre les deux cercles
            if ( i > 0 )
            {
                string dist = "Distance: " + to_string ( distance ) + " pixels";
                putText ( m_frame, dist, Point ( 200, 425 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 0, 255, 0 ), 2 );
                string alti = "Altitude: " + to_string ( altitude ) + " metres";
                putText ( m_frame, alti, Point ( 200, 450 ), FONT_HERSHEY_SIMPLEX, 0.5, Scalar ( 0, 255, 0 ), 2 );
                //imshow ( "Webcam avec cercles", m_frame );
            }
        }
    }
    m_Altitude = altitude ;
    m_TimeAltitude = timeGetTime() ;
 }

void C_Camera::ImageProcessing_QRCodeDetection()
{
    QRCodeDetector qrDetector = QRCodeDetector();

    // V�rification de la validit� de l'image
    if ( m_frame.empty() )
    {
        cout << "Erreur lors de la lecture de l'image" << endl;
    }

    // D�tection des QR codes dans l'image
    vector<Point> points;
    string qrData = qrDetector.detectAndDecode ( m_frame, points );

    // Affichage des QR codes d�tect�s
    if ( qrData.length() > 0 )
    {
        // Dessin des points de d�tection
        for ( int i = 0; i < 4; i++ )
        {
            line ( m_frame, points[i], points[ ( i + 1 ) % 4], Scalar ( 0, 255, 0 ), 2 );
        }
        // Affichage des donn�es du QR code d�tect�
        putText ( m_frame, qrData, Point ( 20, 40 ), FONT_HERSHEY_SIMPLEX, 1, Scalar ( 0, 0, 255 ), 2 );
        //Affichage de l'image avec les QR codes d�tect�s
        //imshow ( "QR code detection", m_frame );
    }
}

void C_Camera::XYStabilizeProcessing_harris()
{
    Mat frame1, frame2; // Frames pour stocker les images
    m_cap >> frame1; // Capture une premi�re image
    cvtColor ( frame1, frame1, COLOR_BGR2GRAY ); // Convertit l'image en niveaux de gris
    // D�finit les param�tres pour le calcul du flux optique
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
        m_cap >> frame2; // Capture une deuxi�me image
        cvtColor ( frame2, frame2, COLOR_BGR2GRAY ); // Convertit l'image en niveaux de gris
        std::vector<uchar> status;
        std::vector<float> err;
        Size win_size = Size ( 21, 21 );
        TermCriteria termcrit = TermCriteria ( TermCriteria::COUNT + TermCriteria::EPS, 70, 0.01 );
        // Calcule le flux optique � partir des deux images et des coins d�tect�s dans la premi�re image
        calcOpticalFlowPyrLK ( frame1, frame2, corners1, corners2, status, err, win_size, 3, termcrit );
        // Dessine les d�placements des coins sur l'image de la deuxi�me frame
        for ( size_t i = 0; i < corners1.size(); i++ )
        {
            if ( status[i] )
            {
                line ( frame2, corners1[i], corners2[i], Scalar ( 0, 0, 255 ) );
                circle ( frame2, corners2[i], 2, Scalar ( 0, 255, 0 ), -1 );
            }
        }
        //imshow ( "Flux optique", frame2 ); // Affiche l'image avec les d�placements des coins
        char c = waitKey ( 1 ); // Attends une touche pour quitter
        if ( c == 27 )
            break;
        // Met � jour la premi�re image et les coins pour la prochaine it�ration
        frame1 = frame2.clone();
        goodFeaturesToTrack ( frame1, corners1, MAX_CORNERS, quality_level, min_distance, Mat(), block_size, use_harris_detector, k );
        corners1 = corners2;
    }
}

bool C_Camera::ShowImage()
{
    if ( m_frame.empty() ) return false ;
    // on adapte la taille de ma frame � celle de l'affichage
    Mat tmpFrame ; // Une matrice temporaire pour faire le boulot
    cv::resize ( m_frame, tmpFrame, cv::Size ( m_imagepanel->GetClientSize().x, m_imagepanel->GetClientSize().y ), 1.0, 1.0, INTER_LINEAR );
    // on passe la frame retaill�e au panel d'affichage
    m_imagepanel->SetBitmapFromMat ( tmpFrame );
    return true ;
}
