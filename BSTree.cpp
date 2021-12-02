#include "BSTree.h"
//using namespace treenode;

namespace bstree {

	void BSTree::Inorder()
	{
		if (root != nullptr)
			root->Inorder();
	}
	void BSTree::Preorder()
	{
		if (root != nullptr)
			root->Preorder();
	}
	void BSTree::Postorder()
	{
		if (root != nullptr)
			root->Postorder();
	}

	int BSTree::size() {
		return nodes;
	}
	bool BSTree::isEmpty()
	{
		if (root == nullptr) {
			cout << "Tree is Empty." << endl;
			return true;
		}
		return false;
	}
	void BSTree::destroyBSTree(TreeNode* node)
	{
		if (node != nullptr) {
			destroyBSTree(node->Left());
			destroyBSTree(node->Right());
			delete node;
		}
	}
	TreeNode* BSTree::get()
	{
		return root;
	}
	
	TreeNode* BSTree::Find(char key)
	{
		TreeNode* temp = root;
		while (temp != nullptr)
		{
			if (key == temp->getKey())
				return temp;
			else if (key < temp->getKey())
				temp = temp->Left();
			else
				temp = temp->Right();
		}
		return nullptr;
	}
	
	TreeNode* BSTree::Max(TreeNode* node)
	{
		TreeNode* temp = root;
		while (temp->Right() != nullptr)
			temp = temp->Right();
		return temp;
	}

	TreeNode* BSTree::Parent(TreeNode* node)
	{
		TreeNode* temp = root;
		TreeNode* parent = root;

		if (node == root)
			return nullptr;
		while (temp != nullptr)
		{
			if (node == temp)
			{
				return parent;
			}
			else if (node->getKey() < temp->getKey()) {
				parent = temp;
				temp = temp->Left();
			}
			else {
				parent = temp;
				temp = temp->Right();
			}
		}
	}
	
	void BSTree::Insert(char key)
	{
		TreeNode* exist;
		exist = Find(key);
		if (exist != nullptr)    // check if the ket is already exists
		{
			exist->addFreq(); // add 1 to the existing key in the tree
			return;
		}
		TreeNode* temp = root;       // current node in tree
		TreeNode* parent = nullptr;  // parent of temp
		TreeNode* new_node;          // new allocated node

		while (temp != nullptr) // find a parent for new_node
		{
			parent = temp;
			if (key < temp->getKey())
				temp = temp->Left();
			else
				temp = temp->Right();
		}
		new_node = new TreeNode(key,1); // alocating memory
		if (parent == nullptr)
			root = new_node;
		else if (key < parent->getKey())
			parent->setLeft(new_node);
		else
			parent->setRight(new_node);
		
		nodes++;
	}
	
	void BSTree::Delete(char key)
	{
		TreeNode* temp = Find(key);
		TreeNode* parent = Parent(temp);
		TreeNode* r = nullptr;

		if (temp == nullptr)
		{
			cout << "Error - doesn't exists." << endl;
			return;
		}
		if ((temp->Left() != nullptr) || (temp->Right() != nullptr)) // there is at least one child
		{
			if (temp == parent->Left())
			{
				if (temp->Left() != nullptr)
					parent->setLeft(temp->Left());
				else
					parent->setLeft(temp->Right());
			}
			else
			{
				if (temp->Left() != nullptr)
					parent->setRight(temp->Left());
				else
					parent->setRight(temp->Right());
			}
			delete temp;
		}
		else // there are 2 childrens
		{
			r = Max(temp->Left());
			//swap temp with r:
			temp->setFreq(r->Freq());
			temp->setKey(r->getKey());

			//delete r:
			parent = Parent(r);
			if (r == parent->Left())
					parent->setLeft(r->Left());
			else
				parent->setRight(r->Left());
			delete r;
		}
	}
}