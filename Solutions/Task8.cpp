#include "../Tasks/Task8.h"

Task8::ListNode* Task8::solution(ListNode* l1, ListNode* l2, int carry)
{
	if (!l1 && !l2 && !carry)
	{
		return nullptr;
	}

	int temp = 0;
	ListNode* result = nullptr;
	if (!l1 && l2)
	{
		temp = l2->val;
		l2 = l2->next;
	}
	else if (!l2 && l1)
	{
		temp = l1->val;
		l1 = l1->next;
	}
	else if (l1 && l2)
	{
		temp = l1->val + l2->val;
		l1 = l1->next;
		l2 = l2->next;
	}

	if (carry)
	{
		temp += 1;
	}

	carry = temp / 10;
	temp %= 10;

	result = new ListNode(temp);
	result->next = solution(l1, l2, carry);

	return result;
}