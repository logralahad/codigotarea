#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
    FILE *aarchivo;
    char linea[10], nueva[10];

    aarchivo = fopen("ids.txt", "r");
    if(aarchivo == NULL){
        printf("Error al abrir el archivo.\n");
        return(1);
    }

    printf("Estas son las direcciones de correo de los alumnos de la clase:\n");

    while(fgets(linea,10,aarchivo) != NULL){ //Lee las lineas hasta que no haya nada
        fscanf(aarchivo, "%s", linea); //Obtiene la linea del archivo
        printf("0%s@ulsaoaxaca.edu.mx\n", linea); //Le agrega un 0 y la direccion de correo
    }

    fclose(aarchivo);
}
