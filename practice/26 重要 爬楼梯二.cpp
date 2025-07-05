#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
����һ���������� cost ������ cost[i] �Ǵ�¥�ݵ� i ��̨����������Ҫ֧���ķ��á�һ����֧���˷��ã�����ѡ��������һ����������̨�ס�

�����ѡ����±�Ϊ 0 ���±�Ϊ 1 ��̨�׿�ʼ��¥�ݡ�

������㲢���شﵽ¥�ݶ�������ͻ���

*/
int main() {


	vector<int> cost = { 10,15,20 };
	vector<int>dp(cost.size());

	dp[0] = 0;
	dp[1] = min(cost[0], cost[1]);

	//dp[i]��ʾ����į�׵�һ���ܻ���


	//dp[i - 2] + cost[i - 1] ����cost����������i-1��Ϊʲô����i��ԭ����û�д�i������
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

	////���ߣ�armeria
	////	���ӣ�https ://leetcode.cn/problems/min-cost-climbing-stairs/solutions/177077/yi-bu-yi-bu-tui-dao-dong-tai-gui-hua-de-duo-chong-/
	////��Դ�����ۣ�LeetCode��
	////	����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
////	vector<int>dp(cost.size());
////
////	//��ʾ����ȥ����cost վ�ڴ˴�̨�ײ���cost
////	dp[1] = min(cost[0], cost[1]);
//////	dp[2] = cost[1];
////
////
////
////	for (int i = 2; i < cost.size()+1; i++) {
////		//�˴���ʾվ�ڴ˴�̨�ײ���cost ����ȥ����
////		dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i - 1]);
////	}
////	cout << dp[cost.size()-1] << endl;
}