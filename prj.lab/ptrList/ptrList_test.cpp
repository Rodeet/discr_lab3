#include "ptrList.h"


int main() {

	std::vector<int> vec = { 1, 5, 7, 8 };
	std::vector<int> vec2 = { 134, 45, 344, 567 };
	
	List list;
	std::cout << "..................STARTING TESTS..................\n\n";
	
	std::cout << "..................PUSH 2..................\n\n";
	list.push(2);
	list.print();
	std::cout << "..................PUSH 4..................\n\n";
	list.push(4);
	list.print();
	std::cout << "..................PUSH 3..................\n\n";
	list.push(3);
	list.print();
	std::cout << "..................REMOVE 4..................\n\n";
	list.remove(4);
	list.print();
	std::cout << "..................REMOVE 4..................\n\n";
	list.remove(4);
	std::cout << "..................REMOVE 2..................\n\n";
	list.remove(2);
	list.print();
	std::cout << "..................REMOVE 3..................\n\n";
	list.remove(3);
	list.print();
	std::cout << "..................PUSH 1337..................\n\n";
	list.push(1337);
	list.print();
	std::cout << "..................CREATING WITH A VECTOR {1, 5, 7, 8}..................\n\n";
	List list1(vec);
	list1.print();
	std::cout << "..................CREATING WITH A VECTOR { 134, 45, 344, 567 }..................\n\n";
	List list2(vec2);
	list2.print();
	std::cout << "..................ASSIGNING list2 TO list1..................\n\n";
	std::cout << "list1: ";
	list1.print();
	std::cout << "list2: ";
	list2.print();
	std::cout << "Assigning...\n";
	list1 = list2;
	std::cout << "list1 after assigning: ";
	list1.print();
	std::cout << "..................CREATING list3 VIA list2..................\n\n";
	List list3(list2);
	std::cout << "list3: ";
	list3.print();
	std::cout <<"list3 size: " << list3.size();



}