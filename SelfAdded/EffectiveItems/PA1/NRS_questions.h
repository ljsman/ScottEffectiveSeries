//----------------------------------------------------------------------------
// Copyright 2020 Woo, Steve, NRS_TechInternship, all rights reserved.
// Edited by:	Jinshi Li
// Date:		03/03/2020 - 03/05/2020
// IDE:			Visual Studio Enterprise 2019(v142)
// SDK:			Windows 10.0.18362.0	
// Mode:		x86 Debug
// Memory:		No Memory leaks
//----------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <vector>
#include <immintrin.h>
#include <smmintrin.h>
#include <map>
#include <string>
union ThreeDPoint;
using namespace std;
using vect_3d = std::vector<ThreeDPoint>;
//7: calculate the lowest points and 1: store float value into the lowest 32 bits
constexpr int BITS = 0x71;

class Employee
{
private:
	string employeeName;
	string department;
	float baseSalary;
	float bonusRate;

protected:
	//Not every is eligible to get a raise.
	virtual void raiseBaseSalaryBy(const float) = 0;
	//The calculation of bonus is different based on the position of particular employee.
	virtual float getBonus() const = 0;

	void setSalary(const float);

	//These functions might get called very often, implicit inline.
	float getBase() const
	{
		return this->baseSalary;
	}

	float getRate() const
	{
		return this->bonusRate;
	}

	string getDept() const
	{
		return this->department;
	}

	string getName() const
	{
		return this->employeeName;
	}

public:
	//overloading ctor. compile time polymorphism 
	Employee(string name, string dept, float base, float rate)
		: employeeName{ move(name) }, department{ move(dept) }, baseSalary{ base }, bonusRate{ rate }{};

	virtual ~Employee() {};
	void getInfo(const float) const;
	friend void question1(Employee*);
};

class Manager : public Employee
{
public:
	Manager() = delete;
	~Manager() = default;
	//overloading ctor. compile time polymorphism 
	Manager(string name, string dept, float base, float rate)
		: Employee(move(name), move(dept), base, rate) {};

	virtual float getBonus() const override
	{
		const float rate = this->getRate();
		const float total = this->getBase() * this->getRate();
		this->getInfo(total);
		return total;
	};

	void raiseBaseSalaryBy(const float base) override
	{
		this->setSalary(base);
		this->getInfo(base);
	}
};

class Staff : public Employee
{

public:

	Staff() = delete;
	//overloading ctor. compile time polymorphism 
	Staff(string name, string dept, float base, float rate)
		: Employee(move(name), move(dept), base, rate) {};
	~Staff() = default;

	virtual float getBonus() const override
	{
		const float rate = this->getRate();
		const float total = (this->getBase() / 2) * rate;
		this->getInfo(total);
		return total;
	};

	void raiseBaseSalaryBy(const float base) override
	{
		printf("Staff %s NOT eligible for a raise.\n", this->getName().c_str());
	}
};

/*
 * Improvements:
 *  1. We need to compute the "length" of a vector in foo() anyway, so why not make all data member float. So, we can do the calculation using SIMD/floating point registers. Casting costs CPU cycles. Using the union to align the float data members.

 *  2. Adding pad for later SIMD calculations. Because SIMD/intrinsics need data to be aligned at least to 128 bits.

 *  3. Measured using CPU clock cycle, adding customized(or even just write out the word default for constructor, copy constructor, copy assignment operator and ect.) functions are faster than compiler generated stuff. The logic is that we have to work with compiler and make its job easier. Also, easier to debug later on.

 *  4. Use const whenever possible. Because, it indicates to compiler that this variable will not change. So compiler can move code around and maybe doing other kinds of optimizations(out of order execution, pipelining and etc). As long as it appear to us that a program executed in program order and the result is consistent.

 *  5. I also choose to use the class NRS_questions to manage
 *		data : vector<ThreeDPoint>, const char* PlayerNames[] and other data.
 *		function : foo(vector<ThreeDPoint>&),  bool IsValidPlayer( const char* player ) and other funcations.
 *
 */
union ThreeDPoint //default public
{
	//data[0 : 31] = float x; data[32 : 63] = float y; data[64 : 95] = float z; data[96 : 127] = float pad;
	__m128 data; //For floating registers

	//actual data
	struct //default public
	{
		float x; //int x;
		float y; // int y;
		float z; // int z;
		float pad; //four bytes pad for alignment
	};
	//public member function, default ctor
	ThreeDPoint() : x{ 0.0f }, y{ 0.0f }, z{ 0.0f }, pad{ 0.0f }
	{
		cout << "ThreeDPoint Default ctor" << endl;
	};

	ThreeDPoint(const float arg_x, const float arg_y, const float arg_z, const float arg_pad)
		: x{ arg_x }, y{ arg_y }, z{ arg_z }, pad{ arg_pad }
	{
		cout << "ThreeDPoint Specialized ctor" << endl;
	};

	ThreeDPoint(const ThreeDPoint & tmp)
		: x{ tmp.x }, y{ tmp.y }, z{ tmp.z }, pad{ tmp.pad }
	{
		cout << "ThreeDPoint Copy ctor" << endl;
	};

	ThreeDPoint(ThreeDPoint && tmp) noexcept
		: x{ move(tmp.x) }, y{ move(tmp.y) }, z{ move(tmp.z) }, pad{ move(tmp.pad) } //move() could be removed
	{
		cout << "ThreeDPoint Move ctor" << endl;
	};
	~ThreeDPoint() = default;
	ThreeDPoint& operator = (const ThreeDPoint&) = default;
	ThreeDPoint& operator = (ThreeDPoint&&) = default;
	
	//results from SIMD are stored in x.
	float getValue() const
	{
		return this->x;
	}
};

class NRS_questions
{
	private:
		vect_3d points;
		map<string, int> valideNames;
	
	public:
		//calls STL vector default ctor and in turn calls ThreeDPoint default ctor
		NRS_questions() : points(), valideNames() {};
		~NRS_questions() = default;
		NRS_questions(const NRS_questions&) = default;
		NRS_questions& operator = (const NRS_questions&) = default;
		NRS_questions(NRS_questions&&) = default;
		NRS_questions& operator = (NRS_questions&&) = default;

		void addPoint(const ThreeDPoint); //adding single ThreeDPoint object
		void fillPoints(vect_3d); //adding a vector of ThreeDPoint

		/*
		 * map give us O(lgN) running time when we validate a player's name. However, unorder_map could also be used to implement this function. Or we could also implement a hash map to speed up the search, which is O(1).
		 */
		bool IsValidPlayer(const char*);
		void addPlayer(const char*[], int);
		void printValidation(bool, const char*);
	
		/*
		 *	Description: foo() is sorting all ThreeDPoints objects according to their "length" which is the square root of dot product with itself.
		 *  Improvements:
		 *	1. The original sorting running time is O(N^2) under worst case. The fact of using the flag to terminate the while loop makes the original algo better than O(N^2). However, a lot of CPU cycle has been used in the vector length calculation.
		   I used STL::map to improve sorting. STL map is implemented using self-balancing red-black tree, it supports dictionary operations under O(logN). So, the improved running time is O(logN) + 2 * O(N) + O(1). Space: O(N) + O(N)
		 
		 *	2. Declare variable only when we actually use it. Especially, pointers in a raw loop. We do not want unexpected inc/dec. from other pieces of code.
		 
		 *	3. I used "auto" and "using" to make cleaner code.
		 
		 *	4. Implicit inline, by putting foo definition inside class NRS_question class. Because, this function might get called very often, since it is doing vector calculations.
		 
		 *	5. I used SIMD to speed up floating point calculation. Improvements could also be made on _mm_dp_ps. We could do the dot product by ourselves. That would require  _mm_mul_ps (__m128 a, __m128 b),  _mm_hadd_ps (__m128 a, __m128 b), and other intrinsics. For clear code, for now I only used existing _mm_dp_ps.
		 
		 *	6. I also move the foo()'s argument into the class NRS_question's data member for better data encapsulation.
		 
			7. For container access I use at(int index) instead of operator[], because at() throws out_of_range exception. Whenever possible avoid using raw loop.
			
			8. I tend to put everything on stack, use stack as much as possible. Because it manages memory efficiently.
		 */
		void foo()
		{
			//local variables on stack need to be initialized, otherwise compiler will make it garbage value
			//also we could use 'auto'
			//int i = 0; //only declare variable when we use it
			//int j = 0;
			ThreeDPoint current;
			//ThreeDPoint tmp2;
			//bool done = false;
			const auto vectSize = points.size();
			map<float, ThreeDPoint> map;
			vect_3d res;

			//O(N) + log(N)
			for (auto i = 0; i < vectSize; i++)
			{
				current.data = _mm_sqrt_ss(_mm_dp_ps(this->points.at(i).data, this->points.at(i).data, BITS));
				map.insert(pair<float, ThreeDPoint>(current.getValue(), this->points.at(i)));
			}

			//O(N)
			for (const auto& value : map)
			{
				res.push_back(value.second);
			}

			//only generate rvalue reference O(1)
			this->points = move(res);
		}

};

/*
 * Run-time Polymorphism helps us to call the right function at all times.
 * C++ implements Polymorphism using vtable and vptr. They are generated by using keyword virtual. There are two ways to use virtual, virtual function and pure virtual function.
 * For a class which contains at least one virtual function, a vtable is created for this class. When an derived object is created, its vptr points to the correct vtable for its overridden function. This vptr stays with the object and will not change. Even if we use a base class pointer to call a function in the derived class object, the vptr direct us to the correct function. 
 * 
 */
 //passed in as Employee*, but always call the right functions.
void question1(Employee* employee)
{
	employee->getBonus();
	employee->raiseBaseSalaryBy(1000.0f);
}

int main() {
//------------------------------Question 1--------------------------------------------------
	Manager* manager = new Manager("Jinshi", "Engineer", 90000.0f, 0.2f);
	Staff* staff = new Staff("Li", "Staff", 60000.0f, 0.2f);
	
	question1(manager);
	question1(staff);
	
	delete manager;
	delete staff;
//------------------------------Question 2--------------------------------------------------
	NRS_questions nrs;
	
	ThreeDPoint d(2.0f, 2.0f, 2.0f, 0.0);
	ThreeDPoint d0(1.0f, 1.0f, 1.0f, 0.0);
	ThreeDPoint d1(3.0f, 3.0f, 3.0f, 0.0);
	ThreeDPoint d2(0.5f, 0.5f, 0.5f, 0.0);
	nrs.fillPoints({ d, d0, d1, d2});
	nrs.foo();
//------------------------------Question 3--------------------------------------------------
	const char* PlayerNames[4] =
	{
				   "Jinshi",
				   "Scorpion",
				   "SubZero",
				   "LiuKang"
	};

	//if we pass in raw array, the size information is lost during the parameter passing.
	nrs.addPlayer(PlayerNames, sizeof(PlayerNames));
	cout << nrs.IsValidPlayer("Jinshi");
}