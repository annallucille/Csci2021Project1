#include "heap.h"
#include "tree.h"
 
#ifndef CODE_H
#define CODE_H

char huffman_code[256][20];
char code_buffer[20];
int z;

/**********************************************************************************************
 *
 * Declare and define any local function here to support your implementation of the heap
 *
 **********************************************************************************************/

 
void init_code()  {
	int i;
	for(i = 0; i < 256; i++)  {
 		huffman_code[i][0] = 0;
	}
}
 
void print_code()   {
	printf("\n----------------\n  CODES BEGIN\n-----------------\n");

    for(int i = 0; i < 256; i++)  {
        if(huffman_code[i][0] != 0)  {
			if(isprint(i))
                        	printf("%d (%c): %s\n", i, i, huffman_code[i]);
			else
                        	printf("%d (--): %s\n", i, huffman_code[i]);
		}
    }
	printf("\n----------------\n  CODES END\n-----------------\n");
}

/* 
 * Traverse the huffman tree and store the huffman codes in huffman_code.
 * You may use code_buffer as a temp variable to store partial results. 
 */

void gen_code(huffman_tree_node *node, int pos){
	if (node->left!=NULL){
		for(int i =0; i<=strlen(huffman_code[pos]);i++){
			huffman_code[pos+1][i] = huffman_code[pos][i];
		}
		huffman_code[pos+1][strlen(huffman_code[pos])+1] = '0';
		gen_code(node->left, pos+1);
	}
    if(node->right!=NULL){
		for(int i =0; i<=strlen(huffman_code[pos]);i++){
			huffman_code[pos+1][i] = huffman_code[pos][i];
		}
		huffman_code[pos+1][strlen(huffman_code[pos])+1]='1';
		gen_code(node->right, pos+1);
	}
}

#endif  // CODE_H
