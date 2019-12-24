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
	
	static void sort(T arrHead[], int size)
	{
		int counter = 0;
		Trace::out("\tStart Sorting...\n");
		for (int j = 1; j < size; ++j)
		{
			T key = arrHead[j];
			int i = j - 1;
			//can NOT enter the code when i is 0, 
			//beacuse next interation i will be out of bound and arrHead[i] is reading it
			while (i >= 0 && (key < arrHead[i]))
			{
				counter++;
				Trace::out("\t\tSWAP\n");
				arrHead[i + 1] = arrHead[i];
				i--;
			}
			arrHead[i + 1] = key;
		}
		Trace::out("Counter = %d", counter);
	}

};

