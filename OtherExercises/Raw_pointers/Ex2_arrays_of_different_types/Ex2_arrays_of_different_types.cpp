
// The aim of this question is to write different versions
// of the same program, where : 
// 
//	   A function asks a user how many real values the user
//	   wishes to insert. Then the function asks the user to insert
//     the real values.
//
//	   A function to print the read values.
//
//     A 'main' which uses the function to read then print the values.
// 
//     There should be no memory leak. Use the "vérification d'allocation'.

// If the aim is only to practice pointers, practice version 3 (presented
// below). The function used to print the result can be the same for all the
// version. Use 'span' (as parameter), instead of the type corresponding to
// the version, to achieve this result.

// TODO : Insert all include statements here.
#include <iostream>
#include <span>
#include <string>
#include <limits>
#include <memory>
#include <vector>
#include <utility>

// Set a constant to determine the maximum number of values
// for the array of fixed size.
const int ARRAY_SIZE = 4;

// Set the number of times a user can try to insert a single
// value.
const int MAX_TRIALS = 3;

// Functions declaration
void printValues(std::span<const double> values);
double enterSingleValue(const int maxTrials);
void askValues(double cTypeArray[], int dim);
std::vector<double> askValuesV2();
std::pair<double*, int> askValuesV3();
std::pair<std::unique_ptr<double>, int> askValuesV4();


// Utility function to check the type of each user entry.

/// <summary>
/// Function used to check and adjust user entry.
/// </summary>
/// <param name="maxTrials">
/// The maximum number of trials the user can write a wrong
/// type inside the prompt.
/// </param>
/// <returns>
/// The user's value if this value is of good type or
/// std::numeric_limits<double>::min(), when the correct
/// value type is not correct after maxTrials trials.
/// </returns>
double enterSingleValue(const int maxTrials) {
	std::cout << "Please, enter a value : " << std::endl;

	// The value min() is use in order to stop the program when
	// the wrong values types are inserted a maximum number of times.
	// When max() is used, the program take a very large number of
	// values (size of array becomes very large), which the user
	// can not fill in a reasonable amount of time.
	double numberOuput = std::numeric_limits<double>::min();
	std::string userValue;

	for (size_t i = 0; i < maxTrials; i++) {
		std::getline(std::cin, userValue);
		try {
			numberOuput = std::stold(userValue);
			break;
		}
		catch (std::invalid_argument const& exception) {
			std::cout << "std::invalid_argument::what(): " << exception.what() << std::endl;
		}
		catch (std::out_of_range const& exception) {
			std::cout << "std::out_of_range::what() :" << exception.what() << std::endl;
		}
			if (i == (maxTrials - 1)) {
				std::cout << "Maximum number of attemps reached. Please, restart " <<
					"the program and insert the appropriate values." << std::endl;
				break;
		}
		std::cout << "Please type a real number." << std::endl;
	}
	return numberOuput;
}


// TODO : 
// Version 1 (chap1 - 2): There is a maximum number of values, which is 
// determined at compilation. An array of fixed size is thus used
// (passed by reference to functions). The other versions do not have
// a maximum number of values.

/// <summary>
/// First version of the function that asks values to a user. This version
/// uses a C-type array and array dimensions as parameters.
/// </summary>
/// <param name="cTypeArray">Array of type C.</param>
/// <param name="dim">Size of the array.</param>
void askValues(double cTypeArray[], int dim) {
	std::cout << "Please, you should enter " << dim << " values." << std::endl;
	for (size_t i = 0; i < dim; i++) {
		double value = enterSingleValue(MAX_TRIALS);
		cTypeArray[i] = value;
	}
}


/// <summary>
/// Function that asks for the number of values to be entered into the array.
/// </summary>
/// <returns>The number of values to be inserted into the array.</returns>
int askNValues() {
	std::cout << "Please, how many values do you wish to enter in the array ? " <<
		std::endl;
	int nValues = int(enterSingleValue(MAX_TRIALS));
	return nValues;
}


// TODO : 
// Version 2 (chap1 - 2): Use std::vector to store the values.

/// <summary>
/// Second version of the function that asks values to a user. This version
/// uses std::vector, which allocates memory dynamically.
/// </summary>
/// <returns>A vector containing all the user inputs.</returns>
std::vector<double> askValuesV2() {
	int nValues = askNValues();

	// Note the size of nValues is not used when initializing
	// the vector because pushback() is used. 
	// If the vector is initialized with zero's, pushback() 
	// adds values above the zeros.
	std::vector<double> values;
	for (size_t i = 0; i < nValues; i++) {
		double value = enterSingleValue(MAX_TRIALS);
		values.push_back(value);
	}
	return values;
}


// TODO : 
// Version 3 (chap 3): The memory is dynamically allocated, using the hand,
// and returned (in return value) by the function, which asks for values.

/// <summary>
/// Third version of the function that asks values to a user. This version
/// uses a raw pointer, hence memory deallocation is required (delete[]). 
/// </summary>
/// <returns>
/// A pair containing a raw pointer to the user's inserted values and 
/// the size of the array (number of values inserted by the user).
/// </returns>
std::pair<double*, int> askValuesV3() {
	int nValues = askNValues();
	double* values = new double[nValues];
	for (size_t i = 0; i < nValues; i++) {
		double value = enterSingleValue(MAX_TRIALS);
		values[i] = value;
	}
	return std::make_pair(values, nValues);
}


// TODO :
// Version 4 (chap6): Use unique_ptr to automatically hand memory possession,
// allocated by the function which askes for values.

/// <summary>
/// Fourth version of the function that asks values to a user. This version
/// uses a intelligent pointers, hence memory deallocation is not required. .
/// </summary>
/// <returns>
/// A pair containing an intelligent pointer to the user's inserted values and 
/// the size of the array (number of values inserted by the user).
/// </returns>
std::pair<std::unique_ptr<double>, int> askValuesV4()
{
	int nValues = askNValues();
	std::unique_ptr<double> values = std::make_unique<double>(nValues);
	for (size_t i = 0; i < nValues; i++) {
		double value = enterSingleValue(MAX_TRIALS);
		(values.get())[i] = value;
	}

	// Move statement must be used for possession transfer of std::unique_ptr.
	return std::make_pair(std::move(values), nValues);
}


// TODO : Function(s) to print the read and print the values.

/// <summary>
/// Function that takes advantage of 'span' to print the values contained in
/// all the different structures used (version 1 to version 4): C-type array,
/// std::vector, raw pointer, and std::std::unique_ptr.
/// </summary>
/// <param name="values">
/// A "span" pointing at the user's inserted values.
/// </param>
void printValues(std::span<const double> values) {
	for (const auto& value : values) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
}


// Note : The best version of this program is generally the version which uses
// std::vector, which is implemented (std::vector) using dynamic allocation.

int main() {
	// Note : The current implementation linits the number of 
	// digits printed to 6, whether these digits comme before or
	// after the decimal point.

	// ---Please uncomment each section to run the code for the corresponding version.---
	
	// 1. Call for the c-type array
	 double cArray[ARRAY_SIZE] = {};
	 askValues(cArray, ARRAY_SIZE);
	 printValues(cArray);

	//// 2. Using std::vector
	//std::vector<double> values = askValuesV2();
	//printValues(values);

	//// 3. Using raw pointers
	//std::pair<double*, int> pairPtrValues = askValuesV3();
	//printValues(std::span(pairPtrValues.first, pairPtrValues.second));
	//delete[] pairPtrValues.first;

	//// 4. Using intelligent pointers
	//std::pair<std::unique_ptr<double>, int> uniqueValues = askValuesV4();
	//printPointerValues(uniqueValues.first.get(), uniqueValues.second);

}
