#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t)
	{
		if (s.length() != t.length())return false;
		map<char, int>record;
		for (int i = 0; i < s.length(); i++)
		{
			if (record.count(s[i]))
				record[s[i]]++;
			else
				record[s[i]] = 1;
		}
		for (int i = 0; i < t.length(); i++)
		{
			if (record.count(t[i]) && record[t[i]] > 0 )
				record[t[i]]--;
			else
				return false;
		}
		return true;
	}
};
//int main()
//{
//	Solution test;
//	string s = "ab", t = "a";
//	cout << test.isAnagram(s, t) << endl;
//	return 0;
//}