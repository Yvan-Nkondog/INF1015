#include <iostream>
#include <random>
#include <string>

constexpr auto ERROR_TEXT = "Sorry, value out of range.";
const int MIN_LIMIT = 0;
const int MAX_LIMIT = 1000;


/// <summary>
/// Function to generate a random number (within an interval) using 
/// the "Mersenne Twister engine".
/// </summary>
/// <param name="minLimit">Lower bound of possible random values.</param>
/// <param name="minLimit">Upper bound of possible random values.</param>
/// <param name="maxLimit"></param>
/// <returns>A random number in a given interval.</returns>
int generateRandomNumber(int minLimit, int maxLimit)
{
	std::random_device rd_dev;
	std::mt19937 gen(rd_dev());
	std::uniform_int_distribution<int> dist(minLimit, maxLimit);
	int randomNumber = dist(gen);
	return randomNumber;
}

/// <summary>
/// Reads and checks the user's input. Each time this function 
/// returns a value, it is considered as one trial, that is
/// users' inputs that are rejected are not considered as trials.
/// </summary>
/// <param name="errorText">
/// Error text to return when the value is type-valid, but out of range.
/// </param>
/// <param name="minValue">Lower bound of possible random values.</param>
/// <param name="maxValue">Upper bound of possible random values.</param>
/// <returns>Valid user's input.</returns>
int readUserInputInInterval(const std::string& errorText, int minValue, int maxValue)
{
	double userInput;
	// Counter to count the number of 
	while (true) {
		std::cout << "Please, enter a value between " << minValue << " and " << maxValue << ": ";
		std::cin >> userInput;

		// Check if the user's input is valid
		if (std::cin.fail()) { // False if the user input is successful.
			// Reset the stream state to avoid further errors.
			std::cin.clear();
			// Discards the rest of the invalid input line.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, please enter a real number or an integer." << std::endl;
			continue;
		}

		if ((userInput >= minValue) && (userInput <= maxValue)) {
			return int(userInput);
		}
		else {
			std::cout << errorText << std::endl;
		}
	}
}

/// <summary>
/// Function that loops (only using valid user inputs that are in the
/// expected range) and tells the user whether the values are lower or
/// upper than the random value. The 
/// </summary>
/// <param name="randomValue">The random value the user should guess.</param>
void guessNumber(int randomValue)
{
	int userInput;
	// Note : The question has not specifically specified exactly what nTrials.
	// The program has been designed to count only the number of successful trials,
	// that is the trials that are found in the interval where the random value is
	// found.
	int nTrials = 0;

	while (true) {
		++nTrials;
		userInput = readUserInputInInterval(ERROR_TEXT, MIN_LIMIT, MAX_LIMIT);
		if (userInput < randomValue) {
			std::cout << "The value you have entered is lower than the random value." << std::endl;
		}
		else if (userInput > randomValue) {
			std::cout << "The value you have entered is higer than the random value." << std::endl;
		}
		else {
			std::cout << "Congratulations, you have entered the correct random value." << std::endl;
			std::cout << "You have succeeded after " << nTrials << " trial(s)." << std::endl;
			break;
		}
	}
}

int main() {
	int randomNumber = generateRandomNumber(MIN_LIMIT, MAX_LIMIT);
	// The following line of code has been added to check if the program
	// works properly (line to be commented after tests). 
	std::cout << randomNumber << std::endl;
	guessNumber(randomNumber);
	std::cout << randomNumber << std::endl;
}
