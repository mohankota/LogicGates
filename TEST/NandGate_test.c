#include "unity.h"
#include "NandGate.h"

void test_NandGate_truth_table(void)
{
	TEST_ASSERT_TRUE(NandGate(false, false));
	TEST_ASSERT_TRUE(NandGate(false, true));
	TEST_ASSERT_TRUE(NandGate(true, false));
	TEST_ASSERT_FALSE(NandGate(true, true));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_NandGate_truth_table);
	return UNITY_END();
}