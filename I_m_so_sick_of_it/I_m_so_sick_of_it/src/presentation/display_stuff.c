#include <stdio.h>
#include <string.h> // Add this at the top of your file
#include "display_stuff.h"


void ask_for_student_data(student_t *student)
{
    printf("Enter first name: ");
    scanf("%s", student->first_name);
    
    printf("Enter last name: ");
    scanf("%s", student->last_name);
    
    printf("Enter birthdate (YYYY-MM-DD): ");
    scanf("%s", student->birthdate);
    
    printf("Enter email: ");
    scanf("%s", student->email);
    
    printf("Enter ID: ");
    scanf("%d", &student->id);
    
    printf("Enter enrollment status (0 for not enrolled, 1 for enrolled): ");
    scanf("%d", &student->enrollment_status);
    
    // Assuming a maximum of 10 courses
    for (int i = 0; i < 10; i++) 
    {
        strcpy(student->course_list[i], "i"); 
    }
}