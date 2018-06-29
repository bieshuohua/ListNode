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
				head = head->next;//ָ��Ҫ�����ǰһ��node
			}
			o1 = head;
			p1 = head->next;
		}
		else {
			p1 = head;//��m=1ʱ������Ҫ�õ�o1��ֻ��Ҫp1ָ��ͷ��㣬Ȼ����ת����
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
		ReverseLinkedList2* o2 = rear_head;//n�պ�Ϊ������ʱ��rear_head�պ�Ϊ��ָ�룬Line 59:p1->next = o2��ָ��û������

		if (m != 1) {
			o1->next = p2;
		}
		else if (m == 1) {
			reserved = new_head;//��m=1ʱ��ͷ����ָ�뱻��ת�����ˡ�
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