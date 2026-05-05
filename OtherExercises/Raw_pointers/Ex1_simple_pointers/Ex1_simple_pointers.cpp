
// Exercises on pointers : Can be used to pratice (raw and intelligent pointers).
// 
// Note : In most cases, each 'TODO' takes one line of code.

// TODO : Include the required libraries here.
#include <iostream>


// TODO : Declare the functions 'f' and 'g' here.

void f(int* ptrX);

void g(int*& ptrX);

int main()
{
	// TODO : Dynamically allocate an int and store it in the pointer 'x'.
	int* x = new int;

	// TODO : Put the value 3 in the int pointed by 'x'.
	*x = 3;

	// TODO : Print the int pointed by 'x' (should print 3).
	std::cout << "*x = " << *x << std::endl;

	// TODO : Copy the pointer 'x' in another point pointer 'y'.
	int* y = x;

	// TODO : Print the int pointed by 'y'. (Should display 3), why ?
	std::cout << "*y = " << *y << std::endl;

	// TODO : Put the value 4 in integers pointed by 'y'.
	*y = 4;

	// TODO : Print again the int pointed by 'x (displays 4), why ?
	std::cout << "*x = " << *x << std::endl;

	// TODO : Copy the int pointed by 'x' in a new dynamically allocated 
	// memory, and store the value in the pointer 'z'.
	int* z = new int(*x);

	// TODO : Store the value 5 in the int pointed by 'z'.
	*z = 5;

	// TODO : Print the integers (int) pointed by 'x' and 'z'. (Displays 4 and 5), why ?
	std::cout << "*x = " << *x << " ; *z = " << *z << std::endl;
	// The pointer z points on a new memory address. The current value of x is copied in
	// that address. However, x does not point where z points. Hence, when the value
	// of the content of the address pointed by z changes, the value of *x is not affected.

	// TODO : Passes the pointer 'x' to the function 'f'. Read the rest of the question 
	// in order to get the description of the functions.
	f(x);

	// TODO : Print the 'int' pointed by 'x' and 'y' (after the function call of 'f')_.
	// Display 6 and 6, why ?
	std::cout << "*x = " << *x << " ; *y = " << *y << std::endl;
	// On the first line, the function f modifies the content of the address pointed
	// by the pointer x. This is the same address pointed by the pointer y. Hence,
	// a change in x changes y. 
	// The second line of the function f creates a copy of the pointer x, allocates
	// the copy of x to a new memory address, and stores a new value inside the new 
	// address. However, the initial pointer x does not point to this new address,
	// hence, the new value stored at the new address is not related does not change
	// the value of *x.

	// TODO : Define a variable 'a' of type 'int' with value = 8.
	int a = 8;

	// TODO : Passe the variable 'a' to the function 'f'.
	f(&a);

	// TODO : Print the content of 'a' (displays 6).
	std::cout << "a = " << a << std::endl;

	// TODO : The 'main' (program entrance), passes 'x' to the function 'g'.
	g(x);

	// TODO : Print the int pointed by the pointers 'x' and 'y'.
	// Displays 10 and 9, why ?
	std::cout << "*x = " << *x << " ; *y = " << *y << std::endl;
	// The first step of the function g changes the value stored at the 
	// address where the pointer x points. The pointer y points at the
	// same address, hence the value *y also changes.
	// The second line of the function's code makes the pointer x to point to a new
	// memory addresse (because it uses a reference to the pointer x), 
	// and stores the value 10. The address pointed by the pointer y is 
	// not changed, hence the result. 

	// TODO : Try to pass the variable 'a' to the function 'g'.
	// Why is there a problem ?

	// g(&a);
	// The parameter of the function 'g' is passed by 'non-const reference'. 
	// In such cases, the argument must be of the same type as the parameter.
	// Temporary values are not allowed. In this specific case (&a) is a temporary
	// value.

	// TODO : Create a variable that points towards 'a'. Pass this variable to
	// the function 'g' (takes two lines).
	int* w = &a;
	g(w);  // Note : In this case, w is not a temporary value because it has been
	//        evaluated in the line int* w = &a.

// TODO : Print the content of 'a' and the int pointed by the variable 
// which pointed towards 'a'. (Displays 9 and 10).
	std::cout << "a = " << a << " ; *w = " << *w << std::endl;

	// The question does not ask to deallocate memory.
}


// Description of functions.
// Note : Define the functions 'f' and 'g' here.
// 
// TODO :
// The function 'f' takes a pointer of 'int' as only parameter and does not return
// anything : Puts 6 in the 'int' pointed by the parameter. Dynamically allocates a 
// new 'int' and stores the pointer in the function parameter. Puts 7 in that 'int'.
void f(int* ptrX)
{
	*ptrX = 6;
	ptrX = new int(7);

}


// TODO :
// The function 'g' is a copy of the function 'f', but takes a reference to a pointer
// of 'int', as only parameter (instead of a direct pointer). The function 'g' does
// not return a value. The values 6 and 7 from the 'f' functions are changed to 
// 9 and 10, for the 'g' function.
void g(int*& ptrX)
{
	*ptrX = 9;
	ptrX = new int(10);
}

