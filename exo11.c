#include <stdio.h>
#include <string.h>

void saisirMotCrypte(char *mot);
void decrypterMot(const char *mot, char *motdecrypt);
void afficherMotDecrypte(const char *motdecrypt);
int estVoyelle(char c);

int main()
{
    char mot[100];
    char motdecrypt[300];

    saisirMotCrypte(mot);
    decrypterMot(mot, motdecrypt);
    afficherMotDecrypte(motdecrypt);

    return (0);
}

// Fonction pour saisir le mot crypte
void saisirMotCrypte(char *mot)
{
    printf("enter le mot  crypter =");
    fgets(mot, 100, stdin);
    int n = strlen(mot);
    if (mot[n - 1] == '\n')
    {
        mot[n - 1] = '\0'; // supprimer le retour a la ligne
    }
}

// Fonction pour verifier si un caractere est une voyelle
int estVoyelle(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u' || c == 'y');
}

// Fonction pour decrypter le mot
void decrypterMot(const char *mot, char *motdecrypt)
{
    int i, v = 0;
    char it1 = 'I';
    char it2 = 'T';

    for (i = 0; mot[i] != '\0'; i++)
    {
        if (mot[i] >= 'a' && mot[i] <= 'z')
        {
            if (!estVoyelle(mot[i]))
            {
                if (mot[i + 1] == it1 && mot[i + 2] == it2)
                {
                    motdecrypt[v++] = mot[i];
                    i += 2; // sauter les lettres IT
                }
                else
                {
                    motdecrypt[v++] = mot[i];
                }
            }
            else
            {
                motdecrypt[v++] = mot[i];
            }
        }
        else
        {
            motdecrypt[v++] = mot[i];
        }
    }

    motdecrypt[v] = '\0'; // fin de chaine
}

// Fonction pour afficher le mot decrypte
void afficherMotDecrypte(const char *motdecrypt)
{
    printf("le mot decrypte est %s\n", motdecrypt);
}
