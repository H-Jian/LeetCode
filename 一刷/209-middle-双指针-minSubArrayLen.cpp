#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution {

public:
	int minSubArrayLen(int s, vector<int>& nums) 
	{
		if (nums.size() < 1)return 0;
		if (nums.size() == 1)
			if (nums[0] >= s)return 1;
			else return 0;
		int i = 0, j = 1;
		int minNUM = INT_MAX;
		int rec = nums[0];
		while (i < nums.size())
		{
			if (nums[i] >= s)return 1;
			rec += nums[j];
			if (rec >= s)
			{
				minNUM = min(minNUM, j - i + 1);
				rec -= nums[i];
				rec -= nums[j];
				i++;
			}
			else if (rec < s )
			{
				if (j < nums.size() - 1)
				{
					j++;
				}
				else
				{
					rec -= nums[i];
					rec -= nums[j];
					i++;
				}
			}
		}
		return minNUM == INT_MAX ? 0 : minNUM;
	}

};

//int main()
//{
//	vector<int> test = { 2,3,1,2,4,3 };
//	Solution s;
//	cout << s.minSubArrayLen(7, test) << endl;
//	return 0;
//}