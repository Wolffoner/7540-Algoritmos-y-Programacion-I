#include<stdio.h>


int main () {

   FILE * archi;
   FILE * dest;


   archi=fopen("./copy.c", "r");
   dest=fopen("./copy_bak.c","w");

   if (!archi){
     printf("error de apertura archi \n");
     return -1;
   }

   if (!dest){
     printf("error de apertura dest \n");
     fclose(archi);
     return -1;
   }
   
   int letra;
   while (!feof(archi)) {
     letra=fgetc(archi);
     fputc(letra,dest);     
   }   

   fclose(archi);
   fclose(dest);
}
