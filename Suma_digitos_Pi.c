/*
 ============================================================================
 Name        : Suma_digitos_Pi.c
 Author      : luisa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*Programa que suma los primeros n digitos de la representacion decimal de Pi*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Se declara la función que sumara los digitos, le entra por parametro el arreglo
 de los digitos y la cantidad de digitos que se quiere sumar*/
int sumar(int *arreglo,int num);

int main(int argc, char **argv){

	int n;
	int i;
	char *nume;

	nume= *(argv +1);
	n=atoi(argv[1]);

	if(n>2500000 || n<0){
		printf("Todo mal \n");

}
	else{


		printf("%d\n",n);
		char arregl[1000];
		FILE *archivo;

		archivo=fopen("Pi_2500000.txt", "r");
		int num=n;
		int *arreglo = malloc(sizeof(int)*n);
		if(!archivo){
			printf("problems opening the file %s\n", "Pi_2500000.txt");
			 exit(1);
		}




		for(i=0;i<num;i++){
			fscanf(archivo, "%1d", &arreglo[i]);
			printf("%d\n",arreglo[i]);
		 }
		int total=sumar(arreglo,num);
		printf("La suma de los digitos es: %d\n",total);
		close(archivo);
	}

	return 0;
}

int sumar(int *arreglo,int num)
{
	int suma=0;
	int i;
	for (i=0; i<num; i++)
	{
		suma+=arreglo[i];
	}
	return suma;
	}


