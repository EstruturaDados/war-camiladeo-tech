// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes
#define MAX_TERRITORIOS 5
#define MAX_NOME 50
#define MAX_COR 20

// o programa terá 5 territórios
//Criar uma Struct com o nome, cor e nº de tropas (será cada território)
//Criar um array para armazenar 5 territórios
//Após a inserção mostrar os dados inseridos
//Após a inserção dos 5 territórios mostrar msg de que já esta cheio e mostrar todos os territórios

// Estrutura dos Territórios
typedef struct Territorio {
    char nome[MAX_NOME];    //Nome do território (ex: "Brasil", "África do Sul")
    char cor[MAX_COR];      //Cor do exército
    int numTropas;          //Nº de tropas
} Territorio;

//Função limpar Buffer
void limparBuff(){
    int c;
    while((c=getchar()) != '\n' && c != EOF);
}

// Função principal
int main() {

    struct Territorio territorios[MAX_TERRITORIOS];
    int i;

    printf("===================================================\n");
    printf("\n Vamos cadastrar os 5 territórios iniciais do nosso mundo.\n");

    for(i=0; i<MAX_TERRITORIOS; i++) {
        printf("\n---Cadastrando o Território nº %d\n",i+1);
        printf("Nome do território: ");
        scanf(" %[^\n]", territorios[i].nome);  // lê string com espaços

        printf("Cor do exécito: ");
        scanf(" %[^\n]", territorios[i].cor);

        printf("Número de tropas: ");
        scanf("%d", &territorios[i].numTropas);
        printf("\n");
    }

    // Mostrar os territórios cadastrados
    printf("\n==========================\n");
    printf("\nMapa do Mundo - Estado Atual\n");
    printf("Territórios cadastrados:\n ");
    printf("\n==========================\n");
    for(i=0; i<MAX_TERRITORIOS; i++) {
        printf("\n%dº Território: \n",i+1);
        printf("Nome do território: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Número de tropas: %d", territorios[i].numTropas);
        printf("\n==========================\n");
    }

    limparBuff();
    
    return 0;
}

