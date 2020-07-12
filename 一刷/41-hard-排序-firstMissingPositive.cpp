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
�ĵ���᣺
1.�������Ҫ����ȫ�棬��vector��vector��size��1�ȡ�
2.������������֮��Ķ��ֹ�ϵ��Ҫ�������
3.if��else if֮�������Ҫ�������  if-if�ǲ��еĹ�ϵ�����ζ��жϽ���ʹ�ã�if-else if�����Ⱥ������if����Ϊ������Ҫִ��else if ����
*/