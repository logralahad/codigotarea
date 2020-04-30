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

/* Remueve los espacios al inicio */
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

/* Remueve los espacios al final */
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

/* Remueve los espacios al final e inicio */
char *trim(char *const s)
{
        rtrim(s);  // remueve los espacios del final
        ltrim(s); // remueve los espacios del inicio
        return s; // regresa la cadena ya sin espacios o saltos
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

    while(fgets(linea,10,aarchivo) != NULL){ // Lee las lineas hasta que no haya nada
        trim(linea);// Obtiene la linea del archivo, le quita los saltos y espacios tanto al inicio como al final
        printf("0%s@ulsaoaxaca.edu.mx\n", linea); // Le agrega un 0 y la parte de ulsaoaxaca y lo imprime
    }

    fclose(aarchivo);
}
