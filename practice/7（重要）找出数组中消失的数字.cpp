#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	//��������˼·Ϊ���ҵ���ʧ����Ҳ������Ϊ�ǳ��ֵĴ���Ϊ��
	vector<int> nums = { 4,3,2,7,8,2,1,3 };
	
	//������nums.size()һ�����0�������жϺ���ĳ��ִ���Ϊ�������
	vector<int>res(nums.size()+1);
	vector<int>ans;

	for (int i = 0; i < nums.size(); i++) {
		res[nums[i]]++;
	}

	for (int i = 1; i < nums.size()+1 ; i++) {

		if (res[i] == 0)
			ans.push_back(i);
	}

	for (auto row : ans)
		cout << row << endl;










	//����һ��ʱ�临�ӶȽϸ�
	//vector<int> nums = { 4,3,2,7,8,2,1,3 };
 //   vector<int>res;
	////[1,2.2,3.3.4.7.8]
	//sort(nums.begin(), nums.end());
	//int cur = 1;

	//for (int i = 0; i < nums.size(); i++) {
	//	if (cur == nums[i])
	//		cur++;

	//	if (cur < nums[i]) {
	//		while (cur != nums[i]) {
	//			res.push_back(cur);
	//			cur++;
	//		}
	//		i--;
	//	}

	//}
	//while (cur <= nums.size()) {
	//	res.push_back(cur);
	//	cur++;
	//}

}