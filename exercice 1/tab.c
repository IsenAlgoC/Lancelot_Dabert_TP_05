#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

#define TAB2SIZE 100
#define TAILLEAJOUT 50

int initTab(int* tab, int size);
int afficheTab(int* tab, int size, int nbElts);


int main()
{
	int myTab1[10] = { 12 };



	int* myTab2 = NULL;
	int tabsize = TAB2SIZE;
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (myTab2 != NULL) { initTab(myTab2, tabsize); }
	else { printf("mémoire insuffisante"); return(-1); }
	for (int i = 1; i <= 20; i++)
	{
		*(myTab2 + i - 1) = i;
	}
	afficheTab(myTab2, 20, 20);

	free(myTab2);

}