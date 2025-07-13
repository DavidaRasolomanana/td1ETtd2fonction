#include <stdio.h>
#include <string.h>

void saisirMot(char *mot);
int estMotCarre(const char *mot);
void afficherResultat(int estCarre);

int main()
{
    char mot[100];
    int estCarre;

    saisirMot(mot);
    estCarre = estMotCarre(mot);
    afficherResultat(estCarre);

    return (0);
}

// Fonction de saisie
void saisirMot(char *mot)
{
    printf("veuillez entrer le mot dont on veut verifier si il est carre= ");
    fgets(mot, 100, stdin);
}

// Fonction pour tester si le mot est un carre
int estMotCarre(const char *mot)
{
    int n = strlen(mot);
    if (mot[n - 1] == '\n')
    {
        n--;
    }
    if (n % 2 != 0)
    {
        return (0); // Si longueur impaire, pas un carre
    }
    int i, milieu = n / 2;
    char racine1[50], racine2[50];

    for (i = 0; i < milieu; i++)
    {
        racine1[i] = mot[i];
    }
    racine1[milieu] = '\0';

    for (i = 0; i < milieu; i++)
    {
        racine2[i] = mot[milieu + i];
    }
    racine2[milieu] = '\0';

    return strcmp(racine1, racine2) == 0;
}

// Fonction d'affichage
void afficherResultat(int estCarre)
{
    if (estCarre)
    {
        printf("c'est un carre\n");
    }
    else
    {
        printf("ce n'est pas un carre\n");

    }
}

