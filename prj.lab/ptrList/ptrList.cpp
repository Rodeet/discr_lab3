#include "ptrList.h"

bool List::isEmpty() const
{
	return head == nullptr;
}

void List::push(const int& val) {
	if (isEmpty()) {
		head = new Node(val);
		lastAddedNode = head;
		size_++;
		return;
	}
	else {
		Node* newnode = new Node(val);
		lastAddedNode->next = newnode;
		newnode->prev = lastAddedNode;
		lastAddedNode = newnode;
		size_++;
	}
}

void List::print() const {
	Node* ptr = head;
	if (isEmpty()) {
		std::cout << "The list is empty!\n";
		return;
	}
	while (ptr != nullptr)
	{
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << "\n";
}

void List::remove(const int& val) {
	if (isEmpty()) {
		std::cout << "Error! The list is already empty!\n";
		return;
	}
	else {
		Node* ptr = head;
		while (ptr != nullptr) {
			if (ptr->data == val) {
				Node* onDelete = new Node();
				onDelete = ptr;

				if(ptr->next != nullptr)ptr->next->prev = ptr->prev;

				if (ptr->prev != nullptr) {
					ptr->prev->next = ptr->next;
					lastAddedNode = ptr->prev;
				}
				else {
					head = ptr->next;
					lastAddedNode = head;
				}
				
				delete onDelete;
				std::cout << "Item " << val << " removed successfully\n";
				size_--;
				return;
			}
			else {
				ptr = ptr->next;
			}
		}
		std::cout << "Error! No such item in the list\n";
	}
}

List::List(const std::vector<int>& values) {
	for (int i = 0; i < values.size(); i++) {
		this->push(values[i]);
	}
	std::cout << "Constructed with vector\n";
}

void List::clear() {
	
	if (this->isEmpty()) return;

	while (lastAddedNode->prev != nullptr) {
		lastAddedNode = lastAddedNode->prev;
		
		Node* onDelete = lastAddedNode->next;
		delete onDelete;
	}

	delete lastAddedNode;
	head = nullptr;
	size_ = 0;
}

List& List::operator=(const List& rhs) {

	this->clear();

	if (rhs.isEmpty()) {
		return *this;
	}
	
	Node* tmp = rhs.head;
	while (tmp != nullptr) {
		this->push(tmp->data);
		tmp = tmp->next;
	}
	return *this;

}

List::List(const List& copy) {
	*this = copy;
}

List::~List() {
	this->clear();
}

size_t List::size() const {
	return this->size_;
}

