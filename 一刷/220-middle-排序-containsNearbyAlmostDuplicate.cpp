#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
	{
		if (nums.size() < 2)return false;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i + 1; j <= i + k && j < nums.size(); ++j)
			{
				if (abs(nums[j] - nums[i]) <= t)
					return true;
			}
		}
		return false;
	}
};