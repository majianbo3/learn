#include <iostream>
#include<vector>
#include<unordered_map>
#include <stack>
using namespace std;

int main() {

	//true =1
	string s = "()";

	//定义哈希表用来存放各个托号以及对应的值
	unordered_map<char, int>m = { {'(',1},{'[',2},
		{'{',3},{')',4},{']',5},{'}',6} };

	//定义一个栈类容器，以此来相同的出栈
	stack<char> barrel;

	bool result = true;

	for (auto row : s) {
		//此时的输出m[row]都对应的是后面的值，及1，2，3.。。。
		//cout << m[row] << endl;
		if (m[row] >= 1 && m[row] <= 3) barrel.push(row);
		//判断出栈顶的括号和m【row】-3的值是否一样
		else if (!barrel.empty() && m[barrel.top()] == m[row] - 3) barrel.pop();

		//都不满足则false
		else
		{
			result = false;
			break;
		}
	}

	//遍历后容器若没有变空，代表括号不匹配
	if (!barrel.empty()) result = false;
	bool test = true;
	cout << result << endl;
	cout << test << endl;


	
	
}