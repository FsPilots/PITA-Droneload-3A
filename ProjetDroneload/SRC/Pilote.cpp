#include "Pilote.h"
#include "Camera.h"
#include "Radio.h"
#include "Profile.h"


extern C_Radio MyRadio ;
extern C_Camera MyBottomCamera ;
extern C_Camera MyFrontCamera ;
extern C_Profile MyProfile;
using namespace cv;
using namespace std;

C_Pilote::C_Pilote()
{
    m_state = IDLE ;
    m_FilteredAltitude = 0. ;
    m_AphaFiltrage = 0.95  ;
    m_AltitudeConsigne = 1. ;
    m_PID_D = 0. ;
    m_PID_P = 1. ;
    m_PID_P_Center = 0.2;
    m_PID_P_Center_Roll = 0.2;
    m_finish = false ;
    m_AltIsToBeStabilised = false ;
    m_PreviousTime = 0 ;
    m_PreviousError = 0. ;
    m_ThrolleCmd = 0 ;
    m_TakeOffProfile.Load ( ( char* ) "TakeOff.txt" ) ;
    m_LandingProfile.Load ( ( char* ) "Landing.txt" ) ;
    m_indice_passsage_mode_auto_throttle = 0;
    m_ThrolleCmd_adaptative_ref = 30;

}

C_Pilote::~C_Pilote()
{
    //dtor
}

void C_Pilote::AltitudeStabilisation()
{
    // R�cup�rer l'altitude du drone mesur�e par le TI
    double Altitude = MyBottomCamera.GetAltitude() ;
    int TimeAltitude = MyBottomCamera.GetTimeAltitude() ;
    // filter cette altitude
    if ( Altitude > 0. ) // si on a pu r�cup�rer une altitude de la cam�ra (sinon renvoie -1)
    {
        m_FilteredAltitude = m_AphaFiltrage * m_FilteredAltitude + ( 1 - m_AphaFiltrage ) * Altitude ;
        fprintf ( stderr, "Filtered altitude : %f", m_FilteredAltitude );
        fprintf ( stderr, " altitude : %f\n", Altitude );
    }
    // Calcul de la commande
    ////////////////////////
    double CurError = 0. ;
    // si on est pas au premier calcul
    if ( ( ( TimeAltitude - m_PreviousTime ) > 10 ) && ( ( TimeAltitude - m_PreviousTime ) < 200 ) )
    {
        // Calculer l'erreur
        CurError = m_AltitudeConsigne - m_FilteredAltitude ;
        // Calculer la d�riv�e de l'erreur
        double Derivate = ( CurError - m_PreviousError ) / ( TimeAltitude - m_PreviousTime ) ;
        // Calculer la commande throttle � envoyer � la t�l�commande
        double ThrolleCmd = m_PID_P * CurError + m_PID_D * Derivate ;
        m_ThrolleCmd = ( int ) ThrolleCmd +m_ThrolleCmd_adaptative_ref ;
        fprintf ( stderr, "CurError %f ", CurError );
        fprintf ( stderr, "Derivate %f ", Derivate );
        fprintf ( stderr, "ThrolleCmd %f ", ThrolleCmd );
        fprintf ( stderr, "m_ThrolleCmd %d ", m_ThrolleCmd );
        fprintf ( stderr, "m_PID_P %f ", m_PID_P );
        fprintf ( stderr, "\n" );
        if ( m_ThrolleCmd < 0 ) m_ThrolleCmd = 0 ;
        if ( m_ThrolleCmd > 100 ) m_ThrolleCmd = 100 ;
    }

    if ( Altitude > 0. ) // si on a pu r�cup�rer une altitude de la cam�ra (sinon renvoie -1)
    {
        // conserver les valeurs pour le prochain calcul
        m_PreviousError = CurError ;
        m_PreviousTime = TimeAltitude ;
    }

    // envoyer la commande
    MyRadio.SetLevelT ( m_ThrolleCmd ) ;
}

void C_Pilote::PassGate()
{
     m_Activity = PASSGATE;
    // Calcul de la commande Throttle
    ////////////////////////
double CurErrory = MyFrontCamera.GetCenter_y() - MyFrontCamera.GetImageCenter_y() ;
double ThrolleCmd = m_PID_P_Center * CurErrory ;
m_ThrolleCmd = ( int ) ThrolleCmd + 50 ;
        if ( m_ThrolleCmd < 0 ) m_ThrolleCmd = 0 ;
        if ( m_ThrolleCmd > 100 ) m_ThrolleCmd = 100 ;

    MyRadio.SetLevelT ( m_ThrolleCmd ) ;

    // Calcul de la commande Roll
    ////////////////////////
double CurErrorx = MyFrontCamera.GetImageCenter_x()-MyFrontCamera.GetCenter_x() ;
double RollCmd = m_PID_P_Center_Roll * CurErrorx ;
m_RollCmd = ( int ) RollCmd +50 ;
        if ( m_RollCmd < 0 ) m_RollCmd = 0 ;
        if ( m_RollCmd > 100 ) m_RollCmd = 100 ;

// envoi de la commande throttle
    MyRadio.SetLevelA ( m_RollCmd ) ;
}



void C_Pilote::StartAutoPiloteLoop()
{
    fprintf ( stderr, "AutoPilote lanc�\n" ) ;
    m_finish = false ;
    do
    {
        if ( m_AltIsToBeStabilised )
        {
            AltitudeStabilisation() ;
        }
            if ( m_Activity == PASSGATE )
            {
                PassGate();
                //avancer
            }

        // TODO d�colage, gauche, droite, ...
        Sleep ( PILOTELOOPTIME ) ;
    }
    while ( ! m_finish ) ;
};

void C_Pilote::StopAutoPiloteLoop()
{
    m_finish = true ;
}

void C_Pilote::ToggleAltitudeStabilisation()
{
    if ( m_AltIsToBeStabilised )
    {
        m_AltIsToBeStabilised = false ;
        m_indice_passsage_mode_auto_throttle=0;
        m_state = INFLIGHT ;
    }
    else
    {
        m_AltIsToBeStabilised = true ;
        m_indice_passsage_mode_auto_throttle=1;
        m_state = STABILIZED ;
    }
};


void C_Pilote::Takeoff()
{
    fprintf ( stderr, "Take OFF\n" );
    /*
    if (m_state != IDLE )
    {
        fprintf(stderr,"Take off impossible car d�j� en vol\n");
        return ;
    }
    */


    m_state = TAKINGOFF ;
    m_TakeOffProfile.Play() ;   // condition d'arret fix�e a 60 cm dans Profile.cpp
    MyRadio.SetLevelT(m_TakeOffProfile.Getm_Last_Throttle_CMD());
    m_ThrolleCmd_adaptative_ref=MyRadio.GetLevelT();
    m_FilteredAltitude=60;
    m_AltitudeConsigne=60;
    m_state = STABILIZED ;
    //AltitudeStabilisation() ;
}

void C_Pilote::Landing()
{
    fprintf ( stderr, "Landing\n" );
    m_state = LANDING ;
    m_LandingProfile.Play() ;
    m_state = IDLE ;
}






//{
//    m_Activity = PASSGATE;
//    // R�cup�rer le centre de la fenetre
//    int Mycenter_x = MyBottomCamera.GetCenter_x() ;
//    int Mycenter_y = MyBottomCamera.GetCenter_y() ;
//    int TimeCenter = MyBottomCamera.GetTimeAltitude() ;
//    // filter ces points
//    m_FilteredCenter_x = m_AphaFiltrage * m_FilteredCenter_x + ( 1 - m_AphaFiltrage ) * Mycenter_x ;
//    m_FilteredCenter_y = m_AphaFiltrage * m_FilteredCenter_y + ( 1 - m_AphaFiltrage ) * Mycenter_y ;
//    // Calcul de la commande
//    ////////////////////////
//    double CurErrorCenter_x = 0. ;
//    double CurErrorCenter_y = 0. ;
//    // si on est pas au premier calcul
//    if ( ( ( TimeCenter - m_PreviousTimeCenter ) > 10 ) && ( ( TimeCenter - m_PreviousTimeCenter ) < 200 ) )
//    {
//        // Calculer l'erreur
//        CurErrorCenter_x = m_CenterConsigne_x - m_FilteredCenter_x ;
//        CurErrorCenter_y = m_CenterConsigne_y - m_FilteredCenter_y ;
//        // Calculer la d�riv�e de l'erreur
//        double DerivateCenter_x = ( CurErrorCenter_x - m_PreviousErrorCenter_x ) / ( TimeCenter - m_PreviousTimeCenter ) ;
//        double DerivateCenter_y = ( CurErrorCenter_y - m_PreviousErrorCenter_y ) / ( TimeCenter - m_PreviousTimeCenter ) ;
//        // Calculer la commande roll � envoyer � la t�l�commande --> stabilisation selon x
//        double RollCmd = m_PID_P_Center * CurErrorCenter_x + m_PID_D_Center * DerivateCenter_x ;
//        m_RollCmd = ( int ) RollCmd ;
//        if ( m_RollCmd < 0 ) m_RollCmd = 0 ;
//        if ( m_RollCmd > 100 ) m_RollCmd = 100 ;
//        /*
//                // Calculer la commande throttle pour ajuster l'altitude
//                double RollCmd = m_PID_P_Center * CurErrorCenter_x + m_PID_D_Center * DerivateCenter_x ;
//                m_RollCmd = ( int ) RollCmd ;
//                if ( m_RollCmd < 0 ) m_RollCmd = 0 ;
//                if ( m_RollCmd > 100 ) m_RollCmd = 100 ;
//        */
//    }
//    // conserver les valeurs pour le prochain calcul
//    m_PreviousErrorCenter_x = CurErrorCenter_x ;
//    m_PreviousTimeCenter = TimeCenter ;
//    // envoyer la commande
//    MyRadio.SetLevelR ( m_RollCmd ) ;
//}

