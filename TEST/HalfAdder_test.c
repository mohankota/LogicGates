#include "unity.h"
#include "HalfAdder.h"

void test_HalfAdder_truth_table(void)
{
	bool sum, carry;
	
	HalfAdder(false, false, &sum, &carry);
	TEST_ASSERT_FALSE(sum);
	TEST_ASSERT_FALSE(carry);
	
	HalfAdder(false, true, &sum, &carry);
	TEST_ASSERT_TRUE(sum);
	TEST_ASSERT_FALSE(carry);
	
	HalfAdder(true, false, &sum, &carry);
	TEST_ASSERT_TRUE(sum);
	TEST_ASSERT_FALSE(carry);
	
	HalfAdder(true, true, &sum, &carry);
	TEST_ASSERT_FALSE(sum);
	TEST_ASSERT_TRUE(carry);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_HalfAdder_truth_table);
	return UNITY_END();
}