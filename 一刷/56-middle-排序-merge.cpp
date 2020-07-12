#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) 
	{
		if (intervals.size() < 2)return intervals;
		sort(intervals);
		vector<vector<int>>res;
		vector<int>rec;
		stack <int>left;
		stack <int>right;
		left.push(intervals[0][0]);
		right.push(intervals[0][1]);
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (intervals[i][1] <= right.top())
				continue;
			if (intervals[i][0] <= right.top())
			{
				right.pop();
				right.push(intervals[i][1]);
			}
			if (intervals[i][0] > right.top())
			{
				rec.push_back(left.top());
				rec.push_back(right.top());
				res.push_back(rec);
				rec.clear();
				left.pop();
				left.push(intervals[i][0]);
				right.pop();
				right.push(intervals[i][1]);
			}

		}
		if (!left.empty())
		{
			rec.push_back(left.top());
			rec.push_back(right.top());
			res.push_back(rec);
			rec.clear();
			left.pop();
			right.pop();
		}
		return res;
	}

	//不适合用时间复杂度为n*n的排序算法，在leetcode上提交会超时
	//所以宜使用归并排序、快速排序等时间复杂度为n*logn或者更快的排序算法
	void sort(vector<vector<int>>&temp)
	{
		for (int i = 1; i < temp.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (temp[i][0] < temp[j][0])
				{
					vector<int>t = temp[i];
					for (int k = i; k > j; --k)
						temp[k] = temp[k - 1];
					temp[j] = t;
					break;
				}

			}
		}
	}
};