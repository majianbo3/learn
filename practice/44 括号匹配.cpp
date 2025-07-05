#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
#include<string>

using namespace std;


int main() {
	
	string s = "{()[]}";

	unordered_map<char, int> m = { {'(',1},{'[',2},{'{',3},{')',4},{']',5},{'}',6} };

	stack<char>stack;

	for (char row : s) {
		if (m[row] <= 3) {
			stack.push(row);
		}
		else if (!stack.empty() && m[stack.top()] == m[row] - 3) {
			stack.pop();
		}
		else
			cout << "no" << endl;
	}
}