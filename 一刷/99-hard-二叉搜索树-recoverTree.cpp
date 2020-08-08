#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<limits.h>
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
	void recoverTree(TreeNode* root) {

	}
};

class Solution {
public:
	// s1 ��С�����Ǹ���㣬s2��������Ǹ���㣬pre��ǰ�����
	TreeNode *s1 = NULL, *s2 = NULL, *pre = NULL;
	void recoverTree(TreeNode* root) {
		TreeNode* cur = root;  // �α�
		while (cur != NULL) {
			if (cur->left != NULL) {  // ����������
				// �ҵ�cur��ǰ����㣬���������
				// 1��cur�����ӽ��û�����ӽ�㣬��cur�����ӽ�����ǰ��
				// 2��cur�����ӽ�������ӽ�㣬��һ·�����£��ߵ��׾���cur��ǰ��
				TreeNode* predecessor = cur->left;
				while (predecessor->right != NULL && predecessor->right != cur) {
					predecessor = predecessor->right;
				}

				// ǰ����û��ָ���Լ���˵����߻�û�б�������ǰ������ָ��ָ���Լ��������ǰ��
				if (predecessor->right == NULL) {
					predecessor->right = cur;
					cur = cur->left;
				}
				else {
					// ǰ���Ѿ�ָ���Լ��ˣ�ֱ�ӱȽ��Ƿ�������ԣ�Ȼ�����������
					if (pre != NULL && cur->val < pre->val) {
						if (s1 == NULL) s1 = pre;
						s2 = cur;
					}
					pre = cur;
					predecessor->right = NULL;
					cur = cur->right;
				}
			}
			else {  // ������Ϊ��ʱ������Ƿ�������ԣ�Ȼ�����������
				if (pre != NULL && cur->val < pre->val) {
					if (s1 == NULL) s1 = pre;
					s2 = cur;
				}
				pre = cur;
				cur = cur->right;
			}
		}
		// ���н���
		int t = s1->val;
		s1->val = s2->val;
		s2->val = t;
		return;
	}
};

