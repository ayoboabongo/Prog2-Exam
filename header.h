#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct ouvrage
{
   int code;
   char titre[25];
}ouvrage;

typedef struct cellule
{
    ouvrage ov;
    struct cellule* suivant;
}cellule;
typedef struct cellule* liste;

typedef struct Abonne
{
    int num;
    char nom[25];
    liste l;
}Abonne;

typedef struct Noeud
{
    Abonne x;
    struct Noeud* FG;
    struct Noeud* FD;
}Noeud;
typedef struct Noeud* Abr;

ouvrage Saisir_ouvrage();
void Remplir_bibio(char nomfich[], int n);
void Saisir_Abonne(Abonne* x);
Abr Inserer_abonne(Abr A, Abonne x);
ouvrage chercher_ouvrage(char nomfich[], int code);
Abr chercher_Abonne(Abr A, int num);
Abonne Ajouter_ouvrage(Abonne x, ouvrage ov);
void Emprunter_ouvrage(Abr A, int code_ouv, int num);
void Afficher_Abonne(Abonne x);
void Afficher_ABR (Abr A);


#endif // HEADER_H_INCLUDED
