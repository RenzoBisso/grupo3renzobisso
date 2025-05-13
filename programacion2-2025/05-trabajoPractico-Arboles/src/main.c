#include "arbol-binario.h"
#include "nodo.h"
#include "listas.h"
#include "utilidades.h"
#include "tp_arboles.h"

int main(){
    srand(time(NULL));
    ArbolBinario A=a_crear();
    cargar_arbol_binario(A);

    printf("Pre-orden:");
    pre_orden(a_raiz(A));
    printf("\n");
    
    printf("In-orden:");
    in_orden(a_raiz(A));
    printf("\n");

    printf("Post-orden:");
    post_orden(a_raiz(A));
    printf("\n");

    Lista lHojas=l_crear();
    lHojas=a_ej2_hojas(A);
    l_mostrar(lHojas);
    printf("\n");
    Lista lInteriores=l_crear();
    lInteriores=a_ej2_interiores(A);
    l_mostrar(lInteriores);
    printf("\n");
    Lista lClaves=l_crear();
    lClaves=a_ej2_buscarclave(A,5);
    l_mostrar_con_nodo(lClaves);
    printf("\n");
    int result=a_ej3_clavepadre(A,5);
    printf("Nodo padre de nodo %d es %d",5,result);
    printf("\n");
    Lista lHijos=l_crear();
    lHijos=a_ej3_hijos(A,5);
    l_mostrar(lHijos);
    printf("\n");
    int hermano=a_ej3_hermano(A,5);
    printf("Hermano de %d es %d",5,hermano);


    return 0;
}