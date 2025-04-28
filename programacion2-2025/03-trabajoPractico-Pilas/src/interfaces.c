#define _CRT_SECURE_NO_WARNINGS

#include "..\headers\interfaz.h"
#include "..\headers\utilidades.h"
#include "..\headers\tp_3_pilas.h"


void interfaz2(){
    char c;
    int opcion;
    int pos,pos2;
    int clave;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 2      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||DADA UNA PILA CARGADA CON VALORES NUMERICOS                                                         ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        Pila p = p_crear();

        opcion = cargaManualAuto();
        if(opcion){
            llenarPRandom(p);
        }
        else{
            interfazCargaPila(p);
        }

        printf("\t||");
        printf("\n\t|| Pila: ");
        p_mostrar(p);

        printf("\t||\n");

        //A
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||A: DETERMINA SI UNA CLAVE SE ENCUENTRA DENTRO DE LA PILA                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||Ingrese una Clave:                                                                                  ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        pedirNumero(&clave);

        bool res = p_ej2_existeclave(p, clave);

        printf("\t||La clave: [%d] se encuentra en la pila? %s\n",clave , res ? "SI":"NO");

        //B
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||B: COLOCAR UNA CLAVE EN UNA POSICION ORDINAL                                                        ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||Ingrese una Clave:                                                                                  ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        pedirNumero(&clave);

        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||Ingrese una Posicion:                                                                               ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        pedirNumero(&pos);

        p = p_ej2_colocarelemento(p, pos, te_crear(clave));

        printf("\t||");
        printf("\n\t|| Pila: ");
        p_mostrar(p);

        printf("\t||\n");

        //C
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||C: ELIMINA DE LA PILA UNA CLAVE (1ERA APARICION)                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||Ingrese una Clave:                                                                                  ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        pedirNumero(&clave);

        p = p_ej2_eliminarclave(p, clave);

        printf("\t||");
        printf("\n\t|| Pila: ");
        p_mostrar(p);

        printf("\t||\n");

        //D
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||D: INTERCAMBIA DOS POSICIONES ORDINALES DE LA PILA                                                  ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||Ingrese la primera posicion:                                                                        ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        pedirNumero(&pos);

        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||Ingrese la segunda posicion:                                                                        ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        pedirNumero(&pos2);

        p = p_ej2_intercambiarposiciones(p, pos, pos2);

        printf("\t||");
        printf("\n\t|| Pila: ");
        p_mostrar(p);

        printf("\t||\n");

        //E
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||E: DUPLICA EL CONTENIDO DE LA PILA                                                                  ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        Pila aux = p_crear();
        aux = p_ej2_duplicar(p);

        printf("\t||");
        printf("\n\t|| Pila: ");
        p_mostrar(p);

        printf("\t||");

        printf("\n\t||");
        printf("\n\t|| Pila Auxiliar: ");
        p_mostrar(aux);

        printf("\t||\n");

        //F
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||F: RETORNA LA CANTIDAD DE ELEMENTOS DE LA PILA                                                      ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        printf("\t||La pila cuenta con [%d] Elementos", p_ej2_cantidadelementos(p));

        free(p);
        free(aux);

        limpiarBuffer();

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfaz3(){
    char c;
    int opcion;
    do  //MENU/////////////////////////////////////////////////
    {
        Pila p0=p_crear();
        Pila p1=p_crear();
        int num;
        
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 3      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||DADAS DOS PILAS DETERMINAR SI SUS CONTENIDOS SON EXACTAMENTE IGUALES                                ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        opcion = cargaManualAuto();
        if(opcion){
            llenarPRandom(p0);
            llenarPRandom(p1);
        }
        else{
            interfazCargaPila(p0);
            interfazCargaPila(p1);
        }
        
        

        if(p_ej3_iguales(p0,p1)==true){
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
            printf("\t||LAS PILAS SON IGUALES                                                                               ||\n");
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
        }else{
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
            printf("\t||LAS PILAS NO SON IGUALES                                                                            ||\n");
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
        }
        
        
        limpiarBuffer();

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfaz4(){
    char c;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 4      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        int numero;
        int base;
        printf("Ingrese el numero a transformar\n");
        pedirNumero(&numero);
        printf("\n");
        printf("Ingrese el numero de la base 2-16\n");
        pedirNumero(&base);
        if(base>16 || base<2){
            printf("dato invalido");
        }


        printf("%s\n", p_ej4_cambiarbase(numero,base));


        limpiarBuffer();

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfaz5(){
    char c;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 5      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        p_ej4_cambiarbase(10,16);

        limpiarBuffer();

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
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");


        limpiarBuffer();

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfaz7(){
    char c;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 7      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");


        limpiarBuffer();

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfaz8(){
    char c;
    int opcion;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 8      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||DADA UNA PILA CON VALORES REPETIDOS, DEVUELVE LA CANTIDAD DE VECES QUE APARECE UN VALOR             ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        Pila p = p_crear();

        opcion = cargaManualAuto();
        if(opcion){
            llenarPRandom(p);
        }
        else{
            interfazCargaPila(p);
        }

        printf("\t||");
        printf("\n\t|| Pila: ");
        p_mostrar(p);

        printf("\t||");

        p_mostrar_con_valor(p);

        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");

        limpiarBuffer();

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfazCargaPila(Pila  p1) {
    //limpiar_pantalla();
    printf("\t||CARGA MANUAL...                                                                                     ||\n");
    printf("\t||----------------------------------------------------------------------------------------------------||\n");
    int tamanio;
    bool flag = true;
    while (flag)
    {
        limpiarBuffer();

        printf("\t||Ingrese el tamanio de la pila: ");

        if (scanf("%d", &tamanio) != 1) {
            printf("\t||\n");
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
            printf("\t||Entrada invalida. No se ingreso un numero entero.                                                   ||\n");
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
            //while (getchar() != '\n');
        }
        else {
            if (tamanio >= 1) {
                flag = false;
            }
            else{                                                                                                                 
                printf("\t||\n");
                printf("\t||----------------------------------------------------------------------------------------------------||\n");
                printf("\t||Entrada invalida. No se ingreso un numero entero.                                                   ||\n");
                printf("\t||----------------------------------------------------------------------------------------------------||\n");
            }
        }
        
    }

    
    //llenarLRandom(l1);
    //llenarLRandom(l2);
    printf("\t||----------------------------------------------------------------------------------------------------||\n");
    p_cargar(p1, tamanio, 0);

    //limpiar_pantalla();
    printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
}
