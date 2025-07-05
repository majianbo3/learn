#include<iostream>
#include<vector>
using namespace std;

int main() {
	int rowIndex = 2;
	vector<vector<int>>dp(rowIndex+1, vector<int>(rowIndex+1));
	vector<int>res;
	int numRows = rowIndex+1;

	for (int i = 0; i < numRows; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	//清除多余的0元素
	dp[0].resize(1);
	if (numRows <= 2) {
		//return v;
	}
	else {
		dp[1].resize(2);

		//从杨辉三角第三行开始赋值
		for (int i = 2; i < numRows; i++) {
			for (int j = 1; j < i; j++) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
			dp[i].resize(i + 1);
		}
	}

	for (auto row : dp)
	{
		for (auto a : row)
			cout << a << " ";
		cout << endl;
	}
	cout << "\n" << endl;
	for (int i = 0; i < rowIndex+1; i++) {
		cout << dp[rowIndex][i] << endl;
		res.push_back(dp[rowIndex][i]);
		//cout << res[i] << endl;
	}
	/*for (auto row : res)
		cout << row << " ";
	cout << endl;*/
}