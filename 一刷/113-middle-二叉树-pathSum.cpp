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
	vector<vector<int>>res;
	void DFS(TreeNode*root, vector<int>&t, int sum) {
		if (!root)return ;
		t.push_back(root->val);
		if (root->val == sum && !root->left && !root->right)
			res.push_back(t);
		DFS(root->left, t, sum - root->val);
		DFS(root->right, t, sum - root->val);
		t.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int>rec;
		DFS(root, rec, sum);
		return res;
	}
};