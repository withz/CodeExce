#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        this->dp = new bool[n + 1];
        for(int i = 0;i <= n;i++){
            this->dp[i] = false;
        }
        sort(begin(wordDict), end(wordDict), Solution::compLen);
        for(int i = 0;i < n;i++){
            this->core(s, i, wordDict);
        }
        return this->dp[n - 1];
    }
private:
    bool *dp = nullptr;
    static bool compLen(string a, string b){
        return a.length() > b.length();
    }
    void core(string s, int pos, vector<string>& dict){
        if(this->dp[pos]){
            return;
        }
        for(auto iter = dict.begin(); iter != dict.end();iter++){
            int len = (*iter).length();
            string a = (*iter);
            string b = s.substr(pos, len);
            if(a.compare(b) == 0){
                this->dp[pos + len - 1] = true;
            }
        }
    }
};

int main()
{
    string a = "abcd";
    vector<string> b = {"a","abc","b","cd"};
    // string a = "aaaaaab";
    // vector<string> b = {"a", "aa", "aaa"};

    Solution solution;
    cout<<solution.wordBreak(a, b)<<endl;
    return 0;
}

