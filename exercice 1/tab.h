#pragma once
#include <stdlib.h>
#include <stdio.h>

#define TAB2SIZE 100
#define TAILLEAJOUT 50

int initTab(int* tab, int size)						// fonction qui remplit un tableau de taille size avec des zeros
{
	if ((tab == NULL) || (size <= 0)) { return -1; } // retourne -1 si tab est un pointeur NULL ou si size est négeatif ou nul
	else
	{
		for (int i = 0; i < size; i++)				// boucle de remplissage
		{
			*(tab + i) = 0;							// donne la valeur 0 a l'adresse numero i du tableau par déréférence 
		}
		return size;								// retourne size car tout va bien
	}
}


int afficheTab(int* tab, int size, int nbElts)
{
	if ((tab == NULL) || (size <= 0) || (nbElts <= 0) || (size < nbElts)) { return -1; } // retourne -1 si tab est un pointeur NULL, si size ou nbElts sont négeatif ou nuls, ou encore si nbElts > size
	else
	{
		for (int i = 0; i < nbElts; i++)													//boucle d'affichage des entiers du tableau
		{
			printf_s("%d ;", *(tab + i));												//affiche l'entier situé a la ieme case 
		}
		return 0;
	}

}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element)

{
	int* tmp;													// variable temporaire utile dans le cas ou la fonction realloc renvoie un pointeur null
	if ((*nbElts < *size))									 // on verifie que le tableau dispose de la place pour ajouter element
	{

		*(tab + *nbElts) = element;								// on ajoute l'element au tableau
		*nbElts += 1;											// on met a jour le nombre d element stockes dans le tableau
		return tab;
	}
	else														// si le tableau ne dispose pas de la place necessaire
	{
		if (tab != NULL)										// on  verifie que tab n est pas un pointeur null
		{
			tmp = (int*)realloc(tab, TAILLEAJOUT * sizeof(int));// on utilise tmp pour ne pas attribuer a tab un pointeur null 
			if (tmp != NULL)									// dans le cas ou tmp n est pas null
			{
				tab = tmp;										// on augmente la taille du tableau de TAILLEAJOUT
				*(tab + *nbElts) = element;						// on ajoute l'element au tableau
				*nbElts += 1;									// on met a jour le nombre d'element stockes dans le tableau
				*size += TAILLEAJOUT;							// on met a jour la capacité reelle du tableau
				return tab;
			}
			else
			{
				printf_s("ajout impossible");					// dans le cas ou tmp est null on retourne ajout impossible
				return NULL;
			}
		}
		else
		{
			printf_s("ajout impossible");						// dans le cas ou tab est null on retourne ajout impossible
			return NULL;
		}



	}