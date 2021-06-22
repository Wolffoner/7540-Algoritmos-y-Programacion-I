#include <stdio.h>
#include <string.h>

#define MAX_PALABRA 256
int const MAX_PALABRA_CARTA = 10;
char const BAJITO[MAX_PALABRA] = "bajito";
char const MUYMUYALTO[MAX_PALABRA] = "muymuyalto";

/*
strcmp -> comparamos 2 strings
strlen -> nos dice el largo del string
strcpy -> nos copia un string en otro
strcat -> nos concatena un string en otro
*/
int main(){

	char carta[2000] = "";
	char palabra[MAX_PALABRA] = ".";

	printf("A continuación, escriban la carta palabra a palabra.\n");
	while (strcmp(palabra, "@") != 0){
		scanf("%s", palabra);

		if (strlen(palabra) <= MAX_PALABRA_CARTA){

			if (strcmp(palabra, BAJITO) == 0){
				strcpy(palabra, MUYMUYALTO);
			}

			strcat(carta, palabra);
			strcat(carta, " ");
		}
	}

	printf("%s\n", carta);
	return 0;	
}