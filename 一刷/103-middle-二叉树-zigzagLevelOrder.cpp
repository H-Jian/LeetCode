#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<limits.h>
#include<queue>
#include<deque>
#include<stack>
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

//Ë«¶Ë¶ÓÁÐ
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (!root) return {};
		if (!root->left && !root->right)return { {root->val} };
		int n = 1,m = 0;
		bool flag = true;
		deque<TreeNode*>rec;
		rec.push_back(root);
		vector<vector<int>>res;
		vector<int>temp;
		while (!rec.empty()) {
			if (flag) {
				flag = false;
				while (n > 0) {
					TreeNode* node = rec.front();
					rec.pop_front();
					temp.push_back(node->val);
					if (node->left) {
						rec.push_back(node->left);
						m++;
					}
					if (node->right) {
						rec.push_back(node->right);
						m++;
					}
					n--;
				}
				res.push_back(temp);
				temp.clear();
				n = m;
				m = 0;
			} else {
				flag = true;
				while (n > 0) {
					TreeNode* node = rec.back();
					rec.pop_back();
					temp.push_back(node->val);
					if (node->right) {
						rec.push_front(node->right);
						m++;
					}
					if (node->left) {
						rec.push_front(node->left);
						m++;
					}
					n--;
				}
				res.push_back(temp);
				temp.clear();
				n = m;
				m = 0;
			}
		}
		return res;
	}
};