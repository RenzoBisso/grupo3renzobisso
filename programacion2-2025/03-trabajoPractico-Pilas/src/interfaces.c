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
        pedirNumero(&clave);
        limpiarBuffer();

        bool res = p_ej2_existeclave(p, clave);

        printf("\t||\n");
        printf("\t||La clave: [%d] se encuentra en la pila? %s\n",clave , res ? "SI":"NO");

        //B
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||B: COLOCAR UNA CLAVE EN UNA POSICION ORDINAL                                                        ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        pedirNumero(&clave);
        limpiarBuffer();

        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||Ingrese una Posicion:                                                                               ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        pedirNumero(&pos);
        limpiarBuffer();

        while(pos > largo(p)){
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
            printf("\t||EEROR, INGRESE UNA POSICION VALIDA:                                                                 ||\n");
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
            pedirNumero(&pos);
            limpiarBuffer();
        }

        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        p = p_ej2_colocarelemento(p, pos, te_crear(clave));

        printf("\t||");
        printf("\n\t|| Pila: ");
        p_mostrar(p);

        printf("\t||\n");

        //C
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||C: ELIMINA DE LA PILA UNA CLAVE (1ERA APARICION)                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        pedirNumero(&clave);
        limpiarBuffer();
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

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
        limpiarBuffer();

        while(pos > largo(p)){
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
            printf("\t||EEROR, INGRESE UNA POSICION VALIDA:                                                                 ||\n");
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
            pedirNumero(&pos);
            limpiarBuffer();
        }

        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||Ingrese la segunda posicion:                                                                        ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        pedirNumero(&pos2);
        limpiarBuffer();

        while(pos2 > largo(p)){
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
            printf("\t||EEROR, INGRESE UNA POSICION VALIDA:                                                                 ||\n");
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
            pedirNumero(&pos2);
            limpiarBuffer();
        }

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

        printf("\t||La pila cuenta con [%d] Elementos\n", p_ej2_cantidadelementos(p));
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

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
            printf("\t||                                                                                                    ||\n");
            printf("\t||");
            p_mostrar(p0);
            printf("\t||");
            p_mostrar(p1);
            printf("\t||\n");
            printf("\t||----------------------------------------------------------------------------------------------------||\n");

        }else{
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
            printf("\t||LAS PILAS NO SON IGUALES                                                                            ||\n");
            printf("\t||                                                                                                    ||\n");
            printf("\t||");
            p_mostrar(p0);
            printf("\t||");
            p_mostrar(p1);
            printf("\t||\n");
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
        }
        
        
        limpiarBuffer();

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfaz4(){
    char c;
    bool flag=false;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 4      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||TRANSFORMA UN NUMERO A UNA BASE DE 2 A 16                                                           ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INGRESE EL NUMERO A TRANSFORMAR                                                                     ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        int numero;
        int base;
        pedirNumero(&numero);
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INGRESE EL NUMERO DE LA BASE 2-16                                                                   ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");  
        
        while(flag==false){
            pedirNumero(&base);
            
            if(base>16 || base<2){
                printf("\t||\n");
                printf("\t||");
                printf("DATO INVALIDO\n");
                printf("\t||\n");
            }
            else{
                flag=true;
            }
        }

        printf("\t||");
        printf("%s\n", p_ej4_cambiarbase(numero,base));
        printf("\t||");

        limpiarBuffer();

        c = salir();
        
        pausa();

    }while (c == 'n');
}

void interfaz5(){
    char c;
    int opcion;
    Pila invertida = p_crear();
    do  //MENU/////////////////////////////////////////////////
    {
        Pila p0 = p_crear();
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 5      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||INVIERTE EL CONTENIDO DE UNA PILA SIN DESTRUIRLA                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        opcion = cargaManualAuto();
        if(opcion==1){
            llenarPRandom(p0);
        }
        else{
            interfazCargaPila(p0);
        }
        printf("\t||PILA ORIGINAL                                                                                       ||\n");
        printf("\t||");
        p_mostrar(p0);
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        invertida = p_ej5_invertir(p0);

        printf("\t||PILA iNVERTIDA                                                                                      ||\n");
        printf("\t||");
        p_mostrar(invertida);
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        limpiarBuffer();

        c = salir();
        free(invertida);
        pausa();

    }while (c == 'n');
}

void interfaz6(){
    char c;


    do  //MENU/////////////////////////////////////////////////
    {
        int opcion;
        int valor;
        Pila p0=p_crear();
        Pila pR=p_crear();
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 6      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||ELIMINA TODAS LAS OCURRENCIAS DE UN DETERMINADO VALOR SIN PERDER LA PILA ORIGINAL                   ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        opcion = cargaManualAuto();
        if(opcion){
            llenarPRandom(p0);
            p_mostrar(p0);
            llenarPRandom(pR);
            p_mostrar(pR);
        }
        else{
            printf("Pila para eliminar normal\n");
            interfazCargaPila(p0);
            p_mostrar(p0);
            printf("Pila para eliminar recursivo\n");
            interfazCargaPila(pR);
            p_mostrar(pR);
            
        }
        printf("Eliminar valor normal\n");
        pedirNumero(&valor);
        Pila pSinValor=p_crear();
        pSinValor=p_ej6_eliminarclave(p0,valor);
        p_mostrar(pSinValor);
        printf("Eliminar valor recursivo\n");
        pedirNumero(&valor);
        Pila pSinValorR=p_crear();
        pSinValorR=p_ej6_eliminarclaveR(pR,valor);
        p_mostrar(pSinValorR);

        limpiarBuffer();
        c = salir();
        pausa();

    }while (c == 'n');
}

void interfaz7(){
    char c;
    int opcion;
    Pila p1= p_crear();
    Pila p2= p_crear();
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 7      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||RETORNA LOS ELEMENTOS EN COMUN DE DOS PILAS                                                         ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        opcion = cargaManualAuto();
        if(opcion){
            llenarPRandom(p1);
            p_mostrar(p1);
            llenarPRandom(p2);
            p_mostrar(p2);
        }
        else{
            interfazCargaPila(p1);
            p_mostrar(p1);
            interfazCargaPila(p2);
            p_mostrar(p2);
            
        }

        Pila pResult=p_crear();
        pResult=p_ej7_elementoscomunes(p1,p2);
        p_mostrar(pResult);

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

        Pila pResult = p_crear();

        pResult = p_ej8_sacarrepetidos(p);

        printf("\t||");
        printf("\n\t|| Pila: ");
        p_mostrar(p);

        printf("\t||\n");

        p_mostrar_con_valor(pResult);

        printf("\t||\n");

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
    printf("\t||----------------------------------------------------------------------------------------------------||\n");
    p_cargar(p1, tamanio, 0);

    //limpiar_pantalla();
    printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
}
