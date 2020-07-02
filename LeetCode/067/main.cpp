#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int pa = a.size() - 1;
        int pb = b.size() - 1;
        int c = 0;
        stack<char> res;
        while(pa>=0 && pb>=0){
            int x = a[pa] - '0';
            int y = b[pb] - '0';
            switch (x + y + c)
            {
            case 0:
                res.push(0);
                c = 0;
                break;
            case 1:
                res.push(1);
                c = 0;
                break;
            case 2:
                res.push(0);
                c = 1;
                break;
            case 3:
                res.push(1);
                c = 1;
                break;
            }
            pa--;
            pb--;
        }
        while(pa>=0){
            int x = a[pa] - '0';
            switch (x + c)
            {
            case 0:
                res.push(0);
                c = 0;
                break;
            case 1:
                res.push(1);
                c = 0;
                break;
            case 2:
                res.push(0);
                c = 1;
                break;
            }
            pa--;
        }
        while(pb>=0){
            int y = b[pb] - '0';
            switch (y + c)
            {
            case 0:
                res.push(0);
                c = 0;
                break;
            case 1:
                res.push(1);
                c = 0;
                break;
            case 2:
                res.push(0);
                c = 1;
                break;
            }
            pb--;
        }
        if(c!=0){
            res.push(1);
        }
        string s = "";
        while(!res.empty()){
            s.push_back(res.top() + '0');
            res.pop();
        }
        return s;
    }
};

int main()
{
    string a = "100";
    string b = "110010";

    Solution solution;
    string result = solution.addBinary(a, b);

    cout<<result<<endl;
    return 0;
}

