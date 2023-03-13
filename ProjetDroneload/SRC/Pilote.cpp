#include "Pilote.h"
#include "Camera.h"
#include "Radio.h"


extern C_Radio MyRadio ;
using namespace cv;
using namespace std;

C_Pilote::C_Pilote()
{
    m_state = IDLE ;

    m_TakeOffProfile.Load((char*) "TakeOff.txt") ;
    m_LandingProfile.Load((char*) "Landing.txt") ;

}

C_Pilote::~C_Pilote()
{
    //dtor
}

void C_Pilote::Takeoff()
{
    fprintf ( stderr, "Take OFF\n" );
    if (m_state != IDLE )
    {
        fprintf(stderr,"Take off impossible car déjà en vol\n");
        return ;
    }
    m_state = TAKINGOFF ;
    m_TakeOffProfile.Play() ;
    m_state = INFLIGHT ;
}

void C_Pilote::Landing()
{
    fprintf ( stderr, "Landing\n" );
    m_state = LANDING ;
    m_LandingProfile.Play() ;
    m_state = IDLE ;
}





