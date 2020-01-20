#include "StackT.h"
template void StackT<char>::InitStack(char* stackT);

template <class T>
void StackT<T>::InitStack(T* stackT)
{
	Trace::out("NEW STACK %p\n", stackT);
}

