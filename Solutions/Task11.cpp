#include "../Tasks/Task11.h"

double Task11::solution(LinkedList* head, LinkedList* tail)
{
	while (head != tail)
	{
		if (head->next == tail)
		{
			return (head->val + tail->val) / 2;
		}
		head = head->next;
		tail = tail->prev;
	}
	return head->val;
}