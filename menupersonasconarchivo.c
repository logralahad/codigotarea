#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct persona //Se define el tipo de estructura de datos que se van a manejar en el codigo
{
	unsigned long int id_persona;
	char nombre[100];
	char sexo;
	char direccion[100], religion[50], escolaridad[20];
	unsigned short int edad;
} Persona;

Persona array_de_personas[10];
int opc, p;
char d, ans, dec;

void modificar(char ips, int n) //esta funcion es para el caso 2 del menu principal donde se puede modificar algun dato de un registro
{

    switch(ips){

        case 'I':  // Aqui modifica el Id de un registro
        printf("Escriba el nuevo ID: ");
        scanf("%d", &array_de_personas[n].id_persona);
        while((d = getc(stdin)) != '\n' && d != EOF);
        break;

        case 'N': //Modifica el nombre de un registro
	printf("Escriba el nuevo nombre: ");
        fgets(array_de_personas[n].nombre,99,stdin);
        break;

        case 'S': //Modifica el sexo de un registro
        printf("Escriba el nuevo sexo: ");
        scanf("%c", &array_de_personas[n].sexo);
        break;

        case 'D': //Modifica la direccion de un registro
        printf("Escriba la nueva direccion: ");
        fgets(array_de_personas[n].direccion,99,stdin);
        break;

        case 'R': //Modifica la religion de un registro
        printf("Escriba la nueva religion: ");
        fgets(array_de_personas[n].religion,49,stdin);
        break;

        case 'G': //Modifica la escolaridad de un registro
        printf("Escriba la nueva escolaridad: ");
        gets(array_de_personas[n].escolaridad);
        break;

        case 'E': //Modifica la edad de un registro
        printf("Escriba la nueva edad: ");
        scanf("%hu", &array_de_personas[n].edad);
        while((d = getc(stdin)) != '\n' && d != EOF);
        break;

        printf("== Ha sido modificado exitosamente ==\n");
    }
}

void impresion()   //La funcion del caso 3 del menu principal
{
    printf("== Estas son las personas registradas ==\n");
        for(int i = 0; i < 10; i++){//inicia la secuencia de impresion de cada dato de la persona
            if(array_de_personas[i].id_persona == 0) continue;
            printf("ID: %d\n",array_de_personas[i].id_persona);
            printf("Nombre: %s",array_de_personas[i].nombre);
            printf("Sexo: %c\n",array_de_personas[i].sexo);
            printf("Direccion: %s",array_de_personas[i].direccion);
            printf("Religion: %s",array_de_personas[i].religion);
            printf("Escolaridad: %s",array_de_personas[i].escolaridad);
            printf("Edad: %d\n",array_de_personas[i].edad);
            printf(" ------------------------------------- \n");
        }
}

void registro(int n) // Esta funcion es del caso 2 del menu principal cuando no se tienen registros para modificar y se tienen que agregar nuevos
{
    array_de_personas[n].id_persona = n+1;
    printf("\n\tRegistro #%d\n", n+1);
    printf(" * Introduzca su nombre completo: ");
    fgets(array_de_personas[n].nombre, 99,stdin);

    printf("\n* Introduzca el sexo de la persona [H/M]: ");
    array_de_personas[n].sexo = getc(stdin);
    while ((d = getc(stdin)) != '\n' && d != EOF); //Esta linea hace flush a la entrada

    printf("\n* Introduzca la direccion: ");
    fgets(array_de_personas[n].direccion, 99,stdin);

    printf("\n* Introduzca la religion: ");
    fgets(array_de_personas[n].religion, 49,stdin);

    printf("\n* Introduzca la escolaridad: ");
    fgets(array_de_personas[n].escolaridad, 19,stdin);

    printf("\n* Introduzca la edad: ");
    scanf("%hu", &array_de_personas[n].edad);
    while ((d = getc(stdin)) != '\n' && d != EOF); //Esta linea hace flush a la entrada

    printf("\n** Persona registrada exitosamente **\n");
    printf("\n ------------------------------------- \n\n");

}

int main(int argc, char const *argv[])   // Inicia el menu principal
{

    FILE *miaarchivo;
    //miaarchivo = fopen("miarchivo.bin", "wb+");

    //printf("\n\tSeleccione una opcion: ");

    do{
        printf("\n\t== BIENVENIDO AL MENU ==\t\n\n");
        printf("     1. Cargar datos de un archivo. \t\n");
        printf("     2. Modificar datos de una persona. \t\n");
        printf("     3. Mostrar lista de personas. \t\n");
        printf("     4. Guardar datos en archivo. \t\n");
        printf("     5. Salir. \t\n");
        printf("\n\tSeleccione una opcion: ");
        scanf("%d",&opc);
        while ((d = getc(stdin)) != '\n' && d != EOF); //Esta linea hace flush a la entrada

        switch(opc){  //Este es el switch en el cual va a llamar a cada caso que asi lo mande el usuario
            case 1:  //Caso 1 solo carga el archivo con el comando fopen y la direccion del archivo
                miaarchivo = fopen("miarchivo.bin", "rb");
                if(miaarchivo == NULL){  //Si no existe el archivo nos va a imprimir lo que esta en la siguiente linea
                    printf("\n** Error al abrir archivo, no hay datos. **\n");
                }
                else{
                    fread(array_de_personas, sizeof(Persona),10,miaarchivo);//lee cada linea y las almacena en el arr de personas
                    printf("\n** Archivo cargado exitosamente. **\n");
                    fclose(miaarchivo);
                }
                break;

            case 2:  //Caso 2 modifica y agrega personas
                if(array_de_personas[0].id_persona != 1){ //Si no hay ningun registro va a mandar error y le preguntara al usuario si quiere agregar alguno
                    printf("\n ** Error, no existen registros aun. **\n\n%5s¿Desea agregar datos? S/N: ");
                    scanf("%c", &dec); 
                  	if(dec == 'S'){  //Si el usuario responde que si desea agregar, le preguntara que  cuantos registros desea agregar
                        printf("\n  Numero de registros a integrar: ");
                        scanf("%d", &p);
                        while ((d = getc(stdin)) != '\n' && d != EOF); //Esta linea hace flush a la entrada

                        for(int i = 0; i < p; i++){
                            registro(i);  // Llama a la fncion registro para ejecutarla
                        }
                    }
                }

                else{ //En caso de que si haya archivo va a pedir al usuario que digite el Id del registro que desea modificar
                    printf("Digite el ID de la persona que quiera modificar: ");
                    scanf("%d", &opc);
                    while((d = getc(stdin)) != '\n' && d != EOF);
                    if(array_de_personas[opc-1].id_persona == 0){  // Si digita un Id que no esta registrado le mandara un eerror y le preguntara di quiere registrarlo como nuevo
                        printf("Lo sentimos. No existe registro.\n");
                        printf("¿Quiere registrar uno nuevo? S/N: \n");
                        scanf("%c", &dec);
                        if(dec == 'S'){ //Si responde si le preguntara el numero de registros que quiere
                            printf("\n  Numero de registros a integrar: ");
                            scanf("%d", &p);
                            while ((d = getc(stdin)) != '\n' && d != EOF); //Esta linea hace flush a la entrada

                            for(int i = 0; i < p; i++){
                                registro(i); //Lama a la funcion registro para registrar nuevos datos
                            }
                        }
                    }
			//En caso dde que si digite un Id valido le preguntara que quiere modificar de ese registro
                    for(int i = 0; i < 10; i++){
                        if(array_de_personas[i].id_persona == opc){
                            printf("\n== Seleccione el dato a modificar ==\n\n");
                            printf("       I = ID de la persona\n");
                            printf("       N = Nombre\n");
                            printf("       S = Sexo\n");
                            printf("       D = Direccion\n");
                            printf("       R = Religion\n");
                            printf("       G = Escolaridad\n");
                            printf("       E = Edad\n\n");
                            printf("\tElija el dato: \n");
                            scanf("%c", &ans);
                            while((d = getc(stdin)) != '\n' && d != EOF);
                            modificar(ans, i); //Lama a la funcion modificar 
                        }
                    }
                }
                break;

            case 3: //Caso 3 Mostrara todos los registros que contiene el archivo
                if(array_de_personas[0].id_persona == 0){ //Si no contiene algun registro el archivo le mandara elerror de la linea de abajo
                    printf("\n** Error, no existen registros aun. **\n");
                }
                else{ //En caso de que si contenga datos el archivo
                    impresion(); //Llama a la funcion impresion
                }
                break;

            case 4: //Caso 4 Guarda los archivo o las modificaciones que se hicieron en la consola durante el tiempo de ejecucion 
                miaarchivo = fopen("miarchivo.bin", "wb+");
                fwrite(array_de_personas, sizeof(Persona), 10, miaarchivo);
                printf("\n** Archivo guardado exitosamente. **\n");

                break;
        }
    } while(opc != 5); //Si el usuario digita 5, lo sacara del programa

    printf("\n** Gracias por usar nuestro programa  **\n");
    printf("\n**           Vuelva pronto            **\n");

    return 0;
}
