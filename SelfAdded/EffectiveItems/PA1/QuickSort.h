#pragma once
#include <vector>
using namespace std;
using IntArr = vector<int>;

class QuickSort
{
private:
	IntArr data;

	void swap(IntArr& arr, const int left, const int right)
	{
		auto const temp = arr.at(left);
		arr.at(left) = arr.at(right);
		arr.at(right) = temp;
	}
	
	int getPivot(IntArr& arr, const int start, const int end)
	{
		//choosing the last element as the pivot
		const int pivot = arr.at(end);
		int startIndex = start;
		
		for(int i = start; i < end; ++i)
		{
			//if equal to pivot still need to move to the left
			if(arr.at(i) <= pivot)
			{
				this->swap(arr, i, startIndex);
				startIndex++;
			}
		}
		//after the loop all element that smaller than pivot are at left side of the index. vice versa
		this->swap(arr, startIndex, end);
		return startIndex;
	}
public:
	QuickSort(IntArr arr) : data(arr)
	{
		
	}
	void sort(IntArr& arr, const int start, const int end)
	{
		if(start < end)
		{
			int p_index = this->getPivot(arr, start, end);
			sort(arr, start, p_index-1);
			sort(arr, p_index+1, end);
		}
	};
};

