#include<iostream>

#include<vector>

using namespace std;

int main() {
	vector<int>nums = { 1,2,3,4,5,6,7 };
	int k = 3;

	vector<int>newarr(nums.size());

	for (int i = 0; i < nums.size(); i++) {
		newarr[(i + k) % nums.size()] = nums[i];
	}

	nums.assign(newarr.begin(), newarr.end());

	for (auto n : nums)
		cout << n << " ";
	
}