#include <iostream>

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