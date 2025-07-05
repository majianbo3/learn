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
                //�˴���2���Ա����������Ҷ��жϵ����
                //��2֮��ֱ�Ӱ���һ���ĽӴ�������ǰ����
                //��ֻҪ�ж���һ�к���һ�о���
                if (i < m - 1 && grid[i + 1][j] == 1) ans -= 2;
                if (j < n - 1 && grid[i][j + 1] == 1) ans -= 2;
            }
        }
    }

    //���ߣ�Harmon Jiang
    //    ���ӣ�https ://leetcode.cn/problems/island-perimeter/solutions/466338/hdu5538xiang-tong-si-lu-rong-chi-yuan-li-jie-ti-by/
    //��Դ�����ۣ�LeetCode��
    //    ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
}