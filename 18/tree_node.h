struct tree_node;
struct tree_node* tree_from_file(char*);
struct tree_node* create_node(int);
void destroy_tree(struct tree_node*);
void put_left (struct tree_node*, int);
void put_right (struct tree_node*, int);
int maximal_sum (struct tree_node*);
