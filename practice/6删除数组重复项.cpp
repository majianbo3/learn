6#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	vector<int>nums = { 1,1,2,2,4,5,2 };
	
	sort(nums.begin(), nums.end());
	//���ظ���Ԫ��Ų��ĩβ
	//unique(nums.begin(), nums.end());
	
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	for (auto row : nums)
		cout << row << endl;
}

