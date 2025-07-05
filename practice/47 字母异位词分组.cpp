#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<ranges>
using namespace std;


int main() {
	vector<string> str = { "eat", "tea", "tan", "ate", "nat", "bat" };

	unordered_map<string, vector<string>>v;

	for (string& s : str) {
		string s1 = s;
		sort(s1.begin(),s1.end());
		v[s1].push_back(s);
	}
	vector<vector<string>>ans;
	ans.reserve(v.size());
	
	for (auto pair : v) {
		ans.push_back(pair.second);
	}
	for (const auto& group : ans) {
		for (const auto& word : group) {
			cout << word << " ";
		}
		cout << endl;
	}
}