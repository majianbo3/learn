#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

string expandAroundCenter(string s, int left, int right) {
	int L = left, R = right;

	//int end = 0, start = 0;

	//cout << s.length() << endl;
	//cout << s.size() << endl;
	while (L >= 0 && s[L]==s[R] && R< s.length()) {
		L--;
		R++;
	}
	return s.substr(L + 1, R - L - 1);

}

string longestPalindrome(string s) {
	string longest;

	for (int i = 0; i < s.size(); i++) {
		
		//判断回文子串最中心是否是单个
		string len1 = expandAroundCenter(s, i, i);
		//判断是否双数
		string len2 = expandAroundCenter(s, i, i+1);

		string len = (len1.size() > len2.size()) ? len1 : len2;

		if (len.size() > longest.size()) {
			//-1 +!是因为是从0开始，计算长度是从1开始
			longest = len;
		}			

	}
	return longest;
}


int main() {

	string s = "aacd";
	string ans=longestPalindrome(s);
	cout << ans << endl;

}