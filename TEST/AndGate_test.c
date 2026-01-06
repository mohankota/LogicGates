#include "unity.h"
#include "AndGate.h"

void test_AndGate_truth_table(void)
{
	TEST_ASSERT_FALSE(AndGate(false, false));
	TEST_ASSERT_FALSE(AndGate(false, true));
	TEST_ASSERT_FALSE(AndGate(true, false));
	TEST_ASSERT_TRUE(AndGate(true, true));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_AndGate_truth_table);
	return UNITY_END();
}