#include<iostream>
#include<vector>

using namespace std;
/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，
满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
*/
int main() {
	vector<int> nums = { 1,2,3,5,3 };
	int k = 3,head = 1;
	int len = nums.size();
	bool ans = false;
	for (int i = 0; i < nums.size(); i++) {
		if (i != head &&head<len) {
			while ( head <len && nums[i] != nums[head])
			{
				head++;
			}
			if (head < len && nums[i] == nums[head])
			{
				ans = true;
				break;
			}
			else
				head = i + 2;
		}
	}
	cout << ans << endl;
}