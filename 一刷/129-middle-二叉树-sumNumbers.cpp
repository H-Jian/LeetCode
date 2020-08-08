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


//要考虑大数问题吗？

class Solution {
public:
	int helper(TreeNode* root, int value) {
		if (!root) return 0;
		int temp = value  * 10 + root->val;
		if (!root->left && !root->right) return temp;
		return helper(root->left, temp) + helper(root->right, temp);
		//DFS

	}
	int sumNumbers(TreeNode* root) {
		return helper(root, 0);
	}
};



class Solution {
public:
	int sumNumbers(TreeNode* root) {
		int res = 0;
		queue<TreeNode*> rec;
		if (root == NULL) return res;
		rec.push(root);
		while (!rec.empty())
		{
			TreeNode* cur = rec.front();
			rec.pop();
			if (!cur->left && !cur->right) res += cur->val;
			if (cur->left)
			{
				cur->left->val = cur->val * 10 + cur->left->val;
				rec.push(cur->left);
			}
			if (cur->right)
			{
				cur->right->val = cur->val * 10 + cur->right->val;
				rec.push(cur->right);
			}
		}
		return res;
	}
};
