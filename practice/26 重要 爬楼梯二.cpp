#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费

*/
int main() {


	vector<int> cost = { 10,15,20 };
	vector<int>dp(cost.size());

	dp[0] = 0;
	dp[1] = min(cost[0], cost[1]);

	//dp[i]表示到达i台阶的一个总花费


	//dp[i - 2] + cost[i - 1] 其中cost表明跳过了i-1，为什么不是i的原因是没有从i上爬，
	for (int i = 2; i < cost.size(); i++) {
		dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i - 1]);
	}

	////int size = cost.size();
	////vector<int> minCost(size);
	////minCost[0] = 0;
	////minCost[1] = min(cost[0], cost[1]);
	////for (int i = 2; i < size; i++) {
	////	minCost[i] = min(minCost[i - 1] + cost[i], minCost[i - 2] + cost[i - 1]);
	////}
	////cout << minCost[size - 1] << endl;
	////return minCost[size - 1];

	////作者：armeria
	////	链接：https ://leetcode.cn/problems/min-cost-climbing-stairs/solutions/177077/yi-bu-yi-bu-tui-dao-dong-tai-gui-hua-de-duo-chong-/
	////来源：力扣（LeetCode）
	////	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
////	vector<int>dp(cost.size());
////
////	//表示跳上去才算cost 站在此处台阶不算cost
////	dp[1] = min(cost[0], cost[1]);
//////	dp[2] = cost[1];
////
////
////
////	for (int i = 2; i < cost.size()+1; i++) {
////		//此处表示站在此处台阶不算cost 跳上去才算
////		dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i - 1]);
////	}
////	cout << dp[cost.size()-1] << endl;
}