#include<iostream>
#include<vector>

using namespace std;


/*

����һ���Ǹ��������� nums �������λ������� ��һ���±� �������е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

�ж����Ƿ��ܹ��������һ���±꣬������ԣ����� true �����򣬷��� false ��
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
		//kΪ���Ƿ�Χ  nums[i] + i Ϊ��i��Ԫ�ظ��Ǽ���Ԫ�أ�����ʼԪ����Ϊ����
		k = max(k, nums[i] + i);
	}
}