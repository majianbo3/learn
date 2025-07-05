#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<vector<int>>intervals = { {1,3},{2,6},{8,10},{15,18} };

	//cout << intervals[0][1] << endl;
	//for (auto row : intervals) {
	//	for (auto col : row) {
	//		cout << col << " ";
	//	}
	//	cout << endl;
	//}
	vector<vector<int>>ans;
	for (int i = 0; i < intervals.size();) {
		int right = intervals[i][1];
		int left = i + 1;

		while (left<intervals.size()&&intervals[left][0]<=right){
			right = max(right, intervals[left][1]);
			left++;
		}
		ans.push_back({ intervals[i][0],right });
		i = left;
	}
}