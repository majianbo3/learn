#include<iostream>
#include<vector>

using namespace std;

int main() {

		vector<vector<int>>marix{{1, 1, 1}, { 1,0,1 }, { 1,1,1 }};

		int m = marix.size();
		int n = marix[0].size();

		vector<int>row(m), col(n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (marix[i][j] == 0) {
					row[i] = true;
					col[j] = true;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (row[i]||col[j]) {
					marix[i][j] = 0;
				}
			}
		}

		for (auto row : marix)
		{
			for (auto col : row)
				cout << col << " ";
			cout << endl;
		}
}