/* student.h - definição da struct e protótipos */
#ifndef STUDENTS_H
#define STUDENTS_H

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

/* Gerenciamento */
void init_student_array(StudentArray *arr);
void free_student_array(StudentArray *arr);

/* Operações */
int add_student(StudentArray *arr, const Student *s);
void list_students(const StudentArray *arr);
int find_student_index_by_id(const StudentArray *arr, int id);
int remove_student_by_id(StudentArray *arr, int id);
void print_student(const Student *s);
void prompt_student(Student *s);

/* I/O */
int load_students_from_file(StudentArray *arr, const char *filename);
int save_students_to_file(const StudentArray *arr, const char *filename);

#endif /* STUDENTS_H */