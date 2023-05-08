#ifndef C_PILOTE_H
#define C_PILOTE_H


#include "Radio.h"
#include "Camera.h"
#include "Profile.h"

#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include  <windows.h>

//valeurs mesur�es de throttle

#define StationnaryThrottleValue 30
#define ClimbThrottleValue 35
#define LandThrottleValue 20
#define ClimbTime 3000

#define IDLE 0
#define TAKINGOFF 1
#define INFLIGHT 2
#define LANDING 3
#define STABILIZED 4

#define PILOTELOOPTIME 50

class C_Pilote
{
    private:
        int m_state ;

        double m_FilteredAltitude ;
        double m_AphaFiltrage ;
        double m_AltitudeConsigne ;
        double m_PID_P ;
        double m_PID_D ;
        bool m_finish ;
        int m_PreviousTime ;
        double m_PreviousError ;
        int m_ThrolleCmd ;

        bool m_AltIsToBeStabilised ;
        void AltitudeStabilisation() ;

        C_Profile m_TakeOffProfile ;
        C_Profile m_LandingProfile ;

    public:
        C_Pilote();
        virtual ~C_Pilote();

        pthread_t m_MoveThread;            //thread pour effectuer des mouvements pr�d�finis ( decoller , atterir , avancer d'un metre ...)--> comme on ne decolle pas en mem temps d'atterir , on aura jamais deux fontions de ce type en meme temps
        pthread_t m_CenterThread;          //thread pour effectuer des controles du drone en temps r�el ( centrer , stabiliser ...)
        pthread_mutex_t m_PilotMutex ;

        // fonction principale � lancer dans une thread
        void StartAutoPiloteLoop() ; //tourne tout le temps , fait soit rien , soit stabilisation altitude , soit centrer .....
        void StopAutoPiloteLoop() ;  //possibilit� d'arreter l'autopilote ( normalement pas utilis�)
        void ToggleAltitudeStabilisation() ;


        // mouvements pr�d�finis
        void Takeoff( ) ;
        void Landing( ) ;
        void Translate ( int i_NbTranslate );


        //controles en temps r�el
        void Center() ;
        void Stabilise();                 //fonction pour stabiliser le drone par flux optique si les r�sultats du lidar ne sont pas satifaisants


        int GetState() { return m_state ; } ;

};

#endif // C_PILOTE_H
