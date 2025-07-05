#include<iostream>
#include<vector>
#include<algorithm>;
#include<unordered_map>
using namespace std;

/*
 ˫ָ��û�취��ȫ��ʱ����
 ����һ���������� nums ��һ������ k ������ͳ�Ʋ����� �������к�Ϊ k ��������ĸ��� ��


��������������Ԫ�ص������ǿ����С�


���룺nums = [1,1,1], k = 2
�����2

ʾ�� 2��
���룺nums = [1,2,3], k = 3
�����2


����λ��0	1	2	3	4
����ֵ	1	2	3	4	5
ǰ׺��	1	3	6	10	15
Ϊʲô�Ҳ�ֵ��
���ڣ������ҵ�һ�������飬���ĺ��� K = 9���������Ѿ����㵽�˵� 4 ��λ�õ�ǰ׺�ͣ��� 15��
��ͻȻ�뵽�����֮ǰĳ��λ�õ�ǰ׺���� 15 - 9 = 6����ô���Ǹ�λ�õ���ǰλ�õ�������Ͳ����� 9 ����Ϊ��

��ǰ��ǰ׺�� - ֮ǰ��ǰ׺�� =������ĺ� 

���仰˵��ֻҪ�ҵ�һ��֮ǰ��ǰ׺���� 6����ô���Ǹ�λ�õ���ǰλ�õ�������;��� 9��

*/

int main() {
	vector<int>nums = { 1,1,1 };
	int k = 2;
	unordered_map<int, int>res;

	//��ֹnums=[1],key=1,res�з���0�����
	res[0] = 1;
	int presum = 0;
	int ans = 0;

	//��ϣ���Ҳ�ֵ����ֵkeyΪǰ׺��
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