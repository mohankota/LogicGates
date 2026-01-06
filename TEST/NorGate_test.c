#include "unity.h"
#include "NorGate.h"

void test_NorGate_truth_table(void)
{
	TEST_ASSERT_TRUE(NorGate(false, false));
	TEST_ASSERT_FALSE(NorGate(false, true));
	TEST_ASSERT_FALSE(NorGate(true, false));
	TEST_ASSERT_FALSE(NorGate(true, true));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_NorGate_truth_table);
	return UNITY_END();
}