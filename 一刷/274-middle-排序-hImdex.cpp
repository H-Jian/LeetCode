#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.size() == 0)return 0;
		if (citations.size() == 1)
		{
			if (citations[0] == 0)
				return 0;
			return 1;
		}
		sort(citations.begin(), citations.end());
		int temp = 0;
		for (int i = 0; i < citations.size(); ++i)
		{
			if (citations.size() - i <= citations[i])
				//return citations[i];
				temp = max(temp, (int)citations.size() - i);
		}
		return temp;

	}
};