#include <stdio.h>  

struct nodo {
        int elemento;
        struct nodo *siguiente;
        };

struct nodo *primero, *ultimo, *primero2, *ultimo2;

void mostrar_menu() {
      printf("\n\nMenú:\n=====\n\n");
      printf("1.- Añadir elementos lista 1\n");
      printf("2.- Añadir elementos lista 2\n");
      printf("3.- Mostrar lista 1\n");
      printf("4.- Mostrar lista 2\n");
      printf("5.- Metodo del parcial\n");
      printf("6.- Salir\n\n");
      printf("Escoge una opción: ");
      fflush(stdout);
 }

/* Con esta función añadimos un elemento al final de la lista */

void anadir_elemento() {
      struct nodo *nuevo;

      /* reservamos memoria para el nuevo elemento */
      nuevo = (struct nodo *) malloc (sizeof(struct nodo));
      
	if (nuevo==NULL) 
		printf( "No hay memoria disponible!\n"); 


     int x= 0;

	printf("\nNuevo elemento:\n");
	printf("Elemento que desea insertar: ");
	fflush(stdout);
	scanf("%d", &x);
	
	nuevo->elemento=x;
	



	/* el campo siguiente va a ser NULL por ser el último elemento de la lista */
      nuevo->siguiente = NULL; 
/* ahora metemos el nuevo elemento en la lista. lo situamos         al final de la lista, se comprueba si la lista está vacía. si primero==NULL es que no hay ningún elemento en la lista. también vale ultimo==NULL */
      if (primero==NULL) {
		printf( "Primer elemento\n");
		primero = nuevo;
		ultimo = nuevo;
	} else {
           /* el hasta ahora último apuntará al nuevo */
           ultimo->siguiente = nuevo;
           /* hacemos que el nuevo sea ahora el último */
           ultimo = nuevo;
      }
 }
 
 /* Con esta función añadimos un elemento al final de la lista */

void anadir_elemento2() {
      struct nodo *nuevo;

      /* reservamos memoria para el nuevo elemento */
      nuevo = (struct nodo *) malloc (sizeof(struct nodo));
      
	if (nuevo==NULL) 
		printf( "No hay memoria disponible!\n"); 


     int x= 0;

	printf("\nNuevo elemento:\n");
	printf("Elemento que desea insertar: ");
	fflush(stdout);
	scanf("%d", &x);
	
	nuevo->elemento=x;
	



	/* el campo siguiente va a ser NULL por ser el último elemento de la lista */
      nuevo->siguiente = NULL; 
/* ahora metemos el nuevo elemento en la lista. lo situamos         al final de la lista, se comprueba si la lista está vacía. si primero==NULL es que no hay ningún elemento en la lista. también vale ultimo==NULL */
      if (primero2==NULL) {
		printf( "Primer elemento\n");
		primero2 = nuevo;
		ultimo2 = nuevo;
	} else {
           /* el hasta ahora último apuntará al nuevo */
           ultimo2->siguiente = nuevo;
           /* hacemos que el nuevo sea ahora el último */
           ultimo2 = nuevo;
      }
 }
 
 
 
 void mostrar_lista() {
      struct nodo *auxiliar; /* para recorrer la lista */

      int i; i=0;
      auxiliar = primero;
      printf("\nMostrando la lista completa:\n");
      while (auxiliar!=NULL) {
            printf( "Elemento: %d \n",                    			
			auxiliar->elemento);
            auxiliar = auxiliar->siguiente;
            i++;
      }
      if (i==0) printf( "\nLa lista está vacía!!\n" );
 }
 
 void mostrar_lista2() {
      struct nodo *auxiliar; /* para recorrer la lista */

      int i; i=0;
      auxiliar = primero2;
      printf("\nMostrando la lista completa:\n");
      while (auxiliar!=NULL) {
            printf( "Elemento: %d \n",                    			
			auxiliar->elemento);
            auxiliar = auxiliar->siguiente;
            i++;
      }
      if (i==0) printf( "\nLa lista está vacía!!\n" );
 }
 
 
 void enlazar(/*struct nodo* nodo1, struct nodo* nodo2*/) {
 	/* Se establecen los nodos temporales con los cuales moveremos los puntero*/
 	/* Punteros de la lista uno*/
	 struct nodo* aux1=primero;
 	struct nodo* aux2=primero->siguiente;
 	
 	/* Punteros de la lista dos*/
 	struct nodo* aux3=primero2;
 	struct nodo* aux4=primero2->siguiente->siguiente;
 	
 	/*establecemos el punto de parada*/
 	
 	while(aux2->siguiente != NULL){
 		
 		/*realizamos los cambios de punteros que se solicitan*/
 		aux1->siguiente = aux4;
		aux3->siguiente = aux2;
		aux1 = aux2->siguiente;
		aux2 = aux1->siguiente;
		aux3 = aux4->siguiente;
		
		/*Preguntamos si la lista 2 es el final y la establecemos al inicio de la lista*/
		if (aux3->siguiente == NULL){
			aux3->siguiente = aux2;
			aux1->siguiente = primero2;
		}
		
		else{
			aux4 = aux3->siguiente;
	 }
 	
 }
 printf("resultado de enlazar lista1: \n");
 mostrar_lista(primero);
 printf("resultado de enlazar lista2: \n");
 mostrar_lista2(primero2);
}

int main() {
     char opcion;
	
	primero = (struct nodo *) NULL;
	primero2 = (struct nodo *) NULL;
	
    ultimo = (struct nodo *) NULL;
    ultimo2 = (struct nodo *) NULL;
     do {
         mostrar_menu();
         opcion = getch();
             switch ( opcion ) {
                case '1': anadir_elemento(); break;
                case '2': anadir_elemento2(); break;
                case '3': mostrar_lista(primero); break;
                case '4': mostrar_lista2(primero2); break;
                case '5': enlazar(primero, primero2); break;
                case '6': exit( 1 );
                default:
			printf( "Opción no válida\n" );
                         break;
             }
     } while (opcion!='6');
 }




