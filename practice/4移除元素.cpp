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
			//进入此处判断由于要删除容器中的一个元素，若要用之前的size则会遗漏一个，故需对i左移
			nums.erase(nums.begin() + i);
			i--;
		}
	}

	for (auto row : nums) cout << row << endl;
}

