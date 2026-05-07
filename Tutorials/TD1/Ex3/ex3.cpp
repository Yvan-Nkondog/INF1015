#include <iostream>
#include <array>
#include <string>
#include <limits>


/// <summary>
/// The aim of this function is to add an element inside a sorted array (c-type array).
/// The input and output array are passed by reference.
/// </summary>
/// <param name="element">The number to be added to the current sorted array.</param>
/// <param name="cArray">The current sorted array.</param>
/// <param name="dim">The dimension (size) of the current sorted array.</param>
/// <param name="resultArray">The output array.</param>
/// <param name="dimResultArray">The size of the output array.</param>
void addElementInSortedArray(int element, int cArray[], 
	int dim, int resultArray[], int dimResultArray)
{
	// Set the index of the result array (to be used inside the loop).
	size_t resultArrayIndex = 0;
	// Set a counter variable (used ensure the new element 
	// is added only once in the new array).
	size_t insertCounter = 0;

	// Loop to fill the new elements in the array
	for (size_t i = 0; i < dim; i++) {
		// Condition used to add the new element at the beginning or at
		// the middle of the array (note : just one addition possible).
		if ((element < cArray[i]) && (insertCounter == 0)) {
			resultArray[resultArrayIndex] = element;
			resultArray[resultArrayIndex + 1] = cArray[i];
			// Note the incrementation of step = 2, since two elements are
			// added in the new array.
			resultArrayIndex += 2;
			insertCounter += 1;
			continue;
		}
		// Add the elements of the original array in the new array.
		resultArray[resultArrayIndex] = cArray[i];
		resultArrayIndex++;
	}
	// If No element has been inserted, then the new element is equal to, or larger
	// than, all the elements, and should be added at the last position.
	if (element >= cArray[dim - 1]) {
		resultArray[dim] = element;
	}
}


/// <summary>
/// This function takes a user input and return the value or maxInteger (2147483647).
/// The user has maxTrials chances to insert a correct input. After, maxTrials
/// trials, the user is asked to restart the program.
/// </summary>
/// <returns>
/// The integer entry of the user or maxInteger (2147483647), if after maxTrials
/// trials, the user is not able to type an integer. The user is asked to restart 
/// the program after maxTrials trials. 
/// </returns>
int enterValue()
{
	const int maxTrials = 5;
	std::string userInput;
	int number = std::numeric_limits<int>::max();

	std::cout << "Please enter a number to add to the sorted " <<
				 "array at the correct position : " << std::endl;
	for (size_t i = 0; i < maxTrials; i++) {
		std::getline(std::cin, userInput);
		try {
			number = std::stoi(userInput);
			break;
		}
		catch (std::invalid_argument const& ex) {
			std::cout << "std::invalid_argument::what(): " << ex.what() << std::endl;
		}
		catch (std::out_of_range const& ex) {
			std::cout << "std::out_of_range::what(): " << ex.what() << std::endl;
		}
		if (i == maxTrials - 1) {
			std::cout << "You have reach the maximum number of attemps. Please, restart " <<
				"the program." << std::endl;
			break;
		}
		std::cout << "Please type an integer." << std::endl;
	}
	return number;
}


/// <summary>
/// This function is used to print the arrays (for comparison purposes).
/// Note : The parameter "dim" must be equal to the length (size) of the array.
/// </summary>
/// <param name="numbers">An array of size = "dim".</param>
/// <param name="dim">The size of the array.</param>
void printArray(int numbers[], int dim) {
	for (size_t j = 0; j < dim; j++) {
		std::cout << numbers[j] << " ";
	}
	std::cout << std::endl;
}


int main()
{
	std::cout << std::stoi("0") << std::endl;
	const int cArraySize = 5;
	const int resultArraySize = cArraySize + 1;
	int cArray1[cArraySize] = { 1, 3, 4, 7, 9 };

	// Print the original array.
	printArray(cArray1, cArraySize);
	
	// Test : Adding an elmment at the middle of the new array.
	int newElement = 5;
	int resultArray1[resultArraySize] = {};
	addElementInSortedArray(newElement, cArray1, cArraySize, resultArray1, resultArraySize);
	// Print the new array.
	printArray(resultArray1, resultArraySize);

	// Test : Adding an elmment at the begining of the array.
	newElement = 0;
	int resultArray2[resultArraySize] = {};
	addElementInSortedArray(newElement, cArray1, cArraySize, resultArray2, resultArraySize);
	// Print the new array.
	printArray(resultArray2, resultArraySize);

	// Test : Adding an elmment at the end of the array.
	newElement = 15;
	int resultArray3[resultArraySize] = {};
	addElementInSortedArray(newElement, cArray1, cArraySize, resultArray3, resultArraySize);
	// Print the new array.
	printArray(resultArray3, resultArraySize);

	// Test : User-defined input.
	newElement = enterValue();
	int resultArray4[resultArraySize] = {};
	if (!(newElement == std::numeric_limits<int>::max())) {
		addElementInSortedArray(newElement, cArray1, cArraySize, resultArray4, resultArraySize);
		// Print the final array if of the user entry is correct.
		printArray(resultArray4, resultArraySize);
	}
}
