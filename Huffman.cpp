#include "Huffman.h"

namespace huffman {

	Huffman::Huffman(TreeNode* A)
	{
		tree = A;
		h = height(tree) - 1;
		file_size = 0;
		coding = new int[h];           // this array will containg the current character's encode;
		for (int i = 0; i < h; i++)    // init the coding array to '-1' for print_code function.
			coding[i] = -1;
	}
	Huffman::~Huffman()
	{
		delete[] coding;
		tree = nullptr;
	}

	int Huffman::height(TreeNode* node)
	{
		int l_h, r_h;
		if (node == nullptr)
			return 0;
		else {
			l_h = height(node->Left());
			r_h = height(node->Right());
			if (l_h >= r_h)
				return l_h + 1;
			else
				return r_h + 1;
		}
	}


	void Huffman::print_code(TreeNode* node)
	{
		int i = 0;
		while ((coding[i] != -1) && (i < h))
			cout << coding[i++];
		cout << endl;
		file_size += node->Freq() * i;
	}

	void Huffman::encode()
	{
		int i = 0;
		p_encode(tree, i);
	}
	int Huffman::get_file_size()
	{
		return file_size;
	}
	void Huffman::p_encode(TreeNode* node, int& i)
	{
	
		if (node == nullptr)
			return;
		if ((node->Left() == nullptr) && (node->Right() == nullptr))
		{
			if (node->getKey() == '\n')
				cout << "'\\n': ";
			else if (node->getKey() == ' ')
				cout << "white space ' ': ";
			else if (node->getKey() == '\t')
				cout << "'\\t': ";
			else
				cout << "'" << node->getKey() << "' : ";
			print_code(node);
			
			if((i<h)&&(i>=0))
				coding[i] = -1;
			i--;
			return;
		}
		if (node->Left() != nullptr)
		{
			coding[i] = 0;
			i++;
			p_encode(node->Left(), i);
		}
		if (node->Right() != nullptr)
		{
			
			coding[i] = 1;
			i++;
			p_encode(node->Right(), i);
		}
		if ((i < h) && (i >= 0))
			coding[i] = -1;
		i--;



	}
}