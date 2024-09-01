// ex: fatorial de 5 = 5 * 4 * 3 * 2 * 1 = 120
// fatorial de 0 e 1 = 1
// a recursividade é uma função que chama a si mesma
// se pegar o exemplo de fatorial de 5 ele vai chamar a função fatorial(5) que vai chamar a função fatorial(4) até chegar em fatorial(1) que vai retornar 1
// e vai multiplicando os valores

#include <iostream>
int fatorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return n * fatorial(n - 1);
    }
}

int main(){
    int n;
    std::cout << "digite um numero: ";
    std::cin >> n;
    std::cout << "O fatorial de " << n << " e: " << fatorial(n) << std::endl;
    return 0;
}

