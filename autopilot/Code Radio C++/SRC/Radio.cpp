#include "Radio.h"
#include <stdio.h>


C_Radio::C_Radio()
{
    Load() ;
    Open( m_NomPort ) ;
    Reset();
    //ctor
}

C_Radio::~C_Radio()
{
    m_Port.close() ;
    Save() ;
    //dtor
}

void C_Radio::SetDefault()
{
        m_Mode = NORM ;
        strcpy(m_NomPort,"COM1") ;
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
            if ( tok != NULL ) strcpy( m_NomPort, tok );
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

bool C_Radio::Open( const char * i_PortName )
{
    m_Port.close() ;
    strcpy(m_NomPort, i_PortName ) ;
    int OK = m_Port.open( m_NomPort );
    if ( OK == 0 )
    {
        m_IsOpen = true ;
    }
    else
    {
        m_IsOpen = false ;
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

void C_Radio::EnvoieCmd( unsigned char cmd, unsigned char value)
{
    fprintf(stderr,"Envoi du niveau %d avec la comande %d\n",value,cmd );
    m_Port.send(cmd);
    m_Port.send(value);
}

void C_Radio::Reset()
{
    SetLevelT(0);
    ReCenter();
}

void C_Radio::ReCenter()
{
    SetLevelA(50);
    SetLevelE(50);
    SetLevelR(50);
}

void C_Radio::SetMode( int i_Mode )
{
    m_Mode=i_Mode ;
}

int C_Radio::GetMode()
{
    return m_Mode ;
}

void C_Radio::SetLevelA( unsigned char i_level )
{
    m_LevelA = i_level ;
    EnvoieCmd( CmdA,m_LevelA + m_TrimA );
}
unsigned char C_Radio::GetLevelA()
{
    return m_LevelA ;
}

void C_Radio::SetLevelE( unsigned char i_level )
{
    m_LevelE = i_level ;
    EnvoieCmd( CmdE,m_LevelE + m_TrimE );
}
unsigned char C_Radio::GetLevelE()
{
    return m_LevelE ;
}

void C_Radio::SetLevelR( unsigned char i_level )
{
    m_LevelR = i_level ;
    EnvoieCmd( CmdR,m_LevelR + m_TrimR );
}
unsigned char C_Radio::GetLevelR()
{
    return m_LevelR ;
}

void C_Radio::SetLevelT( unsigned char i_level )
{
    m_LevelT = i_level ;
    EnvoieCmd( CmdT,m_LevelT + m_TrimT );
}
unsigned char C_Radio::GetLevelT()
{
    return m_LevelT ;
}

void C_Radio::SetTrimA( char i_trim )
{
    m_TrimA = i_trim ;
}
char C_Radio::GetTrimA()
{
    return m_TrimA ;
}

void C_Radio::SetTrimE( char i_trim )
{
    m_TrimE = i_trim ;
}
char C_Radio::GetTrimE()
{
    return m_TrimE ;
}

void C_Radio::SetTrimR( char i_trim )
{
    m_TrimR = i_trim ;
}
char C_Radio::GetTrimR()
{
    return m_TrimR ;
}

void C_Radio::SetTrimT( char i_trim )
{
    m_TrimT = i_trim ;
}
char C_Radio::GetTrimT()
{
    return m_TrimT ;
}
