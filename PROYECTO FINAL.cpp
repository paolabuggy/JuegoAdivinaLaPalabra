//Programa de adivina la palabra
//Paola Alba Bugarín 1°E
//Universidad Autónoma de Aguascalientes
//Lógica de Programación
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<iostream>
#include<string.h>
#include<windows.h>

//funciones
void categorias(); 
void oport(int e); 
int juego1(char palabra[20][20]); 
int puntaje(int sumap[10], int puntof, int game); 
int ordenar(int sumap[10], int game); 
void despedida(); 
void salir1(); //función para mostrar el mensaje de salida del programa en el primer menú
void extra(); //FUNCIÓN AGREGADA PARA EL MÉTODO DE BÚSQUEDA
int game=0;

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon, dwPos);
}

int main(){
	//portada en sistema
	gotoxy (30,1);
	printf("BIENVENIDOS A ADIVINA LA PALABRA");
	gotoxy (30,5);
	printf("Hecho por: Paola Alba Bugar%cn de 1%cE", 161, 167);
	gotoxy (30,9);
	printf("UNIVERSIDAD AUTONOMA DE AGUASCALIENTES");
	gotoxy (30,11);
	printf("Carrera: Ing. en Sistemas Computacionales");
	gotoxy (30,13);
	printf("Materia: L%cgica de Programaci%cn", 162, 162);
	gotoxy (30,15);
	printf("Maestra: Clelia Ivette Ru%cz Vertiz", 161);
	gotoxy (30,17);
	printf("\n   Cargando...");
	Sleep(7000);
	system("cls");	
	int opc, i;
	//menú de ingreso 
	gotoxy (30,1);
	printf("Empecemos...");
	gotoxy (30,5);
	printf("1- Jugar Adivina la Palabra");
	gotoxy (30,7);
	printf("2- Juego extra");
	gotoxy (30,9);
	printf("3- Salir");
	gotoxy (30,11);
	printf("Seleccione una opci%cn: ", 162);
	scanf("%d", &opc);
	while(opc>=1 && opc<=3){
		switch(opc){
			case 1:{
				categorias();  
				break;
			}
			case 2:{
				extra();
				break;
			}
			case 3: {
				salir1();
				system("pause");
				return 0;
				break;
			}
		}
		break;	
	}			
}

//funcion que muestra el menú de las categorias 
void categorias(){
	int cat;
	system("cls");
	printf("\n\n\t\tCategorias:\n");
	printf("\n\t\t1-Animales \n");
	printf("\t\t2-Paises \n");
	printf("\t\t3-Colores \n");
	printf("\t\t4-Dificiles \n");
	printf("\t\t5-Salir \n");
	printf("\n\tSeleccione una opci%cn: ", 162);
	scanf("%d", &cat);
	while(cat>0 || cat<=5){
		switch(cat){
			case 1:{
				char palabra[20][20]={"tiburon","canguro","gato","borrego","gallina","murcielago","elefante","serpiente","jaguar","jirafa"};
				juego1(palabra);
				break;
			}
			case 2:{
				char palabra[20][20]={"mexico","japon","alemania","venezuela","alemania","australia","turquia","brasil","colombia","inglaterra"};
				juego1(palabra);
				break;
			}
			case 3:{
				char palabra[20][20]={"amarillo","naranja","plateado","morado","verde","turquesa","dorado","gris","negro","blanco"};
				juego1(palabra);
				break;
			} 
			case 4:{
				char palabra[20][20]={"hidraulica","cloruro","electrostatica","ornitorrinco","computadora","calculadora","nada","sandia","checoslovaquia","teclado"};
				juego1(palabra);
				break;
			} 
			case 5:{
				despedida();
				exit(0);
				break;
			}
		}
	}
}

//función del juego 
int juego1(char palabra[20][20]){
	int cont, longitud;
	int puntos=0;
	int sumap[10]={0,0,0,0,0,0,0,0,0,0}; //vector para guardar puntajes
	int i, j, e;
	int opc;
	char palshow[20], respuesta[30], letra;	 
 	do{
		system("cls"); //borra lo que había en la pantalla
		gotoxy(20,1); 
		printf("DESCUBRE LA PALABRA");
		oport(0);//se muestra el numero de oportunidades que quedan
  		srand(time(NULL)); //función para generar un número aleatorio del 0 al 10
  		longitud=rand()%11;//el número aleatorio se almacena en longitud	
 	 	cont=0;	 
		e=0; //numero de errores	
 	 	strcpy(palshow,palabra[longitud]);//copia en palshow una palabra de la categoria elegida (FUNCION STRCPY)
 	 	longitud=strlen(palshow);//se obtiene el tamaño de la palabra y se almacena en longitud (FUNCION STRLEN)
 	 	gotoxy(4,7);
  		for (i=0; i<longitud ; i++){
  	 		respuesta[i]='*';//se almacena * en un vector para despues imprimir la longitud de la palabra a descubrir
  	 		printf (" %c ", respuesta[i]);// se imprime * en el lugar de las letras 
 	 	}
 	 	do{
 	 		fflush (stdin);
 			gotoxy (4,12); 
			printf ("Ingrese una letra: ");
  			scanf ("%c", &letra);
  			letra=tolower(letra);//convierte la letra mayuscula en minuscula (si se da el caso)
  			int error=0;
  			gotoxy(4,7);
  			for(j=0; j<longitud; j++){
  				if (letra==palshow[j]){ //condicion que compara si la letra ingresada por el usuario se encuentra en la palabra designada
     				if(letra!=respuesta[j]){
     	 				respuesta[j]=letra;// la sustituye por el *
     	 				cont++;
     	 				puntos=puntos+5;
    				}
   				}
    			else
     				error++;   			
    		printf(" %c ", respuesta[j]);//imprime la letra correcta 
   			}//fin del for
   			if(error==longitud)//si la letra ingresada no corresponde a ninguna de la palabra a adivinar
 				e++;//segun la cantidad de letras erroneas aumenta e
 			oport(e); //llama a la función oport y envia e
  		}while(cont<longitud && e<8);
	int puntof;  
  	if(e==8){//entra si ninguna de las letras corresponden a la palabra o se cometieron 10 errores
		puntof=puntos;
		gotoxy(4,15);
		printf("Has perdido, suerte para la pr%cxima\n    Presione enter para descubrir la palabra...", 162);
		getch(); //lee el enter pero sin mostrarlo en pantalla
		gotoxy(4,7);
		for(j=0; j<longitud; j++){  
			printf (" %c ", palshow[j]);//imprime la palabra
   		}
  	}
  	if(cont==longitud){//entra si todas las letras ingresadas corresponden a la palabra o se cometieron menos de 6 errores
		if(e==0){//si no se cometio ningun error			
			gotoxy(4,15);
			printf ("GANASTE sin cometer errores");
			puntof=puntos+500;
   		}
		else{//si se cometieron pocos errores
			gotoxy(4,15);
			printf ("GANASTE con %d intentos fallidos", e);
			puntof=puntos+250;
		}
  	}
	game++; //contador que aumenta por cada partida para llevar la cuenta de puntajes	
	gotoxy (4,17);
	printf("Obtuviste %d puntos", puntof); //muestra los puntos que obtuvo el usuario en esa misma partida
	puntaje(sumap, puntof, game);	
  	gotoxy(3,22);
  	printf("Presiona (0) si deseas cambiar la categoria, (1) para");
  	gotoxy(3,23);
  	printf("continuar en la misma categoria o (2) para salir: ");
	scanf("%d", &opc);
  	if(opc==0){
  		system("cls");
  		categorias();
	}
	if(opc==2){
		despedida();
		exit(0);		
	}else
		fflush (stdin);
		opc=1;
	}while(opc==1);
}
//función que complementa el juego dando las oportunidades del jugador
void oport(int e){
	int f=0;
 	f=8-e; //se dan 8 oportunidades y se le van restando 'a' veces 
	gotoxy (42,4); 
	printf("    Quedan     %d          ",f);
 	gotoxy (42,5); 
	printf("    oportunidades          ");
}
int puntaje(int sumap[10], int puntof, int game){
	int j;
	sumap[game-1]=puntof; //se van guardando los puntajes ganados por juego en una categoria	
	gotoxy (45,9);
	printf("Tus puntajes son:"); //se imprimen los puntajes abajo de las oportunidades restantes
	ordenar(sumap, game); //se llama a la función ordenar para ordenar los puntajes de mayor a menor
	for(j=0; j<game; j++){
		if(sumap[j]!=0){
			gotoxy (52,10+j);		
			printf("%d", sumap[j]);	
		}
	}	
}
//Método de ordenación por burbuja
int ordenar(int sumap[10], int game){
	int i, j, aux;
	if(game>=2){ //se empiezan a ordenar los puntajes a partir de la segunda partida
	for(i=0; i<game; i++){ //ordenación de puntajes por burbuja
		for(j=0; j<game; j++){
			if(sumap[j]<sumap[j+1]){
				aux=sumap[j];
				sumap[j]=sumap[j+1];
				sumap[j+1]=aux;
			}
		}
	}
	return sumap[10]; //se regresan los valores ordenados
	return game;
	}
}
//se llama a esta función cuando el usuario quiera salir 
void despedida(){
	system("cls");
	gotoxy (30,5);
	printf("Gracias por jugar :)");
	gotoxy (30,7);
	printf("Vuelva pronto \n\n");
}
//FUNCIÓN AGREGADA SIN RETORNO DE VALOR Y SIN PASO DE PARAMETROS (10 DIC)
void salir1(){
	system("cls");
	gotoxy (30,5);
	printf("Gracias por utilizar el programa");
}
//FUNCIÓN AGREGADA PARA EL MÉTODO DE BÚSQUEDA SECUENCIAL (10 DIC)
void extra(){
	char cadena[28][30]={"platano", "manzana", "banana", "naranja", "fresa", "durazno", "limon", "uva", "pera", "sandia", "cereza", "kiwi", "mango", "maracuya", "lichi", "frambuesa", "papaya", "melon", "coco", "ciruela", "granada", "aguacate", "mandarina", "lima", "higo", "arandano", "mora", "zarzamora"};
	char cadena2[30];
	int i, otra;	
	do{
		system("cls");
		printf("\nIngresa en min%csculas una fruta que creas que NO tenga guardada en este programa: ", 163);
		scanf("%s", cadena2);
		int fruta=0;
		for(i=0; i<27; i++){
			if(strcmp(cadena[i], cadena2)==0){
				printf("\n\tRayos y centellas, la fruta que ingresaste fue encontrada\n");
				fruta=1;	
			}	
		}
		if(fruta==0){
				printf("\n\n\tOh no, le ganaste al programa");
				printf("\n\tTu fruta no la tenemos registrada\n\n");
		}
		printf("\n\n\nIngresa (1) para volver a jugar o (0) para salir: ");
		scanf("%d", &otra);
		if(otra==0){
			despedida();
			exit(0);
		}
		else
			otra=1;
	}while(otra==1);
}
