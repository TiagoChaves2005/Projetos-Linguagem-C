/*
	Name: BubbleSort.cpp
	Author: Tiago Moura Chaves
	Date: 24/04/24 09:53
	Description: Implementação do método de implementação Bubble Sort
*/


# include <conio.h>
# include <stdio.h>
# include <windows.h>

int vet[] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};

main()
{
	int tam = sizeof(vet)/sizeof(int); //Sizeof ele te apresenta o tamanho do vetor em bytes, para apresentar o tamanho real tem que fazer essa divisão
	int i = 0;
	int j = 0;
	int aux = 0;
	int trocas = 0;
	int comp = 0;
	puts("Vetor DESORDENADO:\n");
	
	for(i = 0; i < tam; i++)
	{
		printf("%d|", vet[i]);
	}
	
	
	//Ordenação dos dados com Bubble Sort
	
	while(j < tam)
	{
		for(i = 0; i < tam-1; i++)
		{
			comp++;
			if(vet[i] > vet[i + 1]) //trocando a ordem de maior ou menor aqui, irá mudar a ordenação deixando ao contrário
			{
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
				trocas++;
			}
		}//Fim do for
		tam--;
	}//Fim do while
	
	tam = sizeof(vet)/sizeof(int);
	puts("\n\nVetor ordenado com Bubble Sort:\n");
	for(i = 0; i < tam; i++)
	{
		printf("%d|", vet[i]);
	}
	
	printf("\n\nNumero de trocas : %d", trocas);
	printf("\n\nNumero de comparacoes : %d", comp);
	
	
}//Fim do main
