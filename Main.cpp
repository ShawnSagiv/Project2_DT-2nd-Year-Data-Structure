
// Guy Shamay, ID:311456891
// Shawn Sagiv, ID:204816631

// Program's Descriction:

// The program will receive as input a text file name
// and will first count the number of occurrences of each character in the file.
// the program will build a binary search tree from the characters in the file, 
// The key will be a character, and the satellite data will be the number of instances of that character in the file.

// The program will then run the Huffman algorithm that builds a tree that represents an optimal 'Resha' code for the file.
// And, using huffman's tree the program will print to the screen the characters in the file and for each character its huffman coding in bits.
// In addition, the program will print the size of the encoded file(Huffman tree's size).


#include "Header.h"
#include "Heap.h"
#include "BSTree.h"
#include "Huffman.h"

using namespace bstree;
using namespace treenode;
using namespace heap;
using namespace huffman;

BSTree* file_to_bstree(ifstream& in);                              // a function that builds a binarty search tree that will contain the characters in the txt file and the frequency of each character
TreeNode* HuffmanAlgo(TreeNode* c, int n);                         // Huffman Algorithm
void tree_to_array(TreeNode* root, int& index, TreeNode arr[]);    // a function that build and array of TreeNode from BS tree.

int main()
{
	char name[250];                 // contain the file's name
	int n,index=0;                  // n - number of characters, index - index of the array C
	BSTree* my_tree;                // a binary search tree that will contain all n characters from file, and its frequency
	TreeNode* huff_tree;            // Huffman tree
	
	cout << "Enter File's Name:";
	cin >> name;

	ifstream in(name, ios::in);     // opening a txt file for reading
	if (!in) {
		cout << "Error with infile" << endl;
		exit(-1);
	}

	//creating a binary search tree from file:
	my_tree = file_to_bstree(in);
	n = my_tree->size();            // n - number of different characters in bs tree

	
	if (my_tree->get()->is_leaf())
	{
		//There is only 1 character, and size of file is the frequancy
		if (my_tree->get()->getKey() == '\n')
			cout << "'\\n': 1" << endl;
		else if (my_tree->get()->getKey() == ' ')
			cout << "white space ' ': 1" << endl;
		else if (my_tree->get()->getKey() == '\t')
			cout << "'\\t': 1" << endl;
		else
			cout << "'" << my_tree->get()->getKey() << "': 1"<< endl;
		cout << "File's Size: " << my_tree->get()->Freq();
	}
	else
	{
		TreeNode* C;               // an array of TreeNode
		C = new TreeNode[n];       // in the size of the characters

		// converting the binary search tree to an array
		tree_to_array(my_tree->get(), index,C);  

		// Huffman Algorithm
		huff_tree = HuffmanAlgo(C, n);

		Huffman H(huff_tree);
		H.encode(); // encoding the tree to Huffman's code

		// prints the file's size in bits:
		cout << "File's Size: " << H.get_file_size();
		
		//free memory:
		C->~TreeNode();
	}
}
BSTree* file_to_bstree(ifstream& in)
{
	char ch;
	BSTree* my_tree;
	my_tree = new BSTree();
	in >> noskipws>> ch;
	while (!in.eof())
	{
		
		my_tree->Insert(ch);
		in >> ch;
	}
	return my_tree;
}

TreeNode* HuffmanAlgo(TreeNode* C, int n)
{
	Heap Q(C, n);
	TreeNode* node;

	for (int i = 1; i < n; i++){
		node = new TreeNode();
		node->setLeft(Q.DeleteMin());
		node->setRight(Q.DeleteMin());
		node->setFreq(node->Left()->Freq() + node->Right()->Freq());
		Q.Insert(node);
	}
	return Q.DeleteMin();
}

void tree_to_array(TreeNode* root, int& index, TreeNode arr[])
{
	if (root == nullptr) // tree is empty
		return; // nothing to do
	else
	{
		if (root->Left() != nullptr)
			tree_to_array(root->Left(), index, arr);
		if (root->Right() != nullptr)
			tree_to_array(root->Right(), index, arr);

		arr[index++] = *root;
	}
}

