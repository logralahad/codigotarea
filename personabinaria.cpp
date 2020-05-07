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

    FILE *miaarchivo;
    Persona arr[10];

    miaarchivo = fopen("miarchivo.bin", "rb");

    if(miaarchivo == NULL){
        printf("Error al abrir el archivo.\n");
        return(1);
    }

    printf("Estas son las personas registradas:\n");
    fread(arr, sizeof(Persona),10,miaarchivo); //lee cada linea y las almacena en el arr de personas
    for(int i = 0; i < 10; i++){//inicia la secuencia de impresion de cada dato de la persona
        printf("%d\n",arr[i].id_persona);
        printf("%s\n",arr[i].nombre);
        printf("%c\n",arr[i].sexo);
        printf("%s\n",arr[i].direccion);
        printf("%s\n",arr[i].religion);
        printf("%s\n",arr[i].escolaridad);
        printf("%d\n",arr[i].edad);
    }
    fclose(miaarchivo);
}
