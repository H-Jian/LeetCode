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
	//1.龟兔赛跑在环形赛道
	bool hasCycle(ListNode *head) {
		if (!head || !head->next) return false;
		ListNode *fast = head->next;
		ListNode *slow = head;
		while (slow && fast) {
			if (slow == fast) return true;
			slow = slow->next;
			if(fast->next)
				fast = fast->next->next;
		}
		return false;
	}
};