#include "arrList.h"
#include <iostream>

int main() {
	aList a({1,2,3,4,5,6,7});
	std::cout << "List a created by vector:\n" ;
	a.print();
	aList b(a);
	std::cout << "List b created by coping:\n";
	b.print();
	aList c = b;
	std::cout << "List b created using the = operator:\n";
	c.print();
	a.push(8);
	std::cout << "Push 8 in list a:\n";
	a.print();
	a.remove(2);
	std::cout << "Remove 2 from list a:\n";
	a.print();
	std::cout << "Size of list a: " << a.size() << "\n\n\n\n\n";
}