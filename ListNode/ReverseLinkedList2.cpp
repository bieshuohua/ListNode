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
		ReverseLinkedList2* reserved = head;
		ReverseLinkedList2* o1 = NULL;
		ReverseLinkedList2* p1 = NULL;
		if (m != 1) {
			for (int i = 0; i < m - 2; i++) {
				head = head->next;//指向要逆序的前一个node
			}
			o1 = head;
			p1 = head->next;
		}
		else {
			p1 = head;//当m=1时，不需要用到o1。只需要p1指向头结点，然后逆转即可
		}
		
		ReverseLinkedList2* rear_head = p1;

		int count = 0;
		ReverseLinkedList2* new_head = NULL;
		ReverseLinkedList2* next_pointer = NULL;
		if (rear_head == nullptr) {
			return rear_head;
		}
		while (rear_head && count <= n - m) {
			next_pointer = rear_head->next;
			rear_head->next = new_head;
			new_head = rear_head;
			rear_head = next_pointer;

			count++;
		}
		ReverseLinkedList2* p2 = new_head;
		ReverseLinkedList2* o2 = rear_head;//n刚好为链表长度时，rear_head刚好为空指针，Line 59:p1->next = o2的指向没有问题

		if (m != 1) {
			o1->next = p2;
		}
		else if (m == 1) {
			reserved = new_head;//当m=1时，头部的指针被逆转过来了。
		}
		p1->next = o2;

		return reserved;
	}
};

int main() {
	ReverseLinkedList2 a(1);
	ReverseLinkedList2 b(2);
	ReverseLinkedList2 c(3);
	ReverseLinkedList2 d(4);
	ReverseLinkedList2 e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = NULL;
	//a.next = NULL;
	ReverseLinkedList2 *head = &a;
	head = ReverseLinkedList2::reverseList(&a, 1, 4);
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
	system("pause");
	return 0;
}