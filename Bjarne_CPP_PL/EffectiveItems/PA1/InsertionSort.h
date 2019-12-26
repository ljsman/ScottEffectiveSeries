#pragma once
template <typename T>
class InsertionSort
{
public:
	static T* privHead;

	//push the pointer passed in to register
	static void setHead(T* arrHead)
	{
		privHead = arrHead;
	}

	//taking an array
	
	static void sort(T arr[], int n)
	{
		//int counter = 0;
		for (int j = 1; j < n; ++j)
		{
			T key = arr[j];
			int i = j - 1;
			//can NOT enter the code when i is 0, 
			//beacuse next interation i will be out of bound and arrHead[i] is reading it
			while (i >= 0 && (key < arr[i]))
			{
				//counter++;
				//Trace::out("\t\tSWAP\n");
				arr[i + 1] = arr[i];
				i--;
			}
			arr[i + 1] = key;
		}
		//Trace::out("Counter = %d\n", counter);

		//int i, j;
		//for (i = 1; i < n; i++)
		//{
		//	T key = arr[i];
		//	j = i - 1;

		//	/* Move elements of arr[0..i-1], that are
		//	greater than key, to one position ahead
		//	of their current position */
		//	while (j >= 0 && arr[j] > key)
		//	{
		//		arr[j + 1] = arr[j];
		//		j = j - 1;
		//	}
		//	arr[j + 1] = key;
		//}
	}

};

