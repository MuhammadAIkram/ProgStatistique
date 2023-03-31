#ifndef ETUDESTATISTIQUE1D_H
#define ETUDESTATISTIQUE1D_H

#include <iostream> 
#include "DataSource1D.h"
#include <cmath>

using namespace std;

class EtudeStatistiques1D
{
    private:
        float moyenne;
        float mediane;
        int mode[3];
        float ecartType;
        float coefDeVariation;
        int Etendue;
    public:
        EtudeStatistiques1D(DataSource1D data);
        ~EtudeStatistiques1D();

        float getMoyenne() const;
        float getMediane() const;
        int * getMode();
        float getS();
        float getCV();
        int getRange();

        void calculeMoyenne(int, int *);
        void calculeMediane(int, int *);
        void calculeMode(int *);
        void calculeS(int, int*);
        void calculeCV();
        void calculeRange();

        void Affiche();
};

#endif