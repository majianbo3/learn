#include<iostream>
#include<vector>
using namespace std;
/*
思路：KMP算法（找最长相等前后缀）
找出字符串中第一个匹配项的下标
文本串：aabaabaaf
模式串：aabaaf
KMP算法与BF算法不同的地方：
    当找到不匹配的地方后，BF算法直接回退到模式串开头再做匹配；
    而KMP算法只用回退到最长相等前后缀值指向的模式串位置（即模式串中的 b），
                                再做匹配，效率要高很多
如何确定到 b 这个位置：
    定义前缀表（next 数组）
        前缀：不包含最后一个字符的所有以第一个字符开头的连续子串
        后缀：不包含第一个字符的所有以最后一个字符结尾的连续子串
        eg：模式串 aabaaf 的前缀表（可以理解为找对称元素的个数，或用回文来理解）
            前缀    next数组值
            a       0
            aa      1
            aab     0
            aaba    1
            aabaa   2
            aabaaf  0
    前缀表的值为 a a b a a f
                0 1 0 1 2 0
    在匹配时，当匹配到 f 时发现不匹配，我们就去找不匹配的元素的前一个元素（a）
    对应在前缀表中的值（2）
    由于前缀表的特性，不匹配元素的前一元素对应在前缀表中的值就是最长相等前后缀
    于是在 next 数组中找到下标为 2 的元素，即模式串中的 b。
        解释：当找到最长相等前后缀的值，为 2 ，
        表示在不匹配元素的前面有一个后缀 aa ，并且在前面也有一个与其相等的前缀 aa ，
        既然在这个后缀的后面发现不匹配了，那么就要到与其相等的前缀的后面继续匹配，
        也就是找到了前面 aab 里的 b

class Solution
{
private:
    void getNext(int* next, const string& s) // 填充 next 数组
    {
        int j = 0;
        next[0] = 0; // 前缀表的首元素一定是 0 ，因为字符串的首位没有对应的前后缀
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j]) // j要保证大于0，因为下面有取j-1作为数组下标的操作
            {
                j = next[j - 1]; // 找前一位的对应的回退位置
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j; // 更新 next 数组的值
        }
    }
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
        {
            return 0;
        }
        int next[needle.size()]; // 定义 next 数组（前缀表）
        getNext(next, needle); // 填充 next 数组
        int j = 0; // j 指向前缀末尾位置
        for (int i = 0; i < haystack.size(); i++) // i 指向后缀末尾位置
        {
            while (j > 0 && haystack[i] != needle[j]) // 前后缀不匹配时
            {
                j = next[j - 1]; // j 回退到 next 数组前一个位置所指向的值
            }
            if (haystack[i] == needle[j]) // 前后缀匹配时
            {
                j++; // i、j 后移，i 的后移在 for 循环里
            }
            if (j == needle.size()) // 如果 模式串 走完了
            {
                return i - needle.size() + 1;
            }
        }
        return -1; // 没找到
    }
};

作者：NULL
链接：https ://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/2415774/xiao-bai-ha-ha-ha-ha-yi-xing-dai-ma-by-t-dg0z/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/



int main() {
	//string haystack = "sadbutsad", needle = "sad";
	//string haystack = "leetcode", needle = "leeto";
	//string haystack = "a", needle = "a";
	string haystack = "mississippi", needle = "issip";
    vector<int>next(needle.size(), 0);
    int j = 0;

    next[0] = 0;
    for (int i = 1; i < needle.size(); i++)
    {
        while (j > 0 && needle[i] != needle[j]) // j要保证大于0，因为下面有取j-1作为数组下标的操作
        {
            j = next[j - 1]; // 找前一位的对应的回退位置
        }
        if (needle[i] == needle[j])
        {
            j++;
        }
        next[i] = j; // 更新 next 数组的值
    }
    //for (auto row : next)
    //    cout << row << " ";
    //cout << endl;
    // 
    int haystack_len = 0;
    for (int i = 0; i < haystack.size(); i++) {
        while (haystack_len > 0 && haystack[i] != needle[haystack_len]) {
            haystack_len = next[haystack_len - 1];
        }
        if (haystack[i] == needle[haystack_len])
            haystack_len++;
        if (haystack_len == needle.size())
            return i - needle.size() + 1;
    }
    return -1;
	//int len = haystack.size();
	//int len1 = needle.size();
	//int ans = -1,head = 0,idx=0;
	//for (int i = 0; i < len+1; i++) {
	//	if (head < len1 && needle[head] == haystack[i]) {
	//		if (head == 0)
	//			idx = i;
	//		head++;
	//	}
	//	else if (head == len1 )
	//		return idx;
	//	else {
	//		head = 0;
	//		//i = idx + 1;
	//	}
	//	
	//}
	//	return ans;
}