#include<iostream>
#include<vector>

using namespace std;

int main() {
	
	string ransomNote = "aa", magazine = "aav";
	int len = magazine.size();
	bool ans = true;
	int  right =  0, head = 0;
	if (len == 1) {
		if (ransomNote[0] != magazine[0]) ans = false;
	}
	
	for (int i = 0; i < magazine.size(); i++) {
		if ( ransomNote[head] == magazine[i]) {
			//if (head != right) ans = false;
			head++;
			//right++;
			if (head == ransomNote.size())break;
		}
		else {
			head = 0;
			if (i <len && ransomNote[head] != magazine[i])continue;
			//if (i < len) continue;
			ans = false;
		}

	}
	if (head != ransomNote.size()) ans = false;
	cout << ans << endl;
}