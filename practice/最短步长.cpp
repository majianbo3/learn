#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int>nums = { 2,3,1,1,4 };

	int cur = 0, fugai = 0, bride = 0;

	for (int i = 0; i < nums.size(); i++) {
		fugai = max(fugai,i+ nums[i]);

		if (i == cur) {
			if (i < nums.size() - 1) {
				bride++;
				cur = fugai;

				if (fugai >= nums.size() - 1)
					break;
			}
			else
				break;
		}
	}
}