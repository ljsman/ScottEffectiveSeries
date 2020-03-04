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
	
	return res;
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
