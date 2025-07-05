#include <iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
	//vector<int>nums = { 3,2,3 };
	vector<int>nums = { 2,2,1,1,1,2,2 };
	

	unordered_map<int, int>res(nums.size());
	int max = 0,ans=0;

	for (int row : nums)
	{
		res[row]++;
	}
	
	for (int i = 0; i < nums.size(); i++) {
	
		if (res[nums[i]] > max) {
			max = res[nums[i]];
			ans = nums[i];
		}

	}

	cout << ans << endl;
}