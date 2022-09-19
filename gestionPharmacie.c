


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




typedef struct
{
    int quantite;
    char code[15],nom[15];
    float prix,prixTTC;

}Produit;

void Ajouter(Produit p[],int *poi);
void AjouterPlusieurs(Produit p[],int *poi);
void Afficher(Produit p[50],int nben);
void croissant_nom(Produit p[],int nben);
void decroissant_prix(Produit p[],int nben);
void AcheterProduit(Produit p[],int nben);

void make_tolower(char s[])
{
  int length = strlen(s);
  for (int i=0;i<length;i++)
    {
      s[i]=tolower(s[i]);
    }
}

int n,i,nben=0,choix,ech;

Produit p[50];

int main()
{
    int *poi;
 poi=&nben;

    do
    {

             //system("cls");
        printf("\t\t\t\t\n:::::::::::::::::::::::::: Menu Principale ::::::::::::::::::::::::::\n\n");
        printf("\t\t\t 1- Ajouter un produit  \n");
        printf("\t\t\t 2- Ajouter plusieurs produits  \n");
        printf("\t\t\t 3- Afficher les produits\n");
        printf("\t\t\t 4- Acheter produit \n");
        printf("\t\t\t 5- Rechercher les produits \n");
        printf("\t\t\t 6- Etat du stock\n");
        printf("\t\t\t 7- Alimenter le stock\n");
        printf("\t\t\t 8- Supprimer les produits \n");
        printf("\t\t\t 9- Statistique de vente\n");
        printf("\t\t\t 10-Quitter le programme \n");



        do
        {
            printf("\tVeuillez entree Votre choix : \t");
            scanf("%d",&choix);
             if(choix<1 || choix>10)
                printf(" Attention Votre Choix doit Etre Compris Entre 1 et 10 \n");

        }while(choix<1 || choix>10);
        switch(choix)
        {
        case 1:
            {
                Ajouter(p,poi);

            }break;
        case 2:
            {
           AjouterPlusieurs(p,poi);

            }break;

        case 3:
            {
               // Afficher(p,nben);
               do
               {
                    printf("\t\t\t 1- Lister les produits selon l�ordre alphabetique croissant du nom \n");
                    printf("\t\t\t 2- Lister les produits selon l�ordre decroissant du prix.  \n");
                    printf("\t\t\t 3- Menu Principale  \n");
                   do
                 {
            printf("\tVeuillez entree Votre choix : \t");
            scanf("%d",&choix);
             if(choix<1 || choix>3)
                printf(" Attention Votre Choix doit Etre Compris Entre 1 et 3 \n");

                 }while(choix<1 || choix>3);
                 switch(choix)
                 {
                     case 1:
                     {
                         croissant_nom(p,nben);

                     }break;
                     case 2:
                     {
                        decroissant_prix(p,nben);

                     }break;
                     default:
                     {

                     }break;
                 }


               }while(choix !=3);


            }break;

        case 4:
            {
                 AcheterProduit(p,nben);


            }break;
        case 5:
            {

            }break;
        case 6:
            {


            }break;
        case 7:
            {


            }break;
       case 8:
            {


            }break;
       case 9:
            {


            }break;
        default:
        break;




        }



    }while(choix!=10);

    return 0;
}

void Ajouter(Produit p[],int *poi)
{
    int i=*poi;
    printf("Veuillez entrre le code :\t");
    scanf("%s",p[i].code);
    printf("Veuillez entrre le nom de produit :\t");
    //scanf("%s",make_tolower(p[i].nom));
    scanf("%s",p[i].nom);
    make_tolower(p[i].nom);
   printf("%s",p[i].nom);

    //char x_nom[]=p[i].nom;
   // make_tolower(x_nom);
     printf("Veuillez entrre la quantite :\t");
    scanf("%d",&p[i].quantite);
     printf("Veuillez entrre le prix :\t");
    scanf("%f",&p[i].prix);
    (*poi)++;
}
void AjouterPlusieurs(Produit p[],int *poi)
{
      do{
     printf(" Veuillez entree le nombre d'enregistrement:\t");
     scanf("%d",&n);
     if(n<1 || n>50)
     printf("le nombre d'enregistrement doit etre comprit entre 1 et 50\n");
    }while(n<1 || n>50);

  int a=*poi;
   // for(i=*poi;i<n;i++)
    for(i=a;i<a+n;i++)
    {
    printf("entrre les info de produit %d :\t\n",i+1);
    printf("Veuillez entrre le code produit :\t");
    scanf("%s",p[i].code);
    printf("Veuillez entrre le nom de produit :\t");
    scanf("%s",p[i].nom);
    printf("Veuillez entrre la quantite :\t");
    scanf("%d",&p[i].quantite);
     printf("Veuillez entrre le prix :\t");
    scanf("%f",&p[i].prix);
    (*poi)++;
    }
}

void Afficher(Produit p[50],int nben)
{

    printf(" nben = %d\n",nben);
    //printf("holla");
    for( i=0;i<nben;i++)
    {
    printf("les info de produit %d :\t\n",i+1);
    printf(" Code : %s \tNom: %s\t Quantite : %d Prix : \t %.2f DH  :\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
    }
}
void croissant_nom(Produit p[],int nben)
{
    do
    {
        ech=0;
        for(i=0;i<nben;i++)
        {
            if(strcmp(p[i+1].nom,p[i].nom)>0)
            {
                Produit tmp;
                tmp=p[i+1];
                p[i+1]=p[i];
                p[i]=tmp;
                ech++;

            }
        }
    }while(ech>0);


    printf("***************affichage les produits selon ordre alphabetique croissant du nom****************\n");
    for(i=0;i<nben;i++)
    {
     printf(" Code : %s \tNom: %s\t Quantite : %d\t Prix : \t %.2f DH  :\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix);

    }
}

    void decroissant_prix(Produit p[],int nben)
{
    do
    {
        ech=0;
        for(i=0;i<nben;i++)
        {
            if(p[i].prix<p[i+1].prix)
            {
                Produit tmp;
                tmp=p[i+1];
                p[i+1]=p[i];
                p[i]=tmp;
                ech++;

            }
        }
    }while(ech>0);


    printf("***************affichage les produits selon ordre�decroissant du prix****************\n");
    for(i=0;i<nben;i++)
    {
     printf(" Code : %s \tNom: %s\t Quantite : %d Prix : \t %.2f Dh  PrixTTc : %.2f Dh\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix,(p[i].prix+(p[i].prix*0.15)));

    }
}
   void AcheterProduit(Produit p[],int nben)
    {
        char x_code[15];
        int trouve=1;

        printf("Veuillez donner le code de produit acheter:\t");
        scanf("%s",x_code);
        for(i=0;i<nben;i++)
        {
            if (strcmp(p[i].code,x_code)==0)
            {
                 printf("existe\n");
                 p[i].quantite -=1;
                return;
            }
        }
          printf("se produit n'existe pas\n");
    }






































