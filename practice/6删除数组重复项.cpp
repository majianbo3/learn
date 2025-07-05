6#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	vector<int>nums = { 1,1,2,2,4,5,2 };
	
	sort(nums.begin(), nums.end());
	//把重复的元素挪到末尾
	//unique(nums.begin(), nums.end());
	
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	for (auto row : nums)
		cout << row << endl;
}

