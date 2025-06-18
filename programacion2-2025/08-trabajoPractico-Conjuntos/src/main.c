#include "..\..\libs\validaciones\headers\utilidades.h"
#include "..\headers\tp_conjunto.h"

int main() {
    srand(time(NULL));

    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    Conjunto C = cto_crear();
    carga_conjuntos(A, B);
    carga_datos_naturales(C, 3);
    Conjunto cEj2union = c_ej2_union(A, B);
    Conjunto cEj2interseccion = c_ej2_interseccion(A, B);
    Conjunto cEj2Diferencia = c_ej2_diferencia(A, B);

    cto_mostrar(cEj2union);
    cto_mostrar(cEj2interseccion);
    cto_mostrar(cEj2Diferencia);

    /*
        Lista l_de_conjuntos = l_crear();
    l_de_conjuntos = crear_lista_de_conjuntos(5);
    Conjunto cEj3Uniones = c_ej3_uniones(l_de_conjuntos);
    Conjunto cEj3Intercciones = c_ej3_intersecciones(l_de_conjuntos);
    cto_mostrar(cEj3Uniones);
    cto_mostrar(cEj3Intercciones);
    */
    bool es = c_ej4_transitividad(A, B, C);
    printf("%d", es);

    Conjunto cEj5Simetria = c_ej5_dif_simetrica(A, B);
    cto_mostrar(cEj5Simetria);
    return 0;
}