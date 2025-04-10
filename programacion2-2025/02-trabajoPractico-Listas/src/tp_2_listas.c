#include "..\headers\utilidades.h"
#include "..\headers\tp_2_listas.h"

//PUNTO 2
//A Y B
Lista verElementosQueNoSeRepiten(Lista l1, Lista l2){
    Lista lresultado = l_crear();

    Iterador iter1 = iterador(l1);

    TipoElemento x = te_crear(0);
    TipoElemento y = te_crear(0);

    bool bandera;

    while(hay_siguiente(iter1)){
        x = siguiente(iter1);

        Iterador iter2 = iterador(l2);

        while(hay_siguiente(iter2)){
            y = siguiente(iter2);
            if(x->clave != y->clave){
                bandera = false;
            }
        }
        if(!bandera){
            l_agregar(lresultado, x);
        }

        bandera = true;
        free(iter2);
    }

    return lresultado;
}

//C
Lista verElementosRepetidos(Lista l1, Lista l2){
    Lista lresultado = l_crear();

    Iterador iter1 = iterador(l1);

    TipoElemento x = te_crear(0);
    TipoElemento y = te_crear(0);

    bool bandera;

    while(hay_siguiente(iter1)){
        x = siguiente(iter1);

        Iterador iter2 = iterador(l2);

        while(hay_siguiente(iter2)){
            y = siguiente(iter2);
            if(x->clave == y->clave){
                bandera = false;
            }
        }
        if(!bandera){
            l_agregar(lresultado, x);
        }

        bandera = true;
        free(iter2);
    }

    return lresultado;
}

//D
float promedio(Lista l1){}




