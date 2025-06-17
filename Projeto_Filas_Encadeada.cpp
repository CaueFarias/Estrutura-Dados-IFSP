#include <iostream>
using namespace std;

struct No {
    int senha;
    No* prox;
};

class Fila {
private:
    No* frente;
    No* tras;
    int tamanho;

public:
    Fila() {
        frente = tras = nullptr;
        tamanho = 0;
    }

    ~Fila() {
        while (!vazia())
            desenfileira();
    }

    void enfileira(int senha) {
        No* novo = new No{senha, nullptr};
        if (vazia()) {
            frente = tras = novo;
        } else {
            tras->prox = novo;
            tras = novo;
        }
        tamanho++;
    }

    int desenfileira() {
        if (vazia()) return -1;
        No* temp = frente;
        int senha = temp->senha;
        frente = frente->prox;
        delete temp;
        tamanho--;
        if (frente == nullptr) tras = nullptr;
        return senha;
    }

    bool vazia() {
        return frente == nullptr;
    }

    int tamanhoFila() {
        return tamanho;
    }
};

int main() {
    Fila senhasGeradas, senhasAtendidas;
    int opcao, proximaSenha = 1;

    do {
        cout << "\n--- MENU ---\n";
        cout << "0 - Sair\n";
        cout << "1 - Gerar Senha\n";
        cout << "2 - Realizar Atendimento\n";
        cout << "Senhas aguardando atendimento: " << senhasGeradas.tamanhoFila() << "\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
        case 0:
            if (!senhasGeradas.vazia()) {
                cout << "Ainda há senhas aguardando atendimento. Atenda todas antes de sair.\n";
                opcao = -1;
            } else {
                cout << "Sistema encerrado. Senhas atendidas: " << senhasAtendidas.tamanhoFila() << endl;
            }
            break;
        case 1:
            senhasGeradas.enfileira(proximaSenha++);
            cout << "Senha gerada com sucesso.\n";
            break;
        case 2:
            if (senhasGeradas.vazia()) {
                cout << "Nenhuma senha para atender.\n";
            } else {
                int senha = senhasGeradas.desenfileira();
                senhasAtendidas.enfileira(senha);
                cout << "Atendendo senha: " << senha << endl;
            }
            break;
        default:
            cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    return 0;
}
