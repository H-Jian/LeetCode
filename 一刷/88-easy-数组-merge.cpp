#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<queue>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0)return;
		if (m == 0) {
			nums1.clear();
			for (int i = 0; i <n; ++i)
				nums1.push_back(nums2[i]);
			return;
		}
		queue<int>recM;
		queue<int>recN;
		for (int i = 0; i < max(m,n); ++i) {
			if (i < m) recM.push(nums1[i]);
			if (i < n) recN.push(nums2[i]);
		}
		nums1.clear();
		int temp1 = 0, temp2 = 0;
		while (!recM.empty() && !recN.empty()) {
			temp1 = recM.front();
			temp2 = recN.front();
			if (temp1 < temp2) {
				nums1.push_back(temp1);
				recM.pop();
			}
			else {
				nums1.push_back(temp2);
				recN.pop();
			}
		}
		while (!recM.empty()) {
			nums1.push_back(recM.front());
			recM.pop();
		}
		while (!recN.empty()) {
			nums1.push_back(recN.front());
			recN.pop();
		}
	}
};

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = m - 1, j = n - 1;
	for (int k = nums1.size()-1; k >= 0; --k) {
		if (j > -1) {
			if (i >= 0 && nums1[i] > nums2[j]) {
				nums1[k] = nums1[i];
				i--;
			}
			else {
				nums1[k] = nums2[j];
				j--;
			}
		}
		else return;
	}
}
