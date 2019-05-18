#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_paciente{
    char nome[50];
    int telefone;
    int grauUrgencia;
    struct nodo_paciente *prox;
} Paciente;

Paciente *criaPaciente() {
    Paciente *p;
    p = (Paciente *) malloc(sizeof(Paciente));

    if(!p) {
        printf("Problema de alocao");
        exit(0);
    }

    return p;
}


void cadastrarPaciente(Paciente **pacientes, char *nome, int telefone, int grauUrgencia){
    Paciente *paciente;
    paciente = criaPaciente();
    strcpy(paciente->nome, nome);
    paciente->grauUrgencia = grauUrgencia;
    paciente->telefone = telefone;
    paciente->prox = *pacientes;
    *pacientes = paciente;
}

void inicializaLista(Paciente **pacientes){
    *pacientes = NULL;
}

void imprimeLista(Paciente *pacientes){
Paciente *aux;
    int i, j;
    if(pacientes == NULL){
        printf("\n A lista esta vazia!!");
    }
    else{
        for(aux = pacientes; aux != NULL; aux = aux->prox){
            printf("%s ", aux->nome);
        }
    }
}
Paciente* buscarPaciente(Paciente *pacientes, char *nome){
Paciente *aux;
    int i, j;
    if(pacientes == NULL){
        printf("\n A lista esta vazia!!");
    }
    else{
        for(aux = pacientes; aux != NULL; aux = aux->prox){
            if(!strcmp(aux->nome, nome)){
                return aux;
            }
        }
    }

}
Paciente* proximoPaciente(){}
int verificaTamanhoFila(){}
void removerPaciente(){}

void main(){

    Paciente *pacientes, *paciente;
    inicializaLista(&pacientes);

    int telefone, grauUrgencia;
    char nome[50];


    int opcao;
    do{
        do{
            printf("\n*************************************");
            printf("\n*                                   *");
            printf("\n*   1. CADASTRAR PACIENTE           *");
            printf("\n*   2. BUSCAR PACIENTE              *");
            printf("\n*   3. PROXIMO PACIENTE             *");
            printf("\n*   4. VERIFICAR TAMANHO DA LISTA   *");
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
                cadastrarPaciente(&pacientes, nome, telefone, grauUrgencia);
                imprimeLista(pacientes);
            break;
            case 2:
                printf("Insira o nome do paciente a ser pesquisado: ");
                scanf("%s", &nome);
                paciente = buscarPaciente(pacientes, nome);
                if(!paciente){
                    printf("O paciente n existe");
                } else {
                    printf("\n nome: %s", paciente->nome);
                }

        }
    }while(opcao != 0);
}
