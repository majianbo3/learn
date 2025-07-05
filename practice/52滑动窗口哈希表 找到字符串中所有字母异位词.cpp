#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	string s = "cbaebabacd";
	string p = "abc";
	
	vector<int>scount(26, 0);
	vector<int>pcount(26, 0);
	vector<int>ans;

	for (char c : p)
		pcount[c - 'a']++;

	for (int left = 0, right = 0; right < s.size(); right++) {
		scount[s[right] - 'a']++;

		if (right - left + 1 == p.size()) {
			if (scount == pcount)
				ans.push_back(left);
			scount[s[left] - 'a']--;
			left++;
		}
	}
	for (auto a : ans)
		cout << a << " ";
	cout << endl;
	//substrµÄÊ±¼äÌ«¾Ã
	//sort(target.begin(), target.end());
	//int head = 0;
	//int tail = target.size();
	//vector<int>ans;

	//if (s.size() < target.size())
	//	return -1;

	//while (head <= s.size()-tail) {
	//	string s1 = s.substr(head, tail);
	//	sort(s1.begin(), s1.end());
	//	if (s1 == target) {
	//		ans.push_back(head);
	//		head++;
	//		//tail++;
	//	}
	//	else {
	//		head++;
	//		//tail++;
	//	}
	//}
}