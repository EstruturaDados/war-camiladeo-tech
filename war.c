#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

// Constantes
#define MAX_TERRITORIOS 5
#define MAX_NOME 50
#define MAX_COR 20

// o programa terá 5 territórios
//Criar uma Struct com o nome, cor e nº de tropas (será cada território)
//Criar um array para armazenar 5 territórios
//Após a inserção mostrar os dados inseridos
//Após a inserção dos 5 territórios mostrar msg de que já esta cheio e mostrar todos os territórios
// Nivel aventureiro
// Estrutura dos Territórios:
// Substituir o vetor estático por alocação dinâmica com calloc 
// Criar uma função para simular ataques entre dois territórios
// Utilizar números aleatórios para representar dados de batalha

typedef struct Territorio {
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int numTropas;
} Territorio;

//função para alocar memória
Territorio* alocarTerritorios(int quantidade){
    Territorio *ptr = calloc(quantidade, sizeof(Territorio));
    if(ptr == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    return ptr;
}

//Função de inicialização automática
void inicializarTerritorios(Territorio *territorios, int quantidade){
    const char *nomes[MAX_TERRITORIOS] = {"Brasil", "Argentina", "Chile", "Peru", "Uruguai"};
    const char *cores[MAX_TERRITORIOS] = {"Vermelho", "Azul", "Verde", "Amarelo", "Preto"};

    for(int i = 0; i < quantidade; i++){
        strcpy(territorios[i].nome, nomes[i]);
        strcpy(territorios[i].cor, cores[i]);
        territorios[i].numTropas = rand() % 6 + 5;
    }
}

//Função para mostrar o mapa
void mostrarMapa(const Territorio *territorios, int quantidade){
    printf("\n==========================\n");
    printf("Mapa do Mundo - Estado Atual\n");
    printf("==========================\n");
    for(int i = 0; i < quantidade; i++){
        printf("%dº Território\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].numTropas);
        printf("--------------------------\n");
    }
}

//Função de ataque
void atacar(Territorio *atacante, Territorio *defensor){
    if(atacante->numTropas <= 1){
        printf("Território atacante não possui tropas suficientes.\n");
        return;
    }

    int dadoA = rand() % 6 + 1;
    int dadoB = rand() % 6 + 1;

    printf("\n===== BATALHA =====\n");
    printf("Atacante: %s (%s) | Tropas: %d | Dado: %d\n",
           atacante->nome, atacante->cor, atacante->numTropas, dadoA);
    printf("Defensor: %s (%s) | Tropas: %d | Dado: %d\n",
           defensor->nome, defensor->cor, defensor->numTropas, dadoB);

    if (dadoA > dadoB) {
        if(defensor->numTropas > 0)
            defensor->numTropas--;

        printf("Resultado: %s venceu a batalha.\n", atacante->nome);

        if(defensor->numTropas == 0){
            printf("O território %s foi destruído!\n", defensor->nome);
        }
    } 
    else if (dadoB > dadoA) {
        if(atacante->numTropas > 0)
            atacante->numTropas--;

        printf("Resultado: %s venceu a batalha.\n", defensor->nome);
    } 
    else {
        printf("Resultado: Empate. Nenhuma tropa perdida.\n");
    }
}

//Sistema de Missões
int verificarMissaoDestruirVerde(const Territorio *territorios, int quantidade){
    for(int i = 0; i < quantidade; i++){
        if(strcmp(territorios[i].cor, "Verde") == 0 && territorios[i].numTropas > 0){
            return 0;
        }
    }
    return 1;
}

int verificarMissaoConquistarTres(const Territorio *territorios, int quantidade){
    int contador = 0;
    for(int i = 0; i < quantidade; i++){
        if(territorios[i].numTropas > 0)
            contador++;
    }
    return contador >= 3;
}

//Menu principal
int menu(){
    int opcao;
    printf("\n===== MENU =====\n");
    printf("1 - Atacar\n");
    printf("2 - Verificar Missão\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    return opcao;
}

// Função principal
int main() {
    srand(time(NULL));

    Territorio *territorios = alocarTerritorios(MAX_TERRITORIOS);
    inicializarTerritorios(territorios, MAX_TERRITORIOS);

    int missao = rand() % 2;

    if(missao == 0)
        printf("\nMISSÃO: Destruir completamente o exército Verde\n");
    else
        printf("\nMISSÃO: Conquistar pelo menos 3 territórios\n");

    int opcao;
    do{
        mostrarMapa(territorios, MAX_TERRITORIOS);
        opcao = menu();

        if(opcao == 1){
            int a, b;
            printf("Território atacante (1 a 5): ");
            scanf("%d", &a);
            printf("Território defensor (1 a 5): ");
            scanf("%d", &b);

            if(a >= 1 && a <= MAX_TERRITORIOS && b >= 1 && b <= MAX_TERRITORIOS && a != b){
                atacar(&territorios[a - 1], &territorios[b - 1]);
            } else {
                printf("Escolha inválida.\n");
            }
        }

        if(opcao == 2){
            int venceu = (missao == 0) ?
                verificarMissaoDestruirVerde(territorios, MAX_TERRITORIOS) :
                verificarMissaoConquistarTres(territorios, MAX_TERRITORIOS);

            if(venceu){
                printf("\nMISSÃO CUMPRIDA!\n");
                break;
            } else{
                printf("Missão ainda não cumprida.\n");
            }
        }

    } while(opcao != 0);

    free(territorios);
    return 0;
}