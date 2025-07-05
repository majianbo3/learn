#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> nums = { 1, 3, 5, 6 };
	int target = 2;
	int nums_len = nums.size();

	if (nums_len == 0)
		return 0;
	if (nums[nums_len - 1] < target)
		return nums_len;
	for (int i = 0; i < nums_len; i++) {
		if ( nums[i] > target)
			return i ;
		if (nums[i] == target)
			return i;
	}
}