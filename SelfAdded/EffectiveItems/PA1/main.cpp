//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Framework.h"
#include "ItemHeader.h"
#include <vector>
#include <iterator>

void alterPtr(char* ptr)
{

}
int main()
{
	vector<int> vetInt{ 1,2,3,4,5,6 };
	input_iterator_tag iit;
	vector<int>::iterator itrBegin = vetInt.begin();
	itrBegin.operator++();
	vector<int>::iterator itrEnd = vetInt.end();

	Trace::out("The distance is %d\n", distance(itrBegin, itrEnd));
	//StackT<char> stackT(charPtr ,32);
	//StackT stackT(32);
	//charPtr = stackT.getPtr();
	//assert(charPtr);
	//Trace::out("EXIT");
}


