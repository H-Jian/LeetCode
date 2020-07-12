#include<iostream>
#include<ios>
#include<tuple>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<queue>

using namespace std;



//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	// ��תһ�����������ҷ����µ�ͷ��β
	pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
		ListNode* prev = tail->next;
		ListNode* p = head;
		while (prev != tail) {
			ListNode* nex = p->next;
			p->next = prev;
			prev = p;
			p = nex;
		}
		return { tail, head };
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* hair = new ListNode(0);
		hair->next = head;
		ListNode* pre = hair;

		while (head) {
			ListNode* tail = pre;
			// �鿴ʣ�ಿ�ֳ����Ƿ���ڵ��� k
			for (int i = 0; i < k; ++i) {
				tail = tail->next;
				if (!tail) {
					return hair->next;
				}
			}
			ListNode* nex = tail->next;
			// ������ C++17 ��д����Ҳ����д��
			// pair<ListNode*, ListNode*> result = myReverse(head, tail);
			// head = result.first;
			// tail = result.second;
			tie(head, tail) = myReverse(head, tail);
			// �����������½ӻ�ԭ����
			pre->next = head;
			tail->next = nex;
			pre = tail;
			head = tail->next;
		}

		return hair->next;
	}
};



class Solution {
public:
	// ��תһ�����������ҷ����µ�ͷ��β
	pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
		ListNode* cur = head;
		ListNode* pre = tail->next;
		while (pre != tail) {
			ListNode* temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		return { head,tail };
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* prev = dummyHead;

		while (head) {
			ListNode* tail = prev;
			for (int i = 0; i < k; ++i) {
				tail = tail->next;
				if (!tail) return dummyHead->next;
			}
			ListNode* temp = tail->next;
			tie(tail, head) = myReverse(head, tail);
			prev->next = head;
			tail->next = temp;
			prev = tail;
			head = tail->next;
		}
		return dummyHead->next;
	}
};
