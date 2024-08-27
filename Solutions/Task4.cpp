#include "../Tasks/Task4.h"

int Task4::solution(int a, int b)
{
	int result = a ^ b; // adding all bits
	int shifts = a & b; // shifts
	do
	{
		int temp = result;
		shifts = shifts << 1; // next shift
		result ^= shifts;
		shifts &= temp;
	} while (shifts); // while shifts left

	return result;
}