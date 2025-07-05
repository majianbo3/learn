#include<iostream>
#include <vector>
using namespace std;

int main() {

	vector<int>nums = { 2,3,1,1,4 };

	int nextDistance=0, curDiantance=0, ans = 0;

	//如果只有一个元素，直接返回
	if (nums.size() <= 1) return 0;

	for (int i = 0; i < nums.size(); i++) {

		//用于更新下一个元素的覆盖范围
		nextDistance = max(nextDistance, i + nums[i]);

		//可以理解为在更新覆盖范围后，i走到覆盖范围最后一个，但不表示步长增加
		if (i == curDiantance ) {

			if (curDiantance != nums.size() - 1) {
				//增加步长
				ans++;

				//将下一个覆盖范围赋值给当前
				curDiantance = nextDistance;

				if (nextDistance >= nums.size() - 1) break;
			}
			else {
				break;
			}

		}

	}
}



//if (nums.size() == 1) return 0;
//int curDistance = 0, nextDistance = 0, ans = 0;
//for (int i = 0; i < nums.size(); i++) {
//    nextDistance = max(nums[i] + i, nextDistance);  // 更新下一步覆盖最远距离下标
//    if (i == curDistance) {                         // 遇到当前覆盖最远距离下标
//        if (curDistance != nums.size() - 1) {       // 如果当前覆盖最远距离下标不是终点
//            ans++;                                  // 需要走下一步
//            curDistance = nextDistance;             // 更新当前覆盖最远距离下标
//            if (nextDistance >= nums.size() - 1) break; // 下一步覆盖范围已经达到终点结束循环
//        }
//        else break;                               // 当前覆盖最远距离下标是集合终点
//    }
//}
//return ans;
//    }
//
//    作者：Gnakuw
//        链接：https ://leetcode.cn/problems/jump-game-ii/solutions/1537131/by-nehzil-19a5/
//    来源：力扣（LeetCode）
//        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。