#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main() {
	vector<int>nums = { 100,4,200,1,3,2 };

	unordered_set<int>num_set;

	for (auto const n : nums)
		num_set.insert(n);

	int maxlen = 0, numcur = 0, num = 0;
	for (int const n : nums) {
		//判断当前数字是否为首个
		if (!num_set.count(n - 1)) {
			numcur = n;
			num = 0;
			while (num_set.count(numcur)) {
				numcur++;
				num++;
			}
			maxlen = max(maxlen, num);
		}
	}
	cout << maxlen << endl;
}