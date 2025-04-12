/*
	Name: Programa de calculo de sal�rio
	Author: Tiago Moura Chaves
	Date: 21/08/23 10:05
	Description: Programa de calculo de sal�rio usando for e baseado no aumento em porcentagem 
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	int ano_atual, ano_contrato, i;
	float salario, novo_salario, percentual;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o ano atual: ");
	scanf("%d", &ano_atual);
	printf("Digite o ano de contrato: ");
	scanf("%d", &ano_contrato);
	
	salario = 1000;
	percentual = 1.5/100;
	novo_salario = salario + salario * percentual;
	
	for(i = ano_contrato; i<=ano_atual; i++)
	{
		percentual = 2 * percentual;
		novo_salario = novo_salario + percentual * novo_salario;
	}
	
	//5.2 quer dizer que sera cinco casas antes do ponto e duas depois
	printf ("\nNovo salario = %5.2f", novo_salario);
	
	getchar();
	return 0;
}

