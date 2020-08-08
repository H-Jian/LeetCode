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
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root) return {};
		if (!root->left && !root->right)return { {root->val} };
		queue<TreeNode*>rec;
		rec.push(root);
		int n = 1,m = 0;
		vector<vector<int>>res;
		vector<int>temp;
		while (!rec.empty()) {
			while (n > 0) {
				TreeNode* node = rec.front();
				rec.pop();
				temp.push_back(node->val);
				if (node->left) { 
					rec.push(node->left);
					m++; 
				}
				if (node->right) {
					rec.push(node->right);
					m++;
				}
				n--;
			}
			n = m;
			m = 0;
			res.push_back(temp);
			temp.clear();
		}
		return res;
	}
};