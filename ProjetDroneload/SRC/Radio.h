#ifndef RADIO_H
#define RADIO_H

#include "PortSerie.h"
#include <pthread.h>

#define NORM 0
#define STAB 1
#define CmdA 41
#define CmdMaxA 42
#define CmdE 45
#define CmdMaxE 46
#define CmdR 52
#define CmdMaxR 53
#define CmdT 54
#define CmdMaxT 55

class C_Radio
{
    public:
        C_Radio();
        virtual ~C_Radio();

        pthread_t m_ListeningThread;
        pthread_t m_SendingThread;
        pthread_mutex_t m_RadioMutex ;

        void Listen( ) ;
        void Send( ) ;

        bool Open( const char * i_PortName );
        void Close() ;
        bool IsOpen() ;

        void Reset();
        void ReCenter();

        void SetMode( int i_Mode );
        int GetMode();

        char * GetNomPort() ;

        void SetLevelA( int i_level ) ;
        int GetLevelA() ;
        void SetLevelE( int i_level ) ;
        int GetLevelE() ;
        void SetLevelR( int i_level ) ;
        int GetLevelR() ;
        void SetLevelT( int i_level ) ;
        int GetLevelT() ;

        void SetTrimA( int i_trim ) ;
        int GetTrimA() ;
        void SetTrimE( int i_trim ) ;
        int GetTrimE() ;
        void SetTrimR( int i_trim ) ;
        int GetTrimR() ;
        void SetTrimT( int i_trim ) ;
        int GetTrimT() ;

        int GetReceivedMode() ;
        int GetReceivedLevelA() ;
        int GetReceivedLevelE() ;
        int GetReceivedLevelR() ;
        int GetReceivedLevelT() ;

        void ToggleLog () ;
        bool GetLog() ;

    protected:

    private:
        int m_Mode;
        char m_NomPort[255];
        C_PortSerie m_Port ;
        bool m_IsOpen ;

        int m_LevelA;
        int m_LevelE;
        int m_LevelR;
        int m_LevelT;

        unsigned char  m_Received_Mode;
        unsigned char  m_Received_LevelA;
        unsigned char  m_Received_LevelE;
        unsigned char  m_Received_LevelR;
        unsigned char  m_Received_LevelT;

        int m_TrimA;
        int m_TrimE;
        int m_TrimR;
        int m_TrimT;

        void EnvoieCmd( int cmd, int level);
        void SetDefault() ;
        void Load() ;
        void Save() ;

        bool m_Log ;
        FILE * LogFile ;
};

#endif // RADIO_H
