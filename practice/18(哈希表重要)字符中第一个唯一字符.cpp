#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {

	string s = "leetcode";
	unordered_map<char, bool>v;
	int ans = 0;
	//����s��˳���v��ֵ������v��key��0��1��2��3������s�е��ַ���
	//value�� 0��1��ʾ���
	for (char c : s) {
		v[c] = v.find(c) == v.end();//�������ڸ�Ԫ��
		cout << v[c] << endl;
	}
		
	//cout << v[1] << endl;


	for (int i = 0; i < s.size(); i++) {
		if (v[i] == true)
			ans = i;
	}

}