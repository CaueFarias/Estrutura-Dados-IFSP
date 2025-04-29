#include <iostream>
#include <cstring>
#include <ctime> // para pegar o ano do sistema
using namespace std;

// Classe Data
class Data {
private:
    int dia;
    int mes;
    int ano;
public:
    // Construtor padrão
    Data() {
        dia = 1;
        mes = 1;
        ano = 2000;
    }

    // Construtor com parâmetros
    Data(int d, int m, int a) {
        dia = d;
        mes = m;
        ano = a;
    }

    // Getters
    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAno() { return ano; }

    // Setters
    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAno(int a) { ano = a; }
};

// Classe Contato
class Contato {
private:
    char email[100];
    char nome[100];
    char telefone[20];
    Data dtnasc;
public:
    // Construtor padrão
    Contato() {
        strcpy(email, "");
        strcpy(nome, "");
        strcpy(telefone, "");
    }

    // Construtor com parâmetros
    Contato(const char* e, const char* n, const char* t, Data d) {
        strcpy(email, e);
        strcpy(nome, n);
        strcpy(telefone, t);
        dtnasc = d;
    }

    // Getters
    const char* getEmail() { return email; }
    const char* getNome() { return nome; }
    const char* getTelefone() { return telefone; }
    Data getDataNasc() { return dtnasc; }

    // Setters
    void setEmail(const char* e) { strcpy(email, e); }
    void setNome(const char* n) { strcpy(nome, n); }
    void setTelefone(const char* t) { strcpy(telefone, t); }
    void setDataNasc(Data d) { dtnasc = d; }

    // Método para calcular idade
    int idade() {
        time_t t = time(NULL);
        struct tm* now = localtime(&t);
        int anoAtual = now->tm_year + 1900;

        int idade = anoAtual - dtnasc.getAno();

        // Ajuste caso ainda não tenha feito aniversário no ano
        if ( (now->tm_mon + 1) < dtnasc.getMes() || 
             ((now->tm_mon + 1) == dtnasc.getMes() && now->tm_mday < dtnasc.getDia()) ) {
            idade--;
        }

        return idade;
    }
};

int main() {
    Contato contatos[5];
    int dia, mes, ano;
    char nome[100], email[100], telefone[20];

    // Cadastro dos 5 contatos
    for (int i = 0; i < 5; i++) {
        cout << "\nCadastro do Contato " << (i + 1) << endl;
        cout << "Nome: ";
        cin.getline(nome, 100);
        cout << "Email: ";
        cin.getline(email, 100);
        cout << "Telefone: ";
        cin.getline(telefone, 20);
        cout << "Data de Nascimento (dia mes ano): ";
        cin >> dia >> mes >> ano;
        cin.ignore(); // Limpar buffer do Enter
        
        Data d(dia, mes, ano);
        contatos[i] = Contato(email, nome, telefone, d);
    }

    // Exibição dos 5 contatos
    cout << "\n--- Lista de Contatos ---\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nContato " << (i + 1) << ":" << endl;
        cout << "Nome: " << contatos[i].getNome() << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Idade: " << contatos[i].idade() << " anos" << endl;
    }

    return 0;
}
