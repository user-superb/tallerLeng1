#include <stdio.h>
#include <stdlib.h>

#define MACRO(X,Y) (X*Y)

#define SI(X,Y) if (X > Y) \
		printf("%d es mayor que %d\n", X, Y); \
	else \
		printf("%d es menor que %d\n", X, Y);

#define CONCAT(X,Y) X ## Y

#define MENORDE2(X,Y) ((X < Y) ? X : Y)
#define MENORDE3(X,Y,Z) ((MENORDE2(X,Y) < Z) ? MENORDE2(X,Y) : Z)

#include "./libtexto.h"

int main(int argc, char *argv[]) {
	int num = MACRO(5,10);
	
	printf("%d\n", num);
	
	SI(num, 10);
	SI(num, 100);
	
	printf("%d\n", CONCAT(10,20));
	printf("Menor: %d\n", MENORDE3(10,5,20));
	
	imprimirEnPantalla("abc");
	
	return 0;
}

