#include "gmock/gmock.h"

#include "baseball.cpp"


class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
	void assertIllegalArgument(std::string guessNumber) {
		//game.guess() 수행 수 exception이 발생해야 pass이다.
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (std::exception e) {
			//PASS
		}
	}
};


TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
	
}


TEST_F(BaseballFixture, ReturnSolvedResultWith0Ball2Strike) {
	GuessResult result = game.guess("103");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}


int main() {
	testing::InitGoogleMock();

	return RUN_ALL_TESTS();
}