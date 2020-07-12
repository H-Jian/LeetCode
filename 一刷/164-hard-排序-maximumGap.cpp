#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	int maximumGap(vector<int>& nums)
	{
		if (nums.size() < 2)return 0;
		if (nums.size() == 2)return abs(nums[0] - nums[1]);
		sort(nums.begin(), nums.end());
		int temp = 0;
		for (int i = 1; i < nums.size(); ++i)
		{
			temp = temp > nums[i] - nums[i - 1] ? temp : nums[i] - nums[i - 1];
		}
		return temp;
	}
};