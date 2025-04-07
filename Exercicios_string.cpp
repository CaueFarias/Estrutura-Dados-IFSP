#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <dos.h> // Para delay()
using namespace std;

void clearScreen() {
    system("cls");
}

// Exerc�cio 1: Cascata de letras
void exercicio1() {
    char mensagem[100];
    cout << "Digite uma mensagem: ";
    cin.getline(mensagem, 100);

    int len = strlen(mensagem);
    int col = (80 - len) / 2;

    for (int linha = 5; linha <= 20; linha++) {
        clearScreen();
        for (int i = 0; i < linha; i++) cout << endl;
        for (int j = 0; j < col; j++) cout << ' ';
        cout << mensagem << endl;
    }
}

// Exerc�cio 2: Verificar pal�ndromo
void exercicio2() {
    char mensagem[200], tratada[200], inversa[200];
    cout << "Digite uma mensagem: ";
    cin.getline(mensagem, 200);

    int k = 0;
    for (int i = 0; mensagem[i]; i++) {
        if (isalnum(mensagem[i])) {
            tratada[k++] = tolower(mensagem[i]);
        }
    }
    tratada[k] = '\0';

    // Inverter
    int len = strlen(tratada);
    for (int i = 0; i < len; i++) {
        inversa[i] = tratada[len - i - 1];
    }
    inversa[len] = '\0';

    if (strcmp(tratada, inversa) == 0)
        cout << "\nA mensagem � um pal�ndromo.\n";
    else
        cout << "\nA mensagem N�O � um pal�ndromo.\n";
}

// Exerc�cio 3: Agenda Telef�nica
void exercicio3() {
    ifstream arquivo("nomes.txt");
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo nomes.txt\n";
        return;
    }

    char linha[200];
    cout << "\nFormato Agenda Telef�nica:\n";
    while (arquivo.getline(linha, 200)) {
        char* palavras[10];
        int count = 0;
        char* token = strtok(linha, " ");
        while (token != NULL && count < 10) {
            palavras[count++] = token;
            token = strtok(NULL, " ");
        }
        if (count > 0) {
            cout << palavras[count - 1] << ", ";
            for (int i = 0; i < count - 1; i++) {
                cout << palavras[i];
                if (i < count - 2) cout << " ";
            }
            cout << endl;
        }
    }
    arquivo.close();
}

// Exerc�cio 4: Cita��o Bibliogr�fica
void exercicio4() {
    ifstream arquivo("nomes.txt");
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo nomes.txt\n";
        return;
    }

    char linha[200];
    cout << "\nFormato Cita��o Bibliogr�fica:\n";
    while (arquivo.getline(linha, 200)) {
        char* palavras[10];
        int count = 0;
        char* token = strtok(linha, " ");
        while (token != NULL && count < 10) {
            palavras[count++] = token;
            token = strtok(NULL, " ");
        }
        if (count > 0) {
            // Sobrenome em mai�sculo
            for (int i = 0; palavras[count - 1][i]; i++) {
                cout << (char)toupper(palavras[count - 1][i]);
            }
            cout << ", ";
            // Iniciais
            for (int i = 0; i < count - 1; i++) {
                cout << (char)toupper(palavras[i][0]) << ". ";
            }
            cout << endl;
        }
    }
    arquivo.close();
}

// Menu principal
int main() {
    int opcao;
    do {
        cout << "\nMenu de Exerc�cios:\n";
        cout << "1 - Cascata de Letras\n";
        cout << "2 - Verificar Pal�ndromo\n";
        cout << "3 - Formatar para Agenda Telef�nica\n";
        cout << "4 - Formatar para Cita��o Bibliogr�fica\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma op��o: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1: exercicio1(); break;
            case 2: exercicio2(); break;
            case 3: exercicio3(); break;
            case 4: exercicio4(); break;
            case 0: cout << "Saindo...\n"; break;
            default: cout << "Op��o inv�lida!\n";
        }
    } while (opcao != 0);

    return 0;
}
