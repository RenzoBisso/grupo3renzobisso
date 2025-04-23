#include "..\headers\utilidades.h"
#include "..\headers\tp_3_pilas.h" //TEMPORAL

int main(){

    srand(time(NULL));

    //menu();

    char* texto = malloc(100 * sizeof(char));

    texto = p_ej4_cambiarbase(10, 2);

    printf("%s", texto);

    pausa();

    return 0;
}