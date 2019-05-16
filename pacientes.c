#include <stdio.h>

typedef struct paciente{
    char *nome;
    int telefone;
    int grauUrgencia;
} Paciente;

void cadastrarPaciente(){}
Paciente* buscarPaciente(){}
Paciente* proximoPaciente(){}
int verificaTamanhoFila(){}
void removerPaciente(){}

void main(){

    int opcao;
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
    } while(opcao != 0 || opcao < 0 || opcao > 4);


}
