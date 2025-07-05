#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<vector<int>>grid{vector<int>
		{1, 1, 0, 0},
		{ 1,1,1,0 },
		{ 0,1,0,0 },
		{ 1,1,0,0 }};

	cout << grid.size() << endl;
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                ans += 4;
                //此处减2可以避免上下左右都判断的情况
                //减2之后直接把下一个的接触区域提前减完
                //故只要判断下一行和下一列就行
                if (i < m - 1 && grid[i + 1][j] == 1) ans -= 2;
                if (j < n - 1 && grid[i][j + 1] == 1) ans -= 2;
            }
        }
    }

    //作者：Harmon Jiang
    //    链接：https ://leetcode.cn/problems/island-perimeter/solutions/466338/hdu5538xiang-tong-si-lu-rong-chi-yuan-li-jie-ti-by/
    //来源：力扣（LeetCode）
    //    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
}