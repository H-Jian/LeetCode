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

// BFS ʱ��ռ�Ч�ʵ�
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

//�ݹ���� DFS

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



//���ֲ���

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int sum = 0;
		int lLevel = leftLevel(root->left);
		int rLevel = rightLevel(root->right);
		if (lLevel == rLevel) { // ���������� ����ͨ���߶�ֱ��������ڵ������ ������ȫ�������� leftNum <= rightNum
			sum = 2 * (pow(2, lLevel) - 1); // ���������� �ڵ����Ϊ 2 ^ h - 1�� ���������������ڵ����Ϊ 2 * (2 ^ h - 1)
		}
		else { // �������������� �ڽ��еݹ�
			sum += countNodes(root->left) + countNodes(root->right);
		}
		return sum + 1;
	}
	// ����������֧�ĸ߶�
	int leftLevel(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int sum = 0;
		return leftLevel(root->left) + 1;
	}

	// ����������֧�ĸ߶�
	int rightLevel(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int sum = 0;
		return rightLevel(root->right) + 1;
	}
};
