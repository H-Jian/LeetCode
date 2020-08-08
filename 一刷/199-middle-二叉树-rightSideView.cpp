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
	vector<int>res;
	void BFS(TreeNode*root) {
		if (!root)return ;
		res.push_back(root->val);
		if (!root->left && !root->right) return;
		queue<TreeNode*>rec;
		rec.push(root);
		int n = 1, m = 0;
		while (!rec.empty()) {
			while (n > 0) {
				TreeNode *cur = rec.front();
				rec.pop();
				n--;
				if (n == 0) res.push_back(cur->val);
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
	vector<int> rightSideView(TreeNode* root) {
		BFS(root);
		return res;
	}
};