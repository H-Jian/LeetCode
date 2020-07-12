#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>&nums)
	{
		if (nums.size() < 2)return;
		int m = 0;//从前往后
		int n = nums.size() - 1;//从后往前
		int p = m;
		while (p <= n)
		{
			if (nums[p] == 0)
			{
				int temp = nums[p];
				nums[p] = nums[m];
				nums[m] = temp;
				m++;
				p++;
			}
			else if (nums[p] == 1)
			{
				p++;
			}
			else if (nums[p] == 2)
			{
				int temp = nums[p];
				nums[p] = nums[n];
				nums[n] = temp;
				n--;
			}
		}
	}
};


