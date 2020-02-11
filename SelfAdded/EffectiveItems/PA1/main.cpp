//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Framework.h"
#include "ItemHeader.h"
#include <vector>
#include <iterator>
#include <map>
#include <tuple>
#include <iostream>
#include <numeric>
//#include <typeinfo>
class A
{
private: int a;
public:
	int publicA = 11;
	A() : a{ 10 }
	{
		Trace::out("A : 111\n");
	}

	A(const A& tmp) : a{ tmp.a }
	{
		Trace::out("A : 112\n");
	}

	A& operator = (const A& tmp)
	{
		Trace::out("A : 113\n");
		this->a = tmp.a;
		return *this;
	}

	A(A&& tmp) : a{ std::move(tmp.a) }
	{
		Trace::out("A : 114\n");
	}

	A& operator = (A&& tmp)
	{
		Trace::out("A : 115\n");
		this->a = std::move(tmp.a);
		return *this;
	}

	int getA()
	{
		return this->a;
	}
	virtual void test()
	{
		Trace::out("test function in class A\n");
	}
};

class B : public A
{
private:
	int b;
public:
	
	B() : b{ 20 }
	{
		Trace::out("B : 111\n");
	}

	B(const B& tmp) : b{ tmp.b }
	{
		Trace::out("B : 112\n");
	}

	B& operator = (const B& tmp)
	{
		Trace::out("B : 113\n");
		this->b = tmp.b;
		return *this;
	}

	B(B&& tmp) : b{ std::move(tmp.b) }
	{
		Trace::out("B : 114\n");
	}

	B& operator = (B&& tmp)
	{
		Trace::out("B : 115\n");
		this->b = std::move(tmp.b);
		return *this;
	}

	int getB()
	{
		return this->b;
	}
	void test()
	{
		Trace::out("test function in class B\n");
	}
};

class C : public B
{
private:
	int c;
public:

	C() : c{ 30 }
	{
		Trace::out("C : 111\n");
	}

	C(const C& tmp) : c{ tmp.c }
	{
		Trace::out("C : 112\n");
	}

	C& operator = (const C& tmp)
	{
		Trace::out("C : 113\n");
		this->c = tmp.c;
		return *this;
	}

	C(C&& tmp) : c{ std::move(tmp.c) }
	{
		Trace::out("C : 114\n");
	}

	C& operator = (C&& tmp)
	{
		Trace::out("C : 115\n");
		this->c = std::move(tmp.c);
		return *this;
	}

	void test() override
	{
		A::test();
		Trace::out("test function in class C\n");
	}
};

A* convariantRule()
{
	return new C;
}

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int numLength = 0;
	cout << "How many numbers would you like to enter? \n" << endl;

	cin >> numLength;
	vector<int> intVector(numLength, 0);

	int counter = 1;
	for (vector<int>::iterator it = intVector.begin(); it != intVector.end(); it++)
	{
		cout << "Please enter " << counter << " number: " << endl;
		cin >> *it;
		counter++;
	}

	//vector<int>::iterator it = intVector.begin();
	cout << accumulate(intVector.begin(), intVector.end(), 0) << endl;


	string str = {"jinshi"};
	auto tu = make_tuple(10, 10.3, 4.12, str, 'l');

	string typ = typeid(get<3>(tu)).name();

	if (typeid(get<3>(tu)).name() == typeid(str).name())
	{
		Trace::out("the string in tu --> %s", get<3>(tu).c_str());
	}
	

	vector<int> vetInt{ 1,2,3,4,5,6 };

	for (int element : vetInt)
	{
		Trace::out("The current value is --> %d\n", element);
	}

	map<int, int> mapp;
	mapp.insert(pair<int, int>{1, 10});
	mapp.insert(pair<int, int>{2,20});
	mapp.insert(pair<int, int>{4, 40});
	//Trace::out("The distance is %d\n", distance(itrBegin, itrEnd));
	//StackT<char> stackT(charPtr ,32);
	//StackT stackT(32);
	//charPtr = stackT.getPtr();
	//assert(charPtr);
	//Trace::out("EXIT");
}


