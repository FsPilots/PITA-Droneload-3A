#ifndef C_PortSerie_H
#define C_PortSerie_H

#include <windows.h>

class C_PortSerie
{
private:
    HANDLE handleSerial;

public:
    C_PortSerie();
    C_PortSerie( char * i_NomPort );
    ~C_PortSerie();
    int open( char * i_NomPort );
    int close();
    bool IsOpened() ;

    template<typename Type> int send( Type i_value )
    {
        int res = 0 ;
        unsigned long nBytesWritten = 1 ;
        // fprintf(stderr,"Byte à envoyer %d\n",i_byte);
        res = WriteFile( handleSerial, &i_value, sizeof( i_value ), &nBytesWritten, NULL );
        return res ;
    }

    int send( char * i_Chaine );


    template<typename Type> int receive( Type o_value )
    {
        int res = 0 ;
        unsigned long nBytesRead = 0 ;
        res = ReadFile( handleSerial, o_value, sizeof( o_value ), &nBytesRead, NULL );
        if( nBytesRead != 0 ) // Il existe des octets lus
        {
            res = 0;
        }
        else
        {
            res = -1;
        }
        return res ;
    };

    int receive( char * o_Chaine );
};

#endif /* C_PortSerie_H */
