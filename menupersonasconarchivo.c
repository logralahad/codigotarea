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

void impresion(){
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

void registro(int n){
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

int main(int argc, char const *argv[]){

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

        switch(opc){
            case 1:
                miaarchivo = fopen("miarchivo.bin", "rb");
                if(miaarchivo == NULL){
                    printf("\n** Error al abrir archivo, no hay datos. **\n");
                }
                else{
                    fread(array_de_personas, sizeof(Persona),10,miaarchivo);//lee cada linea y las almacena en el arr de personas
                    printf("\n** Archivo cargado exitosamente. **\n");
                    fclose(miaarchivo);
                }
                break;

            case 2:
                if(array_de_personas[0].id_persona != 1){
                    printf("\n ** Error, no existen registros aun. **\n\n%5s¿Desea agregar datos? S/N: ");
                    scanf("%c", &dec);
                  	if(dec == 'S'){
                        printf("\n  Numero de registros a integrar: ");
                        scanf("%d", &p);
                        while ((d = getc(stdin)) != '\n' && d != EOF); //Esta linea hace flush a la entrada

                        for(int i = 0; i < p; i++){
                            registro(i);
                        }
                    }
                }

                else{
                    printf("Digite el ID de la persona que quiera modificar: ");
                    scanf("%d", &opc);
                    while((d = getc(stdin)) != '\n' && d != EOF);
                    if(array_de_personas[opc-1].id_persona == 0){
                        printf("Lo sentimos. No existe registro.\n");
                        printf("¿Quiere registrar uno nuevo? S/N: \n");
                        scanf("%c", &dec);
                        if(dec == 'S'){
                            printf("\n  Numero de registros a integrar: ");
                            scanf("%d", &p);
                            while ((d = getc(stdin)) != '\n' && d != EOF); //Esta linea hace flush a la entrada

                            for(int i = 0; i < p; i++){
                                registro(i);
                            }
                        }
                    }

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
                            modificar(ans, i);
                        }
                    }
                }
                break;

            case 3:
                if(array_de_personas[0].id_persona == 0){
                    printf("\n** Error, no existen registros aun. **\n");
                }
                else{
                    impresion();
                }
                break;

            case 4:
                miaarchivo = fopen("miarchivo.bin", "wb+");
                fwrite(array_de_personas, sizeof(Persona), 10, miaarchivo);
                printf("\n** Archivo guardado exitosamente. **\n");

                break;
        }
    } while(opc != 5);

    printf("\n** Gracias por usar nuestro programa  **\n");
    printf("\n**           Vuelva pronto            **\n");

    return 0;
}
