#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

static void wait_enter(void) {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n');
}

// Gerar um novo ID para um novo aluno
static int next_id(const StudentArray *arr) {
    int max = 0;
    for (size_t i = 0; i < arr->size; ++i) if (arr->data[i].id > max) max = arr->data[i].id;
    return max + 1;
}

int main(void) {
    StudentArray arr;
    init_student_array(&arr);

    int running = 1;
    //loop principal
    while (running) {
        printf("\n=== Cadastro de Alunos ===\n");
        printf("1) Cadastrar aluno\n");
        printf("2) Listar alunos\n");
        printf("3) Buscar por ID\n");
        printf("4) Remover por ID\n");
        printf("5) Salvar em arquivo\n");
        printf("0) Sair\n");
        printf("Escolha: ");

        // Le um inteiro (opção)
        int opt;
        if (scanf("%d", &opt) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        int c = getchar();

        //Logica das opções
        switch (opt) {
            case 1: {
                Student s = {0};
                s.id = next_id(&arr);
                prompt_student(&s);
                if (add_student(&arr, &s) != 0) printf("Erro ao adicionar aluno\n");
                else printf("Aluno cadastrado (ID %d)\n", s.id);
                break;
            }
            case 2:
                list_students(&arr);
                break;
            case 3: {
                printf("ID para buscar: ");
                int id;
                if (scanf("%d", &id) == 1) {
                    int idx = find_student_index_by_id(&arr, id);
                    if (idx >= 0) print_student(&arr.data[idx]);
                    else printf("Aluno com ID %d nao encontrado\n", id);
                }
                while ((c = getchar()) != '\n' && c != EOF);
                break;
            }
            case 4: {
                printf("ID para remover: ");
                int id;
                if (scanf("%d", &id) == 1) {
                    if (remove_student_by_id(&arr, id)) printf("Removido aluno %d\n", id);
                    else printf("Aluno %d nao encontrado\n", id);
                }
                while ((c = getchar()) != '\n' && c != EOF);
                break;
            }
            case 5:
                // TODO: implementar save em arquivo
                break;
            case 0:
                running = 0;
                break;
            default:
                printf("Opcao invalida\n");
        }
        if (running) wait_enter();
    }

}
