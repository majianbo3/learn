#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int main() {
	//法一
	//vector<int> nums = { 1,2,3,1 };
	//unordered_map<int, int>res;
	//bool ans = false;

	//for (int row : nums)
	//	res[row]++;
	//for (int i = 0; i < nums.size(); i++) {
	//	if (res[nums[i]] >= 2)
	//		ans = true;
	//}
	//cout << ans << endl;
	//cout << false << endl;

	//法二
	vector<int> nums = { 1,2,3,1 };
	unordered_set<int>res;
	for (int i = 0; i < nums.size(); i++) {
		//表示存在该元素
		if (res.find(nums[i]) != res.end()) {
			return true;
		}
		else
			res.insert(nums[i]);
	}
		
}