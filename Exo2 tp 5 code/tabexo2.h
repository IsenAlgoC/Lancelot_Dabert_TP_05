#pragma once


typedef struct Tableau {
	int* elt;      //le tableau d'entiers
	int size;      // la taille de ce tableau d’entiers
	int eltsCount; // le nombre d’elements dans le tableau
} TABLEAU;

#define TAILLEINITIALE 100

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



TABLEAU newArray()
{

	int* elt = NULL; // initialisation du pointeur 
	int size = TAILLEINITIALE; // definition de la taille du tableau
	int eltsCount = 0; // nombre d'elements dans le tableau
	elt = (int*)malloc(size * sizeof(int));  // allocation de la memoire 
	if (elt != NULL) { initTab(elt, size); } // si l'allocation n'est pas un echec on rempli le tableau de zero avec la fonction de l'exercice 1
	TABLEAU tab = { elt,size,eltsCount };
	return tab;// on retourne un element de type TABLEAU avec elt etant un pointeur null si l allocation a echouee
}


int incrementArraySize(TABLEAU* tab, int incrementValue)
{
	int* tmp; // pointeur temporaire
	if (tab->elt != NULL) // si elt n'est pas un pointeur null

	{
		tmp = (int*)realloc(tab->elt, incrementValue * sizeof(int)); // on modifie avec realloc le pointeur temporaire
		if (tmp != NULL)
		{
		tab->elt = tmp;  // si la reallocation marche  on modifie la taille du tableau
		tab->size += incrementValue; // et on met a jour la taille indiquée

		return tab->size; // on renvoire alors la nouvelle taille 
	}
		else return	-1; // sinon on revoie -1
		
	}
	else return -1;
}

int setElement(TABLEAU* tab, int pos, int element)
{
	if (tab->elt != NULL) // si elt n'est pas un pointeur null

	{
		if ( pos > tab->size) // si la position a laquelle on doit inserer la valeur est superieur a la taille du tableau
		{
			incrementArraySize(tab, pos); // on agrandit le tableau jsuqu'au moins la position voulu
			for (int i = tab->size; i < pos; i++) // on remplit les cases entre la taille precedente du tableau et la position demandee avec des zeros
			{
				*(tab->elt + i) = 0;
			}

		}
		*(tab->elt + pos) = element; // on ecrit l'element a la position voulu, maintenant que l'on sait qu elle existe necessairement
		return pos; // on retourne alors la position
	}
	else return 0; // si elt est un pointeur null on retourne -1
}

int displayElements(TABLEAU* tab, int startPos, int endPos)
{
	if( (tab->elt != NULL) && (0<=startPos<tab->size) && (0 <= endPos < tab->size)) // on verifie que le pointeur elt ne soit pas null, et que startPos et endPos soient valides
	{
		if (startPos <endPos)  // cas classique ou on affiche les valeurs dans l ordre croissant entre startPos et endPos
		{ 
			for (int i =startPos; i< endPos, i ++;) 
			{printf_s("%d",*(tab->elt + i));}
		}

		if (startPos = endPos) // si egalité on affiche un seul element
		{ printf_s("%d", *(tab->elt + startPos)); }

		if (startPos > endPos) // ici on inverse startPos et endPos par rapport au 1er cas
		{
			for (int i = endPos; i <= startPos, i++;)
			{ {printf_s("%d", *(tab->elt + i)); }

			}

		}
	return 0; // on retourne 0 si tout est ok	
	}
	else return -1; // si erreur on retourne -1
}
