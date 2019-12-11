#pragma once
using namespace std;
class Item7
{
	public:
		Item7();
		void firstTest();
		void secondTest();
		void thirdTest();
		void forthTest();
		void fifthTest();
	private :
		//normal ctors
		class Widget
		{
		public:
			Widget(int i, bool b)
				:
				integer(i),
				d(b)//implicite conversion
				//,integer(i)
				{};

			Widget(int i, double d)
				: 
				integer(i), 
				d(d)
				//integer(i)
			{};
			private:
				int integer;
				double d;
				//int integer;
		};

		//ctors with initilizer_list
		class Widget0
		{
		public:
			Widget0(int i, bool b)
				: integer(i), d(b) {};

			Widget0(int i, double d)
				: integer(i), d(d) {};

			Widget0(const Widget0& tmp)
				: integer(tmp.integer), d(tmp.d)
			{

			}

			Widget0(Widget0&& tmp)
				: integer(move(tmp.integer)), d(move(tmp.d))
			{

			}

			operator float() const
			{
				//Trace::out("CONVERTING?\n");
				return float(d) / float(integer);
			}

			Widget0(initializer_list<long double> li)
			{
				initializer_list<long double>::iterator itr = li.begin();
				this->integer = (int)*itr;
				itr++;
				this->d = (double)*itr;
				Trace::out("Inside Initilizer_list cotr\n");
			}
		private:
			int integer;
			double d;
		};

		//Widget with initilizer_list<bool> ctor
		class Widget1
		{
		public:
			Widget1(int i, bool b)
				: integer(i), d(b) {};

			Widget1(int i, double d)
				: integer(i), d(d) {};

			Widget1(const Widget1& tmp)
				: integer(tmp.integer), d(tmp.d)
			{

			}

			Widget1(Widget1&& tmp)
				: integer(move(tmp.integer)), d(move(tmp.d))
			{

			}

			operator float() const
			{
				//Trace::out("CONVERTING?\n");
				return float(d) / float(integer);
			}

			Widget1(initializer_list<bool> li)
			{
				initializer_list<bool>::iterator itr = li.begin();
				this->integer = (int)*itr;
				itr++;
				this->d = (double)*itr;
				Trace::out("Inside Initilizer_list cotr\n");
			}
		private:
			int integer;
			double d;
		};

		//Widget with initilizer_list<string> ctor
		class Widget2
		{
		public:
			Widget2(int i, bool b)
				: integer(i), d(b) {};

			Widget2(int i, double d)
				: integer(i), d(d) {};

			Widget2(const Widget2& tmp)
				: integer(tmp.integer), d(tmp.d)
			{

			}

			Widget2(Widget2&& tmp)
				: integer(move(tmp.integer)), d(move(tmp.d))
			{

			}

			operator float() const
			{
				//Trace::out("CONVERTING?\n");
				return float(d) / float(integer);
			}

			Widget2(initializer_list<std::string> li)
			{
				initializer_list<std::string>::iterator itr = li.begin();
				/*this->integer = (int)*itr;
				itr++;
				this->d = (double)*itr;*/
				Trace::out("Inside Initilizer_list cotr\n");
			}
		private:
			int integer;
			double d;
		};

		//default construction with empty braces?
		class Widget3
		{
		public:
			//empty ctor
			Widget3() 
			{
			};

			Widget3(initializer_list<int> li)
			{

			}
		};


};

