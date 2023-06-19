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
    m_AphaFiltrage = 0.05  ;
    m_AltitudeConsigne = 1. ;

    m_finish = false ;
    m_AltIsToBeStabilised = false ;
    m_PreviousTime = 0 ;
    m_PreviousError = 0. ;
    m_ThrolleCmd = 0 ;
    m_FilteredAltitude = 60;
    m_TakeOffProfile.Load ( ( char* ) "TakeOff.txt" ) ;
    m_LandingProfile.Load ( ( char* ) "Landing.txt" ) ;
    m_indice_passsage_mode_auto_throttle = 0;
    m_ThrolleCmd_adaptative_ref = 35;
    m_Intagrale_ThrolleCmd = 0;

    FILE * ConfigFile = NULL ;
    ConfigFile = fopen("Pilote.txt","r");

    if (ConfigFile == NULL)
    {
        fprintf(stderr,"Valeur pilote par défaut\n");
        m_PID_P_Up = 0.1 ;
        m_PID_P_Dwn = 0.5;
        m_PID_I = 0.01;
        m_PID_P_Center = 0.2;
        m_PID_P_Center_Roll = 0.2;
    }
    else
    {
        fprintf(stderr,"Valeur pilote depuis fichier pilote.txt\n");
        fscanf(ConfigFile,"%lf",&m_PID_P_Up);
        fscanf(ConfigFile,"%lf",&m_PID_P_Dwn);
        fscanf(ConfigFile,"%lf",&m_PID_I);
        fscanf(ConfigFile,"%lf",&m_PID_P_Center);
        fscanf(ConfigFile,"%lf",&m_PID_P_Center_Roll);
        fclose( ConfigFile );
    }
    fclose (ConfigFile) ;

    fprintf(stderr,"m_PID_P_Up = %f\n",m_PID_P_Up);
    fprintf(stderr,"m_PID_P_Dwn = %f\n",m_PID_P_Dwn);
    fprintf(stderr,"m_PID_I = %f\n",m_PID_I);
    fprintf(stderr,"m_PID_P_Center = %f\n",m_PID_P_Center);
    fprintf(stderr,"m_PID_P_Center_Roll = %f\n",m_PID_P_Center_Roll);

    m_ThrottleFilter.Setup( 100 ) ; // constante de temps en ms

    DebugFile = fopen("PiloteDebugFile.txt","w");

}

C_Pilote::~C_Pilote()
{
    fprintf(stderr,"Save the Pilote parameters in Pilote.txt\n") ;
    FILE * ConfigFile = fopen("Pilote.txt","w");
    fprintf(ConfigFile,"%f\n",m_PID_P_Up);
    fprintf(ConfigFile,"%f\n",m_PID_P_Dwn);
    fprintf(ConfigFile,"%f\n",m_PID_I);
    fprintf(ConfigFile,"%f\n",m_PID_P_Center);
    fprintf(ConfigFile,"%f\n",m_PID_P_Center_Roll);
    fclose( ConfigFile );

    fclose(DebugFile);
}

void C_Pilote::AltitudeStabilisation()
{

    // Récupérer l'altitude du drone mesurée par le TI
    double Altitude = MyBottomCamera.GetAltitude() ;
    int TimeAltitude = MyBottomCamera.GetTimeAltitude() ;

    fprintf(DebugFile,"%d ", TimeAltitude);
    fprintf(DebugFile,"%lf ", Altitude);

//    // filter cette altitude
//    if ( ( Altitude > 0. ) && ( Altitude < 200 ) ) // si on a pu récupérer une altitude de la caméra (sinon renvoie -1)
//    {
//        m_FilteredAltitude = m_AphaFiltrage * m_FilteredAltitude + ( 1 - m_AphaFiltrage ) * Altitude ;
//        fprintf ( stderr, "Filtered altitude : %f", m_FilteredAltitude );
//        fprintf ( stderr, " altitude : %f\n", Altitude );
//    }


    // Calcul de la commande
    ////////////////////////
    //double CurError = 0. ;
    // si on est pas au premier calcul
//    if ( ( ( TimeAltitude - m_PreviousTime ) > 10 ) && ( ( TimeAltitude - m_PreviousTime ) < 200 ) )
//    {
    m_FilteredAltitude =  MyBottomCamera.GetFilteredAltitude() ;
    fprintf(DebugFile,"%lf ", m_FilteredAltitude);

    // Calculer l'erreur
    m_CurrError = m_AltitudeConsigne - m_FilteredAltitude ;

    fprintf(DebugFile,"%lf ", m_AltitudeConsigne);
    fprintf(DebugFile,"%lf ", m_CurrError);

    double deltaThrottleCmd ;
    if (m_CurrError<0) // cons<alt -> drone trop haut
    {
        deltaThrottleCmd = m_PID_P_Up * m_CurrError;
    }
    if (m_CurrError>0)
    {
        deltaThrottleCmd = m_PID_P_Dwn * m_CurrError;
    }

    if ( deltaThrottleCmd < -6. )
    {
        deltaThrottleCmd = -6. ;
    }
    if ( deltaThrottleCmd > 6. )
    {
        deltaThrottleCmd = 6. ;
    }
    fprintf(DebugFile,"%lf ", deltaThrottleCmd);

//    double ThrolleCmd = ( double ) m_PreviousThrottleCmd + deltaThrottleCmd;     // on va rajoiter une action integrale car on a pas de precision pour des petites erreurs , on doit avoir un gain tres grand pour pouvoir réagir a des petites erreur , et ca cré du depassement , donc on garde des gains petits , mais on va rajouter une action integrale.

//    m_Intagrale_ThrolleCmd =  m_Intagrale_ThrolleCmd + m_CurrError; // on somme les petites erreurs pour pouvoir rajouter un peu de gazs si on est un peu trop bas
//    if (m_Intagrale_ThrolleCmd < -200)
//    {
//        m_Intagrale_ThrolleCmd=0;
//    }
//
//     if (m_Intagrale_ThrolleCmd > 200)
//    {
//        m_Intagrale_ThrolleCmd=0;
//    }

    double IntegralThrottleCmd = 0. ;
//    IntegralThrottleCmd = m_PID_I *m_Intagrale_ThrolleCmd;
//    fprintf(DebugFile,"%lf ", IntegralThrottleCmd);



    // envoyer la commande
    m_ThrolleCmd = ( int ) m_ThrottleFilter.FilteredValue(TimeAltitude, ( double ) m_PreviousThrottleCmd + deltaThrottleCmd + IntegralThrottleCmd ) ;
    fprintf(DebugFile,"%f ", ( double ) m_PreviousThrottleCmd + deltaThrottleCmd ) ;
    fprintf(DebugFile,"%d ", m_ThrolleCmd ) ;

    //m_ThrolleCmd = ( int ) ThrolleCmd + (int)IntegralThrottleCmd;

    if ( m_ThrolleCmd < 20 ) m_ThrolleCmd = 20 ;
    if ( m_ThrolleCmd > 55 ) m_ThrolleCmd = 55 ;

    MyRadio.SetLevelT ( m_ThrolleCmd ) ;
    if ( Altitude > 0. ) // si on a pu récupérer une altitude de la caméra (sinon renvoie -1)
    {
        // conserver les valeurs pour le prochain calcul
        m_PreviousTime = TimeAltitude ;
    }
    m_PreviousThrottleCmd = m_ThrolleCmd;
    // Calculer la dérivée de l'erreur
    //double Derivate = ( CurError - m_PreviousError ) / ( TimeAltitude - m_PreviousTime ) ;
    // Calculer la commande throttle à envoyer à la télécommande
//    double ThrolleCmd = 50;
//    if ( CurError < -1. )
//    {
//        if ( CurError < -4. )
//        {
//            ThrolleCmd = m_ThrolleCmd_adaptative_ref - 4. ;
//        }
//        else
//        {
//            ThrolleCmd = m_ThrolleCmd_adaptative_ref - 2. ;
//        }
//    }
//    if ( CurError > 1. )
//    {
//        if ( CurError > 4. )
//        {
//            ThrolleCmd = m_ThrolleCmd_adaptative_ref + 4. ;
//        }
//        else
//        {
//            ThrolleCmd = m_ThrolleCmd_adaptative_ref + 2. ;
//        }
//    }
//    else
//    {
//        if ( m_ThrolleCmd_adaptative_ref < MyRadio.GetLevelT() )
//        {
//            m_ThrolleCmd_adaptative_ref = MyRadio.GetLevelT()-1. ;
//        }
//         if ( m_ThrolleCmd_adaptative_ref > MyRadio.GetLevelT() )
//        {
//            m_ThrolleCmd_adaptative_ref = MyRadio.GetLevelT()+1. ;
//        }
//    }
//        double ThrolleCmd = m_PID_P * CurError + m_PID_D * Derivate ;
//        m_ThrolleCmd = ( int ) ThrolleCmd +m_ThrolleCmd_adaptative_ref -4 ;
//        fprintf ( stderr, "CurError %f ", CurError );
//        fprintf ( stderr, "Derivate %f ", Derivate );
//        fprintf ( stderr, "ThrolleCmd %f ", ThrolleCmd );
//        fprintf ( stderr, "m_ThrolleCmd %d ", m_ThrolleCmd );
//        fprintf ( stderr, "m_PID_P %f ", m_PID_P );
//        fprintf ( stderr, "\n" );
//        if ( m_ThrolleCmd < 0 ) m_ThrolleCmd = 0 ;
//        if ( m_ThrolleCmd > 100 ) m_ThrolleCmd = 100 ;
////    if ( Altitude > 0. ) // si on a pu récupérer une altitude de la caméra (sinon renvoie -1)
////    {
//        // conserver les valeurs pour le prochain calcul
//        m_PreviousError = CurError ;
//        m_PreviousTime = TimeAltitude ;
//    }
    fprintf(DebugFile,"\n" ) ;

}



void C_Pilote::PassGate()
{
    m_Activity = PASSGATE;
    // Calcul de la commande Throttle
    ////////////////////////
    double CurError = MyFrontCamera.GetCenter_y() - MyFrontCamera.GetImageCenter_y() ;
    double ThrolleCmd = m_PID_P_Center * CurError ;
    m_ThrolleCmd = ( int ) ThrolleCmd + m_ThrolleCmd ;
    if ( m_ThrolleCmd < 0 ) m_ThrolleCmd = 0 ;
    if ( m_ThrolleCmd > 100 ) m_ThrolleCmd = 100 ;
    MyRadio.SetLevelT ( m_ThrolleCmd ) ;
    // Calcul de la commande Roll
    ////////////////////////
    double CurErrorx = MyFrontCamera.GetImageCenter_x() - MyFrontCamera.GetCenter_x() ;
    double RollCmd = m_PID_P_Center_Roll * CurErrorx ;
    m_RollCmd = ( int ) RollCmd + 50 ;
    if ( m_RollCmd < 0 ) m_RollCmd = 0 ;
    if ( m_RollCmd > 100 ) m_RollCmd = 100 ;
// envoi de la commande throttle
    MyRadio.SetLevelA ( m_RollCmd ) ;
}



void C_Pilote::StartAutoPiloteLoop()
{
    fprintf ( stderr, "AutoPilote lancé\n" ) ;
    m_PreviousThrottleCmd = MyRadio.GetLevelT();



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
        m_indice_passsage_mode_auto_throttle = 0;
        m_state = INFLIGHT ;
    }
    else
    {
        m_AltIsToBeStabilised = true ;
        m_indice_passsage_mode_auto_throttle = 1;
        m_state = STABILIZED ;
        m_ThrottleFilter.FilteredValue( timeGetTime(), (float) m_PreviousThrottleCmd  ) ;
        SetAltitudeConsigne( MyBottomCamera.GetFilteredAltitude() ) ;
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
    m_TakeOffProfile.Play() ;   // condition d'arret fixée a 60 cm dans Profile.cpp
    MyRadio.SetLevelT ( m_TakeOffProfile.Getm_Last_Throttle_CMD() );
    m_ThrolleCmd_adaptative_ref = MyRadio.GetLevelT();
    m_FilteredAltitude = 60;
    m_AltitudeConsigne = 60;
    m_state = STABILIZED ;
    m_AltIsToBeStabilised = true;
    m_ThrottleFilter.FilteredValue( timeGetTime(), (float) m_PreviousThrottleCmd  ) ;
    SetAltitudeConsigne( MyBottomCamera.GetFilteredAltitude() ) ;
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
//    // Récupérer le centre de la fenetre
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
//        // Calculer la dérivée de l'erreur
//        double DerivateCenter_x = ( CurErrorCenter_x - m_PreviousErrorCenter_x ) / ( TimeCenter - m_PreviousTimeCenter ) ;
//        double DerivateCenter_y = ( CurErrorCenter_y - m_PreviousErrorCenter_y ) / ( TimeCenter - m_PreviousTimeCenter ) ;
//        // Calculer la commande roll à envoyer à la télécommande --> stabilisation selon x
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

