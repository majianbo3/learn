#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��ά������Բ��ô˷�����ֵ��
//result.push_back(vector<int>{nums[i], nums[j], nums[k]});

//������˫ָ���˼��

int main() {

	vector<int>nums = { -1,0,1,2,-1,-4 };
	vector<vector<int>>result;
	sort(nums.begin(), nums.end());//Ĭ�ϵ���

	for (int i = 0; i < nums.size(); i++) {

		//���ڴ�С�������У����ֵ�һ�����ִ�����ֱ�ӿ�ʼ��һ��
		if (nums[0] > 0) continue;
		
		//����ȥ��
		if (i > 0 && nums[i] == nums[i - 1]) continue;

		//����˫ָ���㷨��һ�������ڹ̶�����һ������һ�����������һ�����������м俿��

		int left = i + 1, right = nums.size() - 1;

		//�����ظ��������
		while (right > left) {

			//����ָ��ָ��λ�ý��и���
			//���������right������
			//��Сleft�����ƶ�����Ϊ�����Ѿ��ǵ�������
			if (nums[i] + nums[left] + nums[right] > 0) right--;

			else if (nums[i] + nums[left] + nums[right] < 0) left++;
			
			else {
				result.push_back(vector<int>{nums[i], nums[left], nums[right]});
				right--;
				left++;
				//֮����������ȥ��ԭ�򣬷�ֹ���ֶ���ظ����飬�硾0��0��0��0��0��0��
				while (right > left && nums[right] == nums[right - 1]) right--;
				while (right > left && nums[left] == nums[left + 1]) left++;

				//û���ظ������������м俿��



			}
			
		}
	}

	//return result;
	/*
	���ߣ���������¼
	���ӣ�https ://leetcode.cn/problems/3sum/solutions/1670261/dai-ma-sui-xiang-lu-dai-ni-gao-ding-ha-x-jzkx/
	��Դ�����ۣ�LeetCode��
	����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
	
	*/
}