#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_node.h"

#define TREE_NODE_BUF_SIZE 1024

int num_nodes = 0;

struct tree_node* create_node(int val_in){
	num_nodes += 1;
	struct tree_node* ret = calloc(1, sizeof(struct tree_node));

	ret -> value = val_in;

	return ret;
}

struct tree_node* tree_from_file(char* file_path){
	FILE* f_in = fopen(file_path, "r");
	char* line = calloc(TREE_NODE_BUF_SIZE, sizeof(char));
	int curr_len;	
	
	struct tree_node** curr_row;
	struct tree_node** prev_row;
	int prev_row_len;
	
	struct tree_node* ret;

	fgets(line, TREE_NODE_BUF_SIZE, f_in);

	ret = create_node(atoi(line));

	prev_row  = calloc(1, sizeof(struct tree_node*));
	prev_row[0] = ret;
	prev_row_len = 1;

	curr_len = 2;
	while(fgets(line, TREE_NODE_BUF_SIZE, f_in) != NULL){
		curr_row = calloc(strlen(line)/3, sizeof(struct tree_node*));

		char* curr_item = calloc(3, sizeof(char));

		for (int curr = 0; curr < curr_len; curr++){
			

			strncpy(curr_item, line+(3*curr), 2);

			curr_row[curr] = create_node(atoi(curr_item));

			if(curr < prev_row_len){
				prev_row[curr] -> left = curr_row[curr];
			}

			if(curr != 0){
				prev_row[curr - 1] -> right = curr_row[curr];
			}
		}

		free(prev_row);
		prev_row = curr_row;
		prev_row_len = curr_len;

		free(curr_item);

		curr_len +=1;
	}

	free(line);
	free(curr_row);
	fclose(f_in);

	printf("File Ingestion Complete with %d nodes\n", num_nodes);

	return ret;
}

int maximal_sum (struct tree_node* node_in){
	int ret = 0;
	
	if(node_in == NULL){
		return ret;
	}else if(node_in -> left == NULL && node_in -> right == NULL){
		return node_in -> value;
	}else{
		int right = maximal_sum(node_in -> right);
		int left = maximal_sum(node_in -> left);

		ret = (left > right) ? left : right;

		ret += node_in -> value;
	}
	return ret;
}

static void destroy_left_node(struct tree_node* node_in){
	if(node_in == NULL){return;}

	destroy_left_node(node_in -> left);

	free(node_in);
}

void destroy_tree (struct tree_node* node_in){
	num_nodes -= 1;
	
	if(node_in == NULL){return;}

	destroy_left_node(node_in -> left);

	destroy_tree(node_in -> right);

	free(node_in);

}

