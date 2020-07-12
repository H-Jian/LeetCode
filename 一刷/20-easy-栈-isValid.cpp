#include<stack>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.length() == 0) return true;
		stack<char>rec;
		for (char &temp : s) {
			if (temp == '(' || temp == '[' || temp == '{')
				rec.push(temp);
			else {
				if (rec.empty()) return false;
				else {
					if (rec.top() == '(' && temp == ')') {
						rec.pop();
						continue;
					}
					else if (rec.top() == '[' && temp == ']') {
						rec.pop();
						continue;
					}
					else if (rec.top() == '{' && temp == '}') {
						rec.pop();
						continue;
					}
					else
						return false;
				}
			}
		}
		return rec.empty();
	}
};