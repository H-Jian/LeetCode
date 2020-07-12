#include<stack>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;


class Solution {
public:

	/*����˼·��
	1.����n��numRows����s�ĳ���С��numRows������s�ĳ���
	2.��n==0ʱ��+1����n=numRows-1ʱ�п�ʼ-1
	3.��˳��������s�е��ַ����ηŽ�ÿһ������
	4.����ÿһ�е��ַ�����ӵõ�res
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