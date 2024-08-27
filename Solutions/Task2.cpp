#include "../Tasks/Task2.h"
#include <unordered_set>

bool Task2::solution(std::string s1, std::string s2)
{
	std::unordered_multiset<char> sub = { s1.begin(), s1.end() };
	std::unordered_multiset<char> findsub = { s2.begin(), s2.begin() + s1.length() - 1 };

	for (int i = s1.length() - 1; i < s2.length(); i++)
	{
		findsub.insert(s2[i]); // add next symbol

		if (findsub == sub) return true;

		// remove first symbol
		auto it = findsub.find(s2[i - (s1.length() - 1)]);
		findsub.erase(it);
	}

	return false;
}