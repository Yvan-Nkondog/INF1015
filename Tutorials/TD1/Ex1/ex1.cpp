#include <iostream>
#include <vector>
#include <string>
#include <utility>


/// <summary>
/// This functions asks a user to type a sentence. The sentence is returned
/// using an "OUT" reference parameter (string, using the function getline).
/// </summary>
/// <param name="sentence">
/// The "OUT" parameter that captures the user entry by reference.
/// </param>
void askUserSentence(std::string& sentence)
{
	std::cout << "Saisissez une phrase : " << std::endl;
	std::getline(std::cin, sentence);
}


/// <summary>
/// This function splits a sentence into words and stores the words inside a vector.
/// To avoid iterating the sentence (which can be very long) many times, this function
/// also counts the number of spaces (required to compute the average length of words) 
/// inside the sentence and returns it as a second return value (inside a pair).
/// </summary>
/// <param name="sentence"> User defined sentence.</param>
/// <returns>
/// A pair : the first element of the pair is a vector of words (std::string). 
/// The second element of the pair is the number of space characters inside 
/// the sentence.
/// </returns>
std::pair<std::vector<std::string>, std::size_t> splitSentence(const std::string& sentence)
{
	std::size_t nSpaces = 0;
	std::size_t currentIndex = 0;
	size_t spaceIndex = 0;
	std::vector<std::string> words;
	while (true) {
		spaceIndex = sentence.find(" ", currentIndex);
		if (spaceIndex != sentence.npos) {
			words.push_back(sentence.substr(currentIndex, (spaceIndex - currentIndex)));
			currentIndex = spaceIndex + 1;
			nSpaces++;
		}
		else {
			words.push_back(sentence.substr(currentIndex, std::size(sentence)));
			break;
		}
	}
	return std::make_pair(words, nSpaces);
}


/// <summary>
/// This functions takes a sentence as parameeter and identifies the longest and
/// // the shortest word inside the sentence.
/// </summary>
/// <param name="sentence">
///		sentence : A user defined input (std::string).
/// </param>
/// <returns>
///     A vector of two elements : the first element is the longest word,
///		the second element is the shortest word. 
///		Note : Another data structure could also be used to return these
///		       two elements (longest word and shortest word).
/// </returns>
std::vector<std::string> findShortestAndLongestWords(const std::string& sentence)
{
	std::vector<std::string> longestAndShortest;
	std::vector<std::string> words = splitSentence(sentence).first;
	std::string longestWord = words[0];
	std::string shortestWord = words[0];
	for (size_t i = 0; i < std::size(words); i++) {
		if (std::size(words[i]) > std::size(longestWord)) {
			longestWord = words[i];
		}
		if (std::size(words[i]) < std::size(shortestWord)) {
			shortestWord = words[i];
		}
	}
	longestAndShortest.push_back(longestWord);
	longestAndShortest.push_back(shortestWord);
	return longestAndShortest;
}


/// <summary>
/// This function computes the average length of a sentence (total words size, excluding
/// space characters, divided by total number of words).
/// </summary>
/// <param name="sentence">
/// The user defined sentence.
/// </param>
/// <returns>
/// The average length of words (for sentence passed as argument).
/// </returns>
double computeAverageLength(const std::string& sentence)
{
	std::pair<std::vector<std::string>, std::size_t> wordsAndNumSpaces = splitSentence(sentence);
	return double(std::size(sentence) - wordsAndNumSpaces.second) / std::size(wordsAndNumSpaces.first);
}


int main()
{
	std::string userSentence;
	askUserSentence(userSentence);
	std::vector<std::string> longestAndShortest = 
		findShortestAndLongestWords(userSentence);
	double averageSentenceLength = computeAverageLength(userSentence);
	std::cout << "Le mot le plus court est : " << longestAndShortest[1] << std::endl;
	std::cout << "Le mot le plus long est : " << longestAndShortest[0] << std::endl;
	std::cout << "La longueur moyenne est : " << averageSentenceLength << std::endl;
}
