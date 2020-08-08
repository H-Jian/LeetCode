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
	int numTrees(int n) {
		vector<int> rec(n + 1, 0);
		rec[0] = 1;
		rec[1] = 1;
		for(int i = 2;i <=n;++i)
			for (int j = 1; j <= i; ++j) {
				rec[i] += rec[j - 1] * rec[i - j];
			}
		return rec[n];
	}


	int numTrees(int n) {
		long long res = 1;
		for (int i = 0; i < n; ++i) {
			res = res * (4 * i + 2) / (i + 2);
		}
		return (int)res;
	}
};