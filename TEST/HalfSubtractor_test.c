#include "unity.h"
#include "HalfSubtractor.h"

void test_HalfSubtractor_truth_table(void)
{
	bool difference, borrow;
	
	HalfSubtractor(false, false, &difference, &borrow);
	TEST_ASSERT_FALSE(difference);
	TEST_ASSERT_FALSE(borrow);
	
	HalfSubtractor(false, true, &difference, &borrow);
	TEST_ASSERT_TRUE(difference);
	TEST_ASSERT_TRUE(borrow);
	
	HalfSubtractor(true, false, &difference, &borrow);
	TEST_ASSERT_TRUE(difference);
	TEST_ASSERT_FALSE(borrow);
	
	HalfSubtractor(true, true, &difference, &borrow);
	TEST_ASSERT_FALSE(difference);
	TEST_ASSERT_FALSE(borrow);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_HalfSubtractor_truth_table);
	return UNITY_END();
}