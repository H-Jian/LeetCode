#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
	{
		intervals.push_back(newInterval);
		if (intervals.size() == 1)return intervals;
		for (int i = 0; i < intervals.size(); ++i)
		{
			if (newInterval[0] <= intervals[i][0])
			{
				for (int j = intervals.size() - 1; j > i; --j)
				{
					intervals[j] = intervals[j - 1];
				}
				intervals[i] = newInterval;
				break;
			}
		}
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


};




