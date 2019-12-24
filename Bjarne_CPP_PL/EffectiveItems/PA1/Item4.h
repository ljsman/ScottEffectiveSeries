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
		~Singleton() = default;
		Singleton(const Singleton&) = delete;
		Singleton& operator = (const Singleton&) = delete;
		Singleton(Singleton&&) = delete;
		Singleton& operator = (Singleton&&) = delete;
		
	private:
		Singleton() = default;
		
		
	};
};

