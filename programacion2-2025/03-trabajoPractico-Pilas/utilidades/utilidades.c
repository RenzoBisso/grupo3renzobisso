#define _CRT_SECURE_NO_WARNINGS
#include "..\headers\utilidades.h"
#include "..\headers\tp_3_pilas.h"

//###################
//###################
//FUNCIONES GENERALES
void limpiar_pantalla()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void limpiarBuffer(){    
    char c;
    while(( c = getchar()) != '\n' && c != EOF);
}

void pausa()
{
    printf("Presione cualquier tecla para continuar...\n");
    // fflush(stdin);
    // limpiarBuffer();
    getchar();
    limpiarBuffer();
    // fflush(stdin);
    limpiar_pantalla();
}

int es_decimal(double num){ // Funcion para saber si un numero tiene parte decimal
  double parte_entera;
  double parte_decimal = modf(num, &parte_entera);
  
  return parte_decimal != 0.0; // Retorna 1 si tiene parte decimal, 0 si es entero
}

int esEntero(double num){
    return floor(num) == num;
}

void a_minusculas(char *str){
  while (*str) {
      *str = tolower(*str);
      str++;
  }
}

void imprimirArr(int* arr, int length) {
  for (int i = 0; i < length; i++) {
      printf("%d ", arr[i]);
  }
  //printf("\n");
}

void cargarArray(int arr[], int n,int count){
  if(count==n){
      return;
  }
  int valor;
  bool flag=true;
  while (flag)
  {
  printf("Ingrese el numero a agregar: ");

      if(scanf("%d", &valor)!=1){
          printf("Entrada inválida. No se ingresó un número entero.\n");
          while (getchar() != '\n');
      }else{
          arr[count]=valor;
          flag=false;
      }
  }
  return cargarArray(arr,n,count+1);
  

}

void pedirNumero(int* valor) {

    bool flag = true;
    
    while (flag)
    {
      printf("\t||Ingrese un numero: ");

      if(scanf("%d", valor) != 1) {
        printf("\t||Entrada invalida.\n");
        while (getchar() != '\n');
      }
      else {
        flag = false;
      }
    }
}

char salir(){
  char c;
  char min;
  do {
    printf("\n\nDESEA SALIR? Y/N: ");
    c = getchar();
    min = tolower(c);
    
    limpiarBuffer(); // Limpia lo que quedó después del getchar

    if (min != 'n' && min != 'y') {
      printf("\nError, ingrese un dato valido.");
    }

  } while (min != 'n' && min != 'y');

  return min;
}

int cargaManualAuto(){//0 manual, 1 azar
  bool bandera = true;
  int opcion;
  pedirNumero(&opcion);
  do{
    if (opcion != 1 && opcion != 0) {
      printf("\t||Error, ingrese una opcion valida.\n");
      pedirNumero(&opcion);
    }
    else{
      bandera = false;
    }
    
  }while(bandera);
  printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
  return opcion;
}
//FUNCIONES GENERALES
//###################
//###################





//###################
//###################
//FUNCIONES DE LISTAS
void interfazCargaLista(Lista  l1) {
  //limpiar_pantalla();
  printf("\t||CARGA MANUAL...                                                                                     ||\n");
  printf("\t||----------------------------------------------------------------------------------------------------||\n");
  int tamanio;
  bool flag = true;
  while (flag)
  {
      limpiarBuffer();

      printf("\t||Ingrese el tamanio de la lista: ");

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
  cargarLista(l1, tamanio, 0);

  //limpiar_pantalla();
  printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
}

void mostrar_coeficientes(Lista l){ // 10 9 0 5 6 --- 5 --- 10^5 9^4 0^3 5^2 6
  int i = l_longitud(l) -1;
  Iterador iter = iterador(l);
  TipoElemento X;
  while(hay_siguiente(iter)){
    X = siguiente(iter);
    if(X->clave != 0){
      if(i == 1){
        printf("%dx + ", X->clave);
      }
      else if(i == 0){
        printf("%d\n", X->clave);
      }
      else{
        printf("%dx^%d + ", X->clave, i);
      }
      i--;
    }
    else{
      i--;
    }
  }

}

void l_mostrar_con_valor(Lista l) {//PARA EL EJERCICIO 5 DE LISTAS, NO INCLUIR EN OTROS EJERCICIOS
    //SI SE DESEA UTILIZAR PARA OTROS FINES, ELIMINAR LAS LINEAS MARCADAS Y MODIFICAR EL CAST
  printf("Contenido de la lista: ");
  Iterador iter = iterador(l);
  TipoElemento X = te_crear_con_valor(0, NULL);
  printf("{");//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
  while(hay_siguiente(iter)){
    X = siguiente(iter);
  if(hay_siguiente(iter)){//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    printf("%f; ", *(double*)X->valor);//XXXXXXXXXXXXXXXXXXXXXXXXXXX ELIMINAR ";" Y CAST XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
  }
  else{//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    printf("%f", *(double*)X->valor);//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
  }//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

  }
    printf("}\n");//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

}

void llenarLRandom(Lista l1){
  while(!l_es_llena(l1)){
    l_agregar(l1, te_crear(rand() % 11));
  }
}

void cargarLista(Lista l, int n, int count) {
  if (count == n) {
      return;
  }
  int valor;
  bool flag = true;
  while (flag)
  {
      printf("\t||Ingrese el numero a agregar en la posicion %d: ",count);

      if (scanf("%d", &valor) != 1) {
          printf("\t||Entrada inválida. No se ingresó un número entero.\n");
          while (getchar() != '\n');
      }
      else {
          TipoElemento elemento = te_crear(valor);
          l_agregar(l, elemento);
          flag = false;
      }
  }
  return cargarLista(l, n, count + 1);
}
//FUNCIONES DE LISTAS
//###################
//###################





//##################
//##################
//FUNCIONES DE PILAS

void p_cargar(Pila p,int n, int count){
  if (count == n) {
      return;
    }
  int valor;
  bool flag = true;
  while (flag)
  {
      printf("\t||Ingrese el numero a agregar en la posicion %d: ",count);

      if (scanf("%d", &valor) != 1) {
          printf("\t||Entrada inválida. No se ingresó un número entero.\n");
          while (getchar() != '\n');
      }
      else {
          TipoElemento elemento = te_crear(valor);
          p_apilar(p, elemento);
          flag = false;
      }
  }
  return p_cargar(p, n, count + 1);
}

void llenarPRandom(Pila p1){
  while(!p_es_llena(p1)){
    p_apilar(p1, te_crear(rand() % 11));
  }
}

Pila duplicar(Pila p){
  Pila aux = p_crear();
  Pila doble = p_crear();

  TipoElemento X;

  while(!p_es_vacia(p)){
    X = p_desapilar(p);
    p_apilar(aux, X);
  }

  while(!p_es_vacia(aux)){
    X = p_desapilar(aux);
    p_apilar(p, X);
    p_apilar(doble, X);
  }

  return doble;
}

void p_mostrar_con_valor(Pila p){
  Pila aux = p_crear();
  aux = duplicar(p);

  TipoElemento X;

  printf("\t||Contenido de la pila: ");

  while(!p_es_vacia(aux)){
    X = p_desapilar(aux);
    printf("\t|| ");
  }
}

//FUNCIONES DE PILAS
//##################
//##################