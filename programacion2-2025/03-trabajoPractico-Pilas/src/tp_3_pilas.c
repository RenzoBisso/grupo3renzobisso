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
    Pila aux = p_crear();
    TipoElemento X;

    while(!p_es_vacia(p)){//VACIAMOS LA PILA
        X = p_desapilar(p);
        p_apilar(aux, X);
    }

    int count = largo(aux);

    while(!p_es_vacia(aux)){//INSERTAMOS ELEMENTO
        if(count == posicionordinal){
            p_apilar(p, x);
            X = p_desapilar(aux);//BASURA
        }
        X = p_desapilar(aux);
        p_apilar(p, X);
        count--;
    }

    free(aux);
    return p;
}

//C
Pila p_ej2_eliminarclave(Pila p, int clave){
    Pila aux = p_crear();
    TipoElemento X;
    bool llave = true;

    while(!p_es_vacia(p)){//VACIAMOS LA PILA Y OMITIMOS LA CLAVE
        X = p_desapilar(p);
        if(X->clave == clave && llave){
            llave = false;
            X = p_desapilar(p);
        }
        p_apilar(aux, X);
    }

    while(!p_es_vacia(aux)){//RESTAURAMOS LA PILA
        X = p_desapilar(aux);
        p_apilar(p, X);
    }

    free(aux);
    return p;
}

//D
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2) {
    TipoElemento Basura;
    TipoElemento X;

    Pila aux = p_crear();
    Pila res = p_crear();

    int pos = 1;

    while(!p_es_vacia(p)){
        X = p_desapilar(p);
        if(pos == pos1 || pos == pos2){
            p_apilar(res, X);
        }
        p_apilar(aux, X);
        pos++;
    }

    Pila resAux = p_crear();
    while(!p_es_vacia(res)){
        X = p_desapilar(res);
        p_apilar(resAux, X);
    }

    pos = 1;
    int diferencia = largo(aux);

    while(!p_es_vacia(aux)){
        if(pos == diferencia-pos2+1 || pos == diferencia-pos1+1){
            X = p_desapilar(resAux);
            Basura = p_desapilar(aux);
            p_apilar(p, X);
        }
        else{
            X = p_desapilar(aux);
            p_apilar(p, X);
        }
        pos++;
    }

    return p;
}

//E
Pila p_ej2_duplicar(Pila p) {
	if (p_es_vacia(p)) {
		return p;
	}
	Pila p2 = p_crear();
	Pila pAux = p_crear();

	while (p_tope(p) != NULL) {
		TipoElemento elementoAux = te_crear(0);
		elementoAux = p_desapilar(p);
		p_apilar(pAux, elementoAux);
	}
	while (p_tope(pAux) != NULL) {
		TipoElemento elementoAux = te_crear(0);
		elementoAux = p_desapilar(pAux);
		p_apilar(p, elementoAux);
		p_apilar(p2, elementoAux);
	}
	return p2;
}

//F
int p_ej2_cantidadelementos(Pila p) {
	if (p_es_vacia(p)) {
		return 0;
	}
	Pila pAux = p_crear();
	int count = 0;
	while (p_tope(p) != NULL) {
		TipoElemento elementoAux = te_crear(0);
		elementoAux = p_desapilar(p);
		p_apilar(pAux, elementoAux);
		count++;
	}
	while (p_tope(pAux) != NULL) {
		TipoElemento elementoAux = te_crear(0);
		elementoAux = p_desapilar(pAux);
		p_apilar(p, elementoAux);
	}

	return count;
}

//EJERCICIO 3
bool p_ej3_iguales(Pila p1, Pila p2) {
	if (p_es_vacia(p1) || p_es_vacia(p2)) {
		return false;
	}

	if ((p_ej2_cantidadelementos(p1) > p_ej2_cantidadelementos(p2)) || (p_ej2_cantidadelementos(p1) < p_ej2_cantidadelementos(p2))) {
		return false;
	}

	Pila pAux = p_crear();
	bool flag = true;


	while (!p_es_vacia(p1)) {//O(n1)
        TipoElemento elemAux = te_crear_con_valor(0, NULL);
        TipoElemento elem1 = te_crear(0);
        TipoElemento elem2 = te_crear(0);

        elem1 = p_desapilar(p1);
        elem2 = p_desapilar(p2);
		if (elem1->clave != elem2->clave) {
			flag = false;
		}
		elemAux->clave = elem1->clave;
		elemAux->valor = (void *)(intptr_t)elem2->clave;

		p_apilar(pAux, elemAux);
	}

	while (!p_es_vacia(pAux)) {//O(n2)
        TipoElemento elemAux = te_crear_con_valor(0, NULL);
        TipoElemento elem1 = te_crear(0);
        TipoElemento elem2 = te_crear(0);

		elemAux = p_desapilar(pAux);
		elem1->clave = elemAux->clave;
		elem2->clave = (int)(intptr_t)elemAux->valor;

		p_apilar(p1, elem1);
		p_apilar(p2, elem2);
	}
    printf("Complejidad: O(n1+n2)");
    return flag;
}



//EJERCICIO 4
char* pasarString(Pila p) {
    int l = largo(p);
    Pila pAux = p_crear();

    // Suponiendo longitud promedio de 10 por elemento
    char *texto = (char *)malloc(l * 10 * sizeof(char));
    texto[0] = '\0';  // Inicializar string vacío

    while (p_tope(p) != NULL) {
        TipoElemento elemento = p_desapilar(p);
        char temp[50];

        if (elemento->valor == NULL) {
            sprintf(temp, "%d", elemento->clave);
        } else {
            sprintf(temp, "%s", elemento->valor);
        }

        strcat(texto, temp);
        p_apilar(pAux, elemento);
    }

    // Restaurar pila original
    while (p_tope(pAux) != NULL) {
        p_apilar(p, p_desapilar(pAux));
    }

    return texto;
}

char* p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase) {
    Pila pAux = p_crear();

    while (nrobasedecimal > 0) {
        int resto = nrobasedecimal % nrootrabase;
        nrobasedecimal = nrobasedecimal / nrootrabase;

        if (resto < 10) {
            TipoElemento x = te_crear(resto);
            p_apilar(pAux, x);
        } else {
            char letra = 'A' + (resto - 10);
            char* str = (char*)malloc(2);
            str[0] = letra;
            str[1] = '\0';

            TipoElemento x = te_crear_con_valor(0, str);
            p_apilar(pAux, x);
        }
    }

    char* texto = pasarString(pAux);
    
    return texto;    
}

//EJERCICIO 5
Pila  p_ej5_invertir(Pila p){
    Pila pInvertida = p_crear();
    Pila aux = p_crear();

   

    while(p_tope(p) != NULL){//DESAPILAMOS
        TipoElemento X = p_desapilar(p);
        p_apilar(aux, X);
        p_apilar(pInvertida, X);
    }

    while(p_tope(aux) != NULL){//APILAMOS
        TipoElemento X = p_desapilar(aux);
        p_apilar(p, X);
    }
    printf("\t||Complejidad: O(n)\n");

    return pInvertida;
}

Pila p_dar_vuelta(Pila p){
    Pila pDadaVuelta=p_crear();
    while (!p_es_vacia(p))
    {
        TipoElemento X = p_desapilar(p);
        p_apilar(pDadaVuelta, X);
    }
    return pDadaVuelta;
}


//EJERCICIO 6
Pila ej6R(Pila p, int clave, Pila pSinValor, Pila pAux){
    if (p_es_vacia(p)){
        
        while (!p_es_vacia(pAux)) {
            TipoElemento X = p_desapilar(pAux);
            p_apilar(p, X);
        }
        printf("\t||Complejidad: O(n)\n");
        
        return p_dar_vuelta(pSinValor);
    }

    TipoElemento X = p_desapilar(p);
    p_apilar(pAux, X);
    if (X->clave != clave){
        p_apilar(pSinValor, X);
    }
    return ej6R(p, clave, pSinValor, pAux);
}

Pila p_ej6_eliminarclaveR(Pila p, int clave){
    Pila pSinValor = p_crear();
    Pila pAux = p_crear();
    return ej6R(p, clave, pSinValor, pAux);
}

Pila p_ej6_eliminarclave(Pila p, int clave){
    Pila pSinClave = p_crear();
    Pila aux = p_crear();

    TipoElemento X;

    while(!p_es_vacia(p)){
        X = p_desapilar(p);
        p_apilar(aux, X);
    }

    while(!p_es_vacia(aux)){
        X = p_desapilar(aux);
        p_apilar(p, X);
        if (X->clave != clave){
            p_apilar(pSinClave, X);
        }
    }
    printf("\t||Complejidad: O(n)\n");
    return pSinClave;
}

//EJERCICIO 7
Pila p_ej7_elementoscomunes(Pila p1, Pila p2) {
    Pila pEComunes = p_crear();
    Pila aux1 = p_crear();
    Pila aux2 = p_crear();
    Pila aux2temp = p_crear();
    TipoElemento X, Y;

    
    while (!p_es_vacia(p1)) {
        X = p_desapilar(p1);
        p_apilar(aux1, X);
    }
    
    while (!p_es_vacia(p2)) {
        Y = p_desapilar(p2);
        p_apilar(aux2, Y);
    }

    
    while (!p_es_vacia(aux1)) {
        X = p_desapilar(aux1);
        bool encontrado = false;

        while (!p_es_vacia(aux2)) {
            Y = p_desapilar(aux2);
            if (!encontrado && X->clave == Y->clave) {
                encontrado = true;
                
            } else {
                p_apilar(aux2temp, Y);
            }
        }

       
        while (!p_es_vacia(aux2temp)) {
            Y = p_desapilar(aux2temp);
            p_apilar(aux2, Y);
        }

        if (encontrado) {
            p_apilar(pEComunes, X);
        }

        
        p_apilar(p1, X);
    }

    
    while (!p_es_vacia(aux2)) {
        Y = p_desapilar(aux2);
        p_apilar(p2, Y);
    }
    printf("\t||Complejidad: O(n x m)\n");
    return pEComunes;
}

//EJERCICIO 8
Pila p_ej8_sacarrepetidos(Pila p){
    Lista l = l_crear();
    Lista rep = l_crear();
    Pila pRepetidos = p_crear();
    Pila aux = p_crear();
    TipoElemento X;
    TipoElemento Y;

    while(!p_es_vacia(p)){//VACIAMOS LA PILA Y LLENAMOS LA LISTA
        X = p_desapilar(p);
        p_apilar(aux, X);
        if(l_buscar(rep, X->clave) == NULL){
            l_agregar(rep, X);
        }
        l_agregar(l, X);
    }

    Iterador iter1 = iterador(rep);
    Iterador iter2;

    while(hay_siguiente(iter1)){//APILAMOS LAS CLAVES Y LA CANT DE REPETIDOS
        
        int *count = (int*)malloc(sizeof(int));
        *count = 0;

        X = siguiente(iter1);
        iter2 = iterador(l);

        while(hay_siguiente(iter2)){
            Y = siguiente(iter2);
            if(X->clave == Y->clave){
                (*count)++;
            }
        }
        p_apilar(pRepetidos, te_crear_con_valor(X->clave, count));
    }

    while(!p_es_vacia(aux)){//RESTAURO LA PILA ORIGINAL
        X = p_desapilar(aux);
        p_apilar(p, X);
    }
    printf("\t||Complejidad: O(n^2)\n");
    return pRepetidos;
}


