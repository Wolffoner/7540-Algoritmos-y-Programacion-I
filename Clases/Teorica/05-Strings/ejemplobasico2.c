#include <string.h>
#include <stdio.h>

#define TAM 50

int main () {

 char string0 [TAM] = "Arbol";
 char string1 [TAM] = "Vaca";
 printf("%i\n", strcmp(string0, string1) );
 printf("%i\n", strcmp(string1, string0) );
 printf("%i\n", strcmp(string0, string0) );
 return 0;
}