#include <iostream>

using namespace std;
// 1 true
//0 false
int main() {
	//string s = "abc", t = "ahbgdc";
	//string s = "aec", t = "abcde";
	string s = "axc", t = "ahbgdc";
	bool ans =false;
	int head = 0;
	for (char a : t) {
		if (a == s[head])
			head++;
	}
	if (head == s.size() )
		ans = true;
	cout << ans << endl;

}