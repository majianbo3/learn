#include <cctype>
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;



int main() {






    int num;
    cin >> num;
    int x, y;
    vector<vector<int>>vec(num, vector<int>(num));

    for (auto row : vec) {
        fill_n(row.begin(), num, 0);
    }


    while (cin >> x >> y) { // 注意 while 处理多个 case
        //vector<vector<int>>dp(num+1);
        //vec[x][y] = 1;
        //cout << vec[x][y] << endl;
        cout <<  "x: " << x << endl;
        cout << x + y << endl;
    }
}






/*
int main() {
    int num;
    cin >> num;
    string s, b;
    //cin >> s;

    string t = "";
    string t1 = "";
    long long p = 0;
    long long p1 = 0;

    while (cin >> s >> b)
    {
        for (char c : s) {
            if (isdigit(c)) {
                c = c - '0';
                if (c == num)
                {
                    if (p == 0) {
                        p = c;
                    }
                    else {
                        p = 10 * p + c;
                    }
                }
            }
            else {


                if (c == 'R') {
                    reverse(t.begin(), t.end());
                }
                else {
                    rotate(t.begin(), t.begin() + p, t.end());
                    t += c;
                    p = 0;
                }
            }
        }


        for (char c : b) {
            if (isdigit(c)) {
                c = c - '0';
                if (c == num)
                {
                    if (p1 == 0) {
                        p1 = c;
                    }
                    else {
                        p1 = 10 * p + c;
                    }
                }
            }
            else {


                if (c == 'R') {
                    reverse(t1.begin(), t1.end());
                }
                else {
                    rotate(t1.begin(), t1.begin() + p1, t1.end());
                    t1 += c;
                    p = 0;
                }
            }
        }

    }

    string ans;
    for (auto a : t)
        ans += a;
    cout << ans << "\n";
}
// 64 位输出请用 printf("%lld")
*/
