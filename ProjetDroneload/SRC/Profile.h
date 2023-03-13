#ifndef C_PROFILE_H
#define C_PROFILE_H

#define NB_PROFILE_POINTS 100
#define PAS_T 50



class C_Profile
{
    private:

        int m_NbProfilePoints ; // nombre de points pour décrire un profil
        int m_ProfileTime[NB_PROFILE_POINTS] ; // les dates des commandes
        int m_ProfileA[NB_PROFILE_POINTS] ; // les commande A qui correspondent aux temps
        int m_ProfileE[NB_PROFILE_POINTS] ; // les commande E qui correspondent aux temps
        int m_ProfileR[NB_PROFILE_POINTS] ; // les commande R qui correspondent aux temps
        int m_ProfileT[NB_PROFILE_POINTS] ; // les commande T qui correspondent aux temps

    public:
        C_Profile();
        virtual ~C_Profile();

        void Load( char * i_FileName ) ;
        void Play( );

};

#endif // C_Profile_H
