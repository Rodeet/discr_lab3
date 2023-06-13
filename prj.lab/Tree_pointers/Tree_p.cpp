#include<Tree_pointers/Tree_p.h>

Node::Node(int val_) {
	this->data_ = val_;
}
Node::~Node() = default;

Status Tree_p::find_key(int val_) const {
	if (this->head_ == nullptr) return no;
	
	Node* cur_ = this->head_;
	while (true) {
		if (cur_->data_ == val_) return yes;
		if (val_ > cur_->data_) {
			if (cur_->right_ == nullptr) return no;
			else cur_ = cur_->right_;
		}
		else {
			if (cur_->left_ == nullptr) return no;
			else cur_ = cur_->left_;
		}
	}
}

Status Tree_p::append_node(int val_) {
	if (this->head_ == nullptr) {
		this->head_ = new Node(val_);
		return ok;
	}

	if (this->find_key(val_) == yes) return already_exists;

	Node* cur_ = this->head_;
	while (true) {
		if (val_ < cur_->data_) {
			if (cur_->left_ == nullptr) {
				cur_->left_ = new Node(val_);
				return ok;
			}
			else {
				cur_ = cur_->left_;
			}
		}
		else {
			if (cur_->right_ == nullptr) {
				cur_->right_ = new Node(val_);
				return ok;
			}
			else {
				cur_ = cur_->right_;
			}
		}
	}
}

Status Tree_p::delete_node(int val_) {
	if (this->find_key(val_) == no) return not_exists;

	Node* cur_ = this->head_;
	Node* par_ = this->head_;
	while (true) {
		if (cur_->data_ == val_) break;
		par_ = cur_;
		if (val_ > cur_->data_) {
			cur_ = cur_->right_;
		}
		else {
			cur_ = cur_->left_;
		}
	}

	if (cur_->left_ == nullptr && cur_->right_ == nullptr) { //нет детей
		if (cur_->data_ == head_->data_) { //голова
			delete head_;
			this->head_ = nullptr;
			return ok;
		}
		if (par_->left_ != nullptr && par_->left_->data_ == cur_->data_) par_->left_ = nullptr;
		else par_->right_ = nullptr;
		delete cur_;
		return ok;
	}

	Node* tmp_;
	if ((cur_->left_ != nullptr && cur_->right_ == nullptr) || (cur_->right_ != nullptr && cur_->left_ == nullptr)) { //только один левый предок или правый
		if (cur_->left_ != nullptr && cur_->right_ == nullptr) {
			tmp_ = cur_->left_;
		}
		else {
			tmp_ = cur_->right_;
		}
		cur_->data_ = tmp_->data_;
		cur_->left_ = std::move(tmp_->left_);
		cur_->right_ = std::move(tmp_->right_);
		delete tmp_;
	}
	else { //два потомка
		tmp_ = cur_->right_;
		Node* tpar_ = cur_;
		while (true) { 
			if (tmp_->left_ == nullptr) break;
			tpar_ = tmp_;
			tmp_ = tmp_->left_;
		}
		tpar_->right_ = tmp_->right_;	
		cur_->data_ = tmp_->data_;
		delete tmp_;
	}
	return ok;
}

Tree_p::~Tree_p() {
	while (this->head_ != nullptr) {
		this->delete_node(this->head_->data_);
	}
}