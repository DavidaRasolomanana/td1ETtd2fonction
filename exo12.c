#include <stdio.h>

#define MAX 100

// Déclarations des fonctions
void saisirMatrice(int t[MAX][MAX], int *taille);
int sommeLigne(int t[MAX][MAX], int ligne, int taille);
int sommeColonne(int t[MAX][MAX], int colonne, int taille);
void verifierCarreMagique(int t[MAX][MAX], int taille);

int main()
{
    int t[MAX][MAX];
    int taille;

    saisirMatrice(t, &taille);
    verifierCarreMagique(t, taille);
    return(0);
}

// Fonction de saisie de la matrice
void saisirMatrice(int t[MAX][MAX], int *taille)
{
    int i, j;
    printf("entrer le nombre de ligne et de colonne que vous voulez = ");
    scanf("%d", taille);

    for (i = 0; i < *taille; i++)
    {
        for (j = 0; j < *taille; j++)
        {
            printf("entrer la valeur dans la ligne numero %d et la colonne numero %d = ", i, j);
            scanf("%d", &t[i][j]);
        }
    }
}

// Fonction pour calculer la somme d'une ligne
int sommeLigne(int t[MAX][MAX], int ligne, int taille)
{
    int j, somme = 0;
    for (j = 0; j < taille; j++)
    {
        somme += t[ligne][j];
    }
    return (somme);
}

// Fonction pour calculer la somme d'une colonne
int sommeColonne(int t[MAX][MAX], int colonne, int taille)
{
    int i, somme = 0;
    for (i = 0; i < taille; i++)
    {
        somme += t[i][colonne];
    }
    return (somme);
}

// Fonction pour verifier si la matrice est un carre magique
void verifierCarreMagique(int t[MAX][MAX], int taille)
{
    int i, j;
    int estMagique = 1;
    int sommeref = sommeLigne(t, 0, taille);
    int somme;

    // Verification des lignes
    for (i = 1; i < taille; i++)
    {
        somme = sommeLigne(t, i, taille);
        if (somme != sommeref)
        {
            estMagique = 0;
        }
    }

    // Verification des colonnes
    for (j = 0; j < taille; j++)
    {
        somme = sommeColonne(t, j, taille);
        if (somme != sommeref)
        {
            estMagique = 0;
        }
    }

    if (estMagique == 1)
    {
        printf("le carre est magique\n");
    }
    else
    {
        printf("le carre n'est pas magique\n");
    }
}
