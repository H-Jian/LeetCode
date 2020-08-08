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
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL) return NULL;

		TreeNode* left = invertTree(root->left);
		TreeNode* right = invertTree(root->right);
		root->left = right;
		root->right = left;
		return root;
	}
};




class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL) return NULL;
		queue<TreeNode*>rec;
		rec.push(root);
		while (!rec.empty()) {
			TreeNode* cur = rec.front();
			rec.pop();
			TreeNode* temp = cur->left;
			cur->left = cur->right;
			cur->right = temp;
			if (cur->left) rec.push(cur->left);
			if (cur->right) rec.push(cur->right);
		}
		return root;
 	}
};