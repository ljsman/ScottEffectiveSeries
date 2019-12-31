#pragma once

template <typename T>
class BubbleSort
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
		
		
		//int counter = 0;
		for (int i = 0; i < n - 1; i++)
		{
			// Last i elements are already in place  
			for (int j = 0; j < n - i - 1; j++)
				if (arr[j] > arr[j + 1])
				{
					//counter++;
					swap(arr, j, j + 1);
				}
		}
		//Trace::out("Counter = %d\n", counter);

	}

	static void impvSort(T arr[], int n)
	{
		int i, j;
		bool swapped;
		for (i = 0; i < n - 1; i++)
		{
			swapped = false;
			for (j = 0; j < n - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr, j, j + 1);
					swapped = true;
				}
			}

			// IF no two elements were swapped by inner loop, then break 
			if (swapped == false)
				break;
		}
	}
	


};

