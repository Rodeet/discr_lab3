#include<Tree_vector/Tree_v.h>

Tree_v::Tree_v(Tree_v& copy_) {
	for (size_t i = 0; i < copy_.tree_.size(); i++) {
		this->tree_.push_back(copy_.tree_[i]);
	}
}

Status Tree_v::find_key(int val_) const {
	if (this->tree_.empty()) return no;

	int cur_ = 0;
	while(true) {
		if (this->tree_[cur_] == val_) return yes;
		else {
			if (this->tree_[cur_] < val_) {
				if (2 * cur_ + 2 >= this->tree_.size()) return no;
				else cur_ = 2 * cur_ + 2;
			}
			else {
				if (2 * cur_ + 1 >= this->tree_.size()) return no;
				else cur_ = 2 * cur_ + 1;
			}
		}
	} 
}

Status Tree_v::append_node(int val_) {
	if (!this->tree_.size()) {
		this->tree_.push_back(val_);
		return ok;
	}
	if (this->find_key(val_) == yes) return already_exists;

	int cur_ = 0, level_ = 1;
	while (true) {
		if (2 * cur_ + 2 < this->tree_.size()) {
			if (val_ < this->tree_[cur_]) {
				if (this->tree_[2 * cur_ + 1] == -1) {
					this->tree_[2 * cur_ + 1] = val_;
					return ok;
				}
				else {
					level_++;
					cur_ = 2 * cur_ + 1;
				}
			}
			else {
				if (this->tree_[2 * cur_ + 2] == -1) {
					this->tree_[2 * cur_ + 2] = val_;
					return ok;
				}
				else {
					level_++;
					cur_ = 2 * cur_ + 2;
				}
			}
		}
		else {
			int size = 1;
			for (int i = 0; i < level_+1; i++) {
				size *= 2;
			}
			while (this->tree_.size() != size - 1) {
				this->tree_.push_back(-1);
			}
		}
	}
}

Status Tree_v::delete_node(int val_) {
	if (this->find_key(val_) == no) return not_exists;

	int cur_ = 0;
	while (true) {
		if (this->tree_[cur_] == val_) break;
		else {
			if (this->tree_[cur_] < val_) {
				cur_ = 2 * cur_ + 2;
			}
			else {
				cur_ = 2 * cur_ + 1;
			}
		}
	}

	if (2 * cur_ + 2 > this->tree_.size() || (this->tree_[2 * cur_ + 1] == -1 && this->tree_[2 * cur_ + 2] == -1)) { //нет потомков
		if (!cur_) { //голова 
			this->tree_.pop_back();
			return ok;
		}
		this->tree_[cur_] = -1;
		return ok;
	}

	std::vector<int> q_;
	int i = 0;
	if (this->tree_[2 * cur_ + 1] != -1 && this->tree_[2 * cur_ + 2] == -1 || this->tree_[2 * cur_ + 1] == -1 && this->tree_[2 * cur_ + 2] != -1) { //один левый или правый потомок
		this->tree_[2 * cur_ + 1] != -1 && this->tree_[2 * cur_ + 2] == -1 ? q_.push_back(2 * cur_ + 1) : q_.push_back(2 * cur_ + 2);
		this->tree_[cur_] = this->tree_[q_[i]];
		this->tree_[q_[i]] = -1;
	}
	else {
		int tmp_ = 2 * cur_ + 2;//два потомка 
		while (2 * tmp_ + 1 < this->tree_.size() && this->tree_[2 * tmp_ + 1] != -1) {
			tmp_ = 2 * tmp_ + 1;
		}
		this->tree_[cur_] = this->tree_[tmp_];
		this->tree_[tmp_] = -1;
		if (2 * tmp_ + 2 < this->tree_.size() && this->tree_[2 * tmp_ + 2] != -1) q_.push_back(2 * tmp_ + 2);
	}
	while (i != q_.size()) {
		if (q_[i] * 2 + 2 < this->tree_.size()) {
			if (this->tree_[2 * q_[i] + 1] != -1) q_.push_back(q_[i] * 2 + 1);
			if (this->tree_[2 * q_[i] + 2] != -1) q_.push_back(q_[i] * 2 + 2);
		}
		i++;
	}
	for (int ind_ : q_) {
		int el = this->tree_[ind_];
		this->tree_[ind_] = -1;
		this->append_node(el);
	}
	return ok;
}

//void Tree_v::print() const {
//	print(0, 0);
//}
//
//void Tree_v::print(int node_index, int level) const {
//	if (this->tree_[node_index] == -1) return;
//
//	if (!(2 * node_index + 2 >= this->tree_.size())) print(2*node_index + 2, level + 1);
//
//	for (int i = 0; i < level; i++) {
//		std::cout << "    ";
//	}
//	std::cout << this->tree_[node_index] << std::endl;
//
//	if (!(2 * node_index + 1 >= this->tree_.size())) print(2 * node_index + 1, level + 1);
//}
