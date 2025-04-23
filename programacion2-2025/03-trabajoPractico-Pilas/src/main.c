#include "..\headers\utilidades.h"
#include "..\headers\tp_3_pilas.h"


int main(){

    srand(time(NULL));

    //menu();

    char* texto = malloc(100 * sizeof(char));

    texto = p_ej4_cambiarbase(10, 2);

    printf("%s\n", texto);
    printf("Prueba\n");

    Pila p=p_crear();
    p_cargar(p);

    p_mostrar(p_ej5_invertir(p));
    Pila p2=p_crear();
    Pila pAux2=p_crear();

    p_cargar(p2);
    pAux2=p_ej6_eliminarclaveR(p2,1);
    p_mostrar(pAux2);
    pausa();

    return 0;
}