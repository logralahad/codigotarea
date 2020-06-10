#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>



char tablero[3][3] = {{'*','*','*'},{'*','*','*'},{'*','*','*'}};
char piezaalazar[2];
char* jugadoralazar[2];
int coords[3][3] = {0};

char pieza(){
    char randomletter = 'A' + (rand() % 26);
    return randomletter;
}

char* jugador(){
    char* jugadoralazar[3] = {"Daniel","Jairo","Uziel"};
    return jugadoralazar[rand()% 3];
}



void impresion(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

void nuevo_tiro(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if( coords[i][j] != 0 ){
                coords[i][j] += 1;
            }
            else if( tablero[i][j] != '*' ){
                coords[i][j] += 1;
                printf("\nEl tiro se realizó en la casilla: [%d] [%d]\n", i+1, j+1);
            }
        }
    }
}

int wincondition(){
    int winner = 0;

    if(tablero[0][0] == piezaalazar[0] && tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2]
    || tablero[1][0] == piezaalazar[0] && tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2]
	|| tablero[2][0] == piezaalazar[0] && tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2]

	|| tablero[0][0] == piezaalazar[0] && tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0]
	|| tablero[0][1] == piezaalazar[0] && tablero[0][1] == tablero[1][1] && tablero[0][1] == tablero[2][1]
	|| tablero[0][2] == piezaalazar[0] && tablero[0][2] == tablero[1][2] && tablero[0][2] == tablero[2][2]

	|| tablero[0][0] == piezaalazar[0] && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]
	|| tablero[0][2] == piezaalazar[0] && tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])

	{
	    return winner = 1;
    }

    else if(tablero[0][0] == piezaalazar[1] && tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2]
    || tablero[1][0] == piezaalazar[1] && tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2]
    || tablero[2][0] == piezaalazar[1] && tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2]

    || tablero[0][0] == piezaalazar[1] && tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0]
    || tablero[0][1] == piezaalazar[1] && tablero[0][1] == tablero[1][1] && tablero[0][1] == tablero[2][1]
    || tablero[0][2] == piezaalazar[1] && tablero[0][2] == tablero[1][2] && tablero[0][2] == tablero[2][2]

    || tablero[0][0] == piezaalazar[1] && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]
    || tablero[0][2] == piezaalazar[1] && tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])

    {
        return winner = 2;
    }
}

int main()

{
    int turnos = 0, opc;
    char d;
    char buffer1[50], buffer2[50];
    srand(time(0));
    FILE *miaarchivo;
    //miaarchivo = fopen("miarchivo.bin", "wb+");

    printf("\n\t== BIENVENIDO A TIC TAC TOE ==\t\n\n");
    printf("     Se asignara una ficha a cada jugador\n");
    printf("\tUn momento por favor...Listo!\t\n");

    for(int i = 1; i <= 2; i++){
        piezaalazar[i-1] = pieza();
        jugadoralazar[i-1] = jugador();
        if(jugadoralazar[1] == jugadoralazar[0]){
            jugadoralazar[1] = jugador();
        }
        printf("\n\tEl jugador %d es: %s", i,  jugadoralazar[i-1]);
        printf("\n\tLa ficha del jugador %d es: %c\n", i,  piezaalazar[i-1]);
    }

    printf("\n\tSe creo el tablero, a ganar!\t\n");
    miaarchivo = fopen("tablero.txt", "w");
    fwrite(tablero, 1, 9, miaarchivo);
    fclose(miaarchivo);

    printf("\n   Para iniciar el juego, presione 0 y Enter: ");
    scanf("%d", &opc);
    while ((d = getc(stdin)) != '\n' && d != EOF); //Esta linea hace flush a la entrada*/

    if(opc == 0){
        do{
            if(turnos % 2 == 0 || turnos == 0){
                printf("\nEl jugador 1 realizo el tiro, se muestra el tablero a continuacion:\n\n");
                sprintf(buffer1, "jugada_gato1.exe tablero.txt %c %c", piezaalazar[0], piezaalazar[1]);
                system(buffer1);
                //printf("%s", buffer1);
            }
            else{
                printf("\nEl jugador 2 realizo el tiro, se muestra el tablero a continuacion:\n\n");
                sprintf(buffer2, "jugada_gato2.exe tablero.txt %c %c", piezaalazar[1], piezaalazar[0]);
                system(buffer2);
                //printf("%s", buffer2);
            }

            miaarchivo = fopen("tablero.txt", "r+");
            fread(tablero, 1, 9,miaarchivo);
            fwrite(tablero, 1, 9, miaarchivo);
            fclose(miaarchivo);

            impresion();
            nuevo_tiro();

            if(wincondition() == 1) {printf("\n%s gano! Felicidades campeon\n", jugadoralazar[0]); return 0;}
            else if(wincondition() == 2) {printf("\%s gano! Felicidades campeon\n", jugadoralazar[1]); return 0;}

            turnos++;

        }while(turnos != 9);
    }

    printf("Nadie gana, suerte a la proxima.");

    return 0;
}
