#include "Pilote.h"
#include "Camera.h"
#include "Radio.h"


extern C_Radio MyRadio ;
extern C_Camera MyBottomCamera ;
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
    m_finish = false ;
    m_AltIsToBeStabilised = false ;
    m_PreviousTime = 0 ;
    m_PreviousError = 0. ;
    m_ThrolleCmd = 0 ;
    m_TakeOffProfile.Load ( ( char* ) "TakeOff.txt" ) ;
    m_LandingProfile.Load ( ( char* ) "Landing.txt" ) ;
}

C_Pilote::~C_Pilote()
{
    //dtor
}

void C_Pilote::AltitudeStabilisation()
{
    // Récupérer l'altitude du drone mesurée par le TI
    double Altitude = MyBottomCamera.GetAltitude() ;
    int TimeAltitude = MyBottomCamera.GetTimeAltitude() ;
    // filter cette altitude
    if ( Altitude > 0. ) // si on a pu récupérer une altitude de la caméra (sinon renvoie -1)
    {
        m_FilteredAltitude = m_AphaFiltrage * m_FilteredAltitude + ( 1 - m_AphaFiltrage ) * Altitude ;
    }
    // Calcul de la commande
    ////////////////////////
    double CurError = 0. ;
    // si on est pas au premier calcul
    if ( ( ( TimeAltitude - m_PreviousTime ) > 10 ) && ( ( TimeAltitude - m_PreviousTime ) < 200 ) )
    {
        // Calculer l'erreur
        CurError = m_AltitudeConsigne - m_FilteredAltitude ;
        // Calculer la dérivée de l'erreur
        double Derivate = ( CurError - m_PreviousError ) / ( TimeAltitude - m_PreviousTime ) ;
        // Calculer la commande throttle à envoyer à la télécommande
        double ThrolleCmd = m_PID_P * CurError + m_PID_D * Derivate ;
        m_ThrolleCmd = ( int ) ThrolleCmd ;
        if ( m_ThrolleCmd < 0 ) m_ThrolleCmd = 0 ;
        if ( m_ThrolleCmd > 100 ) m_ThrolleCmd = 100 ;
    }
    // conserver les valeurs pour le prochain calcul
    m_PreviousError = CurError ;
    m_PreviousTime = TimeAltitude ;
    // envoyer la commande
    MyRadio.SetLevelT ( m_ThrolleCmd ) ;
}

void C_Pilote::StartAutoPiloteLoop()
{
    fprintf(stderr,"AutoPilote lancé\n") ;
    m_finish = false ;
    do
    {
        if ( m_AltIsToBeStabilised )
        {
            AltitudeStabilisation() ;
        }

        // TODO décolage, gauche, droite, ...
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
    }
    else
    {
        m_AltIsToBeStabilised = true ;
    }
};


void C_Pilote::Takeoff()
{
    fprintf ( stderr, "Take OFF\n" );
    /*
    if (m_state != IDLE )
    {
        fprintf(stderr,"Take off impossible car déjà en vol\n");
        return ;
    }
    */
    m_state = TAKINGOFF ;
    m_TakeOffProfile.Play() ;
    m_state = INFLIGHT ;
}

void C_Pilote::Landing()
{
    fprintf ( stderr, "Landing\n" );
    m_state = LANDING ;
    m_LandingProfile.Play() ;
    m_state = IDLE ;
}





