#include "..\headers\utilidades.h"
#include "..\headers\tp_3_pilas.h"

//EJERCICIO 2
//A
bool p_ej2_existeclave(Pila p, int clave){
    bool res = false;
    Pila aux = p_crear();
    TipoElemento X;

    while(p_es_llena(p)){//BUSCO COINCIDENCIAS
        X = p_desapilar(p);
        if(X->clave == clave){
            res = true;
        }
        p_apilar(aux, X);
    }

    while(p_es_vacia(p)){//RESTAURO LA PILA ORIGINAL
        X = p_desapilar(aux);
        p_apilar(p, X);
    }

    return res;
}