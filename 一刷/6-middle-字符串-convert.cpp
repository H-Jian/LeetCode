#include<stack>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;


class Solution {
public:

	/*解题思路：
	1.行数n是numRows，当s的长度小于numRows行数是s的长度
	2.当n==0时行+1，当n=numRows-1时行开始-1
	3.按顺序遍历会把s中的字符依次放进每一行里面
	4.遍历每一行的字符串相加得到res
	*/
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		vector<string>rows(min(numRows, (int)s.length()));
		int curRow = 0;
		bool goingDown = false;
		for (char &c : s) {
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) {
				goingDown = !goingDown;
			}
			curRow += goingDown ? 1 : -1;
		}
		string ret;
		for (string &row : rows) {
			ret += row;
		}
		return ret;
	}
};


string convert(string s, int numRows) {
	if (numRows == 1) return s;
	vector<string>row(min(numRows, (int)s.length()));
	int cur = 0;
	bool path = false;

	for (char &c : s) {
		row[cur] += c;
		if (cur == 0 || cur == numRows - 1) {
			path = !path;
		}
		cur += path ? 1 : -1;
	}
	string res;
	for (string &t : row) {
		res += t;
	}
	return res;
}