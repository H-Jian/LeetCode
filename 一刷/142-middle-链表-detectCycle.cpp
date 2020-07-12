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

	//1.���һ� ��141
	//2.��ȷ����ڣ�pt1������ͷ��pt2��slow��fast�����ڵ����һ�ڵ㣬ÿһ��pt1��pt2��ǰ��һ���������������
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