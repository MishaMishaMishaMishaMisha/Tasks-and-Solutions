#pragma once

class Task11
{
public:
	struct LinkedList
	{
		LinkedList* next;
		LinkedList* prev;
		int val;

		LinkedList() : val(0), next(nullptr), prev(nullptr) {}
		LinkedList(int val_) : val(val_), next(nullptr), prev(nullptr) {}
		LinkedList(int val_, LinkedList* prev_) : val(val_), next(nullptr), prev(prev_) {}
		LinkedList(int val_, LinkedList* next_, LinkedList* prev_) : val(val_), next(next_), prev(prev_) {}
	};

	double solution(LinkedList* head, LinkedList* tail);
};