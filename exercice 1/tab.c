#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

#define TAB2SIZE 100
#define TAILLEAJOUT 50 // definition de constante gloables

int initTab(int* tab, int size);
int afficheTab(int* tab, int size, int nbElts);  // declarations de fonctions 


int main()
{
	int myTab1[10] = { 12 }; // creation d'unn tableau fixe d entiers



	int* myTab2 = NULL; // initialisation d un pointeur 
	int tabsize = TAB2SIZE; // taille du tableau
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int)); // allocation de la memoire 
	if (myTab2 != NULL) { initTab(myTab2, tabsize); } // si allocation reussi on initialise le tableau de zeros
	else { printf("mémoire insuffisante"); return(-1); } // sinon on renvoie un message d'erreur
	for (int i = 1; i <= 20; i++) // boucle de remplissage des 20 premieres places du tableau
	{
		*(myTab2 + i - 1) = i; // avec des entiers de 1 a 20 croissants
	}
	afficheTab(myTab2, 20, 20); // affichage des 20 premieres valeurs du tableau

	free(myTab2); // liberation de la memoire allouee au tableau 

}
