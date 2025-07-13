#include <stdio.h>

#define MAX 100

void demanderHauteur(int *n);
void genererTrianglePascal(int tab[MAX][MAX], int n);
void afficherTrianglePascal(int tab[MAX][MAX], int n);

int main()
{
    int n;
    int tab[MAX][MAX];

    demanderHauteur(&n);
    genererTrianglePascal(tab, n);
    afficherTrianglePascal(tab, n);
    return (0);
}

// Fonction pour demander la hauteur du triangle (max 100)
void demanderHauteur(int *n)
{
    int tentative = 0;

    do
    {
        tentative++;
        printf("entrer la hauteur du triangle de pascal inferieur a 100 = ");
        scanf("%d", n);
    }
    while ((*n > MAX || *n <= 0) && tentative < 3);
}

// Fonction pour generer les valeurs du triangle de Pascal
void genererTrianglePascal(int tab[MAX][MAX], int n)
{
    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (j == 1 || j == i)
            {
                tab[i][j] = 1;
            }
            else
            {
                tab[i][j] = tab[i - 1][j - 1] + tab[i - 1][j];
            }
        }
    }
}

// Fonction pour afficher le triangle de Pascal
void afficherTrianglePascal(int tab[MAX][MAX], int n)
{
    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}
