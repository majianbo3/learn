#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
���룺nums = [100,4,200,1,3,2]
�����4
���ͣ���������������� [1, 2, 3, 4]�����ĳ���Ϊ 4��


���룺nums = [1,0,1,2]
�����3
*/

void find_continue(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int max_len = 0,len=0;
	for (int i = 0; i < nums.size(); i++) {
		if (i + 1 < nums.size() && nums[i] == nums[i + 1])
		{
			if(i > 0 && nums[i] - nums[i - 1] == 1)
			{
				len++;
				i += 1;
				max_len = max(max_len, len);
				while (nums[i] == nums[i + 1])
					i++;

				continue;
			}
		}
		else {
			if (i >0 && nums[i] - nums[i-1] == 1) {
				len++;
			}
			else {
				len = 1;
			}
		}
		max_len = max(max_len, len);
	}
	//max_len = max(max_len, len);

	cout << max_len << endl;
}
//
/*
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
	if (nums.empty()) return 0;

	unordered_set<int> num_set(nums.begin(), nums.end());
	int longest_streak = 0;

	for (int num : num_set) {
		// �����ǰ���������е���ʼ��
		if (num_set.find(num - 1) == num_set.end()) {
			int current_num = num;
			int current_streak = 1;

			// ����������������
			while (num_set.find(current_num + 1) != num_set.end()) {
				current_num += 1;
				current_streak += 1;
			}

			// �������������
			longest_streak = max(longest_streak, current_streak);
		}
	}

	return longest_streak;
}

int main() {
	vector<int> nums = {100, 4, 200, 1, 3, 2};
	cout << "The length of the longest consecutive sequence is: " << longestConsecutive(nums) << endl;
	return 0;
}
*/
int main() {
	vector<int>nums = { -2,-3,-3,7,-3,0,5,0,-8,-4,-1,2 };

	find_continue(nums);
}