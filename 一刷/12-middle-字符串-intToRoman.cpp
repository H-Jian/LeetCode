#include<stack>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

class help {
	//unordered_map<int, char>rec{
	//	{1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'},
	//};
	unordered_map<int, string>re{
	{4,"IV"},{9,"IX"},{40,"XL"},{90,"XC"},{400,"CD"},{900,"CM"}
	};
public:
	string helper(int num) {
		if (num == 4 || num == 9 || num == 40 || num == 90
			|| num == 400 || num == 900)
			return re[num];
		string res="";
		//int temp = 0;
		//int temp = -1;
		while (num != 0) {
			if (num >= 1000) {
					res += "M";
				num = num - 1000;
			}
			else if (num >= 500 && num < 1000) {
				if (num >= 900) {
					res += "CM";
					num = num - 900;
				}
				else {
					res += "D";
					num = num - 500;
				}
			}
			else if (num >= 100 && num < 500) {
				if (num >= 400) {
					res += "CD";
					num = num - 400;
				}
				else {
					res += "C";
					num = num - 100;
				}
			}
			else if (num >= 50 && num < 100) {
				if (num >= 90) {
					res += "XC";
					num -= 90;
				}
				else {
					res += "L";
					num = num - 50;
				}
			}
			else if (num >= 10 && num < 50) {
				if (num >= 40) {
					res += "XL";
					num -= 40;
				}
				else {
					res += "X";
					num = num - 10;
				}
			}
			else if (num >= 5 && num < 10) {
				if(num>=9) {
					res += "IX";
					num -= 9;
				}
				else {
					res += "V";
					num = num - 5;
				}
			}
			else if (num >= 1 && num < 5) {
				if (num >= 4) {
					res += "IV";
					num -= 4;
				}
				else {
					res += "I";
					num = num - 1;
				}
			}
		}
		return res;

	}
};

class Solution {
public:
	string intToRoman(int num) {
		help p;
		return p.helper(num);
	}
};


string intToRoman(int num) {
	vector<string>T = { "","M","MM","MMM" };
	vector<string>H = { "","C","CC","CCC" ,"CD","D","DC","DCC","DCCC","CM"};
	vector<string>Ten = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
	vector<string>S = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
	string res = T[num / 1000] + H[num % 1000 / 100] + Ten[num % 100 / 10] + S[num % 10];
	return res;
}
