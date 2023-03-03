#include "Radio.h"
#include <stdio.h>
#include <iostream>

C_Radio::C_Radio()
{
    Load() ;
    Open ( m_NomPort ) ;
    Reset();
    LogFile = fopen("Radio.log","a") ;
    m_Log = false ;
}

C_Radio::~C_Radio()
{
    m_Port.close() ;
    Save() ;
}

void C_Radio::SetDefault()
{
    m_Mode = NORM ;
    strcpy ( m_NomPort, "COM1" ) ;
    m_TrimA = 0 ;
    m_TrimE = 0 ;
    m_TrimR = 0 ;
    m_TrimT = 0 ;
}

void C_Radio::Load()
{
    FILE * InputFile = fopen ( "Radio.cfg", "r" );

    if ( InputFile != NULL )
    {
        char ligne[1024];
        if ( fgets ( ligne, 1024, InputFile ) != NULL )
        {
            char * tok = NULL ;
            tok = strtok ( ligne, ",\"" );
            if ( tok != NULL ) strcpy ( m_NomPort, tok );
            tok = strtok ( NULL, ",\"" );
            if ( tok != NULL ) sscanf ( tok, "%d", &m_Mode );
            tok = strtok ( NULL, ",\"" );
            if ( tok != NULL ) sscanf ( tok, "%d", &m_TrimA );
            tok = strtok ( NULL, ",\"" );
            if ( tok != NULL ) sscanf ( tok, "%d", &m_TrimE );
            tok = strtok ( NULL, ",\"" );
            if ( tok != NULL ) sscanf ( tok, "%d", &m_TrimR );
            tok = strtok ( NULL, ",\"" );
            if ( tok != NULL ) sscanf ( tok, "%d", &m_TrimT );
        }
    }
    else
    {
        SetDefault() ;
    }
    fclose ( InputFile ) ;
}

void C_Radio::Save()
{
    FILE * OutputFile = fopen ( "Radio.cfg", "w" );

    if ( OutputFile != NULL )
    {
        fprintf ( OutputFile, "\"%s\",%d,%d,%d,%d,%d\n",
                  m_NomPort, m_Mode, m_TrimA, m_TrimE, m_TrimR, m_TrimT ) ;
    }
    fclose ( OutputFile ) ;
}

bool C_Radio::Open ( const char * i_PortName )
{
    m_Port.close() ;
    strcpy ( m_NomPort, i_PortName ) ;
    int OK = m_Port.open ( m_NomPort );
    if ( OK == 0 )
    {
        m_IsOpen = true ;
        fprintf ( stderr, "Port %s correctly opened\n", i_PortName );
    }
    else
    {
        m_IsOpen = false ;
        fprintf ( stderr, "Problem when opening port %s\n", i_PortName );
    }
    return m_IsOpen ;
}

void C_Radio::Close()
{
    m_Port.close() ;
    m_IsOpen = false ;
}

char * C_Radio::GetNomPort()
{
    return m_NomPort ;
}

bool C_Radio::IsOpen()
{
    return m_IsOpen ;
}

void C_Radio::Send( )
{
    fprintf(stderr,"La Radio emet\n");
    while ( true )
    {
        pthread_mutex_lock ( & m_RadioMutex ) ;
        if ( m_IsOpen )
        {
            m_Port.flush( BUFFOUT );
            EnvoieCmd ( CmdA, m_LevelA + m_TrimA );
            EnvoieCmd ( CmdA, m_LevelA + m_TrimA );
            EnvoieCmd ( CmdE, m_LevelE + m_TrimE );
            EnvoieCmd ( CmdR, m_LevelR + m_TrimR );
            EnvoieCmd ( CmdT, m_LevelT + m_TrimT );
            if (m_Log) fprintf(LogFile,"%d >> %03d %03d %03d %03d\n", timeGetTime(), (int) (m_LevelA + m_TrimA), (int) ( m_LevelE + m_TrimE ),(int) ( m_LevelR + m_TrimR ), (int) ( m_LevelT + m_TrimT ) ) ;
        }
        pthread_mutex_unlock ( & m_RadioMutex ) ;
        Sleep(10) ;
    }
}

void C_Radio::Listen( )
{
    fprintf(stderr,"La Radio reçoit\n");

    while ( true )
    {
        pthread_mutex_lock ( & m_RadioMutex ) ;
        if ( m_IsOpen )
        {
            m_Port.flush( BUFFIN );
            while( m_Port.receive()!=255 ) // attente synchro
            {
            }
            m_Received_Mode =  m_Port.receive() ;
            m_Received_LevelA =  m_Port.receive();
            m_Received_LevelE =  m_Port.receive();
            m_Received_LevelR =  m_Port.receive();
            m_Received_LevelT =  m_Port.receive();
            if (m_Log) fprintf(LogFile,"%d << %d %03d %03d %03d %03d\n", timeGetTime(), (int)m_Received_Mode, (int) m_Received_LevelA, (int) m_Received_LevelE,(int)  m_Received_LevelR, (int) m_Received_LevelT ) ;
        }
        pthread_mutex_unlock ( & m_RadioMutex ) ;
        Sleep(10) ;
    }
}

void C_Radio::EnvoieCmd ( int cmd, int value )
{
    if ( value > 100 ) value = 100 ;
    if ( value < 0 ) value = 0 ;
    m_Port.send ( 255 ) ; // pour syncho
    m_Port.send ( ( unsigned char ) cmd ) ;
    m_Port.send ( ( unsigned char ) value ) ;
}

void C_Radio::Reset()
{
    SetLevelT ( 0 );
    ReCenter();
}

void C_Radio::ReCenter()
{
    SetLevelA ( 50 );
    SetLevelE ( 50 );
    SetLevelR ( 50 );
}

void C_Radio::SetMode ( int i_Mode )
{
    m_Mode = i_Mode ;
}

int C_Radio::GetMode()
{
    return m_Mode ;
}

void C_Radio::SetLevelA ( int i_level )
{
    m_LevelA = i_level ;
}
int C_Radio::GetLevelA()
{
    return m_LevelA ;
}

void C_Radio::SetLevelE ( int i_level )
{
    m_LevelE = i_level ;
}
int C_Radio::GetLevelE()
{
    return m_LevelE ;
}

void C_Radio::SetLevelR ( int i_level )
{
    m_LevelR = i_level ;
}
int C_Radio::GetLevelR()
{
    return m_LevelR ;
}

void C_Radio::SetLevelT ( int i_level )
{
    m_LevelT = i_level ;
}
int C_Radio::GetLevelT()
{
    return m_LevelT ;
}

void C_Radio::SetTrimA ( int i_trim )
{
    m_TrimA = i_trim ;
}
int C_Radio::GetTrimA()
{
    return m_TrimA ;
}

void C_Radio::SetTrimE ( int i_trim )
{
    m_TrimE = i_trim ;
}
int C_Radio::GetTrimE()
{
    return m_TrimE ;
}

void C_Radio::SetTrimR ( int i_trim )
{
    m_TrimR = i_trim ;
}
int C_Radio::GetTrimR()
{
    return m_TrimR ;
}

void C_Radio::SetTrimT ( int i_trim )
{
    m_TrimT = i_trim ;
}
int C_Radio::GetTrimT()
{
    return m_TrimT ;
}

int C_Radio::GetReceivedMode()
{
    return (int) m_Received_Mode ;
}

int C_Radio::GetReceivedLevelA()
{
    return (int) m_Received_LevelA ;
}

int C_Radio::GetReceivedLevelE()
{
    return (int) m_Received_LevelE ;
}

int C_Radio::GetReceivedLevelR()
{
    return (int) m_Received_LevelR ;
}

int C_Radio::GetReceivedLevelT()
{
    return (int) m_Received_LevelT ;
}

void C_Radio::ToggleLog ()
{
    if ( m_Log )
    {
        fprintf(LogFile,"%d Stop log\n",timeGetTime() ) ;
        m_Log = false ;
    }
    else
    {
        fprintf(LogFile,"%d Start log\n", timeGetTime() ) ;
        m_Log = true ;
    }
}
bool C_Radio::GetLog()
{
    return m_Log ;
};
