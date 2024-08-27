#include "../Tasks/Task1.h"

void Task1::solution(std::vector<int>& vector)
{
	for (int i = 0, j = 0; i < vector.size(); i++)
	{
		if (vector[i] != 0)
		{
			std::swap(vector[j++], vector[i]);
		}
	}
}