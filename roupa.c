#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char tipo_roupa[50];
    char cor[20];
    char tamanho[10];
} Cliente;

void cadastrarCliente(Cliente **clientes, int *numClientes, int *capacidade);
void listarClientes(Cliente *clientes, int numClientes);
void editarCliente(Cliente *clientes, int numClientes);
void excluirCliente(Cliente *clientes, int *numClientes);
void liberarMemoria(Cliente *clientes);

int main() {
    Cliente *clientes = NULL;  // Ponteiro para registros de cliente
    int numClientes = 0;      // Número atual de clientes
    int capacidade = 0;       // Capacidade atual do array

    int opcao;

    // Menu
    while (1) {
        printf("\nSelecione uma op%c%co:\n", 135, 198);
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Editar cliente\n");
        printf("4. Excluir cliente\n");
        printf("5. Sair\n");

        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            printf("Entrada inv%clida. Por favor, insira um n%cmero.\n", 160, 163);
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrarCliente(&clientes, &numClientes, &capacidade);
                break;
            case 2:
                listarClientes(clientes, numClientes);
                break;
            case 3:
                editarCliente(clientes, numClientes);
                break;
            case 4:
                excluirCliente(clientes, &numClientes);
                break;
            case 5:
                liberarMemoria(clientes);
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opção inv%clida. Tente novamente.\n", 160);
        }
    }

    return 0;
}

void cadastrarCliente(Cliente **clientes, int *numClientes, int *capacidade) {
    Cliente novoCliente;

    if (*numClientes >= *capacidade) {
        // Se o número de clientes atingiu a capacidade atual,
        // realoca a memória para acomodar mais registros.
        *capacidade = (*capacidade == 0) ? 1 : *capacidade * 2;
        *clientes = (Cliente *)realloc(*clientes, *capacidade * sizeof(Cliente));

        if (*clientes == NULL) {
            // Verifica se a realocação de memória falhou.
            printf("Erro ao alocar mem%cria para clientes.\n", 162);
            return;
        }
    }

    printf("Nome do cliente: ");
    scanf(" %[^\n]s", novoCliente.nome);
    printf("Tipo de roupa: ");
    scanf(" %[^\n]s", novoCliente.tipo_roupa);
    printf("Cor: ");
    scanf(" %[^\n]s", novoCliente.cor);
    printf("Tamanho: ");
    scanf(" %[^\n]s", novoCliente.tamanho);

    (*clientes)[*numClientes] = novoCliente;
    (*numClientes)++;

    printf("Cliente cadastrado com sucesso!\n");
}

void listarClientes(Cliente *clientes, int numClientes) {
    if (numClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
    } else {
        printf("Lista de clientes:\n");
        for (int i = 0; i < numClientes; i++) {
            printf("Cliente %d\n", i + 1);
            printf("Nome: %s\n", clientes[i].nome);
            printf("Tipo de roupa: %s\n", clientes[i].tipo_roupa);
            printf("Cor: %s\n", clientes[i].cor);
            printf("Tamanho: %s\n", clientes[i].tamanho);
            printf("\n");
        }
    }
}

void editarCliente(Cliente *clientes, int numClientes) {
    if (numClientes == 0) {
        printf("Nenhum cliente cadastrado para editar.\n");
    } else {
        int clienteID;
        printf("Digite o n%cmero do cliente que deseja editar (1 a %d): ", 163, numClientes);
        scanf("%d", &clienteID);

        if (clienteID < 1 || clienteID > numClientes) {
            printf("N%cmero de cliente inv%clido.\n", 163, 160);
        } else {
            Cliente *cliente = &clientes[clienteID - 1];
            printf("Editar informa%c%ces do cliente %d:\n", 135, 228, clienteID);
            printf("Nome do cliente: ");
            scanf(" %[^\n]s", cliente->nome);
            printf("Tipo de roupa: ");
            scanf(" %[^\n]s", cliente->tipo_roupa);
            printf("Cor: ");
            scanf(" %[^\n]s", cliente->cor);
            printf("Tamanho: ");
            scanf(" %[^\n]s", cliente->tamanho);
            printf("Cliente editado com sucesso!\n");
        }
    }
}

void excluirCliente(Cliente *clientes, int *numClientes) {
    if (*numClientes == 0) {
        printf("Nenhum cliente cadastrado para excluir.\n");
    } else {
        int clienteID;
        printf("Digite o n%cmero do cliente que deseja excluir (1 a %d): ", 163, *numClientes);
        scanf("%d", &clienteID);

        if (clienteID < 1 || clienteID > *numClientes) {
            printf("N%cmero de cliente inv%clido.\n", 163, 160);
        } else {
            // Move os registros para preencher o espaço do registro excluído.
            for (int i = clienteID - 1; i < *numClientes - 1; i++) {
                clientes[i] = clientes[i + 1];
            }
            (*numClientes)--;
            printf("Cliente exclu%cdo com sucesso!\n", 161);
        }
    }
}

void liberarMemoria(Cliente *clientes) {
    // Libera a memória alocada para o array de clientes.
    free(clientes);
}
