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
#include "Pilote.h"

//(*AppHeaders
#include "MainFrame.h"
//*)


C_Radio MyRadio ;
C_Camera MyFrontCamera  ;
C_Camera MyBottomCamera  ;
C_Pilote MyPilot;
MainFrame* Frame = NULL ;

void * RunFrontCamera(void *threadid)
{
   int OK = MyFrontCamera.Setup(0,FRONT,(char*) "Front") ;
   if (OK != -1) MyFrontCamera.Run() ;
   pthread_exit(NULL);
   return NULL ;
} ;

void * RunBottomCamera(void *threadid)
{
   int OK = MyBottomCamera.Setup(2,BOTTOM,(char*) "Bottom") ;
   if (OK != -1) MyBottomCamera.Run() ;
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

    if ( pthread_create ( &MyFrontCamera.m_CameraThread, NULL, RunFrontCamera, NULL ) )
    {
        std::cerr << "Impossible de créer le thread FrontCamera\n" ;
        exit ( -1 );
    }

    if ( pthread_create ( &MyBottomCamera.m_CameraThread, NULL, RunBottomCamera, NULL ) )
    {
        std::cerr << "Impossible de créer le thread BottomCamera\n" ;
        exit ( -1 );
    }

    if ( pthread_create( & MyRadio.m_ListeningThread, NULL, RadioListening, NULL) )
    {
        std::cerr << "Impossible de créer le thread d'ecoute Radio\n" ;
        exit ( -1 );
    }

    if ( pthread_create( & MyRadio.m_SendingThread, NULL, RadioSending, NULL) )
    {
        std::cerr << "Impossible de créer le thread d'envoi Radio\n" ;
        exit ( -1 );
    }

    pthread_t MyIhmThread;
    if ( pthread_create( & MyIhmThread, NULL, RefreshIHM, NULL) )
    {
        std::cerr << "Impossible de créer le thread de rafraichissement IHM\n" ;
        exit ( -1 );
    }

    return wxsOK;

}
