// Exercise initially used to practice 'new' and 'delete', with and without [].
// The updated version is used to learn how to used std::unique_ptr, 
// std::shared_ptr, std::make_shared, and std::make_unique. Deletion is not
// required for intelligent pointers.
// The exercise also permit to dereference (* and [] at the right positions) for 
// different double pointers.

// TODO : Include the required libraries here.
#include <iostream>
#include <memory>

int main()
{
	// TODO :
	// Allocate a pointer to an 'int'. Put 3 in that 'int', and print that 'int'.
	std::unique_ptr<std::unique_ptr<int>> ptrPtr = 
		std::make_unique<std::unique_ptr<int>>(std::make_unique<int>(3));
	std::cout << "**ptrPtr = " << **ptrPtr << std::endl;

	// TODO :
	// Allocate a pointer to an array of 2 pointers, each pointing towards a distinct
	// 'int'. Put the values 4 and 5 in these 'int' and print these 'int'.
	std::unique_ptr<std::unique_ptr<int>[]> ptrArrayPtr =
		std::make_unique<std::unique_ptr<int>[]>(2);

	ptrArrayPtr[0] = std::make_unique<int>(4);
	ptrArrayPtr[1] = std::make_unique<int>(5);
	std::cout << "*(ptrArrayPtr[0]) = " << *((ptrArrayPtr[0])) <<
		" ; *(ptrArrayPtr[1]) = " << *((ptrArrayPtr[1])) << std::endl;

	// TODO : 
	// Allocate a pointer to a pointer to an array of 2 'int'. 
	// Put 6 and 7 in these 'int' and print them.
	std::unique_ptr<std::unique_ptr<int[]>> ptrPtrArray = 
		std::make_unique<std::unique_ptr<int[]>>(std::make_unique<int[]>(2));
	(*ptrPtrArray)[0] = 6;
	(*ptrPtrArray)[1] = 7;
	std::cout << "(*ptrPtrArray)[0] = " << (*ptrPtrArray)[0] <<
		"; (*ptrPtrArray)[1] = " << (*ptrPtrArray)[1] << std::endl;

	// TODO : 
	// Allocate a pointer to an array of two pointers, each pointing
	/// towards a distint array of 2 'int'.
	// Put 8, 9, and 10, 11 into these 'int' and print these 'int'.

	// The values to be inserted are 4. To avoid duplication of code,
	// these values are put in an array and read from that array.
	const int nValues = 4;
	int values[nValues] = { 8, 9, 10, 11 };
	const int nValuesFirstLevelArray = 2;
	const int nValuesSecondLevelArray = 2;

	// Initialize the exterior / first pointer  (pointing to 
	// an array of pointers). 
	std::unique_ptr<std::unique_ptr<int[]>[]> ptrArraryPtrArray = 
		std::make_unique< std::unique_ptr<int[]>[]>(nValuesFirstLevelArray);

	// Initialize the two interior / second level pointer, each
	// pointer ot an array of 'int' values.
	for (size_t i = 0; i < nValuesFirstLevelArray; i++) {
		ptrArraryPtrArray[i] = std::make_unique<int[]>(nValuesSecondLevelArray);

		// Fill the values inside the arrays of integers.
		for (size_t j = 0; j < nValuesFirstLevelArray; j++) {
			ptrArraryPtrArray[i][j] = values[i + j];

			// Print the int value stored at the address.
			std::cout << "ptrArraryPtrArray[" << i << "][" << j << "] = " <<
				ptrArraryPtrArray[i][j] << std::endl;;
		}
	}

	// TODO : 
	// Deallocate all the memory that has been allocated.
	// The course library can be used to check this.

	// Memory management is automatically handled by intelligent pointers.

}

