#ifndef DATASOURCE1D_H
#define DATASOURCE1D_H

#include <iostream> 

using namespace std;

class DataSource1D 
{
    private:
        int vec[10];
        int EffectifTotal;
        int min;
        int max;
    public:
        DataSource1D(void);
        ~DataSource1D();

        int getEffectifTotal() const;
        int * getVecteur();

        int getMin() const;
        int getMax() const;

        void IncrementeCase(int val);
};

#endif