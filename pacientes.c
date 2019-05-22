#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo_paciente{
    char nome[50];
    int telefone;
    int grauUrgencia;
    struct nodo_paciente *prox;
} Paciente, *PONT;

typedef struct fila{
    int quantidade;
    PONT inicio, fim;
} Fila;


Paciente* criaPaciente() {
    Paciente *p;
    p = (Paciente*) malloc(sizeof(Paciente));

    if(!p) {
        printf("Problema de alocao");
        exit(0);
    }

    return p;
}

void inicializaFila(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->quantidade = 0;
}

void exibirFila(Fila *fila){
    PONT paciente = fila->inicio;
    while(paciente != NULL){
        printf("\nNome: %s", paciente->nome);
        paciente = paciente->prox;
    }
}

void cadastrarPaciente(Fila *fila, char *nome, int telefone, int grauUrgencia){
    PONT paciente = criaPaciente();
    strcpy(paciente->nome, nome);
    paciente->grauUrgencia = grauUrgencia;
    paciente->telefone = telefone;
    paciente->prox = NULL;

    if(fila->inicio == NULL){
        fila->inicio = paciente;
    } else {
        fila->fim->prox = paciente;
    }
    fila->fim = paciente;
    fila->quantidade++;
}
void removerDaFila(Fila *fila){
    if(fila->inicio == NULL){
        return;
    }
    PONT paciente = fila->inicio;
    fila->inicio = fila->inicio->prox;
    free(paciente);
    if(fila->inicio == NULL){
        fila->fim = NULL;
    }
    fila->quantidade--;
}
PONT proximoLista(Fila *fila){
    if(fila->inicio == NULL){
        printf("A lista esta vazia. Nao ha proximo paciente.");
        return;
    }
    PONT proxFila = fila->inicio;
    printf("\n---------------------------\n");
    printf("Nome: %s", proxFila->nome);
    printf("\nTelefone: %d", proxFila->telefone);
    printf("\nGrau de urgencia: %d", proxFila->grauUrgencia);
    printf("\n---------------------------\n");
    return proxFila;
}

int buscarPaciente(Fila *fila, char *nome){
    PONT paciente = fila->inicio;
    int achou = 0, posicao = 1;
    while(paciente != NULL){
        if(strcmp(paciente->nome, nome) == 0){
            printf("\nNome: %s", paciente->nome);
            printf("\nTelefone: %d", paciente->telefone);
            printf("\nGrau de urgencia: %d", paciente->grauUrgencia);
            printf("\nPosicao: %d", posicao);
           return 1;
        }
        paciente = paciente->prox;
        posicao++;
    }
    if(achou == 0){
        return 0;
    }
}

void escreverArquivo(PONT paciente, FILE *arquivo){
    arquivo = fopen ("pacientes-operados.txt", "a");
    if (!arquivo) {
         printf ("Erro na abertura do arquivo. Fim de programa.");
         exit (1);
    }
    fprintf(arquivo, "\n------------------------", paciente->nome);
    fprintf(arquivo, "\n %s", paciente->nome);
    fprintf(arquivo, "\n %d", paciente->telefone);
    fclose(arquivo);
}

void main(){

    FILE *fp;
    Fila fila;
    inicializaFila(&fila);
    int telefone, grauUrgencia; char nome[50]; PONT paciente;
    int opcao;

    do{
        do{
            printf("\n*************************************");
            printf("\n*                                   *");
            printf("\n*   1. CADASTRAR PACIENTE           *");
            printf("\n*   2. BUSCAR PACIENTE              *");
            printf("\n*   3. PROXIMO PACIENTE             *");
            printf("\n*   4. VERIFICAR TAMANHO DA FILA    *");
            printf("\n*   0. SAIR                         *");
            printf("\n*                                   *");
            printf("\n*************************************\n");
            scanf("%d", &opcao);
        } while(opcao < 0 || opcao > 4);

        switch(opcao){
            case 1:
                printf("Insira o nome do paciente: ");
                scanf("%s", &nome);
                printf("Insira o telefone do paciente: ");
                scanf("%d", &telefone);
                printf("Insira o grau de urgencia do paciente: ");
                scanf("%d", &grauUrgencia);
                cadastrarPaciente(&fila, nome, telefone, grauUrgencia);
                exibirFila(&fila);
            break;
            case 2:
                printf("Insira o nome do paciente a ser pesquisado: ");
                scanf("%s", &nome);
                if(!buscarPaciente(&fila, nome)){
                    printf("O paciente nao se encontra na fila.");
                }
            break;
            case 3:
                paciente = proximoLista(&fila);
                escreverArquivo(paciente, fp);
                removerDaFila(&fila);
                exibirFila(&fila);
            break;
            case 4:
                printf("Tamanho da fila: %d", fila.quantidade);
            break;
        }

    }while(opcao != 0);
}
