#ifndef RADIO_H
#define RADIO_H

#include "PortSerie.h"

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
        bool Open( const char * i_PortName );
        void Close() ;
        bool IsOpen() ;

        void Reset();
        void ReCenter();

        void SetMode( int i_Mode );
        int GetMode();

        char * GetNomPort() ;

        void SetLevelA( unsigned char i_level ) ;
        unsigned char GetLevelA() ;
        void SetLevelE( unsigned char i_level ) ;
        unsigned char GetLevelE() ;
        void SetLevelR( unsigned char i_level ) ;
        unsigned char GetLevelR() ;
        void SetLevelT( unsigned char i_level ) ;
        unsigned char GetLevelT() ;

        void SetTrimA( char i_trim ) ;
        char GetTrimA() ;
        void SetTrimE( char i_trim ) ;
        char GetTrimE() ;
        void SetTrimR( char i_trim ) ;
        char GetTrimR() ;
        void SetTrimT( char i_trim ) ;
        char GetTrimT() ;

    protected:

    private:
        int m_Mode;
        char m_NomPort[255];
        C_PortSerie m_Port ;
        bool m_IsOpen ;

        unsigned char m_LevelA;
        unsigned char m_LevelE;
        unsigned char m_LevelR;
        unsigned char m_LevelT;

        char m_TrimA;
        char m_TrimE;
        char m_TrimR;
        char m_TrimT;

        void EnvoieCmd( unsigned char cmd, unsigned char level);
        void SetDefault() ;
        void Load() ;
        void Save() ;

};

#endif // RADIO_H
