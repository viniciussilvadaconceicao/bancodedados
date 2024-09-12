#include <iostream>
#include <string>
#define TAM_ALFABETO 128 // Tamanho do alfabeto relativo à tabela ASCII

class No {
    friend class ArvoreDigital;

private:
    bool terminal; // Determina se um nó é terminal ou não
    No* filhos[TAM_ALFABETO] = {nullptr}; // Array de nós
    int nos; // Determina quantos nós estão preenchidos

public:
    // Construtor
    No(const bool terminal);
};

class ArvoreDigital {
private:
    No* raiz; // Nó raiz

public:
    // Construtor
    ArvoreDigital();

    // Métodos
    bool buscar(const std::string&); // Retorna se uma palavra pertence ou não à árvore
    void inserir(const std::string&); // Chama a primeira recursão da função de inserção de caractere
    bool remover(const std::string&); // Retorna se a palavra foi removida ou se não existe na árvore
    void limparArvore(No*); // Usada pelo destrutor para limpeza antes do fim do programa
    void inserirCaractere(No*, const std::string&, unsigned int); // Insere caractere recursivamente na árvore
    bool buscarCaractere(No*, const std::string&, unsigned int); // Procura caractere recursivamente na árvore
    bool removerCaractere(No*, const std::string&, unsigned int, bool*); // Remove caractere recursivamente na árvore
    void imprimirNo(No*, std::string); // Imprime terminal
    void imprimirTudo(); // Realiza a primeira chamada de impressão da árvore

    // Destrutor
    ~ArvoreDigital();
};

// Construtor de nó
No::No(bool terminal) {
    this->terminal = terminal;
    this->nos = 0;
}

// Construtor de árvore digital
ArvoreDigital::ArvoreDigital() {
    raiz = new No(false);
}

// Métodos de árvore digital
void ArvoreDigital::inserir(const std::string& palavra) {
    inserirCaractere(raiz, palavra, 0);
}

bool ArvoreDigital::buscar(const std::string& palavra) {
    return buscarCaractere(raiz, palavra, 0);
}

bool ArvoreDigital::remover(const std::string& palavra) {
    bool encontrado;
    removerCaractere(raiz, palavra, 0, &encontrado);
    return encontrado;
}

void ArvoreDigital::inserirCaractere(No* a, const std::string& palavra, unsigned int pos) {
    if (pos < palavra.length()) { // Se ainda existem caracteres a serem percorridos
        char c = palavra.at(pos);
        int posicaoAscii = c;

        if (a->filhos[posicaoAscii] == nullptr) { // Se não houver nó relativo à posição da palavra, é criado
            a->filhos[posicaoAscii] = new No(false);
            a->nos++;
        }
        inserirCaractere(a->filhos[posicaoAscii], palavra, pos + 1); // Recursividade até chegar ao fim da palavra
    } else { // Última chamada para transformar em nó terminal
        a->terminal = true;
    }
}

bool ArvoreDigital::buscarCaractere(No* a, const std::string& palavra, unsigned int pos) {
    if (pos < palavra.length()) { // Se ainda existem caracteres a serem percorridos
        char c = palavra.at(pos);
        int posicaoAscii = c;

        if (a->filhos[posicaoAscii] == nullptr) { // Se não houver nó correspondente ao caractere, a palavra não existe na árvore
            return false;
        }
        return buscarCaractere(a->filhos[posicaoAscii], palavra, pos + 1); // Recursividade até atingir o fim da palavra
    } else if (a->terminal == true) { // Se o último nó relativo ao caractere for terminal, a palavra existe
        return true;
    } else { // Se o último nó relativo ao caractere for não terminal, a palavra não existe
        return false;
    }
}

bool ArvoreDigital::removerCaractere(No* a, const std::string& palavra, unsigned int pos, bool* encontrado) {
    if (pos < palavra.length()) { // Se ainda existem caracteres a serem percorridos
        char c = palavra.at(pos);
        int posicaoAscii = c;

        if (a->filhos[posicaoAscii] == nullptr) { // Se não houver nó correspondente ao caractere, a palavra não existe na árvore
            *encontrado = false;
        } else {
            removerCaractere(a->filhos[posicaoAscii], palavra, pos + 1, encontrado); // Recursividade até atingir o fim da palavra

            if (a->filhos[posicaoAscii]->nos == 0 && a->filhos[posicaoAscii]->terminal == false && *encontrado == true) { // Se o nó filho não tiver filhos e não for terminal, pode ser removido
                a->nos--;
                No* aux = a->filhos[posicaoAscii];
                a->filhos[posicaoAscii] = nullptr;
                delete aux;
            }
        }
    } else if (a->terminal == false && pos == palavra.length()) { // Se o último nó relativo ao caractere for não terminal, a palavra não existe
        *encontrado = false;
    } else if (a->terminal == true && pos == palavra.length()) { // Se o último nó relativo ao caractere for terminal, a palavra existe
        *encontrado = true;
        a->terminal = false;
    }
    return *encontrado;
}

void ArvoreDigital::limparArvore(No* no) {
    int indice = 32;

    while (no->nos > 0 && indice < TAM_ALFABETO) { // Percorrendo array de ponteiros
        if (no->filhos[indice] != nullptr) {
            limparArvore(no->filhos[indice]);
            delete no->filhos[indice];
        }
        indice++;
    }
}

void ArvoreDigital::imprimirTudo() {
    imprimirNo(raiz, "");
}

void ArvoreDigital::imprimirNo(No* p, std::string prefixo) {
    char c;
    if (p->terminal == true) { // Se o nó é terminal
        std::cout << prefixo << std::endl;
    }

    for (int indice = 32; indice < TAM_ALFABETO; indice++) { // Percorrendo array de ponteiros
        if (p->filhos[indice] != nullptr) {
            c = indice;
            prefixo.push_back(c);
            imprimirNo(p->filhos[indice], prefixo);
            prefixo.pop_back();
        }
    }
}

// Destrutor de árvore digital
ArvoreDigital::~ArvoreDigital() {
    limparArvore(raiz);
    delete raiz;
}

int main() {
    std::string entrada, palavra;
    ArvoreDigital* AD = new ArvoreDigital();

    while (entrada.compare("F") != 0) { // Menu principal do programa
        std::getline(std::cin, entrada);

        if (entrada.compare("I") == 0) { // Opção para inserir nova palavra
            std::getline(std::cin, palavra);
            AD->inserir(palavra);
        } else if (entrada.compare("B") == 0) { // Opção de busca de palavra
            std::getline(std::cin, palavra);
            if (AD->buscar(palavra)) {
                std::cout << "Palavra Encontrada" << std::endl;
            } else {
                std::cout << "Palavra não encontrada" << std::endl;
            }
        } else if (entrada.compare("R") == 0) { // Opção de remoção de palavra
            std::getline(std::cin, palavra);
            if (AD->remover(palavra)) {
                std::cout << "Palavra removida" << std::endl;
            } else {
                std::cout << "Palavra inexistente" << std::endl;
            }
        } else if (entrada.compare("E") == 0) { // Opção de exibição de todas as palavras
            AD->imprimirTudo();
        }
    }

    delete AD; // Limpeza da árvore no fim do programa
    return 0;
}


