#include "stdafx.h"
#include <iostream>

using namespace std;

//Definition for singly - linked list.
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};

class ReverseLinkedList2 {
public:
	int val;
	ReverseLinkedList2 *next;
	ReverseLinkedList2(int x) : val(x), next(NULL) {}

	static ReverseLinkedList2 * reverseList(ReverseLinkedList2* head, int m, int n) {
		ReverseLinkedList2* new_head = NULL;
		ReverseLinkedList2* next_pointer = NULL;
		if (head == nullptr) {
			return head;
		}
		next_pointer = head->next;
		head->next = NULL;
		new_head = head;
		head = next_pointer;
		while (head) {
			next_pointer = head->next;
			head->next = new_head;

			new_head = head;
			head = next_pointer;
		}
		return new_head;
	}
};

int main() {
	ReverseLinkedList2 a(NULL);
	//ReverseLinkedList2 b(20);
	//ReverseLinkedList2 c(30);
	//ReverseLinkedList2 d(40);
	//ReverseLinkedList2 e(50);
	//a.next = &b;
	//b.next = &c;
	//c.next = &d;
	//d.next = &e;
	//e.next = NULL;
	a.next = NULL;
	ReverseLinkedList2 *head = &a;
	head = ReverseLinkedList2::reverseList(&a);
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
	system("pause");
	return 0;
}