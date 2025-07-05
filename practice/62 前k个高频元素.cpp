#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int>topkfre(vector<int>nums, int k) {
	unordered_map<int, int>fremap;
	for (auto num : nums)
		fremap[num]++;

	vector <vector< int >> bucket(nums.size() + 1);
	for (auto pair : fremap) {
		bucket[pair.second].push_back(pair.first);
	}
	vector<int>result;
	
	for (int i = nums.size(); i >= 0 && result.size() < k; --i) {
		for (int num : bucket[i]) {
			result.push_back(num);
			if (result.size() == k) break;
		}
	}
	return result;
}


int main() {
	vector<int>nums = { 2,2,3,1,1,1,5 };
	int k = 2;

	vector<int>ans;

	ans = topkfre(nums, k);

	for(auto a:ans)
		cout<<a<<endl;
}