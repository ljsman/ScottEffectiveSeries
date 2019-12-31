#pragma once
#include "Framework.h"
#include "ItemHeader.h"
class SortAlgos
{
public:
	inline void genNum(int head[], int size)
	{
		for (int i = 0; i < size; ++i)
		{
			head[i] = (rand() % 16);
		}
	}
	void compareSorts()
	{
		const int size = 60000;
		int insertionArr[size];
		int bubbleArr[size];
		//int bubbleArr0[size];
		int selectionArr[size];

		genNum(insertionArr, size);
		genNum(bubbleArr, size);
		//genNum(bubbleArr0, size);
		genNum(selectionArr, size);

		PerformanceTimer insertion;
		insertion.Tic();
		InsertionSort<int>::sort(insertionArr, size);
		insertion.Toc();
		Trace::out("\nInsertionSort Time = %f\n", insertion.TimeInSeconds());

		PerformanceTimer bubbleTimer;
		bubbleTimer.Tic();
		BubbleSort<int>::sort(bubbleArr, size);
		bubbleTimer.Toc();
		Trace::out("\nBubbleSort Time = %f\n", bubbleTimer.TimeInSeconds());

		PerformanceTimer selectionTimer;
		selectionTimer.Tic();
		SelectionSort<int>::sort(selectionArr, size);
		selectionTimer.Toc();
		Trace::out("\nSelectionSort Time = %f\n",selectionTimer.TimeInSeconds());
	}
};
