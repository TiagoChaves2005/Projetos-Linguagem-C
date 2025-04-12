/*
	Name: InsertionSort.cpp
	Author: Tiago Moura Chaves
	Date: 15/05/24 09:44
	Description: 
*/

#include <stdio.h>
#include <conio.h>

//prototipação
void insertionSort(int *, int);

main()
{
	
	int vet[] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};
	int i;
	int tam = sizeof(vet)/sizeof(int);	

	puts("Vetor ORIGINAL:");
	for(i=0; i < tam; i++)
		printf("%d|", vet[i]);
	
	insertionSort(vet, tam);
	
	puts("Vetor ORDENADO pelo Insertion Sort:");
	for(i=0; i < tam; i++)
		printf("%d|", vet[i]);
}//Fim do main

void insertionSort(int vet[], int tam)
{
	int i, j, chave;
	for(i=1; i < tam; i++)
	{
		chave = vet[i];
		j = i-1;
		
		while(j >=0 && vet[j] > chave)
		{
			vet[j+1] = vet[j];
			j = j-1;
		}//fim do while
		vet[j+1] = chave;
	}//fim do for	
	
}//Fim do void
