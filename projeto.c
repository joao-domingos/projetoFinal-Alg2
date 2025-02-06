#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} td_data;

typedef struct {
    int hora;
    int min;
} td_hora;

typedef struct{
    int codigo_dis;
    char disciplina[100];
    float notas[4];
    float media;
} td_disciplina;

typedef struct {
    int ra;
    char nome[100];
    td_data matrícula;
    td_disciplina disciplinas[4];
    char email[100];
} td_aluno;

typedef struct {
    td_aluno aluno;
    td_hora horario;
    td_data data;
    char descricao[300];
} td_compromisso;

void cadastra_aluno(td_aluno [], int) {
    printf("ra: ");
    scanf("%d", &td_aluno.ra);
    printf("nome do aluno: ");
    scanf("%s", td_aluno.nome);
    printf("dia, mes, ano: ");
    scanf("%d %d %d", matricula.dia, matricula.mes, matricula.ano);
    for(int i = 0; i < 4; i++) {
        printf("codigo disciplina: ");
        scanf("%d", disciplinas[i].codigo_dis);
        printf("nome disciplina: ");
        scanf("%s", disciplinas[i].disciplina);
        printf("nota 1, 2, 3 e 4: ")
        for(int j = 0; i < 4; j++) {
            scanf("%d", &disciplinas[i].notas[j]);
        }
        disciplinas[i].media = (notas[0] + notas[1] + notas[2] + notas[3]) / 4;
    }
}

int main(void) {

    printf("1 - cadastrar disciplina\n"
            "2 - cadastrar aluno\n"
            "3 - cadastrar compromisso\n"
            "4 - imprimir compromissos\n"
            "   a - de um aluno                    - ordenado por data e hora\n"
            "   b - de todos os alunos             - ordenado por RA, data e hora\n"
            "   c - de uma data                    - ordenado por hora e RA\n"
            "   d - de todas as datas              - ordenado por data, hora e RA\n"
            "5 - imprimir dados de um aluno\n"
            "6 - imprimir dados de todos os alunos  - ordenado por RA\n"
            "7 - sair\n");

    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            printf("saindo do programa...");
            return;
        default:
            break;
    }


    return 0;
}