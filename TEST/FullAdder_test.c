#include "unity.h"
#include "FullAdder.h"

void test_FullAdder_truth_table(void)
{
	bool sum, carry;
	
	FullAdder(false, false, false, &sum, &carry);
	TEST_ASSERT_FALSE(sum);
	TEST_ASSERT_FALSE(carry);
	
	FullAdder(false, false, true, &sum, &carry);
	TEST_ASSERT_TRUE(sum);
	TEST_ASSERT_FALSE(carry);
	
	FullAdder(false, true, false, &sum, &carry);
	TEST_ASSERT_TRUE(sum);
	TEST_ASSERT_FALSE(carry);
	
	FullAdder(false, true, true, &sum, &carry);
	TEST_ASSERT_FALSE(sum);
	TEST_ASSERT_TRUE(carry);
	
	FullAdder(true, false, false, &sum, &carry);
	TEST_ASSERT_TRUE(sum);
	TEST_ASSERT_FALSE(carry);
	
	FullAdder(true, false, true, &sum, &carry);
	TEST_ASSERT_FALSE(sum);
	TEST_ASSERT_TRUE(carry);
	
	FullAdder(true, true, false, &sum, &carry);
	TEST_ASSERT_FALSE(sum);
	TEST_ASSERT_TRUE(carry);
	
	FullAdder(true, true, true, &sum, &carry);
	TEST_ASSERT_TRUE(sum);
	TEST_ASSERT_TRUE(carry);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_FullAdder_truth_table);
	return UNITY_END();
}