#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {

	string s = "leetcode";
	unordered_map<char, bool>v;
	int ans = 0;
	//按照s的顺序给v赋值，其中v的key是0，1，2，3，不是s中的字符串
	//value是 0，1表示真假
	for (char c : s) {
		v[c] = v.find(c) == v.end();//即不存在该元素
		cout << v[c] << endl;
	}
		
	//cout << v[1] << endl;


	for (int i = 0; i < s.size(); i++) {
		if (v[i] == true)
			ans = i;
	}

}