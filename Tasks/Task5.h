#pragma once

#include <vector>

class Task5
{
public:
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int val_) : val(val_), left(nullptr), right(nullptr) {}
		TreeNode(int val_, TreeNode* l, TreeNode* r) : val(val_), left(l), right(r) {}
	};

	TreeNode* solution(std::vector<int> v);

	TreeNode* help_func(std::vector<int> v, int left, int right);

};