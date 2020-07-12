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
	unordered_map<string, int>rec{
{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}
	};
	unordered_map<string, int>rec2{
{"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000}
	};

	int romanToInt(string s) {
		if (s.length() == 0) return 0;
		if (s.length() == 1) return rec2[s];
		int i = 0, j = 1;
		int res = 0;
		string temp;
		while (i < s.length() && j < s.length()) {
			temp.push_back(s[i]);
			temp.push_back(s[j]);
			if (rec.find(temp) != rec.end()) {
				res += rec[temp];
				i += 2; 
				j += 2;
				temp.clear();
			}
			else {
				temp.pop_back();
				res += rec2[temp];
				i++;
				j++;
				temp.clear();
			}
		}
		if (i >= s.length() && j >= s.length()) return res;
		else if (i < s.length() && j >= s.length()) {
			//string temp;
			temp.push_back(s[i]);
			res += rec2[temp];
			i++;
			temp.clear();
			return res;
		}
		return res;
	}
};


class Solution {
public:
	int romanToInt(string s) {
		int m[90] = {};
		m['I'] = 1;
		m['V'] = 5;
		m['X'] = 10;
		m['L'] = 50;
		m['C'] = 100;
		m['D'] = 500;
		m['M'] = 1000;
		int sum = 0;
		for (int i = 0; i < s.size(); ++i)
			m[s[i]] < m[s[i + 1]] ? sum -= m[s[i]] : sum += m[s[i]];
		return sum;
	}
};

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<string, int> m = { {"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000} };
		int r = m[s.substr(0, 1)];
		for (int i = 1; i < s.size(); ++i) {
			string two = s.substr(i - 1, 2);
			string one = s.substr(i, 1);
			r += m[two] ? m[two] : m[one];
		}
		return r;
	}
};
