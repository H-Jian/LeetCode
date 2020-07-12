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
	ListNode* reverseList(ListNode* head) {
		ListNode *pre = NULL;
		ListNode *cur = head;
		while (cur != NULL) {
			ListNode * temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		return pre;
	}
};


ListNode *reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode * rhead = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return rhead;
}