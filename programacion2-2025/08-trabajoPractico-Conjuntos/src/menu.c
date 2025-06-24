#include "..\..\libs\validaciones\headers\utilidades.h"
#include "..\headers\tp_conjunto.h"

void menu(){
    char c;
    do {
        int opcion;
        printf("\n\t\tMENU DE OPERACIONES CON CONJUNTOS\n");
        printf("\t1. Operaciones entre dos conjuntos (Pertenencia, Interseccion, Union, Diferencia)\n");
        printf("\t2. Union e interseccion de una coleccion de conjuntos\n");
        printf("\t3. Transitividad entre conjuntos\n");
        printf("\t4. Diferencia simetrica entre conjuntos\n");
        printf("\t5. Subconjuntos propios entre dos conjuntos\n");
        printf("\t6. Subconjuntos parciales entre tres conjuntos\n");
        printf("\t7. Comparacion de igualdad entre conjuntos\n");
        printf("\tIngrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                Conjunto c1 = cto_crear();
                Conjunto c2 = cto_crear();
                int cantidad;
                printf("Ingrese primer conjunto\n");
                pedirCantidad(&cantidad);
                carga_datos(c1, cantidad);
                printf("Ingrese segundo conjunto\n");
                pedirCantidad(&cantidad);
                carga_datos(c2, cantidad);

                int clave;
                printf("Ingrese la clave para saber si pertenece a los conjuntos: ");
                pedirDatos(&clave, 11);

                if (c_ej2_pertenencia(c1, clave)) {
                    printf("El elemento %d pertenece al conjunto 1\n", clave);
                    cto_mostrar(c1);
                }
                if (c_ej2_pertenencia(c2, clave)) {
                    printf("El elemento %d pertenece al conjunto 2\n", clave);
                    cto_mostrar(c2);
                }
                if (!c_ej2_pertenencia(c1, clave) && !c_ej2_pertenencia(c2, clave)) {
                    printf("No pertenece a ninguno de los dos conjuntos\n");
                }

                printf("\nInterseccion: ");
                cto_mostrar(c_ej2_interseccion(c1, c2));
                printf("\nUnion: ");
                cto_mostrar(c_ej2_union(c1, c2));
                printf("\nDiferencia: ");
                cto_mostrar(c_ej2_diferencia(c1, c2));
                break;
            }
            case 2: {
                Lista l_conjuntos = coleccionDeConjuntos(3);
                Conjunto ctoInter = c_ej3_intersecciones(l_conjuntos);
                Conjunto ctoUnion = c_ej3_uniones(l_conjuntos);
                printf("\nConjunto de interseccion: ");
                cto_mostrar(ctoInter);
                printf("\nConjunto de union: ");
                cto_mostrar(ctoUnion);
                break;
            }
            case 3: {
                Conjunto A = cto_crear();
                Conjunto B = cto_crear();
                Conjunto C = cto_crear();
                int cantidad;
                printf("Cantidad de elementos del primer conjunto\n");
                pedirCantidad(&cantidad);
                carga_datos(A, cantidad);
                printf("Cantidad de elementos del segundo conjunto\n");
                pedirCantidad(&cantidad);
                carga_datos(B, cantidad);
                printf("Cantidad de elementos del tercer conjunto\n");
                pedirCantidad(&cantidad);
                carga_datos(C, cantidad);

                if (c_ej4_transitividad(A, B, C))
                    printf("Se demuestra transitividad: A está contenido en B y B en C, entonces A en C.\n");
                else
                    printf("No se demuestra transitividad entre los conjuntos.\n");
                break;
            }
            case 4: {
                Conjunto c1 = cto_crear();
                Conjunto c2 = cto_crear();
                int cantidad;
                printf("Ingrese primer conjunto\n");
                pedirCantidad(&cantidad);
                carga_datos(c1, cantidad);
                printf("Ingrese segundo conjunto\n");
                pedirCantidad(&cantidad);
                carga_datos(c2, cantidad);

                printf("\nConjunto con la diferencia simetrica: ");
                cto_mostrar(c_ej5_dif_simetrica(c1, c2));
                break;
            }
            case 5: {
                Conjunto c1 = cto_crear();
                Conjunto c2 = cto_crear();
                int cantidad;
                printf("Ingrese primer conjunto\n");
                pedirCantidad(&cantidad);
                carga_datos_naturales(c1, cantidad);
                printf("Ingrese segundo conjunto\n");
                pedirCantidad(&cantidad);
                carga_datos_naturales(c2, cantidad);

                if (c_ej6_subconjuntopropio(c1, c2))
                    printf("El conjunto A es subconjunto propio de B\n");
                else if (c_ej6_subconjuntopropio(c2, c1))
                    printf("El conjunto B es subconjunto propio de A\n");
                else
                    printf("No hay subconjuntos propios, pueden ser iguales o disjuntos\n");
                break;
            }
            case 6: {
                Conjunto c1 = cto_crear();
                Conjunto c2 = cto_crear();
                Conjunto c3 = cto_crear();
                int cantidad;
                printf("Ingrese primer conjunto\n");
                pedirCantidad(&cantidad);
                carga_datos(c1, cantidad);
                printf("Ingrese segundo conjunto\n");
                pedirCantidad(&cantidad);
                carga_datos(c2, cantidad);
                printf("Ingrese tercer conjunto\n");
                pedirCantidad(&cantidad);
                carga_datos(c3, cantidad);

                c_ej7_subconjtotalparcial(c1, c2, c3);
                break;
            }
            case 7: {
                Conjunto conjunto1 = cto_crear();
                Conjunto conjunto2 = cto_crear();
                int cantidad;
                printf("Cantidad de elementos del primer conjunto\n");
                pedirCantidad(&cantidad);
                if (cantidad != 0) carga_datos_naturales(conjunto1, cantidad);
                printf("Cantidad de elementos del segundo conjunto\n");
                pedirCantidad(&cantidad);
                if (cantidad != 0) carga_datos_naturales(conjunto2, cantidad);

                if (c_ej8_soniguales(conjunto1, conjunto2))
                    printf("Los conjuntos son iguales\n");
                else
                    printf("Los conjuntos NO SON iguales\n");
                break;
            }
            default:
                printf("Opcion invalida\n");
        }

        printf("\nDesea realizar otra operacion? (s/n): ");
        limpiarBuffer();
        scanf(" %c", &c);

    } while (c == 's');
}