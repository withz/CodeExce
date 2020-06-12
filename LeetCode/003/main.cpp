#include <iostream>
#include <string>

#define MAX(x,y)    x>y?x:y

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int menu[256];

        int i;
        for (i = 0; i < 256; i++) {
            menu[i] = -1;
        }
        
        int max_len = 0;
        int last_ptr = 0;

        int s_len = s.length();
        for (i = 0; i < s_len; i++) {
            if (menu[s[i]] < 0 || menu[s[i]] < last_ptr){
                menu[s[i]] = i;
                int temp_len = i - last_ptr + 1;
                max_len = max_len > temp_len ? max_len : temp_len;
            } else {
                int temp_len = i - last_ptr;
                max_len = max_len > temp_len ? max_len : temp_len;
                last_ptr = menu[s[i]] + 1;
                menu[s[i]] = i;
            }
        }

        return max_len;
    }
};

int main()
{
    Solution s;
    int r = s.lengthOfLongestSubstring("abcabcbb");
    cout<<r<<endl;
    return 0;
}
