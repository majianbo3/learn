#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool compare(const string a, const string b) {
	return a + b > b + a;
}

string find_max(vector<int>nums) {
	vector<string> str;

	for (auto num : nums) {
		str.push_back(to_string(num));
	}

	sort(str.begin(), str.end(), compare);
	string ans;

	for (auto s : str) {
		ans += s;
	}

}

int main() {
	vector<int>nums = { 1,87,99,123,321 };

	string result = find_max(nums);
}