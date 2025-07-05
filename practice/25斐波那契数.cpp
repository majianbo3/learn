#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n = 0;

	vector<int>FN(n+2);
	FN[0] = 0, FN[1] = 1;
	if (n <= 1)
		return FN[n];

	for (int i = 2; i < n+1; i++) {
		FN[i] = FN[i - 1] + FN[i - 2];
	}
	cout << FN[n] << endl;
}