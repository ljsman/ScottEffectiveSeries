#pragma once
//template <class T>
//class StackT
//{
//private:
//	T* baseElementPtr;
//	int top;
//	unsigned int capacity;
//	int isEmpty;//maybe can just use this->top to indicate the emptiness of the stack.
//public:
//	StackT() = delete;
//	/*
//		top = -2 means not valid stack position
//		top = -1 means valid stack position and the stack is empty
//	*/
//	StackT(T* stackT, unsigned size)
//		: baseElementPtr(nullptr), top(-2), capacity(0), isEmpty(1)
//	{
//		this->InitStack(stackT, size);
//		if (isEmpty)
//		{
//			Trace::out("Empty New Stack Obj Created with Cap. of %d bytes\n", this->capacity);
//		}
//		else
//		{
//			Trace::out("Non-Empty New Stack Obj Created, Maybe there is an error!!!\n");
//		}
//		
//	}
//	
//	void InitStack(T* stackT, unsigned maxSize);
//};
//
//template <class T>
//void StackT<T>::InitStack(T* stackT, unsigned maxSize)
//{
//	//maxSize is the number of type T the caller wants, capacity is the number of bytes allocated
//	const unsigned tmpCap = sizeof(T) * maxSize;
//	this->baseElementPtr = (T*)malloc(tmpCap);
//	assert(this->baseElementPtr);
//	//giving out the pointer to the caller and all other info. about the current stack
//	stackT = this->baseElementPtr;
//	this->capacity = tmpCap;
//	this->top = -1;//this is a valid status of stack object which is empty
//
//	Trace::out("NEW STACK %p\n", stackT);
//	//return stackT;
//}

class StackT
{
private:
	char* baseElementPtr;
	int top;
	unsigned int capacity;
	int isEmpty;//maybe can just use this->top to indicate the emptiness of the stack.
public:
	StackT() = delete;
	/*
		top = -2 means not valid stack position
		top = -1 means valid stack position and the stack is empty
	*/
	StackT(unsigned size)
		: baseElementPtr(nullptr), top(-2), capacity(0), isEmpty(1)
	{
		this->InitStack(size);
		if (isEmpty)
		{
			Trace::out("Empty New Stack Obj Created with Cap. of %d bytes\n", this->capacity);
		}
		else
		{
			Trace::out("Non-Empty New Stack Obj Created, Maybe there is an error!!!\n");
		}

	}

	void InitStack(unsigned maxSize);
	char* getPtr()
	{
		return this->baseElementPtr;
	}
};

