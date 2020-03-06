#include <stdlib.h>
#include <string.h>
#define SIZE 100


void voltea_cadena(char arr[], int k){
    for(int i = k - 1; i >= 0; i--){
        printf("%c", arr[i]);
    }
}

int main(){

    char cadena[SIZE];

    printf("Escriba la cadena a revertir: \n");
    gets(cadena);

    int j = strlen(cadena);
    voltea_cadena(cadena, j);

return 0;
}
