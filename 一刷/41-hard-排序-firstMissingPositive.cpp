#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums)
	{
		if (nums.size() == 0)return 1;
		if (nums.size() == 1)
		{
			if (nums[0] != 1)
				return 1;
			else
				return 2;
		}
		sort(nums.begin(), nums.end());
		if (nums[0] > 1 || nums[nums.size()-1] < 0)return 1;
		int fast = 1, slow = 0;
		while (fast < nums.size())
		{
			if (nums[fast] - nums[slow] <= 1)
			{
				fast++;
				slow++;
			}
			else
			{
				if (nums[fast] <= 0)
				{
					fast++;
					slow++;
				}
				else if (nums[fast] > 0 && nums[slow] >= 0)
						return nums[slow] + 1;
				else if (nums[fast] >= 0 && nums[slow] < 0)
				{
					if (nums[fast] != 1)
						return 1;
					else
					{
						fast++;
						slow++;
					}

				}
			}
		}
		return nums[nums.size() - 1] + 1;
	}
};



/*
心得体会：
1.特殊情况要考虑全面，空vector，vector的size是1等。
2.正数负数和零之间的多种关系需要考虑清楚
3.if和else if之间的区别要考虑清楚  if-if是并列的关系，两次都判断谨慎使用；if-else if存在先后次序，若if条件为真则不需要执行else if 内容
*/