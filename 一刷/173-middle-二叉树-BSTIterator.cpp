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


class BSTIterator {
public:
	vector<int> rec;
public:
	bool comp(int a, int b)
	{
		return(a > b);
	}

	BSTIterator(TreeNode* root) {
		preOrder(root);
		sort(rec.begin(), rec.end(), comp);

		//sort(rec.begin(), rec.end(), comp);
		//sort(A, A + 100, greater<int>());//Ωµ–Ú≈≈¡–
		//sort(A, A + 100, less<int>());//…˝–Ú≈≈¡–
	}

	void preOrder(TreeNode* root) {
		if (!root) return;
		if (!root->left && !root->right) {
			rec.push_back(root->val);
			return;
		}
		rec.push_back(root->val);
		preOrder(root->left);
		preOrder(root->right);
	}

	/** @return the next smallest number */
	int next() {
		int value = rec[rec.size() - 1];
		rec.pop_back();
		return value;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return rec.size();
	}
};
