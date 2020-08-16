
#include<iostream>
#include<vector>
#include "./solution/Solution.h"
using namespace std;

int main(void)
{

    Solution* solution = new Solution;
    int ret = solution->strStr("hello", "ll");
    std::cout << ret << std::endl;
    delete solution;
    return 0;
}