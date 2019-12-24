#pragma once

template <typename T>
class BubbleSort
{
public:
	static inline void swap(T arr[], int i, int j)
	{
		T tmp = std::move(arr[i]);
		arr[i] = std::move(arr[j]);
		arr[j] = std::move(tmp);
	}

	static void sort(T arrHead[], int size)
	{
		
	}


};

