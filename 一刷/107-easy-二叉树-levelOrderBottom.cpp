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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (!root)return {};
		if (!root->left && !root->right)return { {root->val} };
		vector<vector<int>>rec = levelOrder(root);
		vector<vector<int>>res;
		for (int i = rec.size() - 1; i >= 0; --i)
			res.push_back(rec[i]);
		//vector<TreeNode*>rec;
		//rec.push_back(root);
		//vector<int>temp;
		//vector<vector<int>>res;
		//vector<int>nums;
		//int n = 1, m = 0;
		//nums.push_back(n);
		//int i = 0;
		//root = rec[i];
		//while (1) {
		//	while (n > 0) {
		//		if (root->left) {
		//			rec.push_back(root->left);
		//			m++;
		//		}
		//		if (root->right) {
		//			rec.push_back(root->right);
		//			m++;
		//		}
		//	}
		//	if (m == 0)break;
		//	n = m;
		//	m = 0;
		//	i++; 
		//	root = rec[i];
		//	nums.push_back(n);
		//}
		//while (!nums.empty()) {
		//	int n = nums[nums.size() - 1];
		//	for (int i = rec.size() - n + 1; i < rec.size(); ++i) {
		//		temp.push_back(rec[i]->val);
		//	}
		//	while (n > 0)rec.pop_back();
		//	res.push_back(temp);
		//	temp.clear();
		//	nums.pop_back();
		//}
		return res;
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*>rec;
		rec.push(root);
		int n = 1, m = 0;
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