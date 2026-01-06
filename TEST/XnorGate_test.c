#include "unity.h"
#include "XnorGate.h"

void test_XnorGate_truth_table(void)
{
	TEST_ASSERT_TRUE(XnorGate(false, false));
	TEST_ASSERT_FALSE(XnorGate(false, true));
	TEST_ASSERT_FALSE(XnorGate(true, false));
	TEST_ASSERT_TRUE(XnorGate(true, true));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_XnorGate_truth_table);
	return UNITY_END();
}