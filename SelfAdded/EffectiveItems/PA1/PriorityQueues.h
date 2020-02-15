#pragma once
#include "Heap.h"
class PriorityQueues
{
private:
	Heap data;
public:
	void insert(int);
	int maximum();
	int extractMax();
	void increaseKey(int, int);
	void sort()
	{
		this->data.sort();
	}
};

