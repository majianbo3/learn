#include<iostream>
#include<string>

using namespace std;

int main() {
	int x = 1000021;//121;

	if (x < 0)
		return 0;
	string str = to_string(x);
	int len = str.size();
	bool ans = false;
	
	for (int i = 0; i < len; i++) {
		if (len % 2 == 0)
		{
			//0 - 3 1 - 2
			if (str[i] == str[len - i - 1])
			{
				if (i + 1 == len / 2)
				{
					ans = true;
					break;
				}
			}
			else
				break;
		}
		else 
		{
			//0 - 2  1
			if (str[i] == str[len - i - 1])
			{
				if (i + 1 == len / 2 + 1)
				{
					ans = true;
					break;
				}
				/*			else
								break;*/
			}
			else
				break;

		}

	
	}
	cout << ans << endl;
}