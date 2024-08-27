#include "../Tasks/Task3.h"

int Task3::solution(int number, int index)
{
	int size = sizeof(number) * 8;
	if (index < 0 || index > size) return number;

	int temp = 1 << (size - index);
	number ^= temp;

	return number;
}