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
void cadastra_aluno(td_aluno alunos[], int *quantidade) {
    td_aluno novo_aluno;
    printf("ra: ");
    scanf("%d", &novo_aluno.ra);
    printf("nome do aluno: ");
    scanf("%s", novo_aluno.nome);
    printf("email: ");
    scanf("%s", novo_aluno.email);
    //
    
    for(int i = 0; i < 4; i++) {
        printf("codigo disciplina: ");
        scanf("%d", &novo_aluno.disciplinas[i].codigo_dis);
        printf("nome disciplina: ");
        scanf("%s", novo_aluno.disciplinas[i].disciplina);
        printf("nota 1, 2, 3 e 4: ");
        float soma_notas;
        for(int j = 0; i < 4; j++) {
            scanf("%d", &novo_aluno.disciplinas[i].notas[j]);
            soma_notas += novo_aluno.disciplinas[i].notas[j];
        }
        novo_aluno.disciplinas[i].media = soma_notas / 4;
    }
    alunos[*quantidade] = novo_aluno;
    (*quantidade)++;
}

// aqui fiz a validacao da data fazendo com que o usuario desse outro input se nao valida, alem de que nao pensei em como fazer isso em um loop, uma vez que separei a data em dia, mes e ano, logo pode ser 1,2 ou 3 erros e nao um s[o]
int verifica_data(td_data *data) {
    while (data->dia < 1 || data->dia > 31 || data->mes < 1 || data->mes > 12 || data->ano < 1900) {
        printf("Data inválida! Digite novamente (dd mm aaaa): ");
        scanf("%d %d %d", &data->dia, &data->mes, &data->ano);
    }
    return 1;
}

// aqui pensei no jeito mais simples, validacao aepnas, return 0 se nao valida e 1 se valido, nesse caso deverei colocar na main um aviso de erro/pedir outrio input
int verifica_horario(td_hora *horario) {
    while (horario->hora < 0 || horario->hora > 23 || horario->min < 0 || horario->min > 59) {
        printf("Horário inválido! Digite novamente (hh mm): ");
        scanf("%d %d", &horario->hora, &horario->min);
    }
    return 1;
}



//come;ar daqui pra baixo
void cadastra_compromisso(td_compromisso compromissos[], int *quantidade) {
    td_compromisso novo_compromisso;
    printf("Data do compromisso (dia mes ano): ");
    scanf("%d %d %d", &novo_compromisso.data.dia, &novo_compromisso.data.mes, &novo_compromisso.data.ano);
    verifica_data(&novo_compromisso.data);

    printf("Horário do compromisso (hora minutos): ");
    scanf("%d %d", &novo_compromisso.horario.hora, &novo_compromisso.horario.min);
    verifica_horario(&novo_compromisso.horario);

    printf("Descrição do compromisso: ");
    scanf("%s", novo_compromisso.descricao);
    
    compromissos[*quantidade] = novo_compromisso;
    (*quantidade)++;
}

void imprime_vetor_de_alunos(td_aluno alunos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("RA: %d\nNome: %s\nEmail: %s\nData de Matrícula: %02d/%02d/%04d\n", 
               alunos[i].ra, alunos[i].nome, alunos[i].email);
        for (int j = 0; j < 4; j++) {
            printf("  Disciplina %d: %s (Código: %d)\n  Notas: %.2f, %.2f, %.2f, %.2f - Média: %.2f\n", 
                   j + 1, alunos[i].disciplinas[j].disciplina, alunos[i].disciplinas[j].codigo_dis,
                   alunos[i].disciplinas[j].notas[0], alunos[i].disciplinas[j].notas[1],
                   alunos[i].disciplinas[j].notas[2], alunos[i].disciplinas[j].notas[3],
                   alunos[i].disciplinas[j].media);
        }
        printf("--------------------------\n");
    }
}

void imprime_vetor_de_compromissos(td_compromisso compromissos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Data: %02d/%02d/%04d\nHorário: %02d:%02d\nDescrição: %s\nAluno: %s (RA: %d)\n", 
               compromissos[i].data.dia, compromissos[i].data.mes, compromissos[i].data.ano,
               compromissos[i].horario.hora, compromissos[i].horario.min,
               compromissos[i].descricao, compromissos[i].aluno.nome, compromissos[i].aluno.ra);
        printf("--------------------------\n");
    }
}

// parte observacoes do .txt
td_aluno* alocarVetorAlunos(int tamanhoVetorAlunos) {
    td_aluno *vetor = (td_aluno*)malloc(tamanhoVetorAlunos * sizeof(td_aluno));
    if (vetor == NULL) {
        printf("erro na alocação de memória!\n");
        exit(1);
    }
    return vetor;
}

td_aluno* realocarVetorAlunos(td_aluno *vetor, int novoTamanhoVetorAlunos) {
    vetor = (td_aluno*)realloc(vetor, novoTamanhoVetorAlunos * sizeof(td_aluno));
    if (vetor == NULL) {
        printf("erro na realocação de memória!\n");
        exit(1);
    }
    return vetor;
}

td_compromisso* alocarVetorCompromissos(int tamanhoVetorCompromisso) {
    td_compromisso *vetor = (td_compromisso*)malloc(tamanhoVetorCompromisso * sizeof(td_compromisso));
    if (vetor == NULL) {
        printf("erro na alocação de memória!\n");
        exit(1);
    }
    return vetor;
}

td_compromisso* realocarVetorCompromissos(td_compromisso *vetor, int novoTamanhoVetorCompromisso) {
    vetor = (td_compromisso*)realloc(vetor, 5 * sizeof(td_compromisso));
    if (vetor == NULL) {
        printf("erro na realocação de memória!\n");
        exit(1);
    }
    return vetor;
}

int main(void) {
    //lembrar de iniciar os vetores alunos e compromissos
    int num_alunos = 0, capacidade_alunos = 10;
    int num_compromissos = 0, capacidade_compromissos = 15;
    td_aluno *alunos = alocarVetorAlunos(capacidade_alunos);
    td_compromisso *compromissos = alocarVetorCompromissos(capacidade_compromissos);

    int opcao;
    do {

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

        char subopcao;
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            printf("cadastrar disciplina indisponivel\n");
                break;
            case 2:
                if (num_alunos == capacidade_alunos) {
                    capacidade_alunos += 10;
                    alunos = realocarVetorAlunos(alunos, capacidade_alunos * sizeof(td_aluno));
                }
                cadastra_aluno(alunos, &num_alunos);
                break;
            case 3:
                if (num_compromissos == capacidade_compromissos) {
                    capacidade_compromissos += 5;
                    compromissos =  realocarVetorCompromissos(compromissos, capacidade_compromissos * sizeof(td_compromisso));
                }
                cadastra_compromisso(compromissos, &num_compromissos);
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
                imprime_vetor_de_alunos(alunos, num_alunos);
                break;
            case 6:
               imprime_vetor_de_compromissos(compromissos, num_compromissos);
                break;
            case 7:
                printf("saindo do programa...");
                break;
            default:
                printf("opcao invalida");
        }

    } while (opcao != 7);

    //lembrar de dar liberar a memorias dos vetores alunos e compromissos
    free(alunos);
    free(compromissos);

    return 0;
}