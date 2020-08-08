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
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		return abs(helper(root->left) - helper(root->right)) < 2 &&
			isBalanced(root->left) && isBalanced(root->right);
	}
	int helper(TreeNode* root) {
		if (!root)return -1;
		return 1 + max(helper(root->left), helper(root->right));
	}
};


class Solution {
private:
	bool isBalancedTreeHelper(TreeNode* root, int& height) {
		if (root == NULL) {
			height = -1;
			return true;
		}
		int left, right;
		if (isBalancedTreeHelper(root->left, left) &&
			isBalancedTreeHelper(root->right, right) &&
			abs(left - right) < 2) {
			height = max(left, right) + 1;
			return true;
		}
		return false;
	}
public:
	bool isBalanced(TreeNode* root) {
		int height;
		return isBalancedTreeHelper(root, height);
	}
};
