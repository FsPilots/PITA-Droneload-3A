#ifndef C_PortSerie_H
#define C_PortSerie_H

#include <windows.h>
#include <stdio.h>

#define BUFFIN 1
#define BUFFOUT 2

class C_PortSerie
{
private:
    HANDLE handleSerial;
    DCB dcb;                //Configuration du port

public:
    C_PortSerie();
    C_PortSerie ( char * i_NomPort );
    ~C_PortSerie();
    int open ( char * i_NomPort );
    int close();
    bool IsOpened() ;
    int send ( unsigned char i_value ) ;
    unsigned char receive( ) ;
    void flush ( int i_sens ) ;
};

#endif /* C_PortSerie_H */
