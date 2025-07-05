#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//二维数组可以采用此方法赋值，
//result.push_back(vector<int>{nums[i], nums[j], nums[k]});

//运用了双指针的思想

int main() {

	vector<int>nums = { -1,0,1,2,-1,-4 };
	vector<vector<int>>result;
	sort(nums.begin(), nums.end());//默认递增

	for (int i = 0; i < nums.size(); i++) {

		//由于从小到大排列，发现第一个数字大于零直接开始下一个
		if (nums[0] > 0) continue;
		
		//进行去重
		if (i > 0 && nums[i] == nums[i - 1]) continue;

		//进行双指针算法，一个定义在固定数下一个，另一个定义在最后一个，两者向中间靠近

		int left = i + 1, right = nums.size() - 1;

		//避免重复或这出错
		while (right > left) {

			//对两指针指向位置进行更新
			//如果过大则right向左移
			//过小left向右移动，因为数字已经是递增数列
			if (nums[i] + nums[left] + nums[right] > 0) right--;

			else if (nums[i] + nums[left] + nums[right] < 0) left++;
			
			else {
				result.push_back(vector<int>{nums[i], nums[left], nums[right]});
				right--;
				left++;
				//之后对数组进行去重原则，防止出现多个重复数组，如【0，0，0，0，0，0】
				while (right > left && nums[right] == nums[right - 1]) right--;
				while (right > left && nums[left] == nums[left + 1]) left++;

				//没有重复的数组则向中间靠近



			}
			
		}
	}

	//return result;
	/*
	作者：代码随想录
	链接：https ://leetcode.cn/problems/3sum/solutions/1670261/dai-ma-sui-xiang-lu-dai-ni-gao-ding-ha-x-jzkx/
	来源：力扣（LeetCode）
	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	
	*/
}