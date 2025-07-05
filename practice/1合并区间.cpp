#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	vector<vector<int>>intervals = {
		{1,3},
		{2,6},
		{8,10},
		{15,18} };

	sort(intervals.begin(), intervals.end());
	vector<vector<int>> ans;

	for (int i = 0; i < intervals.size();) {
		//��ǰֵ��������
		int right = intervals[i][1];
		int left = i + 1;

		//�ж�jû�д���intervals������һ�������������С�ڵ�����һ��ֵ��������
		while (left < intervals.size() && intervals[left][0] <= right) {
			//���ڸ���ֵ��������
			right = max(right, intervals[left][1]);
			cout << right << endl;
			left++;
		}
		//���ںϲ�����
		ans.push_back({ intervals[i][0],right });
		//��ֹ�ظ�
		i = left;
	}
	for (auto row : ans) {
		for (auto i : row) cout << i << " ";
		cout<<endl;
	}


}





	//	for (int i = 0; i < intervals.size();) {
	//		int t = intervals[i][1];
	//		int j = i + 1;
	//		while (j < intervals.size() && intervals[j][0] <= t) {
	//			t = max(t, intervals[j][1]);
	//			j++;
	//		}
	//		ans.push_back({ intervals[i][0], t });
	//		i = j;
	//	}
	//	return ans;
	//}




