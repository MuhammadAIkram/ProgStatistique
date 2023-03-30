#include <iostream>
using namespace std;

#include "DataSource1D.h"

int main()
{
    cout << "Hello world" << endl;

    DataSource1D data1;

    cout << "Voici le effectif: " << data1.getEffectifTotal() << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << i << " = " << data1.getVecteur()[i] << endl;
    }

    data1.IncrementeCase(1);

    cout << endl << endl;
    
    for(int i = 0; i < 10; i++)
    {
        cout << i << " = " << data1.getVecteur()[i] << endl;
    }
}