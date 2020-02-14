#include "Heap.h"

Heap::Heap()
	: data({-1, 4, 1, 3, 2, 16, 9 ,10, 14, 8, 7}), firstIndex(1), lastIndex(this->data.size() - 1),
	heapSize(this->data.size() - 1)
{
	Trace::out("\tHeap Object Constructing...\n");
	//srand(time(NULL));
	//
	//for (int counter = size-1; counter >= 0; --counter)
	//{
	//	/*Trace::out("Address of signed counter %p\n", &counter);
	//	Trace::out("%d\n", counter);*/
	//	data.push_back( (rand()%100) + 1);
	//}

	Trace::out("\tHeap Object Constructed\n");
}

void Heap::build_max_heap()
{
	Trace::out("Building a max heap...\n");
	for (int counter = (this->heapSize) / 2; counter >= 1; --counter)
	{
		this->max_heapify(counter);
	}

}

void Heap::max_heapify(int param_index)
{

	Trace::out("Heapifying Max...\n");
	int largest = param_index;
	int rootIndex = param_index;

	while (1)
	{
		int left = this->getLeftChild(rootIndex);
		int right = this->getRightChild(rootIndex);

		//check if left child is larger than root
		if (left <= this->lastIndex && (this->data.at(left) > this->data.at(rootIndex)))
		{
			largest = left;
		}
		
		//check if right child is larger than root
		if (right <= this->lastIndex && (this->data.at(right) > this->data.at(largest)))
		{
			largest = right;
		}

		if (largest != rootIndex)
		{
			this->swap(largest, rootIndex);
		}
		else if (largest == rootIndex)
		{
			break;
		}
		rootIndex = largest;
	}
}

void Heap::sort()
{
	this->build_max_heap();

	for (int counter = heapSize; counter >= 2; --counter)
	{
		this->swap(FIRSTELEMENT, lastIndex);
		--(this->lastIndex);
		this->max_heapify(FIRSTELEMENT);
	}
}