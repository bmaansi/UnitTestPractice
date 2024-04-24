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
	bool actual = my_password.has_mixed_case("L");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, one_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("m");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, one_upper_one_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Lm");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, one_lower_one_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("mL");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, two_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("mm");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, random_symbols_and_ints)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("#$*(!$!*$!@)#01924");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, uppers_lowers_ints)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AKFJSHsjkdg039258");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, lowers_ints)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("sjkdg039258");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, uppers_ints)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AKFJSH039258");
	ASSERT_EQ(false, actual);
}

// TEST(PasswordTest, constructor) {
// 	Password my_password;
// 	my_password.set("nj90NJ");
// 	ASSERT_EQ("nj90NJ", my_password.pass_history[my_password.pass_history.size()-1]);
// }

TEST(PasswordTest, constructor) {
	Password my_password;
	//my_password.set("nj90NJ");
	bool actual = my_password.authenticate("ChicoCA-95929");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, bad_password) {
	Password my_password;
	my_password.set("nj90NJ");
	bool actual = my_password.authenticate("nj90NJ");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, good_password) {
	Password my_password;
	my_password.set("nj90NJnjn");
	bool actual = my_password.authenticate("nj90NJnjn");
	ASSERT_EQ(true, actual);
}