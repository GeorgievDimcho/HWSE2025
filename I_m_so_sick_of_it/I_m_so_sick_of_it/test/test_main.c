#include "unity.h"
#include "student.h"
#include "cmock.h"
#include "Mockdisplay_stuff.h"
#include "Mockfile_handling.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void fill_student_data(student_t* student, int cmock_num_calls)
{
    (void)cmock_num_calls; // Unterdrückt "unused parameter"-Warnung

    strcpy(student->first_name, "John");
    strcpy(student->last_name, "Doe");
    strcpy(student->birthdate, "2000-01-01");
    strcpy(student->email, "john.doe@example.com");
    student->id = 1234;
    student->enrollment_status = 1;

    for (int i = 0; i < 10; ++i)
    {
        strcpy(student->course_list[i], "Math");
    }
}


void setUp(void)
{
    // Setup code before each test
}

void tearDown(void)
{
    // Cleanup code after each test
}

void test_my_module_should_add(void)
{
    TEST_ASSERT_EQUAL_INT(5, add(2, 3));

}

/*void test_sub(void)
{
    TEST_ASSERT_EQUAL_INT(8, sub(11, 3));
}*/

void test_create_student_success(void)
{
    student_t student;
    fill_student_data(&student,1);
    
    ask_for_student_data_StubWithCallback(fill_student_data);
    save_student_data_ExpectAnyArgsAndReturn(0);

    // Act: Call the function under test
    int result = create_student();

    // Assert: Verify the result
    TEST_ASSERT_EQUAL_INT(0, result);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_my_module_should_add);
    //RUN_TEST(test_sub);
    RUN_TEST(test_create_student_success);
    return UNITY_END();
}
