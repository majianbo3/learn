#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{

    int n = 15;
    vector<string>v;

    for (int i = 1; i < n+1; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            v.push_back("FizzBuzz");
        }

        else if (i % 3 == 0)
        {
            v.push_back("Fizz");
        }
         else if (i % 5 == 0)
        {
            v.push_back("Buzz");
        }
  
        else
        {
            v.push_back( to_string(i));
        }
    }

    for (auto row : v)
    {
        cout << row << " ";
    }
    cout << endl;
    //string s = "pwwkew";

    //for (int i = 0; i < s.size(); i++)
    //{
    //    for (int j = i + 1; j < s.size(); j++)
    //    {
    //        if (s[i] == s[j])
    //        {
    //            cout << j << endl;
    //            return j;
    //           // break;
    //        }
    //    }
    //}
    //vector<int> nums{1, 2,3};
    //int target = 4;
    //
    //for (int i = 0; i < nums.size(); i++)
    //{
    //    for (int j = i + 1; j < nums.size(); j++)
    //    {
    //        if (nums[i] + nums[j] == target)
    //        {
    //            return i, j;
    //        }
    //    }
    //}
    //异或求法可以用来找出不一样的一个值；
   // int nums[] = {1,3,2,2,3};
   //// cout <<sizeof(nums)/sizeof(nums[0]) << endl;求数组长度
   //
   // int len = sizeof(nums) / sizeof(nums[0]);
   // int c = 0;
   // 
    /*for (auto a : nums)
    {
        c ^= a;
    }*/

    //for (int i = 0; i < len; i++)
    //{
    //    c ^= nums[i];
    //}
   // for(int i=0;i<)

    //1.
	//vector<vector<int>>v{{1, 2, 3}, { 3,2,1 }};
 //   for (const auto& row : v)
 //   {
 //       for (int i : row)
 //       {
 //           //cout << i << " ";
 //           
 //       
 //       }
 //       //cout << row << endl;
 //       //cout << endl;
 //   }
	//v.assign({ { 1,2,3 }, { 3,2,1 } });
	//vector<int> v1(1, 2, 3);


}
/*

int main() {
    std::vector<std::vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (const auto& row : v) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
*/