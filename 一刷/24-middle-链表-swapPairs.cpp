#include<iostream>
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
	//1. 虚拟头节点+三指针
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)return head;
		ListNode *dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode *pre = dummyHead;
		ListNode *cur = dummyHead->next;
		ListNode *next = cur->next;
		while (next != NULL && cur != NULL) {
			pre->next = next;
			cur->next = next->next;
			next->next = cur;
			pre = cur;
			cur = pre->next;
			if (cur)next = cur->next;
			else next = NULL;
		}
		return dummyHead->next;
	}
};

//2.迭代
ListNode* swapPairs(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode *pre = head;
	ListNode *cur = head->next;
	
	pre->next = swapPairs(cur->next);
	cur->next = pre;
	return cur;
}