/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, two_letter_upper_lower_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Zz");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, four_dollarsigh_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("$$$$");
	ASSERT_EQ(4, actual);
}

// bool has_mixed_case(string);

TEST(PasswordTest, one_upper)
{
	Password my_password;
	bool actual = my_password.count_leading_characters("L");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, one_lower)
{
	Password my_password;
	bool actual = my_password.count_leading_characters("m");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, one_upper_one_lower)
{
	Password my_password;
	bool actual = my_password.count_leading_characters("Lm");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, one_lower_one_upper)
{
	Password my_password;
	bool actual = my_password.count_leading_characters("mL");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, two_lower)
{
	Password my_password;
	bool actual = my_password.count_leading_characters("mm");
	ASSERT_EQ(false, actual);
}