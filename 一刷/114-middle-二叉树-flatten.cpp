#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<limits.h>
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
	queue<TreeNode*>rec;
	void helper(TreeNode* root) {
		if (!root)return;
		rec.push(root);
		if (!root->left && !root->right) return;
		helper(root->left);
		helper(root->right);
	}
	void flatten(TreeNode* root) {
		helper(root);
		if (!rec.empty()) {
			root = rec.front();
			rec.pop();
		}
		TreeNode* cur = root;
		while (!rec.empty()) {
			cur->right = rec.front();
			cur->left = NULL;
			rec.pop();
			cur = cur->right;
		}
	}
};