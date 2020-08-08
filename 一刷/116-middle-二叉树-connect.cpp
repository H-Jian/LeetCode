#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<limits.h>
#include<queue>

using namespace std;


// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
	void helper(Node* root,queue<Node*>rec) {
		if (!root)return ;
		if (!root->left && !root->right) return;
		rec.push(root);
		//rec.push(NULL);
		int n = 1, m = 0;
		while (!rec.empty()) {
			while (n > 0) {
				Node* cur = rec.front();
				rec.pop();
				if (n == 1) cur->next = NULL;
				else cur->next = rec.front();
				n--;
				if (cur->left) {
					rec.push(cur->left); 
					m++;
				}
				if (cur->right) {
					rec.push(cur->right);
					m++;
				}
			}
			n = m;
			m = 0;
		}
	}
	Node* connect(Node* root) {
		queue<Node*>rec;
		helper(root,rec);
		return root;
	}
};

void helper2(Node* root) {
	if (!root)return;
	if (!root->left && !root->right) return;
	root->left->next = root->right;
	if (!root->next) {
		root->right->next = root->next->left;
	}
	helper2(root->left);
	helper2(root->right);
}

Node*  connect(Node* root) {
	helper2(root);
	return root;
}
