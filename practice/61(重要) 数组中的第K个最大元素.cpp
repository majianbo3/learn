#include<iostream>
#include<vector>

using namespace std;


//无重复元素
int portation(vector<int>& nums,int left,int right) {
	int part = nums[left];

	while (left < right) {
		while (left<right && nums[right] >= part)
			right--;
		nums[left] = nums[right];

		while (left < right && nums[left] <= part)
			left++;
		nums[right] = nums[left];
	}

	nums[left] = part;
	return left;
}


void threeway(vector<int>& nums, int left, int right, int& lf, int& rg) {
	int port = nums[left];
	lf = left;
	rg = right;
	int i = lf + 1;

	while (i <= rg) {
		if (nums[i] < port) {
			swap(nums[i], nums[left]);
			i++, lf++;
		}
		else if (nums[i] == port)
			i++;
		else {
			swap(nums[i], nums[rg]);
			rg--;
		}
	}

}

//针对重复元素
int find_kMax(vector<int>& nums, int k) {
	int target = nums.size() - k;
	int left = 0, right = nums.size() - 1;
	while (1) {
		//只针对与无重复元素
		//int part = portation(nums, left, right);

		//if (part == target) {
		//	return nums[target];
		//}
		//else if (part > target)
		//	right = part-1;
		//else
		//	left = part+1;

		//有重复
		int lf, rg;
		//int part = 0;
		threeway(nums, left, right, lf, rg);

		if (target < lf)
			right = rg - 1;
		else if (target > rg)
			left = rg + 1;
		else
			return nums[target];
	}
}

int main() {
	vector<int>nums = { 3,2,3,1,2,4,5,5,6 };
	int k = 4;
	int ans=find_kMax(nums, k);
	cout << ans << endl;
}
