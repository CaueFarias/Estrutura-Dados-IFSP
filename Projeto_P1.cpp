#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

class Data {
private:
    int dia, mes, ano;
public:
    Data() { dia = 1; mes = 1; ano = 2000; }
    void setData(int d, int m, int a) { dia = d; mes = m; ano = a; }
    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAno() { return ano; }
};

class Contato {
private:
    char nome[100];
    char email[100];
    char telefone[20];
    Data dtnasc;
public:
   void preencher() {
    int d, m, a;
    char buffer[100]; // Buffer auxiliar para limpeza
    
    // Limpa buffer e lê nome
    printf("\nNome: ");
    fflush(stdin);
    gets(nome);
    
    // Lê email
    printf("Email: ");
    gets(email);
    
    // Lê telefone
    printf("Telefone: ");
    gets(telefone);

    // Validação da data
    while(1) {
        printf("Data de nascimento (DD MM AAAA): ");
        if(scanf("%d %d %d", &d, &m, &a) == 3) {
            // Limpa o buffer completamente
            while(getchar() != '\n');
            
            if(d >= 1 && d <= 31 && m >= 1 && m <= 12 && a >= 1900 && a <= 2023) {
                dtnasc.setData(d, m, a);
                break;
            } else {
                printf("Data invalida! Digite novamente.\n");
            }
        } else {
            // Limpa o buffer se a leitura falhou
            while(getchar() != '\n');
            printf("Formato invalido! Use DD MM AAAA.\n");
        }
    }
}
};

int main() {
    Contato contatos[100];
    int totalContatos = 0;
    int opcao;
    char buffer[100]; // Buffer auxiliar

    do {
        printf("\n=== MENU ===");
        printf("\n1. Adicionar contato");
        printf("\n2. Mostrar estatisticas");
        printf("\n0. Sair");
        printf("\nEscolha: ");
        
        if(scanf("%d", &opcao) != 1) {
            // Limpa completamente o buffer em caso de erro
            while(getchar() != '\n');
            printf("\nDigite apenas numeros!\n");
            continue;
        }
        // Limpa o buffer após scanf bem-sucedido
        while(getchar() != '\n');

        switch(opcao) {
            case 1:
                if(totalContatos < 100) {
                    contatos[totalContatos].preencher();
                    totalContatos++;
                    printf("\nContato adicionado! Total: %d\n", totalContatos);
                } else {
                    printf("\nLimite de 100 contatos atingido!\n");
                }
                break;
                
            // ... restante do código
        }
        
    } while(opcao != 0);

    return 0;
}