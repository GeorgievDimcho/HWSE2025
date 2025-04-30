#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "file_handling.h"
#include "display_stuff.h"


int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int create_student()
{
    student_t *student = (student_t *)calloc(1, sizeof(student_t));
    int error = 0;
    if (student == NULL)
    {
        error = -1; // Memory allocation failed
    }
    ask_for_student_data(student);
    error = save_student_data(student);
    free(student);
    return error;
}