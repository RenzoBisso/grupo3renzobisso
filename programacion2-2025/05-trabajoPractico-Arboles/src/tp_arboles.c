#include "..\headers\tp_arboles.h"

#include "..\..\libs\validaciones\headers\utilidades.h"

// 2.A
void a_ej2_hojasR(NodoArbol n, Lista lHojas) {
    if (n == NULL) {
        return;
    }
    if (a_es_rama_nula(n_hijoizquierdo(n)) &&
        a_es_rama_nula(n_hijoderecho(n))) {
        TipoElemento X = n_recuperar(n);
        l_agregar(lHojas, X);
    }
    a_ej2_hojasR(n_hijoizquierdo(n), lHojas);
    a_ej2_hojasR(n_hijoderecho(n), lHojas);
}

Lista a_ej2_hojas(ArbolBinario A) {
    Lista lHojas = l_crear();
    NodoArbol nodo = a_raiz(A);
    a_ej2_hojasR(nodo, lHojas);
    return lHojas;
}

// 2.B
void a_ej2_interioresR(NodoArbol n, Lista lInteriores) {
    if (n == NULL) {
        return;
    }

    if (!a_es_rama_nula(n_hijoizquierdo(n)) ||
        !a_es_rama_nula(n_hijoderecho(n))) {
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

// 2.C
void a_ej2_buscarclaveR(NodoArbol nodo, int clave, Lista l) {
    if (nodo == NULL) {
        return;
    }
    TipoElemento x = n_recuperar(nodo);
    if (x->clave == clave) {
        TipoElemento nodoDevolver = te_crear_con_valor(clave, nodo);
        l_agregar(l, nodoDevolver);
    }

    a_ej2_buscarclaveR(n_hijoizquierdo(nodo), clave, l);
    a_ej2_buscarclaveR(n_hijoderecho(nodo), clave, l);
}

Lista a_ej2_buscarclave(ArbolBinario A, int clave) {
    Lista lClaves = l_crear();
    NodoArbol nodo = a_raiz(A);
    a_ej2_buscarclaveR(nodo, clave, lClaves);

    return lClaves;
}

// 3.A
void a_ej3_clavepadreR(NodoArbol nodo, int clavehijo, int* nodoPadre) {
    if (nodo == NULL) {
        return;
    }
    if (!a_es_rama_nula(n_hijoizquierdo(nodo)) &&
        n_recuperar(n_hijoizquierdo(nodo)) != NULL &&
        n_recuperar(n_hijoizquierdo(nodo))->clave == clavehijo) {
        *nodoPadre = n_recuperar(nodo)->clave;
        return;
    }

    if (!a_es_rama_nula(n_hijoderecho(nodo)) &&
        n_recuperar(n_hijoderecho(nodo)) != NULL &&
        n_recuperar(n_hijoderecho(nodo))->clave == clavehijo) {
        *nodoPadre = n_recuperar(nodo)->clave;
        return;
    }
    a_ej3_clavepadreR(n_hijoizquierdo(nodo), clavehijo, nodoPadre);
    a_ej3_clavepadreR(n_hijoderecho(nodo), clavehijo, nodoPadre);
}

int a_ej3_clavepadre(ArbolBinario A, int clavehijo) {
    if (a_es_vacio(A)) {
        return 0;
    }
    NodoArbol nodo = a_raiz(A);
    int* nodoPadre = malloc(sizeof(int));
    *nodoPadre = -1;
    a_ej3_clavepadreR(nodo, clavehijo, nodoPadre);
    return *nodoPadre;
}

// 3.B
void a_ej3_hijosR(NodoArbol nodo, int clavepadre, Lista lHijos) {
    if (nodo == NULL) {
        return;
    }
    TipoElemento x = n_recuperar(nodo);
    if (x->clave == clavepadre) {
        if (!a_es_rama_nula(n_hijoizquierdo(nodo)) &&
            n_recuperar(n_hijoizquierdo(nodo)) != NULL &&
            n_recuperar(n_hijoizquierdo(nodo))) {
            l_agregar(lHijos, n_recuperar(n_hijoizquierdo(nodo)));
        }
        if (n_hijoderecho(nodo) != NULL &&
            n_recuperar(n_hijoderecho(nodo)) != NULL &&
            n_recuperar(n_hijoderecho(nodo))) {
            l_agregar(lHijos, n_recuperar(n_hijoderecho(nodo)));
        }
    }
    a_ej3_hijosR(n_hijoizquierdo(nodo), clavepadre, lHijos);
    a_ej3_hijosR(n_hijoderecho(nodo), clavepadre, lHijos);
}

Lista a_ej3_hijos(ArbolBinario A, int clavepadre) {
    Lista lHijos = l_crear();
    if (a_es_vacio(A)) {
        return lHijos;
    }

    NodoArbol nodo = a_raiz(A);

    a_ej3_hijosR(nodo, clavepadre, lHijos);
    return lHijos;
}

// 3.C
void a_ej3_hermanoR(NodoArbol nodo, int clave, int* nodoHermano) {
    if (nodo == NULL)
        return;

    if ((!a_es_rama_nula(n_hijoizquierdo(nodo))) &&
        (n_recuperar(n_hijoizquierdo(nodo))->clave == clave)) {
        if (!a_es_rama_nula(n_hijoderecho(nodo))) {
            *nodoHermano = n_recuperar(n_hijoderecho(nodo))->clave;
        }
        return;
    }

    if ((!a_es_rama_nula(n_hijoderecho(nodo))) &&
        (n_recuperar(n_hijoderecho(nodo))->clave == clave)) {
        if (!a_es_rama_nula(n_hijoizquierdo(nodo))) {
            *nodoHermano = n_recuperar(n_hijoizquierdo(nodo))->clave;
        }
        return;
    }

    a_ej3_hermanoR(n_hijoizquierdo(nodo), clave, nodoHermano);
    a_ej3_hermanoR(n_hijoderecho(nodo), clave, nodoHermano);
}

int a_ej3_hermano(ArbolBinario A, int clave) {
    if (a_es_vacio(A)) {
        printf("Arbol vacio");
        return -1;
    }
    NodoArbol nodo = a_raiz(A);
    int* nodoHermano = malloc(sizeof(int));
    *nodoHermano = -1;
    a_ej3_hermanoR(nodo, clave, nodoHermano);
    return *nodoHermano;
}

// 3.D
int a_ej3_nivelR(NodoArbol nodo, int clave, int nivel) {
    if (nodo == NULL) {
        return -1;
    }

    TipoElemento x = n_recuperar(nodo);
    if (x->clave == clave) {
        return nivel;
    }

    int nivelIzq = a_ej3_nivelR(n_hijoizquierdo(nodo), clave, nivel + 1);
    if (nivelIzq != -1)
        return nivelIzq;

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

// 3.E
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

void altura_subarbol_desde_clave(NodoArbol nodo, int clave,
                                 int* alturaEncontrada) {
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

int a_ej3_alturarama(ArbolBinario A, int clave) {
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

// 3.F
void a_ej3_clavesmismonivelR(NodoArbol nodo, int nivelObjetivo, int nivelActual,
                             Lista lMismoNivel) {
    if (nodo == NULL) {
        return;
    }

    if (nivelActual == nivelObjetivo) {
        TipoElemento elemento = n_recuperar(nodo);
        l_agregar(lMismoNivel, elemento);
        return;
    }

    a_ej3_clavesmismonivelR(n_hijoizquierdo(nodo), nivelObjetivo,
                            nivelActual + 1, lMismoNivel);
    a_ej3_clavesmismonivelR(n_hijoderecho(nodo), nivelObjetivo, nivelActual + 1,
                            lMismoNivel);
}

Lista a_ej3_clavesmismonivel(ArbolBinario A, int nivel) {
    Lista lMismoNivel = l_crear();
    if (!a_es_vacio(A)) {
        a_ej3_clavesmismonivelR(a_raiz(A), nivel, 0, lMismoNivel);
    }
    return lMismoNivel;
}

// 4.A
Lista a_ej4_anchura(ArbolBinario A) {
    Lista lAnchura = l_crear();
    if (a_es_vacio(A))
        return lAnchura;

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

// 4.B
void a_ej4_q_hojasR(NodoArbol nodo, int* count) {
    if (nodo == NULL) {
        return;
    }

    if (a_es_rama_nula(n_hijoizquierdo(nodo))) {
        (*count)++;
    }
    a_ej4_q_hojasR(n_hijoizquierdo(nodo), count);
    a_ej4_q_hojasR(n_hijoderecho(nodo), count);
}

int a_ej4_q_hojas(ArbolBinario A) {
    if (a_es_vacio(A)) {
        return 0;
    }
    NodoArbol nodo = a_raiz(A);
    int count = 0;
    a_ej4_q_hojasR(nodo, &count);
    return count;
}

// 4.C
bool a_ej4_similaresSolucion(NodoArbol nA, NodoArbol nB) {
    if (nA == NULL && nB == NULL)
        return true;
    if ((nA == NULL && nB != NULL) || (nA != NULL && nB == NULL))
        return false;

    NodoArbol hijoA = n_hijoizquierdo(nA);
    NodoArbol hijoB = n_hijoizquierdo(nB);

    while (hijoA != NULL && hijoB != NULL) {
        if (!a_ej4_similaresSolucion(hijoA, hijoB))
            return false;
        hijoA = n_hijoderecho(hijoA);
        hijoB = n_hijoderecho(hijoB);
    }

    if (hijoA != NULL || hijoB != NULL)
        return false;

    return true;
}

bool a_ej4_similares(ArbolBinario A, ArbolBinario B) {
    NodoArbol nA = a_raiz(A);
    NodoArbol nB = a_raiz(B);
    return a_ej4_similaresSolucion(nA, nB);
}

// 4.D
TipoElemento a_ej4_padre(ArbolBinario A, int clave) {
    if (a_es_vacio(A))
        return NULL;

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
            if (n_recuperar(hijo)->clave == clave) {
                return n_recuperar(actual);
            }
            TipoElemento te_hijo = te_crear_con_valor(0, hijo);
            c_encolar(c, te_hijo);
            hijo = n_hijoderecho(hijo);
        }
    }

    return NULL;
}

// 4.E
void a_ej4_hermanosR(NodoArbol nodo, int clave, Lista lHermanos) {
    if (nodo == NULL) {
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
    a_ej4_hermanosR(n_hijoizquierdo(nodo), clave, lHermanos);
    a_ej4_hermanosR(n_hijoderecho(nodo), clave, lHermanos);
}

Lista a_ej4_hermanos(ArbolBinario A, int clave) {
    Lista lHermanos = l_crear();
    if (a_es_vacio(A)) {
        return lHermanos;
    }
    NodoArbol nodo = a_raiz(A);

    a_ej4_hermanosR(nodo, clave, lHermanos);
    return lHermanos;
}

// 7
bool a_ej7_equivalenteR(NodoArbol nA, NodoArbol nB) {
    if (nA == NULL && nB == NULL) {
        return true;
    }

    if (nA == NULL || nB == NULL) {
        return false;
    }

    TipoElemento A = n_recuperar(nA);
    TipoElemento B = n_recuperar(nB);
    if (A->clave != B->clave) {
        return false;
    }
    a_ej7_equivalenteR(n_hijoizquierdo(nA), n_hijoizquierdo(nB));
    a_ej7_equivalenteR(n_hijoderecho(nA), n_hijoderecho(nB));
}

bool a_ej7_equivalente(ArbolBinario A, ArbolBinario B) {
    if (a_es_vacio(A) || a_es_vacio(B)) {
        return false;
    }
    NodoArbol nA = a_raiz(A);
    NodoArbol nB = a_raiz(B);
    return a_ej7_equivalenteR(nA, nB);
}

// 8.1
int a_ej8_alturaR(NodoArbol nodo) {
    if (nodo == NULL) {
        return 0;
    }
    NodoArbol hijo = n_hijoizquierdo(nodo);
    int maxAltura = 0;
    while (hijo != NULL) {
        int alturaHijo = a_ej8_alturaR(hijo);
        if (alturaHijo > maxAltura) {
            maxAltura = alturaHijo;
        }
        hijo = n_hijoderecho(hijo);
    }
    return 1 + maxAltura;
}

int a_ej8_altura(ArbolBinario A) {
    if (a_es_vacio(A)) {
        return 0;
    }
    NodoArbol nodo = a_raiz(A);
    return a_ej8_alturaR(nodo);
}

// 8.2
int a_ej8_nivelR(NodoArbol nodo, int clave, int nivelActual) {
    if (nodo == NULL) {
        return 0;
    }

    if (n_recuperar(nodo)->clave == clave) {
        return nivelActual;
    }

    NodoArbol hijo = n_hijoizquierdo(nodo);
    while (hijo != NULL) {
        int resultado = a_ej8_nivelR(hijo, clave, nivelActual + 1);
        if (resultado != 0) {
            return resultado;
        }
        hijo = n_hijoderecho(hijo);
    }

    return 0;
}

int a_ej8_nivel(ArbolBinario A, int clave) {
    if (a_es_vacio(A)) {
        return 0;
    }
    return a_ej8_nivelR(a_raiz(A), clave, 0);
}

// 8.3
void a_ej8_internosR(NodoArbol nodo, Lista lInternos) {
    if (nodo == NULL) {
        return;
    }
    if (n_hijoizquierdo(nodo) != NULL) {
        TipoElemento x = n_recuperar(nodo);
        l_agregar(lInternos, x);
    }
    a_ej8_internosR(n_hijoizquierdo(nodo), lInternos);
    a_ej8_internosR(n_hijoderecho(nodo), lInternos);
}

Lista a_ej8_internos(ArbolBinario A) {
    Lista lInternos = l_crear();

    if (a_es_vacio(A)) {
        return lInternos;
    }

    NodoArbol nodo = a_raiz(A);
    if (n_hijoizquierdo(nodo) != NULL) {
        a_ej8_internosR(n_hijoizquierdo(nodo), lInternos);
    }

    return lInternos;
}

// 8.4
bool a_ej8_hojasmismonivelR(NodoArbol nodo, ArbolBinario A, int* aux) {
    if (nodo == NULL)
        return true;

    if (a_es_rama_nula(n_hijoizquierdo(nodo))) {
        int nivel = a_ej8_nivel(A, n_recuperar(nodo)->clave);
        if (*aux == 0) {
            *aux = nivel;
        } else if (nivel != *aux) {
            return false;
        }
    }

    bool izq = a_ej8_hojasmismonivelR(n_hijoizquierdo(nodo), A, aux);
    bool der = a_ej8_hojasmismonivelR(n_hijoderecho(nodo), A, aux);
    return izq && der;
}

bool a_ej8_hojasmismonivel(ArbolBinario A) {
    if (a_es_vacio(A))
        return false;
    int aux = 0;
    return a_ej8_hojasmismonivelR(a_raiz(A), A, &aux);
}

// PUNTO 9
void a_ej9_construir(ArbolAVL v, NodoArbol n) {
    if (!a_es_rama_nula(n)) {
        if (!avl_es_lleno(v)) {
            avl_insertar(v, n_recuperar(n));
        }
        a_ej9_construir(v, n_hijoizquierdo(n));
        a_ej9_construir(v, n_hijoderecho(n));
    }
}

ArbolAVL a_ej9_construiravl(ArbolBinario A) {
    ArbolAVL v = avl_crear();
    NodoArbol raiz = a_raiz(A);
    a_ej9_construir(v, raiz);
    return v;
}

int a_ej9_diferenciaalturas(ArbolBinario A, ArbolAVL AVL) {
    return alturaNodo(a_raiz(A)) - alturaNodo(avl_raiz(AVL));
}

// PUNTO 10
Lista a_ej10_generarlistaclaves(int cantidadclavesagenerar, int valorminimo,
                                int valormaximo) {
    Lista lClaves = l_crear();
    lRandomSinRepetir(lClaves, valorminimo, valormaximo, cantidadclavesagenerar,
                      0);
    return lClaves;
}

ArbolBinarioBusqueda a_ej10_crearABB(Lista L) {
    ArbolBinarioBusqueda abb = abb_crear();

    TipoElemento X = te_crear(0);
    Iterador iter = iterador(L);

    while (!abb_es_lleno(abb) || !hay_siguiente(iter)) {
        X = siguiente(iter);
        abb_insertar(abb, X);
    }

    return abb;
}

ArbolAVL a_ej10_crearAVL(Lista L) {
    ArbolAVL avl = avl_crear();

    TipoElemento X = te_crear(0);
    Iterador iter = iterador(L);

    while (!avl_es_lleno(avl) || !hay_siguiente(iter)) {
        X = siguiente(iter);
        avl_insertar(avl, X);
    }

    return avl;
}

int alturaABB(ArbolBinarioBusqueda abb) {
    if (abb_es_vacio(abb)) {
        return -1;
    }
    NodoArbol nodo = abb_raiz(abb);
    int altura = -1;
    int clave = n_recuperar(nodo)->clave;
    altura_subarbol_desde_clave(nodo, clave, &altura);
    if (altura == -1) {
        printf("Altura no encontrada\n");
    } else {
        return altura;
    }
}

int alturaAVL(ArbolAVL avl) {
    if (avl_es_vacio(avl)) {
        return -1;
    }
    NodoArbol nodo = avl_raiz(avl);
    int altura = -1;
    int clave = n_recuperar(nodo)->clave;
    altura_subarbol_desde_clave(nodo, clave, &altura);
    if (altura == -1) {
        printf("Altura no encontrada\n");
    } else {
        return altura;
    }
}

int a_ej10_difalturas(ArbolBinarioBusqueda ABB, ArbolAVL AVL) {
    int a = alturaABB(ABB);
    int b = alturaAVL(AVL);
    return (a - b);
}

Lista a_ej10_comparacionarboles(int N_repeticiones, int valorminimo,int valormaximo, int cantidaclavesagenerar) {
    int count = 0;

    Lista lComparaciones = l_crear();

    while (count < N_repeticiones) {

        Lista lClaves = a_ej10_generarlistaclaves(cantidaclavesagenerar, valorminimo, valormaximo);

        ArbolBinarioBusqueda abb = a_ej10_crearABB(lClaves);

        ArbolAVL avl = a_ej10_crearAVL(lClaves);

        TipoElemento aux = te_crear(a_ej10_difalturas(abb, avl));
        
        l_agregar(lComparaciones, aux);
        count++;
    }
    return lComparaciones;
}