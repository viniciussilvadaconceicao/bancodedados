#include <stdio.h>
#include <stdlib.h>

#define MAX 20
/* botei um valor maximo só para ter uma boa pratica e não gastar memória desnecessária*/
typedef struct {
    int itens[MAX];
    int frente, tras;
} Fila;

void inicioDaFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
}

int estaVazio(Fila *f) {
    return f->tras < f->frente;
}

int estaCheio(Fila *f) {
    return f->tras == MAX - 1;
}

void Enfileirando(Fila *f, int elemento) {
    if (estaCheio(f)) {
        printf("Fila cheia!\n");
    } else {
        f->itens[++f->tras] = elemento;
    }
}

int removerDaFrente(Fila *f) {
    if (estaVazio(f)) {
        printf("Fila vazia!\n");
        return -1;
    } else {
        return f->itens[f->frente++];
    }
}

void AmostraFila(Fila *f) {
    if (estaVazio(f)) {
        printf("A Fila está vazia!\n");
    } else {
        printf("Fila: ");
        for (int i = f->frente; i <= f->tras; i++) {
            printf("%d ", f->itens[i]);
        }
        printf("\n");
    }
}

int main() {
    Fila fila;
    inicioDaFila(&fila);

    int opcao, elemento;

    do {
        printf("\nMENU:\n");
        printf("1. Enfileirar elementos\n");
        printf("2. desenfileirar\n");
        printf("3. Amostra\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser adicionado na fila: ");
                scanf("%d", &elemento);
                Enfileirando(&fila, elemento);
                break;
            case 2:
                elemento = removerDaFrente(&fila);
                if (elemento != -1) {
                    printf("O elemento foi removido da fila: %d\n", elemento);
                }
                break;
            case 3:
                AmostraFila(&fila);
                break;
            case 4:
                printf("Saindo... obrigado por usar o nosso sistema\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}