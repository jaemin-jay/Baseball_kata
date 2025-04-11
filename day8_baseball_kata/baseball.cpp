#include <stdexcept>

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const std::string& question) : question{ question } {}

	GuessResult guess(const std::string& guessNumber) {
		assertIllegalArgument(guessNumber);

		if (guessNumber == question)
			return { true, 3, 0 };
			
		int idx = 0;
		GuessResult result = { false, 0 ,0 };
		for (auto ch : guessNumber) {
			if (question.find(ch) == std::string::npos) {
				idx++;
				continue;
			}
			result.balls++;
			if (guessNumber[idx] == question[idx]) {
				result.balls--;
				result.strikes++;
			}
			idx++;
		}

		return result;
	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw std::length_error("Must be three letters.");

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9')  continue;
			throw std::invalid_argument("Must be numbers");
			
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw std::invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}

private:
	std::string question;
};