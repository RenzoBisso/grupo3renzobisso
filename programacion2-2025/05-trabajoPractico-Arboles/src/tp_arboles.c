#include "tp_arboles.h"
#include "utilidades.h"




//2.A

void a_ej2_hojasR(NodoArbol n, Lista lHojas){
    if(n==NULL){
        return;
    }
    if(n_hijoizquierdo(n)==NULL && n_hijoderecho(n)==NULL){
        TipoElemento X=n_recuperar(n);
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
void a_ej2_interioresR(NodoArbol n, Lista lInteriores) {
    if (n == NULL) {
        return;
    }

    
    if (n_hijoizquierdo(n) != NULL || n_hijoderecho(n) != NULL) {
        TipoElemento X = n_recuperar(n);  
        l_agregar(lInteriores, X);       
    }

    a_ej2_interioresR(n_hijoizquierdo(n), lInteriores);
    a_ej2_interioresR(n_hijoderecho(n), lInteriores);
}

Lista a_ej2_interiores(ArbolBinario A) {
    Lista lInteriores = l_crear();       
    NodoArbol nodo = a_raiz(A);          
    a_ej2_interioresR(nodo, lInteriores); 
    return lInteriores;                 
}
//2.C
void a_ej2_buscarclaveR(NodoArbol nodo, int clave,Lista l){
    if(nodo==NULL){
        return;
    }
        TipoElemento x=n_recuperar(nodo);
        if(x->clave==clave){
            TipoElemento nodoDevolver=te_crear_con_valor(0,nodo);
            l_agregar(l,nodoDevolver);
        }

    a_ej2_buscarclaveR(n_hijoizquierdo(nodo),clave,l);
    a_ej2_buscarclaveR(n_hijoderecho(nodo),clave,l);

}

Lista a_ej2_buscarclave(ArbolBinario A, int clave){
    Lista lClaves=l_crear();
    NodoArbol nodo=a_raiz(A);
    a_ej2_buscarclaveR(nodo,clave,lClaves);
    return lClaves;
}


void a_ej3_clavepadreR(NodoArbol nodo, int clavehijo,int* nodoPadre){

    if(nodo==NULL){
        return;
    }
    if (n_hijoizquierdo(nodo) != NULL && n_recuperar(n_hijoizquierdo(nodo)) != NULL &&
        n_recuperar(n_hijoizquierdo(nodo))->clave == clavehijo) {
        *nodoPadre = n_recuperar(nodo)->clave;
        return; 
    }

    if (n_hijoderecho(nodo) != NULL && n_recuperar(n_hijoderecho(nodo)) != NULL &&
        n_recuperar(n_hijoderecho(nodo))->clave == clavehijo) {
        *nodoPadre = n_recuperar(nodo)->clave;
        return;  
    }
    a_ej3_clavepadreR(n_hijoizquierdo(nodo),clavehijo,nodoPadre);
    a_ej3_clavepadreR(n_hijoderecho(nodo),clavehijo,nodoPadre);
}

int a_ej3_clavepadre(ArbolBinario A, int clavehijo){
    
    if(a_es_vacio(A)){
        return 0;
    }
    NodoArbol nodo=a_raiz(A);
    int* nodoPadre = malloc(sizeof(int));
    *nodoPadre = -1; 
    a_ej3_clavepadreR(nodo,clavehijo,nodoPadre);
    return *nodoPadre;
}


void a_ej3_hijosR(NodoArbol nodo, int clavepadre,Lista lHijos){
    if(nodo==NULL){
        return;
    }
        TipoElemento x=n_recuperar(nodo);
        if(x->clave==clavepadre){
            if(n_hijoizquierdo(nodo) != NULL && n_recuperar(n_hijoizquierdo(nodo)) != NULL && n_recuperar(n_hijoizquierdo(nodo))){
                l_agregar(lHijos,n_recuperar(n_hijoizquierdo(nodo)));
            }
            if(n_hijoderecho(nodo) != NULL && n_recuperar(n_hijoderecho(nodo)) != NULL && n_recuperar(n_hijoderecho(nodo))){
                l_agregar(lHijos,n_recuperar(n_hijoderecho(nodo)));
            }
        }
    a_ej3_hijosR(n_hijoizquierdo(nodo),clavepadre,lHijos);
    a_ej3_hijosR(n_hijoderecho(nodo),clavepadre,lHijos);
}

Lista a_ej3_hijos(ArbolBinario A, int clavepadre){
    Lista lHijos=l_crear();
    if(a_es_vacio(A)){
        return lHijos;
    }

    NodoArbol nodo=a_raiz(A);

    a_ej3_hijosR(nodo,clavepadre,lHijos);
    return lHijos;

}


void a_ej3_hermanoR(NodoArbol nodo, int clave, int* nodoHermano) {
    if (nodo == NULL) return;

    if ((n_hijoizquierdo(nodo) != NULL) && (n_recuperar(n_hijoizquierdo(nodo))->clave == clave)) {
        if (n_hijoderecho(nodo) != NULL) {
            *nodoHermano = n_recuperar(n_hijoderecho(nodo))->clave;
        }
        return;
    }

    if ((n_hijoderecho(nodo) != NULL) && (n_recuperar(n_hijoderecho(nodo))->clave == clave)) {
        if (n_hijoizquierdo(nodo) != NULL) {
            *nodoHermano = n_recuperar(n_hijoizquierdo(nodo))->clave;
        }
        return;
    }

    a_ej3_hermanoR(n_hijoizquierdo(nodo), clave, nodoHermano);
    a_ej3_hermanoR(n_hijoderecho(nodo), clave, nodoHermano);
}

int a_ej3_hermano(ArbolBinario A, int clave){

    if(a_es_vacio(A)){
        printf("Arbol vacio");
        return -1;
    }
    NodoArbol nodo=a_raiz(A);
    int* nodoHermano = malloc(sizeof(int));
    *nodoHermano = -1; 
    a_ej3_hermanoR(nodo,clave,nodoHermano);
    return *nodoHermano;
}

