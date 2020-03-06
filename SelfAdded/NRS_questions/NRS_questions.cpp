#include "NRS_questions.h"

void NRS_questions::addPoint( const ThreeDPoint arg_point)
{
	this->points.push_back(arg_point);
	
}


void NRS_questions::fillPoints(const vect_3d arg_points)
{
	this->points.insert(this->points.end(), arg_points.begin(), arg_points.end());
}

bool NRS_questions::IsValidPlayer(const char* player)
{
	bool res = true;

	if (this->valideNames.find(player) == this->valideNames.end())
		res = false;

	this->printValidation(res, player);
	return res;
}

void NRS_questions::printValidation(bool val, const char* name)
{
	if(val)
	{
		printf("\nPlayer %s is a valid player name.\n", name);
	}else
	{
		printf("\nPlayer %s is NOT a valid player name.\n", name);
	}
}

void NRS_questions::addPlayer(const char* arg_players[], int size)
{
	int nameLength = size / sizeof(char*);
	for(auto i = 0; i < nameLength; ++i)
	{
		string tmpStr = arg_players[i];
		auto itr = this->valideNames.find(tmpStr);
		if(itr != this->valideNames.end())
		{
			itr->second += 1;
		}else
		{
			this->valideNames.insert({tmpStr, 1});
		}
	}
}

void Employee::setSalary(const float raise)
{
	this->baseSalary += raise;
}

void Employee::getInfo(const float money) const
{
	printf("\n");
	printf("Name: %s\n", this->getName().c_str());
	printf("\tDept.: %s\n", this->getDept().c_str());
	printf("\tRate: %s%%\n", std::to_string((this->getRate() * 100)).substr(0, 4).c_str());
	printf("\t+ $%s\n", std::to_string(money).substr(0, 7).c_str());
	printf("\n");
}