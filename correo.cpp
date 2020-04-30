// CÓDIGO CON SCANF

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

// CÓDIGO CON TRIM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *ltrim(char *const s)
{
        size_t len;
        char *cur;

        if(s && *s) {
                len = strlen(s);
                cur = s;

                while(*cur && isspace(*cur))
                        ++cur, --len;

                if(s != cur)
                        memmove(s, cur, len + 1);

        }

        return s;
}

/* Remove trailing whitespaces */
char *rtrim(char *const s)
{
        size_t len;
        char *cur;

        if(s && *s) {
                len = strlen(s);
                cur = s + len - 1;

                while(cur != s && isspace(*cur))
                        --cur, --len;

                cur[isspace(*cur) ? 0 : 1] = '\0';
        }

        return s;
}

/* Remove leading and trailing whitespaces */
char *trim(char *const s)
{
        rtrim(s);  // order matters
        ltrim(s);

        return s;
}

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
        trim(linea);//Obtiene la linea del archivo
        printf("0%s@ulsaoaxaca.edu.mx\n", linea); //Le agrega un 0 y la direccion de correo
    }

    fclose(aarchivo);
}
