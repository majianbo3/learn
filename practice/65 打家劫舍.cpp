#include<iostream>
#include<vector>

using namespace std;


vector<int> rob(vector<int>nums) {

	if (nums.size() == 1)
		return nums;

	vector<int>dp(nums.size(), 0);

	dp[0] = nums[0];

	//��ֻ������Ԫ��ʱ�Ĵ���
	dp[1] = max(dp[0], nums[1]);

	for (int i = 2; i < nums.size(); i++) {

		//���ڴ����Ƿ�Ҫ��ȥi����ط���Ǯ
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
	}
	return dp;
}

int main() {
	vector<int>nums = { 1,1 };

	vector<int> ans=rob(nums);

	cout << ans[nums.size() - 1] << endl;
}