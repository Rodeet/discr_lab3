#include <iostream>
#include <vector>
#include <algorithm> 

class aList {
public:

	aList() = default;
	aList(const std::vector<int>& val);
	aList(const aList& copy);
	~aList() = default;
	aList& operator=(const aList& rhs);
	bool isEmpty();
	void push(const int& val);
	std::vector<int>::const_iterator find(const int& val) const;
	void remove(const int& val);
	void print() const;
	size_t size();
private:
	std::vector<int> data;

};

