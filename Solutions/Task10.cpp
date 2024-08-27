#include "../Tasks/Task10.h"

void Task10::solution(std::vector<std::vector<char>>& box)
{
	int lines = box.size();
	int width = box[0].size();

	// firstly, we move objects (#) to the walls (*) or to the edge
	for (int i = 0; i < lines; i++)
	{
		int index_start = 0;
		for (int j = 0; j < width; j++)
		{
			if (box[i][j] == '*')
			{
				moveObjectsToNearestWall(box[i], index_start, j);
				index_start = j + 1;
			}
			else if (j + 1 == width) moveObjectsToNearestWall(box[i], index_start, j + 1);
		}
	}

	// rotate box
	std::vector<std::vector<char>> newbox(width, std::vector<char>(lines));

	for (int i = 0; i < lines; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			newbox[j][i] = box[i][j];
		}
	}
	for (int i = 0; i < width; ++i)
	{
		std::reverse(newbox[i].begin(), newbox[i].end());
	}

	box = newbox;
}

void Task10::moveObjectsToNearestWall(std::vector<char>& box, int start_index, int wall_index)
{
	if (wall_index - start_index <= 1) return;

	for (int i = 0, j = 0; i < wall_index; i++)
	{
		if (box[i] != '#')
		{
			std::swap(box[j], box[i]);
			j++;
		}
	}

}