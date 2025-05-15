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

int a_ej3_nivelR(NodoArbol nodo, int clave, int nivel) {
    if (nodo == NULL) {
        return -1;
    }

    TipoElemento x = n_recuperar(nodo);
    if (x->clave == clave) {
        return nivel;
    }

    int nivelIzq = a_ej3_nivelR(n_hijoizquierdo(nodo), clave, nivel + 1);
    if (nivelIzq != -1) return nivelIzq;

    int nivelDer = a_ej3_nivelR(n_hijoderecho(nodo), clave, nivel + 1);
    return nivelDer;
}

int a_ej3_nivel(ArbolBinario A, int clave) {
    if (a_es_vacio(A)) {
        printf("Árbol vacío\n");
        return -1;
    }

    NodoArbol raiz = a_raiz(A);
    return a_ej3_nivelR(raiz, clave, 0);
}

int a_ej3_alturaramaR(NodoArbol nodo) {
    if (nodo == NULL) {
        return -1;
    }

    int hIzq = a_ej3_alturaramaR(n_hijoizquierdo(nodo));
    int hDer = a_ej3_alturaramaR(n_hijoderecho(nodo));

    int max;
    if (hIzq > hDer) {
        max = hIzq;
    } else {
        max = hDer;
    }

    return 1 + max;
}

void altura_subarbol_desde_clave(NodoArbol nodo, int clave, int* alturaEncontrada) {
    if (nodo == NULL || *alturaEncontrada != -1) {
        return;
    }

    TipoElemento x = n_recuperar(nodo);

    if (x->clave == clave) {
        *alturaEncontrada = a_ej3_alturaramaR(nodo);
        return;
    }

    altura_subarbol_desde_clave(n_hijoizquierdo(nodo), clave, alturaEncontrada);
    altura_subarbol_desde_clave(n_hijoderecho(nodo), clave, alturaEncontrada);
}





int a_ej3_alturarama(ArbolBinario A, int clave){
    if (a_es_vacio(A)) {
        printf("Árbol vacío\n");
        return -1;
    }

    int altura = -1;
    altura_subarbol_desde_clave(a_raiz(A), clave, &altura);

    if (altura == -1) {
        printf("Clave no encontrada\n");
    }
    return altura;
}

void a_ej3_clavesmismonivelR(NodoArbol nodo, int nivelObjetivo, int nivelActual, Lista lMismoNivel) {
    if (nodo == NULL) {
        return;
    }

    if (nivelActual == nivelObjetivo) {
        TipoElemento elemento = n_recuperar(nodo);
        l_agregar(lMismoNivel, elemento);
        return;
    }

    a_ej3_clavesmismonivelR(n_hijoizquierdo(nodo), nivelObjetivo, nivelActual + 1, lMismoNivel);
    a_ej3_clavesmismonivelR(n_hijoderecho(nodo), nivelObjetivo, nivelActual + 1, lMismoNivel);
}

Lista a_ej3_clavesmismonivel(ArbolBinario A, int nivel) {
    Lista lMismoNivel = l_crear();
    if (!a_es_vacio(A)) {
        a_ej3_clavesmismonivelR(a_raiz(A), nivel, 0, lMismoNivel);
    }
    return lMismoNivel;
}


Lista a_ej4_anchura(ArbolBinario A) {
    Lista lAnchura = l_crear();
    if (a_es_vacio(A)) return lAnchura;

    Cola c = c_crear();

    // Encolar la raíz como referencia
    NodoArbol raiz = a_raiz(A);
    TipoElemento te_raiz = te_crear_con_valor(0, raiz);
    c_encolar(c, te_raiz);

    while (!c_es_vacia(c)) {
        // Desencolamos el TipoElemento y recuperamos el Nodo
        TipoElemento te_nodo = c_desencolar(c);
        NodoArbol actual = te_nodo->valor;

        // Agregamos el dato del nodo a la lista final
        TipoElemento dato = n_recuperar(actual);
        l_agregar(lAnchura, dato);

        // Encolar todos los hijos del nodo actual
        NodoArbol hijo = n_hijoizquierdo(actual);
        while (hijo != NULL) {
            TipoElemento te_hijo = te_crear_con_valor(0, hijo);
            c_encolar(c, te_hijo);
            hijo = n_hijoderecho(hijo);
        }
    }
    return lAnchura;
}




void a_ej4_q_hojasR(NodoArbol nodo,int* count){
    if(nodo==NULL){
        return;
    }

    if(n_hijoizquierdo(nodo)==NULL){
        (*count)++;
    }
    a_ej4_q_hojasR(n_hijoizquierdo(nodo),count);
    a_ej4_q_hojasR(n_hijoderecho(nodo),count);
}

int a_ej4_q_hojas(ArbolBinario A){
    if(a_es_vacio(A)){
        return 0;
    }
    NodoArbol nodo=a_raiz(A);
    int count =0;
    a_ej4_q_hojasR(nodo,&count);
    return count;
}

bool a_ej4_similaresSolucion(NodoArbol nA, NodoArbol nB) {
    if (nA == NULL && nB == NULL) return true;
    if ((nA == NULL && nB != NULL) || (nA != NULL && nB == NULL)) return false;

    NodoArbol hijoA = n_hijoizquierdo(nA);
    NodoArbol hijoB = n_hijoizquierdo(nB);

    while (hijoA != NULL && hijoB != NULL) {
        if (!a_ej4_similaresSolucion(hijoA, hijoB)) return false;
        hijoA = n_hijoderecho(hijoA);
        hijoB = n_hijoderecho(hijoB);
    }

    if (hijoA != NULL || hijoB != NULL) return false;

    return true;
}

bool a_ej4_similares(ArbolBinario A, ArbolBinario B) {
    NodoArbol nA = a_raiz(A);
    NodoArbol nB = a_raiz(B);
    return a_ej4_similaresSolucion(nA, nB);
}




TipoElemento a_ej4_padre(ArbolBinario A, int clave){
    if (a_es_vacio(A)) return NULL;

    Cola c = c_crear();

    // Encolar la raíz como referencia
    NodoArbol raiz = a_raiz(A);
    TipoElemento te_raiz = te_crear_con_valor(0, raiz);
    c_encolar(c, te_raiz);

    while (!c_es_vacia(c)) {
        // Desencolamos el TipoElemento y recuperamos el Nodo
        TipoElemento te_nodo = c_desencolar(c);
        NodoArbol actual = te_nodo->valor;

        // Agregamos el dato del nodo a la lista final
        TipoElemento dato = n_recuperar(actual);
        // Encolar todos los hijos del nodo actual
        NodoArbol hijo = n_hijoizquierdo(actual);
        while (hijo != NULL) {
            if(n_recuperar(hijo)->clave==clave){
                return n_recuperar(actual);
            }
            TipoElemento te_hijo = te_crear_con_valor(0, hijo);
            c_encolar(c, te_hijo);
            hijo = n_hijoderecho(hijo);
        }
    }
    
    return NULL;
}

void a_ej4_hermanosR(NodoArbol nodo, int clave,Lista lHermanos){

    if(nodo==NULL){
        return;
    }

    NodoArbol hijo = n_hijoizquierdo(nodo);
    while (hijo != NULL) {
        if (n_recuperar(hijo)->clave == clave) {
        // Encontramos al hijo con la clave, ahora nodo es el padre
        NodoArbol hermano = n_hijoizquierdo(nodo);
            while (hermano != NULL) {
                if (n_recuperar(hermano)->clave != clave) {
                    l_agregar(lHermanos, n_recuperar(hermano));
                }
            hermano = n_hijoderecho(hermano);
        }
            return;
        }
        hijo = n_hijoderecho(hijo);
    }
    a_ej4_hermanosR(n_hijoizquierdo(nodo),clave,lHermanos);
    a_ej4_hermanosR(n_hijoderecho(nodo),clave,lHermanos);

}


Lista a_ej4_hermanos(ArbolBinario A, int clave){
    Lista lHermanos=l_crear();
    if(a_es_vacio(A)){
        return lHermanos;
    }
    NodoArbol nodo=a_raiz(A);

    a_ej4_hermanosR(nodo,clave,lHermanos);
    return lHermanos;

}