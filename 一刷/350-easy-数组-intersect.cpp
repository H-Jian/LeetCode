#include<stack>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int>res;
		if (nums1.empty() || nums2.empty()) return res;
		unordered_map<int, int>rec;
		for (int i = 0; i < nums1.size(); ++i) {
			if (rec.find(nums1[i]) == rec.end()) {
				rec[nums1[i]] = 1;
			}
			else
				rec[nums1[i]] ++;
		}
		for (int i = 0; i < nums2.size(); ++i) {
			if (rec.find(nums2[i]) != rec.end() && rec[nums2[i]] > 0) {
				res.push_back(nums2[i]);
				rec[nums2[i]]--;
			}
		}
		return res;
	}
};