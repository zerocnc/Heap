// Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <random>

int main()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 1000);

	int randDouble;

	int maxQ = 20;
	PQType<int> myPQ(maxQ);
	
	// Loads priority queue with random numbers.
	for (int ndx = 0; ndx < maxQ; ndx++)
	{
		randDouble = dist(mt);
		std::cout << randDouble << '\t';
		myPQ.Enqueue(randDouble);
	}
	std::cout << '\n';

	// Prints out priority queue with highest at top
	for (int ndx = 0; ndx < maxQ; ndx++)
	{
		myPQ.Dequeue(randDouble);
		std::cout << randDouble << '\t';
	}

	return 0;
}

