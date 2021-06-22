#include <stdio.h>
#include <stdlib.h>
#include "detector_personajes.h"

/*
*   Pre:
*       - Ninguna.
*   Post:
*       - fecha sera un número entero entre MIN_FECHA  y MAX_FECHA.
*/
void definir_fecha_de_nacimiento(int * fecha){

    printf("Introduce un número entre (%i y %i):\n", MIN_FECHA, MAX_FECHA);
    scanf("%i", fecha);

    while((*fecha) < MIN_FECHA || (*fecha) > MAX_FECHA){

        printf("Introdujiste un número fuera del rango entre (%i y %i).\n",
                MIN_FECHA, MAX_FECHA);
        printf("Introduce nuevamente un número entre (%i y %i):\n",
                MIN_FECHA, MAX_FECHA);
        scanf("%i", fecha);
    }
}

/*
*   Pre:
*       - Ninguna.
*   Post:
*       - sabor será un caracter entre (DULCE, SALADO, o AMARGO)
*/
void definir_preferencia_sabor(char* sabor){

    printf("Introduce tu sabor preferido de las siguientes opciones:\n");
    printf("%c: Dulce.\n", DULCE);
    printf("%c: Salado.\n", SALADO);
    printf("%c: Amargo.\n", AMARGO);
    scanf(" %c", sabor);

    while(!((*sabor) == DULCE || (*sabor) == SALADO || (*sabor) == AMARGO)){

        printf("Introdujiste un sabor distinto de (%c, %c o %c).\n",
                DULCE, SALADO, AMARGO);
        printf("Introduce nuevamente un sabor entre (%c, %c o %c):\n",
                DULCE, SALADO, AMARGO);
        scanf(" %c", sabor);
    }
}

/*
*   Pre:
*       - Ninguna.
*   Post:
*       - talla será un numero entero entre MIN_TALLA_ZAPATOS y
*       MAX_TALLA_ZAPATOS o SIN_ZAPATOS.
*/
void definir_talla_zapatos(int* tallaZapatos){

    printf("Introduce tu talla de zapatos, debe ser un número entre (%i y %i).\n",
            MIN_TALLA_ZAPATOS, MAX_TALLA_ZAPATOS);
    printf("o en el caso de que andes sin zapatos, entonces introduce (%i):\n",
            SIN_ZAPATOS);
    scanf("%i", tallaZapatos);

    while(!(((*tallaZapatos) >= MIN_TALLA_ZAPATOS && (*tallaZapatos) <= MAX_TALLA_ZAPATOS)
                || (*tallaZapatos) == SIN_ZAPATOS)){
        printf("Introdujiste una talla equivocada, debe ser un número entre (%i y %i).\n",
                MIN_TALLA_ZAPATOS, MAX_TALLA_ZAPATOS);
        printf("o en el caso de que andes sin zapatos, entonces introduce (%i):\n",
                SIN_ZAPATOS);
        scanf(" %i", tallaZapatos);
    }
}

/*
*   Pre:
*       - Ninguna.
*   Post:
*       - color será un caracter entre (AZUL, AMARILLO, VERDE, NEGRO, BLANCO o
*       ROSA).
*/
void definir_color_preferido(char* color){

    printf("Introduce tu color preferido de las siguientes opciones:\n");
    printf("%c: Azul.\n", AZUL);
    printf("%c: Amarillo.\n", AMARILLO);
    printf("%c: Verde.\n", VERDE);
    printf("%c: Negro.\n", NEGRO);
    printf("%c: Blanco.\n", BLANCO);
    printf("%c: Rosa.\n", ROSA);
    scanf(" %c", color);

    while(!((*color) == AZUL || (*color) == AMARILLO || (*color) == VERDE ||
                (*color) == NEGRO || (*color) == BLANCO || (*color) == ROSA)){
        printf("Introdujiste una opcion de color distinta de (%c, %c, %c, %c, %c o %c).\n",
                AZUL, AMARILLO, VERDE, NEGRO, BLANCO ,ROSA);
        printf("Introduce nuevamente una opcion de color entre (%c, %c, %c, %c, %c o %c):\n",
                AZUL, AMARILLO, VERDE, NEGRO, BLANCO, ROSA);
        scanf(" %c", color);
    }
}

/*
*   Pre:
*       - Ninguna.
*   Post:
*       - altura sera un numero entre (MIN_ALTURA y MAX_ALTURA).
*/
void definir_altura(int* altura){

    printf("Introduce tu altura, entre (%i y %i):\n", MIN_ALTURA, MAX_ALTURA);
    scanf("%i", altura);
    while((*altura) < MIN_ALTURA || (*altura) > MAX_ALTURA){
        printf("Introdujiste un numero fuera del rango de (%i y %i)\n",
                MIN_ALTURA, MAX_ALTURA);
        printf("Introduce nuevamente un numero entre (%i y %i):\n",
                MIN_ALTURA, MAX_ALTURA);
        scanf("%i", altura);
    }
}

/*
*   Pre:
*       - color será un caracter entre (AZUL, AMARILLO, VERDE, NEGRO, BLANCO o
*       ROSA).
*   Post:
*       - Retornara MIN_PUNTOS, MED_PUNTOS o MAX_PUNTOS puntos segun su condicion.
*/
int puntos_por_color(char color){
    int puntosColor;

    if(color == ROSA || color == AMARILLO){
        puntosColor = MIN_PUNTOS;
    } else if (color == NEGRO || color == BLANCO){
        puntosColor = MED_PUNTOS;
    } else {
        puntosColor = MAX_PUNTOS;
    }
    return puntosColor;
}

/*
*   Pre:
*       - sabor será un caracter entre (DULCE, SALADO, o AMARGO)
*   Post:
*       - Retornara MIN_PUNTOS, MED_PUNTOS o MAX_PUNTOS puntos segun su condicion
*/
int puntos_por_sabor(char sabor){
    int puntosSabor;

    if(sabor == SALADO){
        puntosSabor = MIN_PUNTOS;
    } else if (sabor == DULCE){
        puntosSabor = MED_PUNTOS;
    } else {
        puntosSabor = MAX_PUNTOS;
    }
    return puntosSabor;
}

/*
*   Pre:
*       - fecha sera un número entero entre MIN_FECHA  y MAX_FECHA.
*   Post:
*       - Retornara la operacion del resto (%) de la (fecha entre 20) + 1
*/
int puntos_por_fecha(int fecha){
    int puntosFecha;
    puntosFecha = (fecha % NUMERO_DIV);
    puntosFecha++;
    return puntosFecha;
}

/*
*   Pre:
*       - talla será un numero entero entre MIN_TALLA_ZAPATOS y
*       MAX_TALLA_ZAPATOS o SIN_ZAPATOS.
*   Post:
*       - Retornara un numero MULTIPLICADOR_1, MULTIPLICADOR_2, MULTIPLICADOR_3 o MULTIPLICADOR_4 segun sea la condicion.
*/
int multiplicador_por_talla(int talla){
    int multiplicadorTalla;

    if(talla == SIN_ZAPATOS){
        multiplicadorTalla = MULTIPLICADOR_1;
    } else if (talla >= MIN_TALLA_ZAPATOS && talla <= MAX_RANGO_TALLA1){
        multiplicadorTalla = MULTIPLICADOR_2;
    } else if (talla > MAX_RANGO_TALLA1 && talla <= MAX_RANGO_TALLA2){
        multiplicadorTalla = MULTIPLICADOR_3;
    } else {
        multiplicadorTalla = MULTIPLICADOR_4;
    }
    return multiplicadorTalla;
}

/*
*   Pre:
*       - Introduce por parametros primero los puntos Obtenidos y por ultimo un multiplicador.
*   Post:
*       - Retornara una suma de todos los puntos obtenidos multiplicados por el multiplicador.
*/
int calcular_puntos_totales(int puntosA, int puntosB, int puntosC, int multiplicador){
    return (puntosA+puntosB+puntosC)*multiplicador;
}

/*
*   Pre:
*       - Introduce 2 personajes con sus respectivas alturas definidas.
*       - Introduces la altura del personaje que deseas determinar.
*   Post:
*       - Quedaran 2 numeros con las diferencias respectivas de los personajes.
*       - Retornara el personaje determinado.
*/
char determina_entre_dupla_personaje(int alturaPersonaje, char personaje1,
        int alturaPersonaje1, char personaje2, int alturaPersonaje2){
    char personaje;
    int diferencia_personaje_1;
    int diferencia_personaje_2;

    diferencia_personaje_1 = abs(alturaPersonaje1 - alturaPersonaje);
    diferencia_personaje_2 = abs(alturaPersonaje2 - alturaPersonaje);

    if(diferencia_personaje_1 > diferencia_personaje_2){
        personaje = personaje2;
    } else if (diferencia_personaje_1 == diferencia_personaje_2) {
        personaje = personaje1;
    } else {
	personaje = personaje1;
    }
    return personaje;
}

/*
*   Pre:
*       - Introduces los puntosTotales calculados y la altura del Personaje.
*   Post:
*       - Retornara el personaje determinado segun sea la condicion definida.
*/
char calcula_personaje(int puntosTotales, int alturaPersonaje){
    char personaje;

    if(puntosTotales >= MIN_RANGO_PERSONAJE1 && puntosTotales <= MAX_RANGO_PERSONAJE1){
        personaje = determina_entre_dupla_personaje(alturaPersonaje, JOHNNY_BRAVO,
                ALTURA_JOHNNY_BRAVO, CORAJE, ALTURA_CORAJE);
    } else if (puntosTotales > MAX_RANGO_PERSONAJE1 && puntosTotales <= MAX_RANGO_PERSONAJE2){
        personaje = determina_entre_dupla_personaje(alturaPersonaje, PURO_HUESO,
                ALTURA_PURO_HUESO, POLLITO, ALTURA_POLLITO);
    } else if ( puntosTotales > MAX_RANGO_PERSONAJE2 && puntosTotales <=MAX_RANGO_PERSONAJE3){
        personaje = determina_entre_dupla_personaje(alturaPersonaje, BLUE,
                ALTURA_BLUE, BELLOTA, ALTURA_BELLOTA);
    }
    return personaje;
}

/*
*   Pre:
*       - Introduces el puntaje total y el caracter del personaje determnado.
*   Post:
*       - Retornara la impresion del nombre del personaje segun la condicion definida.
*/
void imprimir_resultado(int puntaje, char personaje){
    if (personaje == JOHNNY_BRAVO){
        printf("Con un puntaje de %i puntos se detecto el personaje - Johnny Bravo -.\n", puntaje);
    } else if (personaje == BELLOTA){
        printf("Con un puntaje de %i puntos se detecto el personaje - Bellota -.\n", puntaje);
    } else if (personaje == POLLITO){
        printf("Con un puntaje de %i puntos se detecto el personaje - Pollito -.\n", puntaje);
    } else if (personaje == BLUE){
        printf("Con un puntaje de %i puntos se detecto el personaje - Blue -.\n", puntaje);
    } else if (personaje == PURO_HUESO){
        printf("Con un puntaje de %i puntos se detecto el personaje - Puro Hueso -.\n", puntaje);
    } else if (personaje == CORAJE){
        printf("Con un puntaje de %i puntos se detecto el personaje - Coraje -.\n", puntaje);
    }
}

void detectar_personaje(char *personaje_detectado){
    // Variables del personaje
    int fechaPersonaje;
    int tallaPersonaje;
    int alturaPersonaje;
    char saborPersonaje;
    char colorPersonaje;

    // Variables de Puntos y Multiplicador
    int puntosFecha;
    int puntosSabor;
    int puntosColor;
    int multiplicadorTalla;
    int puntosTotales;

    definir_fecha_de_nacimiento(&fechaPersonaje);
    definir_preferencia_sabor(&saborPersonaje);
    definir_talla_zapatos(&tallaPersonaje);
    definir_color_preferido(&colorPersonaje);
    definir_altura(&alturaPersonaje);

    puntosColor = puntos_por_color(colorPersonaje);
    puntosSabor = puntos_por_sabor(saborPersonaje);
    puntosFecha = puntos_por_fecha(fechaPersonaje);
    multiplicadorTalla = multiplicador_por_talla(tallaPersonaje);

    puntosTotales = calcular_puntos_totales(puntosFecha, puntosSabor, puntosColor, multiplicadorTalla);
    *personaje_detectado = calcula_personaje(puntosTotales, alturaPersonaje);

    imprimir_resultado(puntosTotales, *personaje_detectado);
}

