//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Framework.h"
#include "ItemHeader.h"
#include <string>

void foo()
{
	TestingClass tc;
}

struct Obj
{
	Obj() = default;
	Obj(int param_a, int param_b) : a{ param_a }, b{ param_b }
	{

	}
	Obj(const Obj&) = default;
	Obj& operator = (const Obj&) = default;
	Obj& operator = (Obj&& tmp)
	{
		this->a = std::move(tmp.a);
		this->b = std::move(tmp.b);
		return *this;
	}
	int a;
	int b;
};

struct Obj0 : public Obj
{
	Obj0() : a{ 12 }, b{ 13 }{};
	Obj0(const Obj0&) = default;
	Obj0& operator = (const Obj0&) = default;
	//Obj0& operator = (Obj0&& tmp)
	//{
	//	this->a = std::move(tmp.a);
	//	this->b = std::move(tmp.b);
	//	return *this;
	//}
	int a;
	int b;
};

inline void genNum(int head[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		head[i] = (rand()%16);
	}
}

int main()
{
	/*
	if a string has more than 16 chars, the literals will be places at different address
	and the string class will have the address of the first char.
	if the string has less than 16 chars, the literals will be with the string class.
	*/
	{
		//string fName = "F = jinshi";//16 chars
		//string lName = "L = li";

		//string* ptrFname = new string{ "jinshi" };
		//string* ptrLname = new string{ "li" };

		//Trace::out("%s, %s\n", lName.c_str(), fName.c_str());
		//ptrFname->swap(*ptrLname);
		//Trace::out("%s, %s\n", lName.c_str(), fName.c_str());
	}
	const int size = 60000;
	int insertionArr[size];
	int bubbleArr[size];
	int bubbleArr0[size];
	int selectionArr[size];

	genNum(insertionArr, size);
	genNum(bubbleArr, size);
	genNum(bubbleArr0, size);
	genNum(selectionArr, size);

	PerformanceTimer insertion;
	insertion.Tic();
	InsertionSort<int>::sort(insertionArr, size);
	insertion.Toc();
	Trace::out("\nInsertion Time = %f\n",insertion.TimeInSeconds());

	PerformanceTimer bubbleTimer;
	bubbleTimer.Tic();
	BubbleSort<int>::sort(bubbleArr, size);
	bubbleTimer.Toc();
	Trace::out("\nBubbleSort Time = %f\n", bubbleTimer.TimeInSeconds());

	PerformanceTimer selectionTimer;
	selectionTimer.Tic();
	SelectionSort<int>::sort(selectionArr, size);
	selectionTimer.Toc();
	Trace::out("\nSelection Time = %f\n", selectionTimer.TimeInSeconds());


	Trace::out("EXIT");
}


