/* student.h - definição da struct e protótipos */
#ifndef STUDENT_H
#define STUDENT_H

#include <stddef.h>

#define STUDENT_NAME_LEN 100

typedef struct {
    int id;
    char name[STUDENT_NAME_LEN];
    double grade;
} Student;

typedef struct {
    Student *data;
    size_t size;
    size_t capacity;
} StudentArray;

/* Inicializa/limpa o array */
void init_student_array(StudentArray *arr);
void free_student_array(StudentArray *arr);

/* Operações básicas */
int add_student(StudentArray *arr, const Student *s); // return 0 OK
void list_students(const StudentArray *arr);
int find_student_index_by_id(const StudentArray *arr, int id); // -1 se não
int remove_student_by_id(StudentArray *arr, int id); // 1 se removido
void print_student(const Student *s);
void prompt_student(Student *s);

#endif /* STUDENT_H */