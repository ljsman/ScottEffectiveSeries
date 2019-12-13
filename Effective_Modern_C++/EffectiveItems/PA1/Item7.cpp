#include "Item7.h"

Item7::Item7()
{
	this->firstTest();
	this->secondTest();
	this->thirdTest();
	this->forthTest();
	this->fifthTest();
}

//non-initializer_list cotr
void Item7::firstTest()
{
	Widget* w1 = new Widget(10, true);
	//wPtr = &w1;
	Widget w2{ 10, true };
	Widget w3(10, 5.0);
	Widget w4{ 10, 5.0 };
	delete w1;
}

void Item7::secondTest()
{
	Widget0 w1(10, true);
	Widget0 w2{ 10, true };//10 and true converted to long double
	Widget0 w3(10, 5.0);
	Widget0 w4{ 10, 5.0 };//10 and 5.0 converted to long double
}

void Item7::thirdTest()
{
	Widget0 w4{ 10, 5.0 };
	float val = w4;

	//This is what appears to be different from what Scott said.
	//MS compiler enforces the behavior of copy ctor with use of {}
	Widget0 w5(w4);
	Widget0 w6{ w4 };
	Widget0 w7 = w4;

	//what about move ctor?
	//can we move w4 multipul times?
	//MS also enforces the behavior of move ctor with use of {}
	Widget0 w8(move(w4));
	Widget0 w9{ move(w4) };
	Widget0 w10 = move(w4);
}

void Item7::forthTest()
{
	/*The follow statement is calling the initializer_list cotr, even if this is
		perfect match of Widget1(int i, double d); ctor.
	*/
	//Widget1 w{10, 5.0f};

	//compiler cant convert, because now initilizer_list is taking only strings 
	//and there is no conversion between int, double to string.
	Widget2 w0{ 10, 5.0f };
}

void Item7::fifthTest()
{
	//calling default ctor
	Widget3 widget;
	//calling default ctor, because empty brace means empty argument, NOT empty initializer list.
	Widget3 widget0{};

	Widget3 widget1({1,2,3});
}