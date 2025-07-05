#include<iostream>

#include<vector>
#include<string>



using namespace std;


int find_first(vector<int>nums, int target) {
	int left = 0;
	int right = nums.size()-1;

	int middle = left + right / 2;

	while (left <= right) {
		middle = left + (right - left) / 2;

		if (nums[middle] == target)
			return middle;
		if (nums[middle] < target)
			left=middle+1;
		if (nums[middle] > target)
			right=middle+1;


	}

	return -1;
}


int main() {
	vector<int>nums = { 1,3,4,6,7,8 };
	int target = 3;

	int result =find_first(nums, target);
	cout << result << endl;
}



