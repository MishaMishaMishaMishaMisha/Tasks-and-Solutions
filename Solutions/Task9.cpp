#include "../Tasks/Task9.h"

double Task9::solution(std::vector<int> v1, std::vector<int> v2)
{
	int len = v1.size() + v2.size();
	int medium_index = len / 2;

	int i = 0, j = 0;
	int previous = 0, current = 0;
	for (int k = 0; k <= medium_index; k++)
	{
		previous = current;

		if (i < v1.size() && (j >= v2.size() || v1[i] < v2[j]))
		{
			current = v1[i];
			++i;
		}
		else
		{
			current = v2[j];
			++j;
		}
	}

	if (len % 2 == 0) return (double)(previous + current) / 2;
	return current;
}