#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void wait_enter(void) {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n');
}

int main(void) {
    //StudentArray arr;
    //init_student_array(&arr);

    int running = 1;
    while (running) {
        printf("\n=== Cadastro de Alunos ===\n");
        printf("1) Cadastrar aluno\n");
        printf("2) Listar alunos\n");
        printf("3) Buscar por ID\n");
        printf("4) Remover por ID\n");
        printf("5) Salvar em arquivo\n");
        printf("0) Sair\n");
        printf("Escolha: ");
    }
}
