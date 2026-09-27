#include <gtest/gtest.h>

#include "utils.hpp"

class TestFoo : public ::testing::Test
{
protected:
	void SetUp()
	{
	}
	void TearDown()
	{
	}
};

TEST_F(TestFoo, test_toupper)
{
	ASSERT_EQ(toupper(std::string{"hello"}), std::string{"HELLO9"});
}


int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

