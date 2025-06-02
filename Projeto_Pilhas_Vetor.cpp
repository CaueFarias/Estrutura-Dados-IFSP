#include <iostream>
using namespace std;

class PilhaVetor {
private:
    int dados[30];
    int topo;
public:
    PilhaVetor() { topo = -1; }

    void push(int v) {
        if (topo < 29)
            dados[++topo] = v;
    }

    int pop() {
        if (topo >= 0)
            return dados[topo--];
        return -1; // erro
    }

    bool vazia() {
        return topo == -1;
    }

    void mostrar() {
        for (int i = topo; i >= 0; i--)
            cout << dados[i] << " ";
        cout << endl;
    }
};

int main() {
    int numeros[30];
    PilhaVetor pilhaPar, pilhaImpar;
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
