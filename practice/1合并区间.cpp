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
		//当前值的右区间
		int right = intervals[i][1];
		int left = i + 1;

		//判断j没有大于intervals并且下一个区间的左区间小于等于上一个值的右区间
		while (left < intervals.size() && intervals[left][0] <= right) {
			//用于更新值的右区间
			right = max(right, intervals[left][1]);
			cout << right << endl;
			left++;
		}
		//用于合并区间
		ans.push_back({ intervals[i][0],right });
		//防止重复
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




