#include "gmock/gmock.h"

#include "baseball.cpp"


class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(std::string guessNumber) {
		//game.guess() 수행 수 exception이 발생해야 pass이다.
		try {
			game.guess(std::string("12s"));
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


int main() {
	testing::InitGoogleMock();

	return RUN_ALL_TESTS();
}