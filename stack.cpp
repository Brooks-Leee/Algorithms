#include <iostream>
#include <stack>
#include <string>	
#include <algorithm>	

class ListNode {
public:
	int data;
	ListNode* next;
};

class Solution {
public:
	ListNode* insert(int x, ListNode* head)
	{
		ListNode* node = new ListNode;
		node->data = x;
		node->next = NULL;
		if (!head)
		{
			head = node;
			return head;
		}
		node->next = head;
		head = node;
		return head;
	}

	void print(ListNode* head)
	{
		while (head)
		{
			std::cout << head->data << " ";
			head = head->next;
		}
		std::cout << std::endl;
	}

	ListNode* reverseIterative(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		ListNode* prev, * curr, * next;
		prev = NULL;
		curr = head;
		next = NULL;
		while (curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}

	ListNode* reverseRecursive(ListNode* head)
	{
		if (head->next == NULL || head == NULL)
		{
			return head;
		}
		ListNode* p = reverseRecursive(head->next);
		head->next->next = head;
		head->next = NULL;
		return p;
	}

	ListNode* reverseStackable(ListNode* head)
	{
		std::stack<ListNode*> stack;
		while (head)
		{
			stack.push(head);
			head = head->next;
		}
		head = stack.top();
		ListNode* temp = head;
		stack.pop();
		while (!stack.empty())
		{
			temp->next = stack.top();
			stack.pop();
			temp = temp->next;
		}
		temp->next = NULL;
		return head;
	}
};


int main() {
	Solution s;
	ListNode* head = NULL;
	head = s.insert(1, head);
	head = s.insert(2, head);
	head = s.insert(3, head);
	head = s.insert(4, head);
	s.print(head);
	head = s.reverseIterative(head);
	s.print(head);
	head = s.reverseRecursive(head);
	s.print(head);
	head = s.reverseStackable(head);
	s.print(head);

}