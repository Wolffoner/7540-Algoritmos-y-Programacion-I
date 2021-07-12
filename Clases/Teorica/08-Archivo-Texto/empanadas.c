#include<stdio.h>
#include<stdbool.h>
#include<string.h>


#define MAX 50

typedef struct respuesta{
    char gusto_preferido[MAX];
    int  cuantas_se_come;
    bool carne_con_pasas;
}respuesta_t;


int main () {
    FILE* archivo;
    archivo=fopen("./empanadas.csv","r");
    if(archivo==NULL){
        printf("error al abrir empanadas.csv\n");
        return -1;
    }
    int contador=0;
    int leidos;
    respuesta_t reg;

    leidos=fscanf(archivo, "%[^;];%i;%i\n",reg.gusto_preferido,&(reg.cuantas_se_come),&(reg.carne_con_pasas));
    while (leidos!= EOF){
        if (strcmp("Carne",reg.gusto_preferido)==0)
            contador++;
        
        leidos=fscanf(archivo, "%[^;];%i;%i\n",reg.gusto_preferido,&(reg.cuantas_se_come),&(reg.carne_con_pasas));
    }
    printf("los que aman a Humita son %i\n",contador);
    fclose(archivo);
    return 0;
}




