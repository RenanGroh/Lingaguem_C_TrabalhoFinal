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


#endif /* STUDENT_H */