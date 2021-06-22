#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MENSAJE 500
bool es_vocal(char letra) {
    return (letra == 'a' || letra == 'e' || letra == 'i'
    || letra == 'o' || letra == 'u' );
}

int main () {
    char entrada[MAX_MENSAJE];
    printf("Ingrese el mensaje \n");
    scanf("%[^\n]%*c", entrada);
    char aux;
    int i = 0;
    do {
        if (es_vocal (entrada[i]) ) {
            entrada [i] = 'i'; 
        }
        i++;
    } while (entrada[i] != '\0');
    printf("\n%s",entrada);
}