#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<string>strs = { "flower", "flow", "flight" };
	string res = strs.empty() ? "" : strs[0];
	for (string s : strs) //ð�ź������Ҫ�����ļ��� ǰ��ľ��Ǽ���ÿ�α����Ķ������� 
		//cout << s << endl;
		while (s.find(res) != 0) //��ʾ����˼Ϊ��s��û���ҵ���Ӧ��Ԫ�أ��ͽ�resһֱ����
			res = res.substr(0, res.length() - 1);//������ҵ���λ�ò�����ʼλ
												//	�ã���������0������res��������
	
	cout << res << endl;
	
	

}