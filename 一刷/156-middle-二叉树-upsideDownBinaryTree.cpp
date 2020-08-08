#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
	TreeNode * head;
	TreeNode* DFS(TreeNode* root) {
		if (!root) return NULL;
		if (!root->left && !root->right) {
			if(!head) head = root;
			return root;
		}
		TreeNode *left = DFS(root->left);
		TreeNode *right = DFS(root->right);
		if (left) {
			left->left = right;
			left->right = root;
		}
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	TreeNode* upsideDownBinaryTree(TreeNode* root) {
		DFS(root);
		return head;
	}
};



class Solution {
public:
	TreeNode* upsideDownBinaryTree(TreeNode* root) {
		if (root == NULL || root->left == NULL) return root;
		auto l = root->left;
		auto r = root->right;
		root->left = NULL;
		root->right = NULL;
		auto res = upsideDownBinaryTree(l);
		l->left = r;
		l->right = root;
		return res;
	}
};
