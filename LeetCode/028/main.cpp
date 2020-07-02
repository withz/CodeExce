#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main()
{
    string a = "hello";
    string b = "ll";

    Solution solution;
    cout<<solution.strStr(a, b)<<endl;

    return 0;
}