#include "PortSerie.h"
#include <stdio.h>

C_PortSerie::C_PortSerie()
{

};

C_PortSerie::C_PortSerie ( char * i_NomPort )
{
    open ( i_NomPort );
};

C_PortSerie::~C_PortSerie()
{
    close();
};

int C_PortSerie::open ( char * i_NomPort )
{
    //Ouverture du port de communication
    handleSerial = CreateFile ( TEXT ( i_NomPort ), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );

    //Vérification de l'ouverture du handle
    if ( handleSerial == INVALID_HANDLE_VALUE ) return -1 ;

    //Lecture configuration initiale
    if ( !GetCommState ( handleSerial, &dcb ) ) return -2;
    dcb.BaudRate = CBR_57600;
    if ( !SetCommState ( handleSerial, &dcb ) ) return -3;

    return 0 ;
};

int C_PortSerie::close()
{
    int res = 0 ;
    res = CloseHandle ( handleSerial );
    return res ;
};

int C_PortSerie::send ( unsigned char i_value )
{
    unsigned char ByteToWrite = i_value ;
    unsigned long nBytesWritten = 0 ;
    WriteFile ( handleSerial, &ByteToWrite, 1, &nBytesWritten, NULL );
    return nBytesWritten ;
}

unsigned char C_PortSerie::receive( )
{
    unsigned long nBytesRead = 0 ;
    unsigned char ByteToRead = 0 ;
    while ( nBytesRead == 0 )
    {
        ReadFile ( handleSerial, & ByteToRead, 1, &nBytesRead, NULL );
    }
    return ByteToRead ;
};

void C_PortSerie::flush ( int sens )
{
    switch ( sens )
    {
    case BUFFIN :
        PurgeComm ( handleSerial, PURGE_RXCLEAR );
        break ;
    case BUFFOUT :
        PurgeComm ( handleSerial, PURGE_TXCLEAR );
        break;
    default:
        break;
    }
};
