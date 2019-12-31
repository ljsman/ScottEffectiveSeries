#pragma once
class Item4
{
public:
	class Singleton
	{
	public:
		//implicit inlined function
		static Singleton& getInstance()
		{
			static Singleton singleton;
			return singleton;
		}
		//public member functions
		static int* getData()
		{
			return Singleton::getInstance().privGetData();
		}
		
	private:
		int data;

		int* privGetData()
		{
			return &(this->data); 
		}
		explicit constexpr  Singleton() noexcept
			: data{}
		{
			
		}

		explicit constexpr  Singleton(const int t) noexcept
			: data{t}
		{

		}
		
		~Singleton() = default;
		Singleton(const Singleton&) = delete;
		Singleton& operator = (const Singleton&) = delete;
		Singleton(Singleton&&) = delete;
		Singleton& operator = (Singleton&&) = delete;
		
	};
};

