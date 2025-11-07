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

// o programa terá 5 territórios
//Criar uma Struct com o nome, cor e nº de tropas (será cada território)
//Criar um array para armazenar 5 territórios
//Após a inserção mostrar os dados inseridos
//Após a inserção dos 5 territórios mostrar msg de que já esta cheio e mostrar todos os territórios

// Estrutura dos Territórios
struct Territorios {
    char nome[];
    char cor[];
    int tropas;
};

//Função limpar Buffer
void limparBuff(){
    int c;
    while((c=getchar()) != '\n' && c != EOF);
}

// Função principal
int main() {

    struc Territorios territorio[];
    printf("========================================================================");
    printf("Vamos cadastrar os 5 territórios iniciais do nosso mundo.");

    int i=0;

    for(i=0; i<5; i++) {
        printf("---Cadastrando Território %d",i);
    }





    return 0;
}

