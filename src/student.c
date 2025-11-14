/* Implementação das operações de StudentArray e I/O */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

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
}

int add_student(StudentArray *arr, const Student *s) {
}

void list_students(const StudentArray *arr) {
}

int find_student_index_by_id(const StudentArray *arr, int id) {
}

int remove_student_by_id(StudentArray *arr, int id) {
}

void print_student(const Student *s) {
    printf("ID: %d | Nome: %s | Nota: %.2f\n", s->id, s->name, s->grade);
}

void prompt_student(Student *s) {

}

int load_students_from_file(StudentArray *arr, const char *filename) {

}

int save_students_to_file(const StudentArray *arr, const char *filename) {

}
