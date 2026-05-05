
// This exercise is similar to exercise 1, but a struct is used.
// Note : There is at least one place where the operator '->' has to be used.
// (Do not do (*pointer).attribute), where attribute corresponds to an entry
// in the struct.
// 
// Each step usually takes a line of code.
// The next lines present the 'struct' data structures used for this exercise.

# include <iostream>

struct A {
	int x, y;
};

struct B {
	A* values;
	int nValues;
};

// Declare and define the functions here.

// TODO : 
// The function 'printA' takes an 'A' (struct) as paramter, without copying its value (also
// without using a pointer), then displays the values of 'x' and 'y'.
void printA(const A& a) 
{
	std::cout << "x = " << a.x << " ;  y = " << a.y << std::endl;
}

// TODO : 
// The function 'increment' takes an A (struct) as parameter, without copying its value
// and without using a pointer, to be able to update the value of the passed argument:
// Increments the values of 'x' and 'y' (2 operations).
void increment(A& a)
{
	a.x++;
	a.y++;
}

// TODO :
// The function 'printB' takes a B (struct) as parameter, without copying its value : 
// Prints nValues first values pointed by the aray pointed by values.
void printB(const B& b)
{
	std::cout << "x  ;   y" << std::endl;
	for (size_t i = 0; i < b.nValues; i++) {
		std::cout << (b.values[i]).x << " ; " << (b.values[i]).y << std::endl;
	}
}

// TODO : 
// The main : 
int main()
{
	// TODO : Defines a variable 'a' of type 'A', with x = 3, and y = 4.
	A a = { 3, 4 };

	// TODO : Prints 'a' (displays 3 and 4).
	printA(a);

	// TODO : Makes the variable 'b' to point towards the variable 'a'.
	A* b = &a;

	// TODO : Print the 'A' pointed by 'b'. Displays (3 and 4), why ?
	printA(*b);

	// TODO : Affects to what is pointed by 'b' the values 5 and 6,
	// in a single operation.
	*b = { 5, 6 };

	// TODO : Print 'a'. Displays 5 and 6, why ?
	printA(a);
	// 'b' points at the address of 'a' (where the value of 'a' is stored).
	// Hence, changing the value from 'b' also changes the value of 'a'.

	// TODO : Increment (using the function) what is pointed by 'b'.
	increment(*b);

	// TODO : Print 'a'. Displays 6 and 7, why ?
	printA(a);
	// 'b' points are the place where the values carried by a are stored. When
	// 'b' initiates a change of value, the values changed re the once at the
	// address of 'a'. Hence, the values the variable a stores are updated at
	// the same time 'b' updates values.

	// TODO : Print only the value of 'x' pointed by 'b' (displays 6).
	std::cout << "x pointed by b = " << b->x << std::endl;

	// TODO : Dynamically allocate an 'A' (struct) by copying what is pointed by 'b'
	// (copy in one step, not specifying 'x' and 'y'), and storing it in the
	// pointer 'c.
	A* c = new A(*b);

	// TODO :  Increment (using the function) what is pointed by 'b'.
	increment(*b);

	// TODO : Print what is pointed by 'b' and 'c' (2 opertions).
	// Displays 7, 8 and 6, 7. Why ?
	printA(*b);
	printA(*c);
	// Initially, 'c' is created in a memory distinct from the memory occupied by 'b'.
	// The values stored at the address 'b' points are copied inside the address where
	// 'c' points. However, the addresses pointed by 'b' and 'c' are different. 
	// Calling the function increment on what is pointed by 'b' changes the content of
	// the address pointed by 'b', which is distinct from the address pointed by 'c'.
	// Hence, the content of the address pointed by 'c' remains unchanged.

	// TODO : Define a variable 'd' of type 'B' by allocating an array of two entries.
	// The values of the array entries are the values pointed by b and c.
	// Note : nValues = 2 for this exercise.
	B d = { new A[2]{*b, *c}, 2 };

	// TODO : Print 'd' (displays 7, 8, and 6, 7.
	printB(d);

	// TODO : Copy 'd', in one step, in a variable 'e' (without copying the values of the
	// array.
	B e = d;

	// TODO : In the array 'e', put 9 in the 'x' of the second value.
	(e.values[1]).x = 9;

	// TODO : Print 'd'. Display 7, 8, and 9, 7. Why ?
	printB(d);
	// The struct 'e' of type 'B' has copied the value of the struct 'd' of type 'B'.
	// The pointer contained in the struct B has been copied. That is the pointer 
	// in the variable 'e' is a copy of the pointer in the vairable 'd'; They point
	// towards the same address. Hence, changing the value contained in the shared ç
	// address from anyone of these two pointers chngers the value contained in the
	// address pointed by the other pointer (same address).

	// The exercise does not ask to deallocate memory.

}
