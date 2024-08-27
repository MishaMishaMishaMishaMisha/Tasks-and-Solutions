#include "../Tasks/Task6.h"

int Task6::solution(std::vector<int> cards, int k)
{
	if (k <= 0) return 0;
	if (k == 1) return std::max(cards[0], cards[cards.size() - 1]);

	int temp = 0;
	for (int i = 0; i < k; i++) temp += cards[i];
	int max = 0;
	for (int i = 1; i <= k; i++)
	{
		temp += cards[cards.size() - i];
		temp -= cards[k - i];

		max = std::max(max, temp);
	}
	return std::max(max, temp);
}