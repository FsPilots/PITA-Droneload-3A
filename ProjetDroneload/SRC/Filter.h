#ifndef FILTER_h
#define FILTER_h

class C_Filter
{
public:
    C_Filter();
    void Setup( unsigned long iK );
    float FilteredValue ( unsigned long iTime, float iConsigne );

private:
    bool First ;
    unsigned long K ;
    unsigned long LastTime ;
    float LastValue ;
};
#endif
