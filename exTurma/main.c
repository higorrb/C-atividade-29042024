#include <stdio.h>
#include <string.h>
#define ALUNO_MAX 50
#define TURMA_MAX 10

typedef struct{
    char id[3];
    char nome[ALUNO_MAX];
    char email[ALUNO_MAX];
    float nota_Algoritmo2;
    float nota_AlgoritmoProg;
    float nota_ArquiteturaComp;
    float nota_Algebra;
    float nota_AnaliseProj;
    float nota_Calculo;
    float nota_LabProg;
    float nota_Osm;
    float nota_PesquisaOp;
}estudante;

typedef struct{
    char curso[ALUNO_MAX];
    char turno[ALUNO_MAX];
    int unidade;
    estudante aluno[ALUNO_MAX];
    int numAlunos;
}grupo;

void addTurma(grupo *turma, int *indiceTurma)
{
    printf("Digite o curso: ");
    fgets(turma[*indiceTurma].curso, ALUNO_MAX, stdin );
    turma[*indiceTurma].curso[strcspn(turma[*indiceTurma].curso, "\n")] = '\0';
    printf("Digite o turno[Diuno/Noturno]: ");
    fgets(turma[*indiceTurma].turno, ALUNO_MAX, stdin );
    turma[*indiceTurma].turno[strcspn(turma[*indiceTurma].turno, "\n")] = '\0';
    printf("Digite a Unidade do curso: ");
    scanf("%d", &turma[*indiceTurma].unidade);
    fflush(stdin);
turma[*indiceTurma].numAlunos = 0;
(*indiceTurma)++;
}

void addAluno(grupo *turma, int opTurma)
{
    int indiceAluno = turma[opTurma].numAlunos;

    printf("~-~-~-~-~-~ADICIONAR ALUNO~-~-~-~-~-~\n");
    printf("Digite o ID do aluno(2B / 3B): ");
    scanf("%s", turma[opTurma].aluno[indiceAluno].id);
    getchar();

    printf("Digite o NOME do aluno: ");
    fgets(turma[opTurma].aluno[indiceAluno].nome, ALUNO_MAX, stdin );
    turma[opTurma].aluno[indiceAluno].nome[strcspn(turma[opTurma].aluno[indiceAluno].nome, "\n")] = '\0';

    printf("Digite o EMAIL do aluno: ");
    fgets(turma[opTurma].aluno[indiceAluno].email, ALUNO_MAX, stdin );
    turma[opTurma].aluno[indiceAluno].email[strcspn(turma[opTurma].aluno[indiceAluno].email, "\n")] = '\0';

    printf("=-=-=-=-=-=-NOTAS=-=-=-=-=-=-\n");
    printf("Algoritmos II: ");
    scanf("%f", &turma[opTurma].aluno[indiceAluno].nota_Algoritmo2);
    fflush(stdin);
    printf("Algoritmos e Programacao: ");
    scanf("%f", &turma[opTurma].aluno[indiceAluno].nota_AlgoritmoProg);
    fflush(stdin);
    printf("Arquitetura Computacional: ");
    scanf("%f", &turma[opTurma].aluno[indiceAluno].nota_ArquiteturaComp);
    fflush(stdin);
    printf("Algebra: ");
    scanf("%f", &turma[opTurma].aluno[indiceAluno].nota_Algebra);
    fflush(stdin);
    printf("Analise e Projeto estruturado II: ");
    scanf("%f", &turma[opTurma].aluno[indiceAluno].nota_AnaliseProj);
    fflush(stdin);
    printf("Calculo: ");
    scanf("%f", &turma[opTurma].aluno[indiceAluno].nota_Calculo);
    fflush(stdin);
    printf("Laboratorio de Programacao II: ");
    scanf("%f", &turma[opTurma].aluno[indiceAluno].nota_LabProg);
    fflush(stdin);
    printf("Organizacao Sistemas e Metodos: ");
    scanf("%f", &turma[opTurma].aluno[indiceAluno].nota_Osm);
    fflush(stdin);
    printf("Pesquisa Operacional: ");
    scanf("%f", &turma[opTurma].aluno[indiceAluno].nota_PesquisaOp);
    fflush(stdin);

turma[opTurma].numAlunos++;
}

void verTurma(grupo *turma, int opTurma){
    printf("\n-------------TURMA %d-------------\n", opTurma);
    printf("Curso__________%s\n", turma[opTurma].curso);
    printf("Turno__________%s\n", turma[opTurma].turno);
    printf("Unidade________%d\n", turma[opTurma].unidade);

    printf("\n-------------ALUNOS-------------\n");
    for (int i = 0; i < turma[opTurma].numAlunos; i++)
    {
        printf("\nALUNO %d\n", i);
        printf("ID____________%s\n", turma[opTurma].aluno[i].id);
        printf("Nome__________%s\n", turma[opTurma].aluno[i].nome);
        printf("Email_________%s\n", turma[opTurma].aluno[i].email);
        printf("=-=-=-=-=-=-=-=-NOTAS=-=-=-=-=-=-=-=-\n");
        printf("Algoritmos II_____________________%.2f\n", turma[opTurma].aluno[i].nota_Algoritmo2);
        printf("Algoritmos e Programacao__________%.2f\n", turma[opTurma].aluno[i].nota_AlgoritmoProg);
        printf("Arquitetura Computacional_________%.2f\n", turma[opTurma].aluno[i].nota_ArquiteturaComp);
        printf("Analise e Projeto estruturado II__%.2f\n", turma[opTurma].aluno[i].nota_AnaliseProj);
        printf("Calculo___________________________%.2f\n", turma[opTurma].aluno[i].nota_Calculo);
        printf("Laboratorio de Programacao II_____%.2f\n", turma[opTurma].aluno[i].nota_LabProg);
        printf("Organizacao Sistemas e Metodos____%.2f\n", turma[opTurma].aluno[i].nota_Osm);
        printf("Pesquisa Operacional______________%.2f\n", turma[opTurma].aluno[i].nota_PesquisaOp);
        
    }
}


int main()
{
    grupo turma[TURMA_MAX];
    int op = 0, opTurma = 0, indiceTurma = 0;
do{
printf("\n~~~~~~~~~~MENU~~~~~~~~~\n[1]-Adicionar Turma\n[2]-Adicionar aluno\n[3]-Ver Turma\n[0]-Sair\nDigite uma opcao: ");
scanf("%d", &op);
fflush(stdin);
switch(op)
{
case 1:
    if (indiceTurma < TURMA_MAX) {
        addTurma(turma, &indiceTurma);
    } else {
        printf("Limite de turmas atingido.\n");
    }
    break;

case 2:
    printf("Digite a turma em que deseja adicionar o aluno: ");
    scanf("%d", &opTurma);
    fflush(stdin);

    if (opTurma >= 0 && opTurma < indiceTurma) {
        addAluno(turma, opTurma);
    } else {
        printf("Turma inválida.\n");
    }
    break;

case 3:
    printf("Digite a turma de deseja visualizar: ");
    scanf("%d", &opTurma);
    fflush(stdin);

    if (opTurma >= 0 && opTurma < indiceTurma) {
        verTurma(turma, opTurma);
    } else {
        printf("Turma inválida.\n");
    }
    break;

case 0:
    break;

default:
    printf("\nEscolha invalida...\n");
    break;
}
}while(op != 0);

    return 0;
}