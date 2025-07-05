#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        string ans;
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry >= 1) {

            //将去阿斯克吗值得到数字而不是字符,并确保还在有效数字范围内
            int bit1 = i >= 0 ? a[i] - '0' : 0;
            int bit2 = j >= 0 ? b[j] - '0' : 0;

            int sum = bit1 + bit2 + carry;
            carry = sum / 2;
            ans.push_back((sum % 2) + '0');
            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

};


int main() {

    string a = "101", b = "111";
    
    string ans;
    Solution s;
    ans = s.addBinary(a, b);

    for (auto row : ans)
        cout << row << endl;

    return 0;
}