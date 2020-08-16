#include<iostream>
#include "../solution/Solution.h"

int Solution::strStr(string haystack, string needle)
{
    int len1 = haystack.length();
    int len2 = needle.length();

    if (len1 < len2) {
        return -1;
    }

    if (needle.size() == 0) {
        return 0;
    }
    int i;
    int j;
    for (i = 0; i < len1 - len2 + 1; i++) {
        for (j = 0; j < len2; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == len2) {
            return i;
        }
    }
    return -1;
}

vector<vector<int>> Solution::subsets(vector<int>& nums) 
{
    vector<vector<int>> ret;
    vector<int> tempRet;
    backtrack(nums, 0, tempRet, ret);
    return ret;
}

void backtrack(vector<int>& nums, int pos, vector<int>& temp, vector<vector<int>>& ret) 
{
    ret.push_back(vector(temp));

    for (int i = pos; i < nums.size(); i++) {
        temp.push_back(nums[i]);
        backtrack(nums, i + 1, temp, ret);
        temp.pop_back();
    }
}