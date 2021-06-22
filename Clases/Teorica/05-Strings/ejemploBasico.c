#include <string.h>
#include <stdio.h>

#define TAM 50

int main () {
 char string [TAM] = "cinco";
 int tam;
 tam = strlen(string);
 printf("%i\n", tam);
 return 0;
}