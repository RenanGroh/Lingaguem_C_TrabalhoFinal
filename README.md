# Sistema de Cadastro de Alunos (C)

Breve aplicação em C para cadastrar, listar, buscar, remover e salvar alunos em arquivo. Foco em alocação dinâmica, ponteiros e I/O em arquivos.

## Funcionalidades

- Cadastrar aluno (nome, nota)
- Listar todos os alunos
- Buscar aluno por ID
- Remover aluno por ID
- Salvar/carregar registros em arquivo (`students.txt`)

## Arquivos principais

- [src/main.c](src/main.c) — fluxo principal e menu.
- [src/student.c](src/student.c) — implementação das operações sobre alunos.
- [include/students.h](include/students.h) — definições de tipos e protótipos (contém [`Student`](include/students.h) e [`StudentArray`](include/students.h)).
- [students.txt](students.txt) — arquivo de dados gerado/consumido pelo programa.

## Formato de dados

Cada linha em `students.txt` segue o formato:
id;nome;nota

O programa trata caracteres especiais no nome para não quebrar o formato.

## Estruturas (resumido)

- [`Student`](include/students.h): contem id, nome e nota.
- [`StudentArray`](include/students.h): array dinâmico com campos data, size e capacity.

## Como compilar

Requer um compilador C (GCC / MinGW / MSVC).

Linux / macOS (GCC):

```sh
gcc -Iinclude -o student_app.exe src/*c
```
