#include "Heap.h"
//using namespace treenode;

namespace heap {

	Heap::Heap(int max)
	{
		data = new TreeNode[max];
		maxSize = max;
		heapSize = 0;
		allocated = 1;
	}
	Heap::Heap(TreeNode A[], int n)
	{
		heapSize = maxSize = n;
		data = A;
		forest();
		allocated = 0;
		for (int i = ((n / 2) - 1); i >= 0; i--)
			FixHeap(i);
	}
	Heap::~Heap()
	{
		if (allocated)
			delete[] data;
		data = nullptr;
	}

	void Heap::forest()
	{
		for (int i = 0; i < heapSize; i++)
		{
			data[i].setLeft(nullptr);
			data[i].setRight(nullptr);
		}
	}
	int Heap::Left(int node) {
		return (2 * node + 1);
	}
	int Heap::Right(int node) {
		return (2 * node + 2);
	}
	int Heap::Parent(int node) {
		return ((node - 1) / 2);
	}

	void Heap::FixHeap(int node)
	{
		int min;
		int left = Left(node);
		int right = Right(node);

		if ((left < heapSize) && (data[left].Freq() < data[node].Freq()))
			min = left;
		else
			min = node;
		if ((right < heapSize) && (data[right].Freq() < data[min].Freq()))
			min = right;

		if (min != node)
		{
			Swap(node, min);
			FixHeap(min);
		}
	}
	void Heap::Swap(int a, int b)
	{
		// t = a
		// a = b
		//b = t

		TreeNode* temp;
		temp = new TreeNode();
		*temp = data[a];
		data[a] = data[b];
		data[b] = *temp;
		/*
		temp.set(data[a].getKey(), data[a].Freq(), data[a].Left(), data[a].Right());
		
		
		data[a].setFreq(data[b].Freq());
		data[a].setKey(data[b].getKey());
		data[a].setLeft(data[b].Left());
		data[a].setRight(data[b].Right());

		data[b].setFreq(temp->Freq());
		data[b].setKey(temp->getKey());
		data[b].setLeft(temp->Left());
		data[b].setRight(temp->Right());
		*/
	}

	TreeNode* Heap::DeleteMin() {
		if (heapSize < 1) {
			cout << "Error - nothing to delete.";
			exit(1);
		}
		TreeNode* min;
		min = new TreeNode();
		*min = data[0];
		heapSize--;
		data[0] = data[heapSize];
		FixHeap(0);
		return min;
	}
	void Heap::Insert(TreeNode* item)
	{
		if (heapSize == maxSize)
		{
			cout << "Error - not enough memory to insert.";
			exit(1);
		}
		int i = heapSize;
		heapSize++;
		while ((i > 0) && (data[Parent(i)].Freq() > item->Freq()))
		{
			data[i] = data[Parent(i)];
			i = Parent(i);
		}
		data[i] = *item;
	}

}