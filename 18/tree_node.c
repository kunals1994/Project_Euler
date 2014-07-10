#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_node.h"

#define TRUE 0
#define FALSE 1

#define TREE_NODE_BUF_SIZE 1024

struct tree_node{
	int value;
	struct tree_node* left;
	struct tree_node* right;
};

struct tree_node* create_node(int val_in){
	struct tree_node* ret = calloc(1, sizeof(struct tree_node));

	ret -> value = val_in;

	return ret;
}

struct tree_node* tree_from_file(char* file_path){
	FILE* f_in = fopen(file_path, "r");
	char* line = calloc(TREE_NODE_BUF_SIZE, sizeof(char));
	struct tree_node* ret = calloc (1, sizeof(struct tree_node));

	fgets(line, TREE_NODE_BUF_SIZE, f_in);
	
	while(fgets(line, TREE_NODE_BUF_SIZE, f_in) != NULL){
		printf("%lu \n", strlen(line)/3);
	}

	free(line);
	fclose(f_in);

	return NULL;
}

int maximal_sum (struct tree_node* node_in){
	int ret = 0;
	
	if(node_in == NULL){
		return ret;
	}else if(((node_in -> left) -> value) > ((node_in -> right) -> value)){
		ret = node_in -> value + maximal_sum(node_in -> left);
	}else{
		ret = node_in -> value + maximal_sum(node_in -> right);
	}
	return ret;
}

void destroy_tree (struct tree_node* node_in){
	
	if(node_in == NULL){return;}

	struct tree_node* n1 = node_in -> left;
	struct tree_node* n2 = node_in -> right;

	free(node_in);

	destroy_tree(n1);
	destroy_tree(n2);
}

void put_left (struct tree_node* node_in, int left_val){
	if(node_in == NULL){return;}
	node_in -> left = create_node(left_val);
}

void put_right (struct tree_node* node_in, int right_val){
	if(node_in == NULL){return;}
	node_in -> right = create_node(right_val);
}

