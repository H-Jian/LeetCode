#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) 
	{
		if (nums.size() < 1)return INT_MIN;
		if (nums.size() == 1)return nums[0];
		//sort(nums.begin(), nums.end()); 
		//partial_sort(nums.begin(), nums.begin()+k, nums.end(),func);
		sort_heap(nums.begin(), nums.end());
		//return *(nums.begin()+k-1);
		return nums[nums.size()-k];
	}
	bool func(int i, int j) { return (i > j); }
};