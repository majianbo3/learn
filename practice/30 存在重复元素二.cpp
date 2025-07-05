#include<iostream>
#include<vector>

using namespace std;
/*
����һ���������� nums ��һ������ k ���ж��������Ƿ�������� ��ͬ������ i �� j ��
���� nums[i] == nums[j] �� abs(i - j) <= k ��������ڣ����� true �����򣬷��� false ��
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