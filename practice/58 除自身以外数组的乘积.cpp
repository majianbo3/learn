#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int>nums = { 1,2,3,4 };

	vector<int>L(nums.size(), 0);
	vector<int>R(nums.size(), 0);

	//L表示以当前的i为中心，向左看，故不需要管最后一个
	L[0] = 1;
	for (int i = 1; i < nums.size(); i++)
		L[i] = L[i - 1] * nums[i - 1];

	R[nums.size()-1] = 1;
	for (int i = nums.size()-2; i >=0 ; i--)
		R[i] = R[i + 1] * nums[i + 1];

	vector<int>ans(nums.size());
	for (int i = 0; i < nums.size(); i++) {
		ans[i] = L[i] * R[i];
	}

	for (auto a : ans)
		cout << a << " ";
}