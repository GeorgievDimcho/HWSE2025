// test_rectangle.c
#include "unity.h"
#include "cmock.h"
#include "rectangle.h"

// Mock function declarations
int get_length();
int get_width();

void setUp(void) {
    // Set up code here (if needed)
}

void tearDown(void) {
    // Tear down code here (if needed)
}

void test_calculate_area(void) {
    // Set up the mocks
    get_length_ExpectAndReturn(5); // Mock get_length to return 5
    get_width_ExpectAndReturn(10);  // Mock get_width to return 10

    // Call the function under test
    int area = calculate_area();

    // Verify the result
    TEST_ASSERT_EQUAL(50, area); // 5 * 10 = 50
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_calculate_area);
    return UNITY_END();
}
