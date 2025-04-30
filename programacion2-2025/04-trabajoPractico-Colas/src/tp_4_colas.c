#include "utilidades.h"
#include "tp_4_colas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//ejercicio 2 A

bool c_ej2_existeclave(Cola c, int clave){
        
    bool flag=false;
    Cola cAux=c_crear();
    if(c_es_vacia(c)){
        return flag;
    }

    while (!c_es_vacia(c))
    {
        TipoElemento X=c_desencolar(c);
        if(X->clave==clave){
            flag=true;
        }
        c_encolar(cAux,X);
    }
    while (!c_es_vacia(c))
    {
        TipoElemento X=c_desencolar(cAux);
        c_encolar(c,X);
    }
    return flag;
}
//B
Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X){

    if(c_es_vacia(c)){
        return ;
    }
    int count=0;
    Cola cAux=c_crear();

    while (!c_es_vacia(c))
    {
        TipoElemento Y=c_desencolar(c);
        count++;
        if (count==posicionordinal)
        {
            free(Y);
            c_encolar(cAux,X);
        }
        c_encolar(cAux,Y);
        
    }
    
    while (!c_es_vacia(cAux))
    {
        TipoElemento Y=c_desencolar(cAux);
        c_encolar(c,Y);
        
    }
    
    return c;

}

//C
Cola c_ej2_sacarelemento(Cola c, int clave){

    if(c_es_vacia(c)){
        return ;
    }
    Cola cAux=c_crear();
    while (!c_es_vacia(c))
    {
        TipoElemento X=c_desencolar(c);
        if(X->clave == clave){
            free(X);
        }else{
            c_encolar(cAux,X);
        }
    }
    return cAux;
}

//D
int c_ej2_contarelementos(Cola c){
    int count=0;
    Cola cAux=c_crear();
    if(c_es_vacia(c)){
        return count;
    }
    while (!c_es_vacia(c))
    {
        count++;
        TipoElemento X=c_desencolar(c);
        c_encolar(cAux,X);        
    }
    
    while (!c_es_vacia(c))
    {
        TipoElemento X=c_desencolar(c);
        c_encolar(c,X);        
    }
    return count;

}

//E
Cola c_ej2_copiar(Cola c){
    if(c_es_vacia(c)){
        return ;
    }
    Cola cCopia=c_crear();
    int largoC1=c_ej2_contarelementos(c);
    int largoC2=0;

    while (largoC2!=largoC1)
    {
        largoC2++;
        TipoElemento X=c_desencolar(c);
        c_encolar(c,X);
        c_encolar(cCopia,X);
    }
    return cCopia;


}


//F
Cola c_ej2_invertir(Cola c){
    if(c_es_vacia(c)){
        return;
    }

    Pila p=p_crear();
    while(!c_es_vacia(c)){
        TipoElemento X=c_desencolar(c);
        p_apilar(p,X);
    }

    while(!p_es_vacia(p)){
        TipoElemento X=p_desapilar(p);
        c_encolar(c,X);
    }
    return c;
}


//3
bool c_ej3_iguales(Cola c1, Cola c2){

    if(c_es_vacia(c1)||c_es_vacia(c2)){
        return false;
    }
    if(c_ej2_contarelementos(c1)>c_ej2_contarelementos(c2)||c_ej2_contarelementos(c1)<c_ej2_contarelementos(c2)){
        return false;
    }
    Cola cAux=c_crear();
    bool flag=true;


    while(!c_es_vacia(c1)){
        TipoElemento X=c_desencolar(c1);
        TipoElemento Y=c_desencolar(c2);
        if(X->clave!=Y->clave){
            flag=false;
        }
        TipoElemento elementoValor=te_crear_con_valor(X->clave,Y->clave);
        c_encolar(cAux,elementoValor);
    }

    while (!c_es_vacia(cAux))
    {
        TipoElemento elementoValor=te_crear_con_valor(0,NULL);
        elementoValor=c_desencolar(cAux);
        TipoElemento X=te_crear(elementoValor->clave);
        TipoElemento Y=te_crear(elementoValor->valor);
        c_encolar(c1,X);
        c_encolar(c2,Y);
    }
    return flag;
}

//4
Cola  c_ej4_colanorepetidos(Cola c){
    if(c_es_vacia(c)){
        return;
    }

    int largo= c_ej2_contarelementos(c);
    int largoAux=0;
    Cola cSinRepetir=c_crear();
    Cola cAux=c_crear();

    while(largoAux!=largo){
        largoAux++;
        TipoElemento X=c_desencolar(c);
        if(!c_ej2_existeclave(c,X->clave)){
            c_encolar(cSinRepetir,X);
        }
        c_encolar(cAux,X);

    }

    while(!c_es_vacia(cAux)){
        TipoElemento X=c_desencolar(cAux);
        c_encolar(c,X);
    }

    return cSinRepetir;

}


