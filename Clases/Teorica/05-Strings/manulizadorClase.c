#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXIMO_MENSAJE 500

bool es_vocal(char letra) {
    return (letra == 'a' || letra == 'e'|| letra == 'i'
    || letra == 'o'|| letra == 'u');
}


int main() {
    char mensaje [MAXIMO_MENSAJE];
    printf("Ingrese el mensaje a burlar \n");
    scanf("%[^\n]", mensaje);

    for (size_t i = 0; i < strlen(mensaje); i++) {
        if (es_vocal (mensaje[i]) ){
            mensaje[i] = 'i';
        }
    }
    
    printf("%s\n",mensaje);
    return 0;
}