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

char pieza(){//funcion para encontrar la pieza
    char randomletter = 'A' + (rand() % 26);
    return randomletter;
}

char* jugador(){//funcion para encontrar al jugador
    char* jugadoralazar[3] = {"Daniel","Jairo","Uziel"};
    return jugadoralazar[rand()% 3];
}



void impresion(){//funcion para imprimir
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

void nuevo_tiro(){//funcion para ver en donde se realizo el tiro
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if( coords[i][j] != 0 ){//si la ficha no ha sido ocupada
                coords[i][j] += 1;//le suma 1
            else if( tablero[i][j] != '*' ){//si la ficha ha sido ocupada
                coords[i][j] += 1;//le suma 1 para ejemplificar que numero de movimiento es
                printf("\nEl tiro se realizó en la casilla: [%d] [%d]\n", i+1, j+1);
            }
        }
    }
}

int wincondition(){
    int winner = 0;

    if(tablero[0][0] == piezaalazar[0] && tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2]//condiciones de gane horizontales
    || tablero[1][0] == piezaalazar[0] && tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2]//condiciones de gane horizontales
	|| tablero[2][0] == piezaalazar[0] && tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2]//condiciones de gane horizontales

	|| tablero[0][0] == piezaalazar[0] && tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0]//condiciones de gane verticales
	|| tablero[0][1] == piezaalazar[0] && tablero[0][1] == tablero[1][1] && tablero[0][1] == tablero[2][1]//condiciones de gane verticales
	|| tablero[0][2] == piezaalazar[0] && tablero[0][2] == tablero[1][2] && tablero[0][2] == tablero[2][2]//condiciones de gane verticales

	|| tablero[0][0] == piezaalazar[0] && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]//condiciones de gane diagonales
	|| tablero[0][2] == piezaalazar[0] && tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])//condiciones de gane diagonales

	{
	    return winner = 1;
    }

    else if(tablero[0][0] == piezaalazar[1] && tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2]//condiciones de gane horizontales
    || tablero[1][0] == piezaalazar[1] && tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2]//condiciones de gane horizontales
    || tablero[2][0] == piezaalazar[1] && tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2]//condiciones de gane horizontales

    || tablero[0][0] == piezaalazar[1] && tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0]//condiciones de gane verticales
    || tablero[0][1] == piezaalazar[1] && tablero[0][1] == tablero[1][1] && tablero[0][1] == tablero[2][1]//condiciones de gane verticales
    || tablero[0][2] == piezaalazar[1] && tablero[0][2] == tablero[1][2] && tablero[0][2] == tablero[2][2]//condiciones de gane verticales

    || tablero[0][0] == piezaalazar[1] && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]//condiciones de gane diagonales
    || tablero[0][2] == piezaalazar[1] && tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])//condiciones de gane diagonales

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
        piezaalazar[i-1] = pieza();//llama a funcion pieza
        jugadoralazar[i-1] = jugador();//llama a funcion jugador
        if(jugadoralazar[1] == jugadoralazar[0]){
            jugadoralazar[1] = jugador();
        }
        printf("\n\tEl jugador %d es: %s", i,  jugadoralazar[i-1]);//imprime y asigna quien es jugador 1 y jugador 2
        printf("\n\tLa ficha del jugador %d es: %c\n", i,  piezaalazar[i-1]);//imprime y asigna que ficha le toca a cada quien
    }

    printf("\n\tSe creo el tablero, a ganar!\t\n");
    miaarchivo = fopen("tablero.txt", "w");//se crea el archivo de inicio
    fwrite(tablero, 1, 9, miaarchivo);//crea el archivo del tablero
    fclose(miaarchivo);

    printf("\n   Para iniciar el juego, presione 0 y Enter: ");
    scanf("%d", &opc);
    while ((d = getc(stdin)) != '\n' && d != EOF); //Esta linea hace flush a la entrada*/

    if(opc == 0){
        do{
            if(turnos % 2 == 0 || turnos == 0){//si el turno es el primero o impar significa que es el jugador 1
                printf("\nEl jugador 1 realizo el tiro, se muestra el tablero a continuacion:\n\n");
                sprintf(buffer1, "jugada_gato1.exe tablero.txt %c %c", piezaalazar[0], piezaalazar[1]);//construye el comando para que se ejecute el programa del jugador1
                system(buffer1);
                //printf("%s", buffer1);
            }
            else{//si el turno es el segundo o par significa que es el jugador 2
                printf("\nEl jugador 2 realizo el tiro, se muestra el tablero a continuacion:\n\n");
                sprintf(buffer2, "jugada_gato2.exe tablero.txt %c %c", piezaalazar[1], piezaalazar[0]);//construye el comando para que se ejecute el programa del jugador2
                system(buffer2);
                //printf("%s", buffer2);
            }

            miaarchivo = fopen("tablero.txt", "r+");//abre el archivo para lectura y escritura
            fread(tablero, 1, 9,miaarchivo);//carga lo que tenga al tablero
            fwrite(tablero, 1, 9, miaarchivo);//escribe el nuevo tablero
            fclose(miaarchivo);//cierra el archivo

            impresion();//imprime el tablero para ver el tablero
            nuevo_tiro();//funcion que nos dice en donde se acaba de tirar

            if(wincondition() == 1) {printf("\n%s gano! Felicidades campeon\n", jugadoralazar[0]); return 0;}//si las condiciones de gane regresan 1, pues gano el jugador1
            else if(wincondition() == 2) {printf("\%s gano! Felicidades campeon\n", jugadoralazar[1]); return 0;}//si las condiciones de gane regresan 2, pues gano el jugador2

            turnos++;//suma 1 a los turnos

        }while(turnos != 9);//se juega hasta que lleguen a 9 turnos si no hay ganador aún
    }

    printf("Nadie gana, suerte a la proxima.");

    return 0;
}
