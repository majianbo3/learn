#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        //cout << len << endl;

        digits[len-1]++;


        for (int i = len-1; i >=0; i--) {
            if (digits[i] >= 10) {

                int ge = digits[i] % 10;
                int shi = (digits[i] / 10) % 10;
                
                if (i - 1 < 0)
                {
                    ge = digits[i] % 10;
                    shi = (digits[i] / 10) % 10;
                    digits.insert(digits.begin(), shi);
                    digits[i+1] = ge;
                    
                    return digits;
                }

                digits[i] = ge;
                digits[i - 1] += shi;
            }
        }

        return digits;
    }
};



int main() {

    vector<int> digits = { 9,9,9 };


    Solution c;
    c.plusOne(digits);

    for (auto row : digits)
        cout << row << endl;
}