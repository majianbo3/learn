#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	vector<int>nums1 = { -1,0,0,3,3,3,0,0,0 };
	int m = 6, n = 3;
	vector<int>nums2 = { 2,5,6 };
	vector<int>v;

	for(int i = 0; i < n; i++) {
		
		nums1.push_back(nums2[i]);
	}

	//���������������Ա����0
	sort(nums1.begin(), nums1.end());

	//�������������ж��Ƿ�youlingg
	for (int i = 0; i < nums1.size(); i++) {
		if(nums1[i] != 0){

			//nums1.erase(nums1.begin()+i);
			v.push_back(nums1[i]);
		}

	}
	swap(nums1, v);
	//for (int i = 0; i < v.size(); i++) {
	//	nums1.pop_back();
	//}
	//for (int i = 0; i < v.size(); i++) {
	//	nums1.push_back(v[i]);
	//}
	//�����������nums1��0���Ǹ��ľ��޷����0
	//while (nums1[0] == 0)
	//{
	//	nums1.erase(nums1.begin());
	//}

	for (auto row : nums1)
	{
		cout << row << endl;
	}
}