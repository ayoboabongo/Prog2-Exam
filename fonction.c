#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>


ouvrage Saisir_ouvrage()
{
    ouvrage ov;
    printf("Code\n");
    scanf("%d",&ov.code);
    printf("Titre\n");
    scanf("%s",ov.titre);

    return ov;
}

void Remplir_bibio(char nomfich[], int n)
{
    ouvrage ov;
    int i;
    FILE *fichier;
    fichier=fopen(nomfich,"ab");
    if(fichier!=NULL)
    {
        for(i=0;i<n;i++)
        {
            ov=Saisir_ouvrage();
            fwrite(&ov,sizeof(ouvrage),1,fichier);

        }
        fclose(fichier);
    }
    else
        printf("erreur d'ouverture du fichier\n");
}

void Saisir_Abonne(Abonne* x)
{
    printf("Numero d'inscription\n");
    scanf("%d",&(*x).num);
    printf("Nom\n");
    scanf("%s",(*x).nom);
    (*x).l=NULL;
}

Abr initialiser(Abonne x)
{
    Abr A;
    struct Noeud* nouv;
        nouv=(struct Noeud*)malloc(sizeof(struct Noeud));
        if(nouv!=NULL)
        {
            nouv->x=x;
            nouv->FG=NULL;
            nouv->FD=NULL;
            A=nouv;
        }
        else
            printf("allocation non effectuee\n");

   return A;
}

Abr Inserer_abonne(Abr A, Abonne x)
{
    struct Noeud* nouv;
   if(A==NULL)
   {
     A=initialiser(x);
   }
   else
   {
       if(nouv->x.num<=A->x.num)
        A->FG=Inserer_abonne(A->FG,x);

       else
        A->FD=Inserer_abonne(A->FD,x);
   }

   return A;
}

ouvrage chercher_ouvrage(char nomfich[], int code)
{
    ouvrage ov;
    FILE *fichier;
    fichier=fopen(nomfich,"rb");
    if(fichier!=NULL)
    {
        while(!feof(fichier))
        {
            fread(&ov,sizeof(ouvrage),1,fichier);

            if(ov.code==code)
                return ov;

            else
               ov.code=-1;
        }
        fclose(fichier);
    }
    else
        printf("erreur d'ouverture du fichier\n");

    return ov;

}

Abr chercher_Abonne(Abr A, int num)
{
    if(A!=NULL)
    {
        if(A->x.num==num)
        {
            return A;
        }
        else
        {
            if(A->x.num>num)
            {
                A=chercher_Abonne(A->FG,num);
                return A;

            }
            else
            {
                A=chercher_Abonne(A->FD,num);
                return A;

            }
        }

    }
    else
        return NULL;
}

Abonne Ajouter_ouvrage(Abonne x, ouvrage ov)
{
    struct cellule *nouv,*parc;
    nouv=(struct cellule*)malloc(sizeof(struct cellule));
    if(nouv!=NULL)
    {
        nouv->ov=ov;
        nouv->suivant=NULL;
        if(x.l==NULL)
        {
            x.l=nouv;
        }
        else
        {
            parc=x.l;
            while(parc->suivant!=NULL)
                parc=parc->suivant;

            parc->suivant=nouv;

        }
    }
    else
        printf("allocation non effectuee\n");

    return x;

}

void Emprunter_ouvrage(Abr A, int code_ouv, int num)
{
    ouvrage ov;
    Abonne x;
    ov=chercher_ouvrage("biblio.bin",code_ouv);
    if(ov.code!=-1)
    {
       A=chercher_Abonne(A,num);
       if(A!=NULL)
       {
           x=Ajouter_ouvrage(x,ov);
       }
       else
        printf("Abonne non trouve\n");

    }
    else
        printf("L'ouvrage n'existe pas\n");

}

void Afficher_Abonne(Abonne x)
{
        printf("\nNumero : %d \nNom : %s",x.num,x.nom);
        while(x.l!=NULL)
        {
            printf("\n Code :%d \nTitre : %s",x.l->ov.code,x.l->ov.titre);
        }

}

void Afficher_ABR (Abr A)
{
    if(A!=NULL)
    {
        Afficher_ABR(A->FD);
        Afficher_Abonne(A->x);
        /*printf("\nNumero : %d \nNom : %s",A->x.num,A->x.nom);
        while(A->x.l!=NULL)
        {
            printf("\n Code :%d \nTitre : %s",A->x.l->ov.code,A->x.l->ov.titre);
        }*/
        Afficher_ABR(A->FG);

    }

}
