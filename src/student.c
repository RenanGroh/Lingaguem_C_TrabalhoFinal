/* Implementação das operações de StudentArray e I/O */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

static int ensure_capacity(StudentArray *arr, size_t min_capacity) {
    if (arr->capacity >= min_capacity) return 0;
    size_t newcap = arr->capacity ? arr->capacity * 2 : 4;
    while (newcap < min_capacity) newcap *= 2;
    Student *tmp = realloc(arr->data, newcap * sizeof(Student));
    if (!tmp) return -1;
    arr->data = tmp;
    arr->capacity = newcap;
    return 0;
}

void init_student_array(StudentArray *arr) {
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

void free_student_array(StudentArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int add_student(StudentArray *arr, const Student *s) {
    if (ensure_capacity(arr, arr->size + 1) != 0) return -1;
    arr->data[arr->size++] = *s;
    return 0;
}

void list_students(const StudentArray *arr) {
    if (arr->size == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    printf("\n-- Lista de Alunos (%zu) --\n", arr->size);
    for (size_t i = 0; i < arr->size; ++i) {
        print_student(&arr->data[i]);
    }
}

int find_student_index_by_id(const StudentArray *arr, int id) {
    for (size_t i = 0; i < arr->size; ++i) if (arr->data[i].id == id) return (int)i;
    return -1;
}

int remove_student_by_id(StudentArray *arr, int id) {
    int idx = find_student_index_by_id(arr, id);
    if (idx < 0) return 0;
    /* shift left */
    for (size_t i = idx; i + 1 < arr->size; ++i) arr->data[i] = arr->data[i+1];
    arr->size--;
    return 1;
}

void print_student(const Student *s) {
    printf("ID: %d | Nome: %s | Nota: %.2f\n", s->id, s->name, s->grade);
}

void prompt_student(Student *s) {
    /* Determine next ID by caller commonly, but if ID == 0 assign here */
    printf("Nome: ");
    if (!fgets(s->name, STUDENT_NAME_LEN, stdin)) s->name[0] = '\0';
    /* remover newline */
    size_t len = strlen(s->name);
    if (len && s->name[len-1] == '\n') s->name[len-1] = '\0';
    printf("Nota (0.0 - 10.0): ");
    if (scanf("%lf", &s->grade) != 1) s->grade = 0.0;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int load_students_from_file(StudentArray *arr, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) return -1; /* arquivo pode não existir */
    char line[512];
    while (fgets(line, sizeof(line), f)) {
        /* formato: id;name;grade\n */
        char *p = line;
        char *tok;
        tok = strtok(p, ";\n");
        if (!tok) continue;
        Student s = {0};
        s.id = atoi(tok);
        tok = strtok(NULL, ";\n");
        if (tok) strncpy(s.name, tok, STUDENT_NAME_LEN-1);
        tok = strtok(NULL, ";\n");
        if (tok) s.grade = atof(tok);
        add_student(arr, &s);
    }
    fclose(f);
    return 0;
}

int save_students_to_file(const StudentArray *arr, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) return -1;
    for (size_t i = 0; i < arr->size; ++i) {
        const Student *s = &arr->data[i];
        /* escapar ';' e '\n' no nome é tarefa simples: substituir por '_' */
        char name_safe[STUDENT_NAME_LEN];
        strncpy(name_safe, s->name, STUDENT_NAME_LEN-1);
        name_safe[STUDENT_NAME_LEN-1] = '\0';
        for (char *q = name_safe; *q; ++q) if (*q == ';' || *q == '\n') *q = '_';
        fprintf(f, "%d;%s;%.2f\n", s->id, name_safe, s->grade);
    }
    fclose(f);
    return 0;

}
