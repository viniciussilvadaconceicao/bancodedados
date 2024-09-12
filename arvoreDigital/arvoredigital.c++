#include <iostream>
#include <unordered_map>
using namespace std;

// Definição da estrutura do nó
struct NoTrie {
    unordered_map<char, NoTrie*> filhos;
    bool fimDaPalavra;

    NoTrie() : fimDaPalavra(false) {}
};

// Classe Trie
class Trie {
private:
    NoTrie* raiz;

public:
    Trie() {
        raiz = new NoTrie();
    }

    // Método para inserir uma palavra na trie
    void inserir(const string& palavra) {
        NoTrie* no = raiz;
        for (char ch : palavra) {
            if (no->filhos.find(ch) == no->filhos.end()) {
                no->filhos[ch] = new NoTrie();
            }
            no = no->filhos[ch];
        }
        no->fimDaPalavra = true;
    }

    // Método para buscar uma palavra na trie
    bool buscar(const string& palavra) {
        NoTrie* no = raiz;
        for (char ch : palavra) {
            if (no->filhos.find(ch) == no->filhos.end()) {
                return false;
            }
            no = no->filhos[ch];
        }
        return no->fimDaPalavra;
    }

    // Método para verificar se existe alguma palavra na trie que começa com o prefixo dado
    bool comecaCom(const string& prefixo) {
        NoTrie* no = raiz;
        for (char ch : prefixo) {
            if (no->filhos.find(ch) == no->filhos.end()) {
                return false;
            }
            no = no->filhos[ch];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.inserir("serra");
    trie.inserir("serre");
    trie.inserir("seres");

    cout << boolalpha; // Para imprimir true/false ao invés de 1/0
    cout << "Buscar 'serra': " << trie.buscar("serra") << endl;
    cout << "Buscar 'serre': " << trie.buscar("serre") << endl;
    cout << "Buscar 'seres': " << trie.buscar("seres") << endl;
    cout << "Buscar 'ser': " << trie.buscar("ser") << endl;
    cout << "Prefixo 'ser': " << trie.comecaCom("ser") << endl;

    return 0;
}