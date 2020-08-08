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
	
	int BFS(TreeNode*root, vector<int>&res,int k) {
		if (!root)return;
		queue<TreeNode*>rec;
		rec.push(root);
		while (!rec.empty()) {
				TreeNode *cur = rec.front();
				rec.pop();
				res.push_back(cur->val);
				if (cur->left) {
					rec.push(cur->left);
				}
				if (cur->right) {
					rec.push(cur->right);
				}
		}
		sort(res.begin(), res.end());
		if (k > 0 && k <= res.size()) return res[k-1];
		return INT_MIN;
	}

	TreeNode* res;
	void InOrder(TreeNode* root, int &n) {
		if (!root) return;
		InOrder(root->left, n);
		n--;
		if (n == 0) {
			res = root;
			return;
		}

		InOrder(root->right, n);
	}

	int kthSmallest(TreeNode* root, int k) {
		InOrder(root, k);
		return res->val;
	}
};