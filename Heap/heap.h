#pragma once

template<class T>
struct Heap
{
	void ReheapDown(int root, int bottom);
	void ReheapUp(int root, int bottom);
	T* elements;
	int numElements;
};

template<typename T>
void Swap(T& a, T& b)
{
	T tempVal = a;
	a = b;
	b = tempVal;
}

/// <summary>Restores the order property of heaps to the tree between root and bottom. Precondition</summary>
/// Post Condition: The order property of heaps may be violated only by the root node of the tree.
/// Pre Condition: The order property oapplies to all elements of the heap.
template<class T>
void Heap<T>::ReheapDown(int root, int bottom)
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;

	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}

		if (elements[root] < elements[maxChild])
		{
			Swap(elements[root], elements[maxChild]);
			ReheapDown(maxChild, bottom);
		}
	}

}

///<summary>Restores the order property to the heap between root and bottom.
/// Preconditions: The order property is satisfied from the root fo the heap though the next-to-last node; the last (bottom) node may violate the order
/// property. </summary>
template<typename T>
void Heap<T>::ReheapUp(int root, int bottom)
{
	int parent;

	if (bottom > root)
	{
		parent = (bottom - 1) / 2;
		if (elements[parent] < elements[bottom])
		{
			Swap(elements[parent], elements[bottom]);
			ReheapUp(root, parent);
		}
	}
}

