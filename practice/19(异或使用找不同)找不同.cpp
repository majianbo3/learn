#include<iostream>

using namespace std;

int main() {
	string s = "aebcd", t = "abecdh";


	for (int i = 0; i < s.size(); ++i) 
		t[0] ^= s[i];
	for (int i = 1; i < t.size(); ++i) 
		t[0] ^= t[i];
	cout << t[0] << endl;
	//作者：yudou
	//	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	//	链接：https ://leetcode.cn/problems/find-the-difference/solutions/357173/c3xing-ji-bai-100-ling-kong-jian-fu-za-du-by-yudou/
	//来源：力扣（LeetCode）



	//int head = 0;
	//for (int i = 0; i < s.size(); i++) {
	//	if (s[i] == t[head]) {
	//		head++;
	//	}
	//	else {
	//		break;
	//	}
	//		
	//}
	//cout << t[head] << endl;
}