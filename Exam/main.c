#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct destino {
	int codProv;
	int codLoc;
	char nomLoc[30];
	int nHab;
} t_destino;

void imprimirDestino (t_destino *des) {
	printf("codProv: %d; codLoc: %d; nomLoc: %s; nHab: %d\n", des->codProv, des->codProv, des->nomLoc, des->nHab);
}

void imprimirMaxHab(FILE *file) {
	t_destino *aux, max;
	aux = malloc(sizeof(t_destino));
	
	fseek(file, 0, SEEK_SET);
	
	fread(aux, sizeof(t_destino), 1, file);
	max = *aux;
	while (!feof(file)) {
		fread(aux, sizeof(t_destino), 1, file);
		if (aux->nHab > max.nHab) {
			max = *aux;
		}
	}
	
	printf("loc: %d nom: %s\n", max.codLoc, max.nomLoc);
}

int main(int argc, char *argv[]) {
	FILE *file0, *file1;
	
	file0 = fopen("Habitantes.txt", "r");
	file1 = fopen("Habitantes.dat", "w+");
	
	if (!file0)
		return 1;
	if (!file1)
		return 1;
	
	t_destino *aux;
	aux = malloc(sizeof(t_destino));

	while (!feof(file0)) {
		if (!isdigit(fgetc(file0)))
			while (fgetc(file0) != '\n');
		else
			fseek(file0, -1, SEEK_CUR);
		
		fscanf(file0, "%d %d %s %d\n", &aux->codProv, &aux->codLoc, aux->nomLoc, &aux->nHab);		
		imprimirDestino(aux);
		fwrite(aux, sizeof(t_destino), 1, file1);
	}
	
	imprimirMaxHab(file1);

	fclose(file0);
	fclose(file1);
	
	return 0;
}

