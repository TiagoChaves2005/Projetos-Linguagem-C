/*
	Name: Programa verificador de n�mero primo
	Author: Tiago Moura Chaves
	Date: 21/08/23 10:24
	Description: Programa para seber se n�mero � primo por meio do while
*/

#include <stdio.h>
#include <locale.h>

int main ()
{
	setlocale(LC_ALL, "Portuguese");
	int i, num, qtde;
	
	do {
		printf("\nDigite um n�mero maior que um:");
		scanf("%d", &num);
	}while(num<=1);
	
	i=1;
	qtde = 0;
	while (i<=num)
	{
		if(num%i==0)
			qtde++;
		i++;
	}
	if(qtde > 2)
		printf("\nN�mero informado n�o � primo");
	else
		printf("\nN�mero informado � primo");

	getchar();
	return 0;
}
