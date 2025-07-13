#include <stdio.h>
#include <string.h>

// Fonctions
void saisirMot(char *mot);
void crypterMot(const char *mot, char *motcrypt);
void afficherMotCrypte(const char *motcrypt);
int estVoyelle(char c);

int main()
{
    char mot[100];
    char motcrypt[300];

    saisirMot(mot);
    crypterMot(mot, motcrypt);
    afficherMotCrypte(motcrypt);

    return (0);
}

// Saisie du mot a crypter
void saisirMot(char *mot)
{
    printf("enter le mot que vous voulez crypter =");
    fgets(mot, 100, stdin);
    
    int n = strlen(mot);
    if (mot[n - 1] == '\n')
    {
        mot[n - 1] = '\0'; // enlever le retour a la ligne
    }
}

// Verifie si un caractere est une voyelle
int estVoyelle(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u' || c == 'y');
}

// Crypte le mot selon la regle du IT
void crypterMot(const char *mot, char *motcrypt)
{
    char it[2] = { 'I', 'T' };
    int i, v = 0;

    for (i = 0; mot[i] != '\0'; i++)
    {
        if (!estVoyelle(mot[i]))
        {
            if (estVoyelle(mot[i + 1]))
            {
                motcrypt[v++] = mot[i];
                motcrypt[v++] = it[0];
                motcrypt[v++] = it[1];
            }
            else
            {
                motcrypt[v++] = mot[i];
            }
        }
        else
        {
            motcrypt[v++] = mot[i];
        }
    }

    motcrypt[v] = '\0'; // terminer la chaine cryptee
}

// Affichage du mot crypte
void afficherMotCrypte(const char *motcrypt)
{
    printf("le mot crypte est %s\n", motcrypt);
}
