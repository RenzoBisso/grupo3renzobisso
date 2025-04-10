#include "..\headers\interfaz.h"
#include "..\headers\utilidades.h"
#include "..\headers\tp_2_listas.h"

void interfaz2(){
    
    int opcion;
    char cadena[150]="\0";
    char min;
    char c;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 2      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||DADAS DOS LISTAS CARGADAS CON VALORES AL AZAR:                                                      ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        Lista l1 = l_crear();
        Lista l2 = l_crear();

        while(!l_es_llena(l1)){
            l_agregar(l1, te_crear(rand() % 11));
        }

        while(!l_es_llena(l2)){
            l_agregar(l2, te_crear(rand() % 11));
        }

        printf("Lista 1: ");
        l_mostrar(l1);
        printf("\nLista 2: ");
        l_mostrar(l2);

        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||MOSTRAR LOS VALORES DE L1 QUE NO SE ENCUENTRAN EN L2:                                               ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        Lista resultado = l_crear();
        resultado = verElementosQueNoSeRepiten(l1, l2);
        l_mostrar(resultado);

        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||MOSTRAR LOS VALORES DE L2 QUE NO SE ENCUENTRAN EN L1:                                               ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        free(resultado);
        resultado = verElementosQueNoSeRepiten(l2, l1);
        l_mostrar(resultado);

        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||MOSTRAR LOS VALORES REPETIDOS:                                                                      ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
            
        free(resultado);
        resultado = verElementosRepetidos(l1, l2);
        l_mostrar(resultado);

        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||MOSTRAR EL PROMEDIO DE AMBAS LISTAS:                                                                ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");


        limpiarBuffer();
        
        do {
            printf("\n\nDESEA SALIR? Y/N: ");
            c = getchar();
            min = tolower(c);
            
            limpiarBuffer(); // Limpia lo que quedó después del getchar
    
            if (min != 'n' && min != 'y') {
                printf("\nError, ingrese un dato valido.");
            }
    
        } while (min != 'n' && min != 'y');

        pausa();

    }while (min == 'n');
}

void interfaz3(){
    char min;
    bool bandera;
    char c;
    int m, n, modm, modn;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 2      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        /* fflush(stdin);

        printf("Ingrese un numero m: ");
        bandera = scanf("%d", &m);
        while(bandera != 1){
            printf("\nError, ingrese un dato valido.");
            fflush(stdin);
            printf("\nIngrese un numero m: ");
            bandera = scanf("%d", &m);
        }

        if(m != 0){
            modm = m / abs(m);
        }

        fflush(stdin);
        printf("\nIngrese un numero n: ");
        bandera = scanf("%d", &n);
        while(bandera != 1){
            printf("\nError, ingrese un dato valido.");
            fflush(stdin);
            printf("\nIngrese un numero n: ");
            bandera = scanf("%d", &n);
        }

        if(n != 0){
            modn = n / abs(n);
        }

        printf("\nEl producto de [%d] y [%d] es: [%d]", m, n, (producto(abs(m),abs(n)) * (modm * modn))); */

        limpiarBuffer();
        
        do {
            printf("\n\nDESEA SALIR? Y/N: ");
            c = getchar();
            min = tolower(c);
            
            limpiarBuffer(); // Limpia lo que quedó después del getchar
    
            if (min != 'n' && min != 'y') {
                printf("\nError, ingrese un dato valido.");
            }
    
        } while (min != 'n' && min != 'y');

        pausa();

    }while (min == 'n');
}

void interfaz4(){
    bool bandera;
    int n;
    char min;
    char c;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 3      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        /* fflush(stdin);

        printf("Ingrese un numero m: ");
        bandera = scanf("%d", &n);
        while(bandera != 1 || n < 0){
            printf("\nError, ingrese un dato valido.");
            fflush(stdin);
            printf("\nIngrese un numero n: ");
            bandera = scanf("%d", &n);
        }

        printf("\nEl n-esimo numero[%d] en la serie de fibonacci es: [%d]", n, terminoSeridFibonacci(n)); */

        limpiarBuffer();
        
        do {
            printf("\n\nDESEA SALIR? Y/N: ");
            c = getchar();
            min = tolower(c);
            
            limpiarBuffer(); // Limpia lo que quedó después del getchar
    
            if (min != 'n' && min != 'y') {
                printf("\nError, ingrese un dato valido.");
            }
    
        } while (min != 'n' && min != 'y');

        pausa();

    }while (min == 'n');
}

void interfaz5(){
    char min;
    bool bandera;
    char c;
    int m, n;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 4      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
   
        /* fflush(stdin);

        printf("Ingrese un numero m: ");
        bandera = scanf("%d", &m);
        while(bandera != 1){
            printf("\nError, ingrese un dato valido.");
            fflush(stdin);
            printf("\nIngrese un numero m: ");
            bandera = scanf("%d", &m);
        }

        fflush(stdin);
        printf("\nIngrese un numero n: ");
        bandera = scanf("%d", &n);
        while(bandera != 1){
            printf("\nError, ingrese un dato valido.");
            fflush(stdin);
            printf("\nIngrese un numero n: ");
            bandera = scanf("%d", &n);
        }

        if(esEntero(division(m,n))){
            printf("\nLa division de [%d] por [%d] es: [%.0f]", m, n, division(m,n));
        }
        else{
            printf("\nLa division de [%d] por [%d] es: [%.4f]", m, n, division(m,n));
        } */


        limpiarBuffer();
        
        do {
            printf("\n\nDESEA SALIR? Y/N: ");
            c = getchar();
            min = tolower(c);
            
            limpiarBuffer(); // Limpia lo que quedó después del getchar
    
            if (min != 'n' && min != 'y') {
                printf("\nError, ingrese un dato valido.");
            }
    
        } while (min != 'n' && min != 'y');

        pausa();

    }while (min == 'n');
}

void interfaz6(){
    char min;
    bool bandera;
    char c;
    char cadena[150]="\0";
    char * str;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 5      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        /* fflush(stdin);
        bandera = true;

        do{
            int i = 0;
            bandera = true;
            printf("Ingrese un numero: ");
            fflush(stdin);
            fgets(cadena, 150, stdin);
            strtok(cadena, "\n");
            if(i == 0){
                if(cadena[i] == '-'){
                    i++;
                }
            }
            for(i; i<strlen(cadena); i++){
                if(cadena[i] < '0' || cadena[i] > '9'){
                    bandera = false;
                    printf("\nError, ingrese solo numeros.\n");
                    break;
                }
            }
        }while(!bandera);

        str = agregarSeparadorMiles(cadena);
        printf("%s", str); */
        
        limpiarBuffer();
        
        do {
            printf("\n\nDESEA SALIR? Y/N: ");
            c = getchar();
            min = tolower(c);
            
            limpiarBuffer(); // Limpia lo que quedó después del getchar
    
            if (min != 'n' && min != 'y') {
                printf("\nError, ingrese un dato valido.");
            }
    
        } while (min != 'n' && min != 'y');

        pausa();


    }while (min == 'n');
    free(str);
}

void interfaz7(){
    char min;
    bool bandera;
    char c;
    int m, n;
    char * str;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 6      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        
        /* printf("Ingrese un numero m: ");
        bandera = scanf("%d", &m);
        while(bandera != 1){
            printf("\nError, ingrese un dato valido.");
            fflush(stdin);
            printf("\nIngrese un numero m: ");
            bandera = scanf("%d", &m);
        }

        str = reunionMafia(m);
        printf("%s", str); */

        limpiarBuffer();
        
        do {
            printf("\n\nDESEA SALIR? Y/N: ");
            c = getchar();
            min = tolower(c);
            
            limpiarBuffer(); // Limpia lo que quedó después del getchar
    
            if (min != 'n' && min != 'y') {
                printf("\nError, ingrese un dato valido.");
            }
    
        } while (min != 'n' && min != 'y');

        pausa();


    }while (min == 'n');
    free(str);
}

void interfaz8(){
    char min;
    bool bandera;
    char c;
    char cadena[150]="\0";
    char aux[150]="\0";
    char * str;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 7      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        /* do{
            int i = 0;
            bandera = true;
            printf("Ingrese patron de ondas[L/H]: ");
            fflush(stdin);
            fgets(cadena, 150, stdin);
            strtok(cadena, "\n");

            strcpy(aux, cadena);

            a_minusculas(aux);

            for(i; i<strlen(aux); i++){
                if(aux[i] != 'h' && aux[i] != 'l'){
                    bandera = false;
                    printf("\nError, ingrese datos validos[L/H].\n\n");
                    break;
                }
            }
        }while(!bandera);

        printf("\nPatron de ondas digitalizado: ");
        str = ondaDigital(cadena);
        printf("%s", str); */
        
        limpiarBuffer();

        do {
            printf("\n\nDESEA SALIR? Y/N: ");
            c = getchar();
            min = tolower(c);
            
            limpiarBuffer(); // Limpia lo que quedó después del getchar
    
            if (min != 'n' && min != 'y') {
                printf("\nError, ingrese un dato valido.");
            }
    
        } while (min != 'n' && min != 'y');

        pausa();

    }while (min == 'n');
    free(str);
}

void interfaz9(){
    char min;
    char c;
    int bandera;
    
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 8      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        /* fflush(stdin);

        int tamano,objetivo,valor,contador=0;

        printf("\nIngrese el tamanio del conjunto: ");
        bandera = scanf("%d", &tamano);
        while(bandera != 1 || tamano<0){
            printf("\nError, ingrese un dato valido.");
            fflush(stdin);
            printf("\nIngrese el tamanio del conjunto: ");
            bandera = scanf("%d", &tamano);
        }
    
        int conjunto[tamano];
    
        while(contador!=tamano){
    
            printf("\nIngrese un numero: ");
            bandera = scanf("%d", &valor);
            while(bandera != 1 || valor<0){
                printf("\nError, ingrese un dato valido.");
                fflush(stdin);
                printf("\nIngrese un numero: ");
                bandera = scanf("%d", &valor);
            }

            conjunto[contador]=valor;
            contador=contador+1;
        }

    
        printf("\nIngrese el numero objetivo: ");
        bandera = scanf("%d",&objetivo);
        while(bandera != 1 || objetivo<0){
            printf("\nError, ingrese un dato valido.");
            fflush(stdin);
            printf("\nIngrese el numero objetivo: ");
            bandera = scanf("%d", &objetivo);
        }

        char **conjuntoDeSubconjuntos= NULL;
        conjuntoDeSubconjuntos=(char**)malloc(sizeof(char)*100);
    
        if(conjuntoDeSubconjuntos==NULL){
            printf("No se pudo inicializar el puntero");
            return;
        }
    
        subconjuntosQueSumanN(conjunto,tamano,objetivo,conjuntoDeSubconjuntos); */

        limpiarBuffer();

        do {
            printf("\n\nDESEA SALIR? Y/N: ");
            c = getchar();
            min = tolower(c);
            
            limpiarBuffer(); // Limpia lo que quedó después del getchar
    
            if (min != 'n' && min != 'y') {
                printf("\nError, ingrese un dato valido.");
            }
    
        } while (min != 'n' && min != 'y');

        pausa();

    }while (min == 'n');
}

void interfaz10(){
    char c;
    int m;
    bool bandera;
    char min;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 9      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        /* fflush(stdin);

        printf("Ingrese un numero m: ");
        bandera = scanf("%d", &m);
        while(bandera != 1){
            printf("\nError, ingrese un dato valido.");
            fflush(stdin);
            printf("\nIngrese un numero m: ");
            bandera = scanf("%d", &m);
        }

        if(divisiblePor7(m)){
            printf("\nSI, [%d] es divisible por 7.",m);
        }
        else{
            printf("\nNO, [%d] no es divisible por 7.",m);
        }
 */
        limpiarBuffer();

        do {
            printf("\n\nDESEA SALIR? Y/N: ");
            c = getchar();
            min = tolower(c);
            
            limpiarBuffer(); // Limpia lo que quedó después del getchar
    
            if (min != 'n' && min != 'y') {
                printf("\nError, ingrese un dato valido.");
            }
    
        } while (min != 'n' && min != 'y');

        pausa();

    }while (min == 'n');
}

void interfaz11(){
    char min;
    bool bandera;
    char c;
    int n, b;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 10     |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        
        /* fflush(stdin);

        printf("Ingrese un numero explosivo [N]: ");
        bandera = scanf("%d", &n);
        while(bandera != 1 || n <= 0){
            printf("\nError, ingrese un dato valido.");
            fflush(stdin);
            printf("\nIngrese un numero explosivo [N]: ");
            bandera = scanf("%d", &n);
        }

        fflush(stdin);

        printf("Ingrese un numero bomba [B]: ");
        bandera = scanf("%d", &b);
        while(bandera != 1 || n < b || b <= 0){
            printf("\nError, ingrese un dato valido.");
            fflush(stdin);
            printf("\nIngrese un numero bomba [B]: ");
            bandera = scanf("%d", &b);
        }

        int * v;

        printf("\nEl resultado de explotar [%d] con [%d] es: ",n,b);

        v = explosion(n, b); */

        limpiarBuffer();

        //free(v);

        do {
            printf("\n\nDESEA SALIR? Y/N: ");
            c = getchar();
            min = tolower(c);
            
            limpiarBuffer(); // Limpia lo que quedó después del getchar
    
            if (min != 'n' && min != 'y') {
                printf("\nError, ingrese un dato valido.");
            }
    
        } while (min != 'n' && min != 'y');

        pausa();

    }while (min == 'n');
}
