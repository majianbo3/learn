#include<iostream>
#include<vector>
using namespace std;
//for循环中变量定义成i或j的细节：按照通常的思维，i代表行，j代表列
	  //这样，就可以很容易区分出来变化的量应该放在[][]的第一个还是第二个
	  //对于变量的边界怎么定义：
		  //从左向右填充：填充的列肯定在[left,right]区间
		  //从上向下填充：填充的行肯定在[top,bottom]区间
		  //从右向左填充：填充的列肯定在[right,left]区间
		  //从下向上填充：填充的行肯定在[bootom,top]区间
	  //通过上面的总结会发现边界的起始和结束与方向是对应的
int main() {
	int n = 3;
	vector<vector<int>>v(n,vector<int>(n));
	int left = 0, right = n-1 , top = 0, bottom = n-1 ,max=n*n;
	int count = 0;

	while (count < max) {
		//从左往右填充
		for (int j = left; j <= right; j++) {
			v[top][j] = ++count;
		//	cout << "输出行列" << endl;
	/*		cout << " " << top << " " << j <<"\n" << endl;
			cout << v[top][j] << " ";*/
		}
		cout << endl;
		top++;//顶部向下缩进

		for (int i = top; i <= bottom; i++)
		{
			v[i][right] = ++count;
			//cout << "输出行列" << endl;

			//cout << " " << i << " " << right << "\n" << endl;
			//cout << v[i][right] << " ";
		}
		cout << endl;
		right--;//向左缩进
		
		for (int j = right; j >= left; j--)
		{
			v[bottom][j] = ++count;
			//cout << "输出行列" << endl;
			//cout << " " << j << " " << bottom << "\n" << endl;
			//cout << v[j][bottom] << " ";
		}
		cout << endl;
		bottom--;//向右缩进

		for (int i = bottom; i >= top; i--)
		{
			v[i][left] = ++count;
			//cout << "输出行列" << endl;
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