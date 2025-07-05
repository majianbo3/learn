#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int target = 7;
	vector<int>nums = { 2,3,1,2,4,3 };
	//[1,2,2,3,3,4]
	sort(nums.begin(), nums.end());
	int minlen = nums.size(), next = 1, head = 0;
	int sum = nums[0] + nums[1] ;//存放数组累加值
	if (nums[0] > target)
		return 0;

	for (int i = 0; i < nums.size(); i++) {
		if (next != head) {
			if (nums[i] == target)
				return 1;

			if (i > 1 && next < nums.size() && sum < target) {
				next++;
				sum = sum + nums[next];
			}
			else if (i > 1 && head != next && sum > target) {
				sum -= nums[head];
				head++;
			}
			else {
				minlen = min(minlen, next - head + 1);
				cout << minlen << endl;
			}
		}
	}

}