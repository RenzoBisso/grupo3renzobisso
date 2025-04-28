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
    bool llave = true;

    while(!p_es_vacia(p)){//VACIAMOS LA PILA
        X = p_desapilar(p);
        p_apilar(aux, X);
    }

    while(!p_es_llena(p)){//INSERTAMOS ELEMENTO Y OMITIMOS LA CLAVE
        X = p_desapilar(aux);
        if(X->clave != clave && llave){
            p_apilar(p, X);
            llave = false;
        }
    }

    free(aux);
    return p;
}

//D
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2) {
	if (p_es_vacia(p)) {
		return p;
	}
	int posActual = 1;
	Pila pAux = p_crear();
	TipoElemento elemento1 = te_crear(0);
	TipoElemento elemento2 = te_crear(0);


	//buscamos los elementos en las posiciones dadas y guardamos en la pila auxiliar
	while (p_tope(p) != NULL) {
		TipoElemento elementoAux = te_crear(0);
		if (posActual == pos1) {
			elemento1 = p_desapilar(p);
			p_apilar(pAux, elemento1);
			posActual++;
		}
		else if (posActual == pos2) {
			elemento2 = p_desapilar(p);
			p_apilar(pAux, elemento2);
			posActual++;
		}
		else {
			elementoAux = p_desapilar(p);
			p_apilar(pAux, elementoAux);
			posActual++;
		}
	}
	//Vamos restando el contador hasta que llegamos a la posicion dada y apilamos el valor correspondiente
	while (p_tope(pAux) != NULL) {
		TipoElemento elementoAux = te_crear(0);
		if (posActual == pos1) {
			p_desapilar(pAux);
			p_apilar(p, elemento2);
			posActual--;
		}
		else if (posActual == pos2) {
			p_desapilar(pAux);
			p_apilar(p, elemento1);
			posActual--;
		}
		else {
			elementoAux = p_desapilar(pAux);
			p_apilar(p, elementoAux);
			posActual--;
		}
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
	while (p_tope(p1) != NULL) {
		TipoElemento elem1 = te_crear(0);
		TipoElemento elem2 = te_crear(0);
		TipoElemento elemAux = te_crear_con_valor(0, NULL);
		if (elem1->clave != elem2->clave) {
			flag = false;
		}
		elemAux->clave = elem1->clave;
		elemAux->valor = (void *)(intptr_t)elem2->clave;
		p_apilar(pAux, elemAux);
	}

	while (p_tope(pAux) != NULL) {
		TipoElemento elemetoAux = te_crear_con_valor(0, NULL);
		TipoElemento elem1 = te_crear(0);
		TipoElemento elem2 = te_crear(0);
		elemetoAux = p_desapilar(pAux);
		elem1->clave = elemetoAux->clave;
		elem2->clave = (int)(intptr_t)elemetoAux->valor;
		p_apilar(p1, elem1);
		p_apilar(p2, elem2);
	}
	return flag;


}

//EJERCICIO 4
int largo(Pila p){
    int count=0;
    if(p_es_vacia(p)){
        return 0;
    }
    Pila pAux=p_crear();
    while (p_tope(p)!=NULL)
    {
        TipoElemento aux=te_crear_con_valor(0,NULL);
        aux=p_desapilar(p);
        p_apilar(pAux,aux);
        count++;
    }
    while (p_tope(pAux)!=NULL)
    {
        TipoElemento aux=te_crear_con_valor(0,NULL);
        aux=p_desapilar(pAux);
        p_apilar(p,aux);
    }

    return count;
}

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

    TipoElemento X;

    while(!p_es_vacia(p)){//DESAPILAMOS
        X = p_desapilar(p);
        p_apilar(aux, X);
        p_apilar(pInvertida, X);
    }

    while(!p_es_vacia(p)){//APILAMOS
        X = p_desapilar(aux);
        p_apilar(p, X);
    }

    return pInvertida;
}

//EJERCICIO 6
Pila ej6R(Pila p, int clave, Pila pSinValor, Pila pAux){
    if (p_es_vacia(p)){
        
        while (!p_es_vacia(pAux)) {
            TipoElemento X = p_desapilar(pAux);
            p_apilar(p, X);
        }
        return pSinValor;
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

    return pEComunes;
}



//EJERCICIO 8
Pila p_ej8_sacarrepetidos(Pila p){
    Lista l = l_crear();
    Pila pRepetidos = p_crear();
    Pila aux = p_crear();
    TipoElemento X;
    TipoElemento Y;
    int *count;

    while(!p_es_vacia(p)){//VACIAMOS LA PILA Y LLENAMOS LA LISTA
        X = p_desapilar(p);
        p_apilar(aux, X);
        if(l_buscar(l, X->clave) == NULL){
            l_agregar(l, X);
        }
    }

    Iterador iter1 = iterador(l);
    Iterador iter2;

    while(hay_siguiente(iter1)){//APILAMOS LAS CLAVES Y LA CANT DE REPETIDOS
        X = siguiente(iter1);
        iter2 = iterador(l);
        *count = 1;
        while(hay_siguiente(iter2)){
            Y = siguiente(iter2);
            if(X->clave == Y->clave){
                *count++;
            }
        }
        p_apilar(pRepetidos, te_crear_con_valor(X->clave, count));
    }

    while(!p_es_llena(aux)){//RESTAURO LA PILA ORIGINAL
        X = p_desapilar(aux);
        p_apilar(p, X);
    }

    return pRepetidos;
}


