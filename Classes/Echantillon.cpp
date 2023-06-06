#include "Echantillon.h"

//----------------------------------------------------------------------------------
//---------		CONSTRUCTEURS
//----------------------------------------------------------------------------------

Echantillon::Echantillon(string nomFichier)
{
    cout << "Nom du Fichier: " << nomFichier << endl;

    int choix = 0;

    while(choix != 4)
    {
        cout << "Menu: " << endl;
        cout << "1 - Pistes" << endl;
        cout << "2 - Remontees" << endl;
        cout << "3 - Commerces" << endl;
        cout << "4 - Exit" << endl;
        cout << "Choix: ";
        cin >> choix;

        if(choix < 4)
        {
            ifstream fichier(nomFichier,ios::in);

            string buffer;
            char *chaine;
            char *token;
            int val;
            DataSource1D data;

            getline(fichier, buffer);

            while(getline(fichier, buffer))
            {
                //cout << "Voici la chaine lue:" << endl << buffer << endl;

                chaine = new char[buffer.size() + 1];

                strcpy(chaine, buffer.c_str());

                //cout << "Voici la chaine lue:" << endl << chaine << endl << endl;

                //cout << "Voici la chaine decomposer" << endl;

                token = strtok(chaine, ";");

                int i = 1;

                while(i <= choix)
                {
                    token = strtok(NULL, ";");
                    i++;
                }

                val = atoi(token);

                data.IncrementeCase(val);

                //cout << " - " << val << " - " << endl;

                delete chaine;
            }

            /*
            for(int i = 0; i < 10; i++)
            {
               cout << i+1 << " = " << data.getVecteur()[i] << endl;
            }

            cout << endl << "Voici l'effectif total: " << data.getEffectifTotal() << endl;
            */

            EtudeStatistiques1D etude(data);

            fichier.close();
        }

        //cout << "Votre choix: " << choix << endl << endl;
    }
}

//----------------------------------------------------------------------------------
//---------		DESTRUCTEURS
//----------------------------------------------------------------------------------

Echantillon::~Echantillon()
{

}