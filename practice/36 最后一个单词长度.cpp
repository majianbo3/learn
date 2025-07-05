#include<iostream>

using namespace std;

int main() {
	//string s = "Hello World";
	//string s = "   fly me   to   the moon  ";
	string s = "a  ";

	int count = 0;
	int len = s.size();
	
	if (len == 1)
		return 1;
	for (int i = len-1; i >=0; i--) {
		if (s[i] == ' ')
		{
			if (count != 0)
				break;
		}
		else {
			count++;
		}
		
	}
	cout << count << endl;
}