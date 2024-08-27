#pragma once

#include <vector>

class Task10
{
public:
	void solution(std::vector<std::vector<char>>& box);

	void moveObjectsToNearestWall(std::vector<char>& box, int start_index, int wall_index);
};