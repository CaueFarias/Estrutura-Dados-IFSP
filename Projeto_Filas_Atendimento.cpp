#include <iostream>
using namespace std;

// ----------- Estrutura da Fila -----------
struct NoFila {
    int senha;
    NoFila* prox;
};

class Fila {
private:
    NoFila* frente;
    NoFila* tras;
    int tamanho;

public:
    Fila() : frente(nullptr), tras(nullptr), tamanho(0) {}

    void enfileira(int senha) {
        NoFila* novo = new NoFila{senha, nullptr};
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
        NoFila* temp = frente;
        int senha = temp->senha;
        frente = frente->prox;
        if (!frente) tras = nullptr;
        delete temp;
        tamanho--;
        return senha;
    }

    bool vazia() {
        return frente == nullptr;
    }

    int tamanhoFila() {
        return tamanho;
    }

    void listar() {
        NoFila* atual = frente;
        while (atual) {
            cout << atual->senha << " ";
            atual = atual->prox;
        }
        cout << endl;
    }

    int totalAtendidos() {
        return tamanho;
    }
};

// ----------- Estrutura da Lista de Guich�s -----------
struct Guiche {
    int id;
    Fila senhasAtendidas;
    Guiche* prox;
};

class ListaGuiches {
private:
    Guiche* inicio;

public:
    ListaGuiches() : inicio(nullptr) {}

    void adicionarGuiche(int id) {
        if (buscarGuiche(id)) {
            cout << "Guich� j� existente.\n";
            return;
        }
        Guiche* novo = new Guiche{id, Fila(), inicio};
        inicio = novo;
        cout << "Guich� " << id << " adicionado.\n";
    }

    Guiche* buscarGuiche(int id) {
        Guiche* atual = inicio;
        while (atual) {
            if (atual->id == id)
                return atual;
            atual = atual->prox;
        }
        return nullptr;
    }

    int totalGuiches() {
        int count = 0;
        Guiche* atual = inicio;
        while (atual) {
            count++;
            atual = atual->prox;
        }
        return count;
    }

    int totalSenhasAtendidas() {
        int total = 0;
        Guiche* atual = inicio;
        while (atual) {
            total += atual->senhasAtendidas.totalAtendidos();
            atual = atual->prox;
        }
        return total;
    }
};

// ----------- Fun��o Principal -----------
int main() {
    Fila senhasGeradas;
    ListaGuiches listaGuiches;
    int proximaSenha = 1;
    int opcao;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "0 - Sair\n";
        cout << "1 - Gerar senha\n";
        cout << "2 - Abrir guich�\n";
        cout << "3 - Realizar atendimento\n";
        cout << "4 - Listar senhas atendidas por guich�\n";
        cout << "Senhas aguardando: " << senhasGeradas.tamanhoFila() << "\n";
        cout << "Guich�s abertos: " << listaGuiches.totalGuiches() << "\n";
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch (opcao) {
        case 0:
            if (!senhasGeradas.vazia()) {
                cout << "Ainda h� senhas a serem atendidas. Finaliza��o negada.\n";
                opcao = -1; // continua no loop
            } else {
                cout << "Encerrando sistema. Total de senhas atendidas: " << listaGuiches.totalSenhasAtendidas() << endl;
            }
            break;

        case 1:
            senhasGeradas.enfileira(proximaSenha++);
            cout << "Senha gerada com sucesso.\n";
            break;

        case 2: {
            int idGuiche;
            cout << "Digite o ID do novo guich�: ";
            cin >> idGuiche;
            listaGuiches.adicionarGuiche(idGuiche);
            break;
        }

        case 3: {
            if (senhasGeradas.vazia()) {
                cout << "Nenhuma senha aguardando.\n";
                break;
            }
            int idGuiche;
            cout << "Digite o ID do guich�: ";
            cin >> idGuiche;
            Guiche* guiche = listaGuiches.buscarGuiche(idGuiche);
            if (!guiche) {
                cout << "Guich� n�o encontrado.\n";
            } else {
                int senha = senhasGeradas.desenfileira();
                guiche->senhasAtendidas.enfileira(senha);
                cout << "Senha " << senha << " atendida pelo guich� " << idGuiche << ".\n";
            }
            break;
        }

        case 4: {
            int idGuiche;
            cout << "Digite o ID do guich�: ";
            cin >> idGuiche;
            Guiche* guiche = listaGuiches.buscarGuiche(idGuiche);
            if (!guiche) {
                cout << "Guich� n�o encontrado.\n";
            } else {
                cout << "Senhas atendidas pelo guich� " << idGuiche << ": ";
                guiche->senhasAtendidas.listar();
            }
            break;
        }

        default:
            cout << "Op��o inv�lida.\n";
        }

    } while (opcao != 0);

    return 0;
}
