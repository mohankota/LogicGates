#include "unity.h"
#include "OrGate.h"

void test_OrGate_truth_table(void)
{
	TEST_ASSERT_FALSE(OrGate(false, false));
	TEST_ASSERT_TRUE(OrGate(false, true));
	TEST_ASSERT_TRUE(OrGate(true, false));
	TEST_ASSERT_TRUE(OrGate(true, true));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_OrGate_truth_table);
	return UNITY_END();
}