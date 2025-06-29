#include "..\..\libs\validaciones\headers\utilidades.h"
#include "..\headers\interfaz.h"

void menu(){
    limpiar_pantalla();
    bool bandera, valido;
    int opcion = 0;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t\t\t    +------------------------+\n");
        printf("\t\t\t\t\t    |      Menu Principal    |\n");
        printf("\t\t\t\t\t    +------------------------+\n\n\n");
        printf("\t\t\t\t\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t\t\t\t\t||OPCION 1 - Probar ejercicio 4     ||\n");
        printf("\t\t\t\t\t||----------------------------------||\n");
        printf("\t\t\t\t\t||OPCION 2 - Probar ejercicio 5     ||\n");
        printf("\t\t\t\t\t||----------------------------------||\n");
        printf("\t\t\t\t\t||OPCION 3 - Probar ejercicio 6     ||\n");
        printf("\t\t\t\t\t||----------------------------------||\n");      
        printf("\t\t\t\t\t||OPCION 0 - Salir del menu         ||\n");
        printf("\t\t\t\t\t||----------------------------------||\n");
        printf("\t\t\t\t\t||Ingrese una opcion entre 0 y 4    ||\n");
        printf("\t\t\t\t\t||<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<||\n");
        do //VALIDO OPCION DEL MENU////////////////////////////////////////////////////////////
        {
            valido = true;
            bandera = scanf("%d", &opcion);
            if ( bandera != 1 ||opcion < 0 || opcion > 3 )
            {
                printf("Valor invalido, reintente el ingreso...(Opciones validas entre 0 y 4)\n");
                valido = false;
            }
            fflush(stdin);
        } while (!valido);
        //OPCION SELECCIONADA/////////////////////////////////////////////////////////////////
        limpiar_pantalla();

    switch (opcion)
    {
      case 1:
        interfaz2();
        pausa();
        break;
      case 2:
        interfaz3();
        pausa();
        break;
      case 3:
        interfaz4();
        pausa();
        break;
      default:
        break;
    }
  } while (opcion != 0);

    pausa();
}