/*
 * Crear un struct para una cancion
 */
typedef struct cancion {
	int duracion;
	char genero; // R: Rock - P: Pop - T: Trap - L: Latino
	int cantidad_insultos;
	int bpm;
} cancion_t;

/*
 * Crear un struct para un artista que tiene muchas canciones
 */
typedef struct artista {
	int edad;
	char color_de_pelo;
	char genero_principal;
	int cantidad_discos;
	cancion_t mini_canciones[MAX_CANCIONES];
	int tope_canciones;
} artista_t;

int main(){

	/*artista_t charly;

	charly.petixo_me_dicen.duracion = 272;
	*/
	/*
	int nombre_del_vector[50];

	canciones_t mini_canciones[10];
	int tope;

	cargar_canciones_charly(mini_canciones, &tope);

	// tope == 3 
	mini_canciones[2].genero = 'T';
	*/
	artista_t charly;
	...
	// ponerle 50 insultos a la 4ta cancion de charly

	charly.mini_canciones[3].cantidad_insultos = 50;

	artista_t sol;


}