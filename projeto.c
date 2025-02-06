#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
        return 1;
    }
    if (td_hora->min < 0 || td_hora->min >= 60) {
        return 1;
    }
    return 0;
}



//come;ar daqui pra baixo
void cadastra_compromisso(td_compromisso, int) {
    // devo usar ponteiro para apontar para o aluno? como faco isso

    printf("data do compromisso: (dia, mes, ano)"); 
    scanf("%d %d %d", &data->dia, &data->mes, &data->ano);

    printf("horario do compromisso: (hora, minutos)");
    scanf("%d %d", &hora->hora, &hora->min);
}

void imprime_vetor_de_alunos(td_aluno [], int) {
    
}

// parte observacoes do .txt
int* alocarVetorAlunos(int tamanhoVetorAlunos) {
    int *vetor = (int*)malloc(tamanhoVetorAlunos * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    return vetor;
}

int* realocarVetorAlunos(int *vetor, int novoTamanhoVetorAlunos) {
    vetor = (int*)realloc(vetor, novoTamanhoVetorAlunos * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na realocação de memória!\n");
        exit(1);
    }
    return vetor;
}

int* alocarVetorCompromissos() {
    int *vetor = (int*)malloc(15 * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    return vetor;
}

int* realocarVetorCompromissos(int *vetor) {
    vetor = (int*)realloc(vetor, 5 * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na realocação de memória!\n");
        exit(1);
    }
    return vetor;
}

int main(void) {
    //lembrar de iniciar os vetores alunos e compromissos
    int tamanhoVetorAlunos = 10;
    int *vetorAlunos = alocarVetorAlunos(tamanhoVetorAlunos);
    int *vetorCompromissos = alocarVetorCompromissos();

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

    do {
        int opcao;
        char subopcao;
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                break;
            case 2:
                cadastra_aluno(vetorAlunos, 1);
                break;
            case 3:
                cadastra_compromisso(vetorCompromissos, 1);
                break;
            case 4:
                printf("   a - de um aluno                    - ordenado por data e hora\n"
                        "   b - de todos os alunos             - ordenado por RA, data e hora\n"
                        "   c - de uma data                    - ordenado por hora e RA\n"
                        "   d - de todas as datas              - ordenado por data, hora e RA\n");
                        scanf("%c", &subopcao);
                        subopcao = tolower(subopcao);
                        switch(subopcao) {
                            case 'a':
                                break;
                            case 'b':
                                break;
                            case 'c':
                                break;
                            case 'd':
                                break;
                        }
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                printf("saindo do programa...");
                break;
            default:
                return 1;
                break;
        }
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

    } while (opcao != 7);

    //lembrar de dar liberar a memorias dos vetores alunos e compromissos
    free(vetorAlunos);
    free(vetorCompromissos);

    return 0;
}