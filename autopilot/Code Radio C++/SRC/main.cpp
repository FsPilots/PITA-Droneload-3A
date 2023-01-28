/***************************************************************
 * Name:      main.cpp
 * Purpose:   Code for Application Class
 * Author:    Gabriel ()
 * Created:   2022-10-30
 * Copyright: Gabriel ()
 * License:
 **************************************************************/

#include "main.h"

//(*AppHeaders
#include "MainFrame.h"
//*)

#include "Camera.h"

IMPLEMENT_APP(XVApp);

void *RunCamera(void *threadid)
{
   C_Camera * MyCamera = new C_Camera() ;
   MyCamera->Run() ;
   pthread_exit(NULL);
   return NULL ;
}

bool XVApp::OnInit()
{

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	MainFrame* Frame = new MainFrame(0);
    	Frame->Show();
    	Frame->Update();
    	SetTopWindow(Frame);
    	Frame->UpdateIHM();
    }
    //*)

    pthread_t threads;
    int rc;
    void * t = NULL;
    rc = pthread_create(&threads, NULL, RunCamera, t);
    if (rc)
    {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    }

    return wxsOK;

}
