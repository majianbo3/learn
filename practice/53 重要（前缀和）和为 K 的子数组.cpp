#include<iostream>
#include<vector>
#include<algorithm>;
#include<unordered_map>
using namespace std;

/*
 双指针没办法找全的时候用
 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。


子数组是数组中元素的连续非空序列。


输入：nums = [1,1,1], k = 2
输出：2

示例 2：
输入：nums = [1,2,3], k = 3
输出：2


数组位置0	1	2	3	4
数组值	1	2	3	4	5
前缀和	1	3	6	10	15
为什么找差值？
现在，你想找到一个子数组，它的和是 K = 9。假设你已经计算到了第 4 个位置的前缀和，是 15。
你突然想到：如果之前某个位置的前缀和是 15 - 9 = 6，那么从那个位置到当前位置的子数组和不就是 9 吗？因为：

当前的前缀和 - 之前的前缀和 =子数组的和 

换句话说，只要找到一个之前的前缀和是 6，那么从那个位置到当前位置的子数组和就是 9。

*/

int main() {
	vector<int>nums = { 1,1,1 };
	int k = 2;
	unordered_map<int, int>res;

	//防止nums=[1],key=1,res中返回0的情况
	res[0] = 1;
	int presum = 0;
	int ans = 0;

	//哈希表找差值，赋值key为前缀和
	for (int i = 0; i < nums.size(); ++i) {
		presum += nums[i];

		int r1 = presum - k;

		if (res.find(r1) != res.end())
			ans += res[r1];
	
		res[presum] += 1;

	}

	cout << ans << endl;
	return ans;

}