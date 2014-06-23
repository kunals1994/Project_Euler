#include "tree_node.c"

int main(int argc, char** argv){
	struct tree_node* num_tree;
	int sum;

	if(argc != 2){
		printf("usage: %s tree_file_in\n", argv[0]);
		return -1;
	}

	num_tree = tree_from_file(argv[1]);
	sum = maximal_sum(num_tree);
	destroy_tree(num_tree);

	return 0;
}