
#include <stdio.h>

#define MAX 100

void saisirTableau(int *t, int *n, char *nom);
void afficherTableau(int *t, int n);
int rechercherEtSupprimerSousTableau(int *t1, int *n1, int *t2, int n2);
void verifierSuppressionEtAfficher(int *t1, int *n1, int *t2, int n2);

int main()
{
    int t1[MAX], t2[MAX];
    int n1, n2;

    saisirTableau(t1, &n1, "T1");
    saisirTableau(t2, &n2, "T2");

    verifierSuppressionEtAfficher(t1, &n1, t2, n2);

    return (0);
}

// Fonction pour saisir un tableau avec nom personnalisé
void saisirTableau(int *t, int *n, char *nom)
{
    int i;
    printf("Veuillez inserer la taille de %s = ", nom);
    scanf("%d", n);

    for (i = 0; i < *n; i++)
    {
        printf("Entrer la valeur dans la case numero %d de %s = ", i, nom);
        scanf("%d", &t[i]);
    }
}

// Fonction pour afficher un tableau
void afficherTableau(int *t, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", t[i]);
    }
    printf("\n");
}

// Fonction qui recherche si t2 est un sous-tableau de t1 et le supprime s'il existe
// Retourne 1 si suppression faite, 0 sinon
int rechercherEtSupprimerSousTableau(int *t1, int *n1, int *t2, int n2)
{
    int i, j, k, mark;

    if (n2 > *n1) return 0; // impossible que t2 soit sous-tableau

    for (i = 0; i <= *n1 - n2; i++)
    {
        mark = 1;
        for (j = 0; j < n2; j++)
        {
            if (t1[i + j] != t2[j])
            {
                mark = 0;
                break;
            }
        }
        if (mark == 1)
        {
            // suppression du sous-tableau t2 dans t1 a partir de i
            for (k = i; k < *n1 - n2; k++)
            {
                t1[k] = t1[k + n2];
            }
            *n1 -= n2;
            return 1; // suppression effectuee
        }
    }
    return (0); // sous-tableau non trouve
}

// Fonction qui verifie suppression et affiche resultats
void verifierSuppressionEtAfficher(int *t1, int *n1, int *t2, int n2)
{
    int res = rechercherEtSupprimerSousTableau(t1, n1, t2, n2);

    if (res == 1)
    {
        printf("Sous-tableau supprime.\n");
    }
    else
    {
        printf("Sous-tableau non trouve.\n");
    }

    afficherTableau(t1, *n1);
}
