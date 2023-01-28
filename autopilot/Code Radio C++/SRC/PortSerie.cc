#include "PortSerie.h"
#include <stdio.h>

C_PortSerie::C_PortSerie()
{
};

C_PortSerie::C_PortSerie( char * i_NomPort )
{
    open(i_NomPort);
};

C_PortSerie::~C_PortSerie()
{
    close();
};

int C_PortSerie::open( char * i_NomPort)
{

    int res = 0 ;

    DCB dcb;                //Configuration du port

//Ouverture du port de communication
    handleSerial=CreateFile(TEXT(i_NomPort),GENERIC_WRITE|GENERIC_READ,0,NULL,OPEN_EXISTING,0,NULL);


//Vérification de l'ouverture du handle
    if (handleSerial==INVALID_HANDLE_VALUE)
    {
        res=GetLastError();
        fprintf(stderr,"Code retour %s %d\n",i_NomPort,res);
        return res ;
    }


//Lecture configuration initiale
    if (!GetCommState(handleSerial, &dcb))
    {
        res=-1;
        return res;
    }


//Configuration du port
//Gestion de la vitesse
    dcb.BaudRate=CBR_9600;
//Gestion du nombre de bits
    dcb.ByteSize=8;
//Gestion de la parité
    dcb.Parity=EVENPARITY;

//Gestion du Stop Bit
    dcb.StopBits=ONESTOPBIT;

    dcb.DCBlength=2048;
    dcb.fBinary=1;
    dcb.fParity=1;
    dcb.fOutxCtsFlow=0;
    dcb.fOutxDsrFlow=0;
    dcb.fDtrControl=0;
    dcb.fDsrSensitivity=0;
    dcb.fTXContinueOnXoff=0;
    dcb.fRtsControl=0;

    if (!SetCommState(handleSerial, &dcb))
    {
        res=-2;
        return res;
    }

    // configurer le timeout
    COMMTIMEOUTS tTimeout;
    tTimeout.ReadIntervalTimeout = MAXWORD;
    tTimeout.ReadTotalTimeoutMultiplier = 0;
    tTimeout.ReadTotalTimeoutConstant = 500 ; // pas de time out = 0
    tTimeout.WriteTotalTimeoutMultiplier = 0;
    tTimeout.WriteTotalTimeoutConstant = 0;
    SetCommTimeouts(handleSerial,&tTimeout);

    return res ;
};

int C_PortSerie::close()
{
    int res = 0 ;
    res = CloseHandle(handleSerial);
    return res ;
};

int C_PortSerie::send( char * i_Chaine)
{
    int res = 0 ;
    unsigned long nBytesWritten = 1 ;

    fprintf(stderr,"Chaine à envoyer %s\n",i_Chaine);
    res=WriteFile(handleSerial,i_Chaine,strlen(i_Chaine),&nBytesWritten,NULL);
    fprintf(stderr,"Nombre de bytes envoyés %d\n",(int) nBytesWritten);

    return res ;
};

int C_PortSerie::receive( char * o_chaine)
{
    int res = 0 ;
    unsigned long nBytesRead = 0 ;

    res=ReadFile(handleSerial,o_chaine,199,&nBytesRead,NULL);

    if (nBytesRead!=0) // Il existe des octets lus
    {
        res=0;
    }
    else
    {
        res=-1;
    }
    return res ;
};
