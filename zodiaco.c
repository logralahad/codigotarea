#include <stdio.h>
#include <stdlib.h>

int main(){

    int dia, mes;
    char opc;

        scanf("%d %d", &dia, &mes);
        switch(mes){
            case 1:
                if(dia >= 20){
                    printf("Acuario \nInvierno\n");
                }
                else{
                    printf("Capricornio \nInvierno\n");
                }
                break;

            case 2:
                if(dia <= 18){
                    printf("Acuario \nInvierno\n");
                }
                else{
                    printf("Piscis \nInvierno\n");
                }
                break;

            case 3:
                if(dia <= 20){
                    printf("Piscis \nInvierno\n");
                }
                else{
                    printf("Aries \nPrimavera\n");
                }
                break;

            case 4:
                if(dia <= 19){
                    printf("Aries \nPrimavera\n");
                }
                else{
                    printf("Tauro \nPrimavera\n");
                }
                break;

            case 5:
                if(dia <= 20){
                    printf("Tauro \nPrimavera\n");
                }
                else{
                    printf("Geminis \nPrimavera\n");
                }
                break;

            case 6:
                if(dia <= 20){
                    printf("Geminis \nPrimavera\n");
                }
                else{
                    printf("Cancer \nVerano\n");
                }
                break;

            case 7:
                if(dia <= 22){
                    printf("Cancer \nVerano\n");
                }
                else{
                    printf("Leo \nVerano\n");
                }
                break;

            case 8:
                if(dia <= 22){
                    printf("Leo \nVerano\n");
                }
                else{
                    printf("Virgo \nVerano\n");
                }
                break;

            case 9:
                if(dia <= 20){
                    printf("Virgo \nVerano");
                }
                else if(dia >= 21 && dia <= 22){
                    printf("Virgo \nOtono\n");
                }
                else{
                    printf("Libra \nOtono\n");
                }
                break;

            case 10:
                if(dia <= 22){
                    printf("Libra \nOtono\n");
                }
                else{
                    printf("Escorpion \nOtono\n");
                }
                break;

            case 11:
                if(dia <= 21){
                    printf("Escorpion \nOtono\n");
                }
                else{
                    printf("Sagitario \nOtono\n");
                }
                break;

            case 12:
                if(dia <= 20){
                    printf("Sagitario \nOtono\n");
                }
                else if(dia >= 21 && dia < 22){
                    printf("Sagitario \nInvierno\n");
                }
                else{
                    printf("Capricornio \nInvierno\n");
                }
                break;
        }
return 0;
}
