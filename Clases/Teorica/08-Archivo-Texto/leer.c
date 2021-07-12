#include<stdio.h>


int main () {

   FILE * archi;

   archi=fopen("./copy.c", "r");

   if (!archi){
     printf("error de apertura\n");
     return -1;
   }
   
   int letra;
   while (!feof(archi)) {
     letra=fgetc(archi);
     printf("%c",letra);
   }   

   fclose(archi);
}
