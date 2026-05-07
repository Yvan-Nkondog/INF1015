// The amin of this code file is to implement the russian multiplication.
// Details about the implementation are given in the pdf file describing
// how russian multiplication works (the pdf file should be found in the
// parent directory). Also, comments have been addedto the code, to explain, 
// when required.

#include <iostream>


/// <summary>
/// This function sets the sign of the result of the russian multiplication.
/// </summary>
/// <param name="a">Operand for multiplication.</param>
/// <param name="b">Operand for multiplication.</param>
/// <returns>-1 or +1, based on the signs of each operand.</returns>
int setRussianMultiplicationSign(int a, int b)
{
	// Set variable to hold sign of the result obtained from russian
	// multiplication of abs(a) * abs(b).
	int resultSign = 1;

	// Update the result sign to negative, if any of the entries is negative
	// (but not both, that is excusive "OR").
	if (((a < 0) && (b > 0)) != ((a > 0) and (b < 0))) {
		resultSign = -1;
	}

	// Return the sign of the product obtained from russian multiplication.
	return resultSign;
}


/// <summary>
/// This function computes the russian multiplication between 
/// two integer operands.
/// </summary>
/// <param name="a">Operand for multiplication.</param>
/// <param name="b">Operand for multiplication.</param>
/// <returns>The product obtained after multiplication.</returns>
int russianMultiply(int a, int b)
{
	// Set the sign of the final result.
	int resultSign = setRussianMultiplicationSign(a, b);

	// Extract the absolute values of a and b and perform the
	// russian multiplication.
	a = abs(a);
	b = abs(b);
	
	int result = 0;
	while (a > 0) {
		// Select the lines where the first column is odd.
		if (a % 2 != 0) {
			// Sum the second column each time the corresponding value in the
			// first column is odd.
			result += b;
		}
		// Update the values of the enties (divide the first column by 2
		// and multiply the second column by 2).
		a /= 2;
		b *= 2;
	}

	// Return the product of the expected sign and the final sum.
	return result * resultSign;
}


int main()
{
	// Test the case of two positive numbers
	int x = 5;
	int y = 10;
	std::cout << "Multiplying " << x << " and " << y 
		<< " using russian multiplication yields " << russianMultiply(x, y) << std::endl;

	// Test the case of two negative numbers.
	x = -5;
	y = -10;
	std::cout << "Multiplying " << x << " and " << y 
		<< " using russian multiplication yields " << russianMultiply(x, y) << std::endl;

	// Test the case of two even numbers.
	x = -30;
	y = -10;
	std::cout << "Multiplying " << x << " and " << y
		<< " using russian multiplication yields " << russianMultiply(x, y) << std::endl;

	// Test the case of two odd numbers.
	x = -15;
	y = -5;
	std::cout << "Multiplying " << x << " and " << y
		<< " using russian multiplication yields " << russianMultiply(x, y) << std::endl;

	// Test the case of first argument positive and second argument negative.
	x = 5;
	y = -10;
	std::cout << "Multiplying " << x << " and " << y
		<< " using russian multiplication yields " << russianMultiply(x, y) << std::endl;

	// Test the case of first argument negative and second argument positive.
	x = - 5;
	y = 10;
	std::cout << "Multiplying " << x << " and " << y
		<< " using russian multiplication yields " << russianMultiply(x, y) << std::endl;

	// Test the case of first argument = 0.
	x = 0;
	y = -10;
	std::cout << "Multiplying " << x << " and " << y
		<< " using russian multiplication yields " << russianMultiply(x, y) << std::endl;

	// Test the case of second argument = 0.
	x = 15;
	y = 0;
	std::cout << "Multiplying " << x << " and " << y
		<< " using russian multiplication yields " << russianMultiply(x, y) << std::endl;

	// Test the case of first argument = 1.
	x = 1;
	y = -10;
	std::cout << "Multiplying " << x << " and " << y
		<< " using russian multiplication yields " << russianMultiply(x, y) << std::endl;

	// Test the case of second argument = 1.
	x = 15;
	y = 1;
	std::cout << "Multiplying " << x << " and " << y
		<< " using russian multiplication yields " << russianMultiply(x, y) << std::endl;

	// Test the case of first argument = -1.
	x = -1;
	y = -10;
	std::cout << "Multiplying " << x << " and " << y
		<< " using russian multiplication yields " << russianMultiply(x, y) << std::endl;

	// Test the case of second argument = 1.
	x = 15;
	y = -1;
	std::cout << "Multiplying " << x << " and " << y
		<< " using russian multiplication yields " << russianMultiply(x, y) << std::endl;
}
