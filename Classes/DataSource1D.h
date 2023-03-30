#ifndef DATASOURCE1D_H
#define DATASOURCE1D_H

#include <iostream> 

using namespace std;

class DataSource1D 
{
    private:
        int vec[10];
        int EffectifTotal;
    public:
        DataSource1D(void);
        ~DataSource1D();

        int getEffectifTotal() const;
        int * getVecteur();

        void IncrementeCase(int val);
};

#endif