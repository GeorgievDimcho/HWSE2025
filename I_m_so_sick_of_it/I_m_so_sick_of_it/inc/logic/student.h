#ifndef STUDENT_H
#define STUDENT_H


typedef struct {
    int semester;
    float grades[1]; // A student can have up to 10 grades per semester
} semester_grades;

typedef struct {
    char first_name[50];
    char last_name[50];
    char birthdate[11]; // Format: YYYY-MM-DD
    char email[100];
    int id;
    int enrollment_status; // 0 for not enrolled, 1 for enrolled
    char course_list[1][50]; // A student can have up to 10 courses, each with a max length of 50 characters
    semester_grades semesters[1]; // Assuming a student can have up to 8 semesters of grades
} student_t;


int add(int a, int b);

int sub(int a, int b);

int create_student();

#endif // STUDENT_H
