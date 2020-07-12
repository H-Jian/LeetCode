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

	//1.先找环 题141
	//2.再确定入口，pt1是链表头，pt2是slow和fast相遇节点的下一节点，每一次pt1和pt2向前走一步，相遇即是入口
	ListNode *detectCycle(ListNode *head) {
		if (!head || !head->next) return false;
		ListNode *slow = head;
		ListNode *fast = slow->next;
		while (slow && fast) {
			if (slow == fast) {
				ListNode *pt1 = head;
				ListNode *pt2 = slow->next;
				while (pt1 != pt2) {
					pt1 = pt1->next;
					pt2 = pt2->next;
				}
				return pt1;
			}
			slow = slow->next;
			if (fast->next) fast = fast->next->next;
			else fast = NULL;
		}
		return false;

	}
};