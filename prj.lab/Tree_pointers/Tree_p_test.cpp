#include<Tree_pointers/Tree_p.h>

int main() {
	Tree_p t_;	
	t_.append_node(10);
	t_.append_node(20);
	t_.append_node(15);
	t_.append_node(13);
	t_.append_node(17);
	t_.append_node(14);
	t_.delete_node(10);
}