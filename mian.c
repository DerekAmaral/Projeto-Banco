#include <stdio.h>
#include <string.h>

// Definição da estrutura Conta
typedef struct {
    int numero;
    char titular[100];
    float saldo;
} Conta;

// Função para criar uma nova conta
void criarConta(Conta contas[], int *numContas) {
    Conta novaConta;
    printf("Digite o numero da nova conta: ");
    scanf("%d", &novaConta.numero);
    printf("Digite o nome do titular: ");
    scanf(" %[^\n]", novaConta.titular);
    novaConta.saldo = 0.0;
    contas[*numContas] = novaConta;
    (*numContas)++;
    printf("Conta criada com sucesso!\n");
}

// Função para depositar dinheiro em uma conta
void depositar(Conta contas[], int numContas) {
    int numero;
    float valor;
    printf("Digite o numero da conta para deposito: ");
    scanf("%d", &numero);
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numero == numero) {
            printf("Digite o valor do deposito: ");
            scanf("%f", &valor);
            contas[i].saldo += valor;
            printf("Deposito realizado com sucesso!\n");
            return;
        }
    }
    printf("Conta nao encontrada!\n");
}

// Função para sacar dinheiro de uma conta
void sacar(Conta contas[], int numContas) {
    int numero;
    float valor;
    printf("Digite o numero da conta para saque: ");
    scanf("%d", &numero);
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numero == numero) {
            printf("Digite o valor do saque: ");
            scanf("%f", &valor);
            if (contas[i].saldo >= valor) {
                contas[i].saldo -= valor;
                printf("Saque realizado com sucesso!\n");
            } else {
                printf("Saldo insuficiente!\n");
            }
            return;
        }
    }
    printf("Conta nao encontrada!\n");
}

// Função para mostrar o saldo de uma conta
void mostrarSaldo(Conta contas[], int numContas) {
    int numero;
    printf("Digite o numero da conta para verificar o saldo: ");
    scanf("%d", &numero);
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numero == numero) {
            printf("Saldo da conta %d: %.2f\n", contas[i].numero, contas[i].saldo);
            return;
        }
    }
    printf("Conta nao encontrada!\n");
}

// Função para editar informações do titular de uma conta
void editarTitular(Conta contas[], int numContas) {
    int numero;
    printf("Digite o numero da conta para editar: ");
    scanf("%d", &numero);
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numero == numero) {
            printf("Digite o novo nome do titular: ");
            scanf(" %[^\n]", contas[i].titular);
            printf("Informacoes do titular atualizadas com sucesso!\n");
            return;
        }
    }
    printf("Conta nao encontrada!\n");
}

// Função para remover uma conta
void removerConta(Conta contas[], int *numContas) {
    int numero;
    printf("Digite o numero da conta para remover: ");
    scanf("%d", &numero);
    for (int i = 0; i < *numContas; i++) {
        if (contas[i].numero == numero) {
            for (int j = i; j < (*numContas) - 1; j++) {
                contas[j] = contas[j + 1];
            }
            (*numContas)--;
            printf("Conta removida com sucesso!\n");
            return;
        }
    }
    printf("Conta nao encontrada!\n");
}

// Função para transferir valor entre contas
void transferir(Conta contas[], int numContas) {
    int numeroOrigem, numeroDestino;
    float valor;
    printf("Digite o numero da conta de origem: ");
    scanf("%d", &numeroOrigem);
    printf("Digite o numero da conta de destino: ");
    scanf("%d", &numeroDestino);
    printf("Digite o valor da transferencia: ");
    scanf("%f", &valor);
    
    Conta *contaOrigem = NULL;
    Conta *contaDestino = NULL;
    
    for (int i = 0; i < numContas; i++) {
        if (contas[i].numero == numeroOrigem) {
            contaOrigem = &contas[i];
        }
        if (contas[i].numero == numeroDestino) {
            contaDestino = &contas[i];
        }
    }
    
    if (contaOrigem && contaDestino) {
        if (contaOrigem->saldo >= valor) {
            contaOrigem->saldo -= valor;
            contaDestino->saldo += valor;
            printf("Transferência realizada com sucesso!\n");
        } else {
            printf("Saldo insuficiente na conta de origem!\n");
        }
    } else {
        printf("Conta de origem ou destino nao encontrada!\n");
    }
}

// Função principal
int main() {
    Conta contas[100];
    int numContas = 0;
    int opcao;
    
    do {
        printf("\n----- Sistema Bancario -----\n");
        printf("1. Criar nova conta\n");
        printf("2. Depositar dinheiro\n");
        printf("3. Sacar dinheiro\n");
        printf("4. Mostrar saldo\n");
        printf("5. Editar informacoes do titular\n");
        printf("6. Remover conta\n");
        printf("7. Transferir valor\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                criarConta(contas, &numContas);
                break;
            case 2:
                depositar(contas, numContas);
                break;
            case 3:
                sacar(contas, numContas);
                break;
            case 4:
                mostrarSaldo(contas, numContas);
                break;
            case 5:
                editarTitular(contas, numContas);
                break;
            case 6:
                removerConta(contas, &numContas);
                break;
            case 7:
                transferir(contas, numContas);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while(opcao != 8);
    
    return 0;
}
