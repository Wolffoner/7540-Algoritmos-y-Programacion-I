#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_CELULAR 12
#define MAX_DIRECCION 50
#define MAX_CONTACTOS 100
#define MAX_FILTRO 100
#define MAX_GRUPO 4

typedef struct contacto {
	char nombre [MAX_NOMBRE];
	char celular [MAX_CELULAR];
	char direccion [MAX_DIRECCION];
	int favoritismo; //siendo 5 el max, 0 el min.
	bool borrado;
} contacto_t;

typedef struct agenda {
	char duenio_agenda [MAX_NOMBRE];
	char celular [MAX_CELULAR];
	char grupo_sanguineo [MAX_GRUPO];
	contacto_t contactos [MAX_CONTACTOS];
	int cantidad_contactos;
} agenda_t;

void agregar_contactos(contacto_t contactos[MAX_CONTACTOS], int* cantidad_contactos){
	(*cantidad_contactos) = 0;
	strcpy(contactos[0].nombre,"Manu");
	strcpy(contactos[0].celular,"1533446582");
	strcpy(contactos[0].direccion,"Los delfines 777");
	contactos[0].favoritismo = 4;
	contactos[0].borrado = false;
	(*cantidad_contactos)++;

	strcpy(contactos[1].nombre,"Sol");
	strcpy(contactos[1].celular,"1532740977");
	strcpy(contactos[1].direccion,"Lamejorcolab 343");
	contactos[1].favoritismo = 5;
	contactos[1].borrado = false;
	(*cantidad_contactos)++;

	strcpy(contactos[2].nombre,"Tomi");
	strcpy(contactos[2].celular,"1523548873");
	strcpy(contactos[2].direccion,"Tomidios 39");
	contactos[2].favoritismo = 5;
	contactos[2].borrado = false;
	(*cantidad_contactos)++;

	strcpy(contactos[3].nombre,"Berni");
	strcpy(contactos[3].celular,"1566729943");
	strcpy(contactos[3].direccion,"Navarrito 727");
	contactos[3].favoritismo = 3;
	contactos[3].borrado = true;
	(*cantidad_contactos)++;

	strcpy(contactos[4].nombre,"Santi");
	strcpy(contactos[4].celular,"1532228727");
	strcpy(contactos[4].direccion,"Tinchi 1232");
	contactos[4].favoritismo = 1;
	contactos[4].borrado = false;
	(*cantidad_contactos)++;

	strcpy(contactos[5].nombre,"Charly");
	strcpy(contactos[5].celular,"1598327752");
	strcpy(contactos[5].direccion,"Traperito 727");
	contactos[5].favoritismo = 0;
	contactos[5].borrado = false;
	(*cantidad_contactos)++;

	strcpy(contactos[6].nombre,"Delfi");
	strcpy(contactos[6].celular,"1509438876");
	strcpy(contactos[6].direccion,"Ositos 54");
	contactos[6].favoritismo = 4;
	contactos[6].borrado = false;
	(*cantidad_contactos)++;

	strcpy(contactos[7].nombre,"Rena");
	strcpy(contactos[7].celular,"1572007654");
	strcpy(contactos[7].direccion,"Petra 342");
	contactos[7].favoritismo = 3;
	contactos[7].borrado = false;
	(*cantidad_contactos)++;
}

void crear_agenda(agenda_t* agenda){
	strcpy(agenda->duenio_agenda,"Mariano");
	strcpy(agenda->celular,"1523356599");
	strcpy(agenda->grupo_sanguineo,"A+");
	agregar_contactos(agenda->contactos, &(agenda->cantidad_contactos));

}

void listar_agenda_aux(contacto_t contactos[MAX_CONTACTOS], int tope, int primero) {	
	// condicion de corte
	if (primero == tope){
		return;
	}
	
	printf("%s\n", contactos[primero].nombre);
	listar_agenda_aux(contactos, tope, primero++);
}

void listar_agenda(contacto_t contactos[MAX_CONTACTOS], int tope) {
	// preparacion de la rutina recursiva 
	listar_agenda_aux(contactos, tope, 0);
}




void listar_agenda(contacto_t contactos[MAX_CONTACTOS], int tope) {	
	// condicion de corte
	if (tope <= 0){
		return;
	}

	// llamada recursiva
	listar_agenda(contactos, tope - 1);
	
	// proceso
	printf("%s\n", contactos[tope-1].nombre);
}

int main(){
	
	agenda_t agenda;
	crear_agenda(&agenda);

	listar_agenda(agenda.contactos, agenda.cantidad_contactos);

	return 0;
}