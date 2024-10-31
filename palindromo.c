#include <stdio.h>
#include <string.h>

int main() {
  /*criar duas variaveis max 20*/
  char palavra_inserida[20], reversa[20];
  int quantos_iguais = 0;
  printf("Insira uma palavra: ");
  //usando o fgests para armazer o dados
  fgets(palavra_inserida, sizeof(palavra_inserida), stdin);
  //calcular o tamanho da str
  int tamanho = strlen(palavra_inserida);
  palavra_inserida[strcspn(palavra_inserida, "\n")] = '\0';
  //loop
  for (int cont = 0; cont < tamanho; cont++) {
  //inversao da str
    reversa[cont] = palavra_inserida[tamanho - 1 - cont];
  }

  reversa[tamanho] = '\0';

  for (int inic = 0; inic < tamanho; inic++) {
    if (palavra_inserida[inic] == reversa[inic]) {
      quantos_iguais++;
    }
  }

  if (quantos_iguais == tamanho) {
      printf("eh palindromo\n");
  } else {
      printf("nao eh palindromo");
  }

  return 0;
}
//fim do codigo palindromo.c, vinicius silva da conceicao 