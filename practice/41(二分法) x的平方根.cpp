#include<iostream>
#include<vector>



using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        
        //right+1确保区间里面不是一个空区间
        int left = 0, right = min(x, 46340) + 1;


        while (left + 1 < right) {
        
            int m = (left + right) / 2;
            (m * m <= x ? left : right) = m;
        }
        return left;
    }
};


int main() {

    int x = 2147395599;
    Solution s;
    int ans;

    ans=s.mySqrt(x);
    cout << ans << endl;
}

