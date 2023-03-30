#ifndef ETUDESTATISTIQUE1D_H
#define ETUDESTATISTIQUE1D_H

#include <iostream> 
#include "DataSource1D.h"

using namespace std;

class EtudeStatistiques1D
{
    private:
        float moyenne;
        float mediane;
        int mode[3];
    public:
        EtudeStatistiques1D(DataSource1D data);
        ~EtudeStatistiques1D();

        float getMoyenne() const;
        float getMediane() const;
        int * getMode();

        void calculeMoyenne(int, int *);
        void calculeMediane(int, int *);
        void calculeMode(int *);

        void Affiche();
};

#endif