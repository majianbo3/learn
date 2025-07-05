#include<iostream>
#include<vector>

using namespace std;


vector<int> partlabel(string s) {
	vector<int>last(26);

	//给出最后一个元素索引
	for (int i = 0; i < s.size(); i++) {
		last[s[i]-'a'] = i;
	}

	int end = 0, start = 0;
	vector<int>ans;
	for (int i = 0; i < s.size(); i++) {
		end = max(end, last[s[i] - 'a']);

		if (end == i) {
			ans.push_back(end -start+1);
			start = end + 1;
		}
	}
	return ans;
}

int main() {
	string s = "ababcbacadefegdehijhklij";

	
	vector<int>res=partlabel(s);
	for (auto re : res)
		cout << re << endl;
}