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
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)return false;
		if (!root->left && !root->right) return root->val == sum;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};


class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)return false;
		queue<TreeNode*>que_node;
		queue<int> que_val;
		que_node.push(root);
		que_val.push(root->val);
		while (!que_node.empty()) {
			TreeNode* now = que_node.front();
			int temp = que_val.front();
			que_node.pop();
			que_val.pop();
			if (now->left == NULL && now->right == NULL) {
				if (temp == sum) return true;
				continue;
			}
			if (now->left) {
				que_node.push(now->left);
				que_val.push(now->left->val + temp);
			}
			if (now->right) {
				que_node.push(now->right);
				que_val.push(now->right->val + temp);
			}
		}
		return false;
	}
};