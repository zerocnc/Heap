#pragma once


///<summary>The Priority Queue is arranged to support access to the highest priority item.</summary>
///<remarks>
/// Assumptions: Before any call is made to a priority queue opoeration, the queue has been declared and a constructor has been applied.
///</remarks>
template<class T>
class PQType
{
public:
	PQType(int);
	~PQType();

	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(T item);
	void Dequeue(T& item);

private:
	int numItems;
	Heap<T> items;
	int maxItems;
};

///<summary>
/// The constructor needs to take in a max integer
/// <param name="max">Needs to be of type Integer. </param>
///</summary>
template<typename T>
PQType<T>::PQType(int max)
{
	maxItems = max;
	items.elements = new T[max];
	numItems = 0;
}

///<summary>
/// Initializes the queue to an empty state.
///</summary>
///<remarks>
/// Postcondition: Queue is empty
///</remarks>
template<typename T>
void PQType<T>::MakeEmpty()
{
	numItems = 0;
}

///<summary>
/// Clears memory.
///</summary>
template<class T>
PQType<T>::~PQType()
{
	delete[] items.elements;
}

///<summary>
/// Removes element with highest priority queue and returns it in item.
///</summary>
template<class T>
void PQType<T>::Dequeue(T& item)
{
	item = items.elements[0];
	items.elements[0] = items.elements[numItems - 1];
	numItems--;
	items.ReheapDown(0, numItems - 1);
}

template<typename T>
void PQType<T>::Enqueue(T item)
{
	numItems++;
	items.elements[numItems - 1] = item;
	items.ReheapUp(0, numItems - 1);
}

template<class T>
bool PQType<T>::IsFull() const
{
	return numItems == maxItems;
}

template<class T>
bool PQType<T>::IsEmpty() const
{
	return numItems == 0;
}