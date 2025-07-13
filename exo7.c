#include <stdio.h>
#include <string.h>


void saisirTexte(char *texte);
void verifierPointFinalOuQuitter(char *texte);
void compterAetEs(char *texte, int *counta, int *countes);
void afficherResultats(int counta, int countes);

int main()
{
    char texte[100];
    int counta = 0, countes = 0;

    saisirTexte(texte);
    verifierPointFinalOuQuitter(texte);
    compterAetEs(texte, &counta, &countes);
    afficherResultats(counta, countes);

    return (0);
}

void saisirTexte(char *texte)
{
    printf("veuillez entrer le texte dont on veut compter 'a' et 'es'=");
    gets(texte);  // utilisation volontaire de gets comme demandé
}

void verifierPointFinalOuQuitter(char *texte)
{
    int n = strlen(texte);
    if (n < 1 || texte[n - 1] != '.')
    {
        exit(0);
    }
}

void compterAetEs(char *texte, int *counta, int *countes)
{
    int i, n;
    *counta = 0;
    *countes = 0;
    n = strlen(texte);

    for (i = 0; i < n; i++)
    {
        if (texte[i] == 'a')
        {
            (*counta)++;
        }
        if (texte[i] == 'e' && texte[i + 1] == 's')
        {
            (*countes)++;
        }
    }
}

void afficherResultats(int counta, int countes)
{
    printf("le nombre de 'a' = %d\n", counta);
    printf("le nombre de 'es' = %d\n", countes);
}
