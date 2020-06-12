#include <iostream>
#include <string>

#define MAX(x,y)    x>y?x:y

using namespace std;

class Solution {
public:
    string LongestPalindrome(string s) {
        int n = s.size();
        bool **dp = new bool*[];
        int i, j;
        if (n <= 1)
        {
            return s;
        }

        for (i = 0; i < n; i++)
        {
            dp[i] = new bool[n];
            for (j = 0; j < n; j++)
            {
                dp[i][j] = false;
            }
            dp[i][i]  = true;
        }

        for (i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i+1]  = true;
            }
        }


        for (i = 1; i <= n; i++)
        {
            for (j = 0; j < n - i + 1; j++)
            {
                if(dp[j, j + i - 1])
                {
                    if(j - 1 >= 0 && j + i < n)
                    {
                        if(s[j - 1] == s[i + j])
                        {
                            dp[j - 1][j + i] = true;
                        }
                        else
                        {
                            dp[j - 1][j + i] = false;
                        }
                    }
                }
            }
        }

        int maxi = 0;
        int maxj = 0;

        for (i = 0; i < n; i++)
        {
            for (j = i; j < n; j++)
            {
                if (dp[i][j])
                {
                    if(maxj - maxi < j - i)
                    {
                        maxj = j;
                        maxi = i;
                    }
                }
            }
        }

        return s.substr(maxi, maxj - maxi + 1);
    }
};

int main()
{
    Solution s;
    string r = s.LongestPalindrome("abcabcbb");
    cout<<r<<endl;
    return 0;
}
