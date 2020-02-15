#pragma once
#define FIRSTELEMENT 1
#include <vector>
using namespace std;
//this is a max-heap implementation with vector
class Heap
{
private: 
	vector<int> data;
	int firstIndex;
	int lastIndex;
	int heapSize;
public:
	Heap();
	//how large you want the heap to be, size <= capacity 
	//Heap(int);
	~Heap() = default;
	Heap(const Heap& tmp) = default;
	Heap& operator = (const Heap& tmp) = default;

	int getFirst()
	{
		return this->data.at(FIRSTELEMENT);
	}
	void build_max_heap();
	void max_heapify(int);

	//implicit in-lined
	int getLeftChild(int root)
	{
		return 2 * (root);
	}

	int getRightChild(int root)
	{
		return (2 * root) + 1;
	}

	void swap(int leftIndex, int rightIndex)
	{
		//value at the index in the array, not the index itself
		int tempVal = this->data.at(leftIndex);
		this->data.at(leftIndex) = this->data.at(rightIndex);
		this->data.at(rightIndex) = tempVal;
	}

	void sort();

	int getParent(int index)
	{
		return index / 2;
	}
	int getHeapSize() const
	{
		return this->heapSize;
	}

	int& at(int index)
	{
		return this->data.at(index);
	}

	void heapInsert(int value)
	{
		this->data.push_back(value);
		this->increaseHeapSize();
	}
	
	void increaseHeapSize()
	{
		++(this->heapSize);
		this->lastIndex++;
	}
	void decreaseHeapSize()
	{
		--(this->heapSize);
	}
};

