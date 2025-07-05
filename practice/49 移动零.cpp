#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void move_zero(vector<int>& nums) {
	
	
	int num = 0;
	for (int i = 0; i < nums.size();i++) {
		if (nums[i] == 0) {
			nums.erase(nums.begin() + i);
			i--;
			num++;
		}
	}
	while (num != 0) {
		nums.push_back(0);
		num--;
	}
	for (auto row : nums)
		cout << row << endl;
}

void other(vector<int>& nums) {
	int index = 0;

	for (auto &s : nums) {
		if (s != 0)
		{
			swap(s, nums[index]);
			index++;
		}
	}
}

int main() {
	vector<int>nums = { 1,3,5,0,8 };

	//move_zero(nums);
	other(nums);
}