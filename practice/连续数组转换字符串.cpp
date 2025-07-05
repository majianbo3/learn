#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;


vector<string> find_continue(const vector<int> s1) {

	vector<string>result;
	int start = 0, end = 0;
	vector<int>nums = s1;
	ostringstream oss;


	for (int i = 0; i < nums.size(); i++) {
		//
		if (i + 1 < nums.size() && nums[i + 1] - nums[i] != 1) {
			
			if (start == i) {
				oss << nums[start];
				result.push_back(oss.str());
				oss.str("");
				start = i + 1;
			}
			else {
			end = i;
			oss << nums[start] << "->" << nums[end];
			result.push_back(oss.str());
			start = i + 1;

			oss.str("");
			}

		}
		else if (i == nums.size() - 1) {
			end = i;
			oss << nums[start] << "->" << nums[end];
			result.push_back(oss.str());
			return result;
		}
		if (nums[start] == nums[nums.size()-1]) {
			oss << nums[start];
			result.push_back(oss.str());
			return result;
		}
		
		
	}
	return result;
}


int main() {
	//vector<int>nums = { 1,2,6,8,9,10 };
	vector<int>nums = { 1,2,6,7,8,9,10 };
	
	

	vector<string>result = find_continue(nums);
	

	for (auto row : result)
		cout << row << endl;
}
