#include<iostream>
#include<vector>

using namespace std;

int main() {
	int numRows = 5;
	vector<vector<int>>dp(numRows, vector<int> (numRows));
	//vector<vector<int>>res(numRows, vector<int>(numRows));

	

	//��������ǵı߸�ֵΪһ
	for (int i = 0; i < numRows; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	if (numRows <= 2) {
		//return v;
	}
	else {
		//��������ǵ����п�ʼ��ֵ
		for (int i = 2; i < numRows; i++) {
			for (int j = 1; j < i; j++) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
			dp[i].resize(i+1);
		}
	}

	//����ռ��е���ֵ,�˺����Ǹı���һ��ʣ�༸��
	dp[0].resize(1);
	dp[1].resize(2);
	//for (int i = 0; i < numRows; i++) {
	//	for (int j = 0; j < dp[i].size(); j++) {
	//		if (dp[i][j] == 0)
	//		{
	//			
	//			dp[i].erase(dp[i].begin() + j );
	//			
	//			j--;
	//		}
	//		
	//	}
	//}

	for (auto row : dp) {
		for (auto a : row)
			cout << a << " ";
		cout << endl;
	}
}