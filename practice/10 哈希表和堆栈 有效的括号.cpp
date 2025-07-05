#include <iostream>
#include<vector>
#include<unordered_map>
#include <stack>
using namespace std;

int main() {

	//true =1
	string s = "()";

	//�����ϣ��������Ÿ����к��Լ���Ӧ��ֵ
	unordered_map<char, int>m = { {'(',1},{'[',2},
		{'{',3},{')',4},{']',5},{'}',6} };

	//����һ��ջ���������Դ�����ͬ�ĳ�ջ
	stack<char> barrel;

	bool result = true;

	for (auto row : s) {
		//��ʱ�����m[row]����Ӧ���Ǻ����ֵ����1��2��3.������
		//cout << m[row] << endl;
		if (m[row] >= 1 && m[row] <= 3) barrel.push(row);
		//�жϳ�ջ�������ź�m��row��-3��ֵ�Ƿ�һ��
		else if (!barrel.empty() && m[barrel.top()] == m[row] - 3) barrel.pop();

		//����������false
		else
		{
			result = false;
			break;
		}
	}

	//������������û�б�գ��������Ų�ƥ��
	if (!barrel.empty()) result = false;
	bool test = true;
	cout << result << endl;
	cout << test << endl;


	
	
}