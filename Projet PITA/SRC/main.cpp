/***************************************************************
 * Name:      main.cpp
 * Purpose:   Code for Application Class
 * Author:    Gabriel ()
 * Created:   2022-10-30
 * Copyright: Gabriel ()
 * License:
 **************************************************************/

#include "main.h"
#include "Radio.h"
#include "Camera.h"

//(*AppHeaders
#include "MainFrame.h"
//*)


C_Radio MyRadio ;
C_Camera MyCamera  ;
MainFrame* Frame = NULL ;

void * RunCamera(void *threadid)
{
    MyCamera.Run() ;
    pthread_exit(NULL);
    return NULL ;
} ;

void * RadioListening(void *threadid)
{
    MyRadio.Listen() ;
    pthread_exit(NULL);
    return NULL ;
} ;

void * RadioSending(void *threadid)
{
    MyRadio.Send() ;
    pthread_exit(NULL);
    return NULL ;
} ;

void * RefreshIHM(void *threadid)
{
    while (true )
    {
        Frame->SpecialUpdateIHM();
        Sleep(20);
    }
    pthread_exit(NULL);
    return NULL ;
} ;




IMPLEMENT_APP(XVApp);


bool XVApp::OnInit()
{

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        Frame = new MainFrame(0);
        Frame->Show();
        Frame->Update();
        SetTopWindow(Frame);
    }
    //*)

    if ( pthread_create ( &MyCamera.m_CameraThread, NULL, RunCamera, NULL ) )
    {
        std::cerr << "Impossible de cr�er le thread Camera\n" ;
        exit ( -1 );
    }

    if ( pthread_create( & MyRadio.m_ListeningThread, NULL, RadioListening, NULL) )
    {
        std::cerr << "Impossible de cr�er le thread d'ecoute Radio\n" ;
        exit ( -1 );
    }

    if ( pthread_create( & MyRadio.m_SendingThread, NULL, RadioSending, NULL) )
    {
        std::cerr << "Impossible de cr�er le thread d'envoi Radio\n" ;
        exit ( -1 );
    }

    pthread_t MyIhmThread;
    if ( pthread_create( & MyIhmThread, NULL, RefreshIHM, NULL) )
    {
        std::cerr << "Impossible de cr�er le thread de rafraichissement IHM\n" ;
        exit ( -1 );
    }

    return wxsOK;

}
