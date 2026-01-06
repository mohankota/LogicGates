#include "unity.h"
#include "XorGate.h"

void test_XorGate_truth_table(void)
{
	TEST_ASSERT_FALSE(XorGate(false, false));
	TEST_ASSERT_TRUE(XorGate(false, true));
	TEST_ASSERT_TRUE(XorGate(true, false));
	TEST_ASSERT_FALSE(XorGate(true, true));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_XorGate_truth_table);
	return UNITY_END();
}