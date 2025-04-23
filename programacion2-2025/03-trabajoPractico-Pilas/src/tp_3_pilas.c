#include "..\headers\utilidades.h"
#include "..\headers\tp_3_pilas.h"

//EJERCICIO 2
//A
bool p_ej2_existeclave(Pila p, int clave){
    bool res = false;
    Pila aux = p_crear();
    TipoElemento X;

    while(!p_es_vacia(p)){//BUSCO COINCIDENCIAS
        X = p_desapilar(p);
        if(X->clave == clave){
            res = true;
        }
        p_apilar(aux, X);
    }

    while(!p_es_llena(p)){//RESTAURO LA PILA ORIGINAL
        X = p_desapilar(aux);
        p_apilar(p, X);
    }

    free(aux);
    return res;
}

//B
Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x){
    int count = 1;
    Pila aux = p_crear();
    TipoElemento X;

    while(!p_es_vacia(p)){//VACIAMOS LA PILA
        X = p_desapilar(p);
        p_apilar(aux, X);
    }

    while(!p_es_llena(p)){//INSERTAMOS ELEMENTO
        if(count == posicionordinal){
            p_apilar(p, x);
        }
        X = p_desapilar(aux);
        p_apilar(p, X);
        count++;
    }

    free(aux);
    return p;
}

//C
Pila p_ej2_eliminarclave(Pila p, int clave){
    Pila aux = p_crear();
    TipoElemento X;

    while(!p_es_vacia(p)){//VACIAMOS LA PILA
        X = p_desapilar(p);
        p_apilar(aux, X);
    }

    while(!p_es_llena(p)){//INSERTAMOS ELEMENTO Y OMITIMOS LA CLAVE
        X = p_desapilar(aux);
        if(X->clave != clave){
            p_apilar(p, X);
        }
    }

    free(aux);
    return p;
}

//D
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2){
    
}