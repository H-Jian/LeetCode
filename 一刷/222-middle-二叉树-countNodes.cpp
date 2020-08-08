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

// BFS 时间空间效率低
class Solution {
public:
	
	void BFS(TreeNode* root, int &res) {
		if (!root)return;
		queue<TreeNode*>rec;
		rec.push(root);
		int n = 1, m = 0;
		while (!rec.empty()) {
			res += n;
			while (n > 0) {
				TreeNode* cur = rec.front();
				rec.pop();
				--n;
				if (cur->left) {
					rec.push(cur->left);
					m++;
				}
				if (cur->right) {
					rec.push(cur->right);
					++m;
				}
			}
			n = m;
			m = 0;
		}
	}
	int countNodes(TreeNode* root) {
		int res = 0;
		BFS(root, res);
		return res;
	}
};

//递归调用 DFS

class Solution {
public:
	void DFS(TreeNode* root, int &sum) {
		if (root) {
			sum+=1;
			DFS(root->left, sum);
			DFS(root->right, sum);
		}
	}

	int countNodes(TreeNode* root) {
		int sum = 0;
		countNodes(root, sum);
		return sum;
	}
};



//二分查找

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int sum = 0;
		int lLevel = leftLevel(root->left);
		int rLevel = rightLevel(root->right);
		if (lLevel == rLevel) { // 满二叉树， 可以通过高度直接算出来节点个数， 并且完全二叉树的 leftNum <= rightNum
			sum = 2 * (pow(2, lLevel) - 1); // 满二叉树， 节点个数为 2 ^ h - 1， 所以左右两棵树节点个数为 2 * (2 ^ h - 1)
		}
		else { // 不是满二叉树， 在进行递归
			sum += countNodes(root->left) + countNodes(root->right);
		}
		return sum + 1;
	}
	// 最左子树分支的高度
	int leftLevel(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int sum = 0;
		return leftLevel(root->left) + 1;
	}

	// 最右子树分支的高度
	int rightLevel(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int sum = 0;
		return rightLevel(root->right) + 1;
	}
};
