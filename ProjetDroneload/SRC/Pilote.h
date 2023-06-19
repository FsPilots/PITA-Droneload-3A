#ifndef C_PILOTE_H
#define C_PILOTE_H


#include "Radio.h"
#include "Camera.h"
#include "Profile.h"
#include "Filter.h"

#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include  <windows.h>

//valeurs mesurées de throttle

#define StationnaryThrottleValue 30
#define ClimbThrottleValue 35
#define LandThrottleValue 20
#define ClimbTime 3000


//differentes valeurs d'etat du pilote
#define IDLE 0
#define TAKINGOFF 2
#define INFLIGHT 4
#define LANDING 8
#define STABILIZED 16
#define READINGQR 32
#define PASSGATE 64

#define PILOTELOOPTIME 50

class C_Pilote
{
    private:
        FILE * DebugFile ;
        int m_state ;
        double m_FilteredAltitude ;
        double m_FilteredCenter_x;
        double m_FilteredCenter_y;
        double m_AphaFiltrage ;
        double m_AltitudeConsigne ;
        double m_CenterConsigne_x;
        double m_CenterConsigne_y;
        double m_PID_P_Up ;
        double m_PID_P_Dwn ;
        double m_PID_P_Center ;
        double m_PID_P_Center_Roll ;
        double m_CurrError ;
        double m_Intagrale_ThrolleCmd;
        double m_PID_I;

        double m_PID_D_Center ;
        bool m_finish ;
        int m_PreviousTime ;
        double m_PreviousError ;
        int m_ThrolleCmd ;
        int m_RollCmd;
        int m_ThrolleCmd_adaptative_ref;
        int m_indice_passsage_mode_auto_throttle;
        int m_PreviousThrottleCmd;

        int m_PreviousTimeCenter ;
        double m_PreviousErrorCenter_x ;
        double m_PreviousErrorCenter_y ;


        bool m_AltIsToBeStabilised ;
        void AltitudeStabilisation() ;

        C_Profile m_TakeOffProfile ;
        C_Profile m_LandingProfile ;

        C_Filter m_ThrottleFilter ;

    public:
        C_Pilote();
        virtual ~C_Pilote();

        pthread_t m_MoveThread;            //thread pour effectuer des mouvements prédéfinis ( decoller , atterir , avancer d'un metre ...)--> comme on ne decolle pas en mem temps d'atterir , on aura jamais deux fontions de ce type en meme temps
        pthread_t m_CenterThread;          //thread pour effectuer des controles du drone en temps réel ( centrer , stabiliser ...)
        pthread_mutex_t m_PilotMutex ;

        // fonction principale à lancer dans une thread
        void StartAutoPiloteLoop() ; //tourne tout le temps , fait soit rien , soit stabilisation altitude , soit centrer .....
        void StopAutoPiloteLoop() ;  //possibilité d'arreter l'autopilote ( normalement pas utilisé)
        void ToggleAltitudeStabilisation() ;


        // actions prédéfinies
        void Takeoff( ) ;
        void Landing( ) ;
        void Translate ( int i_NbTranslate );
        void ReadQR();
        void PassGate();
        int m_Activity;




        //controles en temps réel
        void Center() ;
        void Stabilise();                 //fonction pour stabiliser le drone par flux optique si les résultats du lidar ne sont pas satifaisants


        int GetState() { return m_state ; } ;
        int GetActivity() { return m_Activity ; } ;
        void SetActivity(int i_Activity){m_Activity=i_Activity;};
        void SetState(int i_State){m_state=i_State;};


        int GetAltutudeConsigne () {return m_AltitudeConsigne;};
        void SetAltitudeConsigne(int i_AltitudeConsigne){m_AltitudeConsigne=i_AltitudeConsigne;};

        double GetFilteredAltitude () {return m_FilteredAltitude;};



        int Getm_indice_passsage_mode_auto_throttle(){return m_indice_passsage_mode_auto_throttle;};
        void Setm_indice_passsage_mode_auto_throttle(int i_indice_passsage_mode_auto_throttle){m_indice_passsage_mode_auto_throttle=i_indice_passsage_mode_auto_throttle;};


        double Setm_PID_P_Center(double i_m_PID_P_Center){m_PID_P_Center=i_m_PID_P_Center;};
        double Setm_PID_P_Center_Roll(double i_m_PID_P_Center_Roll){m_PID_P_Center_Roll=i_m_PID_P_Center_Roll;};

        double Getm_ThrolleCmd_adaptative_ref(){return m_ThrolleCmd_adaptative_ref;};
        double Getm_CurrError(){return m_CurrError;};

        void SetAlphaFiltrage( double i_AlphaFiltrage ) { m_AphaFiltrage = i_AlphaFiltrage ; } ;
        double GetAlphaFiltrage( ) { return m_AphaFiltrage ; } ;
        void SetPID_P_Up( double i_PID_P_Up ) {m_PID_P_Up=i_PID_P_Up; };
        double GetPID_P_Up( ) { return m_PID_P_Up ; };
        void SetPID_P_Dwn( double i_PID_P_Dwn ) {m_PID_P_Dwn=i_PID_P_Dwn; };
        double GetPID_P_Dwn( ) { return m_PID_P_Dwn ; };

        double Getm_PID_P_Center () {return m_PID_P_Center;};
        double Getm_PID_P_Center_Roll () {return m_PID_P_Center_Roll;};




        double Getm_Intagrale_ThrolleCmd(){return m_Intagrale_ThrolleCmd;};
};

#endif // C_PILOTE_H
