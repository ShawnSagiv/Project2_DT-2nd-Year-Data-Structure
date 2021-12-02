#include "TreeNode.h"

namespace treenode {

	const char TreeNode::getKey()
	{
		return ch;
	}
	
	const int TreeNode::Freq()
	{
		return freq;
	}
	void TreeNode::set(char c, int _freq, TreeNode* _left, TreeNode* _right)
	{
		freq = _freq;
		ch = c;
		left = _left;
		right = _right;
	}
	TreeNode::~TreeNode()
	{
		if (left != nullptr)
			delete left;
		if (right != nullptr)
			delete right;
	}
	void TreeNode::Inorder()
	{
		if (left != nullptr)
			left->Inorder();
		cout << "Key: " << ch << ", Freq: " << freq << endl;
		if (right != nullptr)
			right->Inorder();
	}
	void TreeNode::Preorder()
	{	
		cout << "Key: " << ch << ", Freq: " << freq << endl;
		if (left != nullptr)
			left->Preorder();
		if (right != nullptr)
			right->Preorder();
	}
	void TreeNode::Postorder()
	{
		if (left != nullptr)
			left->Postorder();
		if (right != nullptr)
			right->Postorder();
		cout << "Key: " << ch << ", Freq: " << freq << endl;
	}

	void TreeNode::setLeft(TreeNode* node)
	{
		left = node;
	}
	void TreeNode::setRight(TreeNode* node)
	{
		right = node;
	}
	TreeNode* TreeNode::Left()
	{
		return left;
	}
	TreeNode* TreeNode::Right()
	{
		return right;
	}

	void TreeNode::setFreq(int f) {
		freq = f;
	}
	void TreeNode::addFreq()
	{
		freq ++;
	}
	void TreeNode::setKey(char c) {
		ch = c;
	}

	TreeNode& TreeNode::operator=(const TreeNode& other)
	{
		if (this != &other)
		{
			ch = other.ch;
			freq = other.freq;
			left = other.left;
			right = other.right;
			return *this;
		}
	}
	
	bool TreeNode::is_leaf()
	{
		if ((left == nullptr) && (right == nullptr))
			return true;
		return false;
	}
}