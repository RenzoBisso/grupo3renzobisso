#define _CRT_SECURE_NO_WARNINGS

#include "..\..\libs\validaciones\headers\utilidades.h"
#include "..\headers\interfaz.h"
#include "..\headers\tp_arboles.h"

void interfaz2() {
  char c;
  int opcion;
  int clave;
  do  // MENU/////////////////////////////////////////////////
  {
    printf("\t\t\t                      +------------------------+\n");
    printf("\t\t\t                      |       EJERCICIO 2      |\n");
    printf("\t\t\t                      +------------------------+\n\n\n");
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||DADO UN ARBOL BINARIO NO VACIO DETERMINAR                         "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");
    printf(
        "\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL          "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    ArbolBinario A = a_crear();

    Lista l = l_crear();

    opcion = cargaManualAuto();
    if (opcion) {
      // LLENAR RANDOM
    } else {
      // LLENAR MANUAL
    }

    printf("\t||\n");

    // A
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||A: RETORNA UNA LISTA CON TODOS LOS NODOS HOJA                     "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    l = a_ej2_hojas(A);

    printf("\t||\n");
    printf("\t|| ");
    l_mostrar(l);
    printf("\t||\n");

    free(l);

    // B
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||B: RETORNA UNA ESTRUCTURA CON TODOS LOS NODOS INTERIORES          "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    l = a_ej2_interiores(A);

    printf("\t||\n");
    printf("\t|| ");
    l_mostrar(l);
    printf("\t||\n");

    free(l);

    // C
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||C: BUSCA TODAS LAS OCURRENCIAS DE UNA CLAVE Y RETORNA SUS "
        "POSICIONES                                ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    printf("\t||\n");

    pedirNumero(&clave);

    l = a_ej2_buscarclave(A, clave);

    printf("\t||\n");
    printf("\t|| ");  // l_mostrar_ej2(l);
    printf("\t||\n");

    free(l);

    // D
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||D: COMPLEJIDAD ALGORITMICA DE LOS PUNTOS A), B) Y C)              "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    printf("\t||\n");
    printf("\t|| Complejidad A: \n");
    printf("\t|| Complejidad B: \n");
    printf("\t|| Complejidad C: \n");
    printf("\t||\n");

    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    free(A);

    limpiarBuffer();

    c = salir();

    pausa();

  } while (c == 'n');
}

void interfaz3() {
  char c;
  int opcion;
  int clave;
  do  // MENU/////////////////////////////////////////////////
  {
    printf("\t\t\t                      +------------------------+\n");
    printf("\t\t\t                      |       EJERCICIO 3      |\n");
    printf("\t\t\t                      +------------------------+\n\n\n");
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||PARA UN NODO DE UN ARBOL BINARIO DETERMINAR                       "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");
    printf(
        "\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL          "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    ArbolBinario A = a_crear();

    Lista l = l_crear();

    opcion = cargaManualAuto();
    if (opcion) {
      // LLENAR RANDOM
    } else {
      // LLENAR MANUAL
    }

    // A
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||A: RETORNA LA CLAVE DEL NODO PADRE/RAIZ                           "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    printf("\t|| INGRESE LA CLAVE DEL NODO HIJO \n");
    pedirNumero(&clave);

    printf("\t||\n");
    printf("\t|| CLAVE: %d\n", a_ej3_clavepadre(A, clave));

    // B
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||B: LISTA LOS NODOS HOJA (CLAVE)                                   "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    printf("\t|| INGRESE LA CLAVE DEL NODO PADRE \n");
    pedirNumero(&clave);

    l = a_ej3_hijos(A, clave);

    printf("\t||\n");
    printf("\t|| ");
    l_mostrar(l);
    printf("\t||\n");

    free(l);

    // C
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||C: RETORNA EL NODO HERMANO DE UNA CLAVE                           "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    printf("\t|| INGRESE EL NODO HERMANO \n");
    pedirNumero(&clave);

    printf("\t||\n");
    printf("\t|| NODO HERMANO DE %d: [%d] \n", clave, a_ej3_hermano(A, clave));
    printf("\t||\n");

    // D
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||D: CALCULA EL NIVEL EN EL QUE SE ENCUENTRA UN NODO                "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    printf("\t|| INGRESE LA CLAVE DEL NODO \n");
    pedirNumero(&clave);

    printf("\t||\n");
    printf("\t|| EL NODO CON LA CLAVE '%d' SE ENCUENTRA EN EL NIVEL %d \n",
           clave, a_ej3_nivel(A, clave));
    printf("\t||\n");

    // E
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||E: CALCULA LA ALTURA DE LA RAMA DE UN NODO                        "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    printf("\t|| INGRESE LA CLAVE DEL NODO \n");
    pedirNumero(&clave);

    printf("\t||\n");
    printf("\t|| LA ALTURA DE LA RAMA DEL NODO CON LA CLAVE '%d' ES: [%d] \n",
           clave, a_ej3_alturarama(A, clave));
    printf("\t||\n");

    // F
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||F: LISTA TODOS LOS NODOS EN EL MISMO NIVEL (CLAVE)                "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    printf("\t|| INGRESE EL NIVEL \n");
    pedirNumero(&clave);

    l = a_ej3_clavesmismonivel(A, clave);

    printf("\t||\n");
    printf("\t|| ");
    l_mostrar(l);
    printf("\t||\n");

    free(l);
    free(A);

    limpiarBuffer();

    c = salir();

    pausa();

  } while (c == 'n');
}

void interfaz4() {
  char c;
  int opcion;
  int clave;
  do  // MENU/////////////////////////////////////////////////
  {
    printf("\t\t\t                      +------------------------+\n");
    printf("\t\t\t                      |       EJERCICIO 4      |\n");
    printf("\t\t\t                      +------------------------+\n\n\n");
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||PARA ARBOLES N-ARIOS                                              "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");
    printf(
        "\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL          "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    ArbolBinario A = a_crear();

    Lista l = l_crear();

    opcion = cargaManualAuto();
    if (opcion) {
      // LLENAR RANDOM
    } else {
      // LLENAR MANUAL
    }

    // A
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||A: RETORNAR UNA LISTA CON EL RESULTADO DE RECORRER EL ARBOL POR "
        "ANCHURA                             ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    l = a_ej4_anchura(A);

    printf("\t||\n");
    printf("\t|| NODOS EN RECORRIDO DE ANCHURA: ");
    l_mostrar(l);
    printf("\t||\n");

    free(l);

    // B
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||B: DEVUELVE LA CANTIDAD DE NODOS HOJAS DEL ARBOL N-ARIO           "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    printf("\t||\n");
    printf("\t|| EL ARBOL TIENE [%d] NODOS HOJA\n", a_ej4_q_hojas(A));
    printf("\t||\n");

    // C
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||C: DETERMINA SI DOS ARBOLES N-ARIOS TIENEN LA MISMA ESTRUCTURA    "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");
    printf(
        "\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL (ARBOL "
        "B)                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    ArbolBinario B = a_crear();

    opcion = cargaManualAuto();
    if (opcion) {
      // LLENAR RANDOM
    } else {
      // LLENAR MANUAL
    }

    printf("\t||\n");
    if (a_ej4_similares(A, B)) {
      printf("\t|| LOS ARBOLES A Y B SON SIMILARES\n");
    } else {
      printf("\t|| LOS ARBOLES A Y B 'NO' SON SIMILARES\n");
    }
    printf("\t||\n");

    free(B);

    // D
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||D: RETORNA EL PADRE DE UN ELEMENTO DEL ARBOL                      "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    printf("\t||\n");
    pedirNumero(&clave);

    printf("\t||\n");
    printf("\t|| EL PADRE DE %d ES [%d]\n", clave,
           a_ej4_padre(A, clave)->clave);
    printf("\t||\n");

    // E
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||E: RETORNA LOS HERMANOS DE UN NODO DEL ARBOL                      "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    printf("\t||\n");
    pedirNumero(&clave);

    l = a_ej4_hermanos(A, clave);

    printf("\t||\n");
    printf("\t|| LISTA DE HERMANOS DE %d: ", clave);
    l_mostrar(l);
    printf("\t||\n");

    free(l);
    free(A);

    limpiarBuffer();

    c = salir();

    pausa();

  } while (c == 'n');
}

void interfaz5() {
  char c;
  int opcion;
  do  // MENU/////////////////////////////////////////////////
  {
    printf("\t\t\t                      +------------------------+\n");
    printf("\t\t\t                      |       EJERCICIO 7      |\n");
    printf("\t\t\t                      +------------------------+\n\n\n");
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||DETERMINAR SI DOS ARBOLES BINARIOS SON EQUIVALENTES               "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");
    printf(
        "\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL (ARBOL "
        "A)                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    ArbolBinario A = a_crear();

    opcion = cargaManualAuto();
    if (opcion) {
      // LLENAR RANDOM
    } else {
      // LLENAR MANUAL
    }

    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL (ARBOL "
        "B)                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    ArbolBinario B = a_crear();

    opcion = cargaManualAuto();
    if (opcion) {
      // LLENAR RANDOM
    } else {
      // LLENAR MANUAL
    }

    printf("\t||\n");
    if (a_ej7_equivalente(A, B)) {
      printf("\t|| LOS ARBOLES BINARIOS A Y B SON EQUIVALENTES\n");
    } else {
      printf("\t|| LOS ARBOLES BIANRIOS A Y B 'NO' SON EQUIVALENTES\n");
    }

    free(A);
    free(B);

    limpiarBuffer();

    c = salir();

    pausa();

  } while (c == 'n');
}

void interfaz6() {
  char c;
  int opcion;
  int clave;
  do  // MENU/////////////////////////////////////////////////
  {
    printf("\t\t\t                      +------------------------+\n");
    printf("\t\t\t                      |       EJERCICIO 8      |\n");
    printf("\t\t\t                      +------------------------+\n\n\n");
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||DADO UN ARBOL N-ARIO DETERMINAR                                   "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");
    printf(
        "\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL          "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    Lista l = l_crear();

    ArbolBinario A = a_crear();

    opcion = cargaManualAuto();
    if (opcion) {
      // LLENAR RANDOM
    } else {
      // LLENAR MANUAL
    }

    // O1
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||O: DETERMINAR LA ALTURA DEL ARBOL                                 "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    printf("\t||\n");
    printf("\t|| LA ALTURA DEL ARBOL ES: [%d]\n", a_ej8_altura(A));
    printf("\t||\n");

    // O2
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||O: DETERMINAR EL NIVEL DE UN NODO                                 "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    printf("\t|| INGRESE CLAVE DE UN NODO: \n");
    pedirNumero(&clave);

    printf("\t||\n");
    printf("\t|| EL NIVEL DEL NODO %d ES: [%d]\n", clave,
           a_ej8_nivel(A, clave));
    printf("\t||\n");

    // O3
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||O: LISTAR TODOS LOS NODOS INTERNOS                                "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    l = a_ej8_internos(A);

    printf("\t||\n");
    printf("\t|| NODOS INTERNOS: \n");
    l_mostrar(l);
    printf("\t||\n");

    free(l);

    // O4
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||O: DETERMINAR SI TODAS LAS HOJAS ESTAN AL MISMO NIVEL             "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    printf("\t||\n");
    if (a_ej8_hojasmismonivel(A)) {
      printf("\t|| TODAS LAS HOJAS ESTAN AL MISMO NIVEL\n");
    } else {
      printf("\t|| NO TODAS LAS HOJAS ESTAN AL MISMO NIVEL\n");
    }
    printf("\t||\n");

    free(A);

    limpiarBuffer();

    c = salir();

    pausa();

  } while (c == 'n');
}

void interfaz7() {
  char c;
  int opcion;
  do  // MENU/////////////////////////////////////////////////
  {
    printf("\t\t\t                      +------------------------+\n");
    printf("\t\t\t                      |       EJERCICIO 9      |\n");
    printf("\t\t\t                      +------------------------+\n\n\n");
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||A PARTIR DE UN ARBOL BINARIO LO TRANSFORMA EN ARBOL AVL           "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");
    printf(
        "\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL          "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");

    ArbolBinario A = a_crear();

    opcion = cargaManualAuto();
    if (opcion) {
      // LLENAR RANDOM
    } else {
      // LLENAR MANUAL
    }

    free(A);

    limpiarBuffer();

    c = salir();

    pausa();

  } while (c == 'n');
}

void interfaz8() {
  char c;
  int opcion;
  bool flag;
  int q;

  do  // MENU/////////////////////////////////////////////////
  {
    printf("\t\t\t                      +------------------------+\n");
    printf("\t\t\t                      |       EJERCICIO 10      |\n");
    printf("\t\t\t                      +------------------------+\n\n\n");
    printf(
        "\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
    printf(
        "\t||                                                                  "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");
    printf(
        "\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL          "
        "                                  ||\n");
    printf(
        "\t||------------------------------------------------------------------"
        "----------------------------------||\n");
    ArbolBinarioBusqueda abb = abb_crear();
    ArbolAVL avl = avl_crear();
    opcion = cargaManualAuto();
    if (opcion) {
      cargar_avl(avl);
      cargar_abb(abb);
    } else {
        }

    free(avl);

    limpiarBuffer();

    c = salir();

    pausa();

  } while (c == 'n');
}