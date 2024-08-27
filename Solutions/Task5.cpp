#include "../Tasks/Task5.h"

Task5::TreeNode* Task5::help_func(std::vector<int> v, int left, int right)
{
	if (left > right) return nullptr;

	int middle = (left + right) / 2;
	TreeNode* current_item = new TreeNode(v[middle]);
	current_item->left = help_func(v, left, middle - 1);
	current_item->right = help_func(v, middle + 1, right);

	return current_item;
}

Task5::TreeNode* Task5::solution(std::vector<int> v)
{
	if (v.empty()) return nullptr;

	return help_func(v, 0, v.size() - 1);
}