/*
	Name: MergeSort.cpp 
	Author: Tiago Moura Chaves
	Date: 22/05/24 09:39
	Description: Implementa��o do m�todo de ordena��o Merge Sort
*/


//Sess�o de prototipa��o
void mergeSort(int *, int, int); //Fun��o que divide
void merge(int *, int, int, int); //Fun��o que "junta" o que foi dividido

//Sess�o de importa��o das bibliotecaas
#include <stdio.h>
#include <stdlib.h>

int vet[]={17,24,-5,8,15,10,1,19,12,3};
int i;

int main()
{
	int comeco, fim;
	comeco = 0;
	fim = sizeof(vet)/sizeof(int) - 1;
	
	puts("Vetor DESORDENADO!!\n");
	for(i=0; i<= fim; i++)
		printf("%d|", vet[i]);
		
	mergeSort(vet, comeco, fim);
	
	puts("\n\nVetor Ordenado pelo Merge Sort!!");
	for(i=0; i<= fim; i++)
		printf("%d|", vet[i]);
		
}

void mergeSort(int vet[], int inicio, int fim)
{
	if(inicio < fim)
	{
		int meio = (inicio + fim)/2;
		mergeSort(vet, inicio, meio); //Quebra todos os elementos do lado esquerdo
		mergeSort(vet, meio+1, fim);//Quebra todos os elementos do lado direito
		merge(vet, inicio, meio, fim);//Junta todos os elementos �nicos
	}	
}//fim da fun��o mergeSort

void merge(int vet[], int comeco, int meio, int fim)
{
	int com1 = comeco;
	int com2 = meio + 1;
	int comAux = 0;
	int tam = fim - comeco + 1;
	int vetAux[tam];
	
	while(com1 <= meio && com2 <= fim)
	{
		if(vet[com1] < vet[com2])//Muda a ordem do vetor
		{
			vetAux[comAux] = vet[com1];
			com1++;
		}//fim do if
		else
		{
			vetAux[comAux] = vet[com2];
			com2++;
		}//fim do else
		comAux++;
	}//fim do while
	
	while(com1 <= meio)//Caso ainda haja elementos na primeira metade
	{
		vetAux[comAux] = vet[com1];
		comAux++;
		com1++;
	}
	
	while(com2 <= fim)//Caso ainda haja elementos na segunda metade
	{
		vetAux[comAux] = vet[com2];
		comAux++;
		com2++;
	}
	
	//Move todos os elementos do vetor auxiliar para o vetor original
	for(comAux = comeco; comAux <= fim; comAux++)
	{
		vet[comAux] = vetAux[comAux-comeco];
	}
	
	
}//fim da fun��o merge

