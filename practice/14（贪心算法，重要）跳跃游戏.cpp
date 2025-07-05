#include<iostream>
#include<vector>

using namespace std;


/*

给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
*/
int main() {
	vector<int> nums = { 2,3,1,1,4 };
	int len = nums.size() ;
	bool ans = true;
	int k = 0;
	//cout << len << endl;
	if (nums[0] >= len)
		ans = true;

	for (int i = 0; i < nums.size(); i++) {
		if (i > k) ans = false;
		//k为覆盖范围  nums[i] + i 为第i个元素覆盖几个元素，以起始元素做为基点
		k = max(k, nums[i] + i);
	}
}