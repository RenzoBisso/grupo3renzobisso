#include "tp_conjunto.h"

#include <stdio.h>

// ---------- PUNTO 2 ----------
Conjunto c_ej2_union(Conjunto A, Conjunto B) {
    Conjunto U = cto_crear();
    TipoElemento X;
    int i;

    for (i = 1; i <= cto_cantidad_elementos(A); i++) {
        X = cto_recuperar(A, i);
        cto_agregar(U, X);
    }
    for (i = 1; i <= cto_cantidad_elementos(B); i++) {
        X = cto_recuperar(B, i);
        cto_agregar(U, X);
    }

    return U;
}

Conjunto c_ej2_interseccion(Conjunto A, Conjunto B) {
    Conjunto I = cto_crear();
    TipoElemento X;

    for (int i = 1; i <= cto_cantidad_elementos(A); i++) {
        X = cto_recuperar(A, i);
        if (cto_pertenece(B, X->clave)) {
            cto_agregar(I, X);
        }
    }

    return I;
}

Conjunto c_ej2_diferencia(Conjunto A, Conjunto B) {
    Conjunto D = cto_crear();
    TipoElemento X;

    for (int i = 1; i <= cto_cantidad_elementos(A); i++) {
        X = cto_recuperar(A, i);
        if (!cto_pertenece(B, X->clave)) {
            cto_agregar(D, X);
        }
    }

    return D;
}

bool c_ej2_pertenencia(Conjunto A, int elemento) {
    return cto_pertenece(A, elemento);
}

// ---------- PUNTO 3 ----------
Conjunto c_ej3_uniones(Lista l) {
    Conjunto resultado = cto_crear();
    if (l_es_vacia(l))
        return resultado;

    Iterador it = iterador(l);
    while (hay_siguiente(it)) {
        TipoElemento X = siguiente(it);
        Conjunto c = (Conjunto)X->valor;
        resultado = cto_union(resultado, c);
    }

    return resultado;
}

Conjunto c_ej3_intersecciones(Lista l) {
    if (l_es_vacia(l))
        return cto_crear();

    Iterador it = iterador(l);
    TipoElemento X = siguiente(it);
    Conjunto resultado = (Conjunto)X->valor;

    while (hay_siguiente(it)) {
        X = siguiente(it);
        Conjunto c = (Conjunto)X->valor;
        resultado = cto_interseccion(resultado, c);
    }

    return resultado;
}

// ---------- PUNTO 4 ----------
bool c_ej4_transitividad(Conjunto A, Conjunto B, Conjunto C) {
    return cto_es_subconjunto(A, B) && cto_es_subconjunto(B, C) &&
           cto_es_subconjunto(A, C);
}

// ---------- PUNTO 5 ----------
Conjunto c_ej5_dif_simetrica(Conjunto A, Conjunto B) {
    Conjunto resultado = cto_union(cto_diferencia(A, B), cto_diferencia(B, A));
    return resultado;
}

// ---------- PUNTO 6 ----------
bool c_ej6_subconjuntopropio(Conjunto A, Conjunto B) {
    return cto_es_subconjunto(A, B) && !cto_es_subconjunto(B, A);
}

// ---------- PUNTO 7 ----------
void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C) {
    Conjunto conjuntos[] = {A, B, C};
    const char* nombres[] = {"A", "B", "C"};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                int comunes = 0;
                int total = cto_cantidad_elementos(conjuntos[i]);
                for (int k = 1; k <= total; k++) {
                    TipoElemento X = cto_recuperar(conjuntos[i], k);
                    if (cto_pertenece(conjuntos[j], X->clave)) {
                        comunes++;
                    }
                }

                if (comunes == total) {
                    printf("%s es subconjunto TOTAL de %s\n", nombres[i],
                           nombres[j]);
                } else if (comunes >= (total / 2)) {
                    printf("%s es subconjunto PARCIAL de %s\n", nombres[i],
                           nombres[j]);
                }
            }
        }
    }
}

// ---------- PUNTO 8 ----------
bool c_ej8_soniguales(Conjunto A, Conjunto B) {
    if (cto_cantidad_elementos(A) != cto_cantidad_elementos(B)) {
        return false;
    }

    for (int i = 1; i <= cto_cantidad_elementos(A); i++) {
        TipoElemento X = cto_recuperar(A, i);
        if (!cto_pertenece(B, X->clave)) {
            return false;
        }
    }

    return true;
}
