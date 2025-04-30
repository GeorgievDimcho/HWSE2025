#include "unity.h"
#include "help.h"

void test_add(void)
{
    TEST_ASSERT_EQUAL(5, add(2, 3));
    TEST_ASSERT_EQUAL(0, add(-1, 1));
    TEST_ASSERT_EQUAL(-3, add(-1, -2));
}
void setUp(void) {}
void tearDown(void) {} 
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_add);
    return UNITY_END();
}