#include "Profile.h"
#include "Camera.h"
#include "Radio.h"
#include "Pilote.h"


#include <iostream>
#include <stdio.h>
#include <pthread.h>

extern C_Radio MyRadio ;
extern C_Camera MyBottomCamera ;
extern C_Pilote MyPilot;

using namespace std;

C_Profile::C_Profile()
{
}

C_Profile::~C_Profile()
{
    //dtor
}

void C_Profile::Load ( char * i_InputFileName )
{
    // par défaut le profil temporel ne contient aucun point
    m_NbProfilePoints = 0 ;
    FILE * InputFile = NULL ;
    // on ouvre le fichier en lecture
    InputFile = fopen ( i_InputFileName, "r" );
    // si on a put ouvrir le fichier
    if ( InputFile != NULL )
    {
        // tant qu'on peut lire des ligne dans le fichier
        while ( ! feof ( InputFile ) )
        {
            // on lit le point (temps, levelA, levelE,LevelR, levelT)
            fscanf ( InputFile, "%d %d %d %d %d",
                     &m_ProfileTime[m_NbProfilePoints],
                     &m_ProfileA[m_NbProfilePoints],
                     &m_ProfileE[m_NbProfilePoints],
                     &m_ProfileR[m_NbProfilePoints],
                     &m_ProfileT[m_NbProfilePoints] );

            fprintf(stderr,"%d %d %d %d %d\n",m_ProfileTime[m_NbProfilePoints],m_ProfileA[m_NbProfilePoints],m_ProfileE[m_NbProfilePoints],m_ProfileR[m_NbProfilePoints],m_ProfileT[m_NbProfilePoints]);
            // on a un point de plus lu
            m_NbProfilePoints = m_NbProfilePoints + 1 ;
            // précaution pour le dépassement du nombre de points max fixé à NB_PROFILE_POINTS
            if ( m_NbProfilePoints >= NB_PROFILE_POINTS )
            {
                // on arrete la boucle while
                break ;
            }
        }
    }
    // on ferme le fichier
    fclose ( InputFile ) ;
}

void C_Profile::Play()
{
    int i = 0; // compteur pour savoir dans quel intervalle je suis
    int t = 0; // le temps

    // tant que le t est inférieur au dernier temps du profil


    while( t < m_ProfileTime[m_NbProfilePoints - 1] )
    {

        // on commence par chercher dans quel intervalle de temps se trouve t
        if ( ( t > m_ProfileTime[i + 1] ) && ( i + 1 < m_NbProfilePoints ) )
        {
            i = i + 1 ;
        }

        // calcul du coefficient commun à tous les taux d'accroissements
        double coeff = ( double ) ( t - m_ProfileTime[i] ) / ( double ) ( m_ProfileTime[i + 1] - m_ProfileTime[i] ) ;
        int A  = m_ProfileA[i] + ( int ) ( coeff * ( double ) ( m_ProfileA[i + 1] - m_ProfileA[i] ) ) ;
        int E  = m_ProfileE[i] + ( int ) ( coeff * ( double ) ( m_ProfileE[i + 1] - m_ProfileE[i] ) ) ;
        int R  = m_ProfileR[i] + ( int ) ( coeff * ( double ) ( m_ProfileR[i + 1] - m_ProfileR[i] ) ) ;
        int T  = m_ProfileT[i] + ( int ) ( coeff * ( double ) ( m_ProfileT[i + 1] - m_ProfileT[i] ) ) ;
        fprintf ( stderr, "%d %d %d %d %d\n", t, A, E, R, T ) ;



    if (MyBottomCamera.GetAltitude()<100)
    {
        // On envoie les niveaux à la radio
        //MyRadio.SetLevelA ( A );
        //MyRadio.SetLevelE ( E );
        //MyRadio.SetLevelR ( R );
        MyRadio.SetLevelT ( T );
        m_Last_Throttle_CMD=T;

        // On attend PAS_T
        Sleep ( PAS_T );

        // On passe au temps suivant
        t = t + PAS_T ;
    }
    else
    {
        break;
    }


    }
}





