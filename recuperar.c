#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(){

    char carpetas[SIZE][SIZE], d;
    int num, sum, cont = 0, piv = 1;

    printf("No. de carpetas: ");
    scanf("%d", &num);
    while((d = getc(stdin)) != '\n' && d != EOF);

    for(int i = 0; i < num; i++){
        printf("Nombre de la carpeta %d: ", i + 1);
        gets(carpetas[i]);
    }


    printf("Numero a sumar: ");
    scanf("%d", &sum);
    while((d = getc(stdin)) != '\n' && d != EOF);

   for(int i = 0; i < num; i++){
        cont = 0;
        piv = 1;
        int largo = strlen(carpetas[i]) - 1;
        for(int j = largo; j >= 0 ; j--){
            if(carpetas[i][j] >= '0' && carpetas[i][j] <= '9'){
                cont += (carpetas[i][j] - '0') * piv;
            }
            piv *= 10;
        }
        cont += sum;
        for(int j = 0; j <= largo; j++){
            if(carpetas[i][j] >= '0' && carpetas[i][j] <= '9') continue;
            printf("%c", carpetas[i][j]);
        }
        printf("%d \n", cont);
    }

return 0;
}
