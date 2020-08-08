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

//BFS方法同116题


//递归超时
class Solution {
public:
	void helper2(Node* root) {
		if (!root)return;
		if (!root->left && !root->right) return;

		if (root->left && root->right) root->left->next = root->right;

		Node* temp = root->next;

		while (temp && !temp->left && !temp->right)
			temp = temp->next;
		if (temp) {
			if (temp->left) {
				if (root->right) root->right->next = temp->left;
				else root->left->next = temp->left;
			}
			else if (temp->right) {
				if (root->right) root->right->next = temp->right;
				else root->left->next = temp->right;
			}
		}
		helper2(root->next);
		helper2(root->left);
		helper2(root->right);
	}
	Node*  connect(Node* root) {
		helper2(root);
		return root;
	}

};