#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
	//string s = "IV";
	//string s = "IX";
	//string s = "LVIII";
	string s = "MCMXCIV";
	unordered_map<char, int>v = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},
									{'D',500},{'M',1000} };
	
	int len = s.size();
	int ans = 0;

	for (int i = 0; i < len; i++) {
		if (i + 1 < len && v[s[i]] < v[s[i + 1]])
		{
			ans = v[s[i + 1]] - v[s[i]] + ans;
			i ++;
		}
		else {
			ans = ans + v[s[i]];
		}
	}
	cout << ans << endl;
}