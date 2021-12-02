#pragma once
#include "TreeNode.h"

using namespace treenode;

namespace bstree {

	class BSTree {
	private:
		TreeNode* root;
		int nodes;
	public:
		// ctor & dtor:
		BSTree() : root(nullptr), nodes(0) {}
		~BSTree() { destroyBSTree(root); root = nullptr; }

		// Actions:
		bool isEmpty();
		void destroyBSTree(TreeNode* node);
		int size();
		TreeNode* get();
		TreeNode* Parent(TreeNode* node);
		TreeNode* Max(TreeNode* node);
		TreeNode* Find(char key);
		void Insert(char key);
		void Delete(char key);
		
		// Traversing:
		void Inorder();
		void Preorder();
		void Postorder();
	};
}