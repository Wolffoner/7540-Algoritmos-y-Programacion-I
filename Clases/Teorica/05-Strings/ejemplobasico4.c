#include <string.h>
#include <stdio.h>

#define TAM 50

int main () {
 char string1 [TAM] = "Hola Soy ";
 char string2 [TAM] = "Nicolas Riedel";
 strcat(string1, string2);
 printf("%s \n", string1);
 return 0;
}