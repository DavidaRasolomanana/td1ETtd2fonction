#include <stdio.h>

#define N 100

void saisirTableau(int *t,int *n);
void afficherTableau(int *t,int n);
void separerPairsImpairs(int *t,int n);
void insererEtTrierParParite(int *t, int *n);
int main() 
{
    int t[N];
    int n;

    saisirTableau(t, &n);
    separerPairsImpairs(t, n);
    afficherTableau(t, n);
    insererEtTrierParParite(t, &n);
    afficherTableau(t, n);

    return (0);
}

// Fonction pour saisir les valeurs du tableau
void saisirTableau(int *t, int *n)
{ 
    int tentative=0;
    int i;
    do
    {
        if (++tentative>3) 
        {
            printf("Trop de tentatives. Fin du programme.\n");
            exit(0);
        }

        printf("Veuillez entrer le nombre d'elements (<= %d) : ", N);
        scanf("%d", n);
    } 
    while (*n>N || *n<=0);

    for (i=0;i<*n;i++)
    {
        printf("Entrer la valeur dans la case numero %d : ", i);
        scanf("%d", &t[i]);
    }
}

// Fonction pour afficher un tableau
void afficherTableau(int *t, int n) 
{
    int i;
    for (i=0;i<n;i++) 
    {
        printf("T[%d]=%d ",i,t[i]);
    }
    printf("\n");
}

// Fonction pour reorganiser le tableau : pairs d'abord, puis impairs
void separerPairsImpairs(int *t,int n) 
{
    int temp1[N]; // pour les pairs
    int temp2[N]; // pour les impairs
    int j=0,k=0;
    int i;

    for (i=0;i<n;i++) 
    {
        if (t[i]%2==0) 
        {
            temp1[j++]=t[i];
        }
        else 
        {
            temp2[k++]=t[i];
        }
    }
    //reorganiser le tableau
    for (i=0;i<j;i++) 
    {
        t[i]=temp1[i];
    }
    for (i=0;i<k;i++) 
    {
        t[j+i]=temp2[i];
    }
}

void insererEtTrierParParite(int *t, int *n)
{
    int x;
    printf("Veuillez entrer un nombre a inserer : ");
    scanf("%d", &x);

    if (*n>=N)
    {
        printf("Tableau plein. Insertion impossible.\n");
        return;
    }

    t[*n]=x;  // insertion a la fin
    (*n)++;   // on augmente la taille du tableau

    separerPairsImpairs(t, *n); // on trie a nouveau par parite
}

