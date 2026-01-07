#include "unity.h"
#include "FullSubtractor.h"

void test_FullSubtractor_truth_table(void)
{
	bool difference, borrow;
	
	FullSubtractor(false, false, false, &difference, &borrow);
	TEST_ASSERT_FALSE(difference);
	TEST_ASSERT_FALSE(borrow);
	
	FullSubtractor(false, false, true, &difference, &borrow);
	TEST_ASSERT_TRUE(difference);
	TEST_ASSERT_TRUE(borrow);
	
	FullSubtractor(false, true, false, &difference, &borrow);
	TEST_ASSERT_TRUE(difference);
	TEST_ASSERT_TRUE(borrow);
	
	FullSubtractor(false, true, true, &difference, &borrow);
	TEST_ASSERT_FALSE(difference);
	TEST_ASSERT_TRUE(borrow);
	
	FullSubtractor(true, false, false, &difference, &borrow);
	TEST_ASSERT_TRUE(difference);
	TEST_ASSERT_FALSE(borrow);
	
	FullSubtractor(true, false, true, &difference, &borrow);
	TEST_ASSERT_FALSE(difference);
	TEST_ASSERT_FALSE(borrow);
	
	FullSubtractor(true, true, false, &difference, &borrow);
	TEST_ASSERT_FALSE(difference);
	TEST_ASSERT_FALSE(borrow);
	
	FullSubtractor(true, true, true, &difference, &borrow);
	TEST_ASSERT_TRUE(difference);
	TEST_ASSERT_TRUE(borrow);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_FullSubtractor_truth_table);
	return UNITY_END();
}