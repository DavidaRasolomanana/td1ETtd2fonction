#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void saisirTableau(int *t, int *n);
float calculerMoyenne(int *t, int n);
void calculerDifferences(int *t, float moyenne, float *diff, int n);
int trouverPositionMinDiff(float *diff, int n);
void afficherResultat(int *t, int position, float moyenne);

int main()
{
    int t[MAX];
    float diff[MAX];
    int n, position;
    float moyenne;

    saisirTableau(t, &n);

    moyenne = calculerMoyenne(t, n);

    calculerDifferences(t, moyenne, diff, n);

    position = trouverPositionMinDiff(diff, n);

    afficherResultat(t, position, moyenne);

    return (0);
}

void saisirTableau(int *t, int *n)
{
    int i;
    do
    {
        printf("entrer le nombre de nombre que vous voulez inserer dans le tableau inferieur a 100 =");
        scanf("%d", n);
    }
    while (*n > MAX || *n <= 0);

    for (i = 0; i < *n; i++)
    {
        printf("inserer la valeur dans la case numero %d = ", i);
        scanf("%d", &t[i]);
    }
}

float calculerMoyenne(int *t, int n)
{
    int i;
    float somme = 0;
    for (i = 0; i < n; i++)
    {
        somme += t[i];
    }
    return (somme / n);
}

void calculerDifferences(int *t, float moyenne, float *diff, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        diff[i] = abs(t[i] - moyenne);
    }
}

int trouverPositionMinDiff(float *diff, int n)
{
    int i, position = 0;
    float min = diff[0];
    for (i = 1; i < n; i++)
    {
        if (diff[i] < min)
        {
            min = diff[i];
            position = i;
        }
    }
    return (position);
}

void afficherResultat(int *t, int position, float moyenne)
{
    printf("moyenne=%.2f\n", moyenne);
    printf("t[%d]=%d\n", position, t[position]);
}
