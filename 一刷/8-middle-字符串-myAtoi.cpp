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
	//垃圾代码

	//int singleC2I(char c)
	//{
	//	if (c == 48) return 0;
	//	if (c == 49) return 1; 
	//	if (c == 50) return 2;
	//	if (c == 51) return 3;
	//	if (c == 52) return 4;
	//	if (c == 53) return 5;
	//	if (c == 54) return 6;
	//	if (c == 55) return 7;
	//	if (c == 56) return 8;
	//	if (c == 57) return 9;
	//	return 0;
	//}
	//int myAtoi(string str) {
	//	queue<char>rec;
	//	long res = 0;
	//	for (char &t : str) {
	//		if (rec.empty() && (t < 48 || t>57)) {
	//			if (t == 45) rec.push(t);
	//			else if (t == 32 || t == 43) continue;
	//			else return 0;
	//		}
	//		else if (!rec.empty() && (t < 48 || t>57))
	//			break;
	//		else
	//			rec.push(t);
	//	}
	//	if (rec.empty()) return 0;
	//	else {
	//		if (rec.front() == '-') {
	//			rec.pop();
	//			if (rec.empty()) return 0;
	//			else {
	//				int n = rec.size();
	//					while (!rec.empty()) {
	//						res += -(long)(singleC2I(rec.front()) * (long)pow(10, n - 1));
	//						n--;
	//						rec.pop();
	//					}
	//					if (res < INT_MIN) return INT_MIN;
	//					else return (int)res;
	//			}
	//		}
	//		else {
	//			int n = rec.size();
	//			while (!rec.empty()) {
	//				res += (singleC2I(rec.front())* (long)pow(10, n - 1));
	//				n--;
	//				rec.pop();
	//			}
	//			if (res > (long)INT_MAX) return INT_MAX;
	//			else return (int)res;
	//		}
	//	}
	//	res = 0;
	//	return res;
	//}

};
class Solution {
public:
	int myAtoi(string str)
	{
		size_t iSize = str.length();

		if (0 == iSize)
		{
			return 0;
		}

		bool bReachNumber = false, bNegative = false;
		size_t i = 0;
		int64_t i64Dest = 0, i64Minus = INT32_MIN * -1LL;

		for (i = 0; i < iSize; ++i)
		{
			switch (str[i])
			{
			case ' ':
				if (bReachNumber)
				{
					// already reach number, return
					if (bNegative)
					{
						return (int)(-1 * i64Dest);
					}
					return (int)i64Dest;
				}
				continue;
				break;

			case '-':
				if (bReachNumber)
				{
					// already reach number, return
					if (bNegative)
					{
						return (int)(-1 * i64Dest);
					}
					return (int)i64Dest;
				}
				bNegative = true;
				bReachNumber = true;
				continue;
				break;

			case '+':
				if (bReachNumber)
				{
					// already reach number, return
					if (bNegative)
					{
						return (int)(-1 * i64Dest);
					}
					return (int)i64Dest;
				}

				bReachNumber = true;
				continue;
				break;

			case '0':
				i64Dest = i64Dest * 10;
				bReachNumber = true;
				break;

			case '1':
				i64Dest = i64Dest * 10 + 1;
				bReachNumber = true;
				break;

			case '2':
				i64Dest = i64Dest * 10 + 2;
				bReachNumber = true;
				break;

			case '3':
				i64Dest = i64Dest * 10 + 3;
				bReachNumber = true;
				break;

			case '4':
				i64Dest = i64Dest * 10 + 4;
				bReachNumber = true;
				break;

			case '5':
				i64Dest = i64Dest * 10 + 5;
				bReachNumber = true;
				break;

			case '6':
				i64Dest = i64Dest * 10 + 6;
				bReachNumber = true;
				break;

			case '7':
				i64Dest = i64Dest * 10 + 7;
				bReachNumber = true;
				break;

			case '8':
				i64Dest = i64Dest * 10 + 8;
				bReachNumber = true;
				break;

			case '9':
				i64Dest = i64Dest * 10 + 9;
				bReachNumber = true;
				break;

			default:
				// not number, plus, minus, space
				if (bReachNumber)
				{
					// already reach number, return
					if (bNegative)
					{
						return (int)(-1 * i64Dest);
					}
					return (int)i64Dest;
				}

				return 0;
			}

			if (bNegative)
			{
				if (i64Minus < i64Dest)
				{
					return INT32_MIN;
				}
			}
			else
			{
				if (INT32_MAX < i64Dest)
				{
					return INT32_MAX;
				}
			}
		}

		if (bNegative)
		{
			return (int)(-1 * i64Dest);
		}
		return (int)i64Dest;
	}
};

	//正解思路：自动机的概念  有限状态机

class Automata {
	string state = "start";
	unordered_map<string, vector<string>> table = {
		{"start",{"start","sign","innum","end"}},
		{"sign",{"end","end","innum","end"}},
		{"innum",{"end","end","innum","end"}},
		{"end",{"end","end","end","end"}}
	};
	//定义状态表
	int get_s(char c) {
		if (c == ' ')return 0;//空格
		if (c == '+' || c == '-')return 1;//符号
		if (isdigit(c))return 2; //数字
		return 3; //其他
	}
	//将对应字符转化为数字，结合上一状态得到当前状态

public:
	long long ans = 0;
	int sign = 1;

	void get(char c) {
		state = table[state][get_s(c)];//根据当前状态的不同对数据进行处理
		if (state == "innum") {
			ans = ans * 10 + c - '0';
			ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
		}
		else if (state == "sign") {
			if (c == '-')sign = -1;
		}
	}
};

class Solution {
public:
	int myAtoi(string str) {
		Automata dfa;
		for (char c : str)
			dfa.get(c);
		return dfa.sign*dfa.ans;
	}
};

 //正则表达式

