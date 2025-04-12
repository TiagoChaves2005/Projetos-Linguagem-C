/*
	Name: quickSort.cpp 
	Author: Tiago Moura Chaves
	Date: 29/05/24 09:48
	Description: Implementa��o do m�todo de ordena��o Quick Sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Prototipa��o
void quickSort(int *, int, int);
int particionar(int *, int, int);
int i, tam;
int comp = 0;
int trocas = 0;

int main()
{
	int vet[] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};
	
	tam = sizeof(vet)/sizeof(int);
	
	puts("Vetor DESORDENADO:");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
		
	quickSort(vet, 0, tam-1);
	
	puts("\n\nVetor ordenado pelo Quick Sort:");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
		
	printf("\n\nNumero de trocas : %d", trocas);
	printf("\n\nNumero de comparacoes : %d", comp);
	
}//fim do main

void quickSort(int *V, int inicio, int fim)
{
	int pivot;
	if(fim > inicio)
	{
		pivot = particionar(V, inicio, fim);
		quickSort(V, inicio, pivot-1);
		quickSort(V, pivot+1, fim);
	}
}//fim quickSort

int particionar(int *V, int inicio, int fim)
{
	int dir, esq, pivo, aux;
	esq = inicio;
	dir = fim;
	pivo = V[inicio];
	
	while(esq < dir)
	{
		while(V[esq] <= pivo)
		{
			esq++;
			comp++;
		}
		while(V[dir] > pivo)
		{
			dir--;
			comp++;
		}
		if(esq < dir)
		{
			trocas++;
			aux = V[esq];
			V[esq] = V[dir];
			V[dir] = aux;
		}
		
		/*puts("\n:");
		for(i = 0; i < tam; i++)
			printf("%d|", V[i]);
		getch();
		*/
	}//Fim do while
	V[inicio] = V[dir];
	V[dir] = pivo;
	trocas++;
	return dir;
}//fim particionar
