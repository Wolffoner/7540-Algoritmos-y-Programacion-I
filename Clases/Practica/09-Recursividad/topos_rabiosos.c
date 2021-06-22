



typedef struct coordenada {
	int fil;
	int col;
} coordenada_t;

typedef struct pozo {
	int profundidad;
	coordenada_t proximo_pozo;
} pozo_t;




int cantidad_movimientos(pozo_t terreno[MAX_FILAS][MAX_COLUMNAS],
	coordenada_t pozo_actual){
	
	// condicion de corte
	int fil_siguiente = terreno[pozo_actual.fil][pozo_actual.col].proximo_pozo.fil;
	int col_siguiente = terreno[pozo_actual.fil][pozo_actual.col].proximo_pozo.col;
	if(fil_siguiente == pozo_actual.fil && col_siguiente == pozo_actual.col){
		return 0;
	}

	// llamada recursiva
	return 1 + cantidad_movimientos(terreno, terreno[pozo_actual.fil][pozo_actual.col].proximo_pozo);
}

int cant_mov(pozo_t terreno[MAX_FILAS][MAX_COLUMNAS]){
	coordenada_t inicio;
	inicio.fil = 0;
	inicio.col = 0;
	return cantidad_movimientos(terreno, inicio);
}