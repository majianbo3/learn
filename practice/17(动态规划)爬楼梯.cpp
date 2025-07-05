#include<iostream>
#include<vector>

using namespace std;

int main() {
	//记录爬的楼梯高度
	int n = 3;
	
	vector<int>v(n+1);
	//v[0]表示到台阶0有多少种办法
	v[0] = 0;
	v[1] = 1,v[2]=2;

	for (int i = 3; i <= n; i++) {

		v[i] = v[i - 1] + v[i - 2];
		//cout << v[i] << endl;
		//cout <<"i = "<< i << endl;

	}
	
	cout << v[n] << endl;
}