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
	//冗长的代码，错误的代码
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1)return l2;
		if (!l2)return l1;
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = l2;
		ListNode* l1_cur = l1;
		ListNode* l2_cur = l2;
		while (l1_cur && l2_cur) {
			if (l1_cur->val <= l2_cur->val) {
				ListNode* t1 = l1_cur->next;
				ListNode* t2 = l2_cur->next;
				while (t1 && t1->val <= l2_cur->val) {
					l1_cur = t1;
					t1 = t1->next;
				}
				if (t1) {
					l1_cur->next = l2_cur;
					l1_cur = t1;
				}
				else {
					return dummyHead->next;
				}
			}
			else {
				ListNode* t1 = l1_cur->next;
				ListNode* t2 = l2_cur->next;
				while (t2 && t2->val < l1_cur->val) {
					l2_cur = t2;
					t2 = t2->next;
				}
				if (t2) {
					l2_cur->next = l1_cur;
					l1_cur->next = t2;
					l1_cur = t1;
					l2_cur = t2;
				}
				else {
					l2_cur->next = l1_cur;
					return dummyHead->next;
				}
			}
		}
		ListNode* newl = new ListNode(min(l1->val, l2->val));
		//dummyHead->next = newl;
		newl->next = dummyHead->next;
		return newl;

	}
};

//迭代
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* dummyHead = new ListNode(0);
	ListNode* cur = dummyHead;
	while (l1 && l2) {
		if (l1->val <= l2->val) {
			cur->next = l1;
			l1 = l1->next;
		}
		else {
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	cur->next = l1 != NULL ? l1 : l2;
	return dummyHead->next;

}



//递归
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1 && l2)
		{
			return l2;
		}
		else if (l1 && !l2)
		{
			return l1;
		}
		else if (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				l1->next = mergeTwoLists(l1->next, l2);
				return l1;
			}
			else
			{
				l2->next = mergeTwoLists(l1, l2->next);
				return l2;
			}
		}
		return NULL;
	}
};