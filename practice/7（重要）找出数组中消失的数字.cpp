#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	//方法二，思路为，找到消失的数也可以认为是出现的次数为零
	vector<int> nums = { 4,3,2,7,8,2,1,3 };
	
	//生成与nums.size()一样多的0，用于判断后面的出现次数为零的数字
	vector<int>res(nums.size()+1);
	vector<int>ans;

	for (int i = 0; i < nums.size(); i++) {
		res[nums[i]]++;
	}

	for (int i = 1; i < nums.size()+1 ; i++) {

		if (res[i] == 0)
			ans.push_back(i);
	}

	for (auto row : ans)
		cout << row << endl;










	//方法一，时间复杂度较高
	//vector<int> nums = { 4,3,2,7,8,2,1,3 };
 //   vector<int>res;
	////[1,2.2,3.3.4.7.8]
	//sort(nums.begin(), nums.end());
	//int cur = 1;

	//for (int i = 0; i < nums.size(); i++) {
	//	if (cur == nums[i])
	//		cur++;

	//	if (cur < nums[i]) {
	//		while (cur != nums[i]) {
	//			res.push_back(cur);
	//			cur++;
	//		}
	//		i--;
	//	}

	//}
	//while (cur <= nums.size()) {
	//	res.push_back(cur);
	//	cur++;
	//}

}