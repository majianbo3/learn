#include<iostream>
#include<vector>
using namespace std;

/*
大概思路：
            1、首先令所有字符的值都为0，存放在m中
            2、遍历字符串所有内容
            3、如果有重复的内容 由于此语句   m[s[i]] = i + 1; 则默认会指向重复的语句一个位置
            以此来实现滑动框来确认不重复的长度

*/

int main()
{
	string s = "abcabcbb";

    vector<int> m(128, 0);
    //存最大长度
    int maxlen = 0;
    //head表示窗口最左边的字母序号：如果出现重复的，比如两个相同的字母a，
    // 上一个a在桶里存的m[s[i]]是a+1表示a的下一个位置
    //那么第二个a出现时，head就=a+1也就是max(head,m[s[i]])，
    //去除了窗口里上一个a，保证窗口里无重复字母
    int head = 0;
    //遍历字符串
    
    for (int i = 0; i < s.size(); i++) {

        head = max(head, m[s[i]]);

        m[s[i]] = i + 1;

        maxlen = max(maxlen, i - head + 1);


    }
    
    
    
    
    
    
    
    
    
    for (int i = 0; i < s.size(); i++) {
        ////修改最左边的字母序号head
        //cout << "没改前："<<head << endl;
        head = max(head, m[s[i]]);
   /*     cout << "改后：" << head << endl;
        cout << "m：" << m[s[i]] << endl;
        cout << "s[i]" << s[i] << endl;*/
        //当前字母对应的ASCII码桶里存下一个位置(i+1)，用于更新head
        m[s[i]] = i + 1;//主要帮助更新head的位置
        //更新长度
        maxlen = max(maxlen, i - head + 1);
        cout << "更新后的长度" << maxlen << endl;
    }

    cout << "最终的长度" << maxlen << endl;
    //vector<int> v;
    //for (int i = 0; i < s.size(); i++)
    //{
    //    for (int j = i + 1; j < s.size(); j++)
    //    {
    //        if (s[i] == s[j])
    //        {
    //          // cout << j << endl;
    //            //return j;
    //            // break;
    //            v.push_back(j);
    //            
    //        }
    //    }
    //}
	//vector<int>v = { 1,2,3,4 };
	//auto max = max_element(v.begin(), v.end());
	//cout << *max<< endl;
}
/*   法2
* 
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
         //在unordered_set中如果该元素存在，`find`函数将返回指向该元素的迭代器；
         //如果元素不存在，`find`函数将返回集合的尾后迭代器，即`lookup.end()`。
         //即存在该元素
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            //i表示右边的滑动框，left表示最左边的滑动框，+1是因为从0开始
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
    //}
        return maxStr;

    }

作者：powcai
链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/solutions/3982/hua-dong-chuang-kou-by-powcai/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/