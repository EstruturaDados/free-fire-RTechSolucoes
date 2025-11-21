#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.
#define MAX_ITENS 10
#define TAM_STRING 30

// Variáveis globais de controle
int numItens = 0;          // quantidade atual de itens na mochila
int comparacoes = 0;       // contador de comparações feitas em ordenações/buscas
bool ordenadaPorNome = false; // flag para saber se está ordenada por nome

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.
typedef struct {
    char nome[TAM_STRING];
    int tipo[TAM_STRING];
    int quantidade;
    int prioridade[]
} item;


int main() {
    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        limparTela();   // "limpa" a tela
        exibirMenu();   // mostra o menu com status
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &total);
                break;
            case 2:
                removerItem(mochila, &total);
                break;
            case 3:
                listarItens(mochila, total);
                break;
            case 4:
                menuDeOrdenacao(mochila, total);
                break;
            case 5: {
                char nomeBusca[TAM_STRING];
                printf("Digite o nome do item: ");
                scanf(" %[^\n]", nomeBusca);

                int pos = buscaBinariaPorNome(mochila, nomeBusca);
                if (pos != -1) {
                    printf("Item encontrado: %s | Tipo: %s | Qtd: %d | Prioridade: %d\n",
                           mochila[pos].nome, mochila[pos].tipo,
                           mochila[pos].quantidade, mochila[pos].prioridade);
                } else {
                    printf("Item não encontrado.\n");
                }
                break;
            }
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);


    return 0;
}



// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).
typedef enum {
    ORDENAR_NOME,
    ORDENAR_TIPO,
    ORDENAR_PRIORIDADE
} criterioOrdenacao;


// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).
void inserirItem(Item mochila[]) {
    if (numItens >= MAX_ITENS) {
        printf("\nMochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("\n=== Adicionar Item ===\n");
    printf("Nome: ");
    scanf(" %[^\n]", mochila[numItens].nome);

    printf("Tipo: ");
    scanf(" %[^\n]", mochila[numItens].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[numItens].quantidade);

    printf("Prioridade (1 a 5): ");
    scanf("%d", &mochila[numItens].prioridade);

    numItens++;
    ordenadaPorNome = false; 
    printf("Item adicionado com sucesso!\n");
}

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.
void limparTela() {
    for (int i = 0; i < 30; i++) {
        printf("\n");
    }
}

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.
void exibirMenu() {
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("Itens na mochila: %d/%d\n", numItens, MAX_ITENS);
    printf("Comparações realizadas: %d\n", comparacoes);
    printf("Ordenada por nome: %s\n", ordenadaPorNome ? "SIM" : "NÃO");
    printf("----------------------------\n");
    printf("1. Adicionar Item\n");
    printf("2. Remover Item\n");
    printf("3. Listar Itens\n");
    printf("4. Ordenar Itens\n");
    printf("5. Buscar Item por Nome\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}


// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".
// Função para adicionar um item
void inserirItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("\nMochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("\n=== Adicionar Item ===\n");
    printf("Nome: ");
    scanf(" %[^\n]", mochila[*total].nome);

    printf("Tipo: ");
    scanf(" %[^\n]", mochila[*total].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);

    (*total)++;
    printf("Item adicionado com sucesso!\n");
}

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.
void inserirItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("\nMochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("\n=== Adicionar Item ===\n");
    printf("Nome: ");
    scanf(" %[^\n]", mochila[*total].nome);

    printf("Tipo: ");
    scanf(" %[^\n]", mochila[*total].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);

    printf("Prioridade (1 a 5): ");
    scanf("%d", &mochila[*total].prioridade);

    (*total)++;
    printf("Item adicionado com sucesso!\n");
}

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.
void listarItens(Item mochila[], int total) {
    if (total == 0) {
        printf("\nMochila vazia!\n");
        return;
    }

    printf("\n=== Itens na Mochila ===\n");
    printf("%-20s %-15s %-10s %-10s\n", "Nome", "Tipo", "Qtd", "Prioridade");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%-20s %-15s %-10d %-10d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade,
               mochila[i].prioridade);
    }
}


// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).
void menuDeOrdenacao(Item mochila[], int total) {
    int opcao;
    printf("\n=== Ordenar Itens ===\n");
    printf("1. Por Nome\n");
    printf("2. Por Tipo\n");
    printf("3. Por Prioridade\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            insertionSort(mochila, total, ORDENAR_NOME);
            break;
        case 2:
            insertionSort(mochila, total, ORDENAR_TIPO);
            break;
        case 3:
            insertionSort(mochila, total, ORDENAR_PRIORIDADE);
            break;
        default:
            printf("Opção inválida!\n");
    }
}


// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)
void insertionSort(Item mochila[], int total, CriterioOrdenacao criterio) {
    for (int i = 1; i < total; i++) {
        Item chave = mochila[i];
        int j = i - 1;

        while (j >= 0) {
            int cmp = 0;
            if (criterio == ORDENAR_NOME)
                cmp = strcmp(mochila[j].nome, chave.nome);
            else if (criterio == ORDENAR_TIPO)
                cmp = strcmp(mochila[j].tipo, chave.tipo);
            else if (criterio == ORDENAR_PRIORIDADE)
                cmp = (mochila[j].prioridade - chave.prioridade);

            if (cmp > 0) {
                mochila[j + 1] = mochila[j];
                j--;
            } else {
                break;
            }
        }
        mochila[j + 1] = chave;
    }
    printf("\nItens ordenados com sucesso!\n");
}


// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
int buscaBinariaPorNome(Item mochila[], int total, const char* nome) {
    int inicio = 0, fim = total - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(mochila[meio].nome, nome);

        if (cmp == 0) {
            return meio; // Encontrado
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; // Não encontrado
}

