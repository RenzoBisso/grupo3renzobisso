#include "..\headers\utilidades.h"
#include "..\headers\tp_3_pilas.h" //TEMPORAL
#include "..\headers\tp_3_pilas.h"


int main(){

    srand(time(NULL));

    //menu();

    char* texto = malloc(100 * sizeof(char));

    texto = p_ej4_cambiarbase(10, 16);

    printf("%s\n", texto);
    printf("Prueba");
    pausa();

    return 0;
}