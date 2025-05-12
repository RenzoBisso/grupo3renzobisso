#include "tp_arboles.h"
#include "utilidades.h"




//2.A

void a_ej2_hojasR(NodoArbol n, Lista lHojas){
    if(n==NULL){
        return;
    }
    if(n_hijoizquierdo(n)==NULL && n_hijoderecho(n)==NULL){
        TipoElemento X=n_recuperar(n);
        printf("HOJA encontrada: %d\n", X->clave);
        l_agregar(lHojas,X);
    }
    a_ej2_hojasR(n_hijoizquierdo(n),lHojas);
    a_ej2_hojasR(n_hijoderecho(n),lHojas);
}

Lista a_ej2_hojas(ArbolBinario A){

    Lista lHojas=l_crear();
    NodoArbol nodo=a_raiz(A);
    a_ej2_hojasR(nodo,lHojas);
    return lHojas;
}

//2.B
void a_ej2_interioresR(NodoArbol n,Lista lInteriores){
    if(n==NULL){
        return;
    }

    if(n_hijoizquierdo(n) != NULL || n_hijoderecho(n) != NULL){
        TipoElemento X=n_recuperar(n);
        l_agregar(lInteriores,X);
    }

    a_ej2_interioresR(n_hijoizquierdo(n),lInteriores);
    a_ej2_interioresR(n_hijoderecho(n),lInteriores);
}

Lista a_ej2_interiores(ArbolBinario A){
    Lista lInteriores=l_crear();
    NodoArbol nodo=a_raiz(A);
    a_ej2_interioresR(nodo,lInteriores);
}

//2.C
Lista a_ej2_buscarclave(ArbolBinario A, int clave){

}