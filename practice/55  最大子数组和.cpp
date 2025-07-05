#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int>nums = { 5,4,-1,7,8 };
	int nummax = INT_MIN;
	int pre = 0;
	for (int i = 0; i < nums.size(); i++) {
		pre = max(pre + nums[i], nums[i]);
		nummax = max(nummax, pre);
	}
	cout << nummax << endl;
}