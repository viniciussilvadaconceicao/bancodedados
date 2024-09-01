// ex: fatorial de 5 = 5 * 4 * 3 * 2 * 1 = 120
// fatorial de 0 e 1 = 1
// a recursividade é uma função que chama a si mesma
// se pegar o exemplo de fatorial de 5 ele vai chamar a função fatorial(5) que vai chamar a função fatorial(4) até chegar em fatorial(1) que vai retornar 1
// e vai multiplicando os valores

#include <iostream>
int calcularfatorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return n * calcularfatorial(n - 1);
    }
}

using namespace std;
// usamos o using namespace std para não precisar ficar escrevendo std::cout, std::cin, std::endl
int main(){
    int n;
    cout << "digite um numero: ";
    // cout é para imprimir na tela
    cin >> n;
    // cin é para pegar o valor de n digitado pelo usuário
    cout << "O fatorial de " << n << " e: " << calcularfatorial(n) << endl;
    // endl é para pular uma linha
    return 0;
}

