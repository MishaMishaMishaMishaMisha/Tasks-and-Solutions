#include <iostream>

#include "../Tasks/Task1.h"
#include "../Tasks/Task2.h"
#include "../Tasks/Task3.h"
#include "../Tasks/Task4.h"
#include "../Tasks/Task5.h"
#include "../Tasks/Task6.h"
#include "../Tasks/Task7.h"
#include "../Tasks/Task8.h"
#include "../Tasks/Task9.h"
#include "../Tasks/Task10.h"
#include "../Tasks/Task11.h"


class Tests
{
public:
	void solution1(std::vector<int> v = { 0, 1, 2, 0, 3, 0 })
	{
		std::cout << "\n=====================Task1=====================\n" << std::endl;

		std::cout << "input vector: ";
		for (auto& el : v)
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;

		Task1{}.solution(v);

		std::cout << "result vector: ";
		for (auto& el : v)
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;
	}

	void solution2(std::string s1 = "qwe", std::string s2 = "hahawqehaha")
	{
		std::cout << "\n=====================Task2=====================\n" << std::endl;

		std::cout << "input string: " << s2 << std::endl;
		std::cout << "input substring: " << s1 << std::endl;
		std::cout << "answer: " << Task2{}.solution(s1, s2) << std::endl;
	}

	void solution3(int number = 18, int index = 28)
	{
		std::cout << "\n=====================Task3=====================\n" << std::endl;

		Task3 task3;

		std::cout << "index of bit must be changed: " << index << std::endl;
		std::cout << "number before: ";
		showBinary(number);

		number = task3.solution(number, index);

		std::cout << "number after: ";
		showBinary(number);
	}

	void solution4(int a = 15, int b = 7)
	{
		std::cout << "\n=====================Task4=====================\n" << std::endl;

		int sum = Task4{}.solution(a, b);
		std::cout << a << " + " << b << " = " << sum << std::endl;
	}

	void solution5(std::vector<int> vector = { 1, 2, 10, 12, 43, 100 })
	{
		std::cout << "\n=====================Task5=====================\n" << std::endl;

		std::cout << "input vector: ";
		for (auto& el : vector)
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;

		Task5 task5;
		Task5::TreeNode* root = task5.solution(vector);
		std::cout << "output tree: ";
		printTree(root);
		std::cout << std::endl;
	}

	void solution6(std::vector<int> cards = { 7, 12, 3, 6, 10 }, int k = 3)
	{
		std::cout << "\n=====================Task6=====================\n" << std::endl;

		std::cout << "input cards: ";
		for (auto& el : cards)
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;
		std::cout << "number of moves (k): " << k << std::endl;

		int result = Task6{}.solution(cards, k);
		std::cout << "max points: " << result << std::endl;
	}

	void solution7(std::string str = "hahaqweghagha")
	{
		std::cout << "\n=====================Task7=====================\n" << std::endl;

		std::cout << "input string: " << str << std::endl;
		int result = Task7{}.solution(str);
		std::cout << "length: " << result << std::endl;
	}

	void solution8(Task8::ListNode* list1 = nullptr, Task8::ListNode* list2 = nullptr)
	{
		std::cout << "\n=====================Task8=====================\n" << std::endl;

		if (!list1)
		{
			Task8::ListNode* node1 = new Task8::ListNode(4);
			Task8::ListNode* node2 = new Task8::ListNode(1);
			Task8::ListNode* node3 = new Task8::ListNode(8);
			list1 = node1;
			list1->next = node2;
			node2->next = node3;
		}
		if (!list2)
		{
			Task8::ListNode* node1 = new Task8::ListNode(3);
			Task8::ListNode* node2 = new Task8::ListNode(9);
			Task8::ListNode* node3 = new Task8::ListNode(9);
			list2 = node1;
			list2->next = node2;
			node2->next = node3;
		}

		Task8 task8;
		std::cout << "first list: ";
		printList(list1);
		std::cout << "second list: ";
		printList(list2);

		Task8::ListNode* result = task8.solution(list1, list2);
		std::cout << "result list: ";
		printList(result);
	}

	void solution9(std::vector<int> v1 = { 1, 6, 8, 13 }, std::vector<int> v2 = { 5, 7, 10 })
	{
		std::cout << "\n=====================Task9=====================\n" << std::endl;

		std::cout << "first vector: ";
		for (auto& el : v1)
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;
		std::cout << "second vector: ";
		for (auto& el : v2)
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;

		double result = Task9{}.solution(v1, v2);
		std::cout << "mediana: " << result << std::endl;
	}

	void solution10(std::vector<std::vector<char>> box = { {'#', '.', '#', '.'}, {'#', '.', '*', '.'}, {'*', '#', '*', '.'} })
	{
		std::cout << "\n=====================Task10====================\n" << std::endl;

		Task10 task10;
		std::cout << "input box: \n";
		showBox(box);
		task10.solution(box);
		std::cout << "rotated box: \n";
		showBox(box);
	}

	void solution11(Task11::LinkedList* head = nullptr, Task11::LinkedList* tail = nullptr)
	{
		std::cout << "\n=====================Task11====================\n" << std::endl;

		if (!head)
		{
			Task11::LinkedList* node1 = new Task11::LinkedList(7);
			Task11::LinkedList* node2 = new Task11::LinkedList(10, node1);
			Task11::LinkedList* node3 = new Task11::LinkedList(3, node2);
			Task11::LinkedList* node4 = new Task11::LinkedList(5, node3);
			Task11::LinkedList* node5 = new Task11::LinkedList(20, node4);
			node1->next = node2;
			node2->next = node3;
			node3->next = node4;
			node4->next = node5;
			head = node1;
			tail = node5;
		}

		std::cout << "input head (" << head->val << ") and tail (" << tail->val << ") of list: ";
		Task11 task11;
		printList(head);

		int result = task11.solution(head, tail);
		std::cout << "mediana: " << result << std::endl;
	}

private:
	// print number in binary form
	void showBinary(int number)
	{
		int size = sizeof(number) * 8;

		std::cout << number << " ->\t";
		while (size--)
		{
			if (number & (1 << size))
			{
				std::cout << "1";
			}
			else
			{
				std::cout << "0";
			}
		}
		std::cout << std::endl;
	}

	// print binary tree
	void printTree(Task5::TreeNode* node)
	{
		if (!node) return;

		std::cout << node->val << " ";
		printTree(node->left);
		printTree(node->right);
	}

	// print single linked list
	void printList(Task8::ListNode* list)
	{
		while (list != nullptr)
		{
			std::cout << list->val << " ";
			list = list->next;
		}
		std::cout << std::endl;
	}

	// print box
	void showBox(std::vector<std::vector<char>>& box)
	{
		for (int i = 0; i < box.size(); i++)
		{
			for (int j = 0; j < box[0].size(); j++)
			{
				std::cout << box[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	// print doubly linked list
	void printList(Task11::LinkedList* current)
	{
		while (current != nullptr)
		{
			std::cout << current->val << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}
};


int main()
{

	Tests tests;
	tests.solution1();
	tests.solution2();
	tests.solution3();
	tests.solution4();
	tests.solution5();
	tests.solution6();
	tests.solution7();
	tests.solution8();
	tests.solution9();
	tests.solution10();
	tests.solution11();



	return 0;
}
