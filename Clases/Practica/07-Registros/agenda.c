#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_CELULAR 12
#define MAX_DIRECCION 50
#define MAX_CONTACTOS 100
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
	strcpy(contactos[0].direccion,"Elpela 777");
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
	contactos[3].borrado = false;
	(*cantidad_contactos)++;

	strcpy(contactos[4].nombre,"Santi");
	strcpy(contactos[4].celular,"1532228765");
	strcpy(contactos[4].direccion,"Tinchi 1232");
	contactos[4].favoritismo = 1;
	contactos[4].borrado = false;
	(*cantidad_contactos)++;

	strcpy(contactos[5].nombre,"Charly");
	strcpy(contactos[5].celular,"1598327752");
	strcpy(contactos[5].direccion,"Traperito 234");
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
	strcpy(agenda->duenio_agenda,"Marian");
	strcpy(agenda->celular,"1543759346");
	strcpy(agenda->grupo_sanguineo,"A+");
	agregar_contactos(agenda->contactos,&((*agenda).cantidad_contactos));
}

int buscar_contacto(contacto_t contactos[MAX_CONTACTOS], int cantidad_contactos, char nombre [MAX_NOMBRE]){
	int i = 0;
	int posicion = -1;
	while(i < cantidad_contactos && posicion == -1){
		if(strcmp(contactos[i].nombre,nombre) == 0 && contactos[i].borrado == false){
			posicion = i;
		}
		i++;
	}
	return posicion;
}

void borrar_contacto(agenda_t* agenda, char nombre[MAX_NOMBRE]){
	int posicion = buscar_contacto(agenda->contactos,agenda->cantidad_contactos,nombre);
	if(posicion != -1){
		agenda->contactos[posicion].borrado = true;
		printf("Te saque a un colab\n");
	}
}

void crear_contacto(agenda_t* agenda, char nombre[MAX_NOMBRE], char direccion[MAX_DIRECCION], char celular[MAX_CELULAR]){
	int posicion = buscar_contacto(agenda->contactos,agenda->cantidad_contactos,nombre);
	//int posicion_a_modificar = agenda->contactos[agenda->cantidad_contactos];
	if(posicion == -1){
		strcpy(agenda->contactos[agenda->cantidad_contactos].nombre,nombre);
		strcpy(agenda->contactos[agenda->cantidad_contactos].direccion,direccion);
		strcpy(agenda->contactos[agenda->cantidad_contactos].celular,celular);
		agenda->contactos[agenda->cantidad_contactos].favoritismo = 0;
		agenda->contactos[agenda->cantidad_contactos].borrado = false;
		agenda->cantidad_contactos++;
		printf("Se agrego un nuevo contacto\n");
	}
}

void modificar_contacto(agenda_t* agenda, char nombre[MAX_NOMBRE], char direccion[MAX_DIRECCION], char celular[MAX_CELULAR]){
	int posicion = buscar_contacto(agenda->contactos,agenda->cantidad_contactos,nombre);
	if(posicion != -1){
		if(strlen(direccion) > 0){
			strcpy(agenda->contactos[posicion].direccion,direccion);
			printf("Modifique la direccion de un contacto\n");
		}
		if(strlen(celular) > 0){
			strcpy(agenda->contactos[posicion].celular,celular);
			printf("Modifique el celular de un contacto\n");
		}
	}
}

int main(){
	
	agenda_t agenda;
	char nombre [MAX_NOMBRE];
	strcpy(nombre,"Berni");
	char nombre_a_agregar[MAX_NOMBRE];
	strcpy(nombre_a_agregar,"Rosi");
	char direccion[MAX_DIRECCION];
	strcpy(direccion,"Calle falsa 123");
	char celular[MAX_CELULAR];
	strcpy(celular,"1533333333");

	char nombre_a_modificar[MAX_NOMBRE];
	strcpy(nombre_a_modificar,"Charly");
	char direccion_nueva[MAX_DIRECCION];
	strcpy(direccion_nueva,"Petisito street 111");
	char otra_direccion_nueva[MAX_DIRECCION];

	strcpy(otra_direccion_nueva,"");
	char otro_nombre[MAX_NOMBRE];
	strcpy(otro_nombre,"Manu");
	char otro_celular_nuevo[MAX_CELULAR];
	strcpy(otro_celular_nuevo,"1555534255");
	char celular_nuevo[MAX_CELULAR];
	strcpy(celular_nuevo,"");

	crear_agenda(&agenda);

	for(int i = 0; i < agenda.cantidad_contactos; i++){
		if(agenda.contactos[i].borrado == false){
			printf("%s:\n",agenda.contactos[i].nombre);
			printf("\tDireccion: %s\n",agenda.contactos[i].direccion);
			printf("\tTelefono: %s\n\n",agenda.contactos[i].celular);
		}
	}

	borrar_contacto(&agenda,nombre);
	crear_contacto(&agenda,nombre_a_agregar,direccion,celular);
	modificar_contacto(&agenda,nombre_a_modificar,direccion_nueva,celular_nuevo);
	modificar_contacto(&agenda,otro_nombre,otra_direccion_nueva,otro_celular_nuevo);

	for(int i = 0; i < agenda.cantidad_contactos; i++){
		if(agenda.contactos[i].borrado == false){
			printf("%s:\n",agenda.contactos[i].nombre);
			printf("\tDireccion: %s\n",agenda.contactos[i].direccion);
			printf("\tTelefono: %s\n\n",agenda.contactos[i].celular);
		}
	}
	//printf("%s",agenda.duenio_agenda);

	return 0;
}