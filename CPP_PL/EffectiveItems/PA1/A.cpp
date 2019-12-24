//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "ThreadHelper.h"
#include "ItemHeader.h"
A::A()
{
	TestingClass tc;
	TestingClass* tcPtr = new TestingClass;
	// Thread 2 begins here
	Trace::out("\n");
	ThreadHelper::DebugBegin(1);


	// burn time
	int i = 0;
	for (int j = 0; j < 10; j++)
	{
		ThreadHelper::TabMe(2);
		Trace::out("count:%d\n", i++);
	}

	ThreadHelper::DebugEnd(1);
	Trace::out("\n");
}

