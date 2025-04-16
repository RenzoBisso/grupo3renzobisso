#include "..\headers\utilidades.h"
#include "..\headers\tp_2_listas.h"

//PUNTO 2
//A-B
Lista verElementosQueNoSeRepiten(Lista l1, Lista l2){
    Lista lresultado = l_crear();

    Iterador iter1 = iterador(l1);

    TipoElemento X = te_crear(0);

    while(hay_siguiente(iter1)){
        X = siguiente(iter1);

        if(l_buscar(l2, X->clave) == NULL){
            l_agregar(lresultado, X);
        }
    }

    return lresultado;
}

//C
Lista verElementosRepetidos(Lista l1, Lista l2){
    Lista lresultado = l_crear();

    Iterador iter = iterador(l1);

    TipoElemento X = te_crear(0);


    while(hay_siguiente(iter)){
        X = siguiente(iter);

        if(l_buscar(l2, X->clave) != NULL){
            l_agregar(lresultado, X);
        }
    }

    return lresultado;
}

//D
float promedio(Lista l1){
    Iterador iter = iterador(l1);
    TipoElemento X = te_crear(0);
    float suma = 0;
    float cant = 0;

    while(hay_siguiente(iter)){
        suma += siguiente(iter)->clave;
        cant++;
    }
    float resultado = suma / cant;
    return resultado;
}

//E
ResultadoValorMinimo valorMinimo(Lista l1, Lista l2){ //EN REALIDAD BUSCA EL VALOR MÍNIMO, PERO ASÍ ESTÁ DECLARADO EN EL .h
    
    ResultadoValorMinimo resultado;

    Iterador iter1 = iterador(l1);
    Iterador iter2 = iterador(l2);

    TipoElemento X = te_crear(0);
    X = siguiente(iter1);

    int actual1 = X->clave;
    int i = 1;
    int pos1 = i;

    while(hay_siguiente(iter1)){
        i++;
        X = siguiente(iter1);
        if(X->clave < actual1){
            actual1 = X->clave;
            pos1 = i;
        }
    }

    X = siguiente(iter2);

    int actual2 = X->clave;
    i = 1;
    int pos2 = 1;

    while(hay_siguiente(iter2)){
        i++;
        X = siguiente(iter2);
        if(X->clave < actual2){
            actual2 = X->clave;
            pos2 = i;
        }
    }

    resultado.pos = pos1;
    resultado.valor = actual1;

    resultado.pos_2 = pos2;
    resultado.valor_2 = actual2;
    
    return resultado;
}

//
//
//
//
//

//PUNTO 3
ResultadosMul multiplo(Lista l1, Lista l2){
    Lista l3 = l_crear();
    
    Iterador iter1 = iterador(l1);
    Iterador iter2 = iterador(l2);
    Iterador iter3 = iterador(l3);

    TipoElemento X = te_crear(0);
    TipoElemento Y = te_crear(0);

    ResultadosMul resultado;

    int suma = 0;
    bool bandera = true;
    int actual;

    while(hay_siguiente(iter1) && hay_siguiente(iter2)){
        X = siguiente(iter1);
        Y = siguiente(iter2);
        if(Y->clave == 0 || es_decimal((float)X->clave / (float)Y->clave)){
            resultado.esMultiplo = false;
            resultado.escalar = false;
            resultado.numEscalar = 0;
            return resultado;
        }
        else{
            l_agregar(l3, te_crear(X->clave / Y->clave));
        }
    }
    
    X = siguiente(iter3);
    actual = X->clave;

    while(hay_siguiente(iter3)){
        X = siguiente(iter3);
        if(actual != X->clave){
            bandera = false;
            break;
        }
        actual = X->clave;
    }
    if(bandera){
        resultado.esMultiplo = true;
        resultado.escalar = true;
        resultado.numEscalar = X->clave;
        return resultado;
    }
    else{
        resultado.esMultiplo = true;
        resultado.escalar = false;
        resultado.numEscalar = 0;
        return resultado;
    }
    free(iter1);
    free(iter2);
    free(iter3);
    free(X);
    free(Y);
}

//PUNTO 4
int CompararListas(Lista l1, Lista l2){
    Iterador iter1 = iterador(l1);
    Iterador iter2 = iterador(l2);

    int sumal1 = 0;
    int sumal2 = 0;

    while(hay_siguiente(iter1)){
        sumal1 += siguiente(iter1)->clave;
    }
    
    while(hay_siguiente(iter2)){
        sumal2 += siguiente(iter2)->clave;
    }

    if(sumal1 > sumal2){
        return 1;
    }
    else if(sumal1 == sumal2){
        return 0;
    }
    else{
        return 2;
    }
}

//PUNTO 5
void hacerPolinomio(Lista list) {
    cargarLista(list,5,0);
}

Lista calcularRango(Lista list, double x, double y, double sumando) {
    
    Lista resultados = l_crear();
    
    TipoElemento aux = te_crear(0);

    double xRes = 0;
    
    while(x <= y){

        double* yRes = (double*)malloc(sizeof(double));//Dedicado a mi Transformer favorito
        *yRes = 0.0;

        int largo = l_longitud(list)-1;

        Iterador ite = iterador(list);

        while(hay_siguiente(ite)) {
            aux = siguiente(ite);//tomo el X del coeficiente

            xRes = aux->clave * (pow(x, largo));
            *yRes += xRes;
            largo--;

        }

        l_agregar(resultados, te_crear_con_valor(0, yRes));

        free(ite);

        x += sumando;
    }
    return resultados;
}

//PUNTO 6
bool esSublista(Lista l1, Lista l2){
    Iterador ite  = iterador(l2);

    bool resultado = true;

    while(hay_siguiente(ite)){

        TipoElemento x = siguiente(ite);

        if(l_buscar(l1, x->clave) == NULL ){
            resultado = false;
            }
        }

    return resultado;
}


