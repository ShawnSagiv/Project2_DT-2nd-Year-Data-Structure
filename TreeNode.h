#pragma once
#include "Header.h"

namespace treenode {
	
	// Binary Tree implementation

	class TreeNode {
	private:
		char ch;
		int freq;
		TreeNode* left, * right;
		//int allocated;
	public:
		// ctor & dtor:
		TreeNode() : left(nullptr), right(nullptr) { freq = 0;}
		//TreeNode(int allo) { allocated = allo; }
		TreeNode(char c, int _freq, TreeNode* _left, TreeNode* _right) :ch(c), freq(_freq), left(_left), right(_right) {}
		TreeNode(char c, int _freq) : ch(c), freq(_freq) { left = right = nullptr; }
		~TreeNode();

		// get:
		const char getKey();
		const int Freq();
		TreeNode* Left();
		TreeNode* Right();
		bool is_leaf();
		// set:
		void set(char c, int _freq, TreeNode* _left, TreeNode* _right);
		void setLeft(TreeNode* node);
		void setRight(TreeNode* node);
		void setFreq(int f);
		void addFreq();
		void setKey(char c);

		// Traversing:
		void Inorder();
		void Preorder();
		void Postorder();

		TreeNode& operator=(const TreeNode& other);
	};
}