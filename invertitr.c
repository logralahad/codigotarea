#include <stdio.h>
#include <string.h>


char* voltea_cadena(char arr[]) {
  
  int largo_cadena = strlen(arr) - 1;
  char temp;

  for (int i = 0; i <= (largo_cadena / 2); i++) {
    temp = arr[i];
    arr[i] = arr[largo_cadena - i];
    arr[largo_cadena - i] = temp;
  }

  return arr;
}


int main()
{

  //Inicialización de la cadena 
  char str[100] = "Extrano a mi ex  = xe im a onartxE", * new_str;
  //printf("Ingrese un texto: %s\n", str);

  // Voltear la cadena 
  new_str = voltea_cadena(str);
  //new_str = _strrev(str);

  // Imprimir el resultado 
  printf("La cadena volteada: %s\n", new_str);

  return 0;
}
