#pragma once
template <class Data>
class MyTemplate
{
	private:
		Data data;
	public:
		void printData()
		{
			Trace::out("THe data is %d", this->data);
		};
		MyTemplate() : data()
		{
			
		}
};

