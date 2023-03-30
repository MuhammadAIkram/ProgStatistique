#ifndef ECHANTILLON_H
#define ECHANTILLON_H

#include <iostream> 
#include <string>
#include <fstream>
#include <string.h>

#include "DataSource1D.h"
#include "EtudeStatistiques1D.h"

using namespace std;

class Echantillon
{
    public:
        Echantillon(string nomFichier);
        ~Echantillon();
};

#endif