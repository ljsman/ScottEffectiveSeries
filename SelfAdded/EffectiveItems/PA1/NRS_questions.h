//----------------------------------------------------------------------------
// Copyright 2019, Woo, Steve, NRS_TechInternship, all rights reserved.
// Edited by:	Jinshi Li
// Date:		03/03/2020 - 03/05/2020
// IDE:			Visual Studio Enterprise 2019(v142)
// Compiler:	Windows SDK 10.0.18362.0
//----------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <vector>
#include <immintrin.h>
#include <smmintrin.h>
#include <map>
union ThreeDPoint;
using namespace std;
using vect_3d = std::vector<ThreeDPoint>;
//7: calculate the lowest points and 1: store float value into the lowest 32 bits
constexpr int BITS = 0x71;

/*
 * Improvements:
 *  1. We need to compute the "length" of a vector in code @foo anyway, so why not make all data member float. So, we can do the calculation using SIMD/floating point registers. Casting costs CPU cycles. Using the union to align the float data members.

 *  2. Adding pad for later SIMD calculations. Because SIMD/intrinsics need data to be aligned at least to 128 bits.

 *  3. Measured using CPU clock cycle, adding customized(or even just write out the code @default constructor, copy constructor, copy assignment operator and ect.) is faster than compiler generated stuff. The logic is that we have to work with compiler and make its job easier if necessary. Also, easier to debug later on.

 *  4. Use code @const whenever possible. Because, it indicates to compiler that this variable will not change. So compiler can move code around and maybe doing other kinds of optimizations(out of order execution, pipelining and etc). As long as it appear to us that a program executed in program order and the result is consistent.

 *  5. I also choose to use the class NRS_questions to manage
 *		data : vector<ThreeDPoint> and const char* PlayerNames[]
 *		function : foo(vector<ThreeDPoint>&) and  bool IsValidPlayer( const char* player )
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
	ThreeDPoint() : x{ 2.0f }, y{ 2.0f }, z{ 2.0f }, pad{ 0.0f }
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
		//vect_3d = std::vector<ThreeDPoint>;
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
		 *	Description: foo() is sorting ThreeDPoints in a vector according to their "length" which is the square root of dot product with itself.
		 *  Improvements:
		 *	1. If we could make the argument type lvalue reference, then we don't have to copy all the value in the vector; which could potentially very large.
		 
		 *	2. Declare variable only when we actually use it. Especially, pointers in a raw loop. We do not want unexpected inc/dec. from other pieces of code.
		 
		 *	3. I used "auto" and "using" to make cleaner code.
		 
		 *	4. Implicit inline, by putting foo definition inside class NRS_question class. Because, this function might get called very often, since it is doing vector calculations.
		 
		 *	5. Improvements could also be made with _mm_dp_ps. We could do the dot product by ourselves. That would require  _mm_mul_ps (__m128 a, __m128 b),  _mm_hadd_ps (__m128 a, __m128 b), and other intrinsics. For clear code, for now I only used default one.
		 *	6. I also move the foo() argument into the NRS_question's data member to encapsulate the vector of points.
		 */
		void foo()
		{
			//local variables on stack need to be initialized, otherwise compiler(MSVC) will make it garbage value
			//also we could use 'auto'
			//int i = 0; //only declare variable when we ac it
			//int j = 0;
			ThreeDPoint tmp1;
			ThreeDPoint tmp2;
			bool done = false;
			const auto vectSize = points.size();
			

			while (!done)
			{
				done = true;
				
				for (auto i = 0; i < vectSize; i++)
				{
					const auto j = i + 1;

					if (j >= vectSize) break;
					
					tmp1.data = _mm_sqrt_ss(_mm_dp_ps(this->points.at(i).data, this->points.at(i).data, BITS));
					tmp2.data = _mm_sqrt_ss(_mm_dp_ps(this->points.at(j).data, this->points.at(j).data, BITS));

					if (tmp2.getValue() < tmp1.getValue())
					{
						std::swap(points[i], points[j]);
						done = false;
					}
					//tmp1.data = _mm_mul_ps (points.at(i).data, points.at(i).data);
					//_mm_mul_ps(points.at(i).data, points.at(i).data);
					/*Trace::out("The result is in the lower bits -> %f", tmp1.getValue());
					Trace::out("\n");*/
				}
			}
		}

};

int main() {
	NRS_questions nrs;
	ThreeDPoint d;
	ThreeDPoint d0(1.0f, 1.0f, 1.0f, 0.0);
	ThreeDPoint d1(3.0f, 3.0f, 3.0f, 0.0);
	nrs.fillPoints({ d, d0, d1 });

	const char* PlayerNames[4] =
	{
				   "Jinshi",
				   "Scorpion",
				   "SubZero",
				   "LiuKang"
	};
	cout << sizeof(PlayerNames) << endl;

	//if we pass in raw array, the size information is lost during the parameter passing.
	nrs.addPlayer(PlayerNames, sizeof(PlayerNames));
	cout << nrs.IsValidPlayer("Jinshi");

	nrs.foo();
}