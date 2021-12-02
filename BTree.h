#pragma once
#include "TreeNode.h"
using namespace treenode;

namespace btree {
	class BTree {
	private:
		TreeNode* root;
	public:
		// ctor & dtor:
		BTree() : root(nullptr) {}
		~BTree() { destroyBTree(root); root = nullptr; }
		
		bool isEmpty();
		void destroyBTree(TreeNode* node);
		void Insert(char key,int freq ,TreeNode* node);
		void Insert(char key, int freq);

		// Traversing:
		void Inorder();
		void Preorder();
		void Postorder();
	};
}



