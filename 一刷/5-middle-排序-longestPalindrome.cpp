#include<iostream>
#include<map>

using namespace std;

class Solution {

public:
	int expandAroundCenter(string s, int left, int right)
	{
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R])
		{
			L--;
			R++;
		}
		return R - L - 1;
	}

	string longestPalindrome(string s) {
		//map<int, int>rec;
		//for (int i = 1; i < s.length() - 1; ++i)
		//{
		//	for (int j = i - 1, k = i + 1; j >= 0 && k < s.length(); j--, k++)
		//	{
		//		if (s[j] != s[k])
		//			break;
		//		else if (s[j] == s[k] && rec.count[i])
		//			rec[i]++;
		//		else
		//			rec[i] = 1;
		//	}
		//}
		if (s.length()<1)
		{
			return "";
		}
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			int len1 = expandAroundCenter(s, i, i);
			int len2 = expandAroundCenter(s, i, i + 1);
			int len = len1 >= len2 ? len1 : len2;
			if (len > end - start)
			{
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}
};