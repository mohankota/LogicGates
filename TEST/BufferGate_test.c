#include "unity.h"
#include "BufferGate.h"

void test_BufferGate_truth_table(void)
{
	TEST_ASSERT_FALSE(BufferGate(false));
	TEST_ASSERT_TRUE(BufferGate(true));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_BufferGate_truth_table);
	return UNITY_END();
}