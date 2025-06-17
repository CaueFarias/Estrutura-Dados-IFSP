#include <iostream>
using namespace std;

#define MAX 100

class Fila {
private:
    int dados[MAX];
    int inicio, fim, tamanho;

public:
    Fila() {
        inicio = fim = tamanho = 0;
    }

    bool vazia() {
        return tamanho == 0;
    }

    bool cheia() {
        return tamanho == MAX;
    }

    void enfileira(int valor) {
        if (!cheia()) {
            dados[fim] = valor;
            fim = (fim + 1) % MAX;
            tamanho++;
        } else {
            cout << "Fila cheia!\n";
        }
    }

    int desenfileira() {
        if (!vazia()) {
            int valor = dados[inicio];
            inicio = (inicio + 1) % MAX;
            tamanho--;
            return valor;
        }
        return -1;
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
