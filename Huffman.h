#pragma once
#include "TreeNode.h"
using namespace treenode;
namespace huffman {

	class Huffman {
	private:
		TreeNode* tree;          // huffman tree
		int file_size;           // the size of the file in bits
		int h;                   // tree's height
		int* coding;             // an array of 1 / 0 - the code for each characters

		int height(TreeNode* node);	             // calculate the tree's height
		void p_encode(TreeNode* node, int& i);   // recursive func to encode huffman tree
		void print_code(TreeNode* node);         // prints coding array

	public:
		Huffman(TreeNode* A); // allocate coding
		~Huffman();
		void encode();        
		int get_file_size();        


	};
}