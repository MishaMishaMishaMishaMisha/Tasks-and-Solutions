#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>



/*
	Tasks:
			1. Move zeros to the end of vector
			2. Determine whether s1 is a substring or a permutation within s2
			3. Change bit of number by index
			4. Sum of numbers using bitwise operations
			5. Convert sorted vector to binary tree
			6. You are given a deck of cards with points and a number k, representing the number of moves.
			   In each move, you can take a card from either the top or the bottom of the deck.
			   Your goal is to maximize the total points by selecting k cards.
			7. Find length of the longest substring of unique symbols
			8. Given two linked lists, where each element represents a digit.
			   The digits in the lists form numbers that are stored in reverse order.
			   Create a new linked list representing the digits of the sum of these numbers.
			9. Given two sorted vectors v1 and v2.
			   Find the median of a vector v that would contain all elements from both v1 and v2.
			10. Given box, where '#' - object, '.' - empty, '*' - wall.
				Rotate this box, so that all the objects fall down.
			11. Given head and tail of linked list, find median.
*/

class Task1
{
public:
	void solution(std::vector<int>& vector)
	{
		for (int i = 0, j = 0; i < vector.size(); i++)
		{
			if (vector[i] != 0)
			{
				std::swap(vector[j++], vector[i]);
			}
		}
	}
};

class Task2
{
public:
	bool solution(std::string s1, std::string s2)
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

};

class Task3
{
public:
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

	int solution(int number, int index)
	{
		int size = sizeof(number) * 8;
		if (index < 0 || index > size) return number;

		int temp = 1 << (size - index);
		number ^= temp;

		return number;
	}
};

class Task4
{
public:
	int solution(int a, int b)
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
};

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

	void printTree(TreeNode* node)
	{
		if (!node) return;

		std::cout << node->val << " ";
		printTree(node->left);
		printTree(node->right);
	}


	TreeNode* help_func(std::vector<int> v, int left, int right)
	{
		if (left > right) return nullptr;

		int middle = (left + right) / 2;
		TreeNode* current_item = new TreeNode(v[middle]);
		current_item->left = help_func(v, left, middle - 1);
		current_item->right = help_func(v, middle + 1, right);

		return current_item;
	}

	TreeNode* solution(std::vector<int> v)
	{
		if (v.empty()) return nullptr;

		return help_func(v, 0, v.size() - 1);
	}

};

class Task6
{
public:
	int solution(std::vector<int> cards, int k)
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
};

class Task7
{
public:
	int solution(std::string str)
	{
		std::unordered_map<char, int> map;
		int left = 0;
		int max = 0;

		for (int right = 0; right < str.length(); right++)
		{
			char current = str[right];
			auto iter = map.find(current);
			if (iter != map.end() && iter->second >= left)
			{
				left = iter->second + 1;
			}

			map[current] = right;
			max = std::max(max, right - left + 1);
		}

		return max;
	}
};

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

	void printList(ListNode* list)
	{
		while (list != nullptr)
		{
			std::cout << list->val << " ";
			list = list->next;
		}
		std::cout << std::endl;
	}

	ListNode* solution(ListNode* l1, ListNode* l2, int carry = 0)
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
};

class Task9
{
public:
	double solution(std::vector<int> v1, std::vector<int> v2)
	{
		int len = v1.size() + v2.size();
		int medium_index = len / 2;

		int i = 0, j = 0;
		int previous = 0, current = 0;
		for (int k = 0; k <= medium_index; k++)
		{
			previous = current;

			if (i < v1.size() && (j >= v2.size() || v1[i] < v2[j]))
			{
				current = v1[i];
				++i;
			}
			else
			{
				current = v2[j];
				++j;
			}
		}

		if (len % 2 == 0) return (double)(previous + current) / 2;
		return current;
	}

};

class Task10
{
public:
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

	void moveObjectsToNearestWall(std::vector<char>& box, int start_index, int wall_index)
	{
		if (wall_index - start_index <= 1) return;

		for (int i = 0, j = 0; i < wall_index; i++)
		{
			if (box[i] != '#')
			{
				std::swap(box[j], box[i]);
				j++;
			}
		}

	}

	void solution(std::vector<std::vector<char>>& box)
	{
		int lines = box.size();
		int width = box[0].size();

		// firstly, we move objects (#) to the walls (*) or to the edge
		for (int i = 0; i < lines; i++)
		{
			int index_start = 0;
			for (int j = 0; j < width; j++)
			{
				if (box[i][j] == '*')
				{
					moveObjectsToNearestWall(box[i], index_start, j);
					index_start = j + 1;
				}
				else if (j + 1 == width) moveObjectsToNearestWall(box[i], index_start, j + 1);
			}
		}

		// rotate box
		std::vector<std::vector<char>> newbox(width, std::vector<char>(lines));

		for (int i = 0; i < lines; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				newbox[j][i] = box[i][j];
			}
		}
		for (int i = 0; i < width; ++i)
		{
			std::reverse(newbox[i].begin(), newbox[i].end());
		}

		box = newbox;
	}

};

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

	void printList(LinkedList* current)
	{
		while (current != nullptr)
		{
			std::cout << current->val << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	double solution(LinkedList* head, LinkedList* tail)
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
};



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
		task3.showBinary(number);

		number = task3.solution(number, index);

		std::cout << "number after: ";
		task3.showBinary(number);
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
		task5.printTree(root);
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
		task8.printList(list1);
		std::cout << "second list: ";
		task8.printList(list2);

		Task8::ListNode* result = task8.solution(list1, list2);
		std::cout << "result list: ";
		task8.printList(result);
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
		task10.showBox(box);
		task10.solution(box);
		std::cout << "rotated box: \n";
		task10.showBox(box);
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
		task11.printList(head);

		int result = task11.solution(head, tail);
		std::cout << "mediana: " << result << std::endl;
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
