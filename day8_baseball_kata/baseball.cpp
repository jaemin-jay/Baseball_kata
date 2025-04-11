
#include <stdexcept>
class Baseball {
public:
	void guess(const std::string& guessNumber) {
		if (guessNumber.length() != 3)
			throw std::length_error("Must be three letters.");

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') {
				throw std::invalid_argument("Must be numbers");
			}
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
};