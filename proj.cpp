

/*
	Name: Projeto Estrutura de dados
	Author: Tiago Moura Chaves
	Date: 01/12/24 13:50
	Description: Programa com fila, pilha e lista além do método de ordenação bubble sort 
*/





#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_MAXIMO 1000

// Declaração das funções
void menu();
void inserirNo(int valor);
void exibirLista();
void adicionarFila(int valor);
void removerFila();
void exibirFila();
void empilhar(int valor);

void desempilhar();
void exibirPilha();
void ordenarDados();

// Estruturas de Dados
typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct Fila {
    int dados[TAMANHO_MAXIMO];
    int inicio, fim;
} Fila;

typedef struct Pilha {
    int dados[TAMANHO_MAXIMO];
    int topo;
} Pilha;

// Variáveis globais
No *cabeca = NULL;
Fila fila;
Pilha pilha;

// Função principal
int main() {
    fila.inicio = -1;
    fila.fim = -1;
    pilha.topo = -1;
    menu();
    return 0;
}

// Funções para Lista
void inserirNo(int valor) {
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = cabeca;
    cabeca = novoNo;
    printf("Valor %d inserido na lista.\n", valor);
}

void exibirLista() {
    if (cabeca == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    No *temp = cabeca;
    printf("Lista: ");
    while (temp) {
        printf("%d -> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// Funções para Fila
void adicionarFila(int valor) {
    if (fila.fim == TAMANHO_MAXIMO - 1) {
        printf("Fila cheia.\n");
        return;
    }
    if (fila.inicio == -1) fila.inicio = 0;
    fila.dados[++fila.fim] = valor;
    printf("Valor %d adicionado à fila.\n", valor);
}

void removerFila() {
    if (fila.inicio == -1 || fila.inicio > fila.fim) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Valor %d removido da fila.\n", fila.dados[fila.inicio++]);
}

void exibirFila() {
    if (fila.inicio == -1 || fila.inicio > fila.fim) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila: ");
    for (int i = fila.inicio; i <= fila.fim; i++) {
        printf("%d ", fila.dados[i]);
    }
    printf("\n");
}

// Funções para Pilha
void empilhar(int valor) {
    if (pilha.topo == TAMANHO_MAXIMO - 1) {
        printf("Pilha cheia.\n");
        return;
    }
    pilha.dados[++pilha.topo] = valor;
    printf("Valor %d empilhado.\n", valor);
}

void desempilhar() {
    if (pilha.topo == -1) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Valor %d desempilhado.\n", pilha.dados[pilha.topo--]);
}

void exibirPilha() {
    if (pilha.topo == -1) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Pilha: ");
    for (int i = pilha.topo; i >= 0; i--) {
        printf("%d ", pilha.dados[i]);
    }
    printf("\n");
}

// Funções para Ordenação de Dados
void bubbleSort(int vetor[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void ordenarDados() {
    int vetor[TAMANHO_MAXIMO];
    int i;
    srand(time(NULL));

    for (i = 0; i < TAMANHO_MAXIMO; i++) {
        vetor[i] = rand() % 10000; // Números aleatórios entre 0 e 9999
    }

    printf("Vetor original:\n");
    for (i = 0; i < 20; i++) { // Mostrando apenas os primeiros 20 elementos
        printf("%d ", vetor[i]);
    }
    printf("...\n");

    bubbleSort(vetor, TAMANHO_MAXIMO);

    printf("Vetor ordenado:\n");
    for (i = 0; i < 20; i++) { // Mostrando apenas os primeiros 20 elementos
        printf("%d ", vetor[i]);
    }
    printf("...\n");
}

// Menu Principal
void menu() {
    int opcao, valor;
    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Lista\n");
        printf("2. Fila\n");
        printf("3. Pilha\n");
        printf("4. Ordenação de Dados\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n--- Operações com Lista ---\n");
                printf("1. Inserir\n");
                printf("2. Exibir\n");
                printf("Escolha uma opção: ");
                scanf("%d", &valor);
                if (valor == 1) {
                    printf("Digite um valor para inserir: ");
                    scanf("%d", &valor);
                    inserirNo(valor);
                } else if (valor == 2) {
                    exibirLista();
                } else {
                    printf("Opção inválida.\n");
                }
                break;
            case 2:
                printf("\n--- Operações com Fila ---\n");
                printf("1. Inserir\n");
                printf("2. Remover\n");
                printf("3. Exibir\n");
                printf("Escolha uma opção: ");
                scanf("%d", &valor);
                if (valor == 1) {
                    printf("Digite um valor para inserir: ");
                    scanf("%d", &valor);
                    adicionarFila(valor);
                } else if (valor == 2) {
                    removerFila();
                } else if (valor == 3) {
                    exibirFila();
                } else {
                    printf("Opção inválida.\n");
                }
                break;
            case 3:
                printf("\n--- Operações com Pilha ---\n");
                printf("1. Empilhar\n");
                printf("2. Desempilhar\n");
                printf("3. Exibir\n");
                printf("Escolha uma opção: ");
                scanf("%d", &valor);
                if (valor == 1) {
                    printf("Digite um valor para empilhar: ");
                    scanf("%d", &valor);
                    empilhar(valor);
                } else if (valor == 2) {
                    desempilhar();
                } else if (valor == 3) {
                    exibirPilha();
                } else {
                    printf("Opção inválida.\n");
                }
                break;
            case 4:
                ordenarDados();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);
}

