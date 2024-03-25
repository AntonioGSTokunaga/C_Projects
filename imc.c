#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados_pessoais {
    char nome[50];
    char genero[10];
    int idade;
    float peso;
    float altura;
    float imc;
    struct dados_pessoais *prox;
};

// Função para editar os dados pessoais de uma pessoa
void editarDados(struct dados_pessoais *pessoa) {
    printf("Digite o novo nome: ");
    scanf(" %[^\n]", pessoa->nome);

    printf("Digite o novo g%cnero (M/F): ",136);
    scanf(" %[^\n]", pessoa->genero);

    printf("Digite a nova idade: ");
    scanf("%d", &pessoa->idade);

    printf("Digite o novo peso (em kg): ");
    scanf("%f", &pessoa->peso);

    printf("Digite a nova altura (em metros): ");
    scanf("%f", &pessoa->altura);

    // Recalcular o IMC após a edição dos dados
    pessoa->imc = pessoa->peso / (pessoa->altura * pessoa->altura);

    printf("Dados editados com sucesso!\n");
}

// Função para liberar a memória alocada para a lista encadeada
void liberarMemoria(struct dados_pessoais *head) {
    struct dados_pessoais *atual = head;
    while (atual != NULL) {
        struct dados_pessoais *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

int main() {
    struct dados_pessoais *head = NULL;
    struct dados_pessoais *tail = NULL;
    char opcao;
   
    do {
        printf("*************************MENU*************************\n\n\n");
        printf("1 - Cadastrar nova pessoa\n");
        printf("2 - Mostrar dados pessoais\n");
        printf("3 - Editar dados pessoais\n");
        printf("4 - Excluir registro\n");
        printf("5 - Sair\n");
        printf("Escolha uma op%c%co (1/2/3/4/5): ", 135, 198);
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                {
                    struct dados_pessoais *novo_registro = (struct dados_pessoais *)malloc(sizeof(struct dados_pessoais));
                   
                    if (novo_registro == NULL) {
                        printf("Erro na aloca%c%co de mem%cria.\n", 135, 198, 162);
                        return 1;
                    }
                            
                    printf("***********************CADASTRO***********************\n\n\n");
                   
                    printf("Nome: ");
                    scanf(" %[^\n]", novo_registro->nome);
       
                    printf("G%cnero (M/F): ", 136);
                    scanf(" %[^\n]", novo_registro->genero);
       
                    printf("Idade: ");
                    scanf("%d", &novo_registro->idade);
       
                    printf("Informe o seu peso (em kg): ");
                    scanf("%f", &novo_registro->peso);
       
                    printf("Informe a sua altura (em metros): ");
                    scanf("%f", &novo_registro->altura);
       
                    // Cálculo do IMC
                    novo_registro->imc = novo_registro->peso / (novo_registro->altura * novo_registro->altura);
                   
                    novo_registro->prox = NULL;
       
                    if (head == NULL) {
                        head = novo_registro;
                        tail = novo_registro;
                    } else {
                        tail->prox = novo_registro;
                        tail = novo_registro;
                    }
                }
                break;

            case '2':
                // Mostrar os dados registrados
                printf("\nDados Pessoais:\n");
                struct dados_pessoais *atual = head;

                while (atual != NULL) {
                    printf("Nome: %s\n", atual->nome);
                    printf("G%cnero: %s\n", 136, atual->genero);
                    printf("Idade: %d\n", atual->idade);
                    printf("Peso: %.2f kg\n", atual->peso);
                    printf("Altura: %.2f m\n", atual->altura);
                    printf("IMC: %.2f\n", atual->imc);
                    printf("\n");
                    atual = atual->prox;
                }
                break;

            case '3':
                // Editar os dados
                printf("Digite o n%cmero do registro a ser editado: ", 163);
                int num_registro;
                scanf("%d", &num_registro);

                struct dados_pessoais *editar = head;
                int contador = 1;
                while (contador < num_registro && editar != NULL) {
                    editar = editar->prox;
                    contador++;
                }

                if (editar != NULL) {
                    editarDados(editar);
                } else {
                    printf("Registro n%co encontrado.\n", 198);
                }
                break;

            case '4':
                // Excluir o registro
                printf("Digite o n%cmero do registro a ser exclu%cdo: ", 163, 161);
                int num_excluir;
                scanf("%d", &num_excluir);

                if (num_excluir == 1) {
                    struct dados_pessoais *excluir = head;
                    head = excluir->prox;
                    free(excluir);
                } else {
                    struct dados_pessoais *anterior = head;
                    struct dados_pessoais *excluir = head->prox;
                    int contador = 2;

                    while (excluir != NULL && contador < num_excluir) {
                        anterior = excluir;
                        excluir = excluir->prox;
                        contador++;
                    }

                    if (excluir != NULL) {
                        anterior->prox = excluir->prox;
                        free(excluir);
                    } else {
                        printf("Registro n%co encontrado.\n", 198);
                    }
                }
                break;

            case '5':
                // Sair do programa
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("Op%c%co inv%clida. Escolha uma op%c%co v%clida.\n", 135, 198, 160, 135, 198, 160);
                break;
        }
    } while (opcao != '5');

    // Liberar a memória alocada
    liberarMemoria(head);

    return 0;
}