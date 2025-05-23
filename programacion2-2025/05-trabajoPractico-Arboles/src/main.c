#include "arbol-binario.h"
#include "nodo.h"
#include "listas.h"
#include "utilidades.h"
#include "tp_arboles.h"

int main(){
    /*
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
    lHijos=a_ej3_hijos(A,12);
    l_mostrar(lHijos);
    printf("\n");
    int hermano=a_ej3_hermano(A,5);
    printf("Hermano de %d es %d",5,hermano);
    printf("\n");
    int nivel=a_ej3_nivel(A,13);
    printf("Nivel del valor %d es %d",5,nivel);
    printf("\n");
    int altura=a_ej3_alturarama(A,9);
    printf("Altura de la rama del nodo %d es %d",5,altura);
    printf("\n");
    Lista lMismoNivel=l_crear();
    lMismoNivel=a_ej3_clavesmismonivel(A,2);
    l_mostrar(lMismoNivel);
    ArbolBinario NarioA=a_crear();
    cargar_arbol_binario(NarioA);
    ArbolBinario NarioB=a_crear();
    cargar_arbol_binario(NarioB);
    Lista lAnchura=a_ej4_anchura(NarioA);
    l_mostrar(lAnchura);
    int hojas=a_ej4_q_hojas(NarioA);
    printf("Cantidad de hojas que tiene el arbol n-ario es %d",hojas);
    printf("\n");
    bool esSimiliar=a_ej4_similares(NarioA,NarioB);
    printf("es similiar: %d",esSimiliar);
        TipoElemento elem=te_crear(a_ej4_padre(NarioA,5)->clave);
    printf("padre de %d es %d",5,elem->clave);
        Lista lHermanos=l_crear();
    lHermanos=a_ej4_hermanos(NarioA,2);
    l_mostrar(lHermanos);
        ArbolBinario NarioB=a_crear();
    cargar_arbol_binario(NarioB);
    bool equivalentes=a_ej7_equivalente(NarioA,NarioB);
    printf("Equivalencia : %d",equivalentes);
        int altura=a_ej8_altura(NarioA);
    printf("altura del arbol: %d",altura);
    int nivelActual=a_ej8_nivel(NarioA,9);
    printf("Nivel del %d es %d",9,nivelActual);
        Lista lInternos=a_ej8_internos(NarioA);
    l_mostrar(lInternos);
    */
    ArbolBinario NarioA=a_crear();
    cargar_arbol_binario(NarioA);
    bool mismoNivel=a_ej8_hojasmismonivel(NarioA);
    printf("Mismo nivel: %d",mismoNivel);
    return 0;
}