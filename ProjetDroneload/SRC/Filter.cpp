#include "Filter.h"
#include <math.h>

C_Filter::C_Filter()
{
    First = true;
};

void C_Filter::Setup( unsigned long iK )
{
    K = iK ;
};

float C_Filter::FilteredValue( unsigned long iTime, float iInputValue )
{
    float res = 0. ;
    float alpha = 0. ;
    if( !First )
    {
        if( iTime < LastTime )
        {
            res = LastValue ;
        }
        else
        {
            if( K > 0 )
            {
                alpha = exp( - ( float )( iTime - LastTime ) / ( float ) K );
            }
            else
            {
                alpha = 0. ;
            }
        }
        res = alpha * LastValue + ( 1. - alpha ) * iInputValue ;
    }
    else
    {
        First = false;
        res = iInputValue;
    }
    LastTime = iTime;
    LastValue = res;
    return res ;
};
