# Heap
Heaps using Priority Queues with C++
**Heaps**
	A heap is a complete binary tree that satisfies two properties, one that is concerning its shape and the other concerning the order of the elements. Each of whose elements contains a value that is greater than or equal to the value of each of its children.
	
**Full Binary Tree**
	A binary tree in which all of the leaves are on the same level and every node has two children.

**Complete Binary Tree**
	 A binary tree that is either full or full though the next-to-last level, with the leaves on the last level as far to the left as possible.
	 
## Operations on Heap
ReheapDown(heap, root, bottom)

**Function**: Restores the order property of heaps to the tree between root and bottom
	
**Precondition**: The order property of heaps may be violated only by the root node of the tree.
	
**Postcondition**: The order property applies to all elements of the heap.

ReheapUp(heap, root, bottom)

**Function:** Restores the order property of heap between root and the bottom.
**Precondition:** The order property is satisfied from the root of the heap violated the order property.
**Postcondition:** The order property applies to all the elements of the heap from root though bottom.
