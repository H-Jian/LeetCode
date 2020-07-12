#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) 
	{
		return isMirro(root, root);
	}
	bool isMirro(TreeNode* p, TreeNode* q)
	{
		if (p == NULL && q == NULL)return true;
		if (p == NULL || q == NULL)return false;
		if (p->val == q->val)
			return isMirro(p->left, q->right) && isMirro(p->right, q->left);
		return false;
	}
};