# Gerenciamento de Alunos - Algoritmos 2

Este repositório contém o projeto final da disciplina de **Algoritmos 2** da **UTFPR - Câmpus Cornélio Procópio** pelo Professor **Gabriel Canhadas Genvigir**. O projeto implementa um **Sistema de Gerenciamento de Alunos** em linguagem **C**, abordando conceitos como **ponteiros, alocação dinâmica de memória e recursividade**.

---

## Funcionalidades

O programa permite:

- **Cadastro de alunos** com matrícula, disciplinas, notas e média calculada automaticamente;
- **Validação de datas e horários** para garantir entradas válidas;
- **Cadastro e gerenciamento de compromissos**, assegurando que um aluno não tenha mais de dois compromissos no mesmo dia ou com horários sobrepostos;
- **Ordenação e impressão de alunos e compromissos** utilizando a função `qsort` para organização eficiente dos dados;
- **Alocação dinâmica** dos vetores de alunos e compromissos, garantindo expansão conforme necessidade.

---

## Funcionalidades Implementadas

1. **Cadastro de Alunos**:

   - Cada aluno deve cursar pelo menos 4 disciplinas;
   - Cada disciplina possui 4 notas e cálculo automático da média;
   - Função: `void cadastra_aluno(td_aluno [], int);`

2. **Validação de Data**:

   - Apenas datas válidas são aceitas;
   - Função: `int verifica_data(td_data *);`

3. **Validação de Horário**:

   - Apenas horários válidos são aceitos;
   - Função: `int verifica_horario(td_hora *);`

4. **Cadastro de Compromissos**:

   - Cada aluno pode ter no máximo dois compromissos por data;
   - Os horários de compromissos não podem se sobrepor;
   - Função: `void cadastra_compromisso(td_compromisso [], int);`

5. **Impressão de Alunos**:

   - Ordenado por RA utilizando `qsort`;
   - Função: `void imprime_vetor_de_alunos(td_aluno [], int);`

6. **Alocação Dinâmica de Vetores**:

   - Vetor de alunos inicialmente com 10 espaços, realocado em blocos de 10;
   - Vetor de compromissos inicialmente com 15 espaços, realocado em blocos de 5;

7. **Ordenação de Dados com **``:

   - Alunos são ordenados por RA;
   - Compromissos podem ser ordenados por data, hora e RA.


