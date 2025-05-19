#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;

struct Funcionario {
    int prontuario;
    char nome[100];
    double salario;
};

Funcionario funcionarios[MAX];
int totalFuncionarios = 0;

// Função para verificar se prontuário já existe
int buscarProntuario(int prontuario) {
    for (int i = 0; i < totalFuncionarios; i++) {
        if (funcionarios[i].prontuario == prontuario) {
            return i;
        }
    }
    return -1;
}

// Incluir funcionário
void incluir() {
    if (totalFuncionarios >= MAX) {
        cout << "Limite máximo de funcionários atingido.\n";
        return;
    }

    int pront;
    cout << "Digite o prontuário: ";
    cin >> pront;

    if (buscarProntuario(pront) != -1) {
        cout << "Prontuário já cadastrado.\n";
        return;
    }

    funcionarios[totalFuncionarios].prontuario = pront;

    cin.ignore(); // limpar o buffer
    cout << "Digite o nome: ";
    cin.getline(funcionarios[totalFuncionarios].nome, 100);

    cout << "Digite o salário: ";
    cin >> funcionarios[totalFuncionarios].salario;

    totalFuncionarios++;
    cout << "Funcionário incluído com sucesso.\n";
}

// Excluir funcionário
void excluir() {
    int pront;
    cout << "Digite o prontuário do funcionário a excluir: ";
    cin >> pront;

    int pos = buscarProntuario(pront);
    if (pos == -1) {
        cout << "Funcionário não encontrado.\n";
        return;
    }

    for (int i = pos; i < totalFuncionarios - 1; i++) {
        funcionarios[i] = funcionarios[i + 1];
    }

    totalFuncionarios--;
    cout << "Funcionário excluído com sucesso.\n";
}

// Pesquisar funcionário
void pesquisar() {
    int pront;
    cout << "Digite o prontuário para pesquisa: ";
    cin >> pront;

    int pos = buscarProntuario(pront);
    if (pos == -1) {
        cout << "Funcionário não encontrado.\n";
        return;
    }

    cout << "Nome: " << funcionarios[pos].nome << endl;
    cout << "Salário: R$ " << funcionarios[pos].salario << endl;
}

// Listar todos os funcionários
void listar() {
    if (totalFuncionarios == 0) {
        cout << "Nenhum funcionário cadastrado.\n";
        return;
    }

    double totalSalarios = 0;

    for (int i = 0; i < totalFuncionarios; i++) {
        cout << "\nProntuário: " << funcionarios[i].prontuario << endl;
        cout << "Nome: " << funcionarios[i].nome << endl;
        cout << "Salário: R$ " << funcionarios[i].salario << endl;
        totalSalarios += funcionarios[i].salario;
    }

    cout << "\nTotal dos salários: R$ " << totalSalarios << endl;
}

// Menu principal
int main() {
    int opcao;

    do {
        cout << "\n--- MENU ---\n";
        cout << "0 - Sair\n";
        cout << "1 - Incluir\n";
        cout << "2 - Excluir\n";
        cout << "3 - Pesquisar\n";
        cout << "4 - Listar\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 0: cout << "Encerrando o programa.\n"; break;
            case 1: incluir(); break;
            case 2: excluir(); break;
            case 3: pesquisar(); break;
            case 4: listar(); break;
            default: cout << "Opcao inválida.\n";
        }

    } while(opcao != 0);

    return 0;
}
