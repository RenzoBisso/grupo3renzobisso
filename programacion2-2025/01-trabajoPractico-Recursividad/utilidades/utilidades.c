#include "..\headers\utilidades.h"

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