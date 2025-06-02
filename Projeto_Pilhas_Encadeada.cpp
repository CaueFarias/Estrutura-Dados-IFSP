#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* prox;
};

class PilhaEncadeada {
private:
    Node* topo;
public:
    PilhaEncadeada() { topo = NULL; }

    void push(int v) {
        Node* novo = new Node{v, topo};
        topo = novo;
    }

    void pop() {
        if (topo) {
            Node* temp = topo;
            topo = topo->prox;
            delete temp;
        }
    }

    bool vazia() {
        return topo == NULL;
    }

    void mostrar() {
        Node* aux = topo;
        while (aux) {
            cout << aux->valor << " ";
            aux = aux->prox;
        }
        cout << endl;
    }

    ~PilhaEncadeada() {
        while (!vazia()) pop();
    }
};

int main() {
    int numeros[30];
    PilhaEncadeada pilhaPar, pilhaImpar;
    int anterior = -999999;

    cout << "Digite 30 números inteiros em ordem crescente:\n";
    for (int i = 0; i < 30; i++) {
        int num;
        do {
            cout << "Numero " << i+1 << ": ";
            cin >> num;
        } while (num <= anterior); // garantir crescente

        numeros[i] = num;
        anterior = num;

        if (num % 2 == 0)
            pilhaPar.push(num);
        else
            pilhaImpar.push(num);
    }

    cout << "\nDesempilhando Pares (decrescente): ";
    pilhaPar.mostrar();

    cout << "Desempilhando Impares (decrescente): ";
    pilhaImpar.mostrar();

    return 0;
}
