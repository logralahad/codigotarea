#include <stdio.h>

struct estructura_persona {
	char nombre[30];
	char direccion[100];
	char religion[50];
	char sexo[10];
	unsigned long int edad;
	unsigned long int id;
	char escolaridad[20];
};

struct estructura_persona persona;
int main()
{
	printf("Escribe el nombre de la persona: ");
	scanf_s("%s", &persona.nombre,30);

	printf("Escribe la direccion de la persona: ");
	scanf_s("%s", &persona.direccion,100);

	printf("Escribe la religion de la persona: ");
	scanf_s("%s", &persona.religion,50);

	printf("Escribe el sexo de la persona: ");
	scanf_s("%s", &persona.sexo,10);

	printf("Escribe la edad de la persona: ");
	scanf_s("%d", &persona.edad,1);

	printf("Escribe el id: ");
	scanf_s("%d", &persona.id,1);

	printf("Escribe la escolaridad de la persona: ");
	scanf_s("%s", &persona.escolaridad, 20);

	printf("La persona %s, con direccion en %s.\nDe religion es %s.\nSexo: %s.\nSu edad es %d.\nCon id es %d.\nY hasta escolaridad %s.\n", persona.nombre, persona.direccion, persona.religion, persona.sexo, persona.edad, persona.id, persona.escolaridad);
}