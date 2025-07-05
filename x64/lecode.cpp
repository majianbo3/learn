#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;


void find_str(vector<string>str) {
	unordered_map<string, vector<string>>ans;
	
	for (string s1 : str) {
		auto s = s1;
		sort(s1.begin(), s1.end());
		ans[s1].push_back(s);
	}

	vector<vector<string>>v;
	v.reserve(ans.size());

	for (auto pair : ans) {
		v.push_back(pair.second);
	}

	for (auto row : v) {
		for (auto col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
}

void findNorepeat(string s) {
	vector<int>v(128,0);
	int head = 0,maxlen=0;

	for (int i = 0; i < s.size();i++) {
		head = max(head, v[s[i]]);
		v[s[i]] = i + 1;

		maxlen = max(maxlen, i - head + 1);
	}
	cout << maxlen << endl;
}

int main() {

	/*vector<string>str = { "eat", "tea", "tan", "ate", "nat", "bat" };

	find_str(str);*/
	/*string s = "abcabcbb";

	findNorepeat(s);*/
	vector<int>nums = { 100,4,200,1,3,2 };

	unordered_set<int>set;
	for (auto const n : nums) {
		set.insert(n);
	}
	int longestlen = 0;
	int numset = 0,nummax=0;
	for (auto const n : nums) {
		//表示n为初始值
		if (!set.count(n - 1)) {
			numset = n;
			nummax = 0;
			while (set.count(numset)) {
				numset++;
				nummax++;
			}
			longestlen = max(longestlen, nummax);
		}
	}
}