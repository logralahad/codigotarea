#include <stdlib.h>
#include <stdio.h>

int main(){

    int suma = 0;
    int sums[13] = {0};

    srand((unsigned) time(0));

    for(int j = 1; j <= 36000; j++){
        suma = 0;
        for(int i = 0; i < 2 ; i++){
            suma += ((rand() % 6) + 1);
        }
        sums[suma]++;
    }

    printf("%7s%13s\n", "Suma", "# Veces");

    for(int i = 2; i <= 12; i++){
        printf("%7u%13d\n", i, sums[i]);
    }

    return 0;
}
