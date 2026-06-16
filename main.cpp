/*main.cpp*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

bool availability(const struct collection &c);
bool askPosition(const struct collection &c, int &pos);
void insert(struct collection &c, struct traveler newTraveler, int pos);
void simpleInsertion(struct collection &c, struct traveler newTraveler);
void show(const struct collection &c);
void back();

int main()
{
struct collection c;
struct traveler newTraveler;
c.tope = -1;
int pos;

char options = '0';
do{
system(CLEAR);
printf("===================================\n");
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
printf("===================\n");
printf("Listado de Viajeros");
printf("\n===================\n");
if(c.tope > -1){
show(c);
}else{
printf("\nNo hay viajeros\n");
}

back();

break;
case '2' :
system(CLEAR);
printf("=========================\n");
printf("Insercion indicando posicion");
printf("\n=========================\n");
printf("\nComplete los siguientes datos");

pos = -1;
if(askPosition(c, pos)){
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

insert(c, newTraveler, pos);
}

back();
break;

case '3' :
system(CLEAR);
printf("============================\n");
printf("Insercion simple");
printf("\n============================\n");
printf("Complete los siguientes datos\n");

if(availability(c)){
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

simpleInsertion(c,newTraveler);
printf("\nEl usuario ha sido insertado\n");
}

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

bool askPosition(const struct collection &c, int &pos){
    bool valid = true;

    if(c.tope == MAX - 1){
        printf("\nLa lista esta llena\n");
        valid = false;
    }
    else if(c.tope == -1){
        pos = 0;
    }

    while(valid && c.tope != -1 && (pos < 0 || pos > c.tope + 1)){
        printf("\nIndica una posicion entre 0 y %d: ", c.tope + 1);
        scanf(" %d", &pos);

        if(pos < 0 || pos > c.tope + 1){
            printf("\nPosicion invalida\n");
        }
    }

    return valid;
}

//insert a traveler according to the position
void insert(struct collection &c, struct traveler newTraveler, int pos){
		c.tope++;
		for(int i = c.tope - 1; i>=pos; i--){
			c.arr[i+1] = c.arr[i];
		}
		c.arr[pos] = newTraveler;
		printf("\n El usuario ha sido insertado\n");
}

bool availability(const struct collection &c){
    bool valid = true;
    
    if(c.tope == MAX - 1){
        printf("\nLa lista esta llena\n");
        valid = false;
    }
    return valid;
}

//simple way to insert a traveler
void simpleInsertion(struct collection &c, struct traveler newTraveler){
	if(c.tope == MAX - 1){
		printf("\nla coleccion esta llena");
	}
	
	c.arr[c.tope+1] = newTraveler;
	c.tope++;
	//c.tope++;
	//c.arr[c.tope] = newTraveler;
	//return c;
}

//to show the travelers
void show(const struct collection &c){
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
