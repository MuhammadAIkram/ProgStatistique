#include "DataSource1D.h"

//----------------------------------------------------------------------------------
//---------		CONSTRUCTEURS
//----------------------------------------------------------------------------------

DataSource1D::DataSource1D(void)
{
    for(int i = 0; i < 10; i++)
    {
        vec[i] = 0;
    }

    EffectifTotal = 0;
    min = 10;
    max = 0;
}

//----------------------------------------------------------------------------------
//---------		DESTRUCTEURS
//----------------------------------------------------------------------------------

DataSource1D::~DataSource1D()
{

}


//----------------------------------------------------------------------------------
//---------		GETTER
//----------------------------------------------------------------------------------

int DataSource1D::getEffectifTotal() const { return EffectifTotal; }

int * DataSource1D::getVecteur() { return vec; }

int DataSource1D::getMin() const { return min; }

int DataSource1D::getMax() const { return max; }

//----------------------------------------------------------------------------------
//---------		AUTRES METHODES
//----------------------------------------------------------------------------------

void DataSource1D::IncrementeCase(int val)
{
    vec[val-1] = vec[val-1] + 1;

    if(val > max) max = val;
    else if(val < min) min = val;

    EffectifTotal++;
}