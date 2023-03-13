#ifndef C_PILOTE_H
#define C_PILOTE_H

#include "Radio.h"
#include "Camera.h"
#include "Profile.h"

#include <iostream>
#include <stdio.h>
#include <pthread.h>

//valeurs mesurées de throttle

#define StationnaryThrottleValue 30
#define ClimbThrottleValue 35
#define LandThrottleValue 20
#define ClimbTime 3000

#define IDLE 0
#define TAKINGOFF 1
#define INFLIGHT 2
#define LANDING 3



class C_Pilote
{
    private:
        int m_state ;

        C_Profile m_TakeOffProfile ;
        C_Profile m_LandingProfile ;

    public:
        C_Pilote();
        virtual ~C_Pilote();

        pthread_t m_MoveThread;            //thread pour effectuer des mouvements prédéfinis ( decoller , atterir , avancer d'un metre ...)--> comme on ne decolle pas en mem temps d'atterir , on aura jamais deux fontions de ce type en meme temps
        pthread_t m_CenterThread;          //thread pour effectuer des controles du drone en temps réel ( centrer , stabiliser ...)
        pthread_mutex_t m_PilotMutex ;

        // mouvements prédéfinis
        void Takeoff( ) ;
        void Landing( ) ;
        void Translate ( int i_NbTranslate );


        //controles en temps réel
        void Center() ;
        void Stabilise();                 //fonction pour stabiliser le drone par flux optique si les résultats du lidar ne sont pas satifaisants


        int GetState() { return m_state ; } ;

};

#endif // C_PILOTE_H
