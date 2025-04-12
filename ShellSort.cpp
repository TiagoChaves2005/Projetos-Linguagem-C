/*
	Name: ShellSort.cpp
	Author: Tiago Moura Chaves
	Date: 15/05/24 09:44
	Description: 
*/

# include <conio.h>
# include <stdio.h>
# include <windows.h>
# include <time.h>
# include <stdlib.h>

int comp = 0;
int trocas = 0;
int vet[100];
//prototipação
void shellSort(int *, int);

main()
{
	int i, tam, comp, trocas;
	tam = sizeof(vet)/sizeof(int)/10;	
	srand(time(NULL));
	
	for(i = 0; i < 100; i++)
		vet[i] = rand()%100;
		
	puts("Vetor ORIGINAL:");
	for(i=0; i < tam; i++)
		printf("%d|", vet[i]);
	

	shellSort(vet, tam);
	
	puts("\n\nVetor ORDENADO pelo Shell Sort:");
	for(i=0; i < tam; i++)
		printf("%d|", vet[i]);

}//Fim do main

void shellSort(int vet[], int tam)
{
	int i, j, chave;
	int h = 1;
	
	while (h < tam)
	{
		h = 3*h+1;
	}
	
	comp++;	
	while(h>0)
	{
		for(i=h; i<tam; i++)
		{
			chave = vet[i];
			j=i;
			while(j>h-1 && chave <= vet[j - h])
			{
				vet[j] = vet[j - h];
				j = j - h;
			}
			vet[j] = chave;
		}
		h = h/2;
	}
	printf("\n\nNumero de trocas : %d", trocas);
	printf("\n\nNumero de comparacoes : %d", comp);
}//Fim do void
