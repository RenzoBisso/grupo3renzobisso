#define _CRT_SECURE_NO_WARNINGS
#include "..\headers\utilidades.h"

#include "..\..\..\04-trabajoPractico-Colas\headers\tp_4_colas.h"

// COLAPSAR = Ctrl + K seguido de Ctrl + 0

// EXPANDIR = Ctrl + K seguido de Ctrl + J

// FUNCIONES GENERALES
// ###################
// ###################
void limpiar_pantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int leer_entero_no_negativo() {
    char buffer[100];
    int valor;
    char extra;  // para verificar que no haya caracteres extras

    while (1) {
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            // error o EOF
            printf("Error leyendo la entrada.\n");
            continue;
        }

        // Intentamos escanear un entero y asegurarnos que no haya más
        // caracteres
        if (sscanf(buffer, "%d %c", &valor, &extra) == 1) {
            if (valor >= 0) {
                return valor;
            } else {
                printf("Error: el valor debe ser mayor o igual a 0.\n");
            }
        } else {
            printf(
                "Entrada invalida. Por favor ingrese un numero entero >= 0.\n");
        }
    }
}

void limpiarBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void pausa() {
    printf("Presione cualquier tecla para continuar...\n");
    // fflush(stdin);
    // limpiarBuffer();
    getchar();
    limpiarBuffer();
    // fflush(stdin);
    limpiar_pantalla();
}

int es_decimal(
    double num) {  // Funcion para saber si un numero tiene parte decimal
    double parte_entera;
    double parte_decimal = modf(num, &parte_entera);

    return parte_decimal !=
           0.0;  // Retorna 1 si tiene parte decimal, 0 si es entero
}

int esEntero(double num) {
    return floor(num) == num;
}

void a_minusculas(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void imprimirArr(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    // printf("\n");
}

void cargarArray(int arr[], int n, int count) {
    if (count == n) {
        return;
    }
    int valor;
    bool flag = true;
    while (flag) {
        printf("Ingrese el numero a agregar: ");

        if (scanf("%d", &valor) != 1) {
            printf("Entrada inválida. No se ingresó un número entero.\n");
            while (getchar() != '\n')
                ;
        } else {
            arr[count] = valor;
            flag = false;
        }
    }
    return cargarArray(arr, n, count + 1);
}

void pedirNumero(int *valor) {
    bool flag = true;

    while (flag) {
        printf("\t||Ingrese un numero: ");

        if (scanf("%d", valor) != 1) {
            printf("\t||Entrada invalida.\n");
            while (getchar() != '\n')
                ;
        } else {
            flag = false;
        }
    }
}

char salir() {
    char c;
    char min;
    do {
        printf("\n\nDESEA SALIR? Y/N: ");
        c = getchar();
        min = tolower(c);

        limpiarBuffer();  // Limpia lo que quedó después del getchar

        if (min != 'n' && min != 'y') {
            printf("\nError, ingrese un dato valido.");
        }

    } while (min != 'n' && min != 'y');

    return min;
}

int cargaManualAuto() {  // 0 manual, 1 azar
    bool bandera = true;
    int opcion;
    pedirNumero(&opcion);
    do {
        if (opcion != 1 && opcion != 0) {
            printf("\t||Error, ingrese una opcion valida.\n");
            pedirNumero(&opcion);
        } else {
            bandera = false;
        }

    } while (bandera);
    printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
           ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    return opcion;
}

int maximo(int a, int b) {
    return (a > b) ? a : b;
}

int numero_aleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void pedirNumeroPos(int *valor) {  // pedriNumero PERO SOLO POSITIVOS
    bool flag = true;

    while (flag) {
        printf("\t||Ingrese un numero: ");

        if (scanf("%d", valor) != 1) {
            if (valor < 0) {
                printf("\t||Entrada invalida.\n");
                while (getchar() != '\n')
                    ;
            }
            printf("\t||Entrada invalida.\n");
            while (getchar() != '\n')
                ;
        } else {
            flag = false;
        }
    }
}

bool conversionEntero(char *string, int *nro, int len) {
    int i = 0;
    // Contar la cantidad de espacios.
    while (isspace(string[i]))
        i++;
    // Controlar cadena vacia.
    if (len == i)
        return false;

    char *buffer = malloc(sizeof(char) * len);
    int indiceEntero = 0;

    // Controlar si es un numero negativo.
    if (string[i] == '-') {
        buffer[indiceEntero] = '-';
        indiceEntero++;
        i++;

        if (!isdigit(string[i]))
            return false;
    }

    // Leer los digitos.
    while (i < len && !isspace(string[i])) {
        if (!isdigit(string[i]))
            return false;
        buffer[indiceEntero] = string[i];
        indiceEntero++;
        i++;
    }

    // Agregar el caracter nulo al final del string.
    buffer[indiceEntero] = '\0';

    // Termino de recorrer el string.
    while (isspace(string[i]))
        i++;

    // Si hay mas para recorrer y no son blancos, el string contiene otros
    // caracteres.
    if (string[i] != '\0')
        return false;

    // Convierto el string a un entero.
    *nro = atoi(buffer);

    return true;
}

// Recibe un entero y valida que se encuentre en el rango especificado.
void rango(int *nro, int rango) {
    while (abs(*nro) > rango) {
        printf("El numero ingresado debe estar comprendido en [-9999;9999], "
               "intente nuevamente.\n");
        pedirDatos(nro, 11);
    }
}

void strtrim(char *cadena) {
    char *comienzoDeCadena = cadena;
    char *finalDeCadena = cadena + strlen(cadena) - 1;
    while (isspace(*comienzoDeCadena)) {
        comienzoDeCadena++;
    }
    while (isspace(*finalDeCadena) && finalDeCadena >= comienzoDeCadena) {
        finalDeCadena--;
    }
    *(finalDeCadena + 1) = '\0';
    memmove(cadena, comienzoDeCadena, finalDeCadena - comienzoDeCadena + 2);
}

bool conversionCharPunto4(char *string) {
    int tamanio =
        strlen(string) - 1;  // consigo el tamanio del array para usarlo en el
                             // for y saber si está vacia o no
    if (tamanio >= MAXIMAEJ4 - 1) {
        printf("\t\t///Dato demasiado grande.\n");
        return false;
    }
    int i = 0;

    string[tamanio] =
        '\0';  // quito el \n puesto por el fgets en la ultima linea
    if (strlen(string) == 0) {
        printf("\t\t/// Cadena vacia no es valida.\n");  // Compruebo que no sea
                                                         // una cadena vacia
                                                         // antes de seguir
        return false;
    }
    // else if (string[0]=='-'){   //Me fijo si el primer digito es negativo
    //     if(string[1]=='\0'){    //Si el primer signo es negativo y el
    //     siguiente un vacio, significa que es solo un signo negativo
    //         printf("Signo negativo sin un numero no es valido\n");
    //         return false;
    //     }
    //     i+=1;
    // }

    for (i; i < tamanio; i++) {
        while (!((string[i] >= 65) && (string[i] <= 90)) &&
               !((string[i] >= 97) &&
                 (string[i] <= 122))) {  // Si no esta entre los digitos ascii
                                         // de 0 a 9 tira mensaje de error
            return false;
        }
    }
    return true;
}

void pedirChar(char *string) {
    bool conversionCorrecta = true;
    do {
        fgets(string, MAXIMAEJ4 + 1, stdin);
        conversionCorrecta = conversionCharPunto4(string);
        fflush(stdin);
        if (!conversionCorrecta) {
            printf("\t\t/// Dato invalido, intente nuevamente.\n");
            printf("\t\t/// Ingrese nuevamente: ");
        }
    } while (!conversionCorrecta);
}

void pedirDatos(int *nro, int tamanio) {
    bool conversionCorrecta = true;
    do {
        char *bufferNro = malloc(sizeof(char) * tamanio);
        fgets(bufferNro, tamanio, stdin);
        conversionCorrecta = conversionEntero(bufferNro, nro, tamanio);
        if (!conversionCorrecta) {
            printf("El numero es invalido, revisa los requerimientos\n");
            printf("Ingrese otro numero: ");
            fflush(stdin);
        }
    } while (!conversionCorrecta);
}

void leer_palabra(char *c) {
    char entrada[30];
    int EsValido = false;

    // recorre hasta ver q la palabra sean letras de la "a" a la z
    while (!EsValido) {
        int contadorDeEspacios = 0;
        EsValido = true;
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strlen(entrada) - 1] = '\0';
        strtrim(entrada);
        for (int i = 0; i < strlen(entrada); i++) {
            if (i != 0 && i != strlen(entrada) && entrada[i] == ' ') {
                contadorDeEspacios++;
            } else if (!isalpha(entrada[i]) || contadorDeEspacios > 2) {
                EsValido = false;
            }
        }
        if (!EsValido)
            printf("Entrada invalida, Ingrese Nuevamente: ");
    }
    strcpy(c, entrada);
}

// FUNCIONES GENERALES
// ###################
// ###################

// FUNCIONES DE LISTAS
// ###################
// ###################
void interfazCargaLista(Lista l1) {
    // limpiar_pantalla();
    printf("\t||CARGA MANUAL...                                                "
           "     "
           "                                ||\n");
    printf("\t||---------------------------------------------------------------"
           "-----"
           "--------------------------------||\n");
    int tamanio;
    bool flag = true;
    while (flag) {
        limpiarBuffer();

        printf("\t||Ingrese el tamanio de la lista: ");

        if (scanf("%d", &tamanio) != 1) {
            printf("\t||\n");
            printf("\t||-------------------------------------------------------"
                   "---------"
                   "------------------------------------||\n");
            printf("\t||Entrada invalida. No se ingreso un numero entero.      "
                   "         "
                   "                                    ||\n");
            printf("\t||-------------------------------------------------------"
                   "---------"
                   "------------------------------------||\n");
            // while (getchar() != '\n');
        } else {
            if (tamanio >= 1) {
                flag = false;
            } else {
                printf("\t||\n");
                printf("\t||---------------------------------------------------"
                       "-----------"
                       "--------------------------------------||\n");
                printf("\t||Entrada invalida. No se ingreso un numero entero.  "
                       "           "
                       "                                      ||\n");
                printf("\t||---------------------------------------------------"
                       "-----------"
                       "--------------------------------------||\n");
            }
        }
    }

    // llenarLRandom(l1);
    // llenarLRandom(l2);
    printf("\t||---------------------------------------------------------------"
           "-----"
           "--------------------------------||\n");
    cargarLista(l1, tamanio, 0);

    // limpiar_pantalla();
    printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
           ">>>>>"
           ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
}

void mostrar_coeficientes(Lista l) {  // 10 9 0 5 6 --- 5 --- 10^5 9^4 0^3 5^2 6
    int i = l_longitud(l) - 1;
    Iterador iter = iterador(l);
    TipoElemento X;
    while (hay_siguiente(iter)) {
        X = siguiente(iter);
        if (X->clave != 0) {
            if (i == 1) {
                printf("%dx + ", X->clave);
            } else if (i == 0) {
                printf("%d\n", X->clave);
            } else {
                printf("%dx^%d + ", X->clave, i);
            }
            i--;
        } else {
            i--;
        }
    }
}

void l_mostrar_con_valor(Lista l) {
    printf("Contenido de la lista: ");
    Iterador iter = iterador(l);
    TipoElemento X = te_crear_con_valor(0, NULL);
    printf("{");
    while (hay_siguiente(iter)) {
        X = siguiente(iter);
        if (hay_siguiente(iter)) {
            printf("%f; ", *(int *)X->valor);
        } else {
            printf("%f", *(int *)X->valor);
        }
    }
    printf("}\n");
}

void l_mostrar_comunes_pc(Lista l) {
    printf("\t||ELEMENTOS COMUNES Y POSICIONES: \n");

    Iterador iter = iterador(l);
    TipoElemento X;

    while (hay_siguiente(iter)) {
        X = siguiente(iter);
        if (hay_siguiente(iter)) {
            printf("\t||%d:%s\n", X->clave, (char *)X->valor);
        } else {
            printf("\t||%d:%s\n", X->clave, (char *)X->valor);
        }
    }
}

void llenarLRandom(Lista l1) {
    while (!l_es_llena(l1)) {
        l_agregar(l1, te_crear(rand() % 11));
    }
}

void cargarLista(Lista l, int n, int count) {
    if (count == n) {
        return;
    }
    int valor;
    bool flag = true;
    while (flag) {
        printf("\t||Ingrese el numero a agregar en la posicion %d: ", count);

        if (scanf("%d", &valor) != 1) {
            printf("\t||Entrada inválida. No se ingresó un número entero.\n");
            while (getchar() != '\n')
                ;
        } else {
            TipoElemento elemento = te_crear(valor);
            l_agregar(l, elemento);
            flag = false;
        }
    }
    return cargarLista(l, n, count + 1);
}

void lRandomSinRepetir(Lista l, int min, int max, int cantidad, int count) {
    while (count != cantidad) {
        int clave = rand() % (max - min + 1) + min;
        if (l_buscar(l, clave) == NULL) {
            l_agregar(l, te_crear(clave));
            count++;
        }
    }
}
// FUNCIONES DE LISTAS
// ###################
// ###################

// FUNCIONES DE PILAS
// ##################
// ##################
void p_cargar(Pila p, int n, int count) {
    if (count == n) {
        return;
    }
    int valor;
    bool flag = true;
    while (flag) {
        printf("\t||Ingrese el numero a agregar en la posicion %d: ", count);
        if (scanf("%d", &valor) != 1) {
            printf("\t||Entrada inválida. No se ingresó un número entero.\n");
            while (getchar() != '\n')
                ;
        } else {
            TipoElemento elemento = te_crear(valor);
            p_apilar(p, elemento);
            flag = false;
        }
    }
    p_cargar(p, n, count + 1);
}

void llenarPRandom(Pila p1) {
    while (!p_es_llena(p1)) {
        p_apilar(p1, te_crear(rand() % 11));
    }
}

Pila duplicar(Pila p) {
    Pila aux = p_crear();
    Pila doble = p_crear();

    TipoElemento X;

    while (!p_es_vacia(p)) {
        X = p_desapilar(p);
        p_apilar(aux, X);
    }

    while (!p_es_vacia(aux)) {
        X = p_desapilar(aux);
        p_apilar(p, X);
        p_apilar(doble, X);
    }

    return doble;
}

void p_mostrar_con_valor(Pila p) {
    Pila aux = duplicar(p);
    TipoElemento X;

    printf("\t|| Contenido de la pila: ");

    while (!p_es_vacia(aux)) {
        X = p_desapilar(aux);
        if (X->valor != NULL) {
            printf("{%d, %d} ", X->clave, *(int *)X->valor);
        }
    }
    printf("\n");
}

int largo(Pila p) {
    int count = 0;
    if (p_es_vacia(p)) {
        return 0;
    }
    Pila pAux = p_crear();
    while (p_tope(p) != NULL) {
        TipoElemento aux = te_crear_con_valor(0, NULL);
        aux = p_desapilar(p);
        p_apilar(pAux, aux);
        count++;
    }
    while (p_tope(pAux) != NULL) {
        TipoElemento aux = te_crear_con_valor(0, NULL);
        aux = p_desapilar(pAux);
        p_apilar(p, aux);
    }

    return count;
}

void interfazCargaPila(Pila p1) {
    // limpiar_pantalla();
    printf("\t||CARGA MANUAL...                                                "
           "     "
           "                                ||\n");
    printf("\t||---------------------------------------------------------------"
           "-----"
           "--------------------------------||\n");
    int tamanio;
    bool flag = true;
    while (flag) {
        limpiarBuffer();

        printf("\t||Ingrese el tamanio de la pila: ");

        if (scanf("%d", &tamanio) != 1) {
            printf("\t||\n");
            printf("\t||-------------------------------------------------------"
                   "---------"
                   "------------------------------------||\n");
            printf("\t||Entrada invalida. No se ingreso un numero entero.      "
                   "         "
                   "                                    ||\n");
            printf("\t||-------------------------------------------------------"
                   "---------"
                   "------------------------------------||\n");
            // while (getchar() != '\n');
        } else {
            if (tamanio >= 1) {
                flag = false;
            } else {
                printf("\t||\n");
                printf("\t||---------------------------------------------------"
                       "-----------"
                       "--------------------------------------||\n");
                printf("\t||Entrada invalida. No se ingreso un numero entero.  "
                       "           "
                       "                                      ||\n");
                printf("\t||---------------------------------------------------"
                       "-----------"
                       "--------------------------------------||\n");
            }
        }
    }
    printf("\t||---------------------------------------------------------------"
           "-----"
           "--------------------------------||\n");
    p_cargar(p1, tamanio, 0);

    // limpiar_pantalla();
    printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
           ">>>>>"
           ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
}
// FUNCIONES DE PILAS
// ##################
// ##################

// FUNCIONES DE COLAS
// ##################
// ##################
void interfazCargaCola(Cola c1) {
    // limpiar_pantalla();
    printf("\t||CARGA MANUAL...                                                "
           "     "
           "                                ||\n");
    printf("\t||---------------------------------------------------------------"
           "-----"
           "--------------------------------||\n");
    int tamanio;
    bool flag = true;
    while (flag) {
        limpiarBuffer();

        printf("\t||Ingrese el tamanio de la cola: ");

        if (scanf("%d", &tamanio) != 1) {
            printf("\t||\n");
            printf("\t||-------------------------------------------------------"
                   "---------"
                   "------------------------------------||\n");
            printf("\t||Entrada invalida. No se ingreso un numero entero.      "
                   "         "
                   "                                    ||\n");
            printf("\t||-------------------------------------------------------"
                   "---------"
                   "------------------------------------||\n");
            // while (getchar() != '\n');
        } else {
            if (tamanio >= 1) {
                flag = false;
            } else {
                printf("\t||\n");
                printf("\t||---------------------------------------------------"
                       "-----------"
                       "--------------------------------------||\n");
                printf("\t||Entrada invalida. No se ingreso un numero entero.  "
                       "           "
                       "                                      ||\n");
                printf("\t||---------------------------------------------------"
                       "-----------"
                       "--------------------------------------||\n");
            }
        }
    }
    printf("\t||---------------------------------------------------------------"
           "-----"
           "--------------------------------||\n");
    c_cargar(c1, tamanio, 0);

    // limpiar_pantalla();
    printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
           ">>>>>"
           ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
}

void interfazCargaColaSinRepetir(Cola c1) {
    // limpiar_pantalla();
    printf("\t||CARGA MANUAL...                                                "
           "     "
           "                                ||\n");
    printf("\t||---------------------------------------------------------------"
           "-----"
           "--------------------------------||\n");
    int tamanio;
    bool flag = true;
    while (flag) {
        limpiarBuffer();

        printf("\t||Ingrese el tamanio de la cola: ");

        if (scanf("%d", &tamanio) != 1) {
            printf("\t||\n");
            printf("\t||-------------------------------------------------------"
                   "---------"
                   "------------------------------------||\n");
            printf("\t||Entrada invalida. No se ingreso un numero entero.      "
                   "         "
                   "                                    ||\n");
            printf("\t||-------------------------------------------------------"
                   "---------"
                   "------------------------------------||\n");
            // while (getchar() != '\n');
        } else {
            if (tamanio >= 1) {
                flag = false;
            } else {
                printf("\t||\n");
                printf("\t||---------------------------------------------------"
                       "-----------"
                       "--------------------------------------||\n");
                printf("\t||Entrada invalida. No se ingreso un numero entero.  "
                       "           "
                       "                                      ||\n");
                printf("\t||---------------------------------------------------"
                       "-----------"
                       "--------------------------------------||\n");
            }
        }
    }
    printf("\t||---------------------------------------------------------------"
           "-----"
           "--------------------------------||\n");
    c_cargarSinRepetir(c1, tamanio, 0);

    // limpiar_pantalla();
    printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
           ">>>>>"
           ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
}

void c_cargar(Cola c, int n, int count) {
    if (count == n) {
        return;
    }
    int valor;
    bool flag = true;
    while (flag) {
        printf("\t||Ingrese el numero a agregar en la posicion %d: ", count);
        if (scanf("%d", &valor) != 1) {
            printf("\t||Entrada inválida. No se ingresó un número entero.\n");
            while (getchar() != '\n')
                ;
        } else {
            TipoElemento elemento = te_crear(valor);
            c_encolar(c, elemento);
            flag = false;
        }
    }
    c_cargar(c, n, count + 1);
}

void llenarCRandom(Cola c1) {
    while (!c_es_llena(c1)) {
        int valor = rand() % 11;
        c_encolar(c1, te_crear(valor));
    }
}

bool cexisteclave(Cola c, int clave) {
    bool flag = false;
    Cola cAux = c_crear();
    if (c_es_vacia(c)) {
        return flag;
    }

    while (!c_es_vacia(c)) {
        TipoElemento X = c_desencolar(c);
        if (X->clave == clave) {
            flag = true;
        }
        c_encolar(cAux, X);
    }
    while (!c_es_vacia(cAux)) {
        TipoElemento X = c_desencolar(cAux);
        c_encolar(c, X);
    }
    return flag;
}

void c_cargarSinRepetir(Cola c, int n, int count) {
    if (count == n) {
        return;
    }
    int valor;
    bool flag = true;
    while (flag) {
        printf("\t||Ingrese el numero a agregar en la posicion %d: ", count);
        if (scanf("%d", &valor) != 1) {
            printf("\t||Entrada inválida. No se ingresó un número entero.\n");
            while (getchar() != '\n')
                ;
        } else if (!cexisteclave(c, valor)) {
            TipoElemento elemento = te_crear(valor);
            c_encolar(c, elemento);
            flag = false;
        } else {
            printf("Valor repetido.");
        }
    }
    c_cargarSinRepetir(c, n, count + 1);
}

void llenarCRandomSinRepetir(Cola c1) {
    while (!c_es_llena(c1)) {
        int valor = rand() % 11;
        if (!cexisteclave(c1, valor))
            c_encolar(c1, te_crear(valor));
    }
}

void llenarCRandomValor(Cola c1, int max) {
    while (max != 0) {
        int valor = rand() % 11;
        if (!cexisteclave(c1, valor))
            c_encolar(c1, te_crear(valor));
        max--;
    }
}

void c_mostrar_clientes(Cola c) {
    Cola aux = c_crear();
    TipoElemento X;

    while (!c_es_vacia(c)) {
        X = c_desencolar(c);
        printf("\t||%s\n", (char *)X->valor);
        c_encolar(aux, X);
    }
    while (!c_es_vacia(aux)) {
        X = c_desencolar(aux);
        c_encolar(c, X);
    }
}

void c_mostrar_valor(Cola c) {
    Cola aux = c_crear();
    TipoElemento X;

    while (!c_es_vacia(c)) {
        X = c_desencolar(c);
        printf("\t||Divisor: %d ||Total: %s\n", X->clave,
               *(bool *)X->valor ? "true" : "false");
        c_encolar(aux, X);
    }
    while (!c_es_vacia(aux)) {
        X = c_desencolar(aux);
        c_encolar(c, X);
    }
}

void c_mostrar_bien(Cola c) {
    Cola aux = c_crear();
    TipoElemento X;

    printf("Contenido de la cola: ");

    while (!c_es_vacia(c)) {
        X = c_desencolar(c);
        printf("%d ", X->clave);
        c_encolar(aux, X);
    }
    while (!c_es_vacia(aux)) {
        X = c_desencolar(aux);
        c_encolar(c, X);
    }

    printf("\n");
}
// FUNCIONES DE COLAS
// ##################
// ##################

// FUNCIONES DE ARBOLES
// ####################
// ####################
void l_mostrar_con_nodo(
    Lista l) {  // GUARDA EN EL VALOR DEL TE DE LA LISTA EL NODO
    printf("Contenido de la lista (nodos encontrados):\n");
    Iterador iter = iterador(l);
    TipoElemento X;
    while (hay_siguiente(iter)) {
        X = siguiente(iter);
        NodoArbol nodo = (NodoArbol)X->valor;
        TipoElemento datos = n_recuperar(nodo);

        printf("Clave: %d, Dirección del nodo: %p\n", datos->clave,
               (void *)nodo);
    }
}

char leer_opcion_sn() {  // TE PREGUNTA SI QUERES INGRESAR UN NODO
    char buffer[10];
    char opcion;
    printf("solo obtiene el primer caracter\n");
    while (1) {
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Error leyendo la entrada.\n");
            continue;
        }
        int i = 0;
        while (buffer[i] && isspace(buffer[i]))
            i++;
        opcion = tolower(buffer[i]);
        if (opcion == 's' || opcion == 'n') {
            return opcion;
        }
        printf("Entrada invalida. Por favor ingrese 's' o 'n'.\n");
    }
}

void cargar_nodo(ArbolBinario a, NodoArbol padre,
                 int es_izquierdo) {  // CARGA UN NODO, E HIJOS
    int valor;
    char opcion;

    if (a_es_lleno(a)) {
        return;
    }

    printf("¿Desea agregar un nodo %s de %d? (s/n): ",
           es_izquierdo ? "izquierdo" : "derecho", n_recuperar(padre)->clave);
    opcion = leer_opcion_sn();

    if (opcion == 's') {
        printf("Ingrese el valor del nodo (>= 0): ");
        valor = leer_entero_no_negativo();

        TipoElemento te = te_crear(valor);

        NodoArbol nuevo;
        if (es_izquierdo) {
            nuevo = a_conectar_hi(a, padre, te);
        } else {
            nuevo = a_conectar_hd(a, padre, te);
        }

        cargar_nodo(a, nuevo, 1);
        cargar_nodo(a, nuevo, 0);
    }
}

void cargar_arbol_binario(ArbolBinario a) {  // INTERFAZ PARA CARGAR ARBOL
    int valor;
    printf("Ingrese el valor de la raiz (>= 0): ");
    valor = leer_entero_no_negativo();

    TipoElemento te = te_crear(valor);
    NodoArbol raiz = a_establecer_raiz(a, te);

    cargar_nodo(a, raiz, 1);
    cargar_nodo(a, raiz, 0);
}

void pre_orden(NodoArbol N) {
    TipoElemento X;
    if (N != NULL) {
        X = n_recuperar(N);
        printf(" %d", X->clave);
        pre_orden(n_hijoizquierdo(N));
        pre_orden(n_hijoderecho(N));
    }
}

void in_orden(NodoArbol N) {
    TipoElemento X;
    if (N != NULL) {
        in_orden(n_hijoizquierdo(N));
        X = n_recuperar(N);
        printf(" %d", X->clave);
        in_orden(n_hijoderecho(N));
    }
}

void post_orden(NodoArbol N) {
    TipoElemento X;
    if (N != NULL) {
        post_orden(n_hijoizquierdo(N));
        post_orden(n_hijoderecho(N));
        X = n_recuperar(N);
        printf(" %d", X->clave);
    }
}

void l_mostrar_ej2(Lista l) {
    printf("Contenido de la lista: ");

    Iterador iter = iterador(l);
    TipoElemento X = te_crear_con_valor(0, NULL);

    printf("{");

    while (hay_siguiente(iter)) {
        X = siguiente(iter);

        if (hay_siguiente(iter)) {
            printf("%d : ", n_recuperar((NodoArbol)X->valor)->clave);
        } else {
            printf("%d", n_recuperar((NodoArbol)X->valor)->clave);
        }
    }
    printf("}\n");
}

void mostrar_arbol(NodoArbol n, char *prefijo,
                   int Izq) {  // FUNCION PARA MOSTRAR UN ARBOL
    if (n != NULL) {
        printf("%s", prefijo);
        printf("%s", Izq ? "|-- " : "L-- ");
        printf("%i\n", n_recuperar(n)->clave);

        char prefijoNuevo[100];
        snprintf(prefijoNuevo, sizeof(prefijoNuevo), "%s%s", prefijo,
                 Izq ? "|   " : "    ");

        mostrar_arbol(n_hijoderecho(n), prefijoNuevo, 1);
        mostrar_arbol(n_hijoizquierdo(n), prefijoNuevo, 0);
    }
}

void cargar_avl(ArbolAVL v) {  //[PARTE 3 DE CARGA BINARIA RANDOM]
    while (!avl_es_lleno(v)) {
        TipoElemento aux = te_crear(numero_aleatorio(0, 50));
        avl_insertar(v, aux);
    }
}

NodoArbol nodoAleatorio() {  //[PARTE 2 DE CARGA BINARIA RANDOM]
    ArbolAVL avl = avl_crear();
    cargar_avl(avl);
    NodoArbol nodoAvl = avl_raiz(avl);
    return nodoAvl;
}

void crearBinarioAleatorio(
    ArbolBinario b, NodoArbol aleatorio,
    NodoArbol vacio) {  //[PARTE 4 DE CARGA BINARIA RANDOM]
    if (!a_es_rama_nula(aleatorio)) {
        if (n_hijoderecho(aleatorio) != NULL) {
            NodoArbol x =
                a_conectar_hd(b, vacio, n_recuperar(n_hijoderecho(aleatorio)));
            crearBinarioAleatorio(b, n_hijoderecho(aleatorio), x);
        }
        if (n_hijoizquierdo(aleatorio) != NULL) {
            NodoArbol y = a_conectar_hi(
                b, vacio, n_recuperar(n_hijoizquierdo(aleatorio)));
            crearBinarioAleatorio(b, n_hijoizquierdo(aleatorio), y);
        }
    }
}

ArbolBinario binarioAleatorio() {  //[PARTE 1 DE CARGA BINARIA RANDOM]
    ArbolBinario b = a_crear();
    NodoArbol n = n_crear(te_crear(0));
    NodoArbol rand = nodoAleatorio();
    NodoArbol raiz = a_establecer_raiz(b, n_recuperar(rand));

    crearBinarioAleatorio(b, raiz, n);

    return b;
}

int alturaNodo(NodoArbol na) {  // DEVUELVE LA ALTURA DE UN NODO: -HI+HD
    if (na == NULL) {
        return -1;
    }
    return maximo(alturaNodo(n_hijoizquierdo(na)),
                  alturaNodo(n_hijoderecho(na))) +
           1;
}

void cargarNArio(ArbolBinario a, NodoArbol p, int aux) {
    char c;
    int clave;
    NodoArbol n;

    if (!a_es_lleno(a)) {
        c = pedirNodo(p);

        if (c == 'y') {
            pedirNumero(&clave);
            limpiarBuffer();

            if (aux == -1)
                n = a_conectar_hi(a, p, te_crear(clave));
            else if (aux == 1)
                n = a_conectar_hd(a, p, te_crear(clave));
            else
                n = a_establecer_raiz(a, te_crear(clave));

            cargarNArio(a, n, -1);
            cargarNArio(a, n, 1);
        }
    }
}

char pedirNodo(
    NodoArbol n) {  // TE PREGUNTA SI QUERES INGRESAR UN NODO PARA ARBOL N-ARIO
    char c;
    char min;
    do {
        if (n == NULL) {
            printf("\t|| DESEA INGRESAR UN NODO? Y/N: ");
        } else {
            printf("\t|| DESEA INGRESAR UN NODO A [%d]? Y/N: ",
                   n_recuperar(n)->clave);
        }

        c = getchar();
        min = tolower(c);

        limpiarBuffer();  // Limpia lo que quedó después del getchar

        if (min != 'n' && min != 'y') {
            printf("\nError, ingrese un dato valido.");
        }

    } while (min != 'n' && min != 'y');

    return min;
}
// FUNCIONES DE ARBOLES
// ####################
// ####################

// FUNCIONES DE HASH
// #################
// #################

// FUNCIONES DE HASH
// #################
// #################

bool cto_es_subconjunto(Conjunto A, Conjunto B) {
    for (int i = 1; i <= cto_cantidad_elementos(A); i++) {
        TipoElemento X = cto_recuperar(A, i);
        if (!cto_pertenece(B, X->clave)) {
            return false;
        }
    }
    return true;
}