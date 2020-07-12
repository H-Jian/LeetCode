#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<unordered_set>
using namespace std;

class Solution{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		unordered_set<int>record(nums1.begin(),nums1.end());
		//for (int i = 0; i < nums1.size(); ++i)
		//{
		//	if (record.count(nums1[i]))
		//		record[nums1[i]]++;
		//	else
		//		record[nums1[i]] = 0;
		//}
		//set<int>temp;
		vector<int>res;
		for (int i = 0; i < nums2.size(); ++i)
		{
			//if (record.count(nums2[i]))
			//	temp.insert(nums2[i]);
			if (record.erase(nums2[i]))
				res.push_back(nums2[i]);
		}
		//for (auto k : temp)
		//	res.push_back(k);

		return res;
	}
};