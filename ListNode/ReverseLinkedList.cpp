#include "stdafx.h"
#include <iostream>

using namespace std;

//Definition for singly - linked list.
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};

class ReverseLinkedList {
public:
	int val;
	ReverseLinkedList *next;
	ReverseLinkedList(int x) : val(x), next(NULL) {}

	static ReverseLinkedList * reverseList(ReverseLinkedList* head) {
		ReverseLinkedList* new_head = NULL;
		ReverseLinkedList* next_pointer = NULL;
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

//int main() {
//	ReverseLinkedList a(NULL);
//	//ReverseLinkedList b(20);
//	//ReverseLinkedList c(30);
//	//ReverseLinkedList d(40);
//	//ReverseLinkedList e(50);
//	//a.next = &b;
//	//b.next = &c;
//	//c.next = &d;
//	//d.next = &e;
//	//e.next = NULL;
//	a.next = NULL;
//	ReverseLinkedList *head = &a;
//	head = ReverseLinkedList::reverseList(&a);
//	while (head) {
//		cout << head->val << endl;
//		head = head->next;
//	}
//	system("pause");
//	return 0;
//}