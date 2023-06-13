#include "arrList.h"

aList::aList(const aList& copy) : data(copy.data) {}

aList::aList(const std::vector<int>& val) {
	this->data = val;
}

aList& aList::operator=(const aList& rhs) {
	if (this == &rhs) return *this;
	data = rhs.data;
	return *this;
}

bool aList::isEmpty() {
	if (this->data.empty()) return 1;
	return 0;
}

void aList::push(const int& val) {
	this->data.push_back(val);
}

std::vector<int>::const_iterator aList::find(const int& val) const {
	return std::find(data.begin(), data.end(), val);
}

void aList::remove(const int& val) {
	data.erase(std::find(data.begin(), data.end(), val));
}

void aList::print() const {
	for (int i = 0; i < data.size();++i) {
		std::cout << this->data[i] << " ";
	}
	std::cout << std::endl;
}

size_t aList::size() {
	return data.size();
}