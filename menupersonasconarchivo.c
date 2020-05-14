#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct persona
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

void modificar(char ips, int n){

    switch(ips){

        case 'I':
        printf("Escriba el nuevo ID: ");
        scanf("%d", &array_de_personas[n].id_persona);
        while((d = getc(stdin)) != '\n' && d != EOF);
        break;

        case 'N':
        printf("Escriba el nuevo nombre: ");
        fgets(array_de_personas[n].nombre,99,stdin);
        break;

        case 'S':
        printf("Escriba el nuevo sexo: ");
        scanf("%c", &array_de_personas[n].sexo);
        break;

        case 'D':
        printf("Escriba la nueva direccion: ");
        fgets(array_de_personas[n].direccion,99,stdin);
        break;

        case 'R':
        printf("Escriba la nueva religion: ");
        fgets(array_de_personas[n].religion,49,stdin);
        break;

        case 'G':
        printf("Escriba la nueva escolaridad: ");
        gets(array_de_personas[n].escolaridad);
        break;

        case 'E':
        printf("Escriba la nueva edad: ");
        scanf("%hu", &array_de_personas[n].edad);
        while((d = getc(stdin)) != '\n' && d != EOF);
        break;

        printf("== Ha sido modificado exitosamente ==\n");
    }
}


int main(int argc, char const *argv[]){

    FILE *miaarchivo;
    //miaarchivo = fopen("miarchivo.bin", "wb+");

    printf("\t== BIENVENIDO AL MENU ==\t\n\n");
    printf("     1. Cargar datos de un archivo. \t\n");
    printf("     2. Modificar datos de una persona. \t\n");
    printf("     3. Mostrar lista de personas. \t\n");
    printf("     4. Guardar datos en archivo. \t\n");
    printf("     5. Salir. \t\n");
    //printf("\n\tSeleccione una opcion: ");

    do{
        printf("\n\n\tSeleccione una opcion: ");
        scanf("%d",&opc);
        while ((d = getc(stdin)) != '\n' && d != EOF); //Esta linea hace flush a la entrada
        switch(opc){
            case 1:
                miaarchivo = fopen("miarchivo.bin", "rb");
                if(miaarchivo == NULL){
                    printf("\n\t** Error al abrir archivo, no hay datos. **\n");
                }
                else{
                    fread(array_de_personas, sizeof(Persona),10,miaarchivo);//lee cada linea y las almacena en el arr de personas
                    printf("\n\t** Archivo cargado exitosamente. **\n");
                    fclose(miaarchivo);
                }
                break;

            case 2:
                if(array_de_personas[0].id_persona != 1){
                    do{	printf("\n\t** Error, no existen registros aun. **\n ¿Desea agregar datos? S/N: ");
                    		scanf("%c", &dec);
                  				switch(dec)
                          {
                            case 'S':
                                    printf("¿Cuantas personas desea integrar? [1-10]: ");
                                    scanf("%d", &p);
                                    while ((d = getc(stdin)) != '\n' && d != EOF); //Esta linea hace flush a la entrada
                                    for(int i = 0; i < p; i++)
                                    {
                                            array_de_personas[i].id_persona = i+1;

                                            printf("Introduzca su nombre completo:\n");
                                            fgets(array_de_personas[i].nombre, 99,stdin);

                                            printf("Introduzca el sexo de la persona [H/M]:\n");
                                            array_de_personas[i].sexo = getc(stdin);
                                            while ((d = getc(stdin)) != '\n' && d != EOF); //Esta linea hace flush a la entrada

                                            printf("Introduzca la direccion:\n");
                                            fgets(array_de_personas[i].direccion, 99,stdin);

                                            printf("Introduzca la religion:\n");
                                            fgets(array_de_personas[i].religion, 49,stdin);

                                            printf("Introduzca la escolaridad:\n");
                                            fgets(array_de_personas[i].escolaridad, 19,stdin);

                                            printf("Introduzca la edad:\n");
                                            scanf("%hu", &array_de_personas[i].edad);
                                            while ((d = getc(stdin)) != '\n' && d != EOF); //Esta linea hace flush a la entrada
                                    }
                        	}
                	}while(dec !='N');
                }
                else{
                    printf("Digite el ID de la persona que quiera modificar: ");
                    scanf("%d", &opc);
                    while((d = getc(stdin)) != '\n' && d != EOF);

                    for(int i = 0; i < 2; i++){
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
                            modificar(ans, i);
                        }
                    }
                }
                break;

            case 3:

                if(array_de_personas[0].id_persona != 1){
                    printf("\n\t** Error, no existen registros aun. **\n");
                }
                else{
                    printf("== Estas son las personas registradas ==\n");
                    for(int i = 0; i < 10; i++){//inicia la secuencia de impresion de cada dato de la persona
                        printf("ID: %d\n",array_de_personas[i].id_persona);
                        printf("Nombre: %s\n",array_de_personas[i].nombre);
                        printf("Sexo: %c\n",array_de_personas[i].sexo);
                        printf("Direccion: %s\n",array_de_personas[i].direccion);
                        printf("Religion: %s\n",array_de_personas[i].religion);
                        printf("Escolaridad: %s\n",array_de_personas[i].escolaridad);
                        printf("Edad: %d\n",array_de_personas[i].edad);
                    }
                }

                //fclose(miaarchivo);
                break;

            case 4:
                miaarchivo = fopen("miarchivo.bin", "wb");
                fwrite(array_de_personas, sizeof(Persona), 10, miaarchivo);
                printf("\n\t** Archivo guardado exitosamente. **\n");
                //fclose(miaarchivo);miaarchivo = fopen("miarchivo.bin", "rb");
                break;
        }
    }while(opc != 5);
    printf("\n\t** Gracias por usar nuestro programa. **\n");
    printf("\n\t**           Vuelva pronto            **\n");

    return 0;
}
