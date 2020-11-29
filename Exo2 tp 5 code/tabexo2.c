#include <stdlib.h>
#include <stdio.h>
#include "tabexo2.h"


#define TAILLEINITIALE 100


TABLEAU newArray();
int initTab(int* tab, int size);
int incrementArraySize(TABLEAU* tab, int incrementValue);
int setElement(TABLEAU* tab, int pos, int element);
int displayElements(TABLEAU* tab, int startPos, int endPos);


main()
{
	TABLEAU tab;
	tab = newArray();
	incrementArraySize(&tab, 12);
	setElement( &tab, 46,12);
	displayElements(&tab, 45, 47);

}
