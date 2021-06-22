#include <string.h>
#include <stdio.h>

#define TAM 50

int main () {

 char origen [TAM] = "Christopher Nolan";
 char destino [TAM]; 
 strcpy(destino, origen);
 printf("%s \n", destino);
 return 0;
}