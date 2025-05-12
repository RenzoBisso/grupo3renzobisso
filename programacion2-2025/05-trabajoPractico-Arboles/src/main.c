#include "arbol-binario.h"
#include "nodo.h"
#include "listas.h"
#include "utilidades.h"
#include "tp_arboles.h"

int main(){

    ArbolBinario A=a_crear();
    cargar_arbol_binario(A);
    printf("in-orden\n");
    in_orden(a_raiz(A));
    printf("\n");
    printf("post-orden\n");
    post_orden(a_raiz(A));
    printf("\n");
    printf("pre-orden\n");
    pre_orden(a_raiz(A));
    printf("\n");
    Lista lHojas=l_crear();
    lHojas=a_ej2_hojas(A);
    l_mostrar(lHojas);


    return 0;
}