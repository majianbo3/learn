#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int>nums = { 1,8,6,2,5,4,8,3,7 };

	int left = 0, right = nums.size() - 1;
	int area = 0;

	while (left < right) {
		area = max(area, min(nums[left] , nums[right])*(right-left));

		if (nums[left] < nums[right])
			left++;
		else
			right--;
	}
	cout << area << endl;
}