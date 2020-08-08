#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<limits.h>
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
	bool isValidBST(TreeNode* root) {
		if (root == NULL) return true;
		if (!root->left && !root->right) return true;
		vector<int>rec;
		InOrder(root, rec);
		bool res = true;
		for (int i = 0; i < rec.size() - 1; ++i) {
			res = rec[i] < rec[i + 1];
			if (!res) break;
		}
		return res;
	}
	void InOrder(TreeNode* root, vector<int>&rec) {
		if (!root)return;
		InOrder(root->left, rec);
		rec.push_back(root->val);
		InOrder(root->right, rec);
	}
};

bool isBSTUtil(TreeNode* root, long long &prev) {
	if (root) {
		if (!isBSTUtil(root->left, prev)) return false;
		if (root->val <= prev) return false;
		prev = root->val;
		return isBSTUtil(root->right, prev);
	}
	return true;
}
bool isValidBST(TreeNode* root) {
	long long prev = -9223372036854775808;
	return isBSTUtil(root, prev);
}

