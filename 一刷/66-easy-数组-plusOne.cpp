#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<queue>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		//vector<int> res;
		digits[digits.size() - 1] += 1;
		if (digits[digits.size() - 1] < 9) return digits;
		else {
			for (int i = digits.size() - 1; i >= 0; --i)
			{
				if (i == 0 && digits[0] > 9) {
					vector<int> res(digits.size()+1);
					res[0] = 1;
					res[1] = digits[0] - 10;
					for (int j = 1; j < digits.size(); ++j)
						res[j + 1] = digits[j];
					return res;
				}
				if (digits[i] > 9) {
					digits[i] -= 10;
					digits[i - 1] += 1;
				}
				else
					return digits;
			}
		}
		return digits;
	}
};