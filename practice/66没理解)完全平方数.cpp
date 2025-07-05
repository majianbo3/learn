#include<iostream>
#include<vector>

using namespace std;


void numSquares(int n) {
	vector<int> f(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int mmin = INT_MAX;

		for (int j = 1; j * j <= i; j++) {
			//i-JJ的原因是动态规划思想，拿到前一个·数据
			mmin = min(mmin, f[i - j * j]);
		}
		//f表示f几对应的完全平方数
		f[i] = mmin + 1;
	}

	cout << f[n] << endl;

}

string find_center(string s, int l1, int l2) {
	while (l1 >= 0 && l2 < s.length() && s[l1]==s[l2]) {
		l1--;
		l2++;
	}

	return s.substr(l1+1, l2-l1-1);
}

string longestPalindrome(string s) {

	int len = s.length() - 1;

	for (int i = 0; i < len; i++) {
		string s1 = find_center(s,i, i);
	}

}

int main() {
	int n = 13;

	numSquares(n);
}