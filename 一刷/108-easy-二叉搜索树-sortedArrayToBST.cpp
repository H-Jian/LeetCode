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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, nums.size()-1);
	}
	TreeNode* helper(vector<int>& nums,int begin,int end) {
		if (begin > end) return NULL;
		int mid = (begin + end) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = helper(nums, begin, mid - 1);
		root->right = helper(nums, mid + 1, end);
		return root;
	}
};