#include<iostream>
#include<vector>
using namespace std;
//forѭ���б��������i��j��ϸ�ڣ�����ͨ����˼ά��i�����У�j������
	  //�������Ϳ��Ժ��������ֳ����仯����Ӧ�÷���[][]�ĵ�һ�����ǵڶ���
	  //���ڱ����ı߽���ô���壺
		  //����������䣺�����п϶���[left,right]����
		  //����������䣺�����п϶���[top,bottom]����
		  //����������䣺�����п϶���[right,left]����
		  //����������䣺�����п϶���[bootom,top]����
	  //ͨ��������ܽ�ᷢ�ֱ߽����ʼ�ͽ����뷽���Ƕ�Ӧ��
int main() {
	int n = 3;
	vector<vector<int>>v(n,vector<int>(n));
	int left = 0, right = n-1 , top = 0, bottom = n-1 ,max=n*n;
	int count = 0;

	while (count < max) {
		//�����������
		for (int j = left; j <= right; j++) {
			v[top][j] = ++count;
		//	cout << "�������" << endl;
	/*		cout << " " << top << " " << j <<"\n" << endl;
			cout << v[top][j] << " ";*/
		}
		cout << endl;
		top++;//������������

		for (int i = top; i <= bottom; i++)
		{
			v[i][right] = ++count;
			//cout << "�������" << endl;

			//cout << " " << i << " " << right << "\n" << endl;
			//cout << v[i][right] << " ";
		}
		cout << endl;
		right--;//��������
		
		for (int j = right; j >= left; j--)
		{
			v[bottom][j] = ++count;
			//cout << "�������" << endl;
			//cout << " " << j << " " << bottom << "\n" << endl;
			//cout << v[j][bottom] << " ";
		}
		cout << endl;
		bottom--;//��������

		for (int i = bottom; i >= top; i--)
		{
			v[i][left] = ++count;
			//cout << "�������" << endl;
			//cout << " " << top << "  " << i << "\n" << endl;
			//cout << v[top][i] << " ";
		}
		cout << endl;
		left++;
	}

	for (auto row : v)
	{
		for (int a : row)
			cout << a << " ";
		cout << endl;
	}
}