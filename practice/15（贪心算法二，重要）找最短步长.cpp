#include<iostream>
#include <vector>
using namespace std;

int main() {

	vector<int>nums = { 2,3,1,1,4 };

	int nextDistance=0, curDiantance=0, ans = 0;

	//���ֻ��һ��Ԫ�أ�ֱ�ӷ���
	if (nums.size() <= 1) return 0;

	for (int i = 0; i < nums.size(); i++) {

		//���ڸ�����һ��Ԫ�صĸ��Ƿ�Χ
		nextDistance = max(nextDistance, i + nums[i]);

		//�������Ϊ�ڸ��¸��Ƿ�Χ��i�ߵ����Ƿ�Χ���һ����������ʾ��������
		if (i == curDiantance ) {

			if (curDiantance != nums.size() - 1) {
				//���Ӳ���
				ans++;

				//����һ�����Ƿ�Χ��ֵ����ǰ
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
//    nextDistance = max(nums[i] + i, nextDistance);  // ������һ��������Զ�����±�
//    if (i == curDistance) {                         // ������ǰ������Զ�����±�
//        if (curDistance != nums.size() - 1) {       // �����ǰ������Զ�����±겻���յ�
//            ans++;                                  // ��Ҫ����һ��
//            curDistance = nextDistance;             // ���µ�ǰ������Զ�����±�
//            if (nextDistance >= nums.size() - 1) break; // ��һ�����Ƿ�Χ�Ѿ��ﵽ�յ����ѭ��
//        }
//        else break;                               // ��ǰ������Զ�����±��Ǽ����յ�
//    }
//}
//return ans;
//    }
//
//    ���ߣ�Gnakuw
//        ���ӣ�https ://leetcode.cn/problems/jump-game-ii/solutions/1537131/by-nehzil-19a5/
//    ��Դ�����ۣ�LeetCode��
//        ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������