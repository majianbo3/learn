#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> nums = { 0,1,2,2,3,0,4,2 };
	int val = 2;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == val)
		{
			//����˴��ж�����Ҫɾ�������е�һ��Ԫ�أ���Ҫ��֮ǰ��size�����©һ���������i����
			nums.erase(nums.begin() + i);
			i--;
		}
	}

	for (auto row : nums) cout << row << endl;
}

