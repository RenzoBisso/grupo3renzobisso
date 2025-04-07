#include "..\headers\utilidades.h"
#include "..\headers\tp_1_recursividad.h"

//PUNTO 1
bool palindromo (char * cadena){
    
    int cantL = strlen(cadena);
    char aux[cantL];
    int i;
    
    if(cantL <= 1){ //Si solo queda un caracter es Verdadero
        return true;
    }
    else if(cadena[0] != cadena[cantL-1]){
        return false;
    }
    else{
        for(i=0; i<cantL-1; i++){
            aux[i] = cadena[i+1]; //Mueve todos los caracteres cadena la izquierda
        }
        aux[i-1] = '\0'; //Pone el fin de linea

        palindromo(aux);
    }
}

//PUNTO 2
int productoAux(int m, int n){
    if(m == 0 || n == 0) return 0;
    else{
        return n + productoAux(m-1 ,n);
    }
}

int producto(int m, int n){
    int signo = (m / abs(m)) * (n / abs(n)); //GUARDAMOS EL SIGNO
    int resultado = productoAux(abs(m), abs(n));
    return resultado * signo; //TRATAMIENTO DE SIGNO +/-
}

//PUNTO 3
int terminoSeridFibonacci(int k){
    if (k <= 1) { return k; }
    else {
    return terminoSeridFibonacci(k-1) + terminoSeridFibonacci(k-2); }
}

//PUNTO 4   
float divisionNoExacta(int m, int n, float resto){
    if(resto >= 5 || m == 0){
        return 0.0;
    }
    return (m * 10 / n) / 10.0 + divisionNoExacta((m * 10) % n, n, resto + 1) / 10.0;
}

float division(int m, int n){
    if(m < n){
        if(m == 0){
            return 0;
        }   
        return divisionNoExacta(m, n, 0);
    }
    return 1 + division(m-n, n);
}

//PUNTO 5
char* separadorMilesAux(char* numero, int longitud) {
    if (longitud <= 3) return numero;

    // Espacio para el nuevo string (incluyendo los puntos)
    char* separado = (char *)malloc(longitud + (longitud - 1) / 3 + 1);

    // Caso base: si la longitud es menor o igual a 3
    if (longitud <= 3) {
        strcpy(separado, numero);
        return separado;
    }

    // Separar la parte inicial (los primeros dÃgitos sin punto)
    int inicio = longitud % 3;
    if (inicio == 0) inicio = 3;

    strncpy(separado, numero, inicio);
    separado[inicio] = '.';

    // Concatenar el resto recursivamente
    strcpy(separado + inicio + 1, separadorMilesAux(numero + inicio, longitud - inicio));

    return separado;
}

char* agregarSeparadorMiles(char numero[]) {
    int longitud = strlen(numero);
    

    if(numero[0]=='-'){
        char sacarMenos[longitud-1]; //A longitud le resto -1 teniendo en cuenta el caracter '-'
        char agregarMenos[longitud];
        for(int i=0;i<longitud;i++){
            sacarMenos[i]=numero[i+1];
        }

        agregarMenos[0]='-';

        return strcat(agregarMenos,separadorMilesAux(sacarMenos, longitud-1));
    }else{
        return separadorMilesAux(numero, longitud);
    }
}

//PUNTO 6 
void desarrollarPatron(char *cadena, int mitad, int nivel) {
    if (nivel == 1) return; // Caso base: nivel 1 es solo (-.-)
    
    int inicio = mitad - 3 * (nivel - 1);
    int fin = mitad + 3 * (nivel - 1);

    cadena[inicio] = '(';
    cadena[fin] = ')';
    cadena[inicio + 2] = '.';
    cadena[fin - 2] = '.';
    cadena[inicio + 1] = '-';
    cadena[fin - 1] = '-';

    desarrollarPatron(cadena, mitad, nivel - 1);
}

char *reunionMafia(int nivel) {
    int longCad = 6 + (nivel - 1) * 6;
    int mitad = (longCad - 1) / 2;

    char *cadena = (char *)malloc(longCad * sizeof(char));
    if (cadena == NULL) {
        printf("Error al asignar memoria\n");
        return NULL;
    }

    memset(cadena, ' ', longCad - 1);
    cadena[longCad - 1] = '\0';

    // Insertar el patrón central (-.-)
    cadena[mitad - 1] = '(';
    cadena[mitad] = '-';
    cadena[mitad + 1] = '.';
    cadena[mitad + 2] = '-';
    cadena[mitad + 3] = ')';

    desarrollarPatron(cadena, mitad, nivel);

    return cadena;
}

//PUNTO 7
void digitalizacion(char * digital, char * seniales, int pos, int posAux){
    if(seniales[pos] == '\0'){
        digital[posAux] = '\0';
        return;
    }
    if(pos > 0 && (seniales[pos] != seniales[pos-1])){
        digital[posAux] = '|';
        posAux++;
    }
    if(seniales[pos] == 'l'){
        digital[posAux] = '_';
    }
    else if(seniales[pos] == 'h'){
        digital[posAux] = 238;
    }
    
    digitalizacion(digital, seniales, pos+1, posAux+1);
}

char * ondaDigital(char * seniales){
    int length = strlen(seniales);

    char * digital = (char*)malloc((2 * length + 1) * sizeof(char));

    char *str = (char*)malloc((2 * length + 1) * sizeof(char));
    strcpy(str, seniales);
    a_minusculas(str);

    digitalizacion(digital, str, 0, 0);

    return digital;
}

//PUNTO 8
void imprimirSubconjunto(int arr[], int n, int count) {
    if (count == 0) {
        printf("{");  // Abre el subconjunto
    }
    if (count == n) {
        printf("}");  // Cierra el subconjunto
        return;
    }
    if (count > 0) {
        printf(", ");  // Separador entre elementos
    }
    printf("%d", arr[count]);
    imprimirSubconjunto(arr, n, count + 1);
}

void encontrarSubconjuntos(int conjunto[], int largo, int index, int subconjunto[], int tamanoSub, int sumaActual, int objetivo) {
    if (sumaActual == objetivo) {
        imprimirSubconjunto(subconjunto, tamanoSub,0);  
        return;
    }
    
    if (index == largo || sumaActual > objetivo) return; 
    subconjunto[tamanoSub] = conjunto[index];
    encontrarSubconjuntos(conjunto, largo, index + 1, subconjunto, tamanoSub + 1, sumaActual + conjunto[index], objetivo);

    
    encontrarSubconjuntos(conjunto, largo, index + 1, subconjunto, tamanoSub, sumaActual, objetivo);
}

void sumaSubConjuntos(){
    int largo, objetivo;
    bool flag=true;
    int bandera;
    while(flag){
        printf("Ingrese la cantidad de elementos del conjunto: ");
        bandera = scanf("%d", &largo);
        if(bandera != 1 || largo < 0){
            printf("Entrada inválida. No se ingresó un número entero.\n");
            while (getchar() != '\n');
        }else{
            flag=false;
        }
    }
    flag=true;
    int conjunto[largo];
    int subconjunto[largo]; 

    cargarArray(conjunto, largo, 0);
    while(flag){
        printf("Ingrese el valor a buscar: ");
        if(scanf("%d", &objetivo)!=1){
            printf("Entrada inválida. No se ingresó un número entero.\n");
            while (getchar() != '\n');
        }else{
            flag=false;
        }
    }

    encontrarSubconjuntos(conjunto, largo, 0, subconjunto, 0, 0, objetivo);

}

//PUNTO 9
bool divisiblePor7(int n) {
    int resultado = n % 10;
    resultado *= 2;
    int menos = n / 10;
    menos -= resultado;
    if (n < 70) {
        if (n % 7 == 0) {
            return true;
        } else {
            return false;
        }
    }
    return divisiblePor7(menos);
}

//PUNTO 10 
int explosionRecursiva(int n, int b,int* arr, int* count){
    if(n>b && b!=0){
        int n1=n/b;
        int n2=n-n1;
        arr[*count]=n1;
        (*count)++;
        //printf("%d,",n1);
        if(n1>b){
            return explosionRecursiva(n1,b,arr,count);
        }
        if(n2>b){
            return explosionRecursiva(n2,b,arr,count);
        }
        if(n1==b || n2==b){
            //printf("%d,",b);

            arr[*count]=b;
            (*count)++;
        }
    }
    //printf("\nya no se puede explotar el número. ");
}

int* explosion(int n, int b){
    int* arr = malloc(n * sizeof(int));
    int count=0;
    explosionRecursiva(n,b,arr,&count);
    imprimirArr(arr,count);
    return arr;
}