#include <iostream>
#include <iomanip>

using namespace std;

const int FILEIRAS = 15;
const int POLTRONAS	 = 40;

// Preços por fileira
float getSeatPrice(int fileira) {
    if (fileira >= 1 && fileira <= 5) return 50.0;
    if (fileira >= 6 && fileira <= 10) return 30.0;
    return 15.0;
}

void initializeSeats(bool poltrona[FILEIRAS][POLTRONAS]) {
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < POLTRONAS; j++) {
            poltrona[i][j] = false;
        }
    }
}

void printMap(bool lugares[FILEIRAS][POLTRONAS]) {
    cout << "\n Mapa de Ocupacao:\n";
    for (int i = 0; i < FILEIRAS; i++) {
        cout << "Fileira " << setw(2) << (i + 1) << ": ";
        for (int j = 0; j < POLTRONAS; j++) {
            cout << (lugares[i][j] ? '#' : '.');
        }
        cout << endl;
    }
}

void reserveSeat(bool poltrona[FILEIRAS][POLTRONAS], int &ocupado, float &vago) {
    int fila, lugar;
    cout << "\nDigite a fileira (1-15): ";
    cin >> fila;
    cout << "Digite a poltrona (1-40): ";
    cin >> lugar;

    if (fila < 1 || fila > 15 || lugar < 1 || lugar > 40) {
        cout << "Fileira ou poltrona invalida! Tente novamente.\n";
        return;
    }

    if (poltrona[fila - 1][lugar - 1]) {
        cout << "\n Poltrona ja ocupada!\n";
    } else {
        poltrona[fila - 1][lugar - 1] = true;
        ocupado++;
        vago += getSeatPrice(fila);
        cout << "\n Reserva efetuada com sucesso!\n";
    }
}

void printFaturamento(int ocupado, float vago) {
    cout << "\n Quantidade de lugares ocupados: " << ocupado << endl;
    cout << "Valor da bilheteria: R$ " << fixed << setprecision(2) << vago << endl;
}

int main() {
    bool lugares[FILEIRAS][POLTRONAS];
    int ocupado = 0;
    float vago = 0.0;
    int option;

    initializeSeats(lugares);

    do {
        cout << "\n Selecione uma opcao:\n";
        cout << "0 - Finalizar\n";
        cout << "1 - Reservar poltrona\n";
        cout << "2 - Mapa de ocupacao\n";
        cout << "3 - Faturamento\n";
        cout << "Opcao: ";
        cin >> option;

        switch (option) {
            case 0:
                cout << "\n Finalizando...\n";
                break;
            case 1:
                reserveSeat(lugares, ocupado, vago);
                break;
            case 2:
                printMap(lugares);
                break;
            case 3:
                printFaturamento(ocupado, vago);
                break;
            default:
                cout << "Opção invalida! Tente novamente.\n";
        }
    } while (option != 0);

    return 0;
}
