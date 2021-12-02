#include "BTree.h"
//using namespace treenode;

namespace btree {

	bool BTree::isEmpty()
	{
		if (root == nullptr) {
			cout << "Tree is Empty." << endl;
			return true;
		}
		return false;
	}
	void BTree::Inorder()
	{
		if (root != nullptr)
			root->Inorder();

	}
	void BTree::Preorder()
	{
		if (root != nullptr)
			root->Preorder();
	}
	void BTree::Postorder()
	{
		if (root != nullptr)
			root->Postorder();
	}

	void BTree::Insert(char key, int freq, TreeNode* node)
	{
		TreeNode* new_node = new TreeNode;

		if (key < node->getKey()) {
			if (node->Left() != nullptr) {
				Insert(key, freq, node->Left());
			}
			else {
				node->setLeft(new_node);
				node->Left()->setKey(key);
				node->Left()->setFreq(freq);
				node->Left()->setLeft(nullptr);
				node->Left()->setRight(nullptr);
			}
		}
		else if (key >= node->getKey())
		{
			if (node->Right() != nullptr)
				Insert(key, freq, node->Right());
			else {
				node->setRight(new_node);
				node->Right()->setKey(key);
				node->Right()->setFreq(freq);
				node->Right()->setRight(nullptr);
				node->Right()->setLeft(nullptr);
			}
		}

	}

	void BTree::Insert(char key, int freq) {
		if (root != nullptr) {
			Insert(key, freq, root);
		}
		else {
			TreeNode* new_node = new TreeNode;
			root->set(key, freq, nullptr, nullptr);
		}
	}
	void BTree::destroyBTree(TreeNode* node)
	{
		if (node != nullptr) {
			destroyBTree(node->Left());
			destroyBTree(node->Right());
			delete node;
		}
	}
}