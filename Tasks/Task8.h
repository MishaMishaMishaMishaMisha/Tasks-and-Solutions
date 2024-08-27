#pragma once

class Task8
{
public:
	struct ListNode
	{
		ListNode* next;
		int val;

		ListNode() : val(0), next(nullptr) {}
		ListNode(int val_) : val(val_), next(nullptr) {}
		ListNode(int val_, ListNode* node) : val(val_), next(node) {}
	};

	ListNode* solution(ListNode* l1, ListNode* l2, int carry = 0);
};