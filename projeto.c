#include <stdio.h>
#include <stdlib.h>

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

//acho que ta certo
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

// aqui fiz a validacao da data fazendo com que o usuario desse outro input se nao valida, alem de que nao pensei em como fazer isso em um loop, uma vez que separei a data em dia, mes e ano, logo pode ser 1,2 ou 3 erros e nao um s[o]
int verifica_data(td_data *) {
    if (td_data->ano > 2025 || td_data->ano < 1900) {
        prinf("insira um ano válido: ");
        scanf("%d", &td_data->ano);
    }
    if (td_data->mes > 12 || td_data->mes < 1) {
        prinf("insira um mês válido: ");
        scanf("%d", &td_data->mes)
    }
    if (td_data->mes % 2 == 0) {
        if (td_data->mes == 2) {
            if (td_data->dia > 28 || td_data->dia < 1) {
                printf("insira um dia válido: ");
                scanf("%d", &td_data->dia);
            }
            else {
                if (td_data->dia > 30 || td_data->dia < 1) {
                    prinf("insira um dia válido: ");
                    scanf("%d", &td_data->dia);
                }
            }
        }
    }
    else {
        if (td_data->dia > 31 || td_data->dia < 1) {
            printf("insira um dia válido: ");
            scanf("%d", &td_data->dia);
        }
    }
}

// aqui pensei no jeito mais simples, validacao aepnas, return 0 se nao valida e 1 se valido, nesse caso deverei colocar na main um aviso de erro/pedir outrio input
int verifica_horario(td_hora *) {
    if (td_hora->hora < 0 || td_hora->hora >= 24) {
        return 0;
    }
    if (td_hora->min < 0 || td_hora->min >= 60) {
        return 0
    }
    return 1;
}



//come;ar daqui pra baixo
void cadastra compromisso(td_compromisso, int) {
    // devo usar ponteiro para apontar para o aluno? como faco isso

    printf("data do compromisso: (dia, mes, ano)"); 
    scanf("%d %d %d", &data->dia, &data->mes, &data->ano);

    printf("horario do compromisso: (hora, minutos)");
    scanf("%d %d", &hora->hora, &hora->min);
}

void imprime_vetor_de_alunos(td_aluno [], int) {
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