#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<queue>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (k <= 0) return;
		k = k % nums.size();
		queue<int>rec;
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (i >= nums.size() - k) {
				rec.push(nums[i]);
			}
			if (i - k >= 0) {
				nums[i] = nums[i - k];
			}
			else {
				nums[i] = rec.front();
				rec.pop();
			}
		}
	}
};