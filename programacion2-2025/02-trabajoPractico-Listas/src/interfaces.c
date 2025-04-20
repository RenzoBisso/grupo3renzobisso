#define _CRT_SECURE_NO_WARNINGS

#include "..\headers\interfaz.h"
#include "..\headers\utilidades.h"
#include "..\headers\tp_2_listas.h"


void interfaz2(){
    char c;
    float prom;
    ResultadoValorMinimo res;
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

        llenarLRandom(l1);

        llenarLRandom(l2);

        printf("\t||");
        printf("\n\t|| Lista 1: ");
        l_mostrar(l1);

        printf("\t||");

        printf("\n\t|| Lista 2: ");
        l_mostrar(l2);
        printf("\t||\n");

        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||A: MOSTRAR LOS VALORES DE L1 QUE NO SE ENCUENTRAN EN L2:                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        Lista resultado = verElementosQueNoSeRepiten(l1, l2);

        printf("\t||");
        printf("\n\t|| Valores de L1 que no se encuentran en L2: ");
        l_mostrar(resultado);
        printf("\t||\n");

        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||B: MOSTRAR LOS VALORES DE L2 QUE NO SE ENCUENTRAN EN L1:                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        free(resultado);
        resultado = verElementosQueNoSeRepiten(l2, l1);

        printf("\t||");
        printf("\n\t|| Valores de L2 que no se encuentran en L1: ");
        l_mostrar(resultado);
        printf("\t||\n");

        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||C: MOSTRAR LOS VALORES REPETIDOS:                                                                   ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
            
        free(resultado);
        resultado = verElementosRepetidos(l1, l2);

        printf("\t||");
        printf("\n\t|| Valores repetidos: ");
        l_mostrar(resultado);
        printf("\t||\n");
        free(resultado);

        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||MOSTRAR EL PROMEDIO DE AMBAS LISTAS:                                                                ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        prom = promedio(l1);

        printf("\t||");
        printf("\n\t|| Promedio Lista 1: %.2f\n", prom);
        printf("\t||");

        prom = promedio(l2);

        printf("\n\t|| Promedio Lista 2: %.2f\n", prom);
        printf("\t||\n");

        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||MOSTRAR EL VALOR MINIMO Y SU POSICION ORDINAL                                                       ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        res = valorMinimo(l1, l2);

        printf("\t||\n");
        printf("\t|| Valor minimo y posicion ordinal de L1: min[%d]; pos[%d]\n", res.valor, res.pos);
        printf("\t||\n");
        printf("\t|| Valor minimo y posicion ordinal de L2: min[%d]; pos[%d]\n", res.valor_2, res.pos_2);
        printf("\t||\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");

        free(l1);
        free(l2);

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfaz3(){
    char c;
    ResultadosMul res;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 3      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||DADAS DOS LISTAS, DETERMINAR SI L2 ES MULTIPLO Y ESCALAR DE L1                                      ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||Ingrese 1 para cargar al azar o 0 para cargar manualmente:                                          ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        Lista l1 = l_crear();
        Lista l2 = l_crear();
        int opcion=-1;
        pedirNumero(&opcion);
        bool flag = true;
        while (flag) {
            if (opcion != 1 && opcion != 0) {
                pedirNumero(&opcion);
            }
            else if (opcion == 1) {
                flag = false;

                llenarLRandom(l1);
                llenarLRandom(l2);

            }
            else if (opcion == 0) {
                flag = false;
                interfazCargaLista(l1);
                interfazCargaLista(l2);

            }
            else {
                printf("Opción no válida. Ingrese 0 o 1.\n");
            }
        }

 //TEMPORAL HASTA TENER LA FUNCION DE TAMAÑO Y CARGA MANUAL;

        res = multiplo(l2, l1);

        printf("\t||");
        printf("\n\t|| Lista 1: ");
        l_mostrar(l1);

        printf("\t||");

        printf("\n\t|| Lista 2: ");
        l_mostrar(l2);
        printf("\t||\n");

        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||\n");
        printf("\t|| Es multiplo? %s\n", res.esMultiplo ? "SI":"NO");
        printf("\t||\n");
        printf("\t|| Es escalar? %s\n", res.escalar ? "SI":"NO");
        printf("\t||\n");
        if(res.escalar){
            printf("\t|| Numero escalar %d\n", res.numEscalar);
            printf("\t||\n");
        }
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");

        free(l1);
        free(l2);

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfaz4(){
    char c;
    int num;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 4      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||DADAS DOS LISTAS, COMPARAR SI L1 ES MAYOR/MENOR/IGUAL A L2                                          ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        printf("\t||Ingrese 1 para cargar al azar o 0 para cargar manualmente:                                          ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        Lista l1 = l_crear();
        Lista l2 = l_crear();
        int opcion = -1;
        pedirNumero(&opcion);
        bool flag = true;
        while (flag) {
            if (opcion != 1 && opcion != 0) {
                pedirNumero(&opcion);
            }
            else if (opcion == 1) {

                llenarLRandom(l1);
                llenarLRandom(l2);
                printf("\t||");
                printf("\n\t|| Lista 1: ");
                l_mostrar(l1);

                printf("\t||");

                printf("\n\t|| Lista 2: ");
                l_mostrar(l2);
                printf("\t||\n");
                flag = false;

            }
            else if (opcion == 0) {
                interfazCargaLista(l1);
                interfazCargaLista(l2);

                flag = false;

            }
            else {
                printf("Opción no válida. Ingrese 0 o 1.\n");
            }
        }



        num = CompararListas(l1, l2);

        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||\n");
        switch(num)
        {
        case 0:
            printf("\t|| L1 es igual a L2\n");
            break;
        case 1:
            printf("\t|| L1 es mayor que L2\n");
            break;
        case 2:
            printf("\t|| L1 es menor que L2\n");
            break;
        default:

            break;
        }
        printf("\t||\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");

        free(l1);
        free(l2);

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfaz5(){
    char c;
    double x;
    double y;
    double intervalo;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 5      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||DADA UNA LISTA DE COEFICIENTES Y CIERTO VALOR DE X, DEVOLVER UN POLINOMIO F(X)                      ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
   
        printf("\t||Ingrese 1 para cargar al azar o 0 para cargar manualmente:                                          ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        Lista l1 = l_crear();
        int opcion = -1;
        pedirNumero(&opcion);
        bool flag = true;
        while (flag) {
            if (opcion != 1 && opcion != 0) {
                pedirNumero(&opcion);
            }
            else if (opcion == 1) {

                llenarLRandom(l1);
                printf("\t||");
                printf("\n\t|| Lista 1: ");
                l_mostrar(l1);

                printf("\t||");

                printf("\n\t|| Lista 2: ");
                printf("\t||\n");
                flag = false;

            }
            else if (opcion == 0) {
                interfazCargaLista(l1);
                flag = false;

            }
            else {
                printf("Opción no válida. Ingrese 0 o 1.\n");
            }
        }

        flag = true;
        while (flag)
        {
            double valor;
            printf("Ingrese el numero X:");

            if (scanf("%lf", &valor) != 1) {
                printf("Entrada inválida. No se ingresó un número entero.\n");
                while (getchar() != '\n');
            }
            else {
                x = valor;
                flag = false;
            }
        }
        flag = true;
        while (flag)
        {
            double valor;
            printf("Ingrese el numero Y:");

            if (scanf("%lf", &valor) != 1) {
                printf("Entrada inválida. No se ingresó un número entero.\n");
                while (getchar() != '\n');
            }
            else {
                y= valor;
                flag = false;
            }
        }
        flag = true;
        while (flag)
        {
            double valor;
            printf("Ingrese el numero valor del intervalo:");

            if (scanf("%lf", &valor) != 1) {
                printf("Entrada inválida. No se ingresó un número entero.\n");
                while (getchar() != '\n');
            }
            else {
                intervalo = valor;
                flag = false;
            }
        }

        printf("\t||\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||COEFICIENTES DE LA LISTA:                                                                           ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||\n");
        printf("\t||");
        mostrar_coeficientes(l1);
        printf("\t||\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||RESOLUCION DE F(X) CON RANGO {%.2f;%.2f}, E INTERVALO %.2f                                          ||\n", x, y, intervalo);
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||\n");

        Lista resultado = calcularRango(l1, x, y, intervalo);

        printf("\t|| ");
        l_mostrar_con_valor(resultado);
        printf("\t||\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfaz6(){
    char c;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 6      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||DADAS DOS LISTAS, DETERMINAR SI L2 ES SUBLISTA DE L1                                                ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||Ingrese 1 para cargar al azar o 0 para cargar manualmente:                                          ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        Lista l1 = l_crear();
        Lista l2 = l_crear();
        int opcion = -1;
        pedirNumero(&opcion);
        bool flag = true;
        while (flag) {
            if (opcion != 1 && opcion != 0) {
                pedirNumero(&opcion);
            }
            else if (opcion == 1) {
                flag = false;

                llenarLRandom(l1);
                llenarLRandom(l2);

            }
            else if (opcion == 0) {
                flag = false;
                interfazCargaLista(l1);
                interfazCargaLista(l2);

            }
            else {
                printf("Opción no válida. Ingrese 0 o 1.\n");
            }
        }

        printf("\t||");
        printf("\n\t|| Lista 1: ");
        l_mostrar(l1);

        printf("\t||");

        printf("\n\t|| Lista 2: ");
        l_mostrar(l2);
        printf("\t||\n");

        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||\n");

        if(esSublista(l1, l2)){
            printf("\t|| L2 es sublista de L1.\n");
        }
        else{
            printf("\t|| L2 NO es sublista de L1.\n");
        }

        printf("\t||\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");

        free(l1);
        free(l2);

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfazCargaLista(Lista * l1) {

        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       Cargar Lista     |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        int tamanio = 0;
        bool flag = true;
        while (flag)
        {
            printf("\t||Ingrese el tamanio de la lista:                                                                 ||\n");

            if (scanf("%d", &tamanio) != 1) {
                printf("Entrada inválida. No se ingresó un número entero.\n");
                while (getchar() != '\n');
            }
            else {
                if (tamanio >= 1) {
                    flag = false;
                }
            }
        }

        
        //llenarLRandom(l1);
        //llenarLRandom(l2);
        printf("Lista 1\n");
        cargarLista(l1, tamanio, 0);

        printf("\t||");
        printf("\n\t|| Lista 1: ");
        l_mostrar(l1);

        printf("\t||");

        printf("\t||\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
}
