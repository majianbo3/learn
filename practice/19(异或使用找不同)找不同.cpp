#include<iostream>

using namespace std;

int main() {
	string s = "aebcd", t = "abecdh";


	for (int i = 0; i < s.size(); ++i) 
		t[0] ^= s[i];
	for (int i = 1; i < t.size(); ++i) 
		t[0] ^= t[i];
	cout << t[0] << endl;
	//���ߣ�yudou
	//	����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
	//	���ӣ�https ://leetcode.cn/problems/find-the-difference/solutions/357173/c3xing-ji-bai-100-ling-kong-jian-fu-za-du-by-yudou/
	//��Դ�����ۣ�LeetCode��



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