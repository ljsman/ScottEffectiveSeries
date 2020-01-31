#include "StackT.h"

void StackT::InitStack(unsigned maxSize)
{
	//maxSize is the number of type T the caller wants, capacity is the number of bytes allocated
	const unsigned tmpCap = sizeof(char) * maxSize;
	this->baseElementPtr = (char*)malloc(tmpCap);
	assert(this->baseElementPtr);
	//giving out the pointer to the caller and all other info. about the current stack
	this->capacity = tmpCap;
	this->top = -1;//this is a valid status of stack object which is empty

	Trace::out("NEW STACK %p\n", this->baseElementPtr);
}
