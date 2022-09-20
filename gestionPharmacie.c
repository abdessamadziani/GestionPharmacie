
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>







typedef struct
{
    int quantite;
    char code[15],nom[15];
    float prix,prixTTC;
    float total_p;

    //int day,month,year;


}Produit;

typedef struct
{

    float min,max;
    int day_achat;
    int month_achat;
    int year_achat;
    float total,moyenne,quantiteTotal;
}Stat;

void Ajouter(Produit p[],int *poi);
void AjouterPlusieurs(Produit p[],int *poi);
void Afficher(Produit p[50],int nben);
void croissant_nom(Produit p[],int nben);
void decroissant_prix(Produit p[],int nben);
void AcheterProduit(Produit p[],int nben);
void Chercher_code(Produit p[],int nben);
void Chercher_quantite(Produit p[],int nben);
void Etat_du_stock(Produit p[],int nben);
void Alimenter_le_stock(Produit p[],int nben);
void Supprimer(Produit p[],int *poi);
void Statistique_de_vente();






void make_tolower(char s[])
{
  int length = strlen(s);
  for (int i=0;i<length;i++)
    {
      s[i]=tolower(s[i]);
    }
}

int n,i,nben=0,choix,ech;
float total;

Produit p[50];
Stat s;


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
                    printf("\t\t\t 1- Lister les produits selon l’ordre alphabetique croissant du nom \n");
                    printf("\t\t\t 2- Lister les produits selon l’ordre decroissant du prix.  \n");
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
                     do
               {
                    printf("\t\t\t 1- Par Code \n");
                    printf("\t\t\t 2- Par Quantite \n");
                    printf("\t\t\t 3- Menu Principale \n");

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
                          Chercher_code(p,nben);

                     }break;
                     case 2:
                     {
                         Chercher_quantite(p,nben);

                     }break;
                     default:
                     {

                     }break;
                 }


               }while(choix !=3);


            }break;
        case 6:
            {
                  Etat_du_stock(p,nben);

            }break;
        case 7:
            {
                Alimenter_le_stock(p,nben);


            }break;
       case 8:
            {
            Supprimer(p,poi);
            }break;
       case 9:
            {
             Statistique_de_vente();

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
    scanf("%s",p[i].nom);
    make_tolower(p[i].nom);
   printf("%s",p[i].nom);
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
    make_tolower(p[i].nom);
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
        for(i=0;i<nben-1;i++)
        {
            if(strcmp(p[i].nom,p[i+1].nom)>0)
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
        for(i=0;i<nben-1;i++)
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


    printf("***************affichage les produits selon ordre decroissant du prix****************\n");
    for(i=0;i<nben;i++)
    {
     printf(" Code : %s \tNom: %s\t Quantite : %d Prix : \t %.2f Dh  PrixTTc : %.2f Dh\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix,(p[i].prix+(p[i].prix*0.15)));

    }
}
   void AcheterProduit(Produit p[],int nben)
    {
        char x_code[15];
        int x_quantite;
        printf("Veuillez donner le code de produit a acheter:\t");
        scanf("%s",x_code);
        for(i=0;i<nben;i++)
        {
            if (strcmp(p[i].code,x_code)==0)
            {
                 printf("existe\n");
                 printf("donner la quantite a deduire\t");
                 scanf("%d",&x_quantite);
                 if(x_quantite>p[i].quantite)
                 {
                     printf(" impossible votre stock inferieur de %d",x_quantite);
                     return;
                 }
                 else
                 {
                      p[i].quantite -=x_quantite;
                      s.quantiteTotal+=1;
                      s.total+=(p[i].prix)*x_quantite;
                      s.moyenne=s.total/s.quantiteTotal;
                      p[i].total_p+=p[i].prix*x_quantite;
                      float ma=p[i].total_p;
                      float mi=p[i].total_p;
                      s.min=10000;



                          if(s.max<ma)
                          {
                              s.max=ma;
                          }
                           if(s.min<mi)
                          {
                              s.min=mi;
                          }

                     return;
                 }
            }
        }
          printf("se produit n'existe pas\n");
    }


     void Chercher_code(Produit p[],int nben)
    {
        char x_code[15];
        printf("Veuillez donner le code de produit a Rechercher:\t");
        scanf("%s",x_code);
        for(i=0;i<nben;i++)
        {
            if (strcmp(p[i].code,x_code)==0)
            {
                system("cls");
                 printf("existe\n");
                printf(" Code : %s \tNom: %s\t Quantite : %d Prix : \t %.2f Dh  PrixTTc : %.2f Dh\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix,(p[i].prix+(p[i].prix*0.15)));
                return;
            }
        }
          printf("se produit n'existe pas\n");
    }

    void Chercher_quantite(Produit p[],int nben)
    {
        int x_quantite;
        int trouve=0;

        printf("Veuillez donner la quantite :\t");
        scanf("%d",&x_quantite);
        for(i=0;i<nben;i++)
        {
            if (p[i].quantite == x_quantite)
            {
                printf("existe\n");
                printf(" Code : %s \tNom: %s\t Quantite : %d Prix : \t %.2f Dh  PrixTTc : %.2f Dh\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix,(p[i].prix+(p[i].prix*0.15)));
                trouve++;

            }
        }
        if(trouve == NULL)
          printf(" Quantite n'existe pas\n");
    }

    void Etat_du_stock(Produit p[],int nben)
    {
        for(i=0;i<nben;i++)
        {
            if(p[i].quantite<3)
            printf(" Code : %s \tNom: %s\t Quantite : %d Prix : \t %.2f Dh  PrixTTc : %.2f Dh\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix,(p[i].prix+(p[i].prix*0.15)));
        }

    }

    void Alimenter_le_stock(Produit p[],int nben)
    {
        char x_code_add[15];
        int x_quantite_add;
        printf("Veuillez donner le code de produit :\t");
        scanf("%s",x_code_add);
        for(i=0;i<nben;i++)
        {
            if (strcmp(p[i].code,x_code_add)==0)
            {
                 printf("existe\n");
                 printf("donner la quantiter :\t");
                 scanf("%d",&x_quantite_add);
                 p[i].quantite += x_quantite_add;
                return;
            }
        }
          printf("se produit n'existe pas\n");
    }


     void Supprimer(Produit p[],int *poi)
    {
        char x_code_produit[15];
       printf("entree le code de produit:\t") ;
       scanf("%s",x_code_produit);
       for(i=0;i<nben;i++)
       {
           if(strcmp(x_code_produit,p[i].code)==0)
           {
               p[i]=p[i+1];
               (*poi)--;
               return;
           }
       }
       printf("se code n'existe pas");


    }

    void Statistique_de_vente()
    {
          time_t now = time(NULL);
          struct tm *dt =localtime(&now);
                     s.day_achat=(dt->tm_mday);
                     s.month_achat=(dt->tm_mon+1);
                     s.year_achat=(dt->tm_year+1900);

        printf("le total des prix des produits vendus en journee courante :\n");
        printf(" ==> %d / %d /  %d ==> prix total :  %.2f Dh\n",s.day_achat,s.month_achat,s.year_achat,s.total);
        printf("la moyenne des prix des produits vendus en journee courante\n");
        printf(" ==> %d / %d /  %d ==> moyenne :  %.2f Dh\n",s.day_achat,s.month_achat,s.year_achat,s.moyenne);
        printf("le Max des prix des produits vendus en journe courante : %.2f\n",s.max);
        printf("le Min des prix des produits vendus en journe courante : %.2f\n",s.min);



   }






























