#include<iostream>
enum Status { ok, not_exists, already_exists, yes, no };

class Node {
public:
	Node() = delete;
	Node(int val_);
	Node(Node& copy_) = delete;

	Node* left_ = nullptr;
	Node* right_ = nullptr;
	int data_ = -1;

	~Node();
private:
};

class Tree_p {
public:
	Tree_p() = default;
	Tree_p(Tree_p& copy_) = delete;

	Status find_key(int val_) const;
	Status append_node(int val_);
	Status delete_node(int val_);

	Node* head_ = nullptr;
	~Tree_p();
private:
};