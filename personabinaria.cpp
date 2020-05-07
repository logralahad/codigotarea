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


int main(int argc, char const *argv[]){

    Persona array_de_personas[10];
    char c;

    FILE *miaarchivo;
    miaarchivo = fopen("miarchivo.bin", "rb");

    if(miaarchivo == NULL){
        printf("Error al abrir el archivo.\n");
        for(int i = 0; i < 2; i++){
            printf("\n\n\n");
            array_de_personas[i].id_persona = i+1;

            printf("Introduzca su nombre completo:\n");
            fgets(array_de_personas[i].nombre, 99,stdin);

            printf("Introduzca el sexo de la persona [H/M]:\n");
            array_de_personas[i].sexo = getc(stdin);
            while ((c = getc(stdin)) != '\n' && c != EOF); //Esta linea hace flush a la entrada

            printf("Introduzca la direccion:\n");
            fgets(array_de_personas[i].direccion, 99,stdin);

            printf("Introduzca la religion:\n");
            fgets(array_de_personas[i].religion, 49,stdin);

            printf("Introduzca la escolaridad:\n");
            fgets(array_de_personas[i].escolaridad, 19,stdin);

            printf("Introduzca la edad:\n");
            scanf("%hu", &array_de_personas[i].edad);
            while ((c = getc(stdin)) != '\n' && c != EOF); //Esta linea hace flush a la entrada

            miaarchivo = fopen("miarchivo.bin", "wb");
            if(miaarchivo == NULL){
                printf("Error al abrir archivo.\n");
                return(1);
            }
        }
        fwrite(array_de_personas, sizeof(Persona), 2, miaarchivo);
    }

    else{
        printf("Estas son las personas registradas:\n");
        fread(array_de_personas, sizeof(Persona),2,miaarchivo); //lee cada linea y las almacena en el arr de personas
        for(int i = 0; i < 2; i++){//inicia la secuencia de impresion de cada dato de la persona
            printf("%d\n",array_de_personas[i].id_persona);
            printf("%s\n",array_de_personas[i].nombre);
            printf("%c\n",array_de_personas[i].sexo);
            printf("%s\n",array_de_personas[i].direccion);
            printf("%s\n",array_de_personas[i].religion);
            printf("%s\n",array_de_personas[i].escolaridad);
            printf("%d\n",array_de_personas[i].edad);
        }
        fclose(miaarchivo);
    }
}
