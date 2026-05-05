// Exercise used to practice 'new' and 'delete', with and without [].
// The exercise also permit to dereference (* and [] at the right positions) for 
// different double pointers.

// TODO : Include the required libraries here.
#include <iostream>
#include <string>

int main()
{
	// TODO :
	// Allocate a pointer to a pointer an 'int'. Put 3 in that 'int', and print that 'int'.
	int** ptrPtrX = new int* (new int(3));
	std::cout << "**ptrPtrX = " << **ptrPtrX << std::endl;

	// TODO :
	// Allocate a pointer to an array of 2 pointers, each pointing towards a distinct
	// 'int'. Put the values 4 and 5 in these 'int' and print these 'int'.
	int** ptrArrayPtr = new int* [2] {new int(4), new int(5)};
	std::cout << "*(ptrArray[0]) = " << *(ptrArrayPtr[0]) << "; *(ptrArray[1]) = "
		<< *(ptrArrayPtr[1]) << std::endl;

	// TODO : 
	// Allocate a pointer to a pointer to an array of 2 "int'. 
	// Put 6 and 7 in these 'int' and print them.
	int** ptrPtrArray = new int* { new int[2](6, 7) };
	std::cout << "(*ptrPtrArray)[0] = " << (*ptrPtrArray)[0] <<
		"; (*ptrPtrArray)[1] = " << (*ptrPtrArray)[1] << std::endl;

	// TODO : 
	// Allocate a pointer to an array of two pointers, each pointing
	/// towards a distint array of 2 'int'.
	// Put 8, 9, and 10, 11 into these 'int' and print these 'int'.
	int** ptrArrayPtrArray = new int* [2] {new int[2] {8, 9}, new int[2] {10, 11}};
	for (size_t i = 0; i < 2; i++) {
		for (size_t j = 0; j < 2; j++) {
			std::cout << "ptrArrayPtrArray[" << i << "][" << j << "] = " <<
				ptrArrayPtrArray[i][j] << std::endl;
		}
	}
	std::cout << std::endl;

	// TODO : 
	// Deallocate all the memory that has been allocated.
	// The course library can be used to check this.
	delete* ptrPtrX;
	delete ptrPtrX;

	for (size_t i = 0; i < 2; i++) {
		delete ptrArrayPtr[i];
	}
	delete[] ptrArrayPtr;

	delete[] * ptrPtrArray;
	delete ptrPtrArray;

	for (size_t i = 0; i < 2; i++) {
		delete[] ptrArrayPtrArray[i];
	}
	delete[] ptrArrayPtrArray;

}

