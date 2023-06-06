#include "EtudeStatistiques1D.h"

//----------------------------------------------------------------------------------
//---------		CONSTRUCTEURS
//----------------------------------------------------------------------------------

EtudeStatistiques1D::EtudeStatistiques1D(DataSource1D data)
{
    /*
    cout << "Recu:" << endl << "Effectif Total:" << data.getEffectifTotal() << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << i+1 << " = " << data.getVecteur()[i] << endl;
    }
    */

    //pour calculer notre moyenne
    calculeMoyenne(data.getEffectifTotal(), data.getVecteur());

    //pour calculer notre mediane
    calculeMediane(data.getEffectifTotal(), data.getVecteur());

    //pour calculer le mode

    //premierement on va mettre des valeur par defaut a l'interieur du mode
    mode[0] = -1;
    mode[1] = -1;
    mode[2] = -1;

    calculeMode(data.getVecteur());

    //calculer l'ecart-type
    calculeS(data.getEffectifTotal(), data.getVecteur());

    //calcule variation
    calculeCV();

    //calcule Etendue
    calculeRange(data.getMin(), data.getMax());

    //fait l'affichage
    Affiche();
}

//----------------------------------------------------------------------------------
//---------		DESTRUCTEURS
//----------------------------------------------------------------------------------

EtudeStatistiques1D::~EtudeStatistiques1D()
{

}

//----------------------------------------------------------------------------------
//---------		SETTER
//----------------------------------------------------------------------------------

void EtudeStatistiques1D::calculeMoyenne(int efftotal, int *vec)
{
    int total = 0;

    for(int i = 1; i <= 10; i++)
    {
        total = total + (i*vec[i-1]);
    }

    moyenne = (float)total/efftotal;

    //cout << "Moyenne = " << moyenne << endl;
}

void EtudeStatistiques1D::calculeMediane(int efftotal, int *vec)
{
    int vecVal[50];

    int i = 0;
    int val = 1;

    //nous refais le vecteur avec les valeurs tout separer mais c'est en ordres
    while(i < efftotal)
    {
        int j = 0;

        while(j < vec[val-1])
        {
            vecVal[i] = val;

            j++;
            i++;
        }

        val++;
    }

    //calcule la mediane
    if(efftotal%2 != 0)
    {
        int i = (efftotal+1)/2;

        mediane = vecVal[i-1];
    }
    else
    {
        int i = efftotal/2;

        mediane = (float)(vecVal[i-1] + vecVal[i])/2;
    }

    //cout << "Mediane = " << mediane << endl;
}

void EtudeStatistiques1D::calculeMode(int *vec)
{
    int max = -1;

    //trouve le max
    for(int i = 0; i < 10; i++)
    {
        if(vec[i] > max) max = vec[i];
    }

    //met les maximum valeurs dans notre vecteur mode
    for(int i = 0, j = 0; i < 10 && j < 3; i++)
    {
        if(max == vec[i])
        {
            mode[j] = i+1;
            j++;
        }
    }

    /*
    int i = 0;

    while(mode[i] != -1 && i < 3)
    {
        cout << "Mode " << i << ": " << mode[i] << endl;
        i++;
    }
    */
}

void EtudeStatistiques1D::calculeS(int efftotal, int *vec)
{
    int vecVal[50];

    int i = 0;
    int val = 1;

    //nous refais le vecteur avec les valeurs tout separer mais c'est en ordres
    while(i < efftotal)
    {
        int j = 0;

        while(j < vec[val-1])
        {
            vecVal[i] = val;

            j++;
            i++;
        }

        val++;
    }

    //calculer l'ecart-type

    float somme = 0.0;
    
    for(i = 0; i < efftotal; i++)
    {
        somme = somme + pow((vecVal[i] - moyenne), 2);
    }

    ecartType = sqrt(somme/efftotal);

    //cout << "Ecart-type = " << ecartType << endl;
}

void EtudeStatistiques1D::calculeCV()
{
    coefDeVariation = ecartType/moyenne;

    //cout << "Coefficient de variation = " << coefDeVariation << endl;
}

void EtudeStatistiques1D::calculeRange(int min, int max)
{
    Etendue = max - min;

    //cout << "Etendue = " << Etendue << " Valeur min/max = " << min << "/" << max <<  endl;
}

//----------------------------------------------------------------------------------
//---------		GETTER
//----------------------------------------------------------------------------------

float EtudeStatistiques1D::getMoyenne() const { return moyenne; }

float EtudeStatistiques1D::getMediane() const { return mediane; }

int * EtudeStatistiques1D::getMode() { return mode; }

float EtudeStatistiques1D::getS() {return ecartType; }

float EtudeStatistiques1D::getCV() { return coefDeVariation; }

int EtudeStatistiques1D::getRange() { return Etendue; }

//----------------------------------------------------------------------------------
//---------		AUTRES METHODES
//----------------------------------------------------------------------------------

void EtudeStatistiques1D::Affiche()
{
    cout << endl << "-----------------------------------------------------------------------------" << endl;
    cout << "VOICI L'ETUDE STATISTIQUE: " << endl;
    cout << "Moyenne: " << getMoyenne() << endl;
    cout << "Mediane: " << getMediane() << endl;
    int i = 0;
    while(getMode()[i] != -1 && i < 3)
    {
        cout << "Mode " << i+1 << ": " << mode[i] << endl;
        i++;
    }
    cout << "Ecart-Type: " << getS() << endl;
    cout << "Coefficient de variation : " << getCV() << " (" << getCV()*100 << "%)" << endl;
    cout << "Etendue: " << getRange() << endl;
    cout << "-----------------------------------------------------------------------------" << endl << endl;
}