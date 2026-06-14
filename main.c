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
/*int size = 4;
int tope = size - 1;
int tope = 3;

#antes
#						   0        1          2         3
#struct viajeros v[4] = ["Reina", "Norge", "Nelson", "Micaela"];
#y quiero insertar a Niurisbel en la posicion 1
#despues
tope++; tope=4;
#==========primera corrida==========
#tope = 4;
#pos = 1;
#i=tope-1;
#i=3;
#c.arr[i+1] = c.arr[i];
# i >= pos
# 3 >= 1
#si es true
#							 0	      1	       2         3	         4
#struct collection c[4]= ["Reina", "Norge", "Nelson", "Micaela", "Micaela"];
#i--
#i=2

#===========segunda corrida==========
#int tope = 4;
#int i = 2;
#int pos = 1;
#c.arr[i+1]=c.arr[i];
#c.arr[2+1]=c.arr[2];
#c.arr[3]=c.arr[2];
# i >= pos
# 2 >= 1
#si es true
#							 0         1          2         3         4
#struct collection c[4]=["Reina", "Norge", "Nelson", "Nelson", "Micaela"];
#i--
#i=1

#===========tercera corrida===========
#int tope = 4;
#int i = 1;
#int pos = 1;
# i >= pos
# 1 >= 1
#si es true
#c.arr[i+1]=c.arr[i];
#c.arr[1+1]=c.arr[1];
#c.arr[2]=c.arr[1];
#			 				0         1          2         3         4
#struct collection c[4]=["Reina", "Norge", "Norge", "Nelson", "Micaela"];
#i--
#i=0

#==============cuarta corrida=============
int tope =4;
#int i = 0;
#int pos = 1;
# i >= pos
# 0 >= 1
#como es false porque 0 no es mayor o igual a 1
#entonces hasta ahi llega el for,
#salgo del for
#y asigno el valor en el arreglo en la posicion 1
#c.arr[pos] = new.name;
#c.arr[1] = "Niurisbel";
#			  				0         1         	2         3         4
#struct travelers v[4]= ["Reina", "Niurisbel", "Norge", "Nelson", "Micaela"];
*/
struct collection c;
struct traveler newTraveler;
c.tope= -1;
int pos;

/* probando insercion de datos fijos
c.arr[0].id = 11;
strcpy(c.arr[0].name, "Norge");
strcpy(c.arr[0].lastname, "Cruz");
c.arr[0].flight_date.day = 25;
c.arr[0].flight_date.month = 11;
c.arr[0].flight_date.year = 2026;
strcpy(c.arr[0].destiny, "Italy");

struct traveler newTraveler;
newTraveler.id = 17;
strcpy(newTraveler.name, "Niurisbel");
strcpy(newTraveler.lastname, "Cruz");
newTraveler.flight_date.day = 20;
newTraveler.flight_date.month = 12;
newTraveler.flight_date.year = 2026;
strcpy(newTraveler.destiny, "Spain");
*/



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

//insert(c, newTraveler, 3, 1);
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

struct collection insert(struct collection c, struct traveler newTraveler, int pos){
	c.tope++;
	for(int i = c.tope - 1; i>=pos; i--){
		c.arr[i+1] = c.arr[i];
	}
	c.arr[pos] = newTraveler;
	return c;
}

struct collection simpleInsertion(struct collection c, struct traveler newTraveler){
	c.arr[c.tope+1] = newTraveler;
	c.tope++;
	return c;
}


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



