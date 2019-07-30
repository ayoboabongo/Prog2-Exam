#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

int main()
{
    ouvrage ov;
    Abonne x;
    Abr A;
    int choix,n,code;
    int code_ouv,num;
    do
    {
        printf("*****Menu*****\n");
        printf("1-Saisir Ouvrage\n");
        printf("2-Pemplir Bibliotheque\n");
        printf("3-Saisir Abonne\n");
        printf("4-Inserer abonne\n");
        printf("5-Chercher ouvrage\n");
        printf("6-Chercher abonne\n");
        printf("7-Ajouter Ouvrage\n");
        printf("8-Emprunter Ouvrage\n");
        printf("9-Afficher Abonne\n");
        printf("10-Afficher Arbre\n");
        printf("0-Quitter\n");
        printf("Veuillez entrer votre choix\n");
        scanf("%d",&choix);

        switch(choix)
        {
            case 1 :
        ov=Saisir_ouvrage();
        break;
    case 2 :
        printf("Veuillez entrer le nombre d'ouvrage\n");
        scanf("%d",&n);
        Remplir_bibio("biblio.bin",n);
        break;
    case 3 :
        Saisir_Abonne(&x);
        break;
    case 4 :
        Saisir_Abonne(&x);
        A=Inserer_abonne(A,x);
        break;
    case 5 :
        printf("Veuillez entrer le code de l'ouvrage\n");
        scanf("%d",&code);
        ov=chercher_ouvrage("biblio.bin",code);
        break;
    case 6 :
        break;
    case 7 :
        ov=Saisir_ouvrage();
        x=Ajouter_ouvrage(x,ov);
        break;
    case 8 :
        printf("Veuillez entrer le code de l'ouvrage \n");
        scanf("%d",&code_ouv);
        printf("Veuillez entrer le numero d'abonnement\n");
        scanf("%d",&num);
        Emprunter_ouvrage(A,code_ouv,num);
        break;
    case 9 :
        Afficher_Abonne(x);
        break;
    case 10 :
        Afficher_ABR (A);
        break;

        }

    }while(choix!=0);

    return 0;
}
