#pragma once
#include "TreeNode.h"
using namespace treenode;

namespace heap {

	
	class Heap {
	private:
		TreeNode* data;          // pointer to data array
		int maxSize;             // Max size of heap
		int heapSize;            // Current size of heap - logSize
		int allocated;           // 1 if heap allocated memory
		static int Left(int node);
		static int Right(int node);
		static int Parent(int node);
		void FixHeap(int node);
		void Swap(int a, int b);
		void forest();           // update left&right = nullptr for each leaf
	public:
		Heap(int max);
		Heap(TreeNode A[], int n);
		~Heap();
		TreeNode GetMin() { return data[0]; }
		TreeNode* DeleteMin();
		void Insert(TreeNode* item);

	};
}