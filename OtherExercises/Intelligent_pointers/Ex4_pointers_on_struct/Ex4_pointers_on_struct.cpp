
// This exercise is similar to exercise 1, but a struct is used.
// Note : There is at least one place where the operator '->' has to be used.
// (Do not do (*pointer).attribute), where attribute corresponds to an entry
// in the struct.
// 
// Each step usually takes a line of code.
// The next lines present the 'struct' data structures used for this exercise.

#include <iostream>
#include <memory>

struct A {
	int x, y;
};

struct B {
	std::shared_ptr<A[]> values;
	int nValues;
};

// Declare and define the functions here.

// TODO : 
// The function 'printA' takes an 'A' (struct) as paramter, without copying its value (also
// without using a pointer), then displays the values of 'x' and 'y'.
void printA(const A& a)
{
	std::cout << "struct A{int x, y; }; : " << "x = " << a.x << " ; " << 
		"y = " << a.y << std::endl;
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
	for (size_t i = 0; i < b.nValues; i++) {
		printA(b.values[i]);
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
	std::shared_ptr<A> b(&a, [](A*) {}); // Using a "custom deleter" that does nothing.
	// Note : Wrapping an existing variable ('a') without allocating memory 
	// (the previous line of code above) is not recommended. It has been 
	// used only to complete the exercise, which indirectly compares the 
	// uses of raw and intelligent pointers.

	// TODO : Print the 'A' pointed by 'b'. Displays (3 and 4), why ?
	printA(*b);

	// TODO : Affects to what is pointed by 'b' the values 5 and 6,
	// in a single operation.
	*b = { 5, 6 };
	// 'b' points at the address where the value of 'a' is stored. Updating
	// the value at the address where 'b' points automatically updates the
	// value of 'a' (it is the same address, which holds a single value, that
	// can be updated, either using 'a' or variables pointing towards the 
	// adress of a).

	// TODO : Print 'a'. Displays 5 and 6, why ?
	printA(a);

	// TODO : Increment (using the function) what is pointed by 'b'.
	increment(*b);

	// TODO : Print 'a'. Displays 6 and 7, why ?
	printA(a);
	// Incrementing what is pointed by 'b' increments what is
	// stored at the address of 'a', because 'b' points at the
	// address of 'a'. Hence, the value of 'a' is updated.

	// TODO : Print only the value of 'x' pointed by 'b' (displays 6).
	std::cout << "x = " << b->x << std::endl;

	// TODO : Dynamically allocate an 'A' (struct) by copying what is pointed by 'b'
	// (copy in one step, not specifying 'x' and 'y'), and storing it in the
	// pointer 'c.
	std::shared_ptr<A> c = std::make_shared<A>(*b);

	// Increment what is pointed by 'b' using the function.
	increment(*b);

	// TODO : Print what is pointed by 'b' and 'c' (2 opertions).
	// Displays 7, 8 and 6, 7. Why ?
	printA(*b);
	printA(*c);
	// 'b' and 'c' point at distint memory addresses. Hence, updating
	// 'b' does not update 'c'. Initially, 'c' takes the value of the
	// content of the address of 'b'. However the addresses of 'b' and
	// 'c' are not linked.


	// TODO : Define a variable 'd' of type 'B' by allocating an array of two entries.
	// The values of the array entries are the values pointed by b and c.
	// Note : nValues = 2 for this exercise.
	const int nEntries = 2;
	A values[nEntries] = { *b, *c };
	B d = { std::make_shared<A[]>(nEntries), nEntries };
	for (size_t i = 0; i < nEntries; i++) {
		d.values[i] = values[i];
	}

	// TODO : Print 'd' (displays 7, 8, and 6, 7.
	printB(d);

	// TODO : Copy 'd', in one step, in a variable 'e' (without copying the 
	// values of the array.
	B e = d;

	// TODO : In the array 'e', put 9 in the 'x' of the second value.
	e.values[1].x = 9;

	// TODO : Print 'd'. Display 7, 8, and 9, 7. Why ?
	printB(d);
	// 'e' is a copy (struct copy) of 'd'. The pointer 'values' in 'e' is
	// a copy of the pointer in the 'values' in 'd', hence they point at
	// the same address. Changing the value at this address from either 'd'
	// or 'e' automatically changes the value of the value the other pointer
	// points to, as both pointers point to a single address. 
	// This exercise does not ask to unallocate memory.

}
