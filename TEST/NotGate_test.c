#include "unity.h"
#include "NotGate.h"

void test_NotGate_truth_table(void)
{
	TEST_ASSERT_FALSE(NotGate(true));
	TEST_ASSERT_TRUE(NotGate(false));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_NotGate_truth_table);
	return UNITY_END();
}