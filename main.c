//
//  main.c
//  cours langage C
//
//  Created by TEHE on 21/02/2017.
//  Copyright � 2017 Middlay Production. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function g�n�ratrice du nombre al�atoire

int niveau(int nombreMaximum,int min){
    int nombreAleatoir = 0;
    srand(time(NULL));
    nombreAleatoir = (rand() % (nombreMaximum - min + 1)) + min;
    return nombreAleatoir;
}


int main ( int argc, char** argv )
{
    int nombreMystere1 = 0;
    int nombreMystere2 = 0;
    int nombreMystere3 = 0;
    int nombreEntre = 0;
    int choix = 0;
    int compteur = 1;
    int continuerPartie = 0;
    continuerPartie = 1;

    // G�n�ration du nombre al�atoire

    nombreMystere1 = niveau(100, 1) ;
    nombreMystere2= niveau(1000, 1);
    nombreMystere3 = niveau(10000, 1);



    /* Cette boucle devra se r�p�ter TANT QUE l'utilisateur n'a pas demand� � arr�ter le programme*/

    while (continuerPartie) {


        /* La boucle du programme. Elle se r�p�te tant que l'utilisateur n'a pas trouv� le nombre
         myst�re */

        do{
            // On demande le niveau de jeux

            printf("*----- Choisissez votre niveau de jeux -----*\n\n");
            printf("1.Niveau 1\n");
            printf("2.Niveau 2\n");
            printf("3.Niveau 3\n");

            scanf("%d",&choix);


            switch (choix)
            {
                case 1:
                    choix= nombreMystere1;
                    printf("Trouver un nombre entre 1 et 100\n\n");
                    break;
                case 2:
                    choix = nombreMystere2 ;
                    printf("Trouver un nombre %d entre 1 et 1000\n\n",choix);
                    break;
                case 3:
                    choix = nombreMystere3;
                    printf("Trouver un nombre entre 1 et 10000\n\n");

                    break;
                default:
                    printf("Votre choix n'est pas dans la liste \n\n");
                    break;
            }

        }while (!choix);

        /* La boucle du programme. Elle se r�p�te tant que l'utilisateur n'a pas trouv� le nombre myst�re */

        do
        {

        // On demande le nombre avec indication du nombre du coups � l'essai

            printf("Pour votre essai n�%d. Quel est le nombre ? \n", compteur++);
            scanf("%d", &nombreEntre);


            // On compare le nombre entr� avec le nombre myst�re

            if (choix > nombreEntre){
              printf("C'est %d plus !\n\n",choix);
            }else if (choix < nombreEntre){
                printf("C'est moins !\n\n");
            }
            else{
                printf ("Bravo, vous avez trouve le nombre mystere en %d coups!!!\n\n",compteur);
            }

        } while (nombreEntre != choix);
        /*r�initialisation du compteur de nombre de coups d'�ssai */

        compteur = 1 ;

        /* Menu d'invitation a contniuer le jeux */

        printf("*------ Souhaitez-vous faire une nouvelle partie ? ------*\n\n");
        printf("*------ Taper 1 pour OUI ------*\n");
        printf("*------ Taper 0 pour NON ------*\n");
        scanf("%d",&continuerPartie);
    }
    return 0;
}
