#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n = 6;

	vector<int>dp(n+1, 0);
	//cout << n / 2 << endl;

	for (int i = 0; i <= n; i++) {
		if (i % 2 == 0)
			dp[i] = dp[i / 2];
		else
			dp[i] = dp[i / 2] + 1;
	}

	for (auto row : dp)
		cout << row << " ";
	cout << endl;
}