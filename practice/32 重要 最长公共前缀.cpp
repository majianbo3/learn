#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<string>strs = { "flower", "flow", "flight" };
	string res = strs.empty() ? "" : strs[0];
	for (string s : strs) //冒号后面的是要遍历的集合 前面的就是集合每次遍历的对象名称 
		//cout << s << endl;
		while (s.find(res) != 0) //表示的意思为在s中没有找到对应的元素，就将res一直缩减
			res = res.substr(0, res.length() - 1);//即如果找到的位置不是起始位
												//	置（即不等于0），则将res逐渐缩减，
	
	cout << res << endl;
	
	

}