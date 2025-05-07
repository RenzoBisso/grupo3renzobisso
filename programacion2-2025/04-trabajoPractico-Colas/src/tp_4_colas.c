#include "..\..\libs\validaciones\headers\utilidades.h"
#include "..\headers\tp_4_colas.h"
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
    while (!c_es_vacia(cAux))
    {
        TipoElemento X=c_desencolar(cAux);
        c_encolar(c,X);
    }
    return flag;
}
//B
Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X){

    if(c_es_vacia(c)){
        return c;
    }
    int count=0;
    Cola cAux=c_crear();
    TipoElemento Y=c_desencolar(c);

    while (!c_es_vacia(c))
    {
        
        count++;
        if (count==posicionordinal)
        {
            c_encolar(cAux,X);
        }
        c_encolar(cAux,Y);
        Y=c_desencolar(c);
    }
    
    while (!c_es_vacia(cAux))
    {
        Y=c_desencolar(cAux);
        c_encolar(c,Y);
        
    }
    
    return c;

}
//C
Cola c_ej2_sacarelemento(Cola c, int clave){

    if(c_es_vacia(c)){
        return c;
    }
    TipoElemento X;

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
    while (!c_es_vacia(cAux))
    {
        X=c_desencolar(cAux);
        c_encolar(c,X);
        
    }
    return c;
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
    
    while (!c_es_vacia(cAux))
    {
        TipoElemento X=c_desencolar(cAux);
        c_encolar(c,X);        
    }


    return count;

}
//E
Cola c_ej2_copiar(Cola c){
    if(c_es_vacia(c)){
        return c;
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
        return c;
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
        int clave=Y->clave;
        TipoElemento elementoValor=te_crear_con_valor(X->clave,&clave);
        c_encolar(cAux,elementoValor);
    }

    while (!c_es_vacia(cAux))
    {
        TipoElemento elementoValor=te_crear_con_valor(0,NULL);
        elementoValor=c_desencolar(cAux);
        TipoElemento X=te_crear(elementoValor->clave);
        TipoElemento Y = te_crear(*(int*)(elementoValor->valor));
        c_encolar(c1,X);
        c_encolar(c2,Y);
    }
    return flag;
}
//4
Cola  c_ej4_colanorepetidos(Cola c){
    Cola cCopia1 = c_crear();
    Cola cCopia2 = c_crear(); 
    Cola resultado = c_crear();

    
    while (!c_es_vacia(c)) {
        TipoElemento x = c_desencolar(c);
        c_encolar(cCopia1, x);
        c_encolar(cCopia2, x);
    }

    
    while (!c_es_vacia(cCopia1)) {
        TipoElemento x = c_desencolar(cCopia1);
        int repeticiones = 0;

        
        Cola aux = c_crear();
        while (!c_es_vacia(cCopia2)) {
            TipoElemento y = c_desencolar(cCopia2);
            if (x->clave == y->clave) {
                repeticiones++;
            }
            c_encolar(aux, y);
        }

        
        while (!c_es_vacia(aux)) {
            c_encolar(cCopia2, c_desencolar(aux));
        }

        if (repeticiones == 1) {
            c_encolar(resultado, x);
        }
    }

    
    while (!c_es_vacia(cCopia2)) {
        c_encolar(c, c_desencolar(cCopia2));
    }

    return resultado;

}


//EJERCICIO 5


Cola c_ej5_divisortotal(Cola c) {
    Cola resultado = c_crear();
    Cola copia1 = c_crear();
    Cola copia2 = c_crear();
    Cola aux = c_crear();
    TipoElemento te, te2;
    int total_elementos = 0;

    while (!c_es_vacia(c)) {
        te = c_desencolar(c);
        c_encolar(copia1, te);
        c_encolar(aux, te); 
        total_elementos++;
    }

    while (!c_es_vacia(aux)) {
        c_encolar(c, c_desencolar(aux));
    }

       while (!c_es_vacia(copia1)) {
        te = c_desencolar(copia1);
        int divisor = te->clave;
        int divisibles = 0;

        while (!c_es_vacia(c)) {
            te2 = c_desencolar(c);
            c_encolar(copia2, te2);
            c_encolar(aux, te2);  

            if (te2->clave % divisor == 0) {
                divisibles++;
            }
        }

        
        while (!c_es_vacia(aux)) {
            c_encolar(c, c_desencolar(aux));
        }

        
        if (divisibles == total_elementos || divisibles >= (total_elementos + 1) / 2){
            bool* es_total = malloc(sizeof(bool));
            *es_total = (divisibles == total_elementos);

            TipoElemento nuevo = te_crear_con_valor(divisor, es_total);
            c_encolar(resultado, nuevo);
        }

        
        while (!c_es_vacia(copia2)) {
            c_desencolar(copia2);
        }
    }

    return resultado;
}


//EJERCICIO 6
Lista c_ej6_comunesapilaycola(Pila p, Cola c){
    Pila pAux = p_crear();
    Cola cAux = c_crear();
    Lista l = l_crear();
    
    TipoElemento X;
    TipoElemento Y;

    int posP = 1;
    int posC = 1;

    while(!p_es_vacia(p)){
        X = p_desapilar(p);
        p_apilar(pAux, X);

        char *posiciones = (char*)malloc(sizeof(char));

        while(!c_es_vacia(c)){
            Y = c_recuperar(c);
            c_encolar(cAux, Y);

            if(X->clave == Y->clave){
                sprintf(posiciones, "%d:", posP);
                sprintf(posiciones, "%d:", posC);
            }
            posC++;
        }

        if(posiciones[0] != '\0'){
            l_agregar(l, te_crear_con_valor(X->clave, posiciones));
        }

        posC = 1;

        while(!c_es_vacia(cAux)){
            Y = c_recuperar(cAux);
            c_encolar(c, Y);
        }

        posP++;
    }

    while(!p_es_vacia(pAux)){
        X = p_desapilar(pAux);
        p_apilar(p, X);
    }

    return l;
}

//EJERCICIO 7
Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion){
    Cola res = c_crear();

    enumerar(c1);
    enumerar(c2);
    enumerar(c3);

    do{
        if(!c_es_vacia(c1)) atenderClientes(c1, res, tiempoatencion, 1);
        if(!c_es_vacia(c2)) atenderClientes(c2, res, tiempoatencion, 2);
        if(!c_es_vacia(c3)) atenderClientes(c3, res, tiempoatencion, 3);

    }while(!(c_es_vacia(c1) && c_es_vacia(c2) && c_es_vacia(c3)));
    return res;
}

void enumerar(Cola c){
    Cola aux = c_crear();
    TipoElemento X;

    int *count = (int*)malloc(sizeof(int));
    *count = 1;

    while(!c_es_vacia(c)){//SE DE UNA FUENTE DE BIEN QUE ESTE PROCESO SE PUEDE OPTIMIZAR, PERO NO TENGO GANAS DE CRANEARLO
        X = c_desencolar(c);
        c_encolar(aux, X);
    }
    while(!c_es_vacia(aux)){
        X = c_desencolar(aux);
        c_encolar(c, te_crear_con_valor(X->clave, count));
        (*count)++;
    }
}

void atenderClientes(Cola c, Cola resultado, int tiempoatencion, int nroC){
    TipoElemento X = c_recuperar(c);

    X->clave -= tiempoatencion;

    if(X->clave <= 0){//GUARDAMOS LOS DATOS DEL CLIENTE
        c_encolar(resultado, te_crear_con_valor(nroC, X->valor));
        c_desencolar(c);
    }
}

