#include    <stdio.h>
#include "file_handling.h"


int save_student_data(student_t *student)
{
    FILE *file = fopen("student_data.txt", "w");
    if (file == NULL)
    {
        return -2; // File opening failed
    }

    fprintf(file, "First Name: %s\n", student->first_name);
    fprintf(file, "Last Name: %s\n", student->last_name);
    fprintf(file, "Birthdate: %s\n", student->birthdate);
    fprintf(file, "Email: %s\n", student->email);
    fprintf(file, "ID: %d\n", student->id);
    fprintf(file, "Enrollment Status: %d\n", student->enrollment_status);

    fclose(file);
    return 0; // Success
}

