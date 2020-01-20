#pragma once
template <class T>
class StackT
{
private:
	T* baseElement;
	int top;
	int capcity;
public:
	StackT(int size)
		: baseElement(nullptr), top(-1), capcity(size)
	{
		Trace::out("NEW STACK\n");
	}
	
	void InitStack(T* stackT);
};

//template <class T>
//void StackT<T>::InitStack(T* stackT)
//{
//	Trace::out("NEW STACK %p\n", stackT);
//}

