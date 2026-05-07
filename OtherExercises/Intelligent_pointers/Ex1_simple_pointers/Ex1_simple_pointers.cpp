
// Exercises on pointers : Can be used to pratice (raw and intelligent pointers).
// 
// Note : In most cases, each 'TODO' takes one line of code.

// TODO : Include the required libraries here.
// #include "bibliotheque_cours"
#include <iostream>
#include <memory>


// TODO : Declare the functions 'f' and 'g' here.

void f(std::shared_ptr<int> ptrX);
void g(std::shared_ptr<int>& ptrX);


int main()
{
	// TODO : Dynamically allocate an int and store it in the pointer 'x'.
	std::shared_ptr<int> x;

	// TODO : Put the value 3 in the int pointed by 'x'.
	x = std::make_shared<int>(3);

	// TODO : Print the int pointed by 'x' (should print 3).
	std::cout << "*x = " << *x << std::endl;

	// TODO : Copy the pointer 'x' in another pointer 'y'.
	std::shared_ptr<int> y = x;

	// TODO : Print the int pointed by 'y'. (Should display 3), why ?
	std::cout << "*y = " << *y << std::endl;
	// The pointer 'y' has not created a new memory (using make_shared()).
	// 'y' is a new pointer that points on the same memory space allocated
	// for the pointer x. Finding the value of 'y' is equiva

	// TODO : Put the value 4 in integers pointed by 'y'.
	*y = 4;

	// TODO : Print again the int pointed by 'x (displays 4), why ?
	std::cout << "*x = " << *x << std::endl;
	// 'x' and 'y' point towards the same address (memory space). Changing
	// the content of this space for 'x' changes the ocntent for 'y' and
	// vice versa.

	// TODO : Copy the int pointed by 'x' in a new dynamically allocated 
	// memory, and store the value in the pointer 'z'.
	std::shared_ptr<int> z = std::make_shared<int>(*x);

	// TODO : Store the value 5 in the int pointed by 'z'.
	*z = 5;

	// TODO : Print the integers (int) pointed by 'x' and 'z'. (Displays 4 and 5), why ?
	std::cout << "*x = " << *x << " ; *z = " << *z << std::endl;
	// For 'z', a new memory is created/allocated. The current value of 'x' (the value
	// contained in the address where 'x' points) is stored in the address of 'z'.
	// However, 'x' and 'z' point at two distinct addresses. Hence, when the value 
	// contained in the address 'z' points to is changed, the value of the content
	// of the address  at which 'x' points remains unchanged.

	// TODO : Passes the pointer 'x' to the function 'f'. Read the rest of the question 
	// in order to get the description fo the functions.
	f(x);

	// TODO : Print the 'int' pointed by 'x' and 'y' (after the function call of 'f'.
	// Display 6 and 6, why ?
	std::cout << "*x = " << *x << " ; *y = " << *y << std::endl;
	// Initially.
	// 'x' and 'y' point at the same address, hence any change at the address 'x'
	// points to changes what is contained at the address 'y' points to. Hence,
	// f(x) changes both *x and *y at the first step.
	// It is important to note that the pointer at the lever of the parmmeter of f() 
	// function is a copy. Hence ptrX is a copy of 'x' when 'x' is passed as argument.
	// It is this copy that creates / allocates a new memory / space in the second step
	// of the function and stores 7. Hence, the value of *x and *y are not affected by
	// the new value 7, which is stored in a new memory space.

	// TODO : Define a variable 'a' of type 'int' with value = 8.
	int a = 8;

	// TODO : Passe the variable 'a' to the function 'f'.
	f(std::shared_ptr<int>(&a, [](int*) {})); 
	// The previous line of code uses a "custom deleter" that does nothing.
	// Note : Wrapping an existing variable ('a') without allocating memory 
	// (the previous line of code above) is not recommended. It has been used 
	// only to complete the exercise, which indirectly compares the uses of 
	// raw and intelligent pointers.

	// TODO : Print the content of 'a' (displays 6).
	std::cout << "a = " << a << std::endl;

	// TODO : The 'main' (program entrance), passes 'x' to the function 'g'.
	g(x);

	// TODO : Print the int pointed by the pointers 'x' and 'y'.
	// Displays 10 and 9, why ?
	std::cout << "*x = " << *x << " ; *y = " << *y << std::endl;
	// The parameter in g() function is passed by reference. Hence, updating the
	// the parameter updates the argument.
	// The first step changes the content of the shared address of 'x' and 'y'.
	// After the first step, *x and *y = 9. During the second step, a new memory /
	// space is allocated to the parameter. Because 'x' (and not 'y') is passed to 
	// the parameter by reference, 'x' starts pointing to this new space / memory, 
	// which has been initialized with a value of 10. The value of 'y' remains
	// unchanged, as y points the original address (still containing the value 9,
	// from the first step).


	// TODO : Try to pass the variable 'a' to the function 'g'.
	// Why is there a problem ?
	
	// g(std::shared_ptr<int>(&a, [](int*) {}));
	// The function 'g()' takes a parameter by reference, non const. When the a
	// parameter is a non const reference, the argument passed must be of the
	// exact type. Also the argument can not be the result of an experssion 
	// when the parameter is a non const reference.

	// TODO : Create a variable that points towards 'a'. Pass this variable to
	// the function 'g' (takes two lines).
	std::shared_ptr<int> ptrVariable(&a, [](int*) {});
	g(ptrVariable);
	// Note : See the note concerning the use of "custom deleter" that does nothing,
	// for the same call using the f() function (note above).

	// TODO : Print the content of 'a' and the int pointed by the variable 
	// which pointed towards 'a'. (Displays 9 and 10).
	std::cout << "a = " << a << " ; " << "*ptrVariable = " << *ptrVariable << std::endl;

	// This exercise does not ask to unallocate memory.
}


// Description of functions.
// Note : Define the functions 'f' and 'g' here.
// 
// TODO :
// The function 'f' takes a pointer of 'int' as only parameter and does not return
// anything : Puts 6 in the 'int' pointed by the parameter. Dynamically allocates a 
// new 'int' and store the pointer in the function parameter. Puts 7 in that 'int'.
void f(std::shared_ptr<int> ptrX) 
{
	*ptrX = 6;
	ptrX = std::make_shared<int>(7);
}


// TODO :
// The function 'g' is a copy of the function 'f' but takes a reference to a pointer
// of 'int', as only parameter (instead of a direct pointer). The function 'g' does
// not return a value. The values 6 and 7 from the 'f' functions are changed to 
// 9 and 10, for the 'g' function.
void g(std::shared_ptr<int>& ptrX) 
{
	*ptrX = 9;
	ptrX = std::make_shared<int>(10);
}



