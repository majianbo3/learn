#include "sprintVec.h"
using namespace std;

void sprintVect(int n) {
	vector<vector<int>>v(n, vector<int>(n));
	for (auto row : v)
	{
		for (int a : row)
			cout << a << " ";
		cout << endl;
	}
}