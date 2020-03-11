#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mayusc(char arr[], int n){
    for(int j = 0; j <= n; j++){
        if (arr[j] >= 'A' && arr[j] <= 'Z'){
            arr[j] += 32;
        }
    }
    return arr;
}


int main(){
    char arr[1000], *new_arr;
    int opc, cont;
    int largo_cadena;

    scanf("%d\n", &opc);

    for (int i = 0; i < opc; i++) {

        cont = 0;
        //scanf("%c", &arr);
        gets(arr);
        //strupr(arr);

        if(strlen(arr) == 1){
            printf("Si\n");
        }
        else{
            largo_cadena = strlen(arr) - 1;
            new_arr = mayusc(arr, largo_cadena);

            for(int j = 0; j <= (largo_cadena / 2); j++){
                if (new_arr[j] != new_arr[largo_cadena - j]){
                    cont++;
                }
            }
            if(cont > 0) {
                printf("No\n");
            }
            else {
                printf("Si\n");
            }
        }

    }

return 0;
}

/*
#include <iostream>
#include <string.h>
#include<stdio.h>



int main()
{
    char cadena[1000];
    int palindromo, p = 0;
    printf("Escribe la palabra:\n");
    scanf_s("%s", cadena, 1000);
    fflush(stdout);
    palindromo = strlen(cadena) - 1;

    //for (int cad_izquierda = 0, cad_derecha = palindromo - 1; cad_izquierda = (palindromo / 2); cad_izquierda++, cad_derecha--) {
    for (int i = 0; i <= (palindromo / 2); i++) {
        if (cadena[i] != cadena[palindromo - i])   p++;
    }

    if(p > 0){
        printf("No");
    }

    else{
        printf("Si");
    }

    return 0;
}*/
