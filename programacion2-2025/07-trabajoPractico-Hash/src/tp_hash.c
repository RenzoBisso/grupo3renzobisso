#include "..\headers\tp_thash.h"
#include "..\..\libs\validaciones\headers\utilidades.h"

//Ejercicio 4

void th_ej4_abm(){
    int indice=0;

    TablaHash th=th_crear(CAPACIDAD, &hashingMod);    
    agregar_archivos_al_hash("alumnos.dat","rb", th, &indice);
    mostrarMenu(th, &indice);

    free(th);
}

int hashingMod(int clave){
    return clave%PRIMO;
}

void mostrarMenu(TablaHash th, int *indice){
    int respuesta;
    int legajoAlta;
    int legajoBaja;
    int legajoMod;
    int respuestaMod;
    int opcionMod;
    bool estaActivo;
    TipoElemento te;

    ralumnos *alumnos=(ralumnos*)malloc(sizeof(ralumnos));
    do{
        printf("\t\t/////////////////////////////////////////////////////////\n");
        printf("\t\t///                       Menu                        ///\n");
        printf("\t\t/// 1 Dar altas de alumnos (con legajo)               ///\n");
        printf("\t\t/// 2 Dar baja de alumnos (con legajo)                ///\n");
        printf("\t\t/// 3 Modificar datos alumno (con legajo)             ///\n");
        printf("\t\t/// 4 Mostrar archivo alumnos                         ///\n");
        printf("\t\t/// 5 Mostrar Tabla Hash de alumnos                   ///\n");
        printf("\t\t/// 0 Salir                                           ///\n");
        printf("\t\t/////////////////////////////////////////////////////////\n");

        printf("\t\tIngrese una opcion [0-4]: ");
        pedirDatos(&respuesta, 11);
        
        /////////    ALTAS    /////////
        if(respuesta==1){
            printf("\033[2J\033[H"); // se limpia la pantalla, un reemplazo de cls para que ande en la terminal de visual
            // system("cls");
            printf("\t\t/////////////////////////////////////////////////////////\n");
            printf("\t\t/// Has ingresado a la seccion de altas de alumnos. \n");
            printf("\t\t/// Por favor, ingrese el legajo del alumno a \n\t\t/// dar de alta: ");
            pedirDatos(&legajoAlta, 11);
            while(((legajoAlta)<=0) || (legajoAlta>999999)){
                printf("\t\t/// Legajo invalido.\n");
                printf("\t\t/// Ingrese nuevamente: ");
                pedirDatos(&legajoAlta,11);
            }
            te=th_recuperar(th, legajoAlta);
            if(te){
                alumnos=(ralumnos*)te->valor;
                if((*alumnos).estado==2){
                    printf("\t\t/// Realizando alta del alumno con legajo %d...\n", legajoBaja);
                    alta("alumnos.dat","r+b", th, legajoAlta, (*alumnos).indice);
                    printf("\t\t/// alta del alumno %d realizada correctamente. \n", legajoBaja);
                }else if((*alumnos).estado==1){
                    printf("\t\t/// El alumno con legajo %d ya esta activo.\n", legajoAlta);
                    printf("\t\t/////////////////////////////////////////////////////////\n");
                }
            }else{
                printf("\t\t/// Realizando alta del alumno con legajo %d...\n",legajoAlta);
                crear_alta("alumnos.dat","ab", th, legajoAlta, indice);
                printf("\t\t/// Alta del alumno %d realizada correctamente.\n",legajoAlta);
                printf("\t\t/////////////////////////////////////////////////////////\n");
                (*indice)+=1;
            }
            printf("\t\tPresione enter para volver al menu.");
            fflush(stdin);
            getchar();
            printf("\033[2J\033[H");
            // system("cls");
        }
        /////////////////////////////

        /////////    BAJAS    /////////
        else if(respuesta==2){
            printf("\033[2J\033[H"); // se limpia la pantalla, un reemplazo de cls para que ande en la terminal de visual
            // system("cls");
            printf("\t\t/////////////////////////////////////////////////////////\n");
            printf("\t\t/// Has ingresado a la seccion de bajas de alumnos. \n");
            printf("\t\t/// Por favor, ingrese el legajo del alumno a \n\t\t/// dar de baja: ");
            pedirDatos(&legajoBaja,11);
            te=th_recuperar(th, legajoBaja);
            if(te){
                alumnos=(ralumnos*)(te->valor);
                if((*alumnos).estado==2){
                    printf("\t\t/// El alumno con legajo %d ya se encuentra dado de baja.\n", legajoBaja);
                    printf("\t\t/////////////////////////////////////////////////////////\n");
                }else if((*alumnos).estado==1){
                    printf("\t\t/// Realizando baja del alumno con legajo %d...\n",legajoBaja);
                    baja("alumnos.dat","r+b",th, legajoBaja,(*alumnos).indice);
                    printf("\t\t/// Baja del alumno %d realizada correctamente.\n",legajoBaja);
                    printf("\t\t/////////////////////////////////////////////////////////\n");
                }
            }else{
                printf("\t\t/// El alumno con legajo %d no existe en \n\t\t/// el archivo para poder darlo de baja.\n", legajoBaja);
                printf("\t\t/////////////////////////////////////////////////////////\n");
            }
            printf("\t\tPresione enter para volver al menu.");
            fflush(stdin);
            getchar();
            printf("\033[2J\033[H"); // se limpia la pantalla, un reemplazo de cls para que ande en la terminal de visual
            // system("cls");
        }
        /////////////////////////////////////

        /////////    MODIFICACIONES    /////////
        else if(respuesta==3){
            printf("\033[2J\033[H"); // se limpia la pantalla, un reemplazo de cls para que ande en la terminal de visual
            // system("cls");
            printf("\t\t/////////////////////////////////////////////////////////\n");
            printf("\t\t/// Has ingresado a la seccion de modificaciones\n\t\t/// de alumnos. \n");
            printf("\t\t/// Por favor, ingrese el legajo del alumno a \n\t\t/// modificar: ");
            pedirDatos(&legajoMod,11);
            te=th_recuperar(th, legajoMod);
            if(te){
                alumnos=(ralumnos*)(te->valor);
                if((*alumnos).estado==2){
                    printf("\t\t/// El alumno con legajo %d se encuentra dado de baja\n\t\t/// por lo tanto no se puede modificar.\n", legajoMod);
                    printf("\t\t/////////////////////////////////////////////////////////\n");
                }else if((*alumnos).estado==1){
                    do{
                        printf("\t\t/// Datos actuales del alumnno con legajo %d:\n", legajoMod);
                        mostrarDatosAlumno("alumnos.dat","rb",(*alumnos).indice);
                        printf("\t\t///\n");
                        printf("\t\t/// Que modificacion desea relizar?\n");
                        printf("\t\t/// 1. Apellido.\n");
                        printf("\t\t/// 2. Nombre.\n");
                        printf("\t\t/// 3. Domicilio.\n");
                        printf("\t\t/// 4. Telefono.\n");
                        printf("\t\t/// 0. Salir.\n");
                        printf("\t\t/////////////////////////////////////////////////////////\n");
                        printf("\t\tIngrese una opcion [0-4]: ");
                        pedirDatos(&respuestaMod, 11);
                        if((respuestaMod<0) || (respuestaMod>4)){
                            printf("\t\tDato invalido, revisa las opciones.\n");
                            printf("\t\tPresione enter para volver al menu de modificaciones.");
                            fflush(stdin);
                            getchar();
                            printf("\033[2J\033[H"); // se limpia la pantalla, un reemplazo de cls para que ande en la terminal de visual
                        }else{
                            modificacion("alumnos.dat","r+b",th, legajoMod, (*alumnos).indice, respuestaMod);
                        }
                    }while(respuestaMod!=0);
                }
            }else{
                printf("\t\t/// El alumno con legajo %d no existe en \n\t\t/// el archivo para poder modificar datos.\n", legajoMod);
                printf("\t\t/////////////////////////////////////////////////////////\n");
            }
            printf("\t\tPresione enter para volver al menu.");
            fflush(stdin);
            getchar();
            printf("\033[2J\033[H"); // se limpia la pantalla, un reemplazo de cls para que ande en la terminal de visual
            // system("cls");
        }
        /////////////////////////////////////

        /////////    MOSTRAR ARCHIVO BIN    /////////
        else if(respuesta==4){
            printf("\033[2J\033[H"); // se limpia la pantalla, un reemplazo de cls para que ande en la terminal de visual
            // system("cls");
            printf("\t\t/////////////////////////////////////////////////////////\n");
            printf("\t\t/// Mostrando archivo alumnos...\n");
            mostrarBinario("alumnos.dat","rb"); 
            printf("\t\t/// Archivo alumnos mostrado correctamente.\n");
            printf("\t\t/////////////////////////////////////////////////////////\n");
            printf("\t\tPresione enter para volver al menu.");
            fflush(stdin);
            getchar();
            printf("\033[2J\033[H"); // se limpia la pantalla, un reemplazo de cls para que ande en la terminal de visual
            // system("cls");
        }
        //////////////////////////////////////////

        /////////    MOSTRAR HASH    /////////
        else if(respuesta==5){
            printf("\033[2J\033[H"); // se limpia la pantalla, un reemplazo de cls para que ande en la terminal de visual
            // system("cls");
            printf("///////////////////////////////////////////////////\n");
            printf("Mostrando Tabla Hash...\n");
            // th_mostrar(th);
            th_mostrar_solo_ocupados(th);
            printf(" Tabla Hash mostrada correctamente.\n");
            printf("///////////////////////////////////////////////////\n");
            printf("Presione enter para volver al menu.");
            fflush(stdin);
            getchar();
            printf("\033[2J\033[H"); // se limpia la pantalla, un reemplazo de cls para que ande en la terminal de visual
            // system("cls");
        }
        ////////////////////////////////////////

        /////////    DATO INCORRECTO    /////////
        else{
            if(respuesta!=0){
                printf("\t\tDato incorrecto, intente nuevamente.\n");
                printf("\t\tPresione enter para volver al menu.");
                fflush(stdin);
                getchar();
                printf("\033[2J\033[H"); // se limpia la pantalla, un reemplazo de cls para que ande en la terminal de visual
                // system("cls");
            }
        }
        /////////////////////////////
    } while (respuesta!=0);
    printf("\t\tSaliendo del programa...\n");
}

void crearArchivoBinario(char nombre[], char modo[]){
    FILE*fp=fopen(nombre, modo);
    fclose(fp);
}

void crear_alta(char nombre[], char modo[], TablaHash th, int legajo, int * indice){
    FILE*fp=fopen(nombre,modo);
    ralumnos alumno;
    char apellido2Aux[MAXIMAEJ4]={};
    char nombreAux[MAXIMAEJ4]={};
    char domicilioAux[MAXIMAEJ4]={};
    int telefono;
    //Doy el alta con el indice de la posicion en el archivo
    printf("\t\t/// Ingrese Apellido del alumno: ");
    pedirChar(apellido2Aux);

    printf("\t\t/// Ingrese Nombre del alumno: ");
    pedirChar(nombreAux);
    printf("\t\t/// Ingrese domicilio del alumno: ");
    pedirChar(domicilioAux);

    printf("\t\t/// Ingrese telefono del alumno: ");
    pedirDatos(&telefono,11);
    while(((telefono)<=0) || (telefono>=99999999)){
        printf("\t\t/// Numero invalido o demasiado grande.\n");
        printf("\t\t/// Ingrese nuevamente: ");
        pedirDatos(&telefono,11);
    }

    //Pongo todos los datos escritos en el registro para hacer el write
    alumno.legajo=legajo;
    strcpy(alumno.apellido,apellido2Aux);
    strcpy(alumno.nombre,nombreAux);
    strcpy(alumno.domicilio,domicilioAux);
    alumno.TE=telefono;
    alumno.estado=1; //1 activo, 2 borrado
    alumno.indice=(*indice);

    //Pongo los datos del registro en el hash
    ralumnos *indiceAlumno=(ralumnos*)malloc(sizeof(ralumnos));
    (*indiceAlumno)=alumno;
    TipoElemento te=te_crear_con_valor(alumno.legajo, indiceAlumno);
    th_insertar(th, te);

    //Escribo en el archivo y cierro el archivo
    fwrite(&alumno, sizeof(ralumnos),1,fp);
    fclose(fp);
}

/*
Funcion alta, se encarga de dar altas a legajos YA EXISTENTES en el archivo,
recupero el valor del hash (el cual tiene la estructura alumnos) para poder
actualizar los datos del hash, y actualizar tambien el archivo binario, logrando
asi el impacto tanto en el hash como en el archivo binario.
*/
void alta(char nombre[], char modo[], TablaHash th, int legajo, int indice){
    FILE*fp=fopen(nombre,modo);
    ralumnos alumno;
    TipoElemento te=th_recuperar(th, legajo);
    ralumnos *alumnoTh=(ralumnos*)te->valor;
    fseek(fp, sizeof(ralumnos)*indice,SEEK_SET);
    fread(&alumno,sizeof(ralumnos),1,fp);
    alumno.estado=1; //alta logica
    (*alumnoTh).estado=1;
    fseek(fp,-(long int)sizeof(ralumnos),SEEK_CUR);
    fwrite(&alumno, sizeof(ralumnos),1,fp);
    fclose(fp);
}

/*
Funcion baja, esta funcion da baja tanto en el hash como en el archivo,
cambiando el estado a 2 (baja logica) en el hash y en el archivo binario.
*/
void baja(char nombre[], char modo[],TablaHash th, int legajo, int indice){
    FILE*fp=fopen(nombre,modo);
    ralumnos alumno;
    TipoElemento te=th_recuperar(th, legajo);
    ralumnos *alumnoTh=(ralumnos*)te->valor;
    fseek(fp, sizeof(ralumnos)*indice,SEEK_SET);
    fread(&alumno,sizeof(ralumnos),1,fp);
    alumno.estado=2; //baja logica
    (*alumnoTh).estado=2;
    fseek(fp,-(long int)sizeof(ralumnos),SEEK_CUR);
    fwrite(&alumno, sizeof(ralumnos),1,fp);
    fclose(fp);
}

void modificacion(char nombre[], char modo[], TablaHash th, int legajo, int indice, int respuesta){
    FILE*fp=fopen(nombre,modo);
    ralumnos alumno;
    TipoElemento te=th_recuperar(th, legajo);
    ralumnos *alumnoTh=(ralumnos*)te->valor;
    char apellido2Aux[MAXIMAEJ4]={};
    char nombreAux[MAXIMAEJ4]={};
    char domicilioAux[MAXIMAEJ4]={};
    int telefono;

    fseek(fp, sizeof(ralumnos)*indice,SEEK_SET);
    fread(&alumno,sizeof(ralumnos),1,fp);

    if(respuesta==1){
        printf("\t\t/// Ingrese el nuevo apellido: ");
        pedirChar(apellido2Aux);
        strcpy(alumno.apellido,apellido2Aux);
    }else if(respuesta==2){
        printf("\t\t/// Ingrese el nuevo nombre: ");
        pedirChar(nombreAux);
        strcpy(alumno.nombre,nombreAux);
    }else if(respuesta==3){
        printf("\t\t/// Ingrese el nuevo domicilio: ");
        pedirChar(domicilioAux);
        strcpy(alumno.domicilio,domicilioAux);
    }else if(respuesta==4){
        printf("\t\t/// Ingrese el nuevo telefono: ");
        pedirDatos(&telefono,11);
        alumno.TE=telefono;
    }
    (*alumnoTh)=alumno;
    fseek(fp,-(long int)sizeof(ralumnos),SEEK_CUR);
    fwrite(&alumno, sizeof(ralumnos),1,fp);
    fclose(fp);
}


void mostrarBinario(char nombre[], char modo[]){
    FILE*fp=fopen(nombre,modo);
    ralumnos alumno;
    while(fread(&alumno, sizeof(ralumnos),1,fp)){
        if(alumno.estado==1){
            printf("\t\t/// Legajo del alumno: %d, Indice en el archivo: %d.\n",alumno.legajo, alumno.indice);
            printf("\t\t/// Apellido: %s.\n", alumno.apellido);
            printf("\t\t/// Nombre: %s.\n",alumno.nombre);
            printf("\t\t/// Domicilio: %s.\n",alumno.domicilio);
            printf("\t\t/// Telefono: %d.\n", alumno.TE);
        }
        printf("\t\t/// \n");
    }
    fclose(fp);
}

void mostrarDatosAlumno(char nombre[], char modo[], int indice){
    FILE*fp=fopen(nombre,modo);
    ralumnos alumno;
    fseek(fp, sizeof(ralumnos)*indice,SEEK_SET);
    fread(&alumno, sizeof(ralumnos),1,fp);
    printf("\t\t/// Apellido: %s.\n", alumno.apellido);
    printf("\t\t/// Nombre: %s.\n",alumno.nombre);
    printf("\t\t/// Domicilio: %s.\n",alumno.domicilio);
    printf("\t\t/// Telefono: %d.\n", alumno.TE);
    fclose(fp);
}

/*
Funcion para agregar los archivos ya existentes del archivo binario al hash, de manera
que si ya hay datos en el archivo, se copien al hash para poder seguir operando normalmente 
en caso que se habra varias veces el archivo.
*/
void agregar_archivos_al_hash(char nombre[], char modo[], TablaHash th, int *indiceMain){
    FILE*fp=fopen(nombre,modo);
    TipoElemento te;
    ralumnos alumno;
    ralumnos *alumnoTh;
    int cantidadLecturas=0;
    while(fread(&alumno, sizeof(ralumnos),1,fp)){
        alumnoTh=(ralumnos*)malloc(sizeof(ralumnos));
        (*alumnoTh)=alumno;
        te=te_crear_con_valor(alumno.legajo, alumnoTh);
        th_insertar(th, te);
        cantidadLecturas+=1;
    }
    if(cantidadLecturas>=1){
        *indiceMain=cantidadLecturas+1; //Esto permite recuperar el indice si hubo lecutras
    }
    fclose(fp);
}

//Ejercicio 5

void th_ej5_comparacion(int q_claves, int q_repeticiones, int rango_desde, int rango_hasta){
    int i;
    clock_t start_avl, end_avl, start_hash, end_hash;
    double tiempo_avl = 0.0, tiempo_hash = 0.0;
    
    ArbolAVL arbol = avl_crear();
    TablaHash tabla = th_crear(TAMANIO_MAXIMO_TH, &hashingMod);
    cargarAleatorioARBOLTH(arbol, tabla, rango_desde, rango_hasta, q_claves);
    int numeroBuscar;
    
    srand(time(NULL));
    
    for (int j = 0; j < q_repeticiones; j++){
        start_hash = clock();
        numeroBuscar = (rand() % rango_hasta) + 1;
        th_recuperar(tabla,numeroBuscar);
        end_hash = clock();
        tiempo_hash += (double)(end_hash - start_hash) / CLOCKS_PER_SEC;
    }
    
    for (int j = 0; j < q_repeticiones; j++){
        start_avl = clock();
        numeroBuscar = (rand() % rango_hasta) + 1;
        avl_buscar(arbol,numeroBuscar);
        end_avl = clock();
        tiempo_avl += (double)(end_avl - start_avl) / CLOCKS_PER_SEC;
    }
    free(arbol);
    free(tabla);
    printf("Tiempo de respuesta del arbol (En segundos): %.32f \n", tiempo_avl);
    printf("Tiempo de respuesta del hash (En segundos): %.32f \n", tiempo_hash);    
}

void cargarAleatorioARBOLTH(ArbolAVL arbol, TablaHash tabla, int rango_desde,int rango_hasta, int cantidad){
  srand(time(NULL));
  int i = 0;
  TipoElemento valor;
  int numeroRandom;
  while (i < cantidad){
    numeroRandom = (rand() % rango_hasta) + 1;
    if (!avl_buscar(arbol, numeroRandom) && numeroRandom>rango_desde) {
      valor = te_crear(numeroRandom);
      avl_insertar(arbol, valor);
      th_insertar(tabla, valor);
      i++;
    }
  }
}

// EJERCICIO 6
int th_ej6_covid(){
    TablaHash th = th_crear(TAMANIO_MAXIMO_TH, &hashingMod);
    int menu = -1;
    while (menu != 0){
        int opcionMenu;
        do {
            printf("- - - - CONSULTA DE VACUNACION - - - -\n");
            printf(" 0. Salir del programa \n");
            printf(" 1. Registrar Vacunados \n");
            printf(" 2. Ver Vacunados por fecha \n");
            printf(" Ingrese la opcion deseada: ");
            fflush(stdin);
            pedirDatos(&opcionMenu, 11);
            if (opcionMenu < 0 || opcionMenu > 2){
                printf("Valor fuera del rango de opciones, pulse una tecla\n");
                system("pause");
                system("cls");

            }
        } while (opcionMenu < 0 || opcionMenu > 2);

        if (opcionMenu == 1){
            int cantidadDeVacunados;
            printf("Ingrese la cantidad de vacunados a registrar: ");
            pedirDatos(&cantidadDeVacunados, 11);
            cargarEnTablahash(cantidadDeVacunados,th);
        } else if (opcionMenu == 2){
            printf("- - - Fecha a consultar vacunados - - - \n");
            int fecha = pedirFecha();
            muestraVacunados(th, fecha);
        } else {
            printf("Gracias por utilizar el programa!\n");
            menu = 0;
        }  
    system("pause");
    system("cls");
    }
    return 0;
}

void cargarEnTablahash(int cantidad_paciente, TablaHash th) {
    int i;
    int anterior = 0;
    int fecha = 0;
    Lista lista_personas;
    TipoElemento valor;
    for (i = 0; i < cantidad_paciente; i++) {
        personas *persona = malloc(sizeof(personas)); // Crear nueva instancia de personas
        fflush(stdin);
        printf(" - - - - Persona %d - - - -\n", i + 1);
        fecha = pedirFecha();
        fflush(stdin);
        pedirPersona(persona);
        lista_personas = retornar_lista_fecha(th,fecha);
        l_agregar(lista_personas, te_crear_con_valor(fecha, persona));
        valor = te_crear_con_valor(fecha, lista_personas);
        th_insertar(th, valor); 
        printf("\n");
    }
}

Lista retornar_lista_fecha(TablaHash th,int fecha){
        if (th_recuperar(th,fecha)){
            Lista lista_fecha = (Lista) th_recuperar(th,fecha)->valor;
        }else{
            Lista lista_fecha_nueva = l_crear();
            return lista_fecha_nueva;
        }
}

void pedirPersona(personas * p){
    int dni;
    do {
        printf("Ingrese DNI (Maximo 9 digitos): ");
        pedirDatos(&dni, 11);
        if (dni < 1 || dni > 999999999)
            printf("Valor fuera de rango.\n");
    } while (dni < 1 || dni > 999999999);
    p -> dni = dni;
    fflush(stdin);
    printf("Ingrese Nombre (Se permiten hasta 2 espacios): ");
    leer_palabra(p -> nombre);
    printf("Ingrese Apellido (Se permiten hasta 2 espacios): ");
    leer_palabra(p -> apellido);
}

int pedirFecha(){
    int fechaTotal = 0;
    int dia, mes, anio;
    bool fechaValida;
    do {
        fechaValida = true;
        do {
        printf("Ingrese Dia de Vacunacion (2 digitos): ");
        pedirDatos(&dia, 11);
        if (dia < 1 || dia > 31)
            printf("Entrada Invalida.\n");
        } while (dia < 1 || dia > 31);

        do {
            printf("Ingrese Mes de Vacunacion (2 digitos): ");
            pedirDatos(&mes, 11);
            if (mes < 1 || mes > 12)
                printf("Entrada Invalida.\n");
        } while (mes < 1 || mes > 12);

        do {
            printf("Ingrese Anio de Vacunacion (4 digitos, desde 2020 hasta 2023): ");
            pedirDatos(&anio, 11);
            if (anio < 2020 || anio > 2023)
                printf("Entrada Invalida.\n");
        } while (anio < 2020 || anio > 2023);

        //Se valida anio bisiesto (Sucede en 2020)
        if ((((mes == 2 && (dia > 29 || (dia > 28 && !((anio % 4 == 0) && (anio % 100 != 0 || anio % 400 == 0))))) ||
        ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)))){
            printf("Fecha Invalida.\n");
            fechaValida = false;
        }

        //Se valida fecha maxima.
        if (anio == 2023){
            if (mes >= 6 && dia > 12){ //Se permite fecha hasta el dia de entrega del TP.
                printf("Fecha Invalida.\n");
                fechaValida = false;
            }
        }

    } while (!fechaValida);
    
    fechaTotal = (dia * 1000000) + (mes * 10000) + anio;
    return fechaTotal;
}

void muestraVacunados(TablaHash th,int fecha){
    if (th_recuperar(th, fecha)){
        Lista Muestro = (Lista)th_recuperar(th, fecha)->valor;
        Iterador ite = iterador(Muestro);
        TipoElemento X;
        while (hay_siguiente(ite)) {
            X = siguiente(ite);
            personas per = *(personas *)X->valor;
            printf("- - - - - - - - - - \n");
            printf("\nDNI: %d\n", per.dni);
            printf("Apellido: %s\n", per.apellido);
            printf("Nombre: %s\n", per.nombre);
            printf("- - - - - - - - - - \n");
        }
    } else {
        printf("No hay personas vacunadas en esa fecha.\n");
    }
}

