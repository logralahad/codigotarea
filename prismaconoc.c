#include <stdio.h>
#include <math.h>

float volumen_cono(float radio_base_cono, float altura_cono){
    float vol_cono;
    vol_cono = (altura_cono * M_PI * pow(radio_base_cono, 2)) / 3;
    return vol_cono;
}

float volumen_prisma(float area_base_prisma, float altura_prisma){
    float vol_prisma;
    vol_prisma = area_base_prisma * altura_prisma;
    return vol_prisma;
}

int main(){

    float radio, area_base, altura;
    char opc;

    printf("Seleccione de que figura desea conocer: prisma o cono. P = Prisma / C = Cono: ");
    scanf("%c", &opc);

    if(opc == 'P'){
        printf("Digite el area de la base en m^3: ");
        scanf("%f", &area_base);
        printf("Digite la altura en m^3: ");
        scanf("%f", &altura);

        printf("El volumen del prisma es %.4lf m^3", volumen_prisma(area_base,altura));
    }
    else{
        printf("Digite el radio en m^3: ");
        scanf("%f", &radio);
        printf("Digite la altura en m^3: ");
        scanf("%f",&altura);

        printf("El volumen del cono es %.4lf m^3", volumen_cono(radio,altura));
    }

return 0;
}
