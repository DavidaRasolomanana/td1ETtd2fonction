
#include <stdio.h>
#include <string.h>

void saisirMot(char *mot);
void saisirBigramme(char *big1, char *big2);
int compterBigramme(const char *mot, char big1, char big2);
void afficherResultat(char big1, char big2, int count);

int main()
{
    char mot[100];
    char big1, big2;
    int count;

    saisirMot(mot);
    saisirBigramme(&big1, &big2);
    count = compterBigramme(mot, big1, big2);
    afficherResultat(big1, big2, count);

    return (0);
}

// Saisit le mot a analyser
void saisirMot(char *mot)
{
    printf("entrer le mot= ");
    gets(mot);  // Utilisation volontaire de gets comme demande
}

// Saisit les deux caractères du bigramme
void saisirBigramme(char *big1, char *big2)
{
    printf("entrer les deux caracteres du bigramme= ");
    scanf(" %c", big1); // espace avant %c pour ignorer '\n' residuel
    scanf(" %c", big2);
}

// Compte le nombre d'occurrences du bigramme
int compterBigramme(char *mot, char big1, char big2)
{
    int i, count = 0;
    int n = strlen(mot);

    for (i = 0; i < n - 1; i++)
    {
        if (mot[i] == big1 && mot[i + 1] == big2)
        {
            count++;
        }
    }

    return (count);
}

// Affiche le resultat
void afficherResultat(char big1, char big2, int count)
{
    printf("le bigramme %c%c se repete %d fois\n", big1, big2, count);
}
