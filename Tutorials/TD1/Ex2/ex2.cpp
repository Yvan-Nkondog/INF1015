#include <iostream>
#include <cmath>
#include <utility>

// For a converging recursive sequence,
// the difference between two consecutive
// terms abs(U(n+1) - U(n)) = gets smaller
// as n increases (turns to infinity).
// 
// This difference is used to fixed the equality
// criterion to stop the recursion.
//
// This code has been written to minimize the use
// of data structures. The complete sequence can
// be obtained by storing consecutives terms inside
// a data structure : std:vector (for example).

/// <summary>
/// Function to compute the limit and the number of
/// iterations.
/// </summary>
/// <returns>
/// std::pair<double, int> containing the limit and the
/// number of iterations, respectively as first and second terms.
/// </returns>
std::pair<double, int> computeLimitRecursion() {
	int n = 0;
	double UPrevious = 1;  // U(n-1)
	double Un = 1;		   // U(n) = U(0) = 1, for n = 0;
	double UNext = 1;      // U(n+1)
	while (true) {
		UNext = std::sqrt(2 + Un);
		// Check the assumption in order to decide
		// whether of not to stop the loop.
		if ((n > 0) && ((std::fabs(UNext - Un)) == (std::fabs(Un - UPrevious)))) {
			break;
		}
		n++;
		UPrevious = Un;
		Un = UNext;
	}
	return std::pair<double, int>(Un, n);
}

/// <summary>
/// Function to display the limit of the sequence and the number of iterations
/// used in order to apporximate the limit.
/// </summary>
void displayLimit() {
	std::pair<double, int> limitAndNumIterations = computeLimitRecursion();
	std::cout << "Limit of the series : " << limitAndNumIterations.first << std::endl;
	std::cout << "The limit has been approximated after " << 
		limitAndNumIterations.second << " recursion steps." << std::endl;
}

int main() {
	displayLimit();
}
