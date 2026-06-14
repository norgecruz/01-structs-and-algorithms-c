/*main.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
	#define CLEAR "cls"
#else 
	#define CLEAR "clear"
#endif

#define MAX 40


struct date{
	int day;
	int month;
	int year;
};

struct traveler{
	int id;
	char name[20];
	char lastname[50];
	struct date flight_date;
	char destiny[30];
};

struct collection{
	struct traveler arr[MAX];
	int tope;
};


struct collection insert(struct collection c, struct traveler new, int pos);
struct collection simpleInsertion(struct collection c, struct traveler newTraveler);
void show(struct collection c);
void back();

int main()
{

struct collection c;
struct traveler newTraveler;
c.tope= -1;
int pos;

char options = '0';
do{
system(CLEAR);
printf("\n===================================\n");
printf("Agencia de viajes");
printf("\n===================================\n");

printf("Viajeros\n");
printf("1 Mostrar\n");
printf("2 Insercion indicando posicion\n");
printf("3 Insercion simple\n");
printf("x Salir\n");
printf("\nSelecione una opcion\n");
scanf(" %c", &options);

switch(options){
case '1' :
system(CLEAR);
printf("\n===================\n");
printf("Viajeros");
printf("\n===================\n");
if(c.tope > -1){
show(c);
}else{
printf("\nNo hay viajeros\n");
}

back();
//getchar();
//getchar();

break;
case '2' :
system(CLEAR);
printf("\nComplete los siguientes datos");
printf("\nID: ");
scanf(" %d", &newTraveler.id);
printf("\nNombre: ");
scanf(" %s", newTraveler.name);
printf("\nApellido: ");
scanf(" %s", newTraveler.lastname);
printf("\nFecha de Vuelo ");
printf("\nDia: ");
scanf(" %d", &newTraveler.flight_date.day);
printf("\nMes: ");
scanf(" %d", &newTraveler.flight_date.month);
printf("\nAnnio: ");
scanf(" %d", &newTraveler.flight_date.year);
printf("\nDestino: ");
scanf(" %s", newTraveler.destiny);

/*printf("\nIndica en que posicion quieres insertar al viajero: ");
scanf(" %d", &pos);
*/

if(c.tope == -1){
	pos = 0;
}else{
	printf("Indica una posicion entre 0 y %d: ", c.tope+1);
	scanf(" %d", &pos);
}

if(pos<0 || pos>c.tope+1){
	printf("Posicion invalida\n");
}else{
c = insert(c, newTraveler, pos);
printf("\nEl usuario ha sido insertado\n");
}
back();
break;

case '3' :
system(CLEAR);
printf("Complete los siguientes datos\n");
printf("\nID: ");
scanf("%d", &newTraveler.id);
printf("\nNombre: ");
scanf("%s", newTraveler.name);
printf("\nApellido: ");
scanf(" %s", newTraveler.lastname);
printf("\nFecha de Vuelo ");
printf("\nDia: ");
scanf(" %d", &newTraveler.flight_date.day);
printf("\nMes: ");
scanf(" %d", &newTraveler.flight_date.month);
printf("\nAnnio: ");
scanf(" %d", &newTraveler.flight_date.year);
printf("\nDestino: ");
scanf(" %s", newTraveler.destiny);

c=simpleInsertion(c,newTraveler);
printf("\nEl usuario ha sido insertado\n");
back();
break;

case 'x' :
printf("Ha salido de la aplicacion\n");
break;
default:
printf("No ha seleccionado la opcion correcta\n");
break;
}

}while(options != 'x' && options != 'X');
	

return 0;
}

//insert a traveler according to the position
struct collection insert(struct collection c, struct traveler newTraveler, int pos){
	c.tope++;
	for(int i = c.tope - 1; i>=pos; i--){
		c.arr[i+1] = c.arr[i];
	}
	c.arr[pos] = newTraveler;
	return c;
}
//simple way to insert a traveler
struct collection simpleInsertion(struct collection c, struct traveler newTraveler){
	c.arr[c.tope+1] = newTraveler;
	c.tope++;
	return c;
}

//to show the travelers
void show(struct collection c){
int counter = 1;
	for(int i=0; i<= c.tope; i++){
		printf("Numero: %d\n", counter);
		printf("Posicion: %d\n", i);
		printf("ID: %d\n", c.arr[i].id);
		printf("Nombre: %s\n", c.arr[i].name);
		printf("Apellido: %s\n", c.arr[i].lastname);
		printf("Fecha de Vuelo\n");
		printf("Dia: %d\n", c.arr[i].flight_date.day);
		printf("Mes: %d\n", c.arr[i].flight_date.month);
		printf("Anio: %d\n", c.arr[i].flight_date.year);
		printf("Destino: %s\n", c.arr[i].destiny);
		printf("=================================\n");
		counter++;
	}
}



void back(){
	char letter;
	do{
		printf("\nEscriba la letra 'r' para regresar\n");
		scanf(" %c", &letter);
	}while(letter != 'r' && letter != 'R');
}



