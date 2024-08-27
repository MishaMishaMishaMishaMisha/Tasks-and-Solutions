#include "../Tasks/Task7.h"
#include <unordered_map>

int Task7::solution(std::string str)
{
	std::unordered_map<char, int> map;
	int left = 0;
	int max = 0;

	for (int right = 0; right < str.length(); right++)
	{
		char current = str[right];
		auto iter = map.find(current);
		if (iter != map.end() && iter->second >= left)
		{
			left = iter->second + 1;
		}

		map[current] = right;
		max = std::max(max, right - left + 1);
	}

	return max;
}