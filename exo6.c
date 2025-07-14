#include <stdio.h>
#include <string.h>

void saisirMot(char *mot);
void inverserMot(char *mot, char *motinv);
int estPalindrome(char *mot, char *motinv);
void afficherResultat(int palindrome);

int main()
{
    char mot[100];
    char motinv[100];

    saisirMot(mot);
    inverserMot(mot, motinv);

    int palindrome = estPalindrome(mot, motinv);
    afficherResultat(palindrome);

    return (0);
}

void saisirMot(char *mot)
{
    printf("ecrire le caractere que vous voulez verifer si il est palindrome ou non= ");
    scanf("%s", mot);
}

void inverserMot(char *mot, char *motinv)
{
    int n = strlen(mot);
    int j = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        motinv[j] = mot[i];
        j++;
    }
    motinv[j] = '\0'; // Terminer la chaîne inversée
}

int estPalindrome(char *mot,char *motinv)
{
    return (strcmp(mot, motinv) == 0);
}

void afficherResultat(int palindrome)
{
    if (palindrome)
    {
        printf("le mot est palindrome\n");
    }
    else
    {
        printf("le mot n'est pas palindrome\n");
    }
}
