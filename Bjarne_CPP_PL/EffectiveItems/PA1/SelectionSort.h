#pragma once
template <class T>
class SelectionSort
{
public:
	static inline void swap(T arr[], int i, int j)
	{
		T tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	static void sort(T arr[], int n)
	{
		for (int i = 0; i < n - 1; ++i)
		{
			int min = i;
			for (int j = i + 1; j < n; ++j)
			{
				if (arr[j] < arr[min])
				{
					min = j;
				}
			}
			swap(arr, min, i);
		}
	}
};

