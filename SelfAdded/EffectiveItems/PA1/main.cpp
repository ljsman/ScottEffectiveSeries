//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Framework.h"
//#include "ItemHeader.h"
#include "StackT.h"
int main()
{
	char* newStackPtr = (char*)malloc(32);

	StackT<char> stackT(32);
	stackT.InitStack(newStackPtr);
	Trace::out("EXIT");
}


