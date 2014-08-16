struct tree_node{
	int value;
	struct tree_node* left;
	struct tree_node* right;
};

struct tree_node* tree_from_file(char*);
struct tree_node* create_node(int);
void destroy_tree(struct tree_node*);
int maximal_sum (struct tree_node*);
