#include "PriorityQueues.h"
int PriorityQueues::maximum()
{
	return this->data.getFirst();
}

int PriorityQueues::extractMax()
{
	int max;
	if(!this->data.getHeapSize())
	{
		 Trace::out("The heap is empty");
	}

	max = this->data.getFirst();
	this->data.swap(1, this->data.getHeapSize());
	this->data.decreaseHeapSize();

	this->data.max_heapify(1);
	return max;
}

void PriorityQueues::increaseKey(int index, int val)
{
	if (this->data.at(index) > val || index > this->data.getHeapSize())
	{
		Trace::out("invalid index or key value\n");
	}
	else
	{
		assert(this->data.at(index) == val);

		int parent = this->data.getParent(index);
		while (index > 1 &&
			val > this->data.at(parent))
		{
			this->data.swap(parent, index);
			index = parent;
			parent = this->data.getParent(index);
		}
	}
}

void PriorityQueues::insert(int keyValue)
{
	this->data.heapInsert(keyValue);
	
	this->increaseKey(this->data.getHeapSize(), keyValue);
}
