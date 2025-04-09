#include "..\headers\utilidades.h"
#include "..\headers\tp_2_listas.h" //TEMPORAL

int main(){

    srand(time(NULL));

    Lista l1 = l_crear();
    Lista l2 = l_crear();

    while(!l_es_llena(l1)){
        l_agregar(l1, te_crear(rand() % 11));
    }

    while(!l_es_llena(l2)){
        l_agregar(l2, te_crear(rand() % 11));
    }

    printf("Lista 1: ");
    l_mostrar(l1);
    printf("\nListo 2: ");
    l_mostrar(l2);
    printf("\nElementos en comun: ");
    Lista resultado = l_crear();
    resultado = verElementosRepetidos(l1, l2);
    l_mostrar(resultado);
    printf("\n");

    
    system("pause");

    //menu();

    return 0;
}